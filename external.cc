
#include "system.h"
#include "prototypes.h"

void process_external( vector<double> &flow_vector, int &num_nodes)
{
user_trace( 1, "process_external");
typedef double Real;
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
   
  flow_vector(node_number)=flow_number;

  } while (true);


  
///use debug here  
  cout<< "flow_vector\n";
  for( i=1; i<=num_nodes; i++){cout <<flow_vector(i)<< endl;}
///



user_trace( 2, "process_external");
	
}



  



/////////////////////////////////////////////
///////////////////////////////////////////

void process_initial()
{
user_trace( 1, "process_initial");
typedef double Real;
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


user_trace( 2, "process_initial");
	
}












