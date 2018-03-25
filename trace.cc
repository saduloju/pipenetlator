#include "header.h"
#include "prototypes.h"
//
// global variables
//
//extern ifstream data_file;

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
