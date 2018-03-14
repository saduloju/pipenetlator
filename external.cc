 
//*****************************************************************************
//*             CEE 691                                                       *
//*             project: Input Translator for PipeNetwork Simulator           *
//*             function : process_external function                          *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/9/2018                                       *
//*                                                                           *
//*****************************************************************************
#include "system.h"
#include "prototypes.h"
//
//This function stores the the external flows into a external_flows vector 
//
void process_external( vector<Real> &external_flows, int &num_nodes,
                       bool &debug)
{

if (debug ==true){user_trace( 1, "process_external");} 

int node_number;
int i;
matchs( "nodal", 4);
matchs( "flows", 4);
Real flow_number;

do{
   readsc();
   
   if(  integr( node_number)) //return;
     {
	   if(node_number <0) { error_message(42);readsc(); return;}
	   
	   if( ! numd(flow_number)){ error_message(13); continue;}
	   if(num_nodes < 0){error_message(37); readsc(); return;}
       //	   
       // external flows 
       //
	   if(num_nodes>0) {external_flows(node_number)=flow_number;}
     }
   else return;

  } while (true);


  if(debug ==true)
    {	  
     cout<< "flow_vector\n";
     for( i=1; i<=num_nodes; i++){cout <<external_flows(i)<< endl;}
	}
	
  if(debug ==true){ user_trace( 2, "process_external");}
  
return;	
}



  


 
//*****************************************************************************
//*             CEE 691                                                       *
//*             project: Input Translator for PipeNetwork Simulator           *
//*             function : process_initial function                           *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/9/2018                                       *
//*                                                                           *
//*****************************************************************************
#include "prototypes.h"					 
//
//This function stores the initial heads at each nodes  
//in an "initial_heads" vector
//
void process_initial(vector<Real> &initial_heads, int &num_nodes,
                     bool &debug)
{
	
if (debug ==true){user_trace( 1, "process_initial");} 	
	
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

  } while (true);

  
  if(debug ==true)
    {	  
     cout<< "initial_heads\n";
     for( i=1; i<=num_nodes; i++){cout <<initial_heads(i)<< endl;}
	}
	
  if(debug ==true){ user_trace( 2, "process_external");}
  
return;

}












