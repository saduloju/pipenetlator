#include "system.h"
#include "prototypes.h"





int main()
{

int max_nodes = 2000, max_pipes = 4000, default_num=10;
int num_pipes, num_nodes; 
int i, j;
int new_read;
bool debug = false;
array <int> node_table;
vector<Real> lengths;
vector<Real> diameters;
vector<Real> external_flows;
vector<Real> initial_heads;
vector<Real> hw_coeffs;

init_scan ();

new_read = true;
do
 {	 
   if( new_read ) readsc ();
   if ( matchs( "Project" , 3))
      {
		read_project(debug);
	    continue;
	  }
   if ( matchs( "number" ,3))
      {
		process_number( node_table, lengths, diameters, 
		               hw_coeffs, external_flows, 
					   initial_heads, max_pipes, max_nodes,
					   num_pipes, num_nodes, default_num, debug);
        continue;		
	  }
   if ( matchs( "reservoir" ,5))
      {
		process_reservoir(debug);
        continue;		
	  }
   if ( matchs( "pipe" , 4))
      {
	   process_propties(node_table, lengths, diameters, 
	                     hw_coeffs, num_pipes, 
						 num_nodes, debug);
	   new_read = false;
	   continue;
	  }	 
   if ( matchs( "external" , 4))
      {
	   process_external( external_flows, num_nodes, debug);
	   new_read = false;
	   continue;
	  }
   if ( matchs( "initial" , 4))
      {
	   process_initial(debug);
	   new_read = false;
	   continue;
	  }
   if ( matchs( "convergence", 4))
      {
	   process_convergence(debug);
	   new_read = true;
	   continue;
	  }
   if ( matchs( "maximum", 4))
      {
	   process_iterations(debug);
	   new_read = true;
	   continue;
	  }
   if ( matchs( "solve", 4))
      {
	   process_solve(debug);
	   new_read = true;
	   continue;
	  }
   if ( matchs( "output", 4))
      {
	   process_output(debug);
	   new_read = true;
	   continue;
	  }
   if ( matchs( "debug" , 5))
      {
	   process_debug(debug);
	   new_read = true;
	   continue;
	  }
   else if ( matchs ( "stop", 4 ))
      {
        error_message (1);
	    exit(0);
      }
   else
     {
       while (! endcrd ())
       {
	    error_message(2);
        istrue();
        continue;	
       }
     new_read = true;
     }
 } while (true);
 
 return(0);
 }
 