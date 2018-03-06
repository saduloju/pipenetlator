#include "system.h"
#include "prototypes.h"

void process_propties(array <int> &node, vector<double> &length_vector, vector<double> &diam_vector, vector<double> &hz_coeff_vector, int &num_pipes, int &num_nodes)
{
user_trace( 1, "process_propties");
if ( matchs( " other_properties", 4))
   {
	   
   }
else if ( matchs( "properties", 4))
   {
     process_parameters(node,length_vector, diam_vector, hz_coeff_vector, num_pipes, num_nodes);
   }
user_trace( 2, "process_propties");
   return;
}