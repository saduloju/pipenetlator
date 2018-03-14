//*****************************************************************************
//*             CEE 691(Steady State Pressurized Pipe flow Analysis)          *
//*             project: Input Translator for PipeNetwork Simulator           *
//*             function : main_function                                      *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/9/2018                                       *
//*                                                                           *
//*****************************************************************************
#include "system.h"
#include "prototypes.h"
//
//The main function calls all the functions  to  process the inputs
//Called functions read input data and generate necessary error messages 
//
//
int main()
{
const int max_nodes = 2000, max_pipes = 4000; 
const Real max_tol=10, min_tol=0.0001;
const int max_iter=30, min_iter=2; 
int num_pipes, num_nodes, reservoir_node, iter; 
Real reservoir_head, tol; 
int i, j, counte=0;
int new_read;
bool debug = false;
array <int> node_table;
vector<Real> lengths;
vector<Real> diameters;
vector<Real> external_flows;
vector<Real> initial_heads;
vector<Real> hw_coeffs;
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
					   initial_heads, max_pipes, max_nodes,num_pipes, num_nodes, debug);
        continue;		
	  }
   if ( matchs( "reservoir" ,5))
      {
		process_reservoir(reservoir_node, reservoir_head, debug);
        continue;		
	  }
   if ( matchs( "pipe" , 4))
      {
	   process_propties(node_table, lengths, diameters, hw_coeffs, num_pipes, 
						 num_nodes, debug);
	   new_read = false; continue;
	  }	 
   if ( matchs( "external" , 4))
      {
	   process_external( external_flows, num_nodes, debug);
	   new_read = false; continue;
	  }
   if ( matchs( "initial" , 4))
      {
	   process_initial(initial_heads, num_nodes, debug);
	   new_read = false; continue;
	  }
   if ( matchs( "convergence", 4))
      {
	   process_convergence(tol, min_tol, max_tol, debug);
	   new_read = true; continue;
	  }
   if ( matchs( "maximum", 4))
      {
	   process_iterations(iter, min_iter, max_iter, debug);
	   new_read = true; continue;
	  }
   if ( matchs( "solve", 4))
      {
	   process_solve(debug);
	   new_read = true; continue;
	  }
   if ( matchs( "output", 4))
      {
	   process_output(node_table, lengths, diameters, hw_coeffs,external_flows, initial_heads,
                      max_pipes, max_nodes,num_pipes, num_nodes, reservoir_node, reservoir_head,
					  tol, iter, title, debug);
	   new_read = true;continue;
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
 return(0);
 }
 