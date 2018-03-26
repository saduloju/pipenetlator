//*****************************************************************************
//*             function : solution status function                           *
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
void solution_status( Real maxr, int kont, bool debug)
{
if(debug){user_trace( 1, "solution_status");}

cout << setw(5)<<"Iter:"<<setw(3)<<kont;  
cout << setw(20)<<"Max. res.:";
cout <<setiosflags(ios::fixed)<< setprecision(3)<< maxr << endl;

if(debug){user_trace( 2, "solution_status");}	
return;
}