		 
#include "system.h"
#include "prototypes.h"

void process_convergence( bool &debug)
{
  if (debug ==true){user_trace( 1, "process_convergence");}
  
  Real tol;
  matchs( "tolerance", 4);
  if( ! numd(tol)) { error_message(35);}
 
   if (debug ==true){user_trace( 2, "process_convergence");}
   
return;
}


/////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////

#include "prototypes.h"
void process_iterations(bool &debug)
{
  if (debug ==true){user_trace( 1, "process_iterations");}	
	
 int iter;
  matchs( "newton", 4);
  if( matchs ( "iterations", 4))
    {
      if(! integr( iter)){ error_message(36);}
	}
	
  if (debug ==true){user_trace( 2, "process_iterations");}	
  
return;
}




//////////////////////////////////////////////////////////////

#include "prototypes.h"

 void process_solve(bool &debug)
{
  if (debug ==true){user_trace( 1, "process_solve");}
	
  cout << "COMMAND NOT YET IMPLEMENTED FOR SOLVE\n";
  
  if (debug ==true){user_trace( 2, "process_solve");} 
  
return;
}
 
/////////////////////////////////////////////////////////////////

#include "prototypes.h"
 
void process_output(bool &debug)
{
  if (debug ==true){user_trace( 1, "process_output");}
  
  if( matchs( "data", 4))
    {
	  process_output_data(debug);  
    }
  if( matchs( "results", 4))
    {
	  process_output_results(debug);
	}

  if (debug ==true){user_trace( 2, "process_output");}
	//else break;
return;	
}
 
 
 
 /////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////

void process_debug( bool &debug)
 { 
   if( matchs( "on", 2)) debug=true;
   else if( matchs( "off", 3))debug=false;  
   else error_message(32);

return;
 }
 
 
 
 
 
 
 
 
 /////////////////////////////////////////////////////////
 
 
#include "prototypes.h"

void process_output_data(bool &debug)
{
 if (debug ==true){user_trace( 1, "process_output_data");}		
 cout << "I will need to implement this now!\n";
 if (debug ==true){user_trace( 2, "process_output_data");}	
}


#include "prototypes.h"

void process_output_results(bool &debug)
{
 if (debug ==true){user_trace( 1, "process_output_results");}	
 cout << "COMMAND NOT YET IMPLEMENTED FOR OUTPUT RESULTS\n";
 if (debug ==true){user_trace( 2, "process_output_results");}		
}








 
 