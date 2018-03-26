//*****************************************************************************
//*             function : process_parameters function                        *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/9/2018                                       *
//*                                                                           *
//*****************************************************************************
#include "header.h"
#include "prototypes.h"
//
//
// 
void process_parameters(array <int> &node_table, vector <Real> &lengths,
                        vector <Real> &diameters, vector <Real> &hw_coeffs,
						int &num_pipes, int &num_nodes, bool debug)
{

if (debug){user_trace( 1, "process_parameters");}	

Real length_value, diam_value, hz_w_value;
int pipe_number,LDH;
bool check;

do{
    readsc();

    if(  integr(pipe_number))
	  { 
        if (pipe_number < 0){error_message(38); continue;}
		if (pipe_number > num_pipes){error_message(16); continue;}//}
      else
	    {
	      process_node(node_table, lengths, diameters,
               	   hw_coeffs, pipe_number, length_value, 
				   diam_value, hz_w_value, num_pipes, num_nodes, debug);
	     continue;
	    }
     }
   check= check_Len_diam_hw(LDH, debug);
   if (check)
	 {
		process_Len_diam_hw(length_value, diam_value, hz_w_value, num_nodes, LDH, debug);
		continue;
	 }
	 else break;
		
 } while (true);

if (debug){user_trace( 2, "process_parameters");}

return;
}
