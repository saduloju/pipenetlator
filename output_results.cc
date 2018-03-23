
//*****************************************************************************
//*             CEE 691                                                       *
//*             project: Input Translator for PipeNetwork Simulator           *
//*             function : process_output_results function                    *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/9/2018                                       *
//*                                                                           *
//*****************************************************************************
#include "system.h"
#include "prototypes.h"
//
//This function prints results but the function is not implement yet
//
void process_output_results(vector<Real> &final_heads,vector<Real> &flow_rates, 
                            vector<Real> &residuals,int &num_nodes,
                            int &num_pipes,bool &resolve, bool &debug)
{
 if (debug){user_trace( 1, "process_output_results");}	
 
int i;

if (resolve){ user_messages(6); return;}

cout<< endl;
cout << "***********************************************************"<< endl;
cout << "*                                                         *" << endl;
cout << "*        Steady State Pressurized Pipe flow Analysis      *" << endl;
cout << "*                                                         *" << endl;
cout << "*           -- Results of Pipe flow Analysis --           *" << endl;
cout << "*                                                         *" << endl;
cout << "***********************************************************" << endl;
 
cout <<"Pipe Solutions\n";
cout << "---------------\n";
cout << setw(3)  << "pipe";
cout << setw(25) << "Flow rates\n";
cout << setw(26) << "(cfs)\n" ;
 
for( i=1; i<=num_nodes; i++)
   {
	cout<<setw(3)<<i;
	cout<<setw(22)<<setiosflags(ios::fixed)<< setprecision(1)<<flow_rates(i)<<endl;
   }
 
cout <<"\n\nNodal Solutions\n";
cout << "---------------\n";
cout << setw(3)  << "Node";
cout << setw(25) << "Nodal Heads";
cout << setw(33) << "Residual Nodal Flows\n";
cout << setw(25) << "(ft)\n"; 

for( i=1; i<=num_nodes; i++)
   {
	cout<<setw(3)<<i;
	cout<<setw(22)<<setiosflags(ios::fixed)<< setprecision(1)<<final_heads(i);
	cout<<setw(28)<<setiosflags(ios::fixed)<< setprecision(2)<<residuals(i)<< endl;
   }
cout<< endl;
 
if (debug){user_trace( 2, "process_output_results");}	

resolve = false; 
 
return; 
}