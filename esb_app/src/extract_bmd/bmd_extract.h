#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <string.h>
 
/* 
parses xml file in tree form using libxml and extracts envelope fields and payload from it.
how to run:-
gcc -Wall -I/usr/include/libxml2 -o test bmd_extract.c -lxml2*/
 
struct map{
  char*  key;
  char* value;
};

int is_leaf(xmlNode * node)
{
  xmlNode * child = node->children;
  while(child)
  {
    if(child->type == XML_ELEMENT_NODE) return 0;
 
    child = child->next;
  }
 
  return 1;
}
 

 


