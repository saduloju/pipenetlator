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
// This function performs Newton iteration to solve the Steady State Pressurized 
//Pipe flow Analysis
//
void process_solve(array <int> &node_table, vector<Real> &lengths,
                    vector<Real> &diameters, vector<Real> &hw_coeffs,
					vector<Real> &external_flows, vector<Real> &initial_heads, 
					vector<Real> &final_heads, vector<Real> &residuals,vector<Real> &flow_rates,
					int &num_pipes, int &num_nodes,int &reservoir_node, Real &reservoir_head,
					Real &tol, int &iter, string &title,bool &iter_limit, bool &link_fail,
					bool &resolve, bool &output_reslt, bool &debug)
{

Real maxr;
int i, kont;
vector <Real>frictn_ress;
frictn_ress.create(1,num_pipes);

if (debug){user_trace( 1, "process_solve");}	

output_reslt = resolve ;

if(resolve)
 {	
  for (i=1; i<=num_nodes; i++)residuals(i)=0;//////////////////////////////////////////////////////////////
  process_solve_data(node_table, lengths, diameters, hw_coeffs,external_flows, initial_heads,residuals,
                frictn_ress, num_pipes, num_nodes, reservoir_node, reservoir_head,
			    maxr, title, link_fail, debug);
  kont=1;
 //
 //obtain solution status
 //
  user_messages(7);
  solution_status( maxr,kont, debug);	  
	 	 
  do{
     if( kont > iter)
	   { 
         iter_limit = true;
         user_messages(4); 
         return;
	   }	  
     if(abs(maxr) >tol)
       { 
        process_solve_data(node_table, lengths, diameters, hw_coeffs,external_flows, initial_heads,residuals,
	                   frictn_ress,num_pipes, num_nodes, reservoir_node, reservoir_head,
			           maxr, title,link_fail, debug);
	    kont=++kont;
        solution_status( maxr,kont,debug);	
        continue;				
       }
     else 
	 break;
   
    }while (true);			
  //
  //obtain final heads at all nodes
  //
  for(i=1; i<=num_nodes; i++){ final_heads(i)=initial_heads(i);}
  //
  // compute  pipe flow rates
  //
  compute_flows(node_table, lengths, diameters, hw_coeffs,external_flows, final_heads,
	             flow_rates, frictn_ress,num_pipes, num_nodes, reservoir_node, reservoir_head,
			           maxr, title, debug);	
  user_messages(5);
 }
else
 {
  user_messages(3);
 }

user_messages(8);

if(debug){user_trace( 2, "process_solve");}
 
return; 
}