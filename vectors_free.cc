//*****************************************************************************
//*             function : vectors_free function                              *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/25/2018                                      *
//*                                                                           *
//*****************************************************************************
#include "header.h"
#include "prototypes.h"
//
// free the vectors arrays created earlier for storing solve command data
//
void vectors_free(vector<Real> &final_heads,vector<Real> &residuals,
                  vector<Real> &flow_rates, bool debug)
{
	
if (debug){user_trace( 1, "vectors_free");}	
	
 residuals.free();
 final_heads.free();
 flow_rates.free();

if (debug){user_trace( 2, "vectors_free");}

return;
}