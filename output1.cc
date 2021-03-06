//*****************************************************************************
//*             CEE 691                                                       *
//*             project: Input Translator for PipeNetwork Simulator           *
//*             function : process_output function                            *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/9/2018                                       *
//*                                                                           *
//*****************************************************************************
#include "system.h"
#include "prototypes.h"
//
//This function make 2 calls when it sees output command
//it  calls the "process_output_data" function to print input
//or/and calls process_output_results to print the results
//
void process_output(array <int> &node_table, vector<Real> &lengths,vector<Real> &diameters,
                    vector<Real> &hw_coeffs,vector<Real> &external_flows, vector<Real> &initial_heads, 
					vector<Real> &final_heads, vector<Real> &flow_rates, vector<Real> &residuals,
					int &num_pipes,int &num_nodes,int &reservoir_node, Real &reservoir_head,
					Real &tol, int iter, string &title,bool &iter_limit,bool &link_fail,
					bool &resolve, bool &output_reslt, bool &debug)
{
 if (debug){user_trace( 1, "process_output");}
 while( ! endcrd() )
  {
   if( matchs( "data", 4))
     {  
      process_output_data(node_table, lengths, diameters, hw_coeffs,
					external_flows, initial_heads,
					num_pipes, num_nodes,reservoir_node, reservoir_head, 
					tol,iter, title,debug);
      continue;					
     }
   else if( matchs( "results", 4))
     {
	  if(output_reslt)
	    {
	     if(iter_limit){ user_messages(1); return;}	
	     else if(link_fail) { user_messages(3); return;}
	     else 
	     {
		   process_output_results(final_heads,flow_rates, residuals, num_nodes,
                                num_pipes, resolve,debug);
		  continue;
		 }
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