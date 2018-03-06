		 
#include "system.h"
#include "prototypes.h"

void process_convergence()
{		 
  double tol;
  matchs( "tolerance", 4);
  if( ! numd(tol)) { error_message(15);}
}


/////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////

#include "prototypes.h"
void process_iterations()
{
 int iter;
  matchs( "newton", 4);
  if( matchs ( "iterations", 4))
    {
      if(! integr( iter)){ error_message(16);}
	}
	
}




//////////////////////////////////////////////////////////////

#include "prototypes.h"

 void process_solve()
 {
	
cout << "COMMAND NOT YET IMPLEMENTED FOR SOLVE\n";
	 
 }
 
/////////////////////////////////////////////////////////////////

#include "prototypes.h"
 
void process_output()
{
  if( matchs( "data", 4))
    {
	  process_output_data();  
    }
  if( matchs( "results", 4))
    {
	  process_output_results();
	}
	//else break;
	
}
 
 
 /////////////////////////////////////////////////////////
 
 
#include "prototypes.h"

void process_output_data()
{
	
cout << "I will need to implement this now!\n";
	
}


#include "prototypes.h"

void process_output_results()
{
	
cout << "COMMAND NOT YET IMPLEMENTED FOR OUTPUT RESULTS\n";
	
}








 
 