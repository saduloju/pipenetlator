
#include "system.h"
#include "prototypes.h"

void process_reservoir(bool &debug)
{
if (debug ==true){user_trace( 1, "process_reservoir");}	

int node_num; 
Real head_value;	
while( ! endcrd ())
 {
   matchs( "at", 2 );
   if( matchs( "node", 4))
	 {
	  if( ! integr(node_num)){ error_message(7); continue;}
	 }
   else if( matchs( "head", 4))
     {
	  if( ! numd(head_value)){ error_message(30); continue;}	

   if(debug ==true)
     {
	  cout <<" checking head value"	<<head_value << endl;}
     }
   else 
     {
	   error_message(6);
	   istrue();
	   continue;
	 }
	 
 }
 
if (debug ==true){user_trace( 2, "process_reservoir");}	

return;
}
