
//*****************************************************************************
//*             CEE 691                                                       *
//*             project: Input Translator for PipeNetwork Simulator           *
//*             function : process_solve function                             *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/9/2018                                       *
//*                                                                           *
//*****************************************************************************
#include "system.h"
#include "prototypes.h"

void compute_flows(array <int> &node_table, vector<Real> &lengths,
                   vector<Real> &diameters, vector<Real> &hw_coeffs,
				   vector<Real> &external_flows, vector<Real> &final_heads, 
				   vector<Real> &flow_rates,vector <Real> &frictn_ress,int &num_pipes, int &num_nodes,
				   int &reservoir_node, Real &reservoir_head,Real &maxr, string &title, bool &debug)
{
 int pipe, start, end;
 double a=0.54;
 
 if (debug){user_trace( 1, "compute_flows");}	
  
 for( pipe=1; pipe<=num_pipes; pipe++)
  {
   start = node_table(pipe,1);
   end = node_table(pipe,2);
   if( final_heads(start) >= final_heads(end))
     { 
      flow_rates(pipe)=  pow( ((final_heads(start)-final_heads(end))/frictn_ress(pipe)), a);
	 }
   else 
	 { 
       flow_rates(pipe)= -pow( ((final_heads(end)-final_heads(start))/frictn_ress(pipe)), a);
	 }
  }
 
 if (debug){ for(pipe=1;pipe<=num_pipes;pipe++) cout<< flow_rates(pipe)<< endl;}
 
 if (debug){user_trace( 1, "compute_flows");}
 
return;
} 
 