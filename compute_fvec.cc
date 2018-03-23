//*****************************************************************************
//*             CEE 691                                                       *
//*             project: Input Translator for PipeNetwork Simulator           *
//*             function : compute_fvec function                              *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/9/2018                                       *
//*                                                                           *
//*****************************************************************************
#include "system.h"
#include "prototypes.h"


void compute_fvec(array <int> &node_table, vector<Real> &lengths,vector<Real> &diameters,
                  vector<Real> &hw_coeffs,vector<Real> &initial_heads,
				  vector<Real> &external_flows,vector<Real> &frictn_ress, 
				  vector <Real> &residuals,vector <Real> &residualsneg, vector<int> &ipt,
			      vector<int> &link, int reservoir_node,int num_nodes,  bool &debug)
					
{

int i,j,node;


if (debug){user_trace( 1, "compute_fvec");}


for(node=1; node<= num_nodes; node++)
   {if(node==reservoir_node){ continue;}
 //   else if(node==reservoir_node+1){ continue;}
    else
   {
	 compute_f(node_table, lengths, diameters, hw_coeffs, initial_heads, 
	           external_flows, frictn_ress,residuals,residualsneg, ipt,link,
			   node, reservoir_node,num_nodes,debug);  
   }
  }
  
if(debug)
 {
  cout<< "residuals"<< endl;	
  for( i=1; i<=num_nodes; i++)
	 {cout << setw(5) << residuals(i) << endl;}
 }
  
  if (debug){user_trace( 2, "compute_fvec");}
  
return;
}
