//*****************************************************************************
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/25/2018                                      *
//*                                                                           *
//*****************************************************************************
#include "header.h"
#include "prototypes.h"
//
// provides the solution status of the Newton iterations
//
//
void solution_status( Real & maxr, int &kont, bool &debug)
{
if(debug){user_trace( 1, "solution_status");}

cout << "Iteration number = " << kont<< endl;  
cout << "The maximum residual flow = ";
cout <<setiosflags(ios::fixed)<< setprecision(3)<< maxr << endl;

if(debug){user_trace( 2, "solution_status");}	
return;
}