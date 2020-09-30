#include <stdio.h>
#include <mysql.h>

void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);        
}

int main(int argc, char **argv)
{
    char *server = "localhost";
    char *user = "root";
    char *password ="Devika@1998";
    char *database = "DB";

  MYSQL *con = mysql_init(NULL);
  
  if (con == NULL) 
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      exit(1);
  }  

  if (mysql_real_connect(con, server, user, password, 
          database, 0, NULL, 0) == NULL) 
  {
      finish_with_error(con);
  }    
 // 
  //if (mysql_query(con, "DROP TABLE IF EXISTS routes")) {
     // finish_with_error(con);
 // }
  
  //if (mysql_query(con, "CREATE TABLE transport_config(id,route_id,config_key,config_value)")) {      
    // finish_with_error(con);
 // }
  if (mysql_query(con, "INSERT INTO transport_config VALUES(1,12,'abb','tees')")) {
     finish_with_error(con);
  }
   if (mysql_query(con, "INSERT INTO transport_config VALUES(2,3,'htg','samp')")) {
     finish_with_error(con);
  }
   if (mysql_query(con, "INSERT INTO transport_config VALUES(3,2,'uyr','mitt')")) {
     finish_with_error(con);
  }
  mysql_close(con);
  exit(0);
}
