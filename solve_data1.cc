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
					vector<Real> &external_flows, vector<Real> &initial_heads, 
					vector <Real> &frictn_ress, const int max_pipes, const int max_nodes,
					int &num_pipes, int &num_nodes,int &reservoir_node, Real &reservoir_head,
					Real &maxr, string &title, bool &debug)
					
{

int i,j,node,pipe,first_link_pos,last_link_pos,sign,start, end;
double a=0.54;
double F; 
double sunday1;////////////////////////////////////////////////////
vector<int> ipt;
vector<int> link;
vector <Real>beta;
vector <Real>residuals;
vector <Real>residual;
vector <Real>x;
array <Real>J;

ipt.create(1,num_nodes+1);
link.create(1,2*num_pipes);	
beta.create(1,num_pipes);
residuals.create(1,num_nodes);
residual.create(1,num_nodes);
x.create(1,num_nodes);	
J.create(1,num_nodes,1,num_nodes);

if (debug){user_trace( 1, "process_solve_data");}


linkup(num_pipes,num_nodes,debug, node_table,ipt,link );

debug= true;
if(debug ==true)
  {
  // print the incid_indexes (IPT), nodal incidences, branches attached to nodes
  
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

compute_f(lengths,diameters, hw_coeffs,initial_heads, frictn_ress, ipt,link,reservoir_node,num_nodes);

for(i=1; i<= num_nodes; i++)
  {for(j=1; j<= num_nodes; j++) 
	  {J(i,j)=0;}
  }


for(node=1; node<= num_nodes; node++)
 {if(node==reservoir_node){ continue;}
 else if(node==reservoir_node+1){ continue;}
  else
   {first_link_pos = ipt(node);
    last_link_pos =  ipt (node+1)-1;
F=0.0;
//J(node,start)=0.0;
//J(node,end)=0.0;
	
 for(i=first_link_pos; i<=last_link_pos; i++)
	 {
	  pipe= link(i);
	  sign = pipe/abs(pipe);
	  pipe = abs(pipe);
	  start= node_table(pipe,1);
	  end= node_table(pipe,2);
	  cout<< "start"<< start<< "end" << end<< endl;
      frictn_ress(pipe) = (8.52e5 * lengths(pipe))/ (pow(hw_coeffs(pipe),1.852)*pow(diameters(pipe),4.87));
	  cout<<"a"<< a<< endl;
	  cout << "frictn_ress(pipe)"<<frictn_ress(pipe)<< endl;
	  cout << "initial_heads(start)"<< initial_heads(start)<<endl;//   (hw_coeffs(pipe))^1.852)
	  cout << "initial_heads(end)"<< initial_heads(end)<<endl;
      beta(pipe)=(a/frictn_ress(pipe))* pow((abs(initial_heads(start)-initial_heads(end))/frictn_ress(pipe)),(a-1));
      cout <<"beta(pipe)1"<< beta(pipe)<< endl;
	  if(sign>0)
		{
	//		cout<< "sunday"	<< endl;
		 J(node,start)+=beta(pipe);
		 J(node,end)-=beta(pipe);
			 
         if(initial_heads(start)>initial_heads(end))
	       {F +=pow(((initial_heads(start)-initial_heads(end))/frictn_ress(pipe)),a);//}+
		//	 cout<< "start"<< start<< "end" << end<< endl;
		cout << node<< "F4="<< F<< "fk"<<frictn_ress(pipe)<< "H" << initial_heads(end)<<initial_heads(start)<<endl;}
         else 
	       {F -=pow(((initial_heads(end)-initial_heads(start))/frictn_ress(pipe)),a);//}
	// cout<< "start"<< start<< "end" << end<< endl;
	 cout << node<< "F="<< F<< endl;}
        }			 
			 
	  else
		{
		cout<< "sunday"	<< endl;
		 J(node,start)-=beta(pipe);
		 J(node,end)+=beta(pipe);
		 if(initial_heads(start)>initial_heads(end))	
	       {F -=pow(((initial_heads(start)-initial_heads(end))/frictn_ress(pipe)),a);//}-
		//	 cout<< "start"<< start<< "end" << end<< endl;
		cout << node<< "F8="<< F<< "fk"<<frictn_ress(pipe)<< "H" << initial_heads(end)<<initial_heads(start)<<endl;}
         else
		   {F +=pow(((initial_heads(end)-initial_heads(start))/frictn_ress(pipe)),a);//}
        //   	 cout<< "start"<< start<< "end" << end<< endl;
		   cout << node<< "F="<< F<< endl;}
		}
		
/*		flows(node)=F-external_flows(node);
		cout<<"node"<< node<< "flows(node)"<<flows(node)<< "F"<< F<< "external_flows(node)"<< external_flows(node)<< endl; 
		cout << start<<"end" << end<< endl;
        cout << beta(pipe)<< endl;*/
	  }
	  		residual(node)=F-external_flows(node);
			residuals(node)=-residual(node);
			///////////////////////////////////////////////////////////////////////////////////////////////////
		cout<<"node"<< node<< "residuals(node)"<<residuals(node)<< "F"<< F<< "external_flows(node)"<< external_flows(node)<< endl; 
		cout << start<<"end" << end<< endl;
        cout <<"beta(pipe)2"<< beta(pipe)<< endl;
	}
  }
  
  for(i=1; i<=num_nodes; i++)
  {J(reservoir_node,i)=0; J(i,reservoir_node)=0;}
   J(reservoir_node, reservoir_node)=1.0;
   
   
 ////////////////////////////////////////////// 
   
   for(i=2; i<=num_nodes; i++)
  {J(reservoir_node+1,i)=0; J(i,reservoir_node+1)=0;}
   J(reservoir_node+1, reservoir_node+1)=1.0;  
   
   
   
   
   
   
   
   
	
  cout<< "Jmatrix"<< endl;	
  for( i=1; i<=num_nodes; i++)
	 {cout << setw(5) << i << setw(5);
	  for(j=1; j<=num_nodes; j++)
		{cout <<J(i,j) << setw(15);}
	    cout << endl;
	 }	

  cout<< "residual"<< endl;	
  for( i=1; i<=num_nodes; i++)
	 {cout << setw(5) << residuals(i) << endl;}


linear_solver( J, x,residuals,num_nodes,debug ); 
 /////////////////////////////////////////////////////////////////////////////////////
 
 if(debug)
   {
    cout <<"x"<<endl;
    for(i=1; i<=num_nodes; i++) {cout<< x(i)<< endl;}
   
    cout<< "residuals"<< endl;	
    for( i=1; i<=num_nodes; i++){cout << setw(5) << residual(i) << endl;}
   }
  
   

// obtain residual to compare with convergence tolerance  
maxr=0;
for(i=1; i<=num_nodes; i++)
{if (maxr<abs(residual(i)))maxr=abs(residual(i));}
   
   
   
   
   
   
cout << "maxr" << maxr;

 cout<<"Head\n"; 
  for(i=1; i<=num_nodes; i++)
 {cout<<initial_heads(i)<<endl;}
 
 
 for(i=1; i<=num_nodes; i++){initial_heads(i) += x(i);}
 initial_heads(reservoir_node)= reservoir_head;
 
 
 
 
 
	 
link.free();
ipt.free();

 cout << "COMMAND NOT YET IMPLEMENTED FOR SOLVE\n";
  
  if (debug){user_trace( 2, "process_solve_data");}
  
return;
}
