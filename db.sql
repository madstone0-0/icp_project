drop database if exists records;

create database records;

use records;

create table user (
  uid varchar(8) primary key,
  fname varchar(50) not null,
  lname varchar(50) not null,
  email varchar(100) not null,
  password varchar(100) not null
);

create table admin (
  uid varchar(8) primary key,
  foreign key (uid) references user (uid)
);

create table student (
  uid varchar(8) primary key,
  dob date not null,
  picture longblob,
  major enum ('CS', 'BA', 'EN', 'ME', 'EE', 'CE', 'MA') not null,
  enrollDate date not null,
  foreign key (uid) references user (uid)
);

create table faculty (
  uid varchar(8) primary key,
  appDate date not null default (current_date()),
  dept enum ("CS", "HM", "EN", "BA") not null,
  foreign key (uid) references user (uid)
);

create table course (
  cid int auto_increment primary key,
  cName varchar(100) not null,
  credits double not null default 1.0,
  sem enum ('S1', 'S2') not null default 'S1' -- Semester with ENUM type
);

create table course_faculty (
  uid varchar(8) not null,
  cid int not null,
  primary key (uid, cid),
  foreign key (uid) references faculty (uid), -- Ensuring only faculty are linked to courses
  foreign key (cid) references course (cid)
);

create table enrollment (
  eid int auto_increment primary key,
  uid varchar(8) not null,
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
  ) not null,
  foreign key (uid) references student (uid), -- Ensuring only students are enrolled
  foreign key (cid) references course (cid)
);

-- Insert records into the `user` table
INSERT INTO user (uid, fname, lname, email, password) VALUES
  ('U001', 'Alice', 'Johnson', 'alice.johnson@example.com', 'password123'),
  ('U002', 'Bob', 'Smith', 'bob.smith@example.com', 'password456'),
  ('U003', 'Carol', 'Davis', 'carol.davis@example.com', 'password789'),
  ('U004', 'David', 'Brown', 'david.brown@example.com', 'password101'),
  ('U005', 'Eve', 'Wilson', 'eve.wilson@example.com', 'password202');

-- Insert records into the `admin` table
INSERT INTO admin (uid) VALUES
  ('U001'),  -- Alice is an admin
  ('U003');  -- Carol is also an admin

-- Insert records into the `student` table
INSERT INTO student (uid, dob, picture, major, enrollDate) VALUES
  ('U002', '2002-05-14', NULL, 'CS', '2021-09-01'),  -- Bob is a student
  ('U004', '2003-07-21', NULL, 'EN', '2022-09-01'),  -- David is a student
  ('U005', '2001-11-05', NULL, 'BA', '2021-09-01');  -- Eve is a student

-- Insert records into the `faculty` table
INSERT INTO faculty (uid, appDate, dept) VALUES
  ('U001', '2020-01-15', 'CS'),  -- Alice is a CS faculty member
  ('U003', '2019-03-22', 'BA');  -- Carol is a BA faculty member

-- Insert records into the `course` table
INSERT INTO course (cName, credits, sem) VALUES
  ('Data Structures', 3.0, 'S1'),
  ('Business Ethics', 2.0, 'S2'),
  ('Mechanics', 3.0, 'S1'),
  ('Calculus I', 4.0, 'S2'),
  ('Programming Fundamentals', 3.0, 'S1');

-- Insert records into the `course_faculty` table
INSERT INTO course_faculty (uid, cid) VALUES
  ('U001', 1),  -- Alice teaches Data Structures
  ('U001', 5),  -- Alice also teaches Programming Fundamentals
  ('U003', 2),  -- Carol teaches Business Ethics

-- Insert records into the `enrollment` table
INSERT INTO enrollment (uid, cid, sem, grade) VALUES
  ('U002', 1, 'S1', 'A'),    -- Bob enrolled in Data Structures and scored an A
  ('U002', 5, 'S1', 'B+'),   -- Bob in Programming Fundamentals with a B+
  ('U004', 3, 'S1', 'B'),    -- David enrolled in Mechanics and scored a B
  ('U004', 4, 'S2', 'C+'),   -- David in Calculus I with a C+
  ('U005', 2, 'S2', 'A+');   -- Eve enrolled in Business Ethics with an A+