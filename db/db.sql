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
foreign key (cid) references course (cid) ON DELETE cascade
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
CREATE INDEX idx_enrollment_sem ON enrollment (sem);

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

-- Initial Database population comment out to just have DDL

-- User table
INSERT
    INTO
    USER (
        fname,
        lname,
        email,
        password
    )
VALUES
(
    'Madiba',
    'Hudson-Quansah',
    'mhquansah@gmail.com',
    '1411241789187772614611123143241611482201152118099233'
);
-- Admin table
INSERT
    INTO
    admin (uid)
VALUES (1);

INSERT
    INTO
    USER (
        fname,
        lname ,
        email,
        password
    )
VALUES
(
    'Madiba',
    'Hudson-Quansah',
    'mfac@gmail.com',
    '1411241789187772614611123143241611482201152118099233'
),
(
    'Madiba',
    'Hudson-Quansah',
    'mstu@gmail.com',
    '1411241789187772614611123143241611482201152118099233'
);

INSERT
    INTO
    faculty (
        uid,
        appdate,
        dept
    )
VALUES
(
    2,
    "2024-12-02",
    "CS"
);

INSERT
    INTO
    student(
        uid,
        dob,
        major,
        enrolldate
    )
VALUES
(
    3,
    "2004-12-02",
    "CS",
    "2024-12-02"
);
-- Realistic first names arrays for diversity
SET
@first_names_male = 'James,John,Robert,Michael,William,David,Joseph,Thomas,Charles,Christopher,Daniel,Matthew,Anthony,Donald,Mark,Paul,Steven,Andrew,Kenneth,George,Joshua,Kevin,Brian,Edward,Ronald,Timothy,Jason,Jeffrey,Ryan,Gary,Nicholas,Eric,Stephen,Jonathan,Larry,Justin,Scott,Brandon,Frank,Benjamin,Gregory,Samuel,Raymond,Patrick,Alexander,Jack,Dennis,Jerry,Tyler,Aaron,Henry,Douglas,Jose,Peter,Adam,Nathan,Harold,Kyle,Carl,Jeremy,Keith,Roger,Gerald,Ethan,Arthur,Terry,Christian,Sean,Tyler,Ralph,Dean,Victor,Todd,Jesse,Richard,Shawn,Philip,Chris,Howard,Clarence,Dylan,Nicholas,Leonard,Craig,Phillip,Russell,Zachary,Troy,Cameron,Joel,Shane';

SET
@first_names_female = 'Mary,Elizabeth,Jennifer,Linda,Patricia,Barbara,Margaret,Susan,Alice,Dorothy,Lisa,Nancy,Karen,Betty,Helen,Sandra,Donna,Carol,Ruth,Sharon,Michelle,Laura,Sarah,Kimberly,Deborah,Jessica,Shirley,Cynthia,Angela,Melissa,Brenda,Amy,Anna,Rebecca,Katherine,Nicole,Pamela,Christine,Debra,Rachel,Carolyn,Frances,Maria,Heather,Diane,Julie,Joyce,Emma,Evelyn,Martha,Joan,Kelly,Christina,Lauren,Frances,Judy,Paula,Marilyn,Stephanie,Katherine,Elizabeth';

SET
@last_names = 'Smith,Johnson,Williams,Brown,Jones,Miller,Davis,Garcia,Rodriguez,Wilson,Martinez,Anderson,Taylor,Thomas,Hernandez,Moore,Martin,Jackson,Thompson,White,Lopez,Lee,Harris,Clark,Lewis,Robinson,Walker,Perez,Hall,Young,Allen,Sanchez,Wright,King,Scott,Green,Baker,Adams,Nelson,Hill,Ramirez,Campbell,Mitchell,Roberts,Carter,Phillips,Evans,Turner,Diaz,Parker,Cruz,Edwards,Collins,Reyes,Stewart,Morris,Morales,Murphy,Cook,Rogers,Gutierrez,Ortiz,Gomez,Murray,Freeman,Wells,Webb,Simpson,Stevens,Tucker,Porter,Hunter,Hicks,Crawford,Henry,Boyd,Mason,Morales,Kennedy,Warren,Dixon,Ramos,Reyes,Burns,Gordon,Shaw,Holmes,Rice,Robertson,Hunt,Black,Daniels,Palmer,Mills,Nichols,Grant,Knight,Ferguson,Rose,Stone,Hawkins,Dunn,Perkins,Hudson,Spencer,Gardner,Stephens,Payne,Pierce,Berry,Matthews,Arnold,Wagner,Willis,Ray,Watkins,Olson,Carroll,Duncan,Snyder,Hart,Cunningham,Bradley,Lane,Andrews,Ruiz,Harper,Fox,Riley,Armstrong,Carpenter,Weaver,Greene,Lawrence,Elliott,Chavez,Sims,Austin,Peters,Kelley,Franklin,Lawson,Fields,Gutierrez,Ryan,Schmidt,Carr,Vasquez,Castillo,Wheeler,Chapman,Oliver,Montgomery,Richards,Williamson,Johnston,Banks,Meyer,Bishop,Mccoy,Howell,Alvarez,Morrison,Hansen,Fernandez,Garza,Harvey,Little,Burton,Stanley,Nguyen,George,Jacobs,Reid,Kim,Fuller,Lynch,Dean,Gilbert,Garrett,Romero,Welch,Larson,Frazier,Burke,Hanson,Day,Mendoza,Moreno,Bowman,Medina,Fowler,Brewer,Hoffman,Carlson,Silva,Pearson,Holland,Douglas,Fleming,Jensen,Vargas,Byrd,Davidson,Hopkins,May,Terry,Herrera,Wade,Soto,Walters,Curtis,Neal,Caldwell,Lowe,Jennings,Barnett,Graves,Jimenez,Horton,Shelton,Barrett,Obrien,Castro,Sutton,Gregory,Mckinney,Lucas,Miles,Craig,Rodriquez,Chambers,Holt,Lambert,Fletcher,Watts,Bates,Hale,Rhodes,Pena,Beck,Newman,Haynes,Mcdaniel,Mendez,Bush,Vaughn,Parks,Dawson,Santiago,Norris,Hardy,Love,Steele,Curry,Yates,Wiley,Rowe,Sullivan,Nash,Crosby,Calderon,Joyce,Noble,Houser,Silva';
DELIMITER //
CREATE PROCEDURE generate_realistic_users()
BEGIN
    DECLARE i INT DEFAULT 0;
    DECLARE fname VARCHAR(50);
    DECLARE lname VARCHAR(50);
    DECLARE male_name_count INT;
    DECLARE female_name_count INT;
    DECLARE last_name_count INT;
    
    -- Count total names
    SET male_name_count = LENGTH(@first_names_male) - LENGTH(REPLACE(@first_names_male, ',', '')) + 1;
    SET female_name_count = LENGTH(@first_names_female) - LENGTH(REPLACE(@first_names_female, ',', '')) + 1;
    SET last_name_count = LENGTH(@last_names) - LENGTH(REPLACE(@last_names, ',', '')) + 1;
    
    DELETE FROM enrollment WHERE 1=1;
    DELETE FROM student WHERE uid > 3;
    DELETE FROM user WHERE uid > 3;
    
    WHILE i < 10 DO
        IF RAND() < 0.5 THEN
            SET fname = SUBSTRING_INDEX(SUBSTRING_INDEX(@first_names_male, ',', 1 + FLOOR(RAND() * male_name_count)), ',', -1);
        ELSE
            SET fname = SUBSTRING_INDEX(SUBSTRING_INDEX(@first_names_female, ',', 1 + FLOOR(RAND() * female_name_count)), ',', -1);
        END IF;
        
        SET lname = SUBSTRING_INDEX(SUBSTRING_INDEX(@last_names, ',', 1 + FLOOR(RAND() * last_name_count)), ',', -1);
        
        INSERT INTO user (fname, lname, email, password)
        VALUES (
            fname,
            lname,
            CONCAT(LOWER(fname), LOWER(lname), FLOOR(RAND() * 1000), '@example.com'),
            '1411241789187772614611123143241611482201152118099233'
        );
        
        SET i = i + 1;
    END WHILE;
END //

CREATE PROCEDURE generate_realistic_faculty()
BEGIN
    DECLARE i INT DEFAULT 0;
    DECLARE fname VARCHAR(50);
    DECLARE lname VARCHAR(50);
    DECLARE male_name_count INT;
    DECLARE female_name_count INT;
    DECLARE last_name_count INT;
    
    -- Count total names
    SET male_name_count = LENGTH(@first_names_male) - LENGTH(REPLACE(@first_names_male, ',', '')) + 1;
    SET female_name_count = LENGTH(@first_names_female) - LENGTH(REPLACE(@first_names_female, ',', '')) + 1;
    SET last_name_count = LENGTH(@last_names) - LENGTH(REPLACE(@last_names, ',', '')) + 1;
    
    DELETE FROM course_faculty WHERE 1=1;
    DELETE FROM faculty WHERE uid > 31;
    DELETE FROM user WHERE uid > 31;
    
    WHILE i < 10 DO
        IF RAND() < 0.5 THEN
            SET fname = SUBSTRING_INDEX(SUBSTRING_INDEX(@first_names_male, ',', 1 + FLOOR(RAND() * male_name_count)), ',', -1);
        ELSE
            SET fname = SUBSTRING_INDEX(SUBSTRING_INDEX(@first_names_female, ',', 1 + FLOOR(RAND() * female_name_count)), ',', -1);
        END IF;
        
        SET lname = SUBSTRING_INDEX(SUBSTRING_INDEX(@last_names, ',', 1 + FLOOR(RAND() * last_name_count)), ',', -1);
        
        INSERT INTO user (fname, lname, email, password)
        VALUES (
            fname,
            lname,
            CONCAT('prof', LOWER(fname), LOWER(lname), FLOOR(RAND() * 1000), '@university.edu'),
            '1411241789187772614611123143241611482201152118099233'
        );
        
        SET i = i + 1;
    END WHILE;
END //
DELIMITER ;

-- Call these procedures to generate realistic names
CALL generate_realistic_users();

CALL generate_realistic_faculty();
-- After generating users, insert students and faculty as before
INSERT
    INTO
    student (
        uid,
        dob,
        picture,
        major,
        enrolldate
    )
SELECT
    uid,
       DATE_ADD('2000-01-01', INTERVAL FLOOR(RAND() * 7300) DAY),
       NULL,
       ELT(FLOOR(1 + (RAND() * 7)), 'CS', 'BA', 'EN', 'ME', 'EE', 'CE', 'MA'),
       DATE_ADD('2020-01-01', INTERVAL FLOOR(RAND() * 1000) DAY)
FROM
    USER u
WHERE
    uid > 3 AND u.email NOT LIKE "prof%";

INSERT
    INTO
    faculty (
        uid,
        appdate,
        dept
    )
SELECT
    uid,
       CURDATE(),
       ELT(FLOOR(1 + (RAND() * 4)), 'CS', 'HM', 'EN', 'BA')
FROM
    USER u
WHERE
   uid > 11 and u.email LIKE "prof%";


-- Insert 10 courses with random attributes
INSERT
    INTO
    course (
        cname,
        credits,
        sem,
        capacity
    )
VALUES 
  (
    'Intro to Programming',
    1.0,
    'S1',
    40
),
  (
    'Linear Algebra',
    1.0,
    'S1',
    40
),
  (
    'Database Systems',
    1.0,
    'S2',
    40
),
  (
    'Marketing Principles',
    0.5,
    'S1',
    30
),
  (
    'Thermodynamics',
    1.0,
    'S2',
    40
),
  (
    'Digital Circuits',
    0.5,
    'S2',
    30
),
  (
    'Project Management',
    1.0,
    'S1',
    40
),
  (
    'Quantum Physics',
    1.0,
    'S2',
    30
),
  (
    'Artificial Intelligence',
    1.0,
    'S1',
    40
),
  (
    'Ethics in Engineering',
    0.5,
    'S2',
    30
);
-- Assign faculty to courses
DELIMITER //

CREATE PROCEDURE assign_faculty_to_courses()
BEGIN
    DECLARE done INT DEFAULT FALSE;
    DECLARE faculty_id INT;
    DECLARE course_id INT;
    DECLARE course_dept VARCHAR(50);
    DECLARE sem_required ENUM('S1', 'S2');
    DECLARE cur CURSOR FOR
        SELECT cid, sem, SUBSTRING_INDEX(cname, ' ', 1) AS dept
        FROM course;
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = TRUE;

    -- Temporary table to track faculty assignments
DROP TABLE IF EXISTS temp_faculty_workload;
    CREATE TEMPORARY TABLE temp_faculty_workload (
        uid INT PRIMARY KEY,
        dept VARCHAR(10),
        workload INT DEFAULT 0
    );

    -- Populate faculty workload
    INSERT INTO temp_faculty_workload (uid, dept)
    SELECT uid, dept FROM faculty;

    OPEN cur;

    course_loop: LOOP
        FETCH cur INTO course_id, sem_required, course_dept;
        IF done THEN
            LEAVE course_loop;
        END IF;

        -- Assign faculty to course
        SET faculty_id = (
            SELECT uid
            FROM temp_faculty_workload
            ORDER BY workload ASC, RAND()
            LIMIT 1
        );

        -- If a faculty member is found, assign the course
        IF faculty_id IS NOT NULL THEN
            INSERT INTO course_faculty (uid, cid)
            VALUES (faculty_id, course_id);

            -- Update workload
            UPDATE temp_faculty_workload
            SET workload = workload + 1
            WHERE uid = faculty_id;
        END IF;
    END LOOP;

    CLOSE cur;

    -- Drop temporary table
    DROP TEMPORARY TABLE temp_faculty_workload;
END //

DELIMITER ;
CALL assign_faculty_to_courses();


-- Enroll students in courses
INSERT
    INTO
    enrollment (
        uid,
        cid,
        sem
    )
SELECT
    S.uid,
    C.cid,
    C.sem
FROM
    student S
CROSS JOIN course C
LIMIT 200;

-- Variables for dynamic scheduling
SET
@start_time = '08:00:00';
-- Start time for the first class
SET
@end_time = '18:00:00';
-- End time for the last class
SET
@current_time = @start_time;
-- Initialize current time
SET
@day_index = 1;
-- Start with Monday
SET
@max_days = 5;
-- Total days in the week (Monday to Friday)
-- Loop through courses to assign non-colliding schedules
INSERT
    INTO
    schedule (
        cid,
        starttime,
        endtime,
        DAY
    )
SELECT
    C.cid,
       @current_time AS starttime,
       ADDTIME(@current_time, '02:00:00') AS endtime,
       ELT(@day_index, 'Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday') AS DAY
FROM
    course C
WHERE
    (
        @current_time := CASE
            WHEN ADDTIME(@current_time, '02:00:00') >= @end_time THEN '08:00:00'
            ELSE ADDTIME(@current_time, '02:00:00')
        END
    ) IS NOT NULL
    AND (
        @day_index := CASE
            WHEN ADDTIME(@current_time, '02:00:00') >= @end_time THEN @day_index + 1
            ELSE @day_index
        END
    ) <= @max_days;


