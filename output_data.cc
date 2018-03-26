 //****************************************************************************
//*             function : process_output_data function                       *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/25/2018                                      *
//*                                                                           *
//*****************************************************************************
#include "header.h"
#include "prototypes.h"
//
//This function prints the input data
// this consists of the pipe dimensions and hazen williams coefficient
// the external flows and the heads are also printed
// Lastly it prints the tolerance and maximum iterations 
// specified by the user
//
void process_output_data(array <int> &node_table, vector<Real> &lengths,
                         vector<Real> &diameters, vector<Real> &hw_coeffs,
					     vector<Real> &external_flows, vector<Real> &initial_heads,
					     int num_pipes, int num_nodes,int reservoir_node,
						 int reservoir_head,Real tol, int iter, string &title,
						 bool debug)
{
 if (debug){user_trace( 1, "process_output_data");}

 int i;

cout << "*****************************************************************\n";
cout << "*                                                               *\n";
cout << "*        Steady State Pressurized Pipe flow Analysis            *\n";
cout << "*                                                               *\n";
cout << "*           -- Tabular Listing of Network Data --               *\n";
cout << "*                                                               *\n";
cout << "*****************************************************************\n";      

 
cout <<"Project: "<< title<< endl<< endl;
cout <<"Number of Nodes: "<< num_nodes;//<< endl<< endl;
cout<< setw(18)<< " Number of pipes: "<< num_pipes<< endl<< endl;
cout <<"Reservoir Node: "<< reservoir_node;
cout<< setw(18)<< " Reservoir head: ";
cout << setiosflags(ios::fixed) << setprecision(3) << reservoir_head << endl;
 
//
// output Pipe properties
//
 
 if(num_nodes <0){ error_message(44); return;}
 else
 {
  cout <<"Pipe Properties\n";
  cout << "---------------\n";
  cout << setw(3)  << "Pipe";
  cout << setw(13) << "Start-Node";
  cout << setw(10) << "End-Node"; 
  cout << setw(9)  << "Length";
  cout << setw(12) << "Diameter"; 
  cout << setw(20) << "Hazen Coefficient\n";
  cout << setw(35) << "(ft)" ;
  cout << setw(12) << "(in)\n";
    
  for( i=1; i<=num_pipes; i++)
   {
	cout<<setw(3)<<i<<setw(10)<<node_table(i,1)<<setw(10)<<node_table(i,2);
	cout<<setw(13)<<setiosflags(ios::fixed)<< setprecision(1)<<lengths(i);
	cout<<setw(10)<<setiosflags(ios::fixed)<< setprecision(1)<< diameters(i);
	cout<<setw(13)<<setiosflags(ios::fixed)<<setprecision(1)<<hw_coeffs(i);
	cout<<endl;
   }
//
// output external flows
//   
  cout <<"\nExternal Nodal Flows and Initial Heads\n";
  cout << "--------------------------------------\n";
  cout << setw(3)  << "Node";
  cout << setw(20) << "External Flow Rate";
  cout << setw(15) << "Initial Head\n"; 
  cout << setw(17) << "(cfs)" ;
  cout << setw(19) << "(ft)\n";  
  
  for( i=1; i<=num_nodes; i++)
   {
    cout<<setw(3)<<i;
	cout<<setw(13)<<setiosflags(ios::fixed)<< setprecision(1)<<external_flows(i);
	cout<<setw(18)<<setiosflags(ios::fixed)<<setprecision(1)<<initial_heads(i);
	cout<<endl;	 
   }
 
 }	
//
//prints convergence tolerance sets the user
//		
cout << "\nNewton Tolerance:";
cout<<setw(10)<<setiosflags(ios::fixed)<<setprecision(2)<<tol<<endl;
//
//prints Newton Iteration Limit set by the user
//		
cout << "\nNewton Iteration Limit:";
cout<<setw(5)<<setiosflags(ios::fixed)<<setprecision(2)<<iter<<endl<<endl;		
		
		
 if (debug){user_trace( 2, "process_output_data");}
 
return; 
}