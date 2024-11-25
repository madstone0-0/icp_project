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
    foreign key (preqid) references course(cid)
);


create table course_faculty (
  uid int not null,
  cid int not null,
  primary key (uid, cid),
  foreign key (uid) references faculty (uid) ON DELETE CASCADE,
  foreign key (cid) references course (cid)
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
    'F'
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



/*-- insert records into the `user` table
insert into user (fname, lname, email, password) values
  ('alice', 'johnson', 'alice.johnson@example.com', 'password123'),
  ('bob', 'smith', 'bob.smith@example.com', 'password456'),
  ('carol', 'davis', 'carol.davis@example.com', 'password789'),
  ('david', 'brown', 'david.brown@example.com', 'password101'),
  ('eve', 'wilson', 'eve.wilson@example.com', 'password202');

-- insert records into the `admin` table
insert into admin (uid) values
  (1),  -- alice is an admin
  (3);  -- carol is also an admin

-- insert records into the `student` table
insert into student (uid, dob, picture, major, enrolldate) values
  (2, '2002-05-14', null, 'cs', '2021-09-01'),  -- bob is a student
  (4, '2003-07-21', null, 'en', '2022-09-01'),  -- david is a student
  (5, '2001-11-05', null, 'ba', '2021-09-01');  -- eve is a student

-- insert records into the `faculty` table
insert into faculty (uid, appdate, dept) values
  (1, '2020-01-15', 'cs'),  -- alice is a cs faculty member
  (3, '2019-03-22', 'ba');  -- carol is a ba faculty member

-- insert records into the `course` table
insert into course (cname, credits, sem) values
  ('data structures', 3.0, 's1'),
  ('business ethics', 2.0, 's2'),
  ('mechanics', 3.0, 's1'),
  ('calculus i', 4.0, 's2'),
  ('programming fundamentals', 3.0, 's1');

-- insert records into the `course_faculty` table
insert into course_faculty (uid, cid) values
  (1, 1),  -- alice teaches data structures
  (1, 5),  -- alice also teaches programming fundamentals
  (3, 2);  -- carol teaches business ethics

-- insert records into the `enrollment` table
insert into enrollment (uid, cid, sem, grade) values
  (2, 1, 's1', 'a'),    -- bob enrolled in data structures and scored an a
  (2, 5, 's1', 'b+'),   -- bob in programming fundamentals with a b+
  (4, 3, 's1', 'b'),    -- david enrolled in mechanics and scored a b
  (4, 4, 's2', 'c+'),   -- david    in calculus i with a c+
  (5, 2, 's2', 'a+');   -- eve enrolled in business ethics with an a+*/