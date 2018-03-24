
//*****************************************************************************
//*             CEE 691                                                       *
//*             project: Input Translator for PipeNetwork Simulator           *
//*             function : process_convergence function                       *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/9/2018                                       *
//*                                                                           *
//*****************************************************************************		 
#include "system.h"
#include "prototypes.h"
//
//This function stores the the convergence tolerance value
// and  call an error_messages when there is an error.
//
void process_convergence( Real &tol, const Real min_tol, const Real max_tol,
                         bool &resolve, bool &debug)
{
  if (debug){user_trace( 1, "process_convergence");}
  
  matchs( "tolerance", 4);
  if( ! numd(tol)) { error_message(35);}
  if(tol>max_tol)  {error_message(50);}
  if(tol< min_tol)  error_message(51);
 
 resolve=true;
 
 if (debug){user_trace( 2, "process_convergence");}
  
return;
}

 
 


















 
 