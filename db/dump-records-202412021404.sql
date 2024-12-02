-- MySQL dump 10.13  Distrib 8.0.19, for Win64 (x86_64)
--
-- Host: localhost    Database: records
-- ------------------------------------------------------
-- Server version	8.0.40

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `admin`
--

DROP TABLE IF EXISTS `admin`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `admin` (
  `uid` int NOT NULL,
  PRIMARY KEY (`uid`),
  CONSTRAINT `admin_ibfk_1` FOREIGN KEY (`uid`) REFERENCES `user` (`uid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `admin`
--

LOCK TABLES `admin` WRITE;
/*!40000 ALTER TABLE `admin` DISABLE KEYS */;
INSERT INTO `admin` VALUES (1),(2);
/*!40000 ALTER TABLE `admin` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `audit_log`
--

DROP TABLE IF EXISTS `audit_log`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `audit_log` (
  `log_id` int NOT NULL AUTO_INCREMENT,
  `action` varchar(255) NOT NULL,
  `user_id` int NOT NULL,
  `timestamp` timestamp NULL DEFAULT CURRENT_TIMESTAMP,
  `details` text,
  PRIMARY KEY (`log_id`)
) ENGINE=InnoDB AUTO_INCREMENT=407 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `audit_log`
--

LOCK TABLES `audit_log` WRITE;
/*!40000 ALTER TABLE `audit_log` DISABLE KEYS */;
INSERT INTO `audit_log` VALUES (1,'AdminSignUp',1,'2024-12-01 21:30:44',NULL),(2,'AdminLogin',1,'2024-12-01 21:30:44',NULL),(3,'AdminSignUp',2,'2024-12-01 21:30:44',NULL),(4,'AdminLogin',2,'2024-12-01 21:30:45',NULL),(5,'StudentSignUp',3,'2024-12-01 21:30:45',NULL),(6,'StudentLogin',3,'2024-12-01 21:30:45',NULL),(7,'FacultySignUp',4,'2024-12-01 21:30:45',NULL),(8,'FacultyLogin',4,'2024-12-01 21:30:45',NULL),(9,'AdminLogin',1,'2024-12-01 21:30:45',NULL),(10,'Added new course',1,'2024-12-01 21:30:45','Course: Intro to Programming'),(11,'Added new course',1,'2024-12-01 21:30:45','Course: Data Structures'),(12,'Added new course',1,'2024-12-01 21:30:45','Course: Algorithms'),(13,'Added new course',1,'2024-12-01 21:30:45','Course: Advanced Programming'),(14,'Viewed all courses',1,'2024-12-01 21:30:45',NULL),(15,'Updated course',1,'2024-12-01 21:30:45','Course: Updated Advanced Programming'),(16,'Viewed all courses',1,'2024-12-01 21:30:45',NULL),(17,'Viewed remaining capacity',1,'2024-12-01 21:30:45','Course ID: 4'),(18,'Viewed prerequisite courses',1,'2024-12-01 21:30:45','Course ID: 4'),(19,'Deleted course',1,'2024-12-01 21:30:45','Course ID: 4'),(20,'StudentLogin',3,'2024-12-01 21:30:46',NULL),(21,'Viewed remaining capacity',3,'2024-12-01 21:30:46','Course ID: 1'),(22,'Enrolled user in course',3,'2024-12-01 21:30:46','Course: UID: 3 CID: 1 EID: 1'),(23,'AdminLogin',2,'2024-12-01 21:30:58',NULL),(24,'AdminLogin',2,'2024-12-01 21:32:24',NULL),(26,'AdminLogin',2,'2024-12-01 21:35:23',NULL),(27,'Issued payments',2,'2024-12-01 21:35:40','Issued payments to 1 students'),(28,'Viewed all payments',2,'2024-12-01 21:36:04',NULL),(29,'AdminLogin',2,'2024-12-01 21:36:32',NULL),(30,'Viewed all payments',2,'2024-12-01 21:36:37',NULL),(31,'Viewed all payments',2,'2024-12-01 21:37:03',NULL),(32,'Get all students',2,'2024-12-01 21:38:10',NULL),(33,'AdminLogin',2,'2024-12-01 21:39:10',NULL),(34,'Viewed all payments',2,'2024-12-01 21:39:19',NULL),(35,'Viewed all enrollments',2,'2024-12-01 21:39:28',NULL),(36,'Get all faculty',2,'2024-12-01 21:39:34',NULL),(37,'Viewed all payments',2,'2024-12-01 21:39:38',NULL),(38,'AdminLogin',2,'2024-12-01 21:41:45',NULL),(39,'Issued payments',2,'2024-12-01 21:42:06','Issued payments to 0 students'),(40,'Issued payments',2,'2024-12-01 21:42:25','Issued payments to 1 students'),(41,'Viewed all payments',2,'2024-12-01 21:42:42',NULL),(42,'StudentLogin',3,'2024-12-01 21:54:15',NULL),(43,'AdminLogin',2,'2024-12-01 22:44:47',NULL),(44,'Viewed all outstanding payments',2,'2024-12-01 22:44:51',NULL),(45,'Viewed all payments',2,'2024-12-01 22:44:58',NULL),(46,'Viewed all courses',2,'2024-12-01 22:45:04',NULL),(47,'Viewed all courses',2,'2024-12-01 22:45:08',NULL),(48,'Viewed all courses',2,'2024-12-01 22:45:12',NULL),(49,'Viewed all courses',2,'2024-12-01 22:45:12',NULL),(50,'Viewed all courses',2,'2024-12-01 22:45:12',NULL),(51,'Viewed transcript',2,'2024-12-01 22:45:20','Student ID: 3'),(52,'Viewed transcript',2,'2024-12-01 22:45:27','Student ID: 3'),(53,'AdminLogin',2,'2024-12-01 23:19:09',NULL),(54,'AdminLogin',2,'2024-12-01 23:20:32',NULL),(55,'Viewed courses by faculty',2,'2024-12-01 23:20:39','Faculty ID: 4'),(56,'Viewed all courses',2,'2024-12-01 23:20:39',NULL),(57,'Viewed courses by faculty',2,'2024-12-01 23:20:39','Faculty ID: 4'),(58,'Viewed all courses',2,'2024-12-01 23:20:39',NULL),(59,'Viewed all courses',2,'2024-12-01 23:20:55',NULL),(60,'Added new course',2,'2024-12-01 23:21:07','Course: Rizz 101'),(61,'Assigned faculty to course',2,'2024-12-01 23:21:08','Faculty ID: 4 Course ID: 5'),(62,'Viewed all courses',2,'2024-12-01 23:21:08',NULL),(63,'Viewed all payments',2,'2024-12-01 23:21:13',NULL),(64,'Viewed courses by faculty',2,'2024-12-01 23:21:20','Faculty ID: 4'),(65,'Viewed all courses',2,'2024-12-01 23:21:20',NULL),(66,'Viewed courses by faculty',2,'2024-12-01 23:21:20','Faculty ID: 4'),(67,'Viewed all courses',2,'2024-12-01 23:21:20',NULL),(68,'Viewed courses by faculty',2,'2024-12-01 23:21:21','Faculty ID: 4'),(69,'Viewed all courses',2,'2024-12-01 23:21:21',NULL),(70,'AdminLogin',2,'2024-12-01 23:21:57',NULL),(71,'Viewed courses by faculty',2,'2024-12-01 23:22:02','Faculty ID: 4'),(72,'Viewed all courses',2,'2024-12-01 23:22:02',NULL),(73,'Viewed courses by faculty',2,'2024-12-01 23:22:02','Faculty ID: 4'),(74,'Viewed all courses',2,'2024-12-01 23:22:02',NULL),(75,'AdminLogin',2,'2024-12-01 23:22:26',NULL),(76,'Viewed courses by faculty',2,'2024-12-01 23:22:30','Faculty ID: 4'),(77,'Viewed all courses',2,'2024-12-01 23:22:30',NULL),(78,'Viewed courses by faculty',2,'2024-12-01 23:22:30','Faculty ID: 4'),(79,'Viewed all courses',2,'2024-12-01 23:22:30',NULL),(80,'Viewed transcript',2,'2024-12-01 23:22:42','Student ID: 3'),(81,'Viewed transcript',2,'2024-12-01 23:22:51','Student ID: 3'),(82,'Viewed all courses',2,'2024-12-01 23:23:03',NULL),(83,'Viewed general schedule',2,'2024-12-01 23:23:08',NULL),(84,'Get all students',2,'2024-12-01 23:23:12',NULL),(85,'Viewed all courses',2,'2024-12-01 23:23:20',NULL),(86,'Viewed all courses',2,'2024-12-01 23:23:20',NULL),(87,'Viewed all courses',2,'2024-12-01 23:23:20',NULL),(88,'Viewed all courses',2,'2024-12-01 23:23:21',NULL),(89,'Viewed all courses',2,'2024-12-01 23:23:22',NULL),(90,'Viewed prerequisite courses',2,'2024-12-01 23:23:22','Course ID: 5'),(91,'StudentLogin',3,'2024-12-01 23:23:33',NULL),(92,'Viewed transcript',3,'2024-12-01 23:23:40',NULL),(93,'Viewed all courses',3,'2024-12-01 23:23:50',NULL),(94,'Viewed remaining capacity',3,'2024-12-01 23:23:50','Course ID: 1'),(95,'Viewed remaining capacity',3,'2024-12-01 23:23:50','Course ID: 1'),(96,'Viewed remaining capacity',3,'2024-12-01 23:23:51','Course ID: 3'),(97,'Viewed prerequisite courses',3,'2024-12-01 23:23:52','Course ID: 5'),(98,'Viewed remaining capacity',3,'2024-12-01 23:23:52','Course ID: 5'),(99,'Viewed remaining capacity',3,'2024-12-01 23:23:53','Course ID: 5'),(100,'Viewed remaining capacity',3,'2024-12-01 23:23:56','Course ID: 2'),(101,'Viewed remaining capacity',3,'2024-12-01 23:23:57','Course ID: 2'),(102,'Enrolled user in course',3,'2024-12-01 23:23:57','Course: UID: 3 CID: 2 EID: 2'),(103,'Viewed remaining capacity',3,'2024-12-01 23:23:59','Course ID: 3'),(104,'Viewed remaining capacity',3,'2024-12-01 23:23:59','Course ID: 3'),(105,'Enrolled user in course',3,'2024-12-01 23:24:00','Course: UID: 3 CID: 3 EID: 3'),(106,'Viewed prerequisite courses',3,'2024-12-01 23:24:01','Course ID: 5'),(107,'Viewed remaining capacity',3,'2024-12-01 23:24:01','Course ID: 5'),(108,'Viewed remaining capacity',3,'2024-12-01 23:24:02','Course ID: 5'),(109,'Enrolled user in course',3,'2024-12-01 23:24:02','Course: UID: 3 CID: 5 EID: 4'),(110,'Viewed transcript',3,'2024-12-01 23:24:07',NULL),(111,'Viewed all courses',3,'2024-12-01 23:24:14',NULL),(112,'Viewed remaining capacity',3,'2024-12-01 23:24:14','Course ID: 1'),(113,'Viewed remaining capacity',3,'2024-12-01 23:24:14','Course ID: 1'),(114,'AdminLogin',2,'2024-12-02 08:22:20',NULL),(115,'Viewed courses by faculty',2,'2024-12-02 08:22:27','Faculty ID: 4'),(116,'Viewed all courses',2,'2024-12-02 08:22:27',NULL),(117,'Viewed courses by faculty',2,'2024-12-02 08:22:27','Faculty ID: 4'),(118,'Viewed all courses',2,'2024-12-02 08:22:27',NULL),(119,'Assigned faculty to course',2,'2024-12-02 08:22:31','Faculty ID: 4 Course ID: 1'),(120,'Updated faculty assignment',2,'2024-12-02 08:22:31','Faculty ID: 4 Course ID: 5'),(121,'Viewed all courses',2,'2024-12-02 08:22:45',NULL),(122,'Viewed all courses',2,'2024-12-02 08:22:45',NULL),(123,'Viewed all courses',2,'2024-12-02 08:22:45',NULL),(124,'Viewed all courses',2,'2024-12-02 08:22:46',NULL),(125,'Viewed all courses',2,'2024-12-02 08:22:47',NULL),(126,'Viewed all courses',2,'2024-12-02 08:22:48',NULL),(127,'Viewed all courses',2,'2024-12-02 08:22:48',NULL),(128,'Viewed all courses',2,'2024-12-02 08:22:49',NULL),(129,'Viewed all courses',2,'2024-12-02 08:22:49',NULL),(130,'Viewed prerequisite courses',2,'2024-12-02 08:22:49','Course ID: 5'),(131,'StudentLogin',3,'2024-12-02 08:23:01',NULL),(132,'Viewed all courses',3,'2024-12-02 08:23:11',NULL),(133,'Viewed remaining capacity',3,'2024-12-02 08:23:11','Course ID: 1'),(134,'Viewed remaining capacity',3,'2024-12-02 08:23:11','Course ID: 1'),(135,'Viewed remaining capacity',3,'2024-12-02 08:23:13','Course ID: 2'),(136,'Viewed remaining capacity',3,'2024-12-02 08:23:13','Course ID: 3'),(137,'Viewed remaining capacity',3,'2024-12-02 08:23:14','Course ID: 3'),(138,'Viewed prerequisite courses',3,'2024-12-02 08:23:15','Course ID: 5'),(139,'Viewed remaining capacity',3,'2024-12-02 08:23:15','Course ID: 5'),(140,'AdminLogin',2,'2024-12-02 08:23:31',NULL),(141,'Viewed courses by faculty',2,'2024-12-02 08:23:38','Faculty ID: 4'),(142,'Viewed all courses',2,'2024-12-02 08:23:38',NULL),(143,'Viewed courses by faculty',2,'2024-12-02 08:23:38','Faculty ID: 4'),(144,'Viewed all courses',2,'2024-12-02 08:23:38',NULL),(145,'Updated faculty assignment',2,'2024-12-02 08:23:40','Faculty ID: 4 Course ID: 5'),(146,'AdminLogin',2,'2024-12-02 08:25:43',NULL),(147,'Viewed courses by faculty',2,'2024-12-02 08:26:01','Faculty ID: 4'),(148,'Viewed all courses',2,'2024-12-02 08:26:01',NULL),(149,'Viewed courses by faculty',2,'2024-12-02 08:26:01','Faculty ID: 4'),(150,'Viewed all courses',2,'2024-12-02 08:26:01',NULL),(151,'Assigned faculty to course',2,'2024-12-02 08:26:10','Faculty ID: 4 Course ID: 5'),(152,'Viewed courses by faculty',2,'2024-12-02 08:26:29','Faculty ID: 4'),(153,'Viewed all courses',2,'2024-12-02 08:26:29',NULL),(154,'Viewed courses by faculty',2,'2024-12-02 08:26:29','Faculty ID: 4'),(155,'Viewed all courses',2,'2024-12-02 08:26:29',NULL),(156,'AdminLogin',2,'2024-12-02 08:27:40',NULL),(157,'Viewed courses by faculty',2,'2024-12-02 08:27:46','Faculty ID: 4'),(158,'Viewed all courses',2,'2024-12-02 08:27:46',NULL),(159,'Viewed courses by faculty',2,'2024-12-02 08:27:46','Faculty ID: 4'),(160,'Viewed all courses',2,'2024-12-02 08:27:46',NULL),(161,'AdminLogin',2,'2024-12-02 08:29:54',NULL),(162,'Viewed courses by faculty',2,'2024-12-02 08:30:02','Faculty ID: 4'),(163,'Viewed all courses',2,'2024-12-02 08:30:02',NULL),(164,'Viewed courses by faculty',2,'2024-12-02 08:30:02','Faculty ID: 4'),(165,'Viewed all courses',2,'2024-12-02 08:30:02',NULL),(166,'Assigned faculty to course',2,'2024-12-02 08:30:21','Faculty ID: 4 Course ID: 1'),(167,'Assigned faculty to course',2,'2024-12-02 08:30:21','Faculty ID: 4 Course ID: 2'),(168,'Assigned faculty to course',2,'2024-12-02 08:30:21','Faculty ID: 4 Course ID: 3'),(169,'Assigned faculty to course',2,'2024-12-02 08:30:21','Faculty ID: 4 Course ID: 5'),(170,'FacultyLogin',4,'2024-12-02 08:45:34',NULL),(171,'FacultyLogin',4,'2024-12-02 08:48:13',NULL),(172,'Viewed courses by faculty',4,'2024-12-02 08:48:15','Faculty ID: 4'),(173,'AdminLogin',2,'2024-12-02 11:50:56',NULL),(174,'Viewed all courses',2,'2024-12-02 11:51:00',NULL),(175,'Viewed all outstanding payments',2,'2024-12-02 11:51:05',NULL),(176,'Viewed general schedule',2,'2024-12-02 11:51:10',NULL),(177,'Viewed courses by faculty',2,'2024-12-02 11:51:18','Faculty ID: 4'),(178,'Viewed all courses',2,'2024-12-02 11:51:18',NULL),(179,'Viewed courses by faculty',2,'2024-12-02 11:51:18','Faculty ID: 4'),(180,'Viewed all courses',2,'2024-12-02 11:51:18',NULL),(181,'Get all students',2,'2024-12-02 11:51:38',NULL),(182,'Viewed all enrollments',2,'2024-12-02 11:51:42',NULL),(183,'FacultyLogin',4,'2024-12-02 11:52:06',NULL),(184,'Viewed courses by faculty',4,'2024-12-02 11:52:07','Faculty ID: 4'),(185,'FacultyLogin',4,'2024-12-02 12:20:03',NULL),(186,'Viewed courses by faculty',4,'2024-12-02 12:20:07','Faculty ID: 4'),(187,'FacultyLogin',4,'2024-12-02 12:21:24',NULL),(188,'Viewed courses by faculty',4,'2024-12-02 12:21:27','Faculty ID: 4'),(189,'Viewed courses by faculty',4,'2024-12-02 12:21:27','Faculty ID: 4'),(190,'Viewed all enrollments in course',4,'2024-12-02 12:21:29','Course ID: 1'),(191,'Viewed all enrollments in course',4,'2024-12-02 12:21:39','Course ID: 3'),(192,'Viewed courses by faculty',4,'2024-12-02 12:21:41','Faculty ID: 4'),(193,'Viewed all enrollments in course',4,'2024-12-02 12:21:42','Course ID: 2'),(194,'Viewed all enrollments in course',4,'2024-12-02 12:21:43','Course ID: 2'),(195,'Viewed all enrollments in course',4,'2024-12-02 12:21:43','Course ID: 2'),(196,'Viewed all enrollments in course',4,'2024-12-02 12:21:44','Course ID: 5'),(197,'Viewed all enrollments in course',4,'2024-12-02 12:21:45','Course ID: 2'),(198,'Viewed courses by faculty',4,'2024-12-02 12:21:47','Faculty ID: 4'),(199,'Viewed courses by faculty',4,'2024-12-02 12:22:02','Faculty ID: 4'),(200,'Viewed courses by faculty',4,'2024-12-02 12:22:03','Faculty ID: 4'),(201,'Viewed all enrollments in course',4,'2024-12-02 12:22:04','Course ID: 2'),(202,'Viewed all enrollments in course',4,'2024-12-02 12:22:05','Course ID: 5'),(203,'Viewed all enrollments in course',4,'2024-12-02 12:22:06','Course ID: 2'),(204,'FacultyLogin',4,'2024-12-02 12:25:14',NULL),(205,'Viewed courses by faculty',4,'2024-12-02 12:25:17','Faculty ID: 4'),(206,'Viewed courses by faculty',4,'2024-12-02 12:25:17','Faculty ID: 4'),(207,'Viewed all enrollments in course',4,'2024-12-02 12:25:18','Course ID: 1'),(208,'Viewed all enrollments in course',4,'2024-12-02 12:25:24','Course ID: 3'),(209,'Viewed all enrollments in course',4,'2024-12-02 12:25:26','Course ID: 1'),(210,'Viewed all enrollments in course',4,'2024-12-02 12:25:26','Course ID: 3'),(211,'Viewed courses by faculty',4,'2024-12-02 12:25:28','Faculty ID: 4'),(212,'Viewed all enrollments in course',4,'2024-12-02 12:25:30','Course ID: 5'),(213,'Viewed all enrollments in course',4,'2024-12-02 12:25:30','Course ID: 2'),(214,'Viewed courses by faculty',4,'2024-12-02 12:25:32','Faculty ID: 4'),(215,'Viewed all enrollments in course',4,'2024-12-02 12:25:33','Course ID: 1'),(216,'Viewed all enrollments in course',4,'2024-12-02 12:25:34','Course ID: 3'),(217,'Viewed all enrollments in course',4,'2024-12-02 12:25:35','Course ID: 1'),(218,'Viewed all enrollments in course',4,'2024-12-02 12:25:36','Course ID: 3'),(219,'Viewed all enrollments in course',4,'2024-12-02 12:25:37','Course ID: 1'),(220,'Viewed all enrollments in course',4,'2024-12-02 12:25:38','Course ID: 1'),(221,'Viewed all enrollments in course',4,'2024-12-02 12:25:38','Course ID: 3'),(222,'Viewed courses by faculty',4,'2024-12-02 12:25:39','Faculty ID: 4'),(223,'Viewed courses by faculty',4,'2024-12-02 12:25:41','Faculty ID: 4'),(224,'Viewed courses by faculty',4,'2024-12-02 12:25:42','Faculty ID: 4'),(225,'Viewed all enrollments in course',4,'2024-12-02 12:25:44','Course ID: 2'),(226,'FacultyLogin',4,'2024-12-02 12:32:35',NULL),(227,'Viewed courses by faculty',4,'2024-12-02 12:32:36','Faculty ID: 4'),(228,'Viewed courses by faculty',4,'2024-12-02 12:32:40','Faculty ID: 4'),(229,'Viewed courses by faculty',4,'2024-12-02 12:32:40','Faculty ID: 4'),(230,'Viewed all enrollments in course',4,'2024-12-02 12:32:41','Course ID: 1'),(231,'Viewed all enrollments in course',4,'2024-12-02 12:32:53','Course ID: 3'),(232,'Viewed all enrollments in course',4,'2024-12-02 12:32:55','Course ID: 1'),(233,'Viewed all enrollments in course',4,'2024-12-02 12:33:03','Course ID: 3'),(234,'Viewed courses by faculty',4,'2024-12-02 12:33:05','Faculty ID: 4'),(235,'Viewed all enrollments in course',4,'2024-12-02 12:33:06','Course ID: 2'),(236,'Viewed all enrollments in course',4,'2024-12-02 12:33:09','Course ID: 2'),(237,'Viewed all enrollments in course',4,'2024-12-02 12:33:11','Course ID: 2'),(238,'Viewed courses by faculty',4,'2024-12-02 12:33:13','Faculty ID: 4'),(239,'Viewed all enrollments in course',4,'2024-12-02 12:33:24','Course ID: 3'),(240,'Viewed all enrollments in course',4,'2024-12-02 12:33:25','Course ID: 1'),(241,'Viewed all enrollments in course',4,'2024-12-02 12:33:26','Course ID: 3'),(242,'Viewed all enrollments in course',4,'2024-12-02 12:33:27','Course ID: 1'),(243,'Viewed courses by faculty',4,'2024-12-02 12:33:28','Faculty ID: 4'),(244,'Viewed courses by faculty',4,'2024-12-02 12:33:30','Faculty ID: 4'),(245,'Viewed all enrollments in course',4,'2024-12-02 12:33:31','Course ID: 1'),(246,'Viewed all enrollments in course',4,'2024-12-02 12:33:34','Course ID: 3'),(247,'Viewed courses by faculty',4,'2024-12-02 12:35:03','Faculty ID: 4'),(248,'Viewed all enrollments in course',4,'2024-12-02 12:35:04','Course ID: 5'),(249,'Viewed all enrollments in course',4,'2024-12-02 12:35:04','Course ID: 2'),(250,'Viewed all enrollments in course',4,'2024-12-02 12:35:05','Course ID: 5'),(251,'Viewed all enrollments in course',4,'2024-12-02 12:35:05','Course ID: 2'),(252,'Viewed all enrollments in course',4,'2024-12-02 12:35:06','Course ID: 5'),(253,'Viewed all enrollments in course',4,'2024-12-02 12:35:06','Course ID: 2'),(254,'Viewed all enrollments in course',4,'2024-12-02 12:35:07','Course ID: 5'),(255,'FacultyLogin',4,'2024-12-02 12:43:18',NULL),(256,'Viewed courses by faculty',4,'2024-12-02 12:43:20','Faculty ID: 4'),(257,'Viewed courses by faculty',4,'2024-12-02 12:43:20','Faculty ID: 4'),(258,'Viewed all enrollments in course',4,'2024-12-02 12:43:22','Course ID: 1'),(259,'Viewed all enrollments in course',4,'2024-12-02 12:43:25','Course ID: 1'),(260,'Viewed all enrollments in course',4,'2024-12-02 12:43:26','Course ID: 3'),(261,'Viewed all enrollments in course',4,'2024-12-02 12:43:27','Course ID: 1'),(262,'Viewed all enrollments in course',4,'2024-12-02 12:43:47','Course ID: 1'),(263,'Viewed all enrollments in course',4,'2024-12-02 12:43:47','Course ID: 3'),(264,'Viewed courses by faculty',4,'2024-12-02 12:43:49','Faculty ID: 4'),(265,'Viewed courses by faculty',4,'2024-12-02 12:43:50','Faculty ID: 4'),(266,'Viewed all enrollments in course',4,'2024-12-02 12:43:51','Course ID: 2'),(267,'Viewed all enrollments in course',4,'2024-12-02 12:43:52','Course ID: 5'),(268,'Viewed all enrollments in course',4,'2024-12-02 12:43:53','Course ID: 5'),(269,'Viewed all enrollments in course',4,'2024-12-02 12:43:54','Course ID: 2'),(270,'Viewed all enrollments in course',4,'2024-12-02 12:43:56','Course ID: 2'),(271,'Viewed all enrollments in course',4,'2024-12-02 12:44:08','Course ID: 2'),(272,'Viewed all enrollments in course',4,'2024-12-02 12:44:09','Course ID: 2'),(273,'FacultyLogin',4,'2024-12-02 12:48:37',NULL),(274,'Viewed courses by faculty',4,'2024-12-02 12:48:41','Faculty ID: 4'),(275,'Viewed courses by faculty',4,'2024-12-02 12:48:41','Faculty ID: 4'),(276,'Viewed all enrollments in course',4,'2024-12-02 12:48:43','Course ID: 1'),(277,'FacultyLogin',4,'2024-12-02 12:50:44',NULL),(278,'Viewed courses by faculty',4,'2024-12-02 12:50:46','Faculty ID: 4'),(279,'Viewed courses by faculty',4,'2024-12-02 12:50:46','Faculty ID: 4'),(280,'Viewed all enrollments in course',4,'2024-12-02 12:50:48','Course ID: 3'),(281,'FacultyLogin',4,'2024-12-02 12:51:46',NULL),(282,'Viewed courses by faculty',4,'2024-12-02 12:51:49','Faculty ID: 4'),(283,'Viewed courses by faculty',4,'2024-12-02 12:51:49','Faculty ID: 4'),(284,'Viewed all enrollments in course',4,'2024-12-02 12:51:50','Course ID: 1'),(285,'Viewed all enrollments in course',4,'2024-12-02 12:52:02','Course ID: 1'),(286,'FacultyLogin',4,'2024-12-02 12:53:16',NULL),(287,'Viewed courses by faculty',4,'2024-12-02 12:53:20','Faculty ID: 4'),(288,'Viewed courses by faculty',4,'2024-12-02 12:53:21','Faculty ID: 4'),(289,'Viewed all enrollments in course',4,'2024-12-02 12:53:22','Course ID: 1'),(290,'FacultyLogin',4,'2024-12-02 12:53:55',NULL),(291,'Viewed courses by faculty',4,'2024-12-02 12:53:58','Faculty ID: 4'),(292,'Viewed courses by faculty',4,'2024-12-02 12:53:58','Faculty ID: 4'),(293,'Viewed all enrollments in course',4,'2024-12-02 12:53:59','Course ID: 1'),(294,'FacultyLogin',4,'2024-12-02 12:54:59',NULL),(295,'Viewed courses by faculty',4,'2024-12-02 12:55:03','Faculty ID: 4'),(296,'Viewed courses by faculty',4,'2024-12-02 12:55:03','Faculty ID: 4'),(297,'Viewed all enrollments in course',4,'2024-12-02 12:55:04','Course ID: 1'),(298,'FacultyLogin',4,'2024-12-02 12:57:01',NULL),(299,'Viewed courses by faculty',4,'2024-12-02 12:57:04','Faculty ID: 4'),(300,'Viewed courses by faculty',4,'2024-12-02 12:57:04','Faculty ID: 4'),(301,'Viewed all enrollments in course',4,'2024-12-02 12:57:05','Course ID: 1'),(302,'FacultyLogin',4,'2024-12-02 12:57:41',NULL),(303,'Viewed courses by faculty',4,'2024-12-02 12:57:43','Faculty ID: 4'),(304,'Viewed courses by faculty',4,'2024-12-02 12:57:43','Faculty ID: 4'),(305,'Viewed all enrollments in course',4,'2024-12-02 12:57:45','Course ID: 1'),(306,'FacultyLogin',4,'2024-12-02 12:59:57',NULL),(307,'Viewed courses by faculty',4,'2024-12-02 13:00:00','Faculty ID: 4'),(308,'Viewed courses by faculty',4,'2024-12-02 13:00:00','Faculty ID: 4'),(309,'Viewed all enrollments in course',4,'2024-12-02 13:00:02','Course ID: 1'),(310,'FacultyLogin',4,'2024-12-02 13:02:02',NULL),(311,'Viewed courses by faculty',4,'2024-12-02 13:02:04','Faculty ID: 4'),(312,'Viewed courses by faculty',4,'2024-12-02 13:02:04','Faculty ID: 4'),(313,'FacultyLogin',4,'2024-12-02 13:21:05',NULL),(314,'Viewed courses by faculty',4,'2024-12-02 13:21:07','Faculty ID: 4'),(315,'Viewed courses by faculty',4,'2024-12-02 13:21:07','Faculty ID: 4'),(316,'Viewed all enrollments in course',4,'2024-12-02 13:21:08','Course ID: 3'),(317,'Viewed all enrollments in course',4,'2024-12-02 13:21:09','Course ID: 1'),(318,'FacultyLogin',4,'2024-12-02 13:23:19',NULL),(319,'Viewed courses by faculty',4,'2024-12-02 13:23:27','Faculty ID: 4'),(320,'Viewed courses by faculty',4,'2024-12-02 13:23:28','Faculty ID: 4'),(321,'Viewed courses by faculty',4,'2024-12-02 13:23:29','Faculty ID: 4'),(322,'Viewed all enrollments in course',4,'2024-12-02 13:23:44','Course ID: 1'),(323,'FacultyLogin',4,'2024-12-02 13:24:26',NULL),(324,'Viewed courses by faculty',4,'2024-12-02 13:24:29','Faculty ID: 4'),(325,'Viewed courses by faculty',4,'2024-12-02 13:24:29','Faculty ID: 4'),(326,'Viewed all enrollments in course',4,'2024-12-02 13:24:30','Course ID: 3'),(327,'FacultyLogin',4,'2024-12-02 13:34:19',NULL),(328,'Viewed courses by faculty',4,'2024-12-02 13:34:22','Faculty ID: 4'),(329,'Viewed courses by faculty',4,'2024-12-02 13:34:22','Faculty ID: 4'),(330,'Viewed all enrollments in course',4,'2024-12-02 13:34:23','Course ID: 1'),(331,'FacultyLogin',4,'2024-12-02 13:36:08',NULL),(332,'Viewed courses by faculty',4,'2024-12-02 13:36:10','Faculty ID: 4'),(333,'Viewed courses by faculty',4,'2024-12-02 13:36:10','Faculty ID: 4'),(334,'Viewed all enrollments in course',4,'2024-12-02 13:36:12','Course ID: 1'),(335,'FacultyLogin',4,'2024-12-02 13:42:12',NULL),(336,'FacultyLogin',4,'2024-12-02 13:42:22',NULL),(337,'Viewed courses by faculty',4,'2024-12-02 13:42:24','Faculty ID: 4'),(338,'Viewed courses by faculty',4,'2024-12-02 13:42:24','Faculty ID: 4'),(339,'Viewed all enrollments in course',4,'2024-12-02 13:42:26','Course ID: 1'),(340,'Viewed all enrollments in course',4,'2024-12-02 13:42:40','Course ID: 3'),(341,'FacultyLogin',4,'2024-12-02 13:45:04',NULL),(342,'Viewed courses by faculty',4,'2024-12-02 13:45:06','Faculty ID: 4'),(343,'Viewed courses by faculty',4,'2024-12-02 13:45:06','Faculty ID: 4'),(344,'Viewed all enrollments in course',4,'2024-12-02 13:45:08','Course ID: 3'),(345,'FacultyLogin',4,'2024-12-02 13:51:24',NULL),(346,'Viewed courses by faculty',4,'2024-12-02 13:51:26','Faculty ID: 4'),(347,'Viewed courses by faculty',4,'2024-12-02 13:51:26','Faculty ID: 4'),(348,'Viewed all enrollments in course',4,'2024-12-02 13:51:28','Course ID: 1'),(349,'FacultyLogin',4,'2024-12-02 13:52:34',NULL),(350,'Viewed courses by faculty',4,'2024-12-02 13:52:37','Faculty ID: 4'),(351,'Viewed courses by faculty',4,'2024-12-02 13:52:37','Faculty ID: 4'),(352,'Viewed all enrollments in course',4,'2024-12-02 13:52:38','Course ID: 1'),(353,'FacultyLogin',4,'2024-12-02 13:54:53',NULL),(354,'Viewed courses by faculty',4,'2024-12-02 13:54:55','Faculty ID: 4'),(355,'Viewed courses by faculty',4,'2024-12-02 13:54:55','Faculty ID: 4'),(356,'Viewed all enrollments in course',4,'2024-12-02 13:54:56','Course ID: 1'),(357,'Viewed all enrollments in course',4,'2024-12-02 13:54:57','Course ID: 3'),(358,'FacultyLogin',4,'2024-12-02 13:56:32',NULL),(359,'Viewed courses by faculty',4,'2024-12-02 13:56:35','Faculty ID: 4'),(360,'Viewed courses by faculty',4,'2024-12-02 13:56:35','Faculty ID: 4'),(361,'Viewed all enrollments in course',4,'2024-12-02 13:56:36','Course ID: 1'),(362,'Viewed all enrollments in course',4,'2024-12-02 13:56:37','Course ID: 3'),(363,'Viewed all enrollments in course',4,'2024-12-02 13:56:37','Course ID: 1'),(364,'Viewed courses by faculty',4,'2024-12-02 13:56:40','Faculty ID: 4'),(365,'Viewed all enrollments in course',4,'2024-12-02 13:56:41','Course ID: 2'),(366,'Viewed all enrollments in course',4,'2024-12-02 13:56:44','Course ID: 2'),(367,'Viewed all enrollments in course',4,'2024-12-02 13:56:45','Course ID: 5'),(368,'Viewed courses by faculty',4,'2024-12-02 13:56:46','Faculty ID: 4'),(369,'Viewed all enrollments in course',4,'2024-12-02 13:56:47','Course ID: 1'),(370,'Viewed all enrollments in course',4,'2024-12-02 13:56:49','Course ID: 1'),(371,'Viewed all enrollments in course',4,'2024-12-02 13:56:50','Course ID: 1'),(372,'Viewed all enrollments in course',4,'2024-12-02 13:56:51','Course ID: 3'),(373,'Viewed courses by faculty',4,'2024-12-02 13:56:56','Faculty ID: 4'),(374,'Viewed all enrollments in course',4,'2024-12-02 13:56:58','Course ID: 2'),(375,'Viewed courses by faculty',4,'2024-12-02 13:57:08','Faculty ID: 4'),(376,'Viewed all enrollments in course',4,'2024-12-02 13:57:11','Course ID: 1'),(377,'Viewed all enrollments in course',4,'2024-12-02 13:57:12','Course ID: 3'),(378,'Viewed all enrollments in course',4,'2024-12-02 13:57:18','Course ID: 3'),(379,'Viewed courses by faculty',4,'2024-12-02 13:57:21','Faculty ID: 4'),(380,'StudentLogin',3,'2024-12-02 13:57:33',NULL),(381,'Viewed transcript',3,'2024-12-02 13:57:36',NULL),(382,'Viewed transcript',3,'2024-12-02 13:57:42',NULL),(383,'Viewed all courses',3,'2024-12-02 13:58:00',NULL),(384,'Viewed remaining capacity',3,'2024-12-02 13:58:00','Course ID: 1'),(385,'Viewed remaining capacity',3,'2024-12-02 13:58:00','Course ID: 1'),(386,'Viewed remaining capacity',3,'2024-12-02 13:58:01','Course ID: 3'),(387,'Viewed prerequisite courses',3,'2024-12-02 13:58:02','Course ID: 5'),(388,'Viewed remaining capacity',3,'2024-12-02 13:58:02','Course ID: 5'),(389,'Viewed transcript',3,'2024-12-02 13:58:25',NULL),(390,'FacultyLogin',4,'2024-12-02 13:59:35',NULL),(391,'Viewed courses by faculty',4,'2024-12-02 13:59:38','Faculty ID: 4'),(392,'Viewed courses by faculty',4,'2024-12-02 13:59:38','Faculty ID: 4'),(393,'Viewed all enrollments in course',4,'2024-12-02 13:59:39','Course ID: 1'),(394,'Viewed all enrollments in course',4,'2024-12-02 13:59:50','Course ID: 1'),(395,'Viewed all enrollments in course',4,'2024-12-02 13:59:51','Course ID: 1'),(396,'Viewed all enrollments in course',4,'2024-12-02 13:59:51','Course ID: 3'),(397,'Viewed all enrollments in course',4,'2024-12-02 13:59:52','Course ID: 1'),(398,'Viewed all enrollments in course',4,'2024-12-02 13:59:53','Course ID: 3'),(399,'Viewed all enrollments in course',4,'2024-12-02 13:59:56','Course ID: 1'),(400,'Viewed all enrollments in course',4,'2024-12-02 13:59:57','Course ID: 3'),(401,'StudentLogin',3,'2024-12-02 14:00:06',NULL),(402,'Viewed transcript',3,'2024-12-02 14:00:18',NULL),(403,'AdminLogin',2,'2024-12-02 14:00:32',NULL),(404,'Viewed all courses',2,'2024-12-02 14:00:35',NULL),(405,'Viewed all enrollments',2,'2024-12-02 14:00:40',NULL),(406,'AdminLogin',2,'2024-12-02 14:01:04',NULL);
/*!40000 ALTER TABLE `audit_log` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `course`
--

DROP TABLE IF EXISTS `course`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `course` (
  `cid` int NOT NULL AUTO_INCREMENT,
  `cname` varchar(100) NOT NULL,
  `credits` double NOT NULL DEFAULT '1',
  `sem` enum('S1','S2') NOT NULL DEFAULT 'S1',
  `capacity` int NOT NULL DEFAULT '40',
  PRIMARY KEY (`cid`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `course`
--

LOCK TABLES `course` WRITE;
/*!40000 ALTER TABLE `course` DISABLE KEYS */;
INSERT INTO `course` VALUES (1,'Intro to Programming',1,'S1',40),(2,'Data Structures',1,'S2',35),(3,'Algorithms',1,'S1',30),(5,'Rizz 101',1,'S2',34);
/*!40000 ALTER TABLE `course` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `course_faculty`
--

DROP TABLE IF EXISTS `course_faculty`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `course_faculty` (
  `uid` int NOT NULL,
  `cid` int NOT NULL,
  PRIMARY KEY (`uid`,`cid`),
  KEY `cid` (`cid`),
  CONSTRAINT `course_faculty_ibfk_1` FOREIGN KEY (`uid`) REFERENCES `faculty` (`uid`) ON DELETE CASCADE,
  CONSTRAINT `course_faculty_ibfk_2` FOREIGN KEY (`cid`) REFERENCES `course` (`cid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `course_faculty`
--

LOCK TABLES `course_faculty` WRITE;
/*!40000 ALTER TABLE `course_faculty` DISABLE KEYS */;
INSERT INTO `course_faculty` VALUES (4,1),(4,2),(4,3),(4,5);
/*!40000 ALTER TABLE `course_faculty` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `enrollment`
--

DROP TABLE IF EXISTS `enrollment`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `enrollment` (
  `eid` int NOT NULL AUTO_INCREMENT,
  `uid` int NOT NULL,
  `cid` int NOT NULL,
  `sem` enum('S1','S2') NOT NULL DEFAULT 'S1',
  `grade` enum('A+','A','B+','B','C+','C','D+','D','E+','E','F+','F','NG') DEFAULT NULL,
  PRIMARY KEY (`eid`),
  KEY `uid` (`uid`),
  KEY `cid` (`cid`),
  CONSTRAINT `enrollment_ibfk_1` FOREIGN KEY (`uid`) REFERENCES `student` (`uid`) ON DELETE CASCADE,
  CONSTRAINT `enrollment_ibfk_2` FOREIGN KEY (`cid`) REFERENCES `course` (`cid`) ON DELETE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `enrollment`
--

LOCK TABLES `enrollment` WRITE;
/*!40000 ALTER TABLE `enrollment` DISABLE KEYS */;
INSERT INTO `enrollment` VALUES (1,3,1,'S1','B+'),(2,3,2,'S2','A+');
/*!40000 ALTER TABLE `enrollment` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `faculty`
--

DROP TABLE IF EXISTS `faculty`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `faculty` (
  `uid` int NOT NULL,
  `appdate` date NOT NULL DEFAULT (curdate()),
  `dept` enum('CS','HM','EN','BA') NOT NULL,
  PRIMARY KEY (`uid`),
  CONSTRAINT `faculty_ibfk_1` FOREIGN KEY (`uid`) REFERENCES `user` (`uid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `faculty`
--

LOCK TABLES `faculty` WRITE;
/*!40000 ALTER TABLE `faculty` DISABLE KEYS */;
INSERT INTO `faculty` VALUES (4,'2020-12-01','CS');
/*!40000 ALTER TABLE `faculty` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `payments`
--

DROP TABLE IF EXISTS `payments`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `payments` (
  `pid` int NOT NULL AUTO_INCREMENT,
  `uid` int DEFAULT NULL,
  `sem` enum('S1','S2') DEFAULT 'S1',
  `total_amount` decimal(10,2) DEFAULT NULL,
  `paid_amount` decimal(10,2) DEFAULT NULL,
  `payment_status` enum('pending','partial','paid') DEFAULT 'pending',
  PRIMARY KEY (`pid`),
  KEY `uid` (`uid`),
  CONSTRAINT `payments_ibfk_1` FOREIGN KEY (`uid`) REFERENCES `student` (`uid`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `payments`
--

LOCK TABLES `payments` WRITE;
/*!40000 ALTER TABLE `payments` DISABLE KEYS */;
INSERT INTO `payments` VALUES (2,3,'S1',100000.00,0.00,'pending'),(3,3,'S2',100000.00,0.00,'pending');
/*!40000 ALTER TABLE `payments` ENABLE KEYS */;
UNLOCK TABLES;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 TRIGGER `update_payment_status` BEFORE UPDATE ON `payments` FOR EACH ROW BEGIN
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
END */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;

--
-- Table structure for table `prerequisites`
--

DROP TABLE IF EXISTS `prerequisites`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `prerequisites` (
  `cid` int NOT NULL,
  `preqid` int NOT NULL,
  PRIMARY KEY (`cid`,`preqid`),
  KEY `preqid` (`preqid`),
  CONSTRAINT `prerequisites_ibfk_1` FOREIGN KEY (`cid`) REFERENCES `course` (`cid`) ON DELETE CASCADE,
  CONSTRAINT `prerequisites_ibfk_2` FOREIGN KEY (`preqid`) REFERENCES `course` (`cid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `prerequisites`
--

LOCK TABLES `prerequisites` WRITE;
/*!40000 ALTER TABLE `prerequisites` DISABLE KEYS */;
INSERT INTO `prerequisites` VALUES (5,2),(5,3);
/*!40000 ALTER TABLE `prerequisites` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `schedule`
--

DROP TABLE IF EXISTS `schedule`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `schedule` (
  `scid` int NOT NULL AUTO_INCREMENT,
  `cid` int NOT NULL,
  `starttime` time NOT NULL,
  `endtime` time NOT NULL,
  `day` enum('Monday','Tuesday','Wednesday','Thursday','Friday') DEFAULT NULL,
  PRIMARY KEY (`scid`),
  KEY `cid` (`cid`),
  CONSTRAINT `schedule_ibfk_1` FOREIGN KEY (`cid`) REFERENCES `course` (`cid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `schedule`
--

LOCK TABLES `schedule` WRITE;
/*!40000 ALTER TABLE `schedule` DISABLE KEYS */;
/*!40000 ALTER TABLE `schedule` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `student`
--

DROP TABLE IF EXISTS `student`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `student` (
  `uid` int NOT NULL,
  `dob` date NOT NULL,
  `picture` longblob,
  `major` enum('CS','BA','EN','ME','EE','CE','MA') NOT NULL,
  `enrolldate` date NOT NULL,
  PRIMARY KEY (`uid`),
  CONSTRAINT `student_ibfk_1` FOREIGN KEY (`uid`) REFERENCES `user` (`uid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `student`
--

LOCK TABLES `student` WRITE;
/*!40000 ALTER TABLE `student` DISABLE KEYS */;
INSERT INTO `student` VALUES (3,'2004-01-18',_binary 'ÿ\Øÿ\à\0JFIF\0\0H\0H\0\0ÿ\Û\0„\0		\n\n	\r\r++&.%#%.&D5//5DNB>BN_UU_wqwœœ\Ñ		\n\n	\r\r++&.%#%.&D5//5DNB>BN_UU_wqwœœ\Ñÿ\Â\0€€\"\0ÿ\Ä\0\0\0\0\0\0\0\0\0\0\0\0\0\0ÿ\Ú\0\0\0\0\0\öO\ä.8¿F[9\\Ÿ\×À\"‚\n\0\0‚€\ÑÀ\0R€\0\0Š\"*€\0\0x§I\ÚÕŽ\æ¾M	ú\ÔPb¸\0j«\× \0+\\\0\0\0\0\0Ç€Št~›[# \ç\Ö	ú\Ô\0<\0Dp\0Š\0\0Çƒ\05ÀŠ\0\"€\rp\â—wºLvA¬Ÿ9}l\0Á\à\0Ç‚+\\\"€5À\0\0 ŠŠ\0\0\0x¦f¸\0o\õx#€\0E«‚\Ã0¨ \"\ð\0\0P\0\0\õN\Åiü\É\éÞ²§\Ê\ßG\0\0\rp\01\è¨\0¨ˆ<\0\0\0\0\0\0\0\0\Äý_°3>U\ï½ü>Vú8\0\ð\Þ\æ\çÑ¯,¢$\íh\êj€Ç€\0\"€\0\0\"8\ñMžNW~\àx_\ÔA€\×\0\0	%\ÏÌ£›]’\ÛÐ¹£¥c:\÷€\0(\0Š\0 §‰øDÞ—v\ížw\ÓûD\0\0f?ž‹ž\ãx<\Èb\0<ú‡©\ö\îoU­ \0\0\0\0\0\0y7?X«jšÒ½\õX\0UH\ä©\ÊÁ\Çyvt\0\0\0–ÿ\0¡û­þ&ÿ\0Z\à\0\0\0\0\0\ê\Åk„P\0\0\ä\ó8žWF*m\0\0\0mÿ\0x\ônJ¯d<\0\ê\0\0\0	\Â\ð\çšk³Ož\ô\\Ÿr\0@!Á\Í\ò\ÞB\ä\ó\Ö\ç\ò\à\0\0K—,¿Ö½“\Î\ë€\0\0ª€1\á“A\Ì|¯¤‹?B\05\ÃW/Éµ=\ÛRC\Ä\ãÀ\0\0·µwd¯OP\ö¬Wj\0\0À\0r|eª\ö©s\ZU=‡t\0E\n˜\r\ð\ì\ÛSiO<\Ðd\ñ™l\0¿»\Ù2*T«\Ó\õÿ\0_©*\0\0ŠŠ\0\0lVÊ…y%\è\ô@¼©ƒŽ\àÚŸJ\Ì\ò5•9L\Z(\0Z\Ú\í\æ–s\è×§\ôOm\0®\0\0\0N[Š\Þ\Æ\ë02®^\ôf¸\0°a\òž>\äú–\'Q>G0k\öw¥’H!¡ÿ\0O\\©(\0\0\0\0s\\oA\Õ\àg[ \Ìx	\Ï\Ç\Æù%ùµl\Øske×‚ÜºH{­\Þ$\Ä0\æ\çA\è~\çD•\0<\0\0+\0H\å23«|ûCgr\å§G\ÍÓ®\Ä\0Ò–{smj+›M\Zÿ\0Si\å\Û\0\0@\0\Z\05T\0\0«_7\É|®=\r\í¹\ò°3\êÂ€\0\0£ç¹¯\Ô\Út5\ñª{w£¥Q\0\0\0E\Z\0\0(47e‹b\Ë\á¨Á\0\0\0\0[—wz”¹\ÜGú\riµ®\0\0\0\0j8\0P¡r§ƒù¤ \0\0\0\0\0\0>\å»4ª\Ö\Úû!\Õ`A\0P\0\Z*#€AC¨\Ïù+\0\0\0\0\0\0\0\0Qúû§† Ç€Š\0\0PGÙ½\å?Q\0\0\0\0\0\0\0\0\0ú\Ù[œ\0\0\0\0ª\n \0´6-ü\Ï\æÑ€\0\0\0\0 €\0£ý>™NP\0\0E#@P\Ïé¹¯˜y\Ð\0\0\Ò=\îT\Z\Æ\ÆÀ@K\í\ä\0¨(‚€Š\0\0\0\Ý\Ï\ñ|\Ð\0\0%šG\0\0€Ø¢@\ì—.0\0\0\00\0\Õ\çü\×\æ\õ@\0[Q\0\0\0«\Æ\n\ô§©f\ÖTA\0Qˆ\0@\r[0ü¥Ç°\0	,H\0\0\0\0¨\ÖV` \Ó\ï´3\Ü\0\0 €¨\0¨\ä¼\÷\Ì<À\0L8p\0\0\0Eh\0 zG\ÓÔ°m‚‚\0\0¡\0\0 /B¼Í¸\à\0*(>Y”q,ƒ\nA]\0\0\ê>½^N\Ø\0*\0€,@\0\0)>\ô>M\àU@E@WY&u¹\"§]E+‘ŒUG}\Ðs\0\nŠ€Ejª\0£›wk\ÆüŽ\0\ïs•F\È\àš\á+s\àbIq\éz¬ÊŒú{\Ñ0+¨\0\0¨\n‘ŒQ4\rmH¾h\ó\Èf,8\0\0ÓœJ\Ñ\Ç4gF×§F)\\3\è_[©\Í\Î\09¢ \Z \nŠ‚†ý\Ö|Ÿ\È\Ä· \01\à­v™\õ‚]AJ8Ok\ö{œt\ê€\0\0À\0\0\ê¤\ÎùK›ŒqÀ¨\ÑZ\ð\Ö\è\âÆ«šF\Ç\Ï9\÷\è\Ñk†ú\ï¸ZÂ€@\0\0‘\0(¨7Tr\ß4sŒ\Üsaµ±…KZ\íˆq³¾cUÈ¦Œv”\n^m\Z\Ò\"uÿ\0Q\Ðnp\0\0‘\0(\Z[\ç\ó®BKªØ¬\ô¼•^\Çk™¡\Ý&\ÞÁ—CÑ‹s\Ð\ð97lgTxG\Õ8;œÔ®`‚(€\0¢*9¢\ílq\ó¶P„·\0ú\Ö\ÅTY&\é:¬ZyT\ó\ÙVÆ’SŽü¹´^‡s\ôF7gÅ¼\0I (ˆ\n\0\æª\ô—2ù\ã8BÅ¡\0~\Í.—Kº™y°Ô£Vm+ÏŠ\ZùX¢§«úµnÛ–¬=Š1@\0\0A\n\ñzø¿ˆ\ÐÅ™\Ë†(’m( —Vþ\Å\×KC:\ë\Ïz\Ã`™\\£Z}3%¾£Žœ!˜±\ìW°Uhqûüž\äV4¬Xº\ÈkV{Ñ\Ú\Ñ\Ôp>\n‰RÍ»h‘esü\ìŸQT\Öé¸ª·À+Ì®`¢<\0\0S†\öYq|\Ë\Åiˆ[›NÎœÒ‰*h\íM™\íÓ‚	$\Ë[Z4219lú’†\ÇE’vH	®@AP\0\æ=|\äü\ï\Æi\\›J\í\é,(…ZZ\÷.\Ø\ê\÷©\ñyqt;\\\ì»®ƒ‘\Ã\äq#Eú«#¢Þ“\Âû†U\0	@\0ù–û\õ\ä¾|\æ\é—&½oL³ I~J7\ô\öe\ÇFY\ê\Ñ\îþc‘Îª“}S‰ß’x·V­VG³Š€\'\ê\Úg%\ó¦-W¥nw\ÚR¶D™\íž\öžŽ^L75{n–`nG;\Í\ãÀ—~¤\ç½\Ï\ó6i-w<°*\0¼_·\'\óž%AÎ‘vÍ¹greeÐŠØ³3Fþ¯Y\Ûk)Sš¯\Ê\çs·g\é¬\Ö\ÛùŸ9\é’8mC \0\\@5yŸa¯EŸ/c\ÓV¶\Õû\õ\íè­¥n^%V\Ã$\îžz«µ“\ê{\ÛoN*>\Z\ïÃ¤ú2–¦\Ô\Ðx7l‘Æ„\ê\0—‘A\ÍD*ž™“\Ð|“™XbOZ¥‹V\ì8Î­PW\í\ë\éik\ìYR—?R¿§\Ç4ë¾€›7®{¼+«X+«£’\ËB{¬QQo¿\Ü\Í\É\è¾MË¬5%¹¨¬±z\ÌÁRb­+\ä\é\÷Cf\Ó\Ã¹¼\Þ9\Ã\è\Ë\Ü_vK\ãº¨U\Ég7X¢¹­\âýžLœ\Ýÿ\0“\ók+[“>[R^´\ðehN–\Î>\í†\Ý~¾‚\Ö\çjG\ÌR‡–\rÿ\0¬›\Ä\÷	7\ÊkEUF\Ûr9,i ‚+P\ä}Ç¥±\ò¦uec_uÏ¸ùlÞ*Ò†ºZ\ê[šþºú¬\ï§D\ÆÁ›‡[\õ+9Ž¡\Òeø—X\È]\'œ’3p \×`ú‹q«\ëü³•UZ\ÇÜ»,‹3†TÍ±<ûqG_µ¨\Ò4‹ž£?3š‡i\ôË‘eT\ð²½%’#R ~\àQF\÷m[Ÿ\×_˜rj+\ë“-™\ß<l“4“Z¥\×n\Âu\Õ\éi\éPÊªþRŸ\Ñ:nz\ÅŒk2Šƒ¬¸¡c\\¢&O9\êú\àt™ÿ\03c\ÔDc­NO-¦\ÄU¦\òižÄž\å(!‘,\í\ô\Õ*\Ö8øš\ç¾ktù\æ5˜$L´\ñN’´O\ÌÀ¯\îc —#\ç|:b1f´“º\òReW^±\Ñ\ôW¤Y$¥‡\Î\ó\Ð]\Ùè¨²*œš#}\Üu’(y\õ5\Ë\rT^ºœj\ë0\òDÒ¬}/\È1)\ÖI}®šúT…·‹š4vm,\Ñ\æ\å\ç`M¥»—ü\æŒ\õf\Ô\Î\ç:_œ\ö¨•®bt#\Õg‹Ÿ®zú\Æ\á|·&¢5šmMc«%ˆ\â~ý9A‘VÔŒÝŽ“\ÃUr§©zþ¢\n¼o\áwkJ\éÖ°1\Ô[’Ãƒ\ÏTsŒº\ß>d\ÖcZ\Æ^r5úOd$td•¯•\÷™\Ñ4«\Ö~g0Ç£ýG\Ø/Ls=›aJû\ô˜\ô\ðY»Vx:\Ë\ç;nßƒ\Ö\Û|:eECa’\ó’j6¨\Êb@—^M[@\â80\òž,þ£\ë7Û™¢r\Ú5|\ö\ôhƒvkZ‡6Aü\ï¨\êù\ÝÞ˜ÿ\0²™mc#³*4»j“!Y\ôto\0:Lž%\ßP\ôxyž‚.^\Ïe\ó\Æ\ó\Ôb\0\ÝHg§FHd\Í\ôNß”¤\ÊÝ¯\ÎÙ‰^!5l\È\Ð#c€%Ðžý\ç\n)^ž6|®D\Ò\ö^\Æ\ç%úµ«z\ÇÍ»\Ð>\å5Ik·AR,\äX¢\î;J8Ì£\Ö|ýžØ¡k`c]eA\Z©,–¥[ºNT£‘BIn¯·\ô¶y\É\êþ*Jø­UŒ³q\ÑÁ–\öÕ½·\ÜW±ƒ•\Ôø-&26I4y\ö\â2X­Ma\Ö5eE«C*“ž\÷56½[¥\Ü\ã¢\Ômi:o.¤²\Ç$b³M\élµ¬\ç\ö¶ú¾[C«ù\ê¤KYaary\Õ\Òx\ï\ÚYo\Û\"Šµ<z—\\8i·\ê½ÿ\0g¯«\ë·-©YV°®Ž»\Ý™2û«(¿o\ç\ZÑ¾´lŒ‰\è:w5_v ù¬\Ë 1’Å±’F‹¹ê›½#gÊ³Y/¯³\ÏtÊ²4Q˜¬’&\êÜ­c£\Ñ\âK~\÷\ÎÄ¬®\ÖEVBº\Ë*W\È\ñ+\ì¹\í´¯…zP\Û\èqx\ãS½\Ò\àvR¤\è9BžžS6¥†\Ûg[”µ¯\ç8#l”˜\Ø\Ù²\ÖUkžŽQ\ÎA­²üû\ÑA\ñ5\Ý¥m\ôX¾?•}º:ý›n\ê\çQ™5 ¡\Îß®“Í½™}±[\"->“\çxX\×Q¬lAb›œD\ÐY3å±›b¾\ç×¬/Q\Öv/\äk\é^Y\Ý\Ü\Ô\ò\í\Ö:	UÉ·E&³q“\õº¬L\å\î|oˆ†*±­b¿\':º#’xž\Òx\ÓFµ˜¯\Ç\0\ç/qgÐº.c\ÉlÝµµ\è^o\Æ\ï2£\çh©\Ít\Ù2\Ú}7\è³Ò«µ´=	žY\æ-\ÑWC5%e³Ö‘\í¿E\ÚúnU‘\ö\õ¸:þ‡‰ƒ\Îz\ëy\á\÷4\ÙE\óšÙ±\óz,°ùihjeM\Ø[Áo¦\á\õ>1ÀE\àa\r\êlÔ•D¹Q\èš9Ïž\r\Z7¢G9ýOv½F\ß»\æ]®½?‰t\Îmü\Ë(=1%ƒ Îž\ì.¯\Ð9V¶´uý¿‚r°#Ys\ÒÒ¤©&xŠ—©¼4i\Í4hÙ†Í›]Ž\Ó$\êºo9\Ö\óžÃŸ³½\äû™+\Ì*œ\í›È²bt>­¿‡…\É%Š\Ëg¥\ì~~Â©\"E’KVX¦\Ð/VYkß¦\á5j!§\ÜtB\ëG{\çûw\Ó\ó\öz\'Ø’fE¯ž\å9\öÏµV¬w•øüfiU°Œ—s¬ùÖ’D\È\Ü\Í Š\Å&4[\õ\Â\í\'º]:y\ØW…Ú°\Ý\Æ\ê<\ó_ž\Ñ\îü\ã\Ø\×\Øl\Ì1o\Ú\Æ\í=^|Žog˜Â¯gR¼Ÿs\Öü\Û\Æ>–Š2_Ï¬\×&­,‡_22MJO\ö\è›LŒn•-\Î:þ¯\ÒxŽR\É<\n<›×°tÙ¾o\Üqúü\Þ\\\öaŠ56û=\ßó§²²,\óTl\í‚4u\ê´\Ò\Ä{\æÔ¨{DMŒŽ8wtüD\Ôu¡\ö.\Ê\äk\ï]\Ì}\îOÓ½Nc¥\ê>gT\â§A\Õ\Õ\ì¾~\äHcs\ïg#\ÛM¤›\ò®JºÎC\Ù`b\Å\\dS[\ê8»S\ØdùÛ¤‹\ÔÙ«\î\ZPr\\©™\ê^s$I_\Ð\ô4:¾WÃŸy\Þqa\Ô\"&× Š\Í|y\ã]*\Ë\íTtp\"V–ÎŸ/f\ö\Ø\ëú¿›~\ÌÌ–e§\æ´«z—œTt\Õ!WN—n=^{\ÆS’i(6Ü™£,_ Ž‹oI™¡NnfS\á‰jµ’h\â\ÏN\èW\÷*<g˜É³ ‘û1\Äo\ó\ÐR\ô\ß;¯$\õ#Õ“¦\Ûu¬mkQ\Êü\ôß‡\0Ž]¬m*741\à-ß„\õ\å©¹\õ\Ñ5\ð\îg\è\Õ5½ƒ3[ƒ\óù\ôÿ\Ä\0\0\0\0\0\0\0\0\0\0\0\0\0\0ÿ\Ú\0\0\0\0\è\óVˆ\õ@\0\0\0\àš\Ã\Ô\0\0\0\0S˜OX\0L\0\0\ns‡X\ÞÖš®Œ*\0\n\ó‰\éµž|\é	¶º\ÞyÀR$¾¬¹hºš\à\0\"“k†º-w›ˆt\öE1@L“\rý9\Ú\ó5\ò \ßÕ¥iNy\Õb]8i«h\Æ\Ý\õW<k 	\0\Õ\ç[l³\0·wN<\Ñy\0‘1+e^P\0&\Z\ÊH0	§%@\0mx,‚aG%\"\Zth W)\ä	°‰\"¢\Ý;	*g€’A\Ó\Õ\0. \çŽj%!\"³Ñ¯U€X75l	BA]c]¶˜H8¯\ÉA)ˆ”&ZW{t€S^$‰µ\nX\Û$\é”‚\ÐskÄ”S+\Þ\Ñ:·¶\×I	.:q¦ ´F½¦3¶\Ý½§¥!\0\à‹\òÄª\"¸a¼\å4Û«xè¥»’‚\çÂžyEI\"/^L][\ï;d\ôm!BXrÅ¹\ÓX…„E9r\×}\÷\ðG[\ÅQB\\´£ª’¤S,]:k½Š\öu\è¢2\Ç4ŒJJˆ\Æ&\Û_[Â½…\æ¨À[‚\ÕdŠB&ba¾·\ÕJ\é\ê\èˆs^š¼\É\×<SœU1†—¥g{\í‡©¸e½<ø\é\Ï\n\ÎuA0‰¡n–\õˆÓ£¶²U\ð·-³\ÍŠˆ\"³m5t\Ò\õ\ê\æ\õ&°˜_..®ZS$\çZ ­Kë¡¼\÷ÆžO°¬%6Ž+gL\òŠ™+(ªt¼\Ù\Ù\ÙÏ\ê^†q{\Î1\Ë9\çZZŠV$™/kw\çµ!\Ój\Ë8¾¹S«Ï¦qJ[9¢²	\Ï}=t¦–™µY\ÚwÊºscÎ“EU”¢gIŸO\r+\Õ\å\ö\éS}¹¯Ù—7$eœ\Ökj&!kZ{»¼\Þ\Ë\ß\Îêž•\äŸC²#\Ï\â¦v\Îk5_«³[amm\æ\õV%nLº7\ì\Ò+‡—J\Åb\"‚f\×\õ­k\×+\ë\åmªW\ô±ê½©\\yyk¤Ö³™\ÓÔµ®\Ã[S\Ë\ì²y=®.­)Ç›,i\n\Õ[+i¿¥¥¯*é·›Å¶\×ÿ\Ä\0\Z\0\0\0\0\0\0\0\0\0\0\0\0ÿ\Ú\0\0\0\0\çúmÂ•ù0\00\0\0\0\n}­½|˜\0\0\0\0\0˜\0\0o±†x@\04ÀÀ\0\07\ÒÆš`9\rgU\Ð\0\0¾€@\×E6g•`\0\0=5¥03\ßg\\¿°\0\0™Ak3\0žk‰žÿ\02\n?)o/@	€=Œš1¼\ð³\Õ\ìrŽÿ\0>\õM\ç`\0\0\Ø\ÖD\ï\æ‰\ÝØ¯\ÈtK“\Z®³°À@d·\ètN³\0\õ\ÑÁ\çtu\ð\é0\0O+ª\à\0\0-ˆp4À\Z2žû\Ø\0\0\0\É \0\0\0­\Ø\0o{b\Î0€‡(\00\Ë1\ôtº\é€aŸ\Z\0\0@&\Ç\×P{7±) Ÿ\0–\0·®\Ýl¹­)N„°—\0h\0§c\Õ\ô zÑŒ\í\çšOŠh\0\0§[­±œn£¶!‡MO”\ã’@\0¥;Qf\Z\è{¼\ã\Ö\ï„\á\ÆA\0\0‡½×¨½Z[Nýp–v\ñ=pa!	\ÕÛ¨\è¾\ÞQ¾\Ê\ÎK[\Ï\'˜¸p\ä\0\0¹{6£}•%Á\æ®\à!€«::7L\Ífº†ûºp\ðO…¾d˜\Z\÷R\ö/Ñº¸IWO}•œxüùqm\ó\ã#fÁ:­t][¥\î‰*»RŠ\ä\àŸ0\ã•\0®w~ŒÓ«Onol\ê\Ñ>Xp\â	\ã“™pJ\ËV¸vj›…–\ôn°\ä\äœ6gŽC\ÑÑIv\æ}W×³¿^ŽN\ZW|#5\Ç&%]\êGk\æ\é\êk¸£­“Ø§\å\ÒÓ’\å\ÒKf‰\Û={µ•¯½‰e\ÓZY\ä\ã9\'r\ö\ð&\Í\nX\í\â\ïèµ™{\íƒ\Ö\Â3\á\É\Ç.>ß˜\Û4³.n\Õ~«Z\Ò\ïKOb\ç\åž_™ž\rž—t>…sh\ï½k]\é\æ\ÕMŠ\Ôpy/›«\\\Õ\È\n™\çû=vÕ¨\õ–hk+Z9\ñ\ãn\\\ð\ë\Z:ež]F\Ý}¥5¼i&\ñl\Ç\ðm+yþ\Ì\ð¦J$¼žž¿Z\ÔÝµÌ¤\'µ9ùžO¥\ç©{Yº\"tC\È\â\Ó\õýkj½9S\Í&W\ó¼øGr‘\ì\ä\ã\å\ä\ó\àú;}N½\Ò\ïK<\åù/\Ï\âNR\Í\'±YtG\Í\ì\ós*\ÖÝ½=®´N]|§G/O/9Á[»\öäµ—\ä\ò{^_7S¯Ge{:6‡_>z¹/æ‘¨\óú=\ì\Çÿ\Ä\0P\0\0\0!1A \"2Qaq0BRr±#3@bs‘¡4C’Á\Ñ\ð5PSc‚$Uƒ¢\á6DT%dt²\ñ\Âÿ\Ú\0\0?^X\õ(ü\\¶v\ÃutX\ã\á®vM\ò}Ï©u8¿(\ÝsO\òy\ì¨døÝ¦j£\É\×\Ó\à\å=\'Xf\ä­K[|øú<ÿ\0“™\ìpü\Õ?“rTD$«\â\ä¬\ín\"?\îU[\ä˜9[\ô´\Í21Ò£NUŸi6\æƒ¨<\Ý\Í\ôú?\åR\Å\Ë\É/\Õd\÷(©\ð\íJ‰{cj{1m¨«\r\ÖÖ´´ð½¾Œ\Ã\ãeWU,5TloVCbLa\ÔÓ´\rZU\Ì\ÐQŽ.-ü\ÖÔ©¬e\\q²ü‘\Ã|»×”]j_#ý\éÞ³\ã\æ@²\0}ù¹\ólo¯#\êÀ\ß\ÌycÔ£\ñr\òO\õY}Ë•%‡OAŸ\ñ\ÒIm\"\óL†Wl\÷¶F\áw(]cÙŠ\é\âO 9@IRù«kb~VÉ£¹U\Ú\'l\èùƒ\òhmFf\ÓrW\Çl\ï\ÚW”Z\Òø9\ïH>\ö?™\Ï\ë<o\Ì\òm\Ìù\á\Ï\òÇ©G\â\å\ä\åe=5+¹W\ÛL\ÚP|ž‘…ù¶^—€RmŠ\É&\éa\Ë%A¶Xb\Ë&¯–\\VÔ¥5”’\Ç%\ÚÛ‡x+©µL\í—\æ\Þ\Ë8\÷ª½¡M&Ð¤‘²|\Û5*¦³dM\Ó.ihlUMnÈ¨g\Î88–E\ïH>\õŸq6W·˜\Îü\á¾\Þbù\Ûx\ó\ÖU\òÇ©G\â\åA\ä¼\õ”p\Ô6·\0x½°¯\ÐÊŸùˆý\ÅúSÿ\01º¿Cj\æ\÷W\èmOü\Ä~\âý\r©ÿ\0˜\Ü_¡•?\óû«\ô2§þb?u~†Tÿ\0\ÌG\î©\è\ßA¶#§t˜\Ëe¥\ãÏ°½ü\õ\÷:ü9‡Å¼\åÑ½²B\ö\Í_?®ycÔ£\ñr\òûš‡\î\÷\Ô<\Ç²Üµ…\Ö\ðTµU;Q\Ó\ÉQ¶M;›\Ôm\ì’\Õ\õµpN*\\^@cûy›wÿ\0S½‹\Íç—˜\í\Ýo3p±7´+Ž\Ñþ\r\åR\Å\Ë\É\ï\îZc}dŠ’¢F7›ˆ\åEO³+c«–²°A6+´\Ñ^FMQŽª“[q\ís6\÷þ§w\Þ\Å\æ/¹\ö\Ì\ç\ÌÃùŽ{\Öp	Õ°7ü¶«\â_1\ì\å5=c\î\\½U\ô?º¾QW\Øu|¦§ü±û«\åohYø/•³;“1Ã ×´ø¡4\Ã\öŽM¬¨•üSv\ô\Ùø(\ë!yµ\ì{ù \Þù}d\é¿\Ë¥‹–\È\ò“eR\ì\ÚX%•\á\ìf}¿Kv/ù\Ò~\á_¥»ü\é?p¯\ÒÍ‰þsÿ\0p©¶’?\á\é}\Ù\n)|Ÿ˜\"%û1Y~–\ì_\ó¤ýÂ¿Kv/ù\Ò~\á_¥»ü\çþ\á[F®\nÍ¼\Ù\à$±\Ò\Çk\å\Ìuøs,<\ã\äc\Ü\à\öƒQ·\\­dýPmÜ¾E&²\È\Öø§Ï²`úZÀOv\í¹²#=þû5úQz”?\÷#\å\\ü)\á\ôª³Ô…~”\Ö\öD‡•už¤)žUM~,DwúON\ãÓ¡\Ë\Æ\é»sc\É×…\ì\÷$\É\ö<ÿ\0GY„\÷\å\ñBƒRv;Á?gFO\ÅI±\õ˜£žXú®**\öœ¤\ï\àƒƒ…Á¸ú\÷–]J?nŒb{\âB;\í\ÃG\Ól6¸\í6m\ì\ö5­¥€‡°U@Ly\ß\Çj¤\ØÔµ3U\Ê\ò1É½øu*=›J\í™=AlÁ\Âø\è¸\ß \ñRù?p\ìû—c’ G+^Å·6dT.§0\ßÃ¸\ßCº\õºo½g\Ç\Î\á9gÍ–¦(µv}>²iNÅ¼5FŸyJ™[\ï*mµ³)®!ˆ\Ìþ\Þ\n«\ÊZ\é2k›û:©«¥—¯#\ß\í\Ë=bwo>\äqBWŽ(O\ÚU%†\ñ\È\æž\ãe\Ý\ÚQaùü`pvjƒ\Ê\ZZ›2a\É?þÒ¤¤‚N\ï\nZ	[\Õ\é\Í2IavW\Ê\n\ÆI“º.Fü>¹\åEU[)y\\ü%×²þ\ÄÚ¿ü9Ø»Xg\ò9”¾Q\Êc/eK°u.tF\Ê\'JÉ‹*yFu]\Ä!³v\à\Æ\ô‰.\ïºm\'”Mƒ\Ô\òV¶lÍ¶\Z\Ö\ny\ÃZ\ì@v\Õ>\ÍÛµš	\Þ~\Ökûjÿ\0\ð¤T»j6¦\Z9,$iüüÖ¼ÀI¾[¥š8‡H©k%“&d?4bŽrµRˆ\Ùù•S\åe\ÙCh\õÝª©¬–g\â–G=\Ý\éÒ¸ù\ð\÷7B›0:­›·jh\ì\ÒyH»E´)«c\Åü[\Ä) dÍ³‡½OLøO\Ù\íTÕ…½3½ˆE\Ç\Ö\ß$q·\r¤\Ùbf]!ž\ê\í7\è\ìl\áaÞ±²\×\Ä,‰ \áuv¶\×pX\Ø\r‹‡â±³\×oâ±²\ö\Ä/\Ùt\×5\ÝW\á\ç´RTú¿Šdoäƒ—Q¶i(±2¼¬¾¿<\õr&yqF\"œ\ÞÐb ¨5\Î\Z*z‰a{dÅemøêˆ†¢Ì—\à\ä@p±\ÑTQ\Ý\Ñ\æ;=I‹#›>	®\07\ç‘©mØŒ‘B\à\Zü.ä¦-•d\ôÜ®\Ì1<\áŽ8‹/¨»ÿ\0’ÙŽ\ÃU¶\ÙQ\ÉR8|ƒl€\ë‡\Â\Ù=\å\ÊP#†ª&FÍ£\ÙuD\é?·°¡©˜\Â\Ë\Êg·—¤\éX\Æ\ÞP~\ð[a\ÏþÖ©³n\Òi\î{g(f\Ú\Ï™\Ò~á²¥\ÖÚ®4\ív\Úz‡\ñ^Mtjb\r\Ñ\ô\Î.\ñ\çßœ\÷†•$®‚xo&d™üœ-\Ô\ö­£¶d©Œ“ƒ³‹¼Pgj\r@v,\0\åk§\Ñ\åvœû\ã±\Â\ášs0ù\Ð\ÒPˆqMo`\\“–\rV\ÅÛ½Zj§w1ÿ\0\ÏuU%úqŒøŽ\ÕK7$pž¡?ú¶w\æU\ÑAXÆ¶Pz&\àƒb=\è\ìšo%“š\Æ\ë\êh¿²\éD³€ür_H\Ø\ß-\öE7“9\Â\"9ú!\r—D\Ø<™À$\×2\áÄ¨\è)D™¬8„Ž}\ï\ÅúªŸKR^ee\ñ\ÇÉŸ\Ý?dQ=\å\Îc®C¿\å\è¤\ÙTg/g\\;¿i\ÄS6u\æ5ŒÇ‰ù\ß±\Ê\Ú*-—GB\\`Ž\Ä\åro\Ï\Û\Íøn’@ÁÞœ\ç8Ü©$†žO;¬Á \ââ¶†Ñž¾\\\ò`\ê0pMm¦±XÔ°2F\Ø\ëÚ¤ak‹\\ž\Ü\'Í¶>\Õ/“ª2L¤`\æQgv\â›\Ålm¼#h‚­\ÆÞƒÿ\0šuQN3{G´;U;ˆ	¾Wi\ít8’E¼\æ\Ù{\ÙJ\Â\Çyx†^Ò’yß¶j\ãl\Î\Â\æJÆ‹\èZË¦U\Ï.ÍªŸ•}\Ã)\Ú3üU+‹ë¶‰s\ç\Å\ðfp\Åy7<\ó=\÷’W°B1c>™<=Ë”|»Rgš®O‘¨c\Z\Ò\ë5\ÂÙ‹(ª\åþ\Ó\Ú:p¾)°6ýS\ZŠ®¨\ìº\×6y°¶®\\ty<;”S\ÔOENšCµœžg¥‚Ù…ý¡V\Ú}—/(î€›zµ¦Ù­˜\ç;gR9Ä’b\'Ÿ~d’†\ôI&\å9\ñ\Å¦™Öšªúù«\ç\Är`\ê7°&¶\Èt\Ö\ÙYïª‡”f!\Ö	\Â\áo2\Æq*žœ\Ês\ê„Ö´\0ˆ!t\ön!=¼W“ûZ\àRN\ìÿ\0fO\Ãw&/ùøy«ùú\ê3V!o+=\Â\Ýl)›T² 8\ãH\ò}l|\n‹bAÔ‚Wa’Lw\ìQ\ì\Ó\ó\ÈÚ§†Krø\ì-¥–\Ï\ÙqÐ»r¹×Œ0ƒ\öx©\ö8–¬\ÍË¹­/c\Ü\ËzLMØ”í“•8þw­\Ö\å{|\ö?\'–]ødŒ?\ìâ±Y\È\Ù;r¬wªSv,\rŠ\ñ›2)\ã\ÊjU,M‚ž(\Z\ëˆÛ†üû_|’\ôI&\å9\ÍkKœl\0Ì­©´[ c2…Q\ÛÞ˜\Ûnknƒl€@s<LXq¡R7˜·7QFd~˜Ö±¡­Ýª!\ö\"ŠÍŽ»r¶‹b\í1]Ÿ\ô\Ì\ëw\÷\î?XÚ“\ÔD\ÊvÁ c¤œ2\ä_‚©\Ûub–‚Vaø¹\\¯“\r‘®ªþ\Ðu.1ú\Ër\ô0\â*M¥^\êZG2V‡<Ï‹£¯%Á;ha\Ù->G\è\Õ\í8)\é^	tÐ†¾\Ã6¿Pªvµk9+N\Æ^z†—#\Ñ;j\Ö\ë“úw-kzjžº¨Å³œj™//8k¬\Ð-\Ñ\Óu€\ó/x`¹O¹³\Ûb¿”\É\â=\Ö\ï)¬²5·MmiR³HN¸)\ÂÇœ\Ó[ \n¹&w\ñ\Ü7ˆOgˆ\ÝIS%Ls3Ó´*zˆ\êadÑž‹…\Ñ~?©ß™´©\ê\'d†q\Ì\Ò\ÑK°*#„v]\å\×üvt\ßÚ°\Ö8·„b\ÏÓµ“\öMw\É\éX\Ã&\ñ\\\ð•?g´ì¿ƒû,\0\÷§l\í¡-lg*$\Ìmú GüÔ»¦f\Ó\ã1\Ü>w¿\Æ^\Äý•Xü\ÜYr\ZúHP\íOB\Ñ\r8}<¡\Ö\É\Ýf£Ç¸À¶v\ÒüÀy§ ¤~3Ü¯Ñ·}\ÖÖ¯ù4X~q\ã\ð	¼P	£@Y\0€\ÜQpnd\äŸ]\Ð¾^?\Ë(\Öý…\ò\Ã\ê)ø­e(\ãÎ‰¼U´>\í\ã]Áe¸…#8¢…\Â\òn¿’˜\Ò<\ô_\Ô\ö·LÓ\Äk¯\à˜\à\æ‡vù°o\çs@s˜\ã¾wß¢4\Z\î–vA¤y\ÈWR\ée|¯Ô”\Ç\ñ	’x¨\Ûf €\Ü\\\Z.M”\Õ\íF/ÞŸ#\Þn\ãt^\åOb\å\\¹G.QÈ¼‘nhA\í\íBA\ë&\Ì\ñ¤‡\ñBªoY\n\ÉF¶**¸ß‘\è•~aOmr(—1\Í{r \ÝQN*)`›\Ö`;£ŒÇ‰¾\òúÙ¿œ•ø[Þ \Âæ½‡Rˆ± ­·YŽNA§¢Î·Š‘\×r-M’þ)•o;0™W\Õ\ÖF®œzjJþ·\ÞT’½ù½\È\Êy>\íBS\Å¡ª|yÚ£š9GDû·Šp¸NiNµ³^L\Ï\ÊPÿ\0\Ë}¿\ÇO\ð\ónºR¸‘Á¹®\Z­©T#¥ùK\Ý\ïR\ÊIu\õ<Á!•j\åÚŒ½ˆ¸Ÿª6^\Ô\×qiQÖ¸düû\Ôr\Æ\ñ\Ñvç¹¬Ô€¥¨mú9§¿‰+\ÉJ«VK®Ï†\ó®\â~­;3\òÂ©™f_µT\Å`\\\Ö\Ü°þKk\Í\ó‚ëµ¹§º\î\'\ë \Ù6^\Ô\ØW/(\å\â \íº2ž’VÍ©4µ\Ô\óz¯\ðCs\õ\ß~mþ±u~frI\âPUsŠzye<\Zªe//y\Õ\ÇüüÝQ\ò›Jþ80Ÿ\å¹ú‚=\ÖiT­»‹»7yOU†&@8\æT\Ç;ƒyQx* >‹±~\çiþ	1\Ð(†1»l\Ô\ò\õ<q¹\'ü\ÉzŽKj1¼$in\ñþzr\ÛvÔ¬m-?Ú“¢\ÕS%ÌŽ\í>~\Ë	X°…e„,!aÀ°Ÿ;I1‚¦	G \ðSN&‡\"ûŽNp\ïÿ\0§Œ“w”R“T\Ö\ðŽ?\Í\Ês \ó¡¥;dX‹H\ó{~_f\Ò>þ…¿·K”ž#ü	Œ½\ôA¡¢\Ãv×›”©©wl¶\÷5Jn\ó\æ\ÃU­\õ\"\ÔE¼Ï’Sc\Ù\Ïg©!ü\÷Tz\í|À¢\ên‘\Ø#{»\ZJ©yq\Ö\Å\Çßš9“\æCn€\ê—¸#o1\ät¿=Uk·T\ØB\ò{7\0ÿ\0€°Y£vÕ““\Ù\õ.ûüUSºO\î\ËÌ€\Â\Ä\Ç\ÔI².>o\ÉiK6«\ë±\Í;ªŽ·¹@o\î\ËüŽÿ\0(e£d~»\Çý¹©\Î^\'\Ï\\¬JüÖ´É®Irh³¿yw\Ø\òˆv#É°\å>;Û”“7\í€G›Û¹\ïk3q²\ò¦L<ƒ{\ZâŸ§Ÿ\Z…Ç™k 7ME\ó\ÃqDqÝ€¬`+	\ç[s2s|VÊœ\ÏAN\ó®\ö\åºq‚¨R;¯æ…¸îƒ¯\îÝ´#‘\ÑcaÍ%\å…\Õ\éüSü\Æ°•`\0XB\Âù¬;\Ê:\'\ö¢.€(‚˜Å`X[Úœ\Ûo\Ï&¤\Ç@[\ê¿\ãž\ê\ñ\ÐcýWy\Ë\ó2\ã\Í\'M\×\æsi†N;Ÿ\Õ+nH$ªœÿ\0­o\ÝO\æt\Z¬<\è\Õ7>aj\ÃÜ®Ð‹»6Mp°\ÞBpD\'6Û‡3\Ég7\rC\àÃº¡˜\á{{”N¼m<û\åo¨p\óF7´_‰À\ñ.{¿Ÿ¯0&\é\æ/\Û\æ)\Æ#eÉº\Úo)\ï\ì\æ7Q¾\àqY\àˆ¾\á\Ì\òa\Øj\0\õ\éþL\ì!®\ìpü\÷4`t¬\ìv\à/\õœùhÛ«\É\Ò\Ô?²7*Î»cæ¯0! \æ\ôF§\ð\\£}E\Ê7\ÔWa\Ó\óE¤!˜¿:“¯¸°X\Ï\Ð\ï\Ä%šk\Ü>Ö©®ÂŽb\è„\ñŸ7`<\nŸ\á#\n«ý^O±\Ä\Çv…Rj\õ\Û\ð\ó\â\Ù\Ý—˜q\æ½£¿~\Ù~?}›ø•[úÃ»€	\Ú\ó\òl±¦5\ò\éL§º\æ§v\'œ² ŽsC³\Ä?úY#Í‡\ì@Ž°\÷„\æÛ›N,\ñ½\â\Ï;ŽD¢Qn„b”4;\rÁ\ìX·Å˜!<\'\óv3œÊ¸|„­S\Æ\ñÜ¨\Íú®²®nQ¿±\ß¨°;Oœƒ-ý¾~bz\ÒüK±O!ûH\ë\Ì\ì°\Ìf\ãN!5À§ilŽC%³\ê^Ö˜\Äm#[‰¹\'\à§\ã$\íšk±qCŽ\ð3\ïø(F`¬û7L:W\Ý%\ñb\Ä3¹\ïUmÍ§t—(9K\á_0f1Ã³5S%¥\Æ\Íwj¹M7Qu“\Âp\È\óhÅ¢\ì”Htw\ím\Õ\Ã+\Û\ëþ\n¥¸\àw|M\Ú\n\át-cŸ\ÕomÀ§2”d\ã¿mSÀ\ÏQŽ\ðO7{\ÏyG˜\Þp%ºç—‹8°¦\Ï+…¡ ,rÉ“¤+‘jsp•\î\Ü\ã\ð@~\r\Ûq™ü“š,T‘–x\'A9–6NŽú„\è\ÈWu­|–˜\ëá¿Š\å§~A\Ö\ð_%\Ä.\ç’Q\Ã\ÑX{”l¶e;Dþ<\Ú8\ñlù»›\ÍR¼IE‡‡ÁC”Ñ»½Z\á4a\Ä\ßU\Äy‚\â\ï¨ß³™N-\ß_Ó©¯}¾Š7\ñ\ÍO5žiº\î“Q»ú\ð@w|Tm»³\×ÿ\0\ÕS\îµOƒ‹Sš°v§D¸#\ôM€qM‰5 +\Äcj1\èM“\ØZsG^fÉ‹¹~Ì­Œ\ì{6Ÿ\Â\Ê\Ö&\Ú\Ýv‚§n\Z‡}¡}\÷eº\öD’nŽŸUž^F$>ˆº\òzªY\àŸ•yqkø\÷ï«‘Å›Iø²tŽº,¸sY¸6\árnB!Ä£\\‘EŽ·4	\íº\Â@\Ó4Èšz_‚k\ZÁ`¡ns\ãE»‹AX;Xƒ$\"ŒnE¤p\ÝR2iOny›)–\ØÔ­\âŠ\Øþ	\ì>„®\Öþ¿ ©\Í\âjÚ•†¶\óo_¿ž\óf\óZ[\Çq77¶û\ëÍ·	\áÝ™\æm©pÓ¶1\é»à¼ž„\Âkcv­s>\nCÓ‰½®ø)Žw`º©»vS\ëŒ_¿š:sYº> \Ü\Æft\\“„#\ntg±`ob\Û\í¹P£|9·Ne\ô\\Ó¡\ì\\šklš\Õee…a\nV†»%Ts`S})³¯\Ì\Ù\ÙlÍŸ\î[¡>Ñˆ\ê&G¯o´™‘p^QCŽ„H5\àþ*’nZš7\Û2?>t]\ö\è\Þÿ\0R¨o\Ê\ö½=?\Úÿ\0™q¾G´g!»½È°v-¨üÔ·ÿ\0vKmŽF\Å\Ø\Ö\í9¬\ÝP ½\Þ\ä9…<¡¶›\ÃKŽI°Ž*(\ñ\å¦I‘¾Cf„i%ÁX« þ\ÔJº;ƒm’†œ9¡\Î_\'‹\ÕN¦NmŠŸ­\îU=vø)¾Ý¶\Ó-üU.[>Q\Ú=µ^\Ï]¡\Éýgx¦ß¢{•d<½,\ñz\Ì!lio‘A\ßsú»²\ó</\æ¶9}£WP}=û\ö¯O\äpú\õ\rÿ\0·5\å#Á±¦ú¼\Ön¨™\Ö\ÑeŸgÚ¸Žß‡:Fx¦\År™„`u”=DuTŽh\í\Ý,,“\ÅKˆ\ÝK\0I\Ú\'SDGUK\Ør„!”úS\Ótn\ðot\0Û¤6c¼\ÕO\ÖSý)\÷\'\Û±¿y\Þ\Ü\ÑÞ€ÁID\Þ\à\Ð\Û\ìÿ\0RøŸŠá§­¾&ü›lTCÀ—>s\ôC\êV «$\ä\éfw\Ù^NC‚‡O\á¾_œ\Ú\ô\Ì\áN¼ä¶„Ž/,\à$\Å9¬\Ý„n\ì\íø,½\ß9¯6\Ý\èiuŒh ”gŒqIÁBq\Ä(æ¶‰•dz_Šuox_(½\îÕŠj,¹]G]S\Örr\nw3?G½hWmA´gt\ßHT†\ò;\ÅO‹•8€°oˆ^V´™EF>À[B\íÚ»1ý\å¼Í¶\ÞCjÁ=úÀ~Yn w\Ø\Ú\öOCNa!kç¢¾¶\æX›ù‡•¶¤µ;\ë9QE\È\ÒÁcúQim}\\\Â\ê·\é\ß\í»â¡\æµ5·ºa³·3«Ÿÿ\0Õûþ	¿—Ç˜\÷Y].||\àeuË»±r\Î\îBn\ä\Ù{\Ó&\\°R\Õ\0z:\Û\ðF¡\Ö\0^\ß\ò‰®zj:\×4·\ÓK*—^+ui\ê–r\æ\Æ\á™#&\r\0\í)®k\Å\Ún9„\ØT\î«Òž“”l\åÿ\0\Ý?(p\ÞÝ§ŽúQz˜}¥S§\öV\Ü\Ë\ä\õg\Â\òš\Ó\Ã7¨û~*–LpD\î8G\ä‹\É7*\í\ébWX²µ\òN@ù®\Ì\Ô”mjHx/\ñ\ælŒ\éd˜þ\ÖW¿\óUŸLÿ\0m\ßý9£‚‹¬ž,\ä\Óp˜s_Š\Ï\ß\ð\ÞtO9¬V2{·Ž0ƒ»UÐ•ý«•y\â¾M¯n·Áœ7\Ä<\Î\áÔŽ\Ã£[\ê{\Ö\Ìu\éZl\Þ=®\î\n\ì.\Ö\ÝQ\èŽcÈ¾|3)\ç.\í\ÝRlTM\àH#@Ÿr\÷\\{·\ì\áz\Ø=¥W×‹Ám\ö\ßf‡z®iPœQF~\È@n\Ú\ð\ò\Û>¡¼Coø-“&*l>«·»D	XZbÅ‹>\Ä\Ô-‘;\ö;y}­S7¨\r¾žs`\í*º^JŽ¡ý‘•E#E;#\n¯\éŸ\íŠvœ\ÑÁG\×	Í¸L;†~?\îË‡~\÷hŽª`Zû\ð+sn¬\ä\Zwh›kg§\Åq\ïø\'0‘‘\Êúv¦Dok\Ø\äµ\Â<¥C\Ã\Z\Ûw*HcCE\Ãr¿\ôÆ‹_\r\õ\â\ò…\ì/¸©]\Ñ\ö\ó\÷\"nQUN\Ð{\Ðl—=ˆ\ê\ë~ýŽ\ÜU\ñw*¿¥g²¶£q\ì©ý‹þg;\r1ÿ\0Lo{q±\Í<Af^*šˆ\á½\Ú.Ž­\÷]\ï\Ý\ç#Nl\ï\ä\á•ý^MEjY%>›þ¤??\ñ[_¥LØ³¼²±ŸžjL˜}“\ðS\õ“\ô\æ„\Óg\r\Î¦\æø.\Þ\Þ\'±\r\ïn\ç\Ä5\n\Ü\Ë \Ü\ÔP9\Ù4&Ðž.L¤‰©‘z­PRG±–ŒI±°ß¯2S{3\Ö?’•Øœ\ã\î¥6aN\é\Ë\ïS\á\ä\ó\í\ê\ö®\ßÝ‹aþ½þ\ÕW\ô­\öT\Í\ÇA3OùN[	ø¶l\×†\ê¶üŸn;±\æÿ\0½»­{d¦þsuG#¯3Á‹½\ôDZ\Þkk?±²Ù‘\ò4Í·¡\ÇsüCU]Ÿ_³\âûN“\ð\nN£½‚¦\ôS\ô\æ·s\r\Â69&œ\÷ü‚]\öF$brÀ{Œq’7\î_\'b4\ï\r\"ÁrV± øªp8\÷\î£q˜z\ÖA\÷C™+ú\ïÿ\0kwÔŸšp\ny	\ìS‡¢\Ü\ìz]pß±Ÿ\É\Î\ç[‹\â\å$8\ç\'€`n-e°ÿ\04\å\Ì\á\Ì\ò–<\ÓN<?\×5®E\Ó&s‡bv‡š\Ðu\á¼\ââ‹‰µù¶<Á\Ä\ßD	\ZnÚ·’zX;Oþ@kZ;\0†u¦t\ö¼§ü¸\Z?x©:¯\ö¥\ô|ù­\Ü\ÇX¦\õÖ‡ú\ÏsM\áù9„€ŒŠ\÷CP;\ÔaŒ]=s8)ß¦Ž\×&†°5ƒÜ¬»\ÕÁi\Íýep1_¨Q\Ê	#?z¾\é]f\å©\È)H¸hÑ¹ns°‹•4…ÇºÄªq\Ñ\'½U…žl-\Ñ§™F>m\îÿ\0Qz#v\Êùº½§ú¸¿{™\åX\ö~/Q\àªã¥»-\Ï\Óu\÷\Ä\èÀv o\Ã}\É\Ô\îk15\Ç\çr\æ4r\Ûpÿ\0\r\ð\ç)T|\Õ\Òú\Ó[\÷rS\å§ý2¥\ô|\ô\Þw\r\ãT\íŠn›šr?šk»wd\éq*\è\ÍÀfúV\ðA\òµØ›#±wæ¢«³ex\ð)\Õy\Ú6\â Øž\nF:\Ï8‡T\éd\Ê\ê¨2™œ«=aª‚Zj¡\óO¹\õNEX±–\ÄF`§8\'\Î\Ï\âœ\ï¤ùÓ \áª\åz\ß8z½‹—û\\.Ÿ3®Zo™\÷u»\õ”\ö2\Ê£j©={G‰\ìƒ™B\ÛÀÁ\ëT´.˜\ÃÖ”\ðš}\í\Ëp\Ý[-I<~³\n\ÙN\è\Ë\àw;ªžY‹ ,&þO”\ôo½\îf&\àm²\Þ\×a:_\Î6\×\ÏE°\ÊTV\Ôw\Û\ñ\ÏsQ..<\ZJ\Ù?©1Þ»œ\ïÄªŸ\Õ\æû·|ß²\ö\÷\ÃT\ÝÁ;0Ò›¦\ð\åbW\É=\àKŸ\à›¢n\ác¸\ÉÑ¢\Ä\Þ\ÕpS\ài8\Úp»´(6¬±C}qªid±\â†@\æž\Ä\é$»:\ê¹Y3\ép²\åd\õ¸Yb&\×:ny\Â\Òw<e7zfQ´,§&Ì°\Â\Îøže‹h›ÿ\0\Ü_\ó@\ß´y\ígÉ¶µDVÔŸ\æ€.6	ú\×\ÊÉ­sÍ›®\ö·\ógG7†œÚ§à¥™\ßd­\n\0\î/qv\ézŽS;%S\ÇŠ£f\nJv\öF\ÕYú¥GÝ»\à§\Ò/a?Np\ßû4Îª)¤ˆ\ì\Þ\çX+—›\ÍA	\Z\Ð\àH\Ìd¾Vü8p…\òŽÐ„¬\íM}´+–º6â ™\ô\Òr\ð)\õ\ñO„°[,\ïÀ¦\Ô\ÇDê«¸\Ø\ä3\â°:«©\Ý\Ñp\é‰}–meƒq,§úL\ÝsÇ™³\ó}ûDªO¡\÷žix úY.Q¶¿}–Ý´[R)[\Äû·?«\Í\rE\ÐÓœM–0®9²K|š¶„…´˜=bB*:vv0n{qX-¥¨¥k}\"\Ñø”\Ñ``UŸªT}Û•N}\ß\ñNÓœ\Ýÿ\0³*-7\ã*\ár™œY\';\îW\n\÷\Ð,/\ðB	¦\"¾E7©ø£MP\Ýø/’Ô»\ÐM\ÙÓž\ÄvdÀ]¯F*¨µm\Ât\× …t\×\ë…\Ê=\ï/¹\n2’ˆå¯½]¬ªcwž\í\ÑuI<\\T—\Ã\Ö\Â8ž\äü8„Xs6pÿ\0ˆ¤f\ê\èýû\ï¹\àt\\}u[†ú\Ü\ÝyKL\Îm}½S¿Ÿ²Ž‰ø1\ÃÞ\Ì\\\\)/%­\Â;V\ï\Ü\Ý9\Ï\×p@\ßq\É>l~U;SK\âá¿‰R\Â\ÉCqz.!9\ØE\ÕKË¨ª\Ïúnø*±f\Òý\Ï\ñGNst\Þ\Ý\à¢\æ¼]G\Æk\0\\l£†\÷ž\ô\ÞFùhƒc!r(@\Õ\É7±a	\ð´©)š\î\0ø©\öcunIÔ’7;dƒ0Ü”Á•\Ô\ÐPú=ÁrNè¾¾\n µ€9\Ùú­þ\'›³\êb\î‰R}¿›0s£pn¥E\×x\ôZ\0j\Ã\Ëlú†q\Ãq\î\Íl\×\Þ\ßT¢y—6³st\ÞM‚º Sµ\Þ\ç\õ]\á¸j¨›\Ê\í˜þ\Æ\ð3;ªM¢*¢¡ì§º‡FB­~/“‹[-\ó›ª;¯e\Ï{µ\ßm\Ñ?‚Äš\ô\ÙÀ¦O`.¹vv®Yž²\å\Úœ,#[©RT_-\Ä\×\ðN‹>\ä\Ý\à¢eÍ•\ìÇŸv\ç\ß	4h[ÛÁ¼Ngø+\ï+eþ´ÿ\0º\n—ªy·B\\€M\ä”á‰¤\"Êœjç‡¼Á¸»~\Ä.›‡Å§msm7‚¯¹\Ú ¾U¬T“B³\ï—0•Œ°\ÉN\è\Ý!1¶\ÍM[b­ž_w6´ü\Û|UgÐ¿\Ø*¯X~\èyZ7ƒct\r\÷8_s[\ÇqA\×Xœ%m³)²BAdup±4\'\Ôp\'Jºo\Ñ1–ÏŠ-½•”LÀ\Âã­‘ú\÷øƒ\Z\ç\Å+®t·2Ù²þžs\ö@T\Ç\'sª\Ý\ó\í·£d\ÓvƒÜ¶˜4»k”oø£,†^Vý.\ÔnI<P\Ós\\z˜¬\ÒsR˜º!œ5=»\ñw\';-.\íÿ\0)û\å?a5\÷s°·z&\å;ª|7=\Ø\"y\î+d2\Ô\×\õž…\Ã@\æ9¢J}\0[F&>Š|³6U_°û¡º\ÜÃº3Ã˜\× o¸\ä±‰=\Ý¢\Æ\åÊ»¹r\í\ì\å\ïB®Þ›—Ëˆ\ôŠxµE\ä\î‹1\Ì\åKš\àG\ç]¬ˆ›Y`¦—£„I\'¿Á3®\ß¶PùÊ“\ÞO~\ö“\Ò\ñ\ßYL=R?\r\î\ÉyOtÓe1Ø˜\Ó\Ú7p\æy™\å/¸¦\Ù9\Ã++¦´¸8\ßA}\ñBùnÀ_tL}œü\"Ú•d\Ñ|‘a7Ë‘\è¹\ÍvŠ²FˆU³˜\r;{‚{\Ã\ç\Z\Ù^n]kh†\Ð}´m\ÔU1Ka{;±5…’w*\ï\Ô\ê~\éÊ«\öt7v§k¼\îi±Dƒ¢;\Ú\ë\ÅD¯v|:f\õÉ…€,sz£t Ÿ07zaHx)Ÿ\èŽl\ç£\ö–\Ê\ê\Î~Ú§ú?~\ñ(¼}Õ’^@8³d¿*\Ïz\Û\ñr›:Cl\ØC•\âJX¡p\05\Ýe;Ç\Çb©¥¢\×\Ü\ïŸ1¬a\î/\0j\r\Å<­‹œ”\ì19Í½\ì¹B¹y=e\ò‰qbÅš[UK]Ž(\òÌª\\°x\ÙW“\ÈaJ•ŽÁ¡M†MSgsHk\ò·GQ\ËGŸXj«¿S©û§*Ÿ\Ø}\Ø\ÝÚ8ln\àŠ.j\Å|‡æ±ži\×pkˆ\ñ@\0LŠÙžywX„\\\ÉOv\"J\Êo§b\Ù#\æž{d@\áŠ\ã\×Q;C—(\ÒM¸)^1»Š.‹¶SM†;NŠWr†\î[=\ö«·¬,ª\ã\åi§gkTF\ØÚ®¯—;Mw€\òx\î5µ·`ù¼x†¶·ýç°±\å®\×s9G85š¡\õÀ;V(_kw­UK\Z²XFYw_\ÍIrKŽš¡ƒ\Úr>W~§S\÷nU?±û±½\Û\È\Þ<\ÒOo˜k	M`h@v&\Ã\ë \0\ÐsF»¥x\Ì|¬¦’ù\r9Ô¢\ó\à¶Mu;œ\ï\\ªC\ÒTy\Ã~\ô\âq»\Çq©wK-E¼\ä/\"ü*\à¨c¾\Ö\â9¡;>Û‚n–\"t\Ë\Çx†C–\Ý\Çp67µ\Õ\íš\å_®\ï\Üt<\Ç\õy˜‹MÁ±Tm<´¯=ª6J§ú6¢+O\æˆ\Â\ë\"¦\ô{|¯\ÅN\ì{>W^\÷„©\Ï\Ðý\Ø\Þ\í\åà«£\Í\çu‚\0â‚²2 \íJ\rkt\ð;\ÓÝ–E`Œ½:\î\ÚO¤>\É[\n\ß!\ï\ÆJ«ú\÷*/ )ýwx\áŽv:;£s3*c…Ž\íh[aœ–\×y\õ°»\ñV\Ýb\Z\r²<P{\ðrxŽÁŠŠ) 8\æœ\0$qÛ¾7D1r­.4\Æc{[{]9˜^Z\\2\â°\çb¤uˆ±²\àŠ§ÃŠ@\Ýou\Ë†\Ê	Yƒ$\ç8»	±\×\Ãù\'1¯·\ÅHo\0¸g{v©œ\ÓlÅ¬<-ü“nÍ˜ß“v¾\nm\"\ö7»M\Ü[\Ù’\ßn¾EUþQþ²F’¥¢\æ\"ƒ•\òCNk³†\áŸ\ò@\÷ø­w1\Ä\Î)\Ïü\õ\ìSI‹!¢\ðV\Ü9”c¤ÿ\0el_¢‹ÞœI¥$Ÿ\Ú*/ )ýwx\ÑD:\ÎRV@Ì±þWBã”„x©|n\Åk\ð[5ø©YÝ’\ò•˜k\"l\rÀ+Sd^pµ½„\î/\ì\0emØ€\ì\Ýbt	\Ú\ÄX\ÛtR¯`Gj’\ér„\õr·n\æ¶\'2Lo!ÀtGj§\'WžŽm—\ÇX¨zŠV\È\×^7;?®	\×s³$Ÿ\ëúª(\\\\	\Ò\÷þ»û•@µÿ\0v\å.‘{¸\î:ž`s›\Õ$x&\ÌG[ÿ\0r5\"Ö³¿yP(xŠKbÀ\ëv«da\Þ\r“$\íÝ¢\å\ZŒˆž\Ôùm™\÷\é\íw1Žµ\Ö}3\ÝcÌ¤ý¡\î[\è¡\ð+ÿ\0h~\ñPý\0\ñO\ë»ÄªxŒ\Ó ª\ëëµ¦\Íø©f\rþI’\ÊskN\Ì -’ü¥g}×•¥´>qGu&\å’™7:¬¸d„os\\æ´\Ýyqai±	\æø‰\\´Ý£\÷P’r/•½•\ËL=S\îBi\Ä~\êsn°\ïQ¸º\÷\Ü]Ò¸R\ä\ö;Ü©Ÿ\ÊGoIŸ˜\ÝI\ôA8t\ÎkP7\çg\ê•v\ï‚~‘û;®\ã\ÏÐŽH}\â\ÜtG¡+C-ŠO\Ç+/›\ì)\æ<¹;ûÐ”¡%\Ð7\ã¸9ÃŠÅ¸›\'\Í\ê\æœ\ì\óC4p\ä®-’,I9\ö!¨\'ÿ\0\â%§Ne7\ÑJ¶W\ÑA\ì•ÿ\0³?x¨~€x¢>qÀzÊ²_’\Ó[\×~§¹O.x\És\ÏDjS\ä/wG!À($*Áˆ\ê¶c\í;~Ð²\ò˜\ÂÀ\ÔT‡\æB\Äs«;]\Ù6WY\Íi y§Bœ\ë\Û>±ntø\'\ôI:\î‡&ž\ð…ø,mÇ‡Š›¨B\Â \Æ5rx\â4*“è‡Š\Åwuº:Œ\Õ?\ÒYú¥GÝ»\à£<79\r·‘Ÿ0\è\ô\Ýt¯\æq;µcj\Æ\î\Õ\Ë;@‰¾¦\ë4Fhhœ\ë‹&œ³\Í]c\è\ÛEˆ\ö.½\ì;\÷\Ó˜“Þ¶wRa\Ôÿ\0\ê*/ \÷ªfb\Ä\ð*¾£•žG\ð\á\àr\È\0Ôœ•A\r´-Ñº\÷•›Ÿ\ÇEJ/3{“^\è\Ëm¨\Ím\ç\Ìh¡\å3u\î\èß»2r}»¤2:ø@\Ê\Ùs\\n‚Œ¾0\ñfœM¶cEÉ¸ªY…,¸Ÿ^-k)$\ÆokfwB\Ö\òE\Ø\ó\õVˆ°c\Ç\Æ\ÉÙ‡-–þV‰™M6(³3\ØU(´Y\ö§u\Ý\âšûëªƒ\éûÿ\0¯Yú­GÝ¹<d\ÏgsD[\"Ž\ã¸\î=T\ÝS´\Þ9+ \åu‰]]\\+\÷ JÏµd†«\nÂˆÌ ;\ÖÜ£†\ö\Ä@‘m\Ü:\É\ñ†½Á®\à\Û\0´\ã»ET\î\ð+g\õ`\öýOþ¢¡ú\âW)‚ž­üFCÞª\Ýaeœ‘/kY¾\õEHê‡¸\è\Ö\ê{Ô¯Á\àÿ\0T“\îT\á\òž9u¶ú{.™þ\n”\ä|V©ÆœR„\ò·\Õ6ži\Z\÷µ½ê›¾š¥°\ã\Ä\ÌwÉŒa\0\â&\Ø{Ð®Uþ²‰\ÅÀ\Ý?\é\\š\Ñ`ˆ iÁA\Õ\÷(ù\'	l-\è\ØjQ\Ñ[¡!û+`‚(¼^Tw\'\0BsN\êgž^<\Õ^t³\ôÜ‰³YpY,]\É\ÏŒW\Ðv\'šw;\Ñ)º£¼\'s.¯º\åb+=Ì¹XK\\\\F…r­\ì)®Du(¸(›3ÿ\0–\ÞüŸ‚·ú>%<4œ²DX\ï‹*W{%RT\àX_£d?Qÿ\0¨¨>ƒÞ§?\ðu?zYù\Ë(!dŽ…®¿M\ÖM†\Zjr\ß@fJu\ç¨8Fo~I\ñcc§¢ž¡¥\ÌÃµm‹A²`ýrB¤·Iem\ÂYÖ¼€uM\ÝÙ–\òN$•r0f\ß4)\æƒ)[s—zu¹Ggÿ\0”Þ¨N$Œû^79½\áan]lJ€a4Ç¯?‚:\Å>;f\n¦??|S›‰®i\â,ŽÎ‘”å’²\ÇÀSšZKN£qApÐ®)¸3\Ä‰\æ›C­ù\î\Õ;œt\æ=È¹Ä›wB5A¸¤\Ã{j´\\«\ï\Ã\ðN’\\6\Ê\Þ\Í#²6üž\çj¢‡2š<t\Ïû¥FÞ¯pC\õú‹gþ¯þ\â²{*¢\âMÇ¹V´¶rb‡¢\êW}¥´k¹_š©\Ä\ö­“nùX*­A[$‘·Ä¯)g\ÅS<\ÛûÊ¤h»\Üo¦J8\ß#\ÃX.Js\\\Ç¸X„uMCŽ|Ã¡A\Îfm$\äk\'©‚R\r!\÷¶GEfWGuq²ª…\Ô\ï|n ›pT\î\ÃsoE½Aœ­O7$§\ÓIdY\Ø\Ù\á5\ðOž\'^ú\÷o\÷&\Êß”G„z[œÆ½¥®m}˜\à9X\Å\í\ð\Üw¸o#sxøo;‚w8\ó@\ÉX_t<Sº\ç\Çw%°¾\Ê\Û\é£\ä\èM\Æeª\ôI\í_û\÷­Ÿú¿ûŠqù\ç{KkÐ¶j“‚\Í!¡>\Z\æ\Ä]\éX*mšÈŽ)#ù*>½WÞªž²Ø¿«?\ÛU\Ó\ë\'“µ\åC\Ðc\òE\'(\Ó\ÒRH\é\ç»RQ\Õ7}50²;”\r\ÃÚ²¶™\Ýp*\ã\r°\ç}U>…?\éJÀ\öFZFy.Ž\Ö\÷\Î\ê.>”sü\'\\Š¥Œ\æå ]\Å>®6°4<n\å²\êLmž.\ÍC;_\ÑÝ„\\©%\Å{^\Ê<œ\×\\dA\\¼X1\ãP\í&>W5\Ù\ôJ\Ô-³²þN\î^!\óGQ\Øw»$m¸¸Q	¿\Ãp\Ð#©Lcž\àÖ¶\ä§\×AN\ã\Î\àP\æ\ñ\Ü[¢ã»Š˜YÀw \0\Ìþ\nü\Ê\nLnl²€\Ðv§\Ê]\à˜£`}¯\éª–Ác\ë\ó\ó\Ï\ö•u…I=ÁU~³\Þ+ªC\ó•_xªŠÙ²`\Ù\õŽ\õn$\Ü\È\ï;²¶\èJ\æ\Ë\Ë<ƒnŠb¾Zo\Æ\öº#¢MýÊ˜\Ä\É\ãt\Í\Å\ó\nyc3\È`±“C¬¥ª’Zx£q»XG-¾rÞ²‹C\à°\ÞGù£†\ÍnypO–Y\r‰>\nbTOgK\ólü\Óvm,qrM\ßÄ§C%;\ñ0\ßú\Í>¡\ïÔ”\Z-Ó°p½×Ž\ê*\îO¡!\è\ð=‰\ÍdŒ-vmp[Sg:Š\\³‰\ÝSü75\ÞU\ìP\Â\ãq¯f\èÛŠÁ8O¿º\ÈG(g*\Ã{]rg“p½·ŽaÐ ­¼x£†ý­œ\ì]–\Éen7\\wq\÷§–k\Å0hM½\ëW5º(©e˜41£\ÚP\ì\è¢\Íý7~[Û¡PQ½TŸE\ï)ÿ\0Jÿ\0kø­¥úË½–ªŸ§‹\ÚWTî´•x¦uÇ½Rÿ\0t\íeE\×‡`\Z©#’\'a‘¶*8&”=\Ìm\ÃuL\æ\è\Ç\Í^\ë4œ\Ïr¨l\r¨pø™À \â\"so‘pR8¸\÷\ä€¶\ò;Zq)Ò›»@ª-‘SU\Ò=v•I³))sc.\ïX\ë¸\Ì¯a\àrUÏŠ\Ýt­˜¦¾\Ú\"\âSbq\ÔXs(«»6|\ðCU	ùµÊºŠJ9Œo\Ó\Ñ=¡;EbòŠ®N6:\ö¦·¢œÞ˜\Ù\\\æ\ÜY#}/’\ß\Çwjf]+Û»spzW\îV\Íg\Ý\Ì\Z \Î\Õ`\ßtþ¹@\÷()¦\ØZÁ\ãÁC³!`§HþJÁ¢ÀX\"w4bp³\0½\×.\àÀ\Ë\åŠ\êŠVr#¤3u“Î¿\Çø­¤mT\ìýª~–#\ö\Õ\Ô\'§?¶ž©?º¶²˜\ì%4«\çqÛ’–i%v)I²l\ÒÇˆ1\äjš¥\á±\É$\õ\Æ\ë ln:\ï`%\Ù&Á\Ñ%\æ\Â\êJ¦7az\Ê\nzŠ¹0\Æ\Ò\ãÚ¨v,Y\óZI?!ºz¼™\Å ·bÙ²I,r¹\ç<j´½µp.®\ë_†\ë\Å\í)\Ò9úþ	°ž9#¿EYÃ±B\ãÊ³\ÅRÖºNl\'E]ElŽ\ëz\'°ªˆ¥§‘\ñ½½&•{\ðZs\Ö	\Ýb˜\ë…#ˆ# ®Ã¨²,\Ã\Þ;SGE?\"‡2Ä‡Xh‰Á·\çŠp±-¾›ˆ:\Õ\î\\wa=¡5†ú„o•—\í=\éÙ¼øª]ÁÓ˜\ß\ìZÆ´‹Á¹\Ú#¹†\Î	\ÒFGY^?X*Gd\Ïÿ\0 |\í\ãüV\Ð,ùK®FT\á3ÁcûDNeE×›\ÛN–ÇŒIOW\âmù(6ytÕ´\ç¯	o¸¨\ÎJûÚ†|m¹£‡=\Ü\n±9\0™O\ëeŽ€Ï±I4’›~AP\ì)%³\ê:\r\õx•@\Ì°5½\É\Î\rq°PV	\æ{:-\Z¬XkkH\õ¶d…\ð¸ŸYVÔ‘<­\Â:\ÉÓ—4´´ndE\È3MSŸŸH#%‘$\êšü.pPË‚B\âÆ»¸¨ÝŽ6;´-»³1‡UE\Ö\ô\Ç\ñY‚Ž\íB)½`\×*.*^šp”\Ü6ËµK\ÖCqAvø(ß\à\á\Å	\\\ÛY£$d\Ä-„I&üI\\=\Ë!\Â\åbs•‚n¡<Ù¹&u\Å\×\íG´›\Õ\Þ\í«5\×j\Ï%¬\Ñ\÷\í_´w\ñ[O:\Â>\ËUTa’S\Åû£\ëM\í¡ÁlM*½ ¾C\Ë~Wž<8{–Ô§»BV\ÐwI¾\ô3²9”\Ëb\Ä\æÝ­\"\áLøŸ30³€\ç\È\Çb’ œ›T{>¦±\Ý\ôx¸è¨¶]5&v\Ç\'¬wT\ÕENÛ¼\çÀvªš\Éjy7ƒV\Ë\ä£\Ú)\õUf\Ä\âj\ÙuG\Ø\÷›\ÝU>9f‘\à›¬\Þ\Ô\ÒÑ¨º3\öd\î;u\×j¢\r2uq;‡g½	]Á\ä\ä\ìûr\à£xx#³U¶¶Q\æh›\óN\×\ì”Uš0“ÁË±7BŠn¡;®|Tz©0\Û5\Ð\Ï\"²²‹Š“W%\ÏUcû+¡\à¹>-7@ƒNªÃ‹—C\Õ\\¯!%š·FÛ˜3\nA\ÑQ\Û@tÇ´‡WyV\í\ßÛ’\ÍBtûÖ¦}1\ñ[@•;/D*\îµ/¶¯Ÿ½Cr\é\Ïúˆ\rD”\ò—1\Ägššl4¯˜z˜‚\ÛQ2ª‚:\ÆjÁqM\Ï}\ò²dm,\Ä^z(\éq\Ã,¡\Â\Ì\ï\Õt;\niÀ\ö›b\0\ß\ÅU\Ô6¢Lb0Þ”l–g†1¥\Î\ìT;­³\ê³> MkZZ\0€\ÝW´[\Ûoø\'™&%\Æ\ä\ñ;¶_\ê£\Ú*Ryy²\ô\Ý\ñX\Â%b\ÝtM–%ã¾‹\Ó\ÚúW+\ê…\ì\ì‡´R\Ì\è$l\í Ž\Õf\È\Ë9·k†`\÷­¯A\òJ›7¨\ávÿ\0%dj<Sº\å3¬¤\ä\ì\Û\ßU\ó\\q\'`\ôo\ïQT\×\È\÷ ½\è\ÒB\àVdê¯—}•\î½³²\Ós\\Xx\ê¤#ª2\ÜB\é¤c)½]ý`®± n»WfJ#˜ûÆ¨G\Î<ÿ\0Z­ >}Ç¸*Î½7¶¸ªMj=½\Ò7R©°MGuœ\Âq6žH|.Ë©¢u$\ï†A\Õ?’Šhœ:\nf‡j3E¸Fw\Ç|\Âa°O\ËD_ˆ\ÞÀ.Ž¯\r\Ô\ô”\ô\Í\Ã\0\ï\ã¹\ò26—=\Öh\Ô\É\Ñc\rƒš\n\Â3º.þd¶g\ê£\Ú*o§—\Û)\Ú\õW¹Ç˜7\Ð\ßÎ\â\ïKÀ\'\õŽV\ËO\öª¡\ó8»üª0Œ7\èø›/(\\\×l\ð\áþh\Ü3N\Ñ	ýtÀyAš—ª<V«±G\Ö:©º­\ñCvw²±\ËU\èŸˆ`-‹“ª[\ÑmûV!—Dik§<¼‹\ØXpM\0°‘ÁfÀ\â\Ð\ß\Çw\'UG\ÖL\ë·\Ä,\"\ÃÛ¸\á{¬\\J½‘\ñQu‡\Þ5Dzr\'HMËœn«3’Ÿ?MqP\ç\ö\ÕÓŽª)¤‡6<Œ•.Ú¹¨\ï\n¦’–²?œ®¸\Èÿ\0\åIN\ö<\à\àP\×\é\Ý\×6\à\ÝF.5$è±\Z[Š\ä¼\',\í¢†1†\å¹\î’PÆ¾Ù¹­½”\ÒOP\ìR;.\Å_“\âû”N¾?Á_ø+­•ú£}¢¦w\Ï\Ë\í»\â‰\Õ\0\ìNÔ¬\ïÌ¾\êLb=3£G\óN¶7dt\ãìªÿ\0\r/´\æÅŸv\ßÿ\0e¶¿ºÿ\0\ë\î\àºÀe®‹ŠYG‡.\Õ/U]v&Ê›f£¡§7t\éþLDX.\Z(œ\æ8lŠ=\"Iâ‹‰\0\n\Ê\ÙœKœ\ã\Æ\é¦\Ê\ê\Ý ¤\ê•î£µ\ÚOhBQašs\ÚA\Ýp\Z±Ü¢\õÚ‰\Ì\æ½\è\Ú	Ž\é_¹_j¨\ô©\ó\ô—³{j\ê\èl\Õ\ê°\Û*’kœ]\Ú\ÕU\äû‹Ic±\Î*Zi q@µœ=\ê\Ñüš8\"b\é\r\Îýb»\î‚fŽ\ö\Ö\ÐúH¾\å;ø¯ü!ª\Ù\ÓF\Êk8ú\Î\÷)\r\åý¢\Ö;qNv\'o\áÌ¡Ð™½\Ãx´SÎ¿¥|Ž\íS¶\ô\óxªž°û¶üV\Ùþ\é}¸\õJ¹@t\à°\ç¨Mak®¥\ê\î\âš)p5\Í.Ç£šUd‘ \rû(n\"É£1â­‘\ðBù Ö¶+¹§Šy2\Ì\ÛTÆ¹Ì¸ˆ†g{\ß±×‚i&\è\"Ü\ÎI–½¬›\ÖoŠ ¬»\ÜP9§4š\ô]\â‡ÿ\0\å-~\åUÖ§Ó¬°šƒ­7´¥\ñ<±\Ú\ïc9R\ò,:%Ê˜Zš!\ö¢¨‘ø™%‰ \Û)\å\äš,.\ç\0±Q\×7“™ƒ\ð*³\É\÷Œ\à\é·\ó	\ñTS?0A	•v®c~]¾+€‰¹¯ÿ\Ä\0*\0\0\0\0\0\0!1AQaq ‘¡±0Á\ð@\á\ñ\ÑPÿ\Ú\0\0?\èsùPf`… ¢µpva¬¹Š=@¬½f\n5¨9ZP²GÁ£\Â2\07h]EFÿ\0Oˆ\\|.\0\ÃüU\00|mMnZ‹\ß\ñ´B\Ç/\ò¥£Õ‚\äÁO\ç¾^™L5U‡\Þh¨þ\É*}DÀ\nþý\"4£}U²–ú[™\î\é¿\öû\'/Áeü&w4\ÊË¨\òº[~+£‘O¿‹YþZ5šÿ\0ŒÁR¿‡î›±%5\Èg†	úš‰¦…°¶#M\ØsR\÷Á;e\Ë úH\ó\È\ãWC_\ívN_\àD”\ëgÎ‹º\Ì\ç\çy¯\â¤Vƒ}b\Æ·\ÌVþ?:ùÚ³¿\àx\íø£\Û\ÃL\Ó*\Õ-°…²; 9i*©\Ã½u­l¿3Ý†\á\ë\î_\Ï\öû>Bmœ\Æ_\à¼…\ñÖ—uŸ\àHy=@\ÑüÀhø7Šú\ô?\à\æ\Ó\Új\ê\'þ\æ\÷yÿ\0¶Ÿû‰ÿ\0©Ÿú™ÿ\0«†>ùJ»Ê‡d\Üþ\ßÆ—\\À\Ä\Óxu\ñ~5\Ï\Í\\vr˜\Ì,\×\óÿ\0qNª»‘u\ßÝ·Ž°\ó¾›\è(»G—ø–\ô\n\çø»\'J]\Ö~51\Ò\Ãl\òÿ\0²ƒ\àû‡\ñcþnÿ\0\'\×\Z{´†B\ÕV\Z\ï\"z½\íù…V\É\óœ¸øQ/\Ø55\Ï\Õ?ú\nh¾‘s8;\0Ø·\Ú/¶\÷\n{•\õc³Yb>Á‰»Ìš_½)lƒ/PWxÌŽ\Ô\î«\á\Ï\n‰@·ù”`\Ó\áú‰Õ¦™=?¶»&\Û\ÄšzÔ®‚š¢;z amÃ®E¬¿\ÉNg–0‹\æ\àš…]”LO1Uqº\ìwÿ\0\ÒW»^\Þ\\~…‰e”®ºM´Qy—\n¦\õ0\Ýy¼\åÀÃAú+\épE\Ü\ö3oWs$WK³’SY\öf\n4\ò%”ü\Ûù¥À\Åc¥	ú±¸\õ¾\ò\ôƒQeW \"jµm17hp0|¡[¦>\ÔÙ‚ùkº±\Óü\Ø\íþEL¸~$U\Þ\ã,¦ý—\Û%sJVœ\ñ6Ÿ7	\Ûµbš@\ñ\ÛùšÈšM_8av\ñÎ%\ãv\à\r\Õ:Š\ÎÖ¡%”\Ú\Ó\ìc%_\õL.\ò\Ê\è?D‘SN\Ò[mb\Û\î\Ùe;,¡Õ\ì&\×e	(z\Z\n¯š\à‡o\ð¥+\àÅ©OKMo,u%š+*?\ì¢À=dN\Ôx­\Ýa0wGcùØ…\0j{.\ì)’dÝ‡\òMp6L›)Á‹Œ\ð\ò	b]ÿ\0\ËdB!\÷gÞ¼³¼(\ÉMQº‚\Ì\\\ÐÇ¹€o47‰·\â›Í‘ \"à¶®(•b,¸˜¨SN{3\ôü¹mƒÝ‡ù”´‹>\ôWoD&9²•«©\å\Ñ\è‰\ÓqLO‘\ÌÀoQ\ëM‰DcLž€®%*\åy‘¼ˆ\ë˜J\í1-e|\Øn¡ÿ\0N\r)X\ÃÈ‹ª¾V\Ù\Ç\Ô:o²\ó.\ñxŠ“¡=P(Aû\Þ])(S\Ê\Ñ(\ç—}\åK\éØ¤|\ÄnlPE\ña³M—\Öú\\“2\å\ô¹r\Úý9b»#F\í-5\àŒ\\x¦ ¯?dú\Ü\Ù;œØŒ”\Äe\Üþ]Y	•q\\}²\Ú]\ÂX\ÃÛ“úÌ’s\á…p³!—/¥\ô¶_K—\Ö\â¼\Öþu¥|*\r·lªhEÙŽk:ÀY®!hV¢T™od’L\ìlH|\ì\ÕP‡ž\Ù;S\Í\Ç\Úd\ßT”¤#Ôƒ\æÀ›‘„‚{!\Ö\ë\æŽ¸²\ÏNþ\àEKlÎ€þ\0AN~´„?&	¹\ô“Š \n¼#[²\nù\"ø8þ3¡û#•@\çA]\ójW€*¥95/\Â*ÁCm \0Di1Í¨˜øw<“X\Ï\ð›?•ü‹¥\\T\Ò2\Æ\÷@„&K%orE_\Ô¹¹\Ô\Ú\õa¡\ZlÇ’\Ä2\åY¤U„zT¼½\÷b\0©‡4]™`y±E\îKŒ­´Z¿4\òz#¥µð–»¼Î¼^ûÀ#,ž \íK\n`%¼\Ìc†\Ï$\"$†ª\ñ.xn{øƒjŠŠ@Á%>»\Ät’‰F9šü{GMW]<×¸•ü!TtF\Ä”¾Ã‹d°˜\âû7nÄ va.ˆ\ÔAÓ+–\ãÀ\ÕÂ•Y’t-\êm…\Å`©\è¨›vH±þ\á\ÇQ\ê\ê\ðg;\â$-¡\óE/Ž·­’ZÀSlš	v¸\×.R£|°\0Ž‹=\ÜgÜÞŒØŒTmL\rYý3\çüˆ;\ËØe.5\Ó:œ\äbAV1\ÊV‰/5\Î:w\÷­üh8þk%V­\Ò\nt\Ä\Ýf(º‚\ß\ð\ØE‰\ÚJ$\ZœC‹yVl‹‹\Ä8\ZÙŽp\ï«\ïV—\r3[R\ÏB’\Éd²Y,—.YýV\Ø\õ]›~gÚ…\ï((Œ\î {w\èQ«¦µ/q\Zƒ\ï\Ó\é’\ÆY$@J[ý°À\ç•\ævŠ«\'\ìK\áa\æ\'	¾\ö‡ ËŒw;†\î=:Y\Z–K—.Y1.Y.bY,–EÄ¸ƒl²Y\Ñ\äª[L—.\Ý/\öM %”\ä «\ÎMF(\ë@£°\ÜK\ñ\ÚÄ•poD[h\Ðw\Ó-l\óÇ“„dU¶$\ÏE]ŽT½11,R¾ˆE\Ñ\×Mz\Ý\Ý	”Ý½Ê½Å¢ª•J:dC\Ð–%^d\Ä\ß\é\Ù\ÓûÊ–Žƒpd\Ù4ý\ß-Šc\ë\ñ\Å\åvˆ\å‰\Í\÷–„Z\ïÃ¡\Ú\Õp.\Ðˆ\ê\Ç\\LLt;T\Ç\\LLD&&>b‰E\æ\íø -‚ üF¯Ëªß„·J—2þº#\éx\Çc‚=\í\Ù*Ë˜y”o}\Z¬°¸\ïÔ¹59û|GˆOD{\ä\ó’üø\Ò\È\r 5^…\ï\örÁvª•+\í\Ó,2\î\Ã·\É\ïS´`œ& ±»|Ä¹f\Õ\ß\ÇG\óýb\Z\Ï\òiœµ)\r\÷½\r20¿)¾§£BE5£\æ\Ó*2<\Í_C\ZB\Ë\îYcûþpuyMK=³Ô¸d\Å\ò%\Ô\ÔCb	ž\"\n\ÔAM\Ë}\r®¹þs\Ã\×?\Å}\Z/­Æ‚ÆŒ°(xœ\ð.ø\Æ\áSu\ï\Æ]%V\ß}IŠrA;‘€xM\Ë\Òÿ\0\àŠ62Œ}ò”¢œ’ iÙ¹j\'\Ç2¬¾\Ä\Ë\åmü™e\Åb\ê\ã\ß^\è%_[—\ò¿à¾—.Vëž—.\\¾—\Ö\åË•\Ï\êd\æX\ßW\']ü‰f\Î}­ÿ\0œB¬04`9€Q‹v¥ Em`_PaˆAt\Ä2ú¯\áC\åË—.\\¹r\åË–K—.Qw/¡w.\\¹}\r%\Ë%\ÔÀ<H\04bs\Ñ\'¸·\ç¿þ§2\Î\×\àA½²: \à\ô¸\å\ßK%\Ë\ë‰rú\\¹d¹r\å\Ëe\ËÌ¹r\åük7.ff~\';$1\Ò\Â\æK\Ïaÿ\0\ã[ìŸ«¤[<L\ô¦fffg®~9øf_\Æú\Û\ð¾—-˜C\Ü\Î\ö\æ-\n\ê#nF§—ÿ\0\Z\É^K¹%Ë—\æ\\¹r\åË—.\\¹p*\\¾¶\÷–\÷—\ð¹s3?G˜@ ;J\ÎVH\ó¶fÍü\â`Û€\ï\Ô;¯bx	\àj#†+†!Ä§ùªmý0tB^Ÿz>\òüu¾·\Ó=/¥Ë—.\\¹}._[e\Ë\érþE\Æ/Y®—³o\êL[ùUW\ÆþH`qü€SVù\é\n\òu¾—/\á}/\ç}n\\¹r\åË–t¾¤£zBƒAÒ„Tsé©°k\Æ\î\à4?\à\Ô&.\Ç\ðÛ¼o§N\ñG\×Eün\\¾—/¥Ë—.\\²¥\Ë\ér\åË—.\\¹r\á–\nz\Z-ˆ“»\Ø;Gc»ü)\'ü5\"\ôvhþ\nœ\êº6Š«\ÍO8K\è2ú,¹rú\\¹}.\\¹r\å\Å1R\åË—,¯1Ä¹}h~•ã–Ÿ\Æ}ø\ãøj\n\ï\Ï,;\ð\à*_\ñp»¤;Ô´\öD¼ŸJ;ÿ\0&:\\¼,¾—\Ò\åË—}.\\¸d\ÒNP}´]º\æ\Çùn¦\ñ¢ú€l”c³©\Ün\Õ\ÅOi@½MþR<\0_t»&›µ\Òáž¸¾—\ð\Ä\Ä\Ä\ÇK—3/\ãr\åË—.\Z^o\í\Ð@C\Ú\Ã\Ê\Ï\Ý\è#Qo?\Å_‚o\Ô\ê4‰¸fM0G.b\Ë\nU¼q5B˜\êž&:k “\Ît\Ñ\Ù\ð	E\rJdÇ—´£·¢+]„¡¿\Ït?\ö2|/¥\õ\Ä9Ì¹™}.\\¸\Ã}Ð½i«¬t¹rú•v®†\ÓÛ ŽR\Ò^%úÓœZø‡J¸/—›<Œ!\ã\éÀ\ß\Ã\"B°ý!t=˜\ÃŒÀ\n`°8”g‚\Ø{³Õ‹\×0\Ü¹l\èO\ñ\í;c¾}±¶p\ô:Ÿúeün\\¹}T•\ðvK%’\â\ËÁRå’¯\0*™}.\\\ö>\Ý†î¼¬uk\é“c\àO¦Š¹€h˜þEA•\Ê	Q1>\Ô	*uŸ¢H\ê\áfÁ%\Ë5ÒŸü;\Îù\ö\Î\Ø\ôGœý`\íøqK˜\é×²#[ªûK—/¥\ôn)\Ó2”\\c¥\Ì\Ì\ôÌ¹}9\éq\07kÄ¾—.[/¥Ï–Þ‡›ûK\Ë>@À°þ¸\ð\Ä{£™M]c]DZ_zµ\ó\Ñ\Ü±\Ã<y •L\Úvü¾}±\ã¿nÐ¼\è{‡þZ\ÕJ\ç^½9—Q4¤¹r\åË—.\\¹r\åË¿…¦~W‹X%Ë™…Ø\Ó*U\ËúO\ñ‹\Ê<þ¾0D¾e\í	\ê\Þ\Ù\ß\á1S\Ú2\áˆ\ZF>\\>—S¹«#n:¡\æeØƒ¶´¢\ÌUZ\Û\\ 	R\Ê$\ã‰\ß>\Ù\Ûˆ\×Ó¿yJs\0_Š\ðBtÁ#œžú.Y,ù\\¹}-Œ”@@\ï-–Ë—\Ò\åÀ.LK\é}|ø:µ}˜ý6ü4†¥%ƒ\íL_±5‹\÷ehP+¨¦¬Y.{\ç”\Za»RÅšzT¨\0T`p\ÃC³e‰z™šH˜b\Ê¾%\ôv=`\öa\ï\Û;c<\Î9{\Æ\ï\Ï\êZeW\Þj¬¹ž\í =m\õü«—\Ò\à­`e\Ì|n\\¼WÂŒ\Â\î¦ß¤_aˆ\÷q\ö\Ä\Ý\ð\ã\ïª!\rœPx.Z\ÆÈ¬0ˆ\ÕW%\Ú·X`± \Z^\ðÑ˜d\Î\Ø\ÏŠ\ñû\ÙúC¢\Ñ(mùè´¦\ÉÎ¡F?Q±qU\ÓA]„\ÇxkTxhY\Ý<Ò„ýLü“š‡\ôNù\ö\ÌÙŒ\ðv˜®k\÷]ø\ä¸A\é.5;_d¬2\Ý=\å< Fœ4MK\é}5\Ò\åË—\Òú\âŒ\ï!Zž\Ñ\ð\Ö9¹;m\õ¨\ó#MŸ‡qø½nC´\r5’9\ÝY=1\"\ôÔ \ÆùvÊ€û\ÎJË‚VÜ½\âYF˜8\ÓK«•»=‡i\\}E»\÷A¡b^ª^b^\Ú{\\\Ä\Üx5À‹vˆ’w\\\ÑG³û:C\ñž\ßs¶3Á\Úw\Î9{\ÌßŸ\Ôr‡\é:þº6\ó?\\}\"t•2üC6¤¦-,ÎŠšiø_\Ç=n\\\ÕKƒ;}	kv\Û\Õ	ª\ö´v\Ö?\rŽ‹\ë]3Ò¦^d•Þˆo°1žvwþ®cm\Z\àX]rLwKR\è\í\Ú„ˆL¾\ÌšCÀf1UQD\Ò\Å\ö\"xœ&)C`\Ù>®f3z\å\ï3z\Ï\êQ^?s\"MŸí–ž\Ï\íe\×js\î:|ù†F~\ð»0>\ôË—	J\Û´\Ù„\â^Žf\È)‘Ì¶Õ—/­\ô¾–K\óÔ·5\ð\r	~­piO\0E\n¾–ø\"PŽÏˆ\è\ãF\Ø+ªœ¢\'K\Ò3`¢ˆ\rËº…\â{\ÂÌš‹´w{ŒmA^¦b\Önù•¦T¢ [B9‚D\Þ(\â\ÙÝƒ—Å‚\Ô\Ù)S\ëŒ&¹û\ÎNüx˜¯¹›\óúƒ\\e/½˜\ÂÁLi·ŒU\Ç(ÁMÁ¬7\ç3W.\\¾Ž‰\ÜýË—\Ò\à«ŒK‡P—\ÐbT¬üEM0AI’WU|\Çm6\\›/´\Å\ÌM¸þ\ÑÉµ{e@r/¡}?\Ø\\¸\ê\Ó\ïF\ï]^š¿	˜(O}\Î\Z\Ä\â\à·hø\ôè’«l\ì*¨–­\0WQ¨ZnmV¨\æ`½\å½0p€%’œ¼‡±\0w>\àe<\',\Ç|s\æfüþ¦1\Û\÷,t\Û\0I¿\n,?û¿\Ü!ú\ÂUqtú\Â\Z¶øz\\¹r\æK\Ù.\\\ì^¥\ô¾—\ó¶ª\ñ\ð+6:”GÙµ>¡T\ò\'tQ\ëe¯¬w\Òß±F%\íd\Å\õz\n°\nŠ^+°\î\ÆßŽýÞ•›˜anüF\ô\ï¥P@\å[\ÚQšˆ\0h\â^¸À¦c‡þ£MBZŠþ`G(\\\nŽw…\÷G\×x¸Cg2ÀI¯\Ò<NÝÀc‚füŸˆ\ë\ôw™\ö\ï\ÛÁ)\Û	;\Þ47V\ñüÿ\0³\ZPK\È\ìÀBS Í\â.\\¹r\ã¥\ìƒ4mo¥Ë—.\\¹rº—/¥Ë—\Ò\á7O#\Ù\×Z`\Þg¨¥œ\Ù\Õ\é£\ÓTtj\ÏO\'‘v ´W§jTÂ¡«pb5kC\Ê\Û\è8À¡OA2WqJp·¸\ÃQ³ù•ÀŒ¦©\Ö.¦\íÁÅ®\Ä\n„ŽÊ£Um±k\à—\Ê\à).ºÿ\0˜­c·y\ß9å…¢·sÂ\÷%±Ð£\ÚKº,¯sžœXp{\Æ\\jÜ¹}3úæ„¹r\åË—/ø\Ô‡P.r0\ö\à€\ìü­¦·þ‘^\çC\Ë;ú½9J\Ða„`Û†vm\Ï\ê\ã·;ýxø¦]º*1	3<\Ålg°\Ç‹ujg=d\Ð#\ÆQA>°D-)[$!	e©aC.šWL)I,\ñ(|7\ôC–\ä\Ä/‹\Ä\ç^\ÓUè²»|&Ÿ+ý6½Ã¡*…O}¸\ÝW:‰\ÑF\\¹c\Ä\ÐF\Ò\åÔ¹pJ\È\ëª\ò©R£¹ž€ ·¥\Ëéž—©¦(4D\'®	€W}¥½n\ËýU\nü.¯M£z‹•z!®\0ç¿„\òk\ô2˜¦­Ž\ë¿À¥\ç¶\\ppE4	ÞŽü_U\ô³6`E²º³\ÙÐŠb¶\Â\ò¼À\\¢™x%’\Ð\Ù_V>Fµ\á\Î*ad\õ9P\0DºOj¥º/¢‡x_\Äl€§g\ÜmR\Z\Ù\å8;pw\ó\íŒJ\ãD h\Äq\Ù}ÁºNšJ³c9<·Ü‚\ÍiPU\Õw+m‘\ê\\T¾—.\\¹}D¡2\ëø	\Ï*¯B„Zýý vd`E$\ð\÷Ò£¾›\Â\Ë\Ô\ÍV\Ê1[\Ë\Ä*?«†M£Ë·„\\T™e.-\æ\ÊF\Ý\Ç\Z74wOl‘N‡o\âP–\ÛlwqªL¼’\î\Ç&7F\0\ÛÛ´\áÀ¤~€‰„}xš%¢ŠÆ¢\Õù~¢Ád\êm\ßÓ¥-Ê\ä„69\Ôm\Ý#½¹\å\íz?¸&\Þ\r\Ì\Äx¥ÿ\0‰(`h\ï¾sÊ˜ú9b¥\Ä\Þ(VºÛ—\Ò\åü\ét=F\Ý(\èns©\è®\÷ý$n~wJ fq\å-Œ`«yR£\ÓxÐ…:”¼<\÷f¢U•†^*‚ÝŽWv\ÏKI\Ê<: ªm1¾]/¶ºS\íBy\'1–\Âa¾ °\Å-®\ò\Ñ*r\ÛÁÀ«¥\ñp\Z\í\ò\Ç©Á\Þ\âª,\Ïù\ê\\‚š\ÉÛ¢]²\Ú\éV\ð5*–£\åJ*8/l¦À¼.gn\Üº\Ë\í‰\ØÙ¨°þ\õ[\ëŠO³\ö*\nK\÷\ÌJ9³\÷u.\\Y\ËÀÛž\Õ¡¥–Ëƒ\Z›%Ï¬¿“\êª\ÊøŠŽ\æ.øÿ\0n„nc&\"ÞŽ®\ÙB¨hü0¬½\íû¿	\é˜2\ã\Ñ‡®\Ä@$\Z\Ø^,.\òüØ™vz9#ŒA!š}E‰)\íT˜	/Pü°\Û‰‚q6\Ëqk2Œv!˜-\í-¾\Ð\0\0 \ÑÕ9\É\àe‚—\è:Y\î:\Î\öŒ¯Î±\ô#–\Æ]	\ß>\ØÖ†{Cg\ÞQ6°7\n\ãHgÁý¨Ábu\ÓWjûS •¿(³ƒ.h¢ZiŽ\épˆ®Irüt\Å:‰\\ˆ\Ùq\Ë+\åOL¥“’˜/y\ËeƒY¨û_hü¼LŸF=\õw+ ”\ò¶C\â\â\\v\ï±N}¯vYZ\Û\ç±ÎˆJa+Lf:©¦\Â;a¨I\â\"\ðZ\Ú\Ç\Ô8\ô4©m\n#i\'\'-„D\â|0w¿\îb¯M\áx=^\'…¬20Yzn\ÞY\íS·\à\óí‚€\Èý\öŒ\÷r†\r\Ô\÷.£_’\ÏB\ìŒMù>\÷q€À}Ó€\r)\ï\Þ9\\¹qgµ}eË”Q|¹@WEþ:~[Ú¬®ˆÎž\Ø2”	\ô\é{^%¬¬\Ãd\ÇüX\èµ=\õzoÒ´Æy\ÜkEƒž‡It;c\ÍLý¿,va¿?\r¤<\îbÀ†\0V\Ú\Ä =2®w¹jx#p\0µrÀ©p\Ë\ÎÂ¢\Î!_\÷0\ßU¤¤¸µmÁ\Ìâ§—— $‹B‰\ÅJû\Ï\Ò=“¥\órø\'n|N\öûfqFx;JÌ¶•ü\Ã\ð¡£\Ò#¨-\Î]\æ\íútY\õ\\¸6Ç¸\àeËŽe’\á$Á§˜”\×[jº¡H£·Sr\ò\ÐyÓ¥\ò\Ë2œ‹¾\ñ\Ðø~‰	\ì_§£\Õ\ñn\ÃC\Ñ\à½á«œ™\ì#\í£‹\é¼k»—Á0¦h\"a€2\ÊºCNf\ÑWb!n\í  mQ<Œ(púL-\ã\'· ~\Zˆ€Ñ ‘Jt\ç±*QJb›p(9T+¹\í\nPZÊ±\"À¬\Ã\Z¾¸«\Ú!\í»0\Õ\Ü\æ	[8ø ÿ\0Yg%‰Œ\ö\å\ï\â¦vv\ÇÛ¦iq7~1×„­î¢›‹\å\Ä_‘\ézL-ûœA£r\âÆ¢\0]·™w.Z4Á)øµxo\áÃ˜l‹j\Ämp\ÔtW5ß—E‹:u‰^‚ ¾K~mŠ¦?\ÆÙ¯Jø-%t,%ø—Ý· ¦a—s\Ç]\ÆÖ–§h§oyS_\ÔÁ¯©LB\ÇP`@À†£¨\Û³?I­\ï¼wœw–|\öƒ¡ 03Qf\ÛYƒS1\ÙÁ\ÄG‘J:xHŽmv\Ê[°üš\n\ï©T°W\ï\îŽ\ÏÁ1žÜ³6w\à\í†\ç~ˆf›œ\ÂÖ WTD\0\ÏN3.—}¢%rû\Z\í\r•\Ñj\ë].0`\åß®·.Âœþ•*T©QJw\ï\ðe6è®&?¯\é‡EREÀ\Õú‘Ø¿T`¯\ò\Û7\õrt\Ó7\ès/Ô¥+HF‰RºA²\Ét\ÛÁupB,\ÔYFjy•\ë\Ì]°\ñ}ž\È\ôo€™Š‹¤9E\çqË”&8.–¹a\Þ2\é\ä r-J\Ò\Þ	\îYœK¥Œþ\Ò&	€w2\ËÕ—4=S¾}³·~\ÓKûÁ‰ÿ\0± \Î\àWKºµN\×.\ìûC~½\ð—\Ú+¥K3rà£†º4º\r\ZúÅ„¹rú@7ÁB\Õ\ÄT\è\ï3Í†ûf\Zl\Ë\éoJh¡v\Ëß¡  >\Óý\î\Ð\'œþ\Ó|®Œ©[œ:\ì{$OPn\\©/M*³d\nÁ©R0¿HA3OJÁ¹Os~‰R#W]\Û2µ-\é 60\Ó\Û\É\ÃQÁ’ÀKh\áï˜–ro=\ÌK\ÊjWi±b‡K¢lþcÀo<\à\íD·º±è—¾Ü½\æ~µ\ö•\ö.0~\òæ¹„\\}Š!°¾\õ7:‰\æ¶%mz•“T)†=BYÜ—Ht¸‹XYo\ÑX—.\\¾š::\ê\â\å\í§d\÷À¼\ï«\0\0\íˆ\î]—`¥JC]ˆn\ÍqPb\í\rkþS7Ö§=O}28µ\Æ1\æ1rœ±`Ac–\Ê\ö²n\0¢}\å«\'‰BÅ\å`< z!—E\Ã\Ñ\ñS~’\ôXmYQK¸ßŽÐ b»v@lmg“‹B\ö «y·\ß2±/\rÿ\0Dü®eo8\å\ï\ÆQªs\Üuÿ\0¤©{\ô;\ÔYÀÞˆ\å?t­\ïýaƒ©g~ª#V¯¬¸¥[e½\å£ƒ{‹€«.~³¡‚%’\ç\ågXˆ\Z°\ßØ—\Ñ[¯\ÃM•1‚‚x\Æ\Èˆî—¶\à\Ã\ë¥tL\Æ07¨i:Z\Õ\ÉR¤ta¥WDQNp/3°\ÌaH@j\óˆ/lËƒ\n/Š\æpL\êf¤¥	ùXÞ‹­p|°–.\r±Jv\á\Û\ÌC9·/x\0\è\á+\ï-D\ñ“Á\ëÐˆúA¿|xW\Üü¿S\n4Aa\õ\ï]H%\î4&¨>„\àƒ£\"úÃ´7”\Â^°\Ì\ÙS,,l&9­š\\Y)\ËX:Tt\Í\óC\Ô_i„y‚\è—sˆl”3­;’Õ•Q6V\÷Y/¾ƒ/ ƒ{•E¨\ôeF\r#ŽNœJˆcP\òD”6˜‹\nÀÕ†ƒ‰PTÀ\"yN®a‹JƒE¶\ç\Ät²ž\'žŸ»0£»©U\r*•\æR*Xxº\õ\Ê\Ê!8C!\îm€WÜ¦\÷M}¡`4¬\ÛE\ô¤—.¹r\æ\Â\Ôúf:C\÷‰°W°ƒn˜iµ\óŽ•/^\Ò\ë\ÌÀm\Ø]yT´\â6l˜Dh(V…t0™J\Û\ï!lù‡kÁ!#?%Ñ¨\õ&}Va°Zp(\ÇK›Ç¯\Å\Æ‹®\Ôu›«šbt=,\ã\õ\Ò\â\Å ›:#,yž\Ý\Û9j¾|J‘\ËV0aF—\Òw$©\éœ(\n\Â{%\Z°\Ô\ä¨\ñ\Ò\öÊŒ\î R\æ\0¼‹@m¨71\\¸\ó]\ãm,)¾Ü½\æq\ß\õ65ÿ\0h,ùe\ì7\õ¹	§]X=S‡Üº®l¾‘O!>!ƒPK\Ç$qQ¸\õ/i-tU\ÜnGc†P$*\åµ3e\÷ŸHùK±mF\Å’½}	k¡0\îX-$¿\í3¸©)\Æ\å·;xD\ò\æj	´OŸX0´»º\á‹kkúg1P\Ó?\Ì\í5\èMût*WBJ\ÉV\Å:¿‰\Ù\Ó][m\ãüÍŸ\ÐXn§û½RÄ¹^\é\äf}²ž†½Eo,‡\Â\Ñ9*\È\öZ\Ôs\ò1o\Ô\rwýLV±û‚—ù\ñ,\0\Å!\æmk\Ü\ö\éU\0¡}Ÿ1R\à\Ú\í%‹´‚S\Ö	\ÎG@ž5Q`l–]lƒ-\ïZDr#\Û2·§n\áûeUˆL\nm ¨	l”`¨½e\0\ÕøÅ‡\'x§\äR\ë\r²\r\n\Ö5\Ûq\é(½\è”\éû¦ŠEF	i<¼\Ï\ò{K¤mÀ¥C–=¸\ÓÓž\\z¶_\Z€¦Ú‚\Î\Óµ•Uuo\Z¯R\å\ôB\Â\à¤Ó²\Åq\ZÚ¢: ¸e{|Lœ\äB0nZ³k¬\ðvœxý\Ï\ß\êb¼~\æI\æb—iW \Ô\nJl­˜\ñ(T?¹eË•¹Ü²¡wŒOX\ë¢\Û\Å#ýKC.\\^™”¤ŽœtX}N\Ó\ó3\ÓW²>\é\Îs6\Ë*Êµt\ÞúUn›[eø©\\\\\áœ\Í«¥w\\¾%t\å\\\×\×ì•ŒÉŒV¼\ñ_˜\Ê$\0›\Â>û“ü.\Ðbz\è2t®’1ŠŸ‰i¦£\Â\Ó\Ò\ó8\ë\Ì\Ïh=\Ö!K\ËÌ±¡j¼Aj‚g\àÀYd³´V‰p½‡2\Í\Øo\ÌaG¯\Üý\×\Ú5^?}=\äa¹uY1ø\Æ*\×¢\íž\ô\Ä,À”\0\0‹P\Õuû=…?\"\áe#|K¾\Æ\\5Y\Ô\ô A a!e¥Š n]³\ñ:\ô­ú=à ƒ„\ÌAPi\".W\ò\Ç7`pw¨­®\Ûc1„\"5x¬Qýw9„»\ßW\Ü\í\Ú\ZQyV(\Ù\Ù\ïß”\Â\Õe\n\â\\ze\éPj=	\ðN\è‚€‡5ˆcp\á}we¡y\å\Ú£‚Pa¨\ÂýT|\í¼etÀ±pffmJ§$s\í\ï³\à\í5\ë\÷3~]yÄ±©\ÉSO¬üÀ[…€\ç.6\Ì\çj»Q\è\nAˆ’\áy*˜j[‚í‹A«\Z—@”©U9\Å*\áÑ¶¥\05²­\Ñ6¸\'dPP.³\Å2§cMYÒ’ t\ð\ÔL3\Ç3¸Ê‹+BQ,\ê7%Gƒ8²\ä;¡\Î ”\ï7uˆ@¨TÚ·_\ÜS\ØWe«ýy›aW–yO\Ãþúrt)E\\\Æ$x;*\Â!½}\Î\ð`®\ñª¹ÀÌ\Ç}X¸\Ø\Ù\Ã!½u\Þ2•Æ¿³(µ\å—\ôAš\éj\ÏqÛ¥?¬¸\Ã]\Ý\æVJ\ò\æ	£@€\Í\ë–v£<¥,¼Ÿ¸Ý½ÿ\0SÑŽ—<*©\Ù+Ic\óF¹JŸDUVN\r\Ô$3\ãˆ7u2\Êw-’½36Á™\0*\à\"[uˆ½üt\æ\Æ\Õs\æ[C€\×\Ö ŠE½Y€\óOKW\á\ë†P3]¥”.™\èQb†\n«ˆ\âŒ\ôN\î\×v­\÷úwŒ-†\Ê\Öÿ\0\Å\â&¬*\ïÆ­\â¡}\ô¢Ì¯z\î\çB9œ9‹¾\'û¼½5,¢Yh\è\Æ1~\ÑPL›Û½\Ï\0\ëfc\ÊsS,©\ÌMCˆ°.8Œ\0\æ†\ã¨.Þ¢‚\Ô&H®±\Ìl¼@„X\íX„>³HOgi\\:ý\Ä8ÿ\0\á¿q•\r!0ŸW&Ì¾™Y‹dˆ°jy¤Rœ¼	k`#Å^\È\Ü	1n(b¢‚€‚<7Kiµ\÷.ƒUVå¹›A>\Ó\è\õ[±Škj\ÏýP\Z\ZU\Û_\ÙHû·\÷\Z\ÜÚ \Ö\Õb\òhfa\ö\êú\Åg’!q_¹‡\ä/\×\õ908·ý¿\ê/4>uþ\ßC\â\Õ?=0CLc¢\×€\Ò‚\ötN/Gs=—\ÒgÆµ\Ïx\áÝª [[•.nÐ©e\Â\åK\ßDfy”À°¥\Ý\æY\ÞR·v\r&nîˆªR²\ð®\÷™Rr\Î˜Ž•\èþ\ã¬G\ê\r8\Z\Þcùýu“r€\÷#<‚\Ä&´wÚšXÛ¢aŸ½\âSŠz\Ü(A¥-\Ä-\á\\¿µý\Éo…`\08¥ù¨„!¦\é\ïPšT8(8eºø~2\ê\Ñ\Üj¿q\å\ÈA½\ZE˜s€\ñ\ÑP<·\î2®\ô\ñx‰[v.fÊrq=O1\ô{O\Ê@¶\Û^\î[C_5ý\Î#\×ÿ\0‘‚—´Twˆý\"T½’…	•Pdº\ë‹™\Ä#\ô‰™X\â\â	-J4¾\óÍŽ\ëÀK>±ÕºxœCiR\æjše±LH¦f\ØWc´<\Ð\ç½ÃS\â±Zv\íÀ™¬ÿ\0_‰·\Új\öƒ£?\áŒÛ’ž0j éº¬r@\È\Ê\í-ý‹P!}*\öŸ…cxR¯2š5ø\\³Jùn\0T\Í\r\rsÖª®\Ë\ÉˆX5o»HZ\×i˜ÿ\0¶˜	¸\r\Ýt{Àh)”·7-µ<D…t¤¿ \Ì\r\Ð\ÜQ.\ì™<\Å#aFýL«G…vk_n%\ïWz\ò»D$f“z#¤)‚šŒw]L\ÈxzC)w›¥œ­n¢xcx•¨…\Óvx‹\È¶n\ãY·b¥\ØT=\Ò=84\\Aû¥\Ð\æ\í¸XiC\Äa†ø™*O˜¨}:%ªYDú›}º#\ä\÷9h9¢&Œ^úFJÓ˜×‹‚\ì(„4·\ö\÷,Ú²¢p\ÍS[Bù¢n©x4\Ë\ßW\Ñ}¯¶B-\ß\Ç\ís\äyQcƒ(zrcœË±g\Éþ,·+œ$t½U¸G\ÞZR„’…\Z¶V•=3*\É\Ã\Ërx\Ñ?B¢;fCº!\ï7C\éD-Š;…\Õ0\ó©\÷&˜p\õT½.¡P]¬Ü—‹@†flT\Ël¤ \Z/\éÊˆ~³¹e\ËZKýfafdƒ^!X\×rU0`\Ê\ëZ*Œ«D´‡Pz{,}YI¥Qî£±\nÏ¼3\Ìq\Ñ\Ø\\®Õ‰%\çK·˜\Õ\Î)\îR\òKåªµV\ö#\Ð@$¯f¡˜nø—\Êbs”¹b\0l\æ\\_0<|µ\ôˆºF©an2\Õ9!N\Õû(S\ÑØŽ\Ä†¥_$[sQ\Ãp½4•¹G€\Ý;‰\ÉÝ‹(Ç¶hž†°¿q-\r;\ñ\ï\ÃšDb\\\ì‰Lz1\Ü=Ç²p¦©•\0Ï»\Û«TÄŽ±-7s™s\ë\ÌT\åä®›Ž¥°ºL\ÂZ\ß53‡r\ã\Å °v†”þ¥\ë6p\Ø\ïq9Ú¡±\Ù\"M\Ì:þE.\åW¶\×¡Ý•±\èFi±@»V,#D\Æ%\ÞÙŽ¥\áLZ`j4}’T\÷\n<\\¶qY\"\âø\ç»x­[”®•\ï/\n8„\Ò1\åXAE\õ¶_\é1¯%*f”2\ëY-Þˆ°\0\èƒ\ÐmpZU\ð\÷*Z  ›.j#¸¼\Ð=ÃŸr™9l\ñ.:—†\â\íÃ´\æ\á\ÐÄ˜^Q\ÐY5.\Ë%1±.0Xc˜‚\rL¢Jš¶=‘\"j+\Ä\è%–\Í¹HŠ2¨_\Æ/¸…]s\Ú^]Ã’\nWFM8ƒ0L3˜‚\n4Ÿ\Þ:®\Ü1}yHz+\ëÞŽ\ðs§\ïÑ‚–\rKº»Å‚\ï,w½PÕ·\\¥\ï\ò/À\Ë\ßrÏŽ\Õ?*+úß©I\ÚqPçˆ…­Wev\Ô\Ó\Ó5\â¾\Â\r\Æ\ä\'j‹ùn\ñ”V\ê-.™S\ÏhV¨xUn0K\ìÁ\ð\õ»YLj\ãEH\"{e–û®—ALqy–¸‚\Í*W\Þ\è¢rd\òêŒ›³¨\r°hª	¼Y¡*2› l\Ý3k‰ˆ\â \ÑG\ÚS0¸{\Ýd\Û/±k\æ;À`\Ñ§<GhC¼¶\Z–¤=\ò2X;	V­¢)=\Ò\æ\\ü9™Y€§\Æh†™k5‚æ„7b`›\Éù—\ZM\ã9fÏ¨µ)™\è@ˆ\ìéŒ\íÝ«¸°C’fN\Â;7\É\rÖ‹G\ÕÆ„(¥tTü,KY\õ´Š\Ò\Ó-An\rÁwr\ß\Ò \Öw-\î\Z-\Ãe~„£À\Í\rDewŒ\Ø×ƒ*\ê\×¨sr‚±6#(¶°ÿ\0rT9–Ù1‚\n\Â\Â#LÝ¨Í½Ž\ð`›X«Ä¯Øµ\ö\ï\Ïg\î&+³g5\ÌL\ê‹\ï	’³H\é#Šƒ½¡ª\ä\Î\Ì\Æ\ÛB\ì0\÷1jd\ÅUCH¦yF\õšª¼Å»m¼À5½–;f-}^½U«µm‚øXY\õ&¢\Å\ÇsH­\ÉH¦q…0\ö\Æ>¾Bl\ñ˜{¨- \Ù\î(f^COf*³Û½E—Ô¹}8Ÿ€Ä”¤\Òú®Lf†e2Ñ‚\Ëh\"\Ø\Ö\ðE\Ì}²„þþú%•¾…²¶±º\Ðl{)@\ÄP\ØY‚œžø›7\èGŽâº•–cûcGx\'Ca?c2u°\êAPKºn1Šú»\rš†ØŒ¸ˆj\×G–&o\ß\r1 ³j 2\\ÊŠya¸G\Äv\ÜLZ´\Îdem.T\Â\ïìª‚ÝŒh6Ò˜5Ñš1›w¤A6¾\ÉTi¢ˆ(\0²\ó\Þ\'¤\0t\æc9·ZŠQ€ \é,\Ê;†¶@%sp*=\ËûR¨Û†~\äS ¯\ô…jbª/E\\\Ä\ÚR{ŽI‚-\ìCJ\'$Ý…\\›x|K™VŠ\Ä@L\ÆF\í\ô cÑ„)0\î\ÓÖlú¬J\õÍ¡¢r\Å¾QlElÅ•©r£\ÜÁ\n\Åj+QZùÒ£²<]§Œy*,\Ë\"ª¹™³[\ì\Î\ÉU@/žU@Á*A›b\Æ1W¾\n\öG©\Ù9“¿\Ý\ÍD\È{(D†\Ó‚\Þ5/.£\Þùœš\ÜX\"ø\'\Õ\÷–0l–k¥7\ÑIJ\ç\Ó2”\ðƒBæ£‹\öG—¼:™Z\îm	Ko¸)k.&\Æå¯³Ÿù®\Ñù¢þ\Òï‘	Mya`Õ±×¹-\ÍQ\Ýú\Ò\r\ï»a`„M’\â—\áº\'·\Ä´\Í¾²\âß¢T±Zj\ðB\è<–—\æ\\7†`£œ”µhG6ü·B±!hY%\çª[@jªq+=\á\è\É\Ì\Æ>]\ÌW\ô˜´¬B]¢\Ýi&0¤T\÷+sB\÷\Øpˆúts\0Lt~L_r-.¹–*V\â\ð\íŽ\Ð\íqp\Ù)ˆ³\ß$¡Ç•+\ZP\ÃeKÅœn³¤”`\Ù\à\êYv¢ý±\n{¥?\Ø: \êR‡\â	L}\ÈÙ”\Ù.\Ü\æ\àå­ˆ\ð\ôKŒU\é1[³\ÔÀ\\^U-a[c\É.\ê8@B¬ÁÀ\ÓûŽ\ßp\'¹m\Ü\é, ‡q\Ë\Ë)GO¢\n\Ìv(°B\r\Ì]VvŒ!«–¥Ë—.:}KKB[ûNfAC\Ü\ë¢ûˆÃ–,n\Z€@-²\Z@·±_$´\ñ¦#À¾\Ñ\ñUìª\å§7zŠ	G¾Ia¶mp,\÷\÷]‰TN.¦k\ð\',0]t\Ê@\ê\Ü[GI´ü¨`Áú˜(Vøaÿ\0vN1ª\Í\ËVQ›$\Ze®±&+P^)Q\Ð\ñ\î\Ô\Ë\Ö(\î\Ê\Ýù\ÐA\ãlÁ\Â\í/6˜\ìy¨û\Ä\Ðh%¾\âe{ ¢\Ü/ DX¦%\ðc,l,YJÀE\0L§ü\\wþ›Šd\ÞØš¨ þ\æ\í\01‹F­C\âV¼%Ába#\êÉ­ýï¸ˆ@]9 \éR…n³˜ \à\çŸPn\çT\å\äJ\r\"{5 h\êœ2¶\ÐPŠ#`—[œlÙ¥‰B«–ˆHÅ±\Ý\Ã(A^Ð?bX\â\àÀ­\á•K\ôŒ\n48–¥Â“\ÜE¡T9]\â…\0F<&`Q\Z\ð³ƒ\r¯ÿ\0¹CÌš¾\å]3\ó\ô\Í#½]”Y]„5>¿”K9\Ý\ÌA-š½L»QbYœ\Çazb­UÁµqr4l%8¤“q£j\Õ\ñ[›\í°´³y\å\Ú]­_\'\÷DX³aox½\ÖnYQ*%¯»´Æ…ZWþ¬\ËÆ½\Å^+_IŽOÜ·\î‹\×\Ækx\ÔURª¡¹_¦\'j¦\ô¼eb\è\ÅSŽ\òÜ \ó\n€BÀFD¤ˆ\ÄP\ì¹uœ\à(ûGv\Ý,\Îg™·e\í\èmk&¢›Fª\íºúJ\Ê\îPúM\Û\÷˜ÿ\0\"Ê˜l\"ªR\ñ0Å´j\ã‰\÷1\ÜF> 2¯»ZHÃp|Ì‘¿\ß\0·×…\"?tw\ËSse\ÅJ„ºg¾1KŽv˜*l‚\ÒckJ\ë1\å5RlU\Ë\îaEÁ\Âå¢ª B\ôÍ¿ü—\0:x.\ï—\Ìm\0\0\Z.G­ÁwVÆ¦;&\Ë×‡\ÅO\Íû!üa=¨‚±\é\Í1ƒC†\àPyˆ¶j!D[Ÿ\àw”—‹>\ñ„\Ô-[b\'Ü¿\Î(G=\â{˜tˆ\ëû	\÷B¯„‹T\ä+N!)wwL\ÒK7y–¢m\ñ\Ä\Ùd2‚W’ž\åQ\ÔØ»\÷E{»‹\êÃ¼\Â\Ðp4_i\0³\Ù\r­\ñúB[\"0„Q\Â,8^\ÔÁg=\á|\Â Žv}%+•pÒˆ¢\Í\ì\à\Û\nŽFüB³y\Âi\óý\Ø\Ãg\Ìv‘•»Ô¦„c‡”9­›8¨\é<YŠ…]Š,¹T¾Ja\Ò—w”[ˆY‡pZ»\Ú¦e]vK\Ôt¢Ò¿YV\Èh£B\Î\Ð>5h³«5¢Œ\Ê\Üv%.\ê	k²\óª.sLv\ÉdƒD$³N¥)‹,…”©\æ¥6£½-\Æ@\äO´c\Ì?,´«€ýË·±ýÁŸ\ÏuljeM7ª†œ\ÝCt,\ÙP/ž©J]\ÂS†\ì!7l\Ûý“B\ÌN©D\Óy¢¾\Âc3tý@\Ã\ë\ôš!º¨ý#*\äE\ÏJ\Ê$;f 8>\Ò\Â 0I‚\Õ-Ù¾ƒ–d¢v<dAS/°\Ó2‰\ï\ö	—ù1‹\ìÿ\0lzJ“.5-P±m··¸Qd­“\ö‘¸E\î\îi<¢@J\n,9&&·+º\\Zdn2n0¶?p™73LS\è%.‡[\ì$]\Üã€³\ïE´²Š\Ð?Ü¶\Â6\Ô9¦ ¯,­rX	¯Ì£‹€AúH,uŒ\Ô\Ùe\0%‚rE‚WÖŽ^“\n\äl–\Ìi‹²*6&Yw²\åË©f\è…y\è<\î\ZO7\ê\Ö;Š w\óË¶\ðjYS·H‘zG\Ìd]\í~¡Œªÿ\Ä\05\0\0\0\0\0\0\0!1 AQ\"02aqB@Rr#$3Cb‘s’ÿ\Ú\0?\0Ÿµ‰M\Óã—¹\Úf”ü\ò\ßCµ*Äžˆª„[œ¶0¥?\âmV}¦ùW\ò\öœb’µ»\ð\í.%mq*j®˜\ç|u%¤‘þe\ÉI4\×%??iK²)J)vE.\ÈIZ\Ð[,\õ\ï\è^ƒ_\ä\ç\í|«u•^K›V,)u¨ýœ8Ky7\ô\'†¶\Ãl\ã_\Ñû8£ý1ÿ\0²\âÿ\0\Ûà·‹À}‚ž°d¡(\î½yûYL§Ù”ûÄ­9\õb\×d,4’s\ÍEh”Q,ezk\ö<Y¾¥·\×;}Å‰5û…ýQLM=p\å_\Æ{M\ÂMqCnÞ³ÙŠZœ\Ça\Ï\àR\Õi\ÉY\ÆE¨\é\rú±.·lž•\ê\É\áN¯Aq^–AJkÌ…)a²J8‹‰o\ÕÒ¬ž\ÌRBqµ¡q\í\Ô\âb->œšå‡†\å«\Øo\ö\Ç\ò*]²\áRN\Ìl7‡6º=¹°p­½…‡ªHj‰$Ö¦°Þ·\ê:§h¸vb\à}\Ü\'f(\ÅkEVP…½X\ôB¼¨F>œ+ª\ï“\õ$»-[8RI$45c\'YQEQEQE\rZ8À“c‚8\Û6%l¤’11”d‘\nž©\å±?h•±øœ^Œþ\'ú†\í·Éƒ\âa‡¸>\Ùüf\Ý4FQš|,¡¬±#M2>QGBŠ+%\ZORx‰B\Þ\õ°\ßlŒ\å\r™üL\ë¡,I\Ëy?J”¦\Ì?)\Å\êš\'8F\õ7k.\ÅVtQ^”R»Ÿ§\Ô\ñ2·_\Èq5³7\ë’\Ùaz4R+*(YI\ð\Ã\í˜I]²n\ä\ß\òpvˆ\å^rVx¯Tº$?&ç¢Š(Ð¢Š\æ\Ã{¢\åK-\nF;\Zv4\í\èM´²\ñ¡\óW­\r\È\é$QEs\ÑEQErF;\óü%Í¯&¼\óGt-\ì}=\Z(¢Š\Ï\Ýø\"¶w\ÓSY<«%•–3^Z(¢…º(ªhd\ÅeK±K±K±K±K±K±K·¡?s#´‰{žH¬\ï–ù\ë&vú0^z\ïEy/cû\ï%²64\É&\öV4Öf\ó²\Åe—›!û.-z5Íˆ\ê-°£\öuyt7(d$\à\ì”ø­µ›b’\Z¼¡5\×\n­ºuQ‰¤\Ó\õ\ñ½¹M5ý\ò{“R²“¤\Ë„\ËÄ‹By\Ý\Æ&2\ò¦a»‚ÊŠÛ’¹\ñ¥­¨\ÆzG\â\'~k/&JV\Å$úˆ¶)\r.‚’{\Ù\Øý¨\Ä\Ú&\Ý’\ÝŒë›£&\îL[˜šÿ\0\ó\Èù,mŽÙ‰TpI\n\ÒZ\r¶n)´9¶²\ÃZY\r+.¨ý±%\'*0L\í’\Ýz”\ÝE\ç>¹\ËNTQCB‚BK±Â­R1#M\Ò,Z‘T‘‚B\Ý}\Û\îÈº’#ªL£j\Z\ôq\Ý!e>¹v$¶\å\\®i!\â¨\Û%‰\ÄÞ™a£°•5”U\Ê#\Ò\ï,\'pBÔ¢¬¬Ÿ66¬Š\ß\è\ìO®o§.¥²\Î:d¬š»\Ziˆ‚¤ˆ\îGY,¡\îE¶’l–ùxgi¡-s\Ö\ö\çdÝ¶G\Û\'ñ”º•“Û’²¬¤“Hp‹\\wG\rŠ\è%±F\ï(nþ„<¼3©¡-Ju£7\Ðj¹)\ç(µÙ»e\Òk\'\×7¶}+*\×\\«\äIŠO¨\ãÑ‘Ã¶’%‚Z\å\r²Á\÷^y}ŒFQš#²y&·ª\Z\Ín2¨ÂŠv\Ù\â)a\ç7(6—Q¦¯L‘\\·y45$yD\ä)S²NÝ‘\ë”Vˆª0˜\Ä\÷²Š¦‰ªi˜-8!\é“(£\ô—F\Î8\êa\Ånxj\'VnCB*5¾\äÖ¬­\òCZ¾};š\Z\ð1\ô•Ð´K,mý“\ÖO\ï*1\×øXr<+N4\÷¬½\É\èl‹8‹»­\Ë\ézZ\ÜQ’­LTœ\ç®\ÈÀÃŒ¢\Û\Þ\É`&‰\ßLž\ã\Øb\Z½}&\óŠ\Ö\È,ü:\ë\òMSo\äÃƒvšÒŽ5#ü»]R³\Â5\ÇLQ®¹<\õÔ¬¢­‰y$\ÚÝ³I=t²ÙSù\'¸\ö\Ée$W=æ¾„Ÿ\äJ³…¨&‰£\ó\ÄEyW\Ê8!t<²„’i\Ú0<¸µ\ò*\î;\é\Ümd\Ý#[z\ådd£¨µM=­˜‘\à·Ü£\è¾\Ég›r·M	¾´U¦³Z\ZwÊŠ+\àHŒK\è!e„¼ŸƒL\'ý\âj8jO°\â©\ÊoG²#Áj›1‰’\éd^\ßFˆ{¼ø¾Y\Ä\ìWkQ´m\Å\r#\\?\ÉMWÑ‹\ïüe^a\î\ÆuC\Ý\r\Óc§Ð¦5©Â“z±išB]\Ëb]ÈŠ\ò\ÂOiûLo\ôŸ\÷žù¨¿ll”ø¤\äý«dEKŽ\Z\ê\ÞÇ‹\Âk\Z2MjCXG\è¼Ø’Õ‹Ü„¸šU³<Lœ%\n\ì4\ç®µ³…5¿C<3_F\ä®\ö«7Ð–\å_Á§\É\å\ì\ó\Ô\Ô}+¥LNI\õ!–\Ñ/ø˜\Ëü9x¼¸X¯«i†\Í\í\Ô\ð\ñ\ãÅ·\Óc\ÆbA\Ë)§$\õF\\¢š\Ù\õ,zä¯‹$\õTa½Oœ¢¥[’”U!6ž‡ŒOŠ\àRŒ¢´©$IZat=™>ƒL}Š\Ø\ÒÅºQlI+B‚*Ž¨\ÃUO\à\Çÿ\0J_û	\Å\éû•NW¾\Ï\r±‰\ó¿dŒ¢\Ê\è².›-\ôDwüX+“1|OqŠ\Ð\ð\Î<:qYV®Œ|Õ¦\ÝQ\áiqC¦èŒº2K¨\ä=\Ð\ö\'²g”m::\ÇzeDnØµ²Ko¢µ\Ð\Ý[d_IE³\Ãjœ\Ê\Ón†;u5ÓŒÿ\0wû—žƒTQ5~&kþF\Ãz-y:ƒ«d\ñ£\r µ­\ÉNRv\Ùúr\às{Yƒ\á\ã\åŸØ¿‚ûž#99At\Õ\ê˜\Ñ\ÕT´%T™º\É\ô$\Ò{š>¤6‘h›º\ó/£\Ã7\\OBq‚¤‹v´<F\Z–\ì\Ûû½\óûF°Ä—‰\Äw³4¤¶|®p\ÃD\ñ¥+\ÔIÉ¤•²X*\\RÕ½‘‰	<K¤t0£PG[eS²Qk\\·\Ì~\Ò/M™4©1;[>„£\Ý\ÙUHŽ\Ï\ìŠÔ—½\÷¡l²ŽS\ö“•caüE˜m\Ü\ï\à\Â\ö/	\Ç\É=&xy7†\Ó\Þ/%—Z}Y)NIx\nmh\ñü?È›P‰m\Õ\ržk‹\íe\r4lwµ­\Ù%\åhŽ\ÂV\Ðúv-Ö„:z½\îD}\Â{I‰‹ýHË¢Taû¦`¯)\â|<±£N.Æ±p\'ROV7(û¢þ(E2¶!\'¨ £<:ùÑž!?\Ó\Óú‘\Z\á\Ñ‡OT\òo±‰\íe\ìK\Ûù\É\éci­\r‰º²;]ºoE\Õ\n®D^´ISDoˆ]\Ä\ßr\ì\ìJ;3y˜2\\)X\ögþA§5z\Ùú¸øo‚\ÓDq×²]™E³Ü³ÿ\Ä\05\0\0\0\0\0\0!1A Q\"2aq0#3BrSb‘$@s¡ÿ\Ú\0?\0¥\ë	Õ°\ÔMf;\rD\é \×0gT\Êøs[Ó„£`/·&PÄµž©ƒ¡¦¡™€`¦¼V\ÅÔ§K\r‡\Ä\Z±”¨Á(b[AŒ¨jKs¼›\å~ÿ\0Dt™ú7\Îz)z\Â\Ä`«Öª^\Ên-\ÑLHâ™„\Ç\Z.¨(a`‚Û²¥€¬(?U—:,‘\épvÉ¸G3úCWU\à\Óq06q6•‰ª\ïü#(>‹˜\êuf\\7™\èTf>=|œ„ý*~°¼Z£jŽÿ\0kÆ«ý\Ç²¼Z¿\Üwû+Å«ý\Ç²œ\÷¸CœH\÷=R ¨\È›œ­ÿ\0NŸ¬tœ‰´\å{GU„¢\ð6Zžvi¨y^û•\á¿\Ý?º,t<@…B=Al¯\õF\×L\õ#º‘\Ü)Â¤w\ëØ¢@\ÝkŸHM¤\çn\nm\07At–4\ðHpS\é\Æ\áv)¯:~¶ü¢Á\Ã\ë\Ã\Z‡\Â\ðýÖˆ\Ï[œ\r/¹*ÀX*X\âÀ\Z\æ\Ô\ß¸šFbœ\Ò\ÒA@°’†ŸY\rNƒ,\Ç\Ïpœ\ÙMqiƒ²ÅºÉˆ¶B\ä-.D:	”\Z\ë_…¥\ÝùN~lœ\èLlÜ©D¢Sj9Žiº¤\ö\â¨Xi\é¹\î\0,F)˜`Lþ\é\õ\êT2\÷…\Ð(„\Ó\Õ~¡2!yû„Cû„û„C\ãp‰q#¥Î„\Ñ%J*rÁ\×4kûMŠ\Ä0ÝŽ{ªÕ†„5¸\"\ç9Ä“$”\n+{}P`„j¬²µ\å`d ANt¹X|7ˆ\×C¡\ÑeQ®¦aÀ\Ê(L%Pü:¥O3\á­_\Ò\à™c%x8û\n}ZF–€\r…³Ã†\ë—‰Á:»Ë¼fû\Ä\r‹OÁU)T¤\è{HRº7\ê›¢2‹\ï•òŒ‰’©3S“e±x”êˆ¬\Ð}\×\ô83$T)¿\Ó\Ð–ÀOrŸY\ï\ÜÀ\ë”Úi\â¼ZU›¢«Ê­øq\ê\'P\ì‹\Ãi\n\n\Õ\r˜~Ul+iR»\å\óq•\×9\Ý]]]]]J”&\ò¥J•e)\Æ\ÖP4¨6\õ\ÙU\ì\"\n8€\í\é‚Q®ý‡”v\Þd§qR‰‹\ÆR¥J•*T©\n\ò¶\\\ç\ì#(—…\È	¢\0\ô\ë~R¤)Sœ©Ë’c¢T\Ê\æro\'\ÝR\ðz\ÃP¦9Z\Ø(–‘\ÙÁ\ZmF™D\ÇMq`QúB\ç¤žŠs\ÒJ\r\èÓºpc\ÑTK\n;—\Û\ê2QÎ€`¯¡W\Ù\n€­\ç(P \ä\ç\öROK®\Ó\ð¸(l*n§)R¥JrŸ~HlS}P›°\è\Ò\ã\Â\ðÜ¼2…3d†E\î\ÐI^^\÷E„g\ÝwGs\ô£¨l™\êm“”\Z\ÏCwÌ¥Š)íƒN\Üü§Xƒ\Ñ`\Ò\í•?PøC*\\£`V±\Âsœ\ñ²cšbm\ß\"œè•¬ \ñ\Ýj˜ºUS[9\ÈÝ³\ô\"\ë“\Ñ9œ©z\Ï\Æt¶+u¤\'2F\é\Ô\õL¢\á`+\ìr`’œ\ÂL8’NaN \çd¦\Òx0S\îu¹ÿ\0)—i\è”YÍ›\åF\å\Ù\Ò\ôŸ•IPT&¢.€•I’à´§3{\"”\Ö{-²\Òy	\ÍQ\Üü\äû9\ß*™\Ý\ô¥N`[*ü\çO\Ó\÷C`‚²,•B¤\È(#„Qij‚\É\åPD£¹ù\\\í\Êf\å<[2~\á©|\éÝ7d3>\é r¥­ ªUd^\Ä\í$Ø„a®\Z“˜Ò›L•EW”w(\ìV\ä \"Q¸?U›\çOaO\Ýe¦D…t\ó°\÷E\ñ\ÂA0AA\ñ²uwTŽ\ëY4\É3´‰T^\\Ö“\Û7\Ó\÷)\É\Öi_¸¡‘±9JŸ£L#•3¶tè ˜\è²7U\"\Æ\ëK¢…1< ™\á8&`§aœø\0Û”\Êa \0r{¡bœ|¯>È”\ó\å(zŽu7G)R§­¶	\Ç`»*|e*(*r²(S&w\Û aL¢œdªŽ\n¥©”UOID_:£”sC²> ¹L\ã\"©q\Èdr”M\à	ZL\\¦—b‰&\Î)¯{9\Ö:©`o\È+R\×e\Ý8Ê®| \"nUOO\Ý\ê	i\ÊT¡\Ñ!FA\ÃPE\òg\nQM0\àr\ä&;C¦´:KLw\ZƒL´\Þ`\Í\r\ßr‹‰Ù¥8U<8|<~?!j¨\ßU3\òi¸0S\ñmÜ™T˜Nu‘\Ü,A—;«(	§\Ê9#„\ë˜R¥„ª®\" ª2jetê¯\0¦™ŒŠc\å\Üf\Úm’@A2 d×µÁyTªÓ£:=\Ó@N\árªºK¾Tªþ›\é\nW1\Ò\rùU\Ék\Ì\Ó3œ©^+–°ª…@úÏ¼\Û\'\Ó/qp6B¦|¡²9jc]\í rJ\n\Ñ\Ê\ñ\Û\Ý\Z¯\"\Å\\\î¡6¢SŸ\0ü\'%‰6M6\nTª$ø\ò±à ¤wS*pƒ€N{`\ÙQy\é\Î\îq+Y\ÍxhC{Â§’\åS\ô&\î/—\ÝS¨Z#‚‚\ò\Ð\Ô\Z;&‚€\Í\Û,C\á±(eŠ<{&\Þ²{À\å \ÛeN¯ü{údŽ\n‘\Ê:+:)”\÷\ÅJm\ÍhUN¦\Ì-¢\Ë\é*^”\Ó|£*o…\Ê\ç(@!›´\Í\Êsƒºs‹‰\':\ðj€›ú\Äq¥8ùùRâŸ©®k À)\Þj_#1ß¢µ2\ö\ÛquQ¤9®v…EÆ¨\r‚p\à¬>þÐ™fý\×#  (Ly\è@‰\È\ÊJ%Tª\Z‰/$¨Î»¼\ÎùR$\Õ\ìGSªŽ\å5\îs´Rm\Æ\åTm`Ó¨4ˆXgkÃ°\ÏS“\ò£1¸Z`´6Z‘UPDl$ƒµR?\Åj›\ò°\ÐY\÷M_´&™²\ä¡Ê‰8µ6¨;„2)F §\Ö&\Í\n\ÝZ\àvN›XD£\ï– ù\óT`\Ôo\ðO\ò0Ç­\î€U*^\Z\Æú¹\öO,ªùl\ÐD¯Ã«·\Ãs/d\ã.Ê‰\ÌtH­	\öNv–“<,#EJU\'}I¤R{ˆˆZ\Ü×’F\æV\rú\é“î€ŽS \ÓlP\\\ä2\0„‰^#–·û/\ËQ(ü\ä\Ñ6„Ö¶\ò‹Y\'o\Âî«ŸQÿ\05C\õ\î\Ä\ß>.“N\Íi*µ`\rceŽ©\á\áƒ©Û¯\Ãi\Ôn²ZCHœ\ÒÚ•	\ä\È\è	\É\÷„}Wa,1\Ùa\Z)¸¶}mÿ\0\ê¬\ÒÇSƒ\\¯Ãˆ¨\Ù\Ù\Èµ\æL±\×É†!E\ä TD\ÎM\Ø\æ]“€“4\Æ\×î›³‘\Ù‘\åV>¦\÷q+ú¬ÿ\0Ö¨=­¨\ç»\ö’\ÓþÖª,¡p;ÀX\×k¨g\Úÿ\0Ç§üS\ÉsŠ…n \"½\n«‹›\áSb$\ÈT0EŽ«P—€6X\ÆK\õÉ°UjI\Ò	……\Äx\0À\õ,>:\\YWŠ\÷L\'d&¸€@L\Z…Š`\óB \ÉM6Í‘7	û„E\Å\Âg(lmi\Ý\\\Ø\'€ÀIp\n¾.Å´\Ç\ÉEÎ’JÃ€K>\Z˜¥X\Ç\ïŸÉ¥\÷X“5O\Ùa\Ìa}¿UW\ç²\ÍFÃ„5\0Ö§\âJ5\ÚjxbI…_P‡\Ó,£uT!\Z»˜\Ð\×\ÜdË‘ ™\ê\n‘kªG°Oh 91®\ÔDpœ.rf\Å&\ÖU6A®;B”ƒ©=\ÑLŽ•LSD†Q\ï¨|\Äü\"sZV\Z¡k\Í\äB\"h\Õþa8—\ÝbæŸ€°\íœ+²\0‰œ(@—l!\nli\Ôn\ä\\¼Bú­h°¹*›\Ãq\0\Ýr«j<‰Wº\Êcv²¦6\0ªu6ºkÉ†\ã\å0\Åaü•qù„\Ï\ã¯I<*Œ\Z\Ý.\ëCO\ï\n?-IY\0ù²‰\"^7\Ø*\æ4[„\\O*™>C%;\ô¹Do\ò¹	\å\\\Êo©5€\Òx\'\÷X\0\Ê`\nÄ½Â³†žÀ\Õi¢]¢\ê \0‚\rˆ\é.*•\Z\\S±„¸|¦þ«L[IE­}W\ËW†À\×.=\Ðl \Ú`	D\0@T‰$[”7L7\ÜL7Û”\ÛV*»¼û\r•\çWýB‚¡!\Â\"w6@	¼¬N\ÌFÉŽ&O„\óùH‹Ÿ”l‰dD‹ÀMÿ\0d\×¶.J­\é§\ðV)\ÓTý–\Ú%Ú›!ÊJU™ ‹\r“t>t8\È\åH…\ÉUZ,J\ï¨Êº¸ @S/)®ŠŒ\âS›y“ºxtÀ•L–\08D™9²h˜\Õ\ÙS\Ü(o	ž±‡‘\ãt\Ð\ï<ªÿ\0©\öTD¸LÊ®f¡Ê‰%$¡¨È›!½\Ü6UÁ-fû\"¨]•<\'À§¸\Ý;r´‚M¤”\à\â\ï\ò7€\ç	U\Üi\É\à¬CI{œd.G\Êü6C\êX\Ä-^\ß4´ŽE”˜Ã‡p‹9\n=\×ÿ\Ù','CS','2022-01-01');
/*!40000 ALTER TABLE `student` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `user`
--

DROP TABLE IF EXISTS `user`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `user` (
  `uid` int NOT NULL AUTO_INCREMENT,
  `fname` varchar(50) NOT NULL,
  `lname` varchar(50) NOT NULL,
  `email` varchar(100) NOT NULL,
  `password` varchar(255) NOT NULL,
  PRIMARY KEY (`uid`),
  UNIQUE KEY `email` (`email`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `user`
--

LOCK TABLES `user` WRITE;
/*!40000 ALTER TABLE `user` DISABLE KEYS */;
INSERT INTO `user` VALUES (1,'Madiba','Hudson-Quansah','madmin@gmail.com','1411241789187772614611123143241611482201152118099233'),(2,'Madiba','Hudson-Quansah','mhquansah@gmail.com','1411241789187772614611123143241611482201152118099233'),(3,'Madiba','Hudson-Quansah','mstu@gmail.com','1411241789187772614611123143241611482201152118099233'),(4,'Madiba','Hudson-Quansah','mfac@gmail.com','1411241789187772614611123143241611482201152118099233');
/*!40000 ALTER TABLE `user` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping routines for database 'records'
--
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2024-12-02 14:04:06
