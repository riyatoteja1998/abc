#include <stdio.h>

#include "xml2json.c"
/* 
takes in xml file and uses libxml to convert it in a tree like data structure and then prints in json format using libxml.
how to run:-
gcc -Wall -I/usr/include/libxml2 -o xml2json xml2json.c -lxml2*/
 
int main(){
  char* input="bmd.xml";
  char * output="bmd2.json";
  printf("%s generated successfully", output);
  xml_to_json(input, output);
  return 0;


}
