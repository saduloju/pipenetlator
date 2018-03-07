#include "system.h"
#include "prototypes.h"
 
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
	  { //error_message(15); continue;}
		if (pipe_number > num_pipes){error_message(16); continue;}//}
	   //return;
      else
	  {process_node(node_table, lengths, diameters,
               	   hw_coeffs, pipe_number, length_value, 
				   diam_value, hz_w_value, num_pipes, num_nodes, debug);
	  continue;}
     }
	 check= check_Len_diam_hw(LDH, debug);
   if (check == true)
	 {
		process_Len_diam_hw(length_value, diam_value, hz_w_value, LDH, debug);
		continue;
	 }
	 else break;
		
} while (true);

if (debug ==true){user_trace( 2, "process_parameters");}

}


///////////////////////

/////////////////////////////////////////////////////
#include "prototypes.h"

bool check_Len_diam_hw(int &LDH, bool &debug)
 {
  if (debug ==true){user_trace( 1, "check_Len_diam_hw");}	

  if ( matchs( "length", 3)){ LDH=1; return( true );}
  if ( matchs( "diameter", 4)){ LDH=2; return( true );}
  else if ( matchs( "hazen_williams", 4)){LDH=3; return( true );}
  else return( false );
 
  if (debug ==true){user_trace( 2, "check_Len_diam_hw");} 

 }
 



/////////
//////////
///////// function

#include "prototypes.h"
	 
void process_Len_diam_hw(Real &length_value, Real &diam_value, 
                         Real &hz_w_value, int &LDH, bool &debug)
{
  if (debug ==true){user_trace( 1, "process_Len_diam_hw");} 

  if ( LDH==1)
     {
	if( ! numd(length_value)) {error_message(8);}
	if(length_value < 0) {error_message(24); length_value= abs(length_value);}
	if(length_value < 0.2) {error_message(24);}
     }
  if ( LDH==2)
     {
	if( ! numd(diam_value)) {error_message(9);}
	if(diam_value < 0) {error_message(25); diam_value= abs(diam_value);}
    if(diam_value < 0.5) {error_message(24);}
	}
  else if ( LDH==3)
    {
    matchs( "coeffients", 4);
    if( ! numd(hz_w_value)) {error_message(10);}
	if(hz_w_value < 0) {error_message(26); hz_w_value= abs(hz_w_value);}
    if(hz_w_value < 0.005) {error_message(24);}
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
 
if (debug ==true){user_trace( 1, "process_Len_diam_hw");} 

return;
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

void process_node(array <int> &node_table, vector<Real> &lengths, 
                 vector<Real> &diameters, vector<Real> &hw_coeffs,
				 int &pipe_number,Real &length_value, Real &diam_value,
				 Real &hz_w_value, int &num_pipes, int &num_nodes, bool &debug)
{

if (debug ==true){user_trace( 1, "process_node");} 
int node_idS, node_idE;
int i,j;

while ( ! endcrd() )
 {
   matchs( "start", 4);
   if( ! integr(node_idS)) { error_message(11);continue;}
   if (node_idS > num_nodes){error_message(18); continue;}

   matchs( "end", 3);
   if( ! integr(node_idE)) { error_message(12);continue;}
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
//	else 
//	 { error_message(12);
//	   continue;
//	 }
}

  if (debug ==true){user_trace( 2, "process_node");} 
  
 } 
//}
//}

