drop database if exists records;

create database records;

use records;

create table user (
    uid int auto_increment primary key,
    fname varchar(50) not null,
    lname varchar(50) not null,
    email varchar(100) unique not null ,
    password varchar(255) not null
);

create table admin (
    uid int primary key,
    foreign key (uid) references user (uid)
);

create table student (
    uid int primary key,
    dob date not null,
    picture longblob,
    major enum (
        'CS',
        'BA',
        'EN',
        'ME',
        'EE',
        'CE',
        'MA'
    ) not null,
    enrolldate date not null,
    foreign key (uid) references user (uid)
);

create table payments (
    pid int auto_increment primary key,
    uid int,
    sem enum(
        'S1',
        'S2'
    ) DEFAULT "S1",
    total_amount decimal(
        10,
        2
    ),
    paid_amount decimal(
        10,
        2
    ),
    payment_status enum(
        'pending',
        'partial',
        'paid'
    ) DEFAULT "pending",
    foreign key (uid) references student(uid)
);

create table faculty (
    uid int primary key,
    appdate date not null default (
        current_date()
    ),
    dept enum (
        "CS",
        "HM",
        "EN",
        "BA"
    ) not null,
    foreign key (uid) references user (uid)
);

create table course (
    cid int auto_increment primary key,
    cname varchar(100) not null,
    credits double not null default 1.0,
    sem enum (
        'S1',
        'S2'
    ) not null default 'S1',
    capacity int NOT NULL DEFAULT 40
    -- semester with enum type
);

create table prerequisites (
    cid int NOT null,
    preqid int NOT null,
    primary key (cid, preqid),
    foreign key (cid) references course(cid) ON DELETE CASCADE,
    foreign key (preqid) references course(cid) ON DELETE cascade
);


create table course_faculty (
  uid int not null,
  cid int not null,
  primary key (uid, cid),
  foreign key (uid) references faculty (uid) ON DELETE CASCADE,
  foreign key (cid) references course (cid) ON DELETE cascade
);

create table enrollment (
  eid int auto_increment primary key,
  uid int  not null,
  cid int not null,
  sem enum ('S1', 'S2') not null default 'S1',
  grade enum (
    'A+',
    'A',
    'B+',
    'B',
    'C+',
    'C',
    'D+',
    'D',
    'E+',
    'E',
    'F+',
    'F',
    "NG"
  ),
  foreign key (uid) references student (uid) ON DELETE CASCADE,
  foreign key (cid) references course (cid) ON DELETE CASCADE
);

create table schedule (
scid int auto_increment primary key,
cid int NOT null,
starttime time not null,
endtime time not null,
day enum ("Monday", "Tuesday", "Wednesday", "Thursday", "Friday"),
foreign key (cid) references course (cid)
);

CREATE TABLE audit_log (
    log_id INT AUTO_INCREMENT PRIMARY KEY,
    action VARCHAR(255) NOT NULL,
    user_id INT NOT NULL,
    timestamp TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    details TEXT
);

DELIMITER //

CREATE TRIGGER update_payment_status 
BEFORE UPDATE ON payments
FOR EACH ROW
BEGIN
    -- If no amount has been paid, status remains 'pending'
    IF NEW.paid_amount = 0 THEN
        SET NEW.payment_status = 'pending';
    
    -- If paid amount is less than total amount, status is 'partial'
    ELSEIF NEW.paid_amount > 0 AND NEW.paid_amount < NEW.total_amount THEN
        SET NEW.payment_status = 'partial';
    
    -- If paid amount is equal to or greater than total amount, status is 'paid'
    ELSEIF NEW.paid_amount >= NEW.total_amount THEN
        SET NEW.payment_status = 'paid';
    END IF;
END;//

DELIMITER ;