





//*****************************************************************************
//*             CEE 691                                                       *
//*             project: Input Translator for PipeNetwork Simulator           *
//*             function : process_convergence function                       *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/9/2018                                       *
//*                                                                           *
//*****************************************************************************		 
#include "system.h"
#include "prototypes.h"
//
//This function stores the the convergence tolerance value
// and  call an error_messages when there is an error.
//
void process_convergence( Real &tol, const Real min_tol, const Real max_tol,
                         bool &debug)
{
  if (debug ==true){user_trace( 1, "process_convergence");}
  
  matchs( "tolerance", 4);
  if( ! numd(tol)) { error_message(35);}
  if(tol>max_tol)  {error_message(50);}
  if(tol< min_tol)  error_message(51);
 
 
 if (debug ==true){user_trace( 2, "process_convergence");}
  
return;
}


//*****************************************************************************
//*             CEE 691                                                       *
//*             project: Input Translator for PipeNetwork Simulator           *
//*             function : process_iterations function                        *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/9/2018                                       *
//*                                                                           *
//*****************************************************************************
#include "prototypes.h"
//
//This function stores the the maximum iteration value
// and  call an error_messages when there is an error.
//

void process_iterations(int &iter, const int min_iter, const int max_iter, bool &debug)
{
  if (debug ==true){user_trace( 1, "process_iterations");}	
	
  matchs( "newton", 4);
  if( matchs ( "iterations", 4))
    {
      if(! integr( iter)){ error_message(36);}
      if(iter>max_iter)  {error_message(52);}
      if(iter< min_iter)  error_message(53);
	}
	
  if (debug ==true){user_trace( 2, "process_iterations");}	
  
return;
}




 



//*****************************************************************************
//*             CEE 691                                                       *
//*             project: Input Translator for PipeNetwork Simulator           *
//*             function : process_output function                            *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/9/2018                                       *
//*                                                                           *
//*****************************************************************************
#include "prototypes.h"
//
//This function make 2 calls when it sees output command
//it  calls the "process_output_data" function to print input
//or/and calls process_output_results to print the results
//
void process_output(array <int> &node_table, vector<Real> &lengths,
                    vector<Real> &diameters, vector<Real> &hw_coeffs,
					vector<Real> &external_flows, vector<Real> &initial_heads, 
					const int max_pipes, const int max_nodes,int &num_pipes,
					int &num_nodes,int reservoir_node, int reservoir_head,
					Real &tol, int iter, string &title, bool &debug)
{
  if (debug ==true){user_trace( 1, "process_output");}
  
  if( matchs( "data", 4))
    {  
      process_output_data(node_table, lengths, diameters, hw_coeffs,
					external_flows, initial_heads, max_pipes, max_nodes,
					num_pipes, num_nodes,reservoir_node, reservoir_head, tol,iter, title, debug);  
    }
  if( matchs( "results", 4))
    {
	  process_output_results(debug);
	}

  if (debug ==true){user_trace( 2, "process_output");}
return;	
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
//*****************************************************************************
//*             CEE 691                                                       *
//*             project: Input Translator for PipeNetwork Simulator           *
//*             function : process_debug function                             *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/9/2018                                       *
//*                                                                           *
//*****************************************************************************
#include "prototypes.h"
//
//This helps with debugging
// it debugs when the user send "debug on" command 
// and stop debugging hen the user sends the "debug off" function
//
void process_debug( bool &debug)
 { 
   if( matchs( "on", 2)) debug=true;
   else if( matchs( "off", 3))debug=false;  
   else error_message(32);

return;
 }
 
 
 
 
 
//*****************************************************************************
//*             CEE 691                                                       *
//*             project: Input Translator for PipeNetwork Simulator           *
//*             function : process_output_data function                       *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/9/2018                                       *
//*                                                                           *
//*****************************************************************************
#include "prototypes.h"
//
//This function prints the input
// this consists of the pipe dimensions and hazen williams coefficient
// the external flows and the heads are also printed
// Lastly it prints the tolerance and maximum iterations 
//specified by the user
//

void process_output_data(array <int> &node_table, vector<Real> &lengths,
                    vector<Real> &diameters, vector<Real> &hw_coeffs,
					vector<Real> &external_flows, vector<Real> &initial_heads, 
					const int max_pipes, const int max_nodes,
					int &num_pipes, int &num_nodes,int reservoir_node, int reservoir_head,
					Real &tol, int iter, string &title, bool &debug)
{
 if (debug ==true){user_trace( 1, "process_output_data");}

 int i;

cout << "***************************************************************** "<< endl;
cout << "*                                                               *" << endl;
cout << "*        Steady State Pressurized Pipe flow Analysis            *" << endl;
cout << "*                                                               *" << endl;
cout << "*           -- Tabular Listing of Network Data --               *" << endl;
cout << "*                                                               *" << endl;
cout << "*****************************************************************" << endl;      

 
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
	cout<<setw(13)<<setiosflags(ios::fixed)<<setprecision(1)<<hw_coeffs(i)<<endl;
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
	cout<<setw(18)<<setiosflags(ios::fixed)<<setprecision(1)<<initial_heads(i)<<endl;	 
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
		
		
 if (debug ==true){user_trace( 2, "process_output_data");}
 
return; 
}



//*****************************************************************************
//*             CEE 691                                                       *
//*             project: Input Translator for PipeNetwork Simulator           *
//*             function : process_output_results function                    *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/9/2018                                       *
//*                                                                           *
//*****************************************************************************
#include "prototypes.h"
//
//This function prints results but the function is not implement yet
//
void process_output_results(bool &debug)
{
 if (debug ==true){user_trace( 1, "process_output_results");}	
 cout << "COMMAND NOT YET IMPLEMENTED FOR OUTPUT RESULTS\n";
 if (debug ==true){user_trace( 2, "process_output_results");}	
 
return; 
}






//*****************************************************************************
//*             CEE 691                                                       *
//*             project: Input Translator for PipeNetwork Simulator           *
//*             function : process_solve function                             *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/9/2018                                       *
//*                                                                           *
//*****************************************************************************
#include "prototypes.h"
// This function performs Newton iteration to solve the Steady State Pressurized 
//Pipe flow Analysis
//
 void process_solve(bool &debug)
{
  if (debug ==true){user_trace( 1, "process_solve");}
	
  cout << "COMMAND NOT YET IMPLEMENTED FOR SOLVE\n";
  
  if (debug ==true){user_trace( 2, "process_solve");} 
  
return;
}













 
 