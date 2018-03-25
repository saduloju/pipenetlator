//*****************************************************************************
//*             CEE 691                                                       *
//*             project: Input Translator for PipeNetwork Simulator           *
//*             function : read project function                              *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/9/2018                                       *
//*                                                                           *
//*****************************************************************************
#include "header.h"
#include "prototypes.h"
//
// This function reads the project command, creates arrays and 
// free the array after the next project command is read
//

void read_project(array <int> &node_table, vector<Real> &lengths, 
                  vector<Real> &diameters, vector<Real> &hw_coeffs, 
				  vector<Real> &external_flows, vector<Real> &initial_heads,
				  int &counte,Real &tol,int &iter, string &title, bool &debug)
{

int nchar_in_string;
title.reserve(80);

if (debug ==true){user_trace( 1, "read_project");}

if(isstring ())
  {
	title = " ";
	scan_contents(title,nchar_in_string);
  }

if( counte > 1)
  {
    node_table.free();
    lengths.free();
    diameters.free();
    hw_coeffs.free();
    external_flows.free();
    initial_heads.free();
    tol=0.0;
    iter=0;	
  }
 
if(debug ==true){user_trace( 2, "read_project");}

return;	 
}