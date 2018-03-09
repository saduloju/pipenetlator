
#include "system.h"
#include "prototypes.h"
void process_number(array <int> &node_table, vector<Real> &lengths,
                    vector<Real> &diameters, vector<Real> &hw_coeffs,
					vector<Real> &external_flows, vector<Real> &initial_heads, 
					const int max_pipes, const int max_nodes,
					int &num_pipes, int &num_nodes, bool &debug)
{
if (debug ==true){user_trace( 1, "process_number");}
int i,j;
//Real head_value;	
while( ! endcrd ())
 {
   matchs( "of", 2 );
   if( matchs( "nodes", 4))
	 {
	  if( ! integr(num_nodes)){ error_message(3); continue;}
	  if( num_nodes > max_nodes){ error_message(4); num_nodes = max_nodes; continue;}
	  if( num_nodes < 0){ error_message(5); istrue(); return;}
	 }
   else if( matchs( "pipes", 4))
     {
	  if( ! integr(num_pipes)){ error_message(20); continue;}
	  if( num_pipes > max_pipes){ error_message(21);num_pipes= max_pipes; continue;}
	  if( num_pipes < 0){ error_message(22); istrue(); return;}	  
     }
   else 
     {
	   error_message(6);
	   istrue();
	   continue;
	 }
	 
 }
 
 
node_table.create(1,num_pipes,1, 2);
lengths.create(1, num_pipes);
diameters.create(1, num_pipes);
hw_coeffs.create(1, num_pipes);
external_flows.create(1, num_nodes);
initial_heads.create(1, num_nodes);

for( i=1; i<=num_pipes; i++)
   {for(j=1; j<=2 ; j++){node_table(i,j)=0;}}

for( i=1; i<=num_pipes; i++)
   {
     lengths(i)=0;
     diameters(i)=0;
     hw_coeffs(i)=0;
   }
 
if (debug ==true){user_trace( 2, "process_number");}
return;
}


