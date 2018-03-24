//*****************************************************************************
//*             CEE 691                                                       *
//*             project: Input Translator for PipeNetwork Simulator           *
//*             function : process_debug function                             *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/24/2018                                       *
//*                                                                           *
//*****************************************************************************
#include "system.h"
#include "prototypes.h"
//
//	This helps with debugging
// 	it debugs when the user send "debug on" command 
// 	and stop debugging when the user sends the "debug off" function
//
void process_debug( bool &debug)
 { 
   if( matchs( "on", 2)) debug=true;
   else if( matchs( "off", 3))debug=false;  
   else error_message(32);

return;
 }