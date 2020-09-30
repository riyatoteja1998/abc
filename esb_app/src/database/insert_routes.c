#include<stdio.h>
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
  
  // if (mysql_query(con, "CREATE TABLE routes(Id route_id, varchar sender, varchar destination,varchar message_type,bit is_active)")) {      
   //   finish_with_error(con);
  //}
  
  if (mysql_query(con, "INSERT INTO routes VALUES(12,'756E-1D5B-4BC0-ACC4-4CEB66','F82F-4687-433D-AA23-1966330381FE','CreditReport',1)")) {
      finish_with_error(con);
  }

  
  if (mysql_query(con, "INSERT INTO routes VALUES(13,'8790-CC4-4CEB78','89F42F-4687-433D-AA23-1966330381FE','BulkPurchase',1)")) {
     finish_with_error(con);
 }
  
  if (mysql_query(con, "INSERT INTO routes VALUES(15,'8567E2EAA-2D5B-8BC0-ACC4-4CEB669408DA','7896F87H-3567-BBA5-3265781FE','CreditReport',1)")) {
     finish_with_error(con);
  }

  mysql_close(con);
  exit(0);
}
