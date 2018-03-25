//*****************************************************************************
//*             CEE 691                                                       *
//*             project: Input Translator for PipeNetwork Simulator           *
//*             function : compute_f function                                 *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/25/2018                                      *
//*                                                                           *
//*****************************************************************************
#include "header.h"
#include "prototypes.h"
//
// compute the residual for each node
//

void compute_f(array <int> &node_table, vector<Real> &lengths,
               vector<Real> &diameters, vector<Real> &hw_coeffs,
			   vector<Real> &initial_heads,vector<Real> &external_flows,
			   vector<Real> &frictn_ress,vector <Real> &residuals,
			   vector <Real> &residualsneg, vector<int> &ipt,vector<int> &link,
			   int &node, int reservoir_node,int num_nodes,  bool &debug)
					
{

int i, pipe,first_link_pos,last_link_pos,sign,start, end;
Real a=0.54, F, pow_pties; 
//                     Parameters
// link:       contains all pipes in node 1 first followed by node 2, etc.
// ipt:        used to access the starting postion of link for the list of 
//             branches attached to certain node
// Node_table: defines the nodes connected to pipe and direction
// start:    For a given pipe,the node from which water flow start from
// end:      For a given pipe,the node from which water flow flow to
// frictn_ress:stores friction resistance to flow in pipes

if(debug){user_trace( 1, "compute_f");}

 first_link_pos = ipt(node);
 last_link_pos =  ipt (node+1)-1;
 F=0.0;
	
 for(i=first_link_pos; i<=last_link_pos; i++)
	{
	 pipe= link(i);
	 sign = 1;
	 if(pipe < 0){pipe=-pipe;sign=-1;}
	 start= node_table(pipe,1);
	 end= node_table(pipe,2);
	 pow_pties=(pow(hw_coeffs(pipe),1.852)*pow(diameters(pipe),4.87));
     frictn_ress(pipe) = (8.52e5 * lengths(pipe))/ pow_pties;

	 if(sign>0)
	   {
        if(initial_heads(start)>initial_heads(end))
	      {F +=pow(((initial_heads(start)-initial_heads(end))/frictn_ress(pipe)),a);}
        else 
	      {F -=pow(((initial_heads(end)-initial_heads(start))/frictn_ress(pipe)),a);}
        }			 
			 
	 else
		{

		 if(initial_heads(start)>initial_heads(end))	
	       {F -=pow(((initial_heads(start)-initial_heads(end))/frictn_ress(pipe)),a);}
         else
		   {F +=pow(((initial_heads(end)-initial_heads(start))/frictn_ress(pipe)),a);}
		}

	}
residuals(node)=F-external_flows(node);
residualsneg(node)=-residuals(node);

if(debug)
  {
   cout<<"node"<< node<< "residuals(node)"<<residuals(node)<< "F"<< F;
   cout << "external_flows(node)"<< external_flows(node)<< endl; 
   cout << start<<"end" << end<< endl;
  }
		
if(debug){user_trace( 1, "compute_f");}
return;
}
