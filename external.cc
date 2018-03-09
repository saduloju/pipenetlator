
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
	   if(node_number <0) { error_message(42);readsc(); return;}
	   
	   if( ! numd(flow_number)){ error_message(13); continue;}
	   if(num_nodes < 0){error_message(37); readsc (); return;}
	   if(flow_number < 0){ error_message(13); continue;}
	   if (num_nodes>0) {external_flows(node_number)=flow_number;}
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



  



/////////////////////////////////////////////
///////////////////////////////////////////

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
	   
	   if( ! numd(heads)){ error_message(13); continue;}
	   if(num_nodes < 0){error_message(37); readsc (); return;}
	   if( heads< 0){ error_message(13); continue;}
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


/*
do{
readsc();
   if(  integr( node_number)) //return;
     {
	   if( ! numd(head)){ error_message(14); continue;}
	   if(num_nodes < 0){error_message(37); readsc ();}

	   continue;
     }
   else break;
		
  } while (true);

if (debug ==true){user_trace( 2, "process_initial");} 	

return;*/
}












