//*****************************************************************************
//*             function : compute_flows function                             *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/25/2018                                      *
//*                                                                           *
//*****************************************************************************
#include "header.h"
#include "prototypes.h"
//
// The function computes the flow rates when the final heads are provided
//
void compute_flows(array <int> &node_table, vector<Real> &lengths,
                   vector<Real> &diameters, vector<Real> &hw_coeffs,
				   vector<Real> &external_flows, vector<Real> &final_heads, 
				   vector<Real> &flow_rates,vector <Real> &frictn_ress,
				   int num_pipes, int num_nodes,int reservoir_node, 
				   Real reservoir_head,bool debug)
{
 int pipe, start, end;
 Real a=0.54, head_diff;
//                     Parameters
// start:     For a given pipe,the node from which water flow start from
// end:       For a given pipe,the node from which water flow flow to
// head_diff: Difference between final heads of the pipes
// frictn_ress:Stores friction resistance to flow in pipes
 if (debug){user_trace( 1, "compute_flows");}	
  
 for( pipe=1; pipe<=num_pipes; pipe++)
  {
   start = node_table(pipe,1);
   end = node_table(pipe,2);
   if( final_heads(start) >= final_heads(end))
     { 
      head_diff= final_heads(start)-final_heads(end);
      flow_rates(pipe)=  pow( ((head_diff)/frictn_ress(pipe)), a);
	 }
   else 
	 { 
       head_diff=final_heads(end)-final_heads(start);
       flow_rates(pipe)= -pow( ((head_diff)/frictn_ress(pipe)), a);
	 }
  }
 
 if (debug){ for(pipe=1;pipe<=num_pipes;pipe++) cout<< flow_rates(pipe)<< endl;}
 
 if (debug){user_trace( 1, "compute_flows");}
 
return;
} 
 