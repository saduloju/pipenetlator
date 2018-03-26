//*****************************************************************************
//*             function : data_check function                                *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/25/2018                                      *
//*                                                                           *
//*****************************************************************************
#include "header.h"
#include "prototypes.h"
//
// This function double check to see if bad data were stored
// This function check the availability of required data to perform analysis
// It also gives the user the idea of the default values that are used to solve
//
bool data_check(array <int> &node_table, vector<Real> &lengths,
                   vector<Real> &diameters, vector<Real> &hw_coeffs,
				   vector<Real> &external_flows, vector<Real> &initial_heads, 
				   vector<Real> &final_heads, vector<Real> &residuals,
				   vector<Real> &flow_rates,int &num_pipes, int &num_nodes,
				   int &reservoir_node, Real &reservoir_head,Real &tol,
				   const Real min_tol,const Real max_tol, int &iter,
  				   const int max_iter,bool debug)
				   
{					
 int i,j;
 
 if (debug){user_trace( 1, "data_check");}
 
 if(reservoir_head==0){user_mess(17);cout<<i<<endl; return (true);}
 if(tol==max_tol) { user_mess(18);cout<< tol<<endl;}
 if(tol==min_tol) { user_mess(19);cout<< tol<<endl;}
 if(iter==max_iter){ user_mess(20);cout<< iter<<endl;}
 
 for( i=1; i<= num_nodes; i++)
   { for( j=1; j<=2; j++)
    {
	 if(node_table(i,j)<=0){user_mess(16);cout<<i<<endl; return (true);}	 
	}
   }
 for( i=1; i<= num_nodes; i++)
    {
	 if(initial_heads(i)<=0){user_mess(15);cout<<i<<endl; return (true);}	 
	}
 
 for( i=1; i<= num_pipes; i++)
    {
     if(lengths(i)<=0){user_mess(12);cout<<i<<endl; return (true);}
	 if(diameters(i)<=0){user_mess(13);cout<<i<<endl;return(true);}
	 if(hw_coeffs(i)<=0){user_mess(14);cout<<i<<endl;return(true);}
	}
	
if (debug){user_trace( 1, "data_check");}	

return(false);
}