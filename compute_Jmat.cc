//*****************************************************************************
//*             CEE 691                                                       *
//*             project: Input Translator for PipeNetwork Simulator           *
//*             function : compute_jmat function                             *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/9/2018                                       *
//*                                                                           *
//*****************************************************************************
#include "system.h"
#include "prototypes.h"
					
void compute_jmat( array <int> &node_table, array <Real> &J,vector <Real> &beta, vector<Real> &lengths,vector<Real> &diameters, vector<Real> &hw_coeffs,
               vector<Real> &initial_heads,vector<Real> &frictn_ress,
			   vector<int> &ipt,vector<int> &link, int reservoir_node,int num_nodes,  bool &debug)					
					
					
{

int i,j,node;

if (debug){user_trace( 1, "compute_jmat");}

for(i=1; i<= num_nodes; i++)
   {for(j=1; j<= num_nodes; j++) 
	  {J(i,j)=0;}
   }


for(node=1; node<= num_nodes; node++)
 {if(node==reservoir_node)
  { 
   continue;
  }
 else
  {
   compute_j( node_table, J, beta,lengths,diameters, hw_coeffs, initial_heads,frictn_ress,
			  ipt, link, node, reservoir_node, num_nodes, debug);	  
  }
 }
 
 
for(i=1; i<=num_nodes; i++){J(reservoir_node,i)=0; J(i,reservoir_node)=0;}
    J(reservoir_node, reservoir_node)=1.0;
   
	
if(debug)
  {
   cout<< "Jmatrix"<< endl;	
   for( i=1; i<=num_nodes; i++)
      {cout << setw(5) << i << setw(5);
       for(j=1; j<=num_nodes; j++)
	       {cout <<J(i,j) << setw(15);}
	   cout << endl;
	  }
  }
 
if (debug){user_trace( 2, "compute_jmat");}
  
return;
}
