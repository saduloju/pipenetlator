//*****************************************************************************
//*             function : trace function                                     *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/25/2018                                      *
//*****************************************************************************

#include "header.h"
#include "prototypes.h"
//
// trace entry and exit of functions
//

void user_trace(int type, string function_name )
{
  const bool on = true;
  if(! on) return;
  if(type == 1 )
	  cout << "... Trace. Entering: " << function_name << endl;
   if( type == 2)
	   cout << "...Trace. Leaving: " << function_name << endl;
   return;
}
