//*****************************************************************************
//*             function : process_solve function                             *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/25/2018                                      *
//*                                                                           *
//*****************************************************************************
#include "header.h"
#include "prototypes.h"
//
// This function call other functions to compute residuals,
// provide the correction factors 
// The function add correction factors to residuals to obtain the new residuals
// Provides the maxumum residuals
//
void process_solve_data(array <int> &node_table, vector<Real> &lengths,
         vector<Real> &diameters, vector<Real> &hw_coeffs,
		 vector<Real> &external_flows,vector<Real> &initial_heads,
		 vector <Real> &residuals,vector <Real> &frictn_ress,vector<int> &ipt,
		 vector<int> &link, int &num_pipes,int &num_nodes,int &reservoir_node,
		 Real &reservoir_head,Real &maxr,bool &debug)					
{
int i,j;

vector <Real>beta;
vector <Real>residualsneg;
vector <Real>x;
array <Real>J;

beta.create(1,num_pipes);
residualsneg.create(1,num_nodes);
x.create(1,num_nodes);	
J.create(1,num_nodes,1,num_nodes);
//                     Parameters
// beta: pipes values required for the computation of the Jacobian 
// residualsneg: negative value of residual
// x:     the correction (delH) which is added to the residual to drive
//        it to zero
// J:     Jacobian matrix
// maxr: maximum residual
//
//                     Functions
// compute_fvec: solve continuity quations and store the residuals at all nodes
// compute_jmat: compute the Jacobian matrix
// linear_solver: solve non linear simultaneous equations to obtain the
//                correction (delH) which makes resudual (F) closer to zero 

 if (debug){user_trace( 1, "process_solve_data");} 
 
 compute_fvec(node_table, lengths, diameters, hw_coeffs, initial_heads,
              external_flows, frictn_ress,residuals,residualsneg, ipt,link,
			  reservoir_node,num_nodes,debug);
 compute_jmat(node_table, J, beta,lengths,diameters, hw_coeffs, initial_heads,
              frictn_ress,ipt, link, reservoir_node, num_nodes, debug);	
 linear_solver(J, x,residualsneg,num_nodes,debug ); 
 for(i=1; i<=num_nodes; i++){initial_heads(i) += x(i);}
 
 if(debug)		
   {
	cout <<"x"<<endl;
    for(i=1; i<=num_nodes; i++) {cout<< x(i)<< endl;}
    cout<< "residuals"<< endl;	
    for( i=1; i<=num_nodes; i++){cout << setw(5) << residuals(i) << endl;}
   }  
 // obtain maximum residual 
 maxr=0;
 for(i=1; i<=num_nodes; i++){if (maxr<abs(residuals(i)))maxr=abs(residuals(i));}
	 
beta.free();
residualsneg.free();
x.free();	
J.free();

if (debug){user_trace( 2, "process_solve_data");}
  
return;
}
