
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
     cout << ">>>CHECK! Some nodes are connected to pipes " << flush;
     break;
   case 3:
     cout << " No modification to existing data!\n" ;
     cout << " ....The earlier solution is still valid\n" ;
     break;
   case 4:
     cout << "....Failed to converge for the set iteration !" << endl ;
     break;
   case 5:
     cout<< "Solution is successful!" << endl; 
     break;
   case 6:
     cout<< ">>> ChECK! Results not yet available !" << endl; 
	 cout<< ">>> please include solve command before output result !" << endl; 
     break;
   case 7:
     cout << "\nSolution Status:"<< endl;
     cout << "---------------\n";
     break;
   case 8:
     cout << "\n";
     break;
   case 9:
     cout << "No new solution from solve command\n";
	 cout << "No need to output result \n";
     break;
   default:
     cout << " invalid message number..../n please crosscheck...\n";
     break;
 }
return ;
}