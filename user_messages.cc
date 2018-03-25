
//***************************************************************************
//*                                                                         *
//*             function : user_message                                     *
//*             Author : Sunday Aduloju                                     *
//*             Last Modified: 2/12/2018                                    *
//*             This function calls out messages                            *
//*                                                                         *
//***************************************************************************
//
#include "header.h"
#include "prototypes.h"
//
// global variables
//
//extern ifstream data_file;

void user_mess(int mess_num)
{
switch( mess_num ) 
 { 
   case 1 :
     cout << "***********************************************************\n";
     cout << "*                                                         *\n";
     cout << "*        Steady State Pressurized Pipe flow Analysis      *\n";
     cout << "*                                                         *\n";
     cout << "*           -- Results of Pipe flow Analysis --           *\n";
     cout << "*                                                         *\n";
     cout << "***********************************************************\n";
	 cout << " Results is invalid because the solution failed to converge!\n";
	 break;
   case 2 :
     cout << ">>>CHECK! pipe(s) connected to node(s) is missing \n";
	 cout << ">>>....check earlier error message(s) while translating data\n";
     break;
   case 3:
     cout << ">>> There is no modification to existing data!\n" ;
     cout << ">>> ....The earlier solution is still valid\n" ;
     break;
   case 4:
     cout << ">>>....Solution failed to converge for the set iteration !\n";
     break;
   case 5:
     cout<< ">>> Non linear solution converged!\n"; 
     break;
   case 6:
     cout<< ">>>CHECK! Results not yet available !\n"; 
	 cout<< ">>>...please include solve command before output result !\n"; 
     break;
   case 7:
     cout << "\nSolution Status:\n";
     cout << "---------------\n";
     break;
   case 8:
     cout << "\n";
     break;
   case 9:
     cout << ">>>No new solution from solve command\n";
	 cout << ">>>...No need to output result \n";
     break;
   case 10:
     cout << ">>> There was error in input data, solution not computed\n";
	 cout << ">>>...No solution to output\n";
     break;
   case 12:
     cout << ">>> There is in an error in the length of pipe: ";
     break;
   case 13:
     cout << ">>> There is in an error in the dimeter of pipe: ";
     break;
   case 14:
     cout << ">>> There is in an error in the hw_coeff. of pipe: ";
     break;
   case 15:
     cout << ">>> There is in an error in the initial head: ";
     break;
   case 16:
     cout << ">>> CHECK! A node need to connected to pipe: ";
     break;
   case 17:
     cout << ">>> CHECK! Reservoir head not stored!";
	 cout << "...solution can not be provided\ ";
     break;
   case 18:
	 cout << ">>>The tol used is the max permiss value of:";
     break;
   case 19:
	 cout << ">>>The tol used is the min permiss value of:";
     break;
   case 20:
	 cout << ">>>The iter used is the max permiss value of:";
     break;
	 case 22:
	 cout << "...solution can not be provided\ ";
     break;	 
	 default:
     cout <<">>> invalid message number....\n";
     cout <<	" please crosscheck...\n";
     break;
 }
return ;
}