#include "system.h"
#include "prototypes.h"

void process_propties(array <int> &node_table, vector<Real> &lengths, 
                      vector<Real> &diameters, vector<Real> &hw_coeffs,
					  int &num_pipes, int &num_nodes, bool &debug)
{
 if (debug ==true){user_trace( 1, "process_propties");}

 if ( matchs( "properties", 4))
   {
     process_parameters(node_table,lengths, diameters, hw_coeffs, num_pipes, num_nodes, debug);
   }
 else
 {
   error_message(23);
   
 }
   
 if (debug ==true){user_trace( 2, "process_propties");}

return;
}