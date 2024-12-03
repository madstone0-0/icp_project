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
  ) default "NG",
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

-- Indices
CREATE INDEX idx_course_name ON course (cname);
CREATE INDEX idx_course_sem ON course (sem);

CREATE INDEX idx_enrollment_uid ON enrollment (uid);
CREATE INDEX idx_enrollment_cid ON enrollment (cid);
CREATE INDEX idx_enrollment_sem ON enrollmen 09t (sem);

CREATE INDEX idx_schedule_cid ON schedule (cid);
CREATE INDEX idx_schedule_day ON schedule (day);

CREATE INDEX idx_user_email_password ON user (email, password);
CREATE INDEX idx_payments_uid_status_sem ON payments (uid, payment_status, sem);
CREATE INDEX idx_course_faculty_uid_cid ON course_faculty (uid, cid);


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

-- User table
INSERT INTO user (fname, lname, email, password)
VALUES
('Madiba', 'Hudson-Quansah', 'mhquansah@gmail.com', '1411241789187772614611123143241611482201152118099233');

-- Admin table
INSERT INTO admin (uid)
VALUES (1);

INSERT INTO USER (fname, lname ,email, password)
VALUES
('Madiba', 'Hudson-Quansah', 'mfac@gmail.com', '1411241789187772614611123143241611482201152118099233'),
('Madiba', 'Hudson-Quansah', 'mstu@gmail.com', '1411241789187772614611123143241611482201152118099233');
INSERT INTO faculty (uid, appdate, dept) VALUES
(2,"2024-12-02", "CS");
INSERT INTO student(uid, dob, major, enrolldate) 
VALUES
(3, "2004-12-02", "CS", "2024-12-02");

-- Add 30 students
INSERT INTO user (fname, lname, email, password)
SELECT CONCAT('Student', FLOOR(RAND() * 10000)),
       'LastName',
       CONCAT('student', FLOOR(RAND() * 10000), '@example.com'),
       '1411241789187772614611123143241611482201152118099233'
FROM (SELECT 1 UNION ALL SELECT 2 UNION ALL SELECT 3 UNION ALL SELECT 4 UNION ALL SELECT 5 UNION ALL SELECT 6 UNION ALL SELECT 7 UNION ALL SELECT 8 UNION ALL SELECT 9 UNION ALL SELECT 10) T1,
     (SELECT 1 UNION ALL SELECT 2 UNION ALL SELECT 3) T2
LIMIT 30;

INSERT INTO student (uid, dob, picture, major, enrolldate)
SELECT uid,
       DATE_ADD('2000-01-01', INTERVAL FLOOR(RAND() * 7300) DAY),
       NULL,
       ELT(FLOOR(1 + (RAND() * 7)), 'CS', 'BA', 'EN', 'ME', 'EE', 'CE', 'MA'),
       DATE_ADD('2020-01-01', INTERVAL FLOOR(RAND() * 1000) DAY)
FROM user
WHERE uid > 3;

-- Add 30 faculty members
INSERT INTO user (fname, lname, email, password)
SELECT CONCAT('Faculty', FLOOR(RAND() * 10000)),
       'LastName',
       CONCAT('faculty', FLOOR(RAND() * 10000), '@example.com'),
       '1411241789187772614611123143241611482201152118099233'
FROM (SELECT 1 UNION ALL SELECT 2 UNION ALL SELECT 3 UNION ALL SELECT 4 UNION ALL SELECT 5 UNION ALL SELECT 6 UNION ALL SELECT 7 UNION ALL SELECT 8 UNION ALL SELECT 9 UNION ALL SELECT 10) T1,
     (SELECT 1 UNION ALL SELECT 2 UNION ALL SELECT 3) T2
LIMIT 30;

INSERT INTO faculty (uid, appdate, dept)
SELECT uid,
       CURDATE(),
       ELT(FLOOR(1 + (RAND() * 4)), 'CS', 'HM', 'EN', 'BA')
FROM user
WHERE uid > 31;

-- Add 30 courses
-- Insert 10 courses with random attributes
INSERT INTO course (cname, credits, sem, capacity)
VALUES 
  ('Intro to Programming', 1.0, 'S1', 40),
  ('Linear Algebra', 1.0, 'S1', 40),
  ('Database Systems', 1.0, 'S2', 40),
  ('Marketing Principles', 0.5, 'S1', 30),
  ('Thermodynamics', 1.0, 'S2', 40),
  ('Digital Circuits', 0.5, 'S2', 30),
  ('Project Management', 1.0, 'S1', 40),
  ('Quantum Physics', 1.0, 'S2', 30),
  ('Artificial Intelligence', 1.0, 'S1', 40),
  ('Ethics in Engineering', 0.5, 'S2', 30);

-- Assign faculty to courses
INSERT INTO course_faculty (uid, cid)
SELECT F.uid, C.cid
FROM faculty F
CROSS JOIN course C
WHERE F.uid > 31
LIMIT 30;

-- Enroll students in courses
INSERT INTO enrollment (uid, cid, sem)
SELECT S.uid, C.cid, ELT(FLOOR(1 + (RAND() * 2)), 'S1', 'S2')
FROM student S
CROSS JOIN course C
LIMIT 200;

-- Reset schedule table to avoid duplicates
DELETE FROM schedule;

-- Variables for dynamic scheduling
SET @start_time = '08:00:00'; -- Start time for the first class
SET @end_time = '18:00:00'; -- End time for the last class
SET @current_time = @start_time; -- Initialize current time
SET @day_index = 1; -- Start with Monday
SET @max_days = 5; -- Total days in the week (Monday to Friday)

-- Loop through courses to assign non-colliding schedules
INSERT INTO schedule (cid, starttime, endtime, day)
SELECT C.cid,
       @current_time AS starttime,
       ADDTIME(@current_time, '02:00:00') AS endtime,
       ELT(@day_index, 'Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday') AS day
FROM course C
WHERE (@current_time := CASE
         WHEN ADDTIME(@current_time, '02:00:00') >= @end_time THEN '08:00:00'
         ELSE ADDTIME(@current_time, '02:00:00')
       END) IS NOT NULL
AND (@day_index := CASE
         WHEN ADDTIME(@current_time, '02:00:00') >= @end_time THEN @day_index + 1
         ELSE @day_index
       END) <= @max_days;


