CREATE TABLE routes
(
	route_id  int NOT NULL AUTO_INCREMENT,
	sender  varchar(45) NOT NULL, 
	destination  varchar(45) NOT NULL,
	message_type  varchar(45) NOT NULL, 
	is_active  bit(1) NOT NULL,
	PRIMARY KEY (`route_id`),
        UNIQUE INDEX `UK_sender_dest_msg_type` (`message_type`,`destination`,`sender`)
);
CREATE TABLE transform_config
(
	 id  int NOT NULL AUTO_INCREMENT,
	 route_id  int NOT NULL,
	 config_key  varchar(45) NOT NULL, 
	 config_value  text,
	 PRIMARY KEY (id),
	 UNIQUE INDEX `UK_route_config` (`route_id`,`config_key`),
         INDEX `route_idx` (`route_id`),
        CONSTRAINT `route`
        FOREIGN KEY (`route_id`) 
        REFERENCES `routes` (`route_id`)
);
CREATE TABLE transport_config
(
	 id  INT NOT NULL AUTO_INCREMENT,
	 route_id  INT NULL,
	 config_key  varchar(45) NULL, 
	 config_value  TEXT NULL,
	 PRIMARY KEY (id),
	 UNIQUE INDEX `UK_route_config` (`config_key`,`route_id`),
         INDEX `route_idx` (`route_id`),
         CONSTRAINT `route_id` 
         FOREIGN KEY (`route_id`)
         REFERENCES `routes` (`route_id`)
);
CREATE TABLE esb_request
(
	 id INT NOT NULL AUTO_INCREMENT,
	 sender_id  varchar(45) NOT NULL, 
	 dest_id  varchar(45) NOT NULL,
	 message_type  varchar(45) NOT NULL,
	 reference_id  varchar(45) NOT NULL,
	 message_id  varchar(45) NOT NULL , 
	 received_on  timestamp NOT NULL,
	 data_location TEXT NULL,
	 status VARCHAR(20) NOT NULL,
	 status_details TEXT NULL ,
	 PRIMARY KEY(id),
	 UNIQUE INDEX `UK_sender_message` (`sender_id`, `message_id`)
);
