//*****************************************************************************
//*             CEE 691                                                       *
//*             project: Input Translator for PipeNetwork Simulator           *
//*             function : process_solve function                             *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/9/2018                                       *
//*                                                                           *
//*****************************************************************************
#include "system.h"
#include "prototypes.h"


void compute_f(array <int> &node_table, vector<Real> &lengths,vector<Real> &diameters,
               vector<Real> &hw_coeffs,vector<Real> &initial_heads,
			   vector<Real> &external_flows,vector<Real> &frictn_ress,
			   vector <Real> &residuals,vector <Real> &residualsneg, vector<int> &ipt,
			   vector<int> &link, int &node, int reservoir_node,int num_nodes,  bool &debug)
					
{

int i,j,pipe,first_link_pos,last_link_pos,sign,start, end;
double a=0.54;
double F; 

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
     frictn_ress(pipe) = (8.52e5 * lengths(pipe))/ (pow(hw_coeffs(pipe),1.852)*pow(diameters(pipe),4.87));

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
