//*****************************************************************************
//*             CEE 691                                                       *
//*             project: Input Translator for PipeNetwork Simulator           *
//*             function : process_propties function                          *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/9/2018                                       *
//*                                                                           *
//*****************************************************************************

#include "header.h"
#include "prototypes.h"
//
//This function reads the pipe properties  by calling the process_parameter
// function
//
void process_propties(array <int> &node_table, vector<Real> &lengths, 
                      vector<Real> &diameters, vector<Real> &hw_coeffs,
					  int &num_pipes, int &num_nodes, bool &resolve, bool &debug)
{
 if (debug ==true){user_trace( 1, "process_propties");}

 if ( matchs( "properties", 4))
   {
     process_parameters(node_table,lengths, diameters, hw_coeffs, num_pipes, 
	                    num_nodes, debug);
   }
 else
 {
   error_message(23);
   
 }
 
resolve = true;
 
 if (debug ==true){user_trace( 2, "process_propties");}

 return;
}