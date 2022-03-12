CREATE DATABASE
IF NOT EXISTS seteam15;

USE `seteam15`;

DROP TABLE IF EXISTS `Game`;

CREATE TABLE `Game` (
  `id_game` int NOT NULL AUTO_INCREMENT,
  `holding_cost` float NOT NULL,
  `backlog_cost` float NOT NULL,
  `session_length` int NOT NULL,
  `retailer_present` tinyint DEFAULT NULL,
  `wholesaler_present` tinyint DEFAULT NULL,
  PRIMARY KEY (`id_game`)
);

DROP TABLE IF EXISTS `Instructor`;

CREATE TABLE `Instructor` (
  `id_instructor` int NOT NULL AUTO_INCREMENT,
  `i_password` varchar(45) NOT NULL,
  `i_username` varchar(45) NOT NULL,
  PRIMARY KEY (`id_instructor`),
  UNIQUE KEY `i_username_UNIQUE` (`i_username`)
);

DROP TABLE IF EXISTS `Instructor_Controls_Games`;

CREATE TABLE `Instructor_Controls_Games` (
  `id_instructor` int NULL,
  `id_game` int NULL,
  FOREIGN KEY (`id_instructor`) REFERENCES Instructor(id_instructor),
  FOREIGN KEY (`id_game`) REFERENCES Game(id_game),
  UNIQUE KEY (`id_instructor`, `id_game`)
);

DROP TABLE IF EXISTS `Player`;

CREATE TABLE `Player` (
  `id_player` int NOT NULL AUTO_INCREMENT,
  `p_username` varchar(45) NOT NULL,
  `p_password` varchar(45) NULL,
  `id_game` int NULL,
  `p_role` varchar(45) NULL,
  FOREIGN KEY (`id_game`) REFERENCES Game(id_game),
  PRIMARY KEY (`id_player`),
  UNIQUE KEY `p_username_UNIQUE` (`p_username`)
);