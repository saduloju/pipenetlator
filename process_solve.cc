//*****************************************************************************
//*             function : process_solve function                             *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/25/2018                                      *
//*****************************************************************************
#include "header.h"
#include "prototypes.h"
//
// This function performs Newton iteration to solve the Steady State Pressurized 
// Pipe flow analysis
// Newton iterations provides the final heads needed to computes flow rates
//
void process_solve(array <int> &node_table, vector<Real> &lengths,
                   vector<Real> &diameters, vector<Real> &hw_coeffs,
				   vector<Real> &external_flows, vector<Real> &initial_heads, 
				   vector<Real> &final_heads, vector<Real> &residuals,
				   vector<Real> &flow_rates,int num_pipes, int num_nodes,
				   int reservoir_node, Real reservoir_head,Real &maxr,
				   Real tol,const Real min_tol, const Real max_tol,int &iter,
				   const int max_iter,bool &iter_limit, bool &data_fail,
				   bool &resolve, bool &output_reslt, bool debug)
{
int i, kont;
bool check_link= true,check_data=false;
vector<int> ipt,link;
vector <Real>frictn_ress;
frictn_ress.create(1,num_pipes);ipt.create(1,num_nodes+1);
link.create(1,2*num_pipes);		
//                     Parameters
// kont:       counter for number of iterations
// check_link: checks if the pipes are properly connected to
// outplt:     control output results function to print result.
// link:       contains all pipes in node 1 first followed by node 2, etc.
// ipt:        used to access the starting postion of link for the list of 
//             branches attached to certain nodes
// maxr:       Maximum residual 
// check_data: checks all other data required to solve are present/correct
// frictn_ress:stores friction resistance to flow in pipes
// resolve:    contols the solve function to provide solution if modifications 
//             are made
// output_reslt:controls the output_result function to provide results only
//             when new solutions are provided
//
//                     Functions
// linkup: provides a list of pipes connected to the node and returns true if
//             if there is connectivity error
// data_check: check if all input data required to solve are available/correct
// process_solve_data: call functions to calculate the residuals and Jacobian 
//             matrix
// solution status: provide the current iteration number and maximum residual
// compute_flows: compute the flow rate in the pipe
//
if (debug){user_trace( 1, "process_solve");}

output_reslt = resolve ; 
if(resolve)
  {  	  
   check_link=linkup(num_pipes,num_nodes,debug, node_table,ipt,link );
   
   if(debug)
      {
//		Prints the incid_indexes(IPT),nodal incidences
       cout << "\n incid_indexes"<< endl;
       for( i=1; i<= num_nodes+1; i++){cout <<setw(6)<< ipt(i) << endl;}
       cout << "\n Link"<< endl;
       for( i=1; i<= 2*num_pipes; i++){cout <<setw(6)<<link(i) << endl;}
     }  

   if( !check_link){ user_mess(2); data_fail= true; return;}
 
   initial_heads(reservoir_node)= reservoir_head;

   check_data= data_check(node_table, lengths, diameters, hw_coeffs,external_flows,
                     initial_heads,final_heads,residuals, flow_rates,num_pipes,
					 num_nodes, reservoir_node, reservoir_head,tol,min_tol, max_tol,
					 iter,max_iter, debug);
					 
   if (check_data){ data_fail= true; return;}
	 
   for (i=1; i<=num_nodes; i++)residuals(i)=0;
  
   process_solve_data(node_table, lengths, diameters, hw_coeffs,external_flows,
                     initial_heads,residuals,frictn_ress, ipt, link,num_pipes,
					 num_nodes, reservoir_node, reservoir_head,maxr,debug);
   kont=1;
   user_mess(7);
   solution_status( maxr,kont, debug); 
   do{
      if( kont > iter)
	    { 
         iter_limit = true;
         user_mess(4); 
         return;
	    }	  
      if(abs(maxr) >tol)
        { 
         process_solve_data(node_table, lengths, diameters, hw_coeffs,
		           external_flows,initial_heads,residuals,frictn_ress,ipt,link,
				   num_pipes,num_nodes, reservoir_node, reservoir_head, maxr,
				   debug);
	     kont=++kont;
         solution_status( maxr,kont,debug);	
         continue;				
        }
      else 
	  break;
   
     }while (true);			
//           obtain final heads at all nodes
   for(i=1; i<=num_nodes; i++){ final_heads(i)=initial_heads(i);}

   compute_flows(node_table, lengths, diameters, hw_coeffs,external_flows,
                     final_heads,flow_rates, frictn_ress,num_pipes, num_nodes,
				     reservoir_node, reservoir_head,debug);	
   user_mess(5);
  }
 else
  {
   user_mess(3);
  }
link.free();ipt.free();frictn_ress.free();
user_mess(8);
if(debug){user_trace( 2, "process_solve");}
return; 
}