 
//*****************************************************************************
//*             function : process_initial function                           *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/25/2018                                      *
//*                                                                           *
//*****************************************************************************
#include "header.h"
#include "prototypes.h"
//
//This function stores the initial heads at each nodes  
//in an "initial_heads" vector
//
void process_initial(vector<Real> &initial_heads, int &num_nodes, bool &resolve,
                     bool debug)
{
	
if (debug){user_trace( 1, "process_initial");} 	
	
int i, node_number;
matchs( "nodal", 4);
matchs( "heads", 4);
Real heads;

do{
   readsc();
   
   if(  integr( node_number)) //return;
     {
	   if(node_number <0) { error_message(42);readsc(); return;}
	   
	   if( ! numd(heads)){ error_message(46); continue;}
	   if(num_nodes < 0){error_message(37); readsc (); return;}
	   if( heads< 0){ error_message(48); continue;}
	   //
	   //stores the initial heads
	   //
	   if (num_nodes>0) {initial_heads(node_number)=heads;}
     }
   else return;

  }while (true);

  
if(debug)
  {	  
    cout<< "initial_heads\n";
    for( i=1; i<=num_nodes; i++){cout <<initial_heads(i)<< endl;}
  }

resolve=true;
	
if(debug){ user_trace( 2, "process_external");}
  
return;

}