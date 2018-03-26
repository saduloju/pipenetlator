//*****************************************************************************
//*             function : process number function                            *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/9/2018                                       *
//*                                                                           *
//*****************************************************************************
#include "header.h"
#include "prototypes.h"
//
// read the number of nodes and pipes  and initializes the arrays of node table,
// external flows, initial heads,lengths, diameters and hw_coeffs
//
void process_number(array <int> &node_table, vector<Real> &lengths,
                    vector<Real> &diameters, vector<Real> &hw_coeffs,
					vector<Real> &external_flows, vector<Real> &initial_heads, 
					const int max_pipes, const int max_nodes,
					int &num_pipes, int &num_nodes,bool &resolve, bool debug)
{
if (debug){user_trace( 1, "process_number");}
int i,j;	
while( ! endcrd ())
 {
   matchs( "of", 2 );
   if( matchs( "nodes", 4))
	 {
	  if( ! integr(num_nodes)){ error_message(3);num_nodes=max_nodes;continue;}
	  if(num_nodes > max_nodes){error_message(4);num_nodes=max_nodes; continue;}
	  if( num_nodes < 0){ error_message(5); istrue(); return;}
	  external_flows.create(1, num_nodes);
      initial_heads.create(1, num_nodes);
      for( i=1; i<=num_nodes; i++)
         {
           external_flows(i)=0;
           initial_heads(i)=0;
         }
	 }
   else if( matchs( "pipes", 4))
     {
	  if( ! integr(num_pipes)){ error_message(20); continue;}
	  if( num_pipes > max_pipes){ error_message(21);num_pipes= max_pipes; continue;}
	  if( num_pipes < 0){ error_message(22); istrue(); return;}	 
      node_table.create(1,num_pipes,1, 2);
      lengths.create(1, num_pipes);
      diameters.create(1, num_pipes);
      hw_coeffs.create(1, num_pipes);
      for( i=1; i<=num_pipes; i++)
         {
           lengths(i)=0;
           diameters(i)=0;
           hw_coeffs(i)=0;
         }	  
     }
   else 
     {
	   error_message(6);
	   istrue();
	   continue;
	 }
	 
 }
 //
 //initialize the node table
 //
for( i=1; i<=num_pipes; i++)
   {for(j=1; j<=2 ; j++){node_table(i,j)=0;}}

resolve=true;
if (debug){user_trace( 2, "process_number");}

return;
}


