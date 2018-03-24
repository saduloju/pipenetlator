
//***************************************************************************
//*                                                                         *
//*             function : user_message                                     *
//*             Author : Sunday Aduloju                                     *
//*             Last Modified: 2/12/2018                                    *
//*             This function calls out messages                            *
//*                                                                         *
//***************************************************************************
//
#include "system.h"
#include "prototypes.h"
//
// global variables
//
//extern ifstream data_file;

void user_messages(int mess_num)
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
   default:
     cout << " invalid message number..../n please crosscheck...\n";
     break;
 }
return ;
}