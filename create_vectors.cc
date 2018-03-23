//*****************************************************************************
//*             CEE 691                                                       *
//*             project: Input Translator for PipeNetwork Simulator           *
//*             function : create_vectors function                            *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/9/2018                                       *
//*                                                                           *
//*****************************************************************************
#include "system.h"
#include "prototypes.h"
void create_vectors(vector<Real> &final_heads, vector<Real> &residuals,
                    vector<Real> &flow_rates , int &num_nodes, int &num_pipes,
					bool &debug)
{
	
if (debug){user_trace( 1, "create_vectors");}	
	
final_heads.create(1,num_nodes);
residuals.create(1,num_nodes);
flow_rates.create(1,num_pipes);

if (debug){user_trace( 2, "create_vectors");}

return;
}