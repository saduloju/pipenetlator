 
//*****************************************************************************
//*             function : process_external function                          *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/25/2018                                      *
//*                                                                           *
//*****************************************************************************
#include "header.h"
#include "prototypes.h"
//
//This function stores the the external flows into a external_flows vector 
//
void process_external( vector<Real> &external_flows, int &num_nodes,
                       bool &resolve,bool debug)
{

if (debug){user_trace( 1, "process_external");} 

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
   else 
    {
	  resolve= true; return;
    }

  } while (true);


  if(debug)
    {	  
     cout<< "flow_vector\n";
     for( i=1; i<=num_nodes; i++){cout <<external_flows(i)<< endl;}
	}

	
  if(debug){ user_trace( 2, "process_external");}

return;	
}
