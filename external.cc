
#include "system.h"
#include "prototypes.h"

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
	   if( ! numd(flow_number)){ error_message(13); continue;}
	//   continue;
     }
   else break;
   
  external_flows(node_number)=flow_number;

  } while (true);


  if(debug ==true)
    {	  
     cout<< "flow_vector\n";
     for( i=1; i<=num_nodes; i++){cout <<external_flows(i)<< endl;}
    
	 user_trace( 2, "process_external");
	} 

return;	
}



  



/////////////////////////////////////////////
///////////////////////////////////////////

void process_initial( bool &debug)
{
	
if (debug ==true){user_trace( 1, "process_initial");} 	
	
int node_number;
matchs( "nodal", 4);
matchs( "heads", 4);
Real head;

do{
readsc();
   if(  integr( node_number)) //return;
     {
	   if( ! numd(head)){ error_message(14); continue;}
//	   numd( head);
	   //process_node(node,pipe_number);
	   continue;
     }
   else break;
		
  } while (true);

if (debug ==true){user_trace( 2, "process_initial");} 	

return;
}












