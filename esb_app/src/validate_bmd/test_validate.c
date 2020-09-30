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
#include "bmd_validate.c"


int main(){
   char * file="bmd.xml";
   int x=validate_bmd(file);
   return 0;


}
