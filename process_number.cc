
#include "system.h"
#include "prototypes.h"
void process_number(array <int> &node, vector<double> &length_vector,
                    vector<double> &diam_vector, vector<double> &hz_coeff_vector,
					vector<double> &flow_vector, vector<double> &ihead_vector, int &num_pipes, int &num_nodes)
{
 user_trace( 1, "process_number");
int i,j;
//double head_value;	
while( ! endcrd ())
 {
   matchs( "of", 2 );
   if( matchs( "nodes", 4))
	 {
	  if( ! integr(num_nodes)){ error_message(4); continue;}
	 }
   else if( matchs( "pipes", 4))
     {
	  if( ! integr(num_pipes)){ error_message(5); continue;}	  
     }
   else 
     {
	   error_message(6);
	   istrue();
	   continue;
	 }
	 
 }
 
 
node.create(1,num_pipes,1, 2);
length_vector.create(1, num_pipes);
diam_vector.create(1, num_pipes);
hz_coeff_vector.create(1, num_pipes);
flow_vector.create(1, num_nodes);
ihead_vector.create(1, num_nodes);

for( i=1; i<=num_pipes; i++)
   {for(j=1; j<=2 ; j++){node(i,j)=0;}}

for( i=1; i<=num_pipes; i++)
   {
     length_vector(i)=0;
     diam_vector(i)=0;
     hz_coeff_vector(i)=0;
   }
 
user_trace( 2, "process_number");
return;
}


