//*****************************************************************************
//*             function : check_Len_diam_hw function                         *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/9/2018                                       *
//*                                                                           *
//*****************************************************************************
#include "header.h"
#include "prototypes.h"
//
//This function check if the Length, diameter or hazen williams starts a line
// and capture the pipe properties type
//
bool check_Len_diam_hw(int &LDH, bool debug)
 {
  if (debug){user_trace( 1, "check_Len_diam_hw");}	

  if ( matchs( "length", 3)){ LDH=1; return( true );}
  if ( matchs( "diameter", 4)){ LDH=2; return( true );}
  else if ( matchs( "hazen_williams", 4)){LDH=3; return( true );}
  if (debug){user_trace( 2, "check_Len_diam_hw");} 

  else return( false );
 }