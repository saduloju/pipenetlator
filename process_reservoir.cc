
#include "system.h"
#include "prototypes.h"


void process_reservoir()
{
user_trace( 1, "process_reservoir");
typedef double Real;
int node_num; 
double head_value;	
while( ! endcrd ())
 {
   matchs( "at", 2 );
   if( matchs( "node", 4))
	 {
	  if( ! integr(node_num)){ error_message(4); continue;}
	 }
   else if( matchs( "head", 4))
     {
	  if( ! numd(head_value)){ error_message(5); continue;}	
     cout <<" checking double head value"	<<head_value << endl;
     }
   else 
     {
	   error_message(6);
	   istrue();
	   continue;
	 }
	 
 }	
user_trace( 2, "process_reservoir"); 
return;
}
