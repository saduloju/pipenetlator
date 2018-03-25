//*****************************************************************************
//*             CEE 691                                                       *
//*             project: Input Translator for PipeNetwork Simulator           *
//*             function : process_iterations function                        *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/9/2018                                       *
//*                                                                           *
//*****************************************************************************
#include "header.h"
#include "prototypes.h"
//
//This function stores the the maximum iteration value
// and  call an error_messages when there is an error.
//

void process_iterations(int &iter, const int min_iter, const int max_iter, bool &resolve,
                         bool &debug)
{
  if (debug ==true){user_trace( 1, "process_iterations");}	
	
  matchs( "newton", 4);
  if( matchs ( "iterations", 4))
    {
      if(! integr( iter)){ error_message(36);}
      if(iter>max_iter)  {error_message(52);}
      if(iter< min_iter)  error_message(53);
	}

resolve= true;
	
  if (debug ==true){user_trace( 2, "process_iterations");}	
  
return;
}