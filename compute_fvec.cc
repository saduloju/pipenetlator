//*****************************************************************************
//*             function : compute_fvec function                              *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/25/2018                                      *
//*                                                                           *
//*****************************************************************************
#include "header.h"
#include "prototypes.h"
//
// calls the compute_f function to provide residual for each node
// and provide the residuals for all nodes
//

void compute_fvec(array <int> &node_table, vector<Real> &lengths,
                vector<Real> &diameters,vector<Real> &hw_coeffs,
				vector<Real> &initial_heads,vector<Real> &external_flows,
				vector<Real> &frictn_ress,vector <Real> &residuals,
				vector <Real> &residualsneg, vector<int> &ipt,
				vector <int> &link,int reservoir_node,int num_nodes,bool debug)					
{

int node;


if (debug){user_trace( 1, "compute_fvec");}


for(node=1; node<= num_nodes; node++)
   {if(node==reservoir_node){ continue;}
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
  for( node=1; node<=num_nodes; node++){cout << setw(5) << residuals(node); 
  cout  << endl;}
 }
  
if(debug){user_trace( 2, "compute_fvec");}
  
return;
}
