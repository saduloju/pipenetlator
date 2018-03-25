//*****************************************************************************
//*             function : process_output_results function                    *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/25/2018                                      *
//*                                                                           *
//*****************************************************************************
#include "header.h"
#include "prototypes.h"
//
//This function prints results
//
void process_output_results(vector<Real> &final_heads,vector<Real> &flow_rates, 
                            vector<Real> &residuals,Real &maxr,int &num_nodes,
                            int &num_pipes,string &title,bool &resolve,
							bool &debug)
{
 if (debug){user_trace( 1, "process_output_results");}	
 
int i;

if (resolve){ user_mess(6); return;}

cout << endl;
cout << "***********************************************************\n";
cout << "*                                                         *\n";
cout << "*        Steady State Pressurized Pipe flow Analysis      *\n";
cout << "*                                                         *\n";
cout << "*           -- computed Network Solutions --              *\n";
cout << "*                                                         *\n";
cout << "***********************************************************\n";
 
cout <<"Project: "<< title<< endl<< endl;

cout <<"Water flow rates in pipes\n";
cout << "-------------------------\n";
cout << setw(3)  << "pipe";
cout << setw(22) << "Flow rates\n";
cout << setw(23) << "(cfs)\n" ;
 
for( i=1; i<=num_nodes; i++)
   {
	cout<<setw(3)<<i;
	cout<<setw(19)<<setiosflags(ios::fixed)<< setprecision(1)<<flow_rates(i)<<endl;
   }
 
cout <<"\n\nNodal Pressures and Residual flows\n";
cout << "----------------------------------\n";
cout << setw(3)  << "Node";
cout << setw(22) << "Nodal Heads";
cout << setw(30) << "Nodal Residual Flows\n";
cout << setw(22) << "(ft)\n"; 

for( i=1; i<=num_nodes; i++)
   {
	cout<<setw(3)<<i;
	cout<<setw(19)<<setiosflags(ios::fixed)<< setprecision(1)<<final_heads(i);
	cout<<setw(25)<<setiosflags(ios::fixed)<< setprecision(3)<<residuals(i)<< endl;
   }
cout<<"Maximum Residual=";  
cout<<setw(6)<<setiosflags(ios::fixed)<< setprecision(3)<<maxr<< endl;
cout<< endl;
 
if (debug){user_trace( 2, "process_output_results");}	

resolve = false; 
 
return; 
}