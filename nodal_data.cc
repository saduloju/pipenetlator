#include "system.h"
#include "prototypes.h"

void process_nodal_data(array<double> &inten)
{

if ( matchs( "coordinates", 5))
   {
   }
else if ( matchs( "loads", 4))
   {
	 process_nodal_loads(inten);
   }
   return;
}