CREATE DATABASE  IF NOT EXISTS `warehouse_db` /*!40100 DEFAULT CHARACTER SET utf8 */ /*!80016 DEFAULT ENCRYPTION='N' */;
USE `warehouse_db`;
-- MySQL dump 10.13  Distrib 8.0.18, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: warehouse_db
-- ------------------------------------------------------
-- Server version	8.0.18

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
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
  `AdminID` int(11) NOT NULL AUTO_INCREMENT,
  `AdminWarehouse` int(11) NOT NULL,
  `AdminName` varchar(20) NOT NULL,
  `AdminAccount` varchar(20) NOT NULL,
  `AdminPassWord` varchar(20) NOT NULL,
  PRIMARY KEY (`AdminID`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `admin`
--

LOCK TABLES `admin` WRITE;
/*!40000 ALTER TABLE `admin` DISABLE KEYS */;
INSERT INTO `admin` VALUES (1,1,'tony','tloinny','1100111000'),(2,1,'alice','3092582008','1100111000'),(3,1,'seth','1448165494','1100111000'),(4,1,'smith','723369999','1100111000'),(5,1,'alison','562465535','1100111000');
/*!40000 ALTER TABLE `admin` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `entry_log_1`
--

DROP TABLE IF EXISTS `entry_log_1`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `entry_log_1` (
  `EntryLogID` int(11) NOT NULL AUTO_INCREMENT,
  `EntryLogTimeStamp` timestamp(6) NOT NULL,
  `EntryLogSKU` int(11) NOT NULL,
  `EntryLogNum` int(11) NOT NULL,
  `EntryLogComment` varchar(140) DEFAULT NULL,
  PRIMARY KEY (`EntryLogID`)
) ENGINE=InnoDB AUTO_INCREMENT=25 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `entry_log_1`
--

LOCK TABLES `entry_log_1` WRITE;
/*!40000 ALTER TABLE `entry_log_1` DISABLE KEYS */;
INSERT INTO `entry_log_1` VALUES (16,'2019-12-14 12:55:07.000000',1912140001,1,''),(17,'2019-12-14 12:55:42.000000',1912140001,1,''),(18,'2019-12-14 12:55:43.000000',1912140001,1,''),(19,'2019-12-14 12:55:44.000000',1912140001,1,''),(20,'2019-12-14 12:55:46.000000',1912140001,1,''),(21,'2019-12-14 13:02:06.000000',1912140001,10,'test2'),(22,'2019-12-14 13:02:31.000000',1912140001,10,'test2'),(23,'2019-12-14 13:02:33.000000',1912140001,10,'test2'),(24,'2019-12-14 13:59:06.000000',1912140001,1000,'entry test');
/*!40000 ALTER TABLE `entry_log_1` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `owner`
--

DROP TABLE IF EXISTS `owner`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `owner` (
  `OwnerID` int(11) NOT NULL,
  `OwnerName` varchar(20) NOT NULL,
  `OwnerAccount` varchar(20) NOT NULL,
  `OwnerPassword` varchar(20) NOT NULL,
  PRIMARY KEY (`OwnerID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `owner`
--

LOCK TABLES `owner` WRITE;
/*!40000 ALTER TABLE `owner` DISABLE KEYS */;
INSERT INTO `owner` VALUES (1,'Sam','Sam','1100111000'),(2,'tloinny','423870200','1100111000'),(3,'tloinny','240322713','1100111000');
/*!40000 ALTER TABLE `owner` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `removal_log_1`
--

DROP TABLE IF EXISTS `removal_log_1`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `removal_log_1` (
  `RemovalLogID` int(11) NOT NULL AUTO_INCREMENT,
  `RemovalLogTimeStamp` timestamp NOT NULL,
  `RemovalLogSKU` int(11) NOT NULL,
  `RemovalLogNum` int(11) NOT NULL,
  `RemovalLogComment` varchar(140) DEFAULT NULL,
  PRIMARY KEY (`RemovalLogID`)
) ENGINE=InnoDB AUTO_INCREMENT=21 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `removal_log_1`
--

LOCK TABLES `removal_log_1` WRITE;
/*!40000 ALTER TABLE `removal_log_1` DISABLE KEYS */;
INSERT INTO `removal_log_1` VALUES (3,'2019-12-14 13:09:00',1912140001,100,'remove test'),(4,'2019-12-14 13:16:19',1912140001,31,''),(5,'2019-12-14 13:16:25',1912140001,30,''),(6,'2019-12-14 13:16:39',1912140001,29,''),(7,'2019-12-14 13:17:41',1912140001,1,''),(8,'2019-12-14 13:18:54',1912140001,1,''),(9,'2019-12-14 13:19:47',1912140001,1,''),(10,'2019-12-14 13:22:12',1912140001,1,''),(11,'2019-12-14 13:22:51',1912140001,10,''),(12,'2019-12-14 13:23:22',1912140001,1,''),(13,'2019-12-14 13:24:36',1912140001,1,''),(14,'2019-12-14 13:25:51',1912140001,1,''),(15,'2019-12-14 13:26:28',1912140001,1,''),(16,'2019-12-14 13:28:58',1912140001,1,''),(17,'2019-12-14 13:31:05',1912140001,1,''),(18,'2019-12-14 13:55:42',1912140001,1,''),(19,'2019-12-14 13:57:12',1912140001,2,'remove test'),(20,'2019-12-14 13:59:23',1912140001,900,'remove test2');
/*!40000 ALTER TABLE `removal_log_1` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `sku_map_1`
--

DROP TABLE IF EXISTS `sku_map_1`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `sku_map_1` (
  `MapSKU` int(11) NOT NULL,
  `MapCargoName` varchar(20) NOT NULL,
  `Belong` int(11) NOT NULL,
  PRIMARY KEY (`MapSKU`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `sku_map_1`
--

LOCK TABLES `sku_map_1` WRITE;
/*!40000 ALTER TABLE `sku_map_1` DISABLE KEYS */;
INSERT INTO `sku_map_1` VALUES (1912140001,'brushless dc motor',1),(1912140002,'brushed dc motor',1),(1912140003,'42 stepper motor',1);
/*!40000 ALTER TABLE `sku_map_1` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `warehouse`
--

DROP TABLE IF EXISTS `warehouse`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `warehouse` (
  `WarehouseID` int(11) NOT NULL,
  `WarehouseOwner` int(11) NOT NULL,
  `WarehouseName` varchar(20) NOT NULL,
  `WarehouseMapped` int(11) NOT NULL,
  PRIMARY KEY (`WarehouseID`),
  CONSTRAINT `warehouse_chk_1` CHECK (((`WarehouseMapped` = 0) or (`WarehouseMapped` = 1)))
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `warehouse`
--

LOCK TABLES `warehouse` WRITE;
/*!40000 ALTER TABLE `warehouse` DISABLE KEYS */;
INSERT INTO `warehouse` VALUES (1,1,'no.1',1);
/*!40000 ALTER TABLE `warehouse` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `warehouse_detail_1`
--

DROP TABLE IF EXISTS `warehouse_detail_1`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `warehouse_detail_1` (
  `DetailSKU` int(11) NOT NULL,
  `DetailStocks` int(11) NOT NULL,
  PRIMARY KEY (`DetailSKU`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `warehouse_detail_1`
--

LOCK TABLES `warehouse_detail_1` WRITE;
/*!40000 ALTER TABLE `warehouse_detail_1` DISABLE KEYS */;
INSERT INTO `warehouse_detail_1` VALUES (1912140001,127),(1912140002,50),(1912140003,15);
/*!40000 ALTER TABLE `warehouse_detail_1` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2019-12-27 13:42:40
