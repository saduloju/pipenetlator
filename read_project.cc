

#include "system.h"
#include "prototypes.h"

void read_project(array <int> &node_table, vector<Real> &lengths, 
                  vector<Real> &diameters, vector<Real> &hw_coeffs, 
				  vector<Real> &external_flows, vector<Real> &initial_heads,
				  int &counte, string &title, bool &debug)
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
  }
 
if(debug ==true){user_trace( 2, "read_project");}

return;	 
}