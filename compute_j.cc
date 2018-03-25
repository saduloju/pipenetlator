//*****************************************************************************
//*             project: Input Translator for PipeNetwork Simulator           *
//*             function : compute_j function                                 *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/25/2018                                      *
//*                                                                           *
//*****************************************************************************
#include "header.h"
#include "prototypes.h"
//
//This funtion computes each row of Jacobian(representing each node)
//
					
void compute_j(array <int> &node_table, array <Real> &J,vector <Real> &beta, 
          vector<Real> &lengths,vector<Real> &diameters, vector<Real> &hw_coeffs,
          vector<Real> &initial_heads,vector<Real> &frictn_ress, vector<int> &ipt,
		  vector<int> &link, int &node, int reservoir_node,int num_nodes,
		  bool &debug)
{

int i,j,pipe,first_link_pos,last_link_pos,sign,start, end;
double a=0.54, powe_hw, powe_heads,head_diff;


if (debug){user_trace( 1, "compute_j");}

 first_link_pos = ipt(node);
 last_link_pos =  ipt (node+1)-1;	
 for(i=first_link_pos; i<=last_link_pos; i++)
	{
	  pipe = link(i);
	  sign = 1;
	  if(pipe < 0){pipe=-pipe;sign=-1;}
	  start= node_table(pipe,1);
	  end= node_table(pipe,2);
	  powe_hw=pow(hw_coeffs(pipe),1.852)*pow(diameters(pipe),4.87);
	  head_diff= initial_heads(start)-initial_heads(end);
	  powe_heads=pow((abs(head_diff)/frictn_ress(pipe)),(a-1));
      frictn_ress(pipe) = (8.52e5 * lengths(pipe))/ powe_hw;
      beta(pipe)=(a/frictn_ress(pipe))* powe_heads ;
	  if(sign>0)
		{
		 J(node,start)+=beta(pipe);
		 J(node,end)-=beta(pipe);	
        }			 
			 
	  else
		{
		 J(node,start)-=beta(pipe);
		 J(node,end)+=beta(pipe);
		}
    }
	
if (debug)
   { 
     cout<< "The J" << node <<","<< start<< "=" << J(node,start)<< endl;
     cout<< "The J" << node <<","<< end<< "=" << J(node,end)<< endl;
   }

if (debug){user_trace( 1, "compute_j");}
	
return;
}