 
//*****************************************************************************
//*             function : process_Len_diam_hw function                       *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/9/2018                                       *
//*                                                                           *
//*****************************************************************************
#include "header.h"
#include "prototypes.h"
//
//This function reads the pipe properties on the line and
// and transfer it to the process_node function for storage
	 
void process_Len_diam_hw(Real &length_value, Real &diam_value, Real &hz_w_value,
                         int &num_nodes, int &LDH, bool debug)
{
  if (debug){user_trace( 1, "process_Len_diam_hw");} 
//
//read the pipe properties values that has been read by the 
//bool function check_Len_diam_hw
//
  if ( LDH==1)
     {
	if( ! numd(length_value)) {error_message(8);}
	if(num_nodes < 0) { error_message(38);}
	if(length_value < 0) {error_message(24);}
	if(length_value < 0.2) {error_message(27);}
     }
  if ( LDH==2)
     {
	if( ! numd(diam_value)) {error_message(9);}
	if(diam_value < 0) {error_message(25);}
    if(diam_value < 0.5) {error_message(28);}
	}
  else if ( LDH==3)
    {
    matchs( "coeffients", 4);
    if( ! numd(hz_w_value)) {error_message(10);}
	if(hz_w_value < 0) {error_message(26);}
    if(hz_w_value < 0.005) {error_message(29);}
    } 

//
//read the other pipe properties and values remaining on  
//the line
//
//	
  while ( ! endcrd() )
  {
   if ( matchs( "length", 3))
     {
	  if( ! numd(length_value)) {error_message(8); continue;}
	  if(num_nodes < 0) { error_message(38); return;}
	  if(length_value < 0) {error_message(24);}
	  if(length_value < 0.2) {error_message(27);}
     }
   if ( matchs( "diameter", 4))
     {
	  if( ! numd(diam_value)) {error_message(9); continue;}
	  if(diam_value < 0) {error_message(25);}
      if(diam_value < 0.5) {error_message(28);}
     }
  else if ( matchs( "hazen_williams", 4))
    {
     matchs( "coeffients", 4);
     if( ! numd(hz_w_value)) {error_message(10); continue;}
	 if(hz_w_value < 0) {error_message(26);}
     if(hz_w_value < 0.005) {error_message(29);}
    } 
  else break;  
 }
 
if (debug){user_trace( 1, "process_Len_diam_hw");} 

return;
} 