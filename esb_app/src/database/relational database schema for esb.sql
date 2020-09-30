create table routes
	(route_id           integer not null,
	 sender_id		varchar(45) not null, 
	 destination_id           varchar(45) not null,
	 message_type		varchar(45), 
	 is_active   bit,       
	 primary key (route_id)
	);
create table transform_config
	(id           integer not null,
	 route_id           integer not null,
	 config_key		varchar(45) , 
	 config_value           text ,
	 primary key (id),
	foreign key (route_id) references routes
		on delete cascade
	);
create table esb_request
	(id           integer not null,
	 sender_id		varchar(45) not null, 
	 destination_id           varchar(45) not null,
	 message_type		varchar(45) ,
	 reference_id		varchar(45) ,
	 message_id		varchar(45) , 
	 received_on           timestamp,
	 data_location           text,
	 status		varchar(20) ,
	 status_details  	text ,
	 primary key (id)
	);

create table transport_config
	(id           integer not null,
	 route_id           integer not null,
	 config_key		varchar(45) , 
	 config_value           text ,
	 primary key (id),
	 foreign key (route_id) references routes
		on delete cascade
	);

