#include "system.h"
#include "prototypes.h"

void process_parameters(array <int> &node, vector <double> &length_vector,  vector <double> &diam_vector, vector <double> &hz_coeff_vector, int &num_pipes, int &num_nodes)
{
user_trace( 1, "process_parameters");
typedef double Real;
Real length_value, diam_value, hz_w_value;
int pipe_number,LDH;
bool check;

do{
	
readsc();
   if(  integr( pipe_number))
   //if (pipe_number > num_pipes){error_message(17); continue;}	   //return;
     {
	   process_node(node, length_vector, diam_vector, hz_coeff_vector, pipe_number, length_value, diam_value, hz_w_value, num_pipes, num_nodes);
	   continue;
     }
	 check= check_Len_diam_hw(LDH );
   if (check == true)
	 {
		process_Len_diam_hw(length_value, diam_value, hz_w_value, LDH);
		continue;
	 }
	 else break;
		
} while (true);
user_trace( 1, "process_parameters");
}


///////////////////////

/////////////////////////////////////////////////////
#include "prototypes.h"


bool check_Len_diam_hw(int &LDH )
 {
user_trace( 1, "check_Len_diam_hw");
	   if ( matchs( "length", 3)){ LDH=1; return( true );}
	   if ( matchs( "diameter", 4)){ LDH=2; return( true );}
       else if ( matchs( "hazen_williams", 4)){LDH=3; return( true );}
	   else return( false );
user_trace( 2, "check_Len_diam_hw");
 }
 



/////////
//////////
///////// function

#include "prototypes.h"
	 
void process_Len_diam_hw(double &length_value, double &diam_value, double &hz_w_value, int &LDH)
{
user_trace( 1, "process_Len_diam_hw");

  if ( LDH==1)
     {
	if( ! numd(length_value)) {error_message(8);}
    // process_parameters(inten);
     }
  if ( LDH==2)
     {
	if( ! numd(diam_value)) {error_message(9);}
    // process_parameters(inten);
     }
  else if ( LDH==3)
    {
    matchs( "coeffients", 4);
    if( ! numd(hz_w_value)) {error_message(10);}
    // process_parameters(inten);
    } 

	
while ( ! endcrd() )
 {
  if ( matchs( "length", 3))
     {
	if( ! numd(length_value)) {error_message(8); continue;}
    // process_parameters(inten);
     }
  if ( matchs( "diameter", 4))
     {
	if( ! numd(diam_value)) {error_message(9); continue;}
    // process_parameters(inten);
     }
  else if ( matchs( "hazen_williams", 4))
    {
    matchs( "coeffients", 4);
    if( ! numd(hz_w_value)) {error_message(10); continue;}
    // process_parameters(inten);
    } 
  else break;  
 }
 user_trace( 2, "process_Len_diam_hw");
} 
 
 
 
 /*
else 
   {
	//error_message (3);
	return;
//    istrue();
 //   continue;
   }
 }
 
// }*/

///////
//////////////
////function : process node 

void process_node(array <int> &node, vector<double> &length_vector, vector<double> &diam_vector, vector<double> &hz_coeff_vector, int &pipe_number,
                   double &length_value,  double &diam_value,  double &hz_w_value, int num_pipes, int num_nodes)
{
user_trace( 1, "process_node");

int node_idS, node_idE;// pipe_number;
int i,j;

while ( ! endcrd() )
{
  matchs( "start", 4);
  if( ! integr(node_idS)) { error_message(11);continue;}
  if (node_idS > num_nodes){error_message(18); continue;}
 //      node(pipe_number,1)= node_idS;
  matchs( "end", 3);
  if( ! integr(node_idE)) { error_message(12);continue;}
  if (node_idE > num_nodes){error_message(18); continue;}

  
  
  
  ///////DEBUG THIS !!
	 cout << "pipe_number: "<< pipe_number<< endl<< flush;
	 cout << "node_idS: "<< node_idS<< endl << flush;
	 cout << "node_idE: "<< node_idE<< endl << flush;
	

	
node(pipe_number,1)= node_idS;
node(pipe_number,2)= node_idE;

length_vector(pipe_number) = length_value;
diam_vector(pipe_number) = diam_value;
hz_coeff_vector(pipe_number) = hz_w_value;



  for( i=1; i<=num_pipes; i++)
	 {for(j=1; j<=2 ; j++)
		 {cout <<i<<j<< node(i,j)<< endl;}
	 }
	 
  cout<< "length_vector\n";
  for( i=1; i<=num_pipes; i++){cout <<length_vector(i)<< endl;}
  cout<< "diam_vector\n";
  for( i=1; i<=num_pipes; i++){cout <<diam_vector(i)<< endl;}
  cout<< "hz_coeff_vector\n";
  for( i=1; i<=num_pipes; i++){cout <<hz_coeff_vector(i)<< endl;}
//	else 
//	 { error_message(12);
//	   continue;
//	 }
}
user_trace( 2, "process_node");
 } 
//}
//}

