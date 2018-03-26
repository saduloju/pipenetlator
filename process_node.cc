//*****************************************************************************
//*             function : process_node function                              *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/9/2018                                       *
//*                                                                           *
//*****************************************************************************
//
//This function store the pipe properties into an array. Thus, the node_table store
// the start and end nodes, diameters stores the pipe diameters, the lengths store
// pipe lengths, hw_coeffs stores the Hazen Williams coefficients. 
//
#include "header.h"
#include "prototypes.h"

void process_node(array <int> &node_table, vector<Real> &lengths, 
                 vector<Real> &diameters, vector<Real> &hw_coeffs,
				 int &pipe_number,Real &length_value, Real &diam_value,
				 Real hz_w_value, int &num_pipes, int &num_nodes, bool debug)
{

 if (debug){user_trace( 1, "process_node");} 
 int node_idS, node_idE;
 int i,j;

 while ( ! endcrd() )
  {
    matchs( "start", 4);
    if( ! integr(node_idS)) { error_message(11);continue;}
    if (num_nodes < 0){error_message(37); return;}
    if (node_idS > num_nodes){error_message(18); return;}

    matchs( "end", 3);
    if( ! integr(node_idE)) { error_message(12);continue;}
    if (num_nodes < 0){error_message(37); continue;}
    if (node_idE > num_nodes){error_message(19); continue;}

   
    if(debug)
      { 
	   cout << "pipe_number: "<< pipe_number<< endl<< flush;
	   cout << "node_idS: "<< node_idS<< endl << flush;
	   cout << "node_idE: "<< node_idE<< endl << flush;
      }

    node_table(pipe_number,1)= node_idS;
    node_table(pipe_number,2)= node_idE;

    lengths(pipe_number) = length_value;
    diameters(pipe_number) = diam_value;
    hw_coeffs(pipe_number) = hz_w_value;

    if(debug)
     { 
       for( i=1; i<=num_pipes; i++)
	      {for(j=1; j<=2 ; j++)
	  	     {cout <<i<<j<< node_table(i,j)<< endl;}
          }
	 }

    if(debug)  
     {
	   cout<< "lengths\n";
      for( i=1; i<=num_pipes; i++){cout <<lengths(i)<< endl;}
      cout<< "diameters\n";
      for( i=1; i<=num_pipes; i++){cout <<diameters(i)<< endl;}
      cout<< "hw_coeffs\n";
      for( i=1; i<=num_pipes; i++){cout <<hw_coeffs(i)<< endl;}
     }

 }

  if (debug){user_trace( 2, "process_node");} 
  
 return; 
} 