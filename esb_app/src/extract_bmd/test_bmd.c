#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <string.h>
#include "bmd_extract.h"
#include "bmd_extract.c"

/* 
parses xml file in tree form using libxml and extracts envelope fields and payload from it.
how to run:-
gcc -Wall -I/usr/include/libxml2 -o test bmd_extract.c -lxml2*/


int main(){
  
  char * filename="bmd.xml";
  char * fields[10];
  extract_bmd(filename, fields); 
    
  printf("MessageID = %s\n",fields[0]);
  printf("MessageType = %s\n",fields[1]);
  printf("Sender = %s\n",fields[2]);
  printf("Destination = %s\n",fields[3]);
  printf("CreationDateTime = %s\n",fields[4]);
  printf("Signature = %s\n",fields[5]);
  printf("ReferenceID = %s\n",fields[6]);
  printf("Payload = %s\n",fields[7]);
  printf("UserProperties = %s\n",fields[8]);
  exit (0);  
}
