//*****************************************************************************
//*             CEE 691                                                       *
//*             project: Input Translator for PipeNetwork Simulator           *
//*             function : process_parameters function                        *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/9/2018                                       *
//*                                                                           *
//*****************************************************************************
#include "header.h"
#include "prototypes.h"
//
//
// 
void process_parameters(array <int> &node_table, vector <Real> &lengths,
                        vector <Real> &diameters, vector <Real> &hw_coeffs,
						int &num_pipes, int &num_nodes, bool &debug)
{

if (debug ==true){user_trace( 1, "process_parameters");}	

Real length_value, diam_value, hz_w_value;
int pipe_number,LDH;
bool check;

do{
    readsc();

    if(  integr(pipe_number))
	  { 
        if (pipe_number < 0){error_message(38); continue;}
		if (pipe_number > num_pipes){error_message(16); continue;}//}
      else
	    {
	      process_node(node_table, lengths, diameters,
               	   hw_coeffs, pipe_number, length_value, 
				   diam_value, hz_w_value, num_pipes, num_nodes, debug);
	     continue;
	    }
     }
   check= check_Len_diam_hw(LDH, debug);
   if (check == true)
	 {
		process_Len_diam_hw(length_value, diam_value, hz_w_value, num_nodes, LDH, debug);
		continue;
	 }
	 else break;
		
 } while (true);

if (debug ==true){user_trace( 2, "process_parameters");}

}











//*****************************************************************************
//*             CEE 691                                                       *
//*             project: Input Translator for PipeNetwork Simulator           *
//*             function : check_Len_diam_hw function                         *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/9/2018                                       *
//*                                                                           *
//*****************************************************************************
#include "prototypes.h"
//
//This function check if the Length, diameter or hazen williams starts a line
// and capture the pipe properties type
//
bool check_Len_diam_hw(int &LDH, bool &debug)
 {
  if (debug ==true){user_trace( 1, "check_Len_diam_hw");}	

  if ( matchs( "length", 3)){ LDH=1; return( true );}
  if ( matchs( "diameter", 4)){ LDH=2; return( true );}
  else if ( matchs( "hazen_williams", 4)){LDH=3; return( true );}
  else return( false );
 
  if (debug ==true){user_trace( 2, "check_Len_diam_hw");} 

 }
 

 
//*****************************************************************************
//*             CEE 691                                                       *
//*             project: Input Translator for PipeNetwork Simulator           *
//*             function : process_Len_diam_hw function                       *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/9/2018                                       *
//*                                                                           *
//*****************************************************************************
#include "prototypes.h"
//
//This function reads the pipe properties on the line and
// and transfer it to the process_node function for storage
	 
void process_Len_diam_hw(Real &length_value, Real &diam_value, 
                         Real &hz_w_value,int &num_nodes, int &LDH, bool &debug)
{
  if (debug ==true){user_trace( 1, "process_Len_diam_hw");} 
//
//read the pipe properties values that has been read by the 
//bool function check_Len_diam_hw
//
  if ( LDH==1)
     {
	if( ! numd(length_value)) {error_message(8);}
	if(num_nodes < 0) { error_message(38);}
	if(length_value < 0) {error_message(24);}
	if(length_value < 0.2) {error_message(27);}
     }
  if ( LDH==2)
     {
	if( ! numd(diam_value)) {error_message(9);}
	if(diam_value < 0) {error_message(25);}
    if(diam_value < 0.5) {error_message(28);}
	}
  else if ( LDH==3)
    {
    matchs( "coeffients", 4);
    if( ! numd(hz_w_value)) {error_message(10);}
	if(hz_w_value < 0) {error_message(26);}
    if(hz_w_value < 0.005) {error_message(29);}
    } 

//
//read the other pipe properties and values remaining on  
//the line
//
//	
  while ( ! endcrd() )
  {
   if ( matchs( "length", 3))
     {
	  if( ! numd(length_value)) {error_message(8); continue;}
	  if(num_nodes < 0) { error_message(38); return;}
	  if(length_value < 0) {error_message(24);}
	  if(length_value < 0.2) {error_message(27);}
     }
   if ( matchs( "diameter", 4))
     {
	  if( ! numd(diam_value)) {error_message(9); continue;}
	  if(diam_value < 0) {error_message(25);}
      if(diam_value < 0.5) {error_message(28);}
     }
  else if ( matchs( "hazen_williams", 4))
    {
     matchs( "coeffients", 4);
     if( ! numd(hz_w_value)) {error_message(10); continue;}
	 if(hz_w_value < 0) {error_message(26);}
     if(hz_w_value < 0.005) {error_message(29);}
    } 
  else break;  
 }
 
if (debug ==true){user_trace( 1, "process_Len_diam_hw");} 

return;
} 
 
 

 
//*****************************************************************************
//*             CEE 691                                                       *
//*             project: Input Translator for PipeNetwork Simulator           *
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
#include "prototypes.h"

void process_node(array <int> &node_table, vector<Real> &lengths, 
                 vector<Real> &diameters, vector<Real> &hw_coeffs,
				 int &pipe_number,Real &length_value, Real &diam_value,
				 Real hz_w_value, int &num_pipes, int &num_nodes, bool &debug)
{

 if (debug ==true){user_trace( 1, "process_node");} 
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

   
    if(debug ==true)
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

    if(debug ==true)
     { 
       for( i=1; i<=num_pipes; i++)
	      {for(j=1; j<=2 ; j++)
	  	     {cout <<i<<j<< node_table(i,j)<< endl;}
          }
	 }

    if(debug ==true)  
     {
	   cout<< "lengths\n";
      for( i=1; i<=num_pipes; i++){cout <<lengths(i)<< endl;}
      cout<< "diameters\n";
      for( i=1; i<=num_pipes; i++){cout <<diameters(i)<< endl;}
      cout<< "hw_coeffs\n";
      for( i=1; i<=num_pipes; i++){cout <<hw_coeffs(i)<< endl;}
     }

 }

  if (debug ==true){user_trace( 2, "process_node");} 
  
 return; 
} 


