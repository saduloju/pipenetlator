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

void process_solve_data(array <int> &node_table, vector<Real> &lengths,
         vector<Real> &diameters, vector<Real> &hw_coeffs,
		 vector<Real> &external_flows,vector<Real> &initial_heads,
		 vector <Real> &residuals,vector <Real> &frictn_ress,int &num_pipes, 
		 int &num_nodes,int &reservoir_node, Real &reservoir_head,Real &maxr,
		 string &title,bool &link_fail, bool &debug)					
{
int i,j;
vector<int> ipt;
vector<int> link;
vector <Real>beta;
vector <Real>residualsneg;
vector <Real>x;
array <Real>J;

ipt.create(1,num_nodes+1);
link.create(1,2*num_pipes);	
beta.create(1,num_pipes);
residualsneg.create(1,num_nodes);
x.create(1,num_nodes);	
J.create(1,num_nodes,1,num_nodes);

 if (debug){user_trace( 1, "process_solve_data");}


 linkup(num_pipes,num_nodes,debug, node_table,ipt,link );
   
 for( i=1; i<= 2*num_pipes; i++)
    {
     if(link(i)==0){ user_messages(2); link_fail= true; return;} 
	}


 if(debug)
  {
  //Prints the incid_indexes(IPT),nodal incidences,branches attached to nodes
  
   cout << "\n incid_indexes"<< endl;
   for( i=1; i<= num_nodes+1; i++){cout <<setw(6)<< ipt(i) << endl;}

   cout << "\n Link"<< endl;
   for( i=1; i<= 2*num_pipes; i++){cout <<setw(6)<<link(i) << endl;}

   cout << "\n NODE No.   BRANCHES ATTACHED\n";
   for( i=2; i<=num_nodes+1; i++)
     {cout << setw(3) << i-1 << setw(12);
      for(j=ipt(i-1); j<=ipt(i)-1; j++){cout <<link(j) << setw(4);}
	  cout << endl;
	 }
   }


 initial_heads(reservoir_node)= reservoir_head;  
   
 //  
 // compute the residual flows 
 //  
 compute_fvec(node_table, lengths, diameters, hw_coeffs, initial_heads, external_flows, frictn_ress,residuals,
			   residualsneg, ipt,link, reservoir_node,num_nodes,debug);
 //
 //compute the Jacobian
 //
 compute_jmat( node_table, J, beta,lengths,diameters, hw_coeffs, initial_heads,frictn_ress,
			  ipt, link, reservoir_node, num_nodes, debug);	
 /////////////////////////////////////////////////////////
 
 linear_solver( J, x,residualsneg,num_nodes,debug ); 


 for(i=1; i<=num_nodes; i++){initial_heads(i) += x(i);}
 

 if(debug)		
   {
	cout <<"x"<<endl;
    for(i=1; i<=num_nodes; i++) {cout<< x(i)<< endl;}
    cout<< "residuals"<< endl;	
    for( i=1; i<=num_nodes; i++){cout << setw(5) << residuals(i) << endl;}
   }  
 //
 // obtain maximum residual
 // 
 maxr=0;
 for(i=1; i<=num_nodes; i++)
    {if (maxr<abs(residuals(i)))maxr=abs(residuals(i));}
	 
link.free();
ipt.free();
beta.free();
residualsneg.free();
x.free();	
J.free();

if (debug){user_trace( 2, "process_solve_data");}
  
return;
}
