//*****************************************************************************
//*             function : process_solve function                             *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/25/2018                                      *
//*                                                                           *
//*****************************************************************************
#include "system.h"
#include "prototypes.h"
// This function performs Newton iteration to solve the Steady State Pressurized 
// Pipe flow analysis
//
void process_solve(array <int> &node_table, vector<Real> &lengths,
                    vector<Real> &diameters, vector<Real> &hw_coeffs,
					vector<Real> &external_flows, vector<Real> &initial_heads, 
					vector<Real> &final_heads, vector<Real> &residuals,
					vector<Real> &flow_rates,int &num_pipes, int &num_nodes,
					int &reservoir_node, Real &reservoir_head,Real &tol,
					int &iter, string &title,bool &iter_limit, bool &data_fail,
					bool &resolve, bool &output_reslt, bool &debug)
{

Real maxr;
int i, kont;
bool check_link= true,check_data=false;
vector<int> ipt;
vector<int> link;
vector <Real>frictn_ress;

frictn_ress.create(1,num_pipes);
ipt.create(1,num_nodes+1);
link.create(1,2*num_pipes);	
if (debug){user_trace( 1, "process_solve");}	
// parameters
// outplt: control output results function to print result.
// link:
// ipt: 
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
//
//  check stored data for errors
//
   if( !check_link){ user_mess(2); data_fail= true; return;}
 
   initial_heads(reservoir_node)= reservoir_head;

   check_data= data_check(node_table, lengths, diameters, hw_coeffs,external_flows,
                     initial_heads,final_heads,residuals, flow_rates,num_pipes,
					 num_nodes, reservoir_node, reservoir_head,tol, iter,title,
					 iter_limit,data_fail, resolve,output_reslt, debug);
					 
   if (check_data){ data_fail= true; return;}
	 
   for (i=1; i<=num_nodes; i++)residuals(i)=0;
  
   process_solve_data(node_table, lengths, diameters, hw_coeffs,external_flows,
                     initial_heads,residuals,frictn_ress, ipt, link,num_pipes,
					 num_nodes, reservoir_node, reservoir_head,maxr, title, 
					 debug);
   kont=1;
//
//obtain solution status
//
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
         process_solve_data(node_table, lengths, diameters, hw_coeffs,external_flows,
                     		initial_heads,residuals,frictn_ress,ipt, link,num_pipes,
							num_nodes, reservoir_node, reservoir_head, maxr, title,
							debug);
	     kont=++kont;
         solution_status( maxr,kont,debug);	
         continue;				
        }
      else 
	  break;
   
     }while (true);			
//
//   obtain final heads at all nodes
//
   for(i=1; i<=num_nodes; i++){ final_heads(i)=initial_heads(i);}
//
//   compute  pipe flow rates
//
   compute_flows(node_table, lengths, diameters, hw_coeffs,external_flows, final_heads,
	             flow_rates, frictn_ress,num_pipes, num_nodes, reservoir_node, reservoir_head,
			           maxr, title, debug);	
   user_mess(5);
  }
 else
  {
   user_mess(3);
  }
 
link.free();
ipt.free();

user_mess(8);

if(debug){user_trace( 2, "process_solve");}
 
return; 
}