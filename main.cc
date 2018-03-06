#include "system.h"
#include "prototypes.h"

//ifstream data_file;

int main()
{
 user_trace( 1, "main");
 //int i,values[10];
 //int *v_ptr;
 
/* v_ptr = values;
 v_ptr = &values[0];*/
 
//string num_values;
array <double>inten;////////////////////////////////////////////////////////////////////////////////
array <int> node;
vector<double> length_vector;
vector<double> diam_vector;
vector<double> flow_vector;
vector<double> ihead_vector;
vector<double> hz_coeff_vector;
inten.create(1,100,1, 100); /////////////////////////////////////////////////////////////////
int num_pipes, num_nodes; 
int i, j;
 int new_read;
 init_scan ();
 new_read = true;
 do
 {	 
   if( new_read ) readsc ();
   if ( matchs( "Project" , 3))
      {
		 read_project();
	   continue;
	  }
   if ( matchs( "number" ,3))
      {
		process_number( node, length_vector, diam_vector, hz_coeff_vector, flow_vector, ihead_vector, num_pipes, num_nodes);
        continue;		
	  }
   if ( matchs( "reservoir" ,5))
      {
		process_reservoir();
        continue;		
	  }
   if ( matchs( "pipe" , 4))
      {
	   process_propties(node, length_vector, diam_vector, hz_coeff_vector, num_pipes, num_nodes);
	   new_read = false;
	   continue;
	  }	 
   if ( matchs( "external" , 4))
      {
	   process_external( flow_vector, num_nodes);
	   new_read = false;
	   continue;
	  }
   if ( matchs( "initial" , 4))
      {
	   process_initial();
	   new_read = false;
	   continue;
	  }
   if ( matchs( "convergence", 4))
      {
	   process_convergence();
	   new_read = false;
	   continue;
	  }
   if ( matchs( "maximum", 4))
      {
	   process_iterations();
	   new_read = false;
	   continue;
	  }
   if ( matchs( "solve", 4))
      {
	   process_solve();
	   new_read = false;
	   continue;
	  }
   if ( matchs( "output", 4))
      {
	   process_output();
	   new_read = false;
	   continue;
	  }
   if ( matchs( "nodal" , 3))
      {
	   process_nodal_data(inten);
	   new_read = false;
	   continue;
	  }
   if( matchs( " element", 4))
     {	  cout << "not processed now" << endl;
	 }
   else if ( matchs ( "stop", 4 ))
   {
    error_message (1);
	exit(0);
   }
   else
   {
     while (! endcrd ())
      {
	    error_message(2);
        istrue();
        continue;	
      }
     new_read = true;
   }
 } while (true);
 {cout <<"work on this/n";}
 user_trace( 2, "main");
 return(0);
 }
 