//*****************************************************************************
//*             CEE 691                                                       *
//*             project: Input Translator for PipeNetwork Simulator           *
//*             function : process reservoir function                         *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/9/2018                                       *
//*                                                                           *
//*****************************************************************************

#include "system.h"
#include "prototypes.h"
//
// reads the reservoir nodes and heads
//
void process_reservoir(int &reservoir_node, Real &reservoir_head, bool &debug)
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
	  if( node_num < 0){ error_message(40); continue;}
	 }
   else if( matchs( "head", 4))
     {
	  if( ! numd(head_value)){ error_message(30); continue;}
	  if( head_value < 0){ error_message(41); continue;}	  

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
reservoir_node = node_num;
reservoir_head = head_value;
if (debug ==true){user_trace( 2, "process_reservoir");}	

return;
}
