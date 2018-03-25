//*****************************************************************************
//*             function : process_output function                            *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/25/2018                                      *
//*                                                                           *
//*****************************************************************************
#include "header.h"
#include "prototypes.h"
//
//This function make 2 calls when it sees output command
//it  calls the function to print input data
//or/and calls function print the results
//
void process_output(array <int> &node_table, vector<Real> &lengths,
           vector<Real> &diameters,vector<Real> &hw_coeffs,
		   vector<Real> &external_flows, vector<Real> &initial_heads, 
		   vector<Real> &final_heads, vector<Real> &flow_rates, 
		   vector<Real> &residuals,int &num_pipes,int &num_nodes,
		   int &reservoir_node, Real &reservoir_head,Real &tol, int iter, 
		   Real &maxr, string &title, bool &iter_limit,bool &data_fail,
		   bool &resolve, bool &output_reslt, bool &debug)
{
int first;	
	
 if (debug){user_trace( 1, "process_output");}
//                     Functions
// process_output_data: print input data
// process_output_results: print the results
//
 
 first= true;
 while(! endcrd() )
  {
   if( matchs( "data", 4))
     {  
      process_output_data(node_table, lengths, diameters, hw_coeffs,
					external_flows, initial_heads,
					num_pipes, num_nodes,reservoir_node, reservoir_head, 
					tol,iter, title,debug);					
     }
   else if( matchs( "results", 4))
     {   
	  if(iter_limit){ user_mess(1); return;}	
	  else if(data_fail) { user_mess(10); return;}
	  if(!output_reslt){ user_mess(9); return;}
	  if(first)
	    { process_output_results(final_heads,flow_rates, residuals, maxr, num_nodes,
                                num_pipes, title, resolve,debug);
	    }
	  }
   else
      {
	   error_message(54);
	   istrue();
	   continue;	
	  }
  }

 if (debug ==true){user_trace( 2, "process_output");}
 return;	
}