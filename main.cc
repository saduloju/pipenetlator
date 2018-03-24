//*****************************************************************************
//*             project: Steady State Pressurized Pipe flow Analysis          *
//*             function : main_function                                      *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/25/2018                                      *
//*                                                                           *
//*****************************************************************************
#include "system.h"
#include "prototypes.h"
//
// The main function calls all the functions  to  read input data,process the 
// inputs, generate necessary error messages  and provide and a nonlinear 
// solution for water pipe flow analysis
//
int main()
{
const int max_nodes = 2000, max_pipes = 4000, max_iter=300, min_iter=2;; 
const Real max_tol=10, min_tol=0.0001; 
int i,j, counte=0, num_pipes, num_nodes, reservoir_node, iter, new_read; 
Real reservoir_head, tol; 
bool debug = false, resolve = false,output_reslt = false,iter_limit = false;
bool data_fail = false ;
array <int> node_table;
vector<Real> lengths, diameters, external_flows,initial_heads,final_heads;
vector<Real> hw_coeffs, residuals, flow_rates;
string title;

init_scan ();

new_read = true;
do
 {	 
   if( new_read ) readsc ();
   if ( matchs( "Project" , 3))
      {
		counte =++counte;	
		read_project(node_table, lengths, diameters, hw_coeffs, external_flows,
		             initial_heads, counte,tol,iter, title, debug);
	    continue;
	  }
   if ( matchs( "number" ,3))
      {
		process_number( node_table, lengths, diameters, hw_coeffs, external_flows, 
					   initial_heads, max_pipes, max_nodes,num_pipes, num_nodes, 
					   resolve,debug);
		create_vectors(final_heads,residuals,flow_rates, num_nodes,num_pipes,debug);
        continue;		
	  }
   if ( matchs( "reservoir" ,5))
      {
		process_reservoir(reservoir_node, reservoir_head, resolve, debug);
        continue;		
	  }
   if ( matchs( "pipe" , 4))
      {
	   process_propties(node_table, lengths, diameters, hw_coeffs, num_pipes, 
						 num_nodes, resolve, debug);
	   new_read = false; continue;
	  }	 
   if ( matchs( "external" , 4))
      {
	   process_external( external_flows, num_nodes,resolve, debug);
	   new_read = false; continue;
	  }
   if ( matchs( "initial" , 4))
      {
	   process_initial(initial_heads, num_nodes, resolve, debug);
	   new_read = false; continue;
	  }
   if ( matchs( "convergence", 4))
      {
	   process_convergence(tol, min_tol, max_tol, resolve, debug);
	   new_read = true; continue;
	  }
   if ( matchs( "maximum", 4))
      {
	   process_iterations(iter, min_iter, max_iter,resolve, debug);
	   new_read = true; continue;
	  }
   if ( matchs( "solve", 4))
      {
	   process_solve(node_table, lengths, diameters, hw_coeffs,external_flows,
                     initial_heads,final_heads,residuals, flow_rates,num_pipes,
					 num_nodes, reservoir_node, reservoir_head,tol, iter,title,
					 iter_limit,data_fail, resolve,output_reslt, debug);
       resolve = false;	new_read = true; continue;
	  }
   if ( matchs( "output", 4))
      {
	   process_output(node_table, lengths, diameters, hw_coeffs,external_flows,
                      initial_heads,final_heads,flow_rates,residuals,num_pipes,
					  num_nodes, reservoir_node, reservoir_head,tol, iter, 
					  title,iter_limit,data_fail,resolve,output_reslt, debug);
	   iter_limit=false; new_read = true;continue;
	  }
   if ( matchs( "debug" , 5))
      {
	   process_debug(debug);
	   new_read = true; continue;
	  }
   else if ( matchs ( "stop", 4 )) 
      {
        error_message (1);exit(0);
      }
   else
     {
       while (! endcrd ())
       {
	    error_message(2);istrue();continue;	
       }
       new_read = true;
     }
 } while (true);
 
 vectors_free(final_heads,residuals,flow_rates,debug);
 return(0);
 }
 