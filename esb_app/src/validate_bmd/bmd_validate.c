/*
gcc -Wall -I/usr/include/libxml2  -o test  bmd_validate.c  `mysql_config --cflags --libs` -lxml2
The validation will be done mainly for the envelope part of the BMD.
1. The mandatory values (Sender, Destination, Message Type, etc.) must be present in the
received BMD.
2. For the received {Sender, Destination, Message Type}, there should be an active route
record present in the routes table (​ see here​ ).
3. For the selected route record, there should be corresponding records present in
transport_config and transform_config tables.
4. We will also check for some upper limit on the payload size. For example, the payload
larger than 5MB may not be allowed, or are allowed only for certain senders and message
types, etc
*/
#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <string.h>
#include <mysql.h>
#include "../extract_bmd/bmd_extract.c"
 

 
int validate_bmd (char * bmd){

  char * filename=bmd;
  char * fields[10];
  extract_bmd(filename, fields); 
  MYSQL *conn;

  MYSQL_ROW row;
	
  char *server = "localhost";
  char *user = "root";
  char *password = "riya"; /* set me first */
  char *database = "esb_db";
	
  conn = mysql_init(NULL);
	
  /* Connect to database */
  if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
	fprintf(stderr, "%s\n", mysql_error(conn));
	return 0;
  }
	
  
  
  char * MessageType=fields[1];
  char * Sender=fields[2];
  char * Destination=fields[3];
  

 
  char  query[1000]="SELECT route_id FROM routes where sender='";
  strcat(query,Sender);
  strcat(query,"' and destination='");
  strcat(query,Destination);
  strcat(query,"' and  message_type='");
  strcat(query,MessageType); 
  strcat(query,"' and is_active=1"); 
  //printf("%s", query);
  if (mysql_query(conn, query)) 
  {
     fprintf(stderr, "%s\n", mysql_error(conn));
     return 0;
  }
  
  MYSQL_RES *result = mysql_store_result(conn);
  
 
  int num_fields = mysql_num_fields(result);

  char query2[1000]="";
  char query3[1000]="";
  int k=-1; int p=-1; int q=-1;
  while ((row = mysql_fetch_row(result))) 
  {   int i,j;
      k++;
      for( i = 0; i < num_fields; i++) 
      {   
          
          printf("route id for the received Sender, Destination, Message Type : %s \n", row[i] ? row[i] : "NULL"); 
          strcat(query2,"SELECT id FROM transport_config where route_id='");
          strcat(query2,row[i]);
          strcat(query2,"'");
          strcat(query3,"SELECT id FROM transform_config where route_id='");
          strcat(query3,row[i]);
          strcat(query3,"'");

          if (mysql_query(conn, query2)) 
          {
            fprintf(stderr, "%s\n", mysql_error(conn));
            return 0;
          }
  
          MYSQL_RES *result2 = mysql_store_result(conn);
           
         
          if (mysql_query(conn, query3)) 
          {
            fprintf(stderr, "%s\n", mysql_error(conn));
            return 0;
          }
  
          MYSQL_RES *result3 = mysql_store_result(conn);
  
           

           while ((row = mysql_fetch_row(result2))) 
           {    p++;
                for( j = 0; j < mysql_num_fields(result2); j++) 
                {   
                    printf("transport_config id for this route id is : %s \n", row[j] ? row[j] : "NULL"); 
                }
           }
           while ((row = mysql_fetch_row(result3))) 
           {    q++;
                for( j = 0; j < mysql_num_fields(result3); j++) 
                {   
                    printf("transform_config id for this route id is : %s \n", row[j] ? row[j] : "NULL"); 
                }
           }


      } 

  }
  if (k==-1) 
  {
      printf( "For the received Sender, Destination, Message Type there are no  active route record present in the routes table \n");
      return 0;
  }
  if (p==-1) 
  {
     printf( "For this route id there are no record present in the transport_config table \n");
     return 0;
  }
  if (q==-1) 
  {
     printf( "For this route id there are no record present in the transform_config table \n");
     return 0;
  }
  mysql_free_result(result);
  mysql_close(conn);
  printf("validation part done\n");
  return 1;

  
}



/*

int main(){
   char * file="bmd.xml";
   int x=validate_bmd(file);
   return 0;


}
*/
