
//***************************************************************************
//*                                                                         *
//*             function : user_message                                     *
//*             Author : Sunday Aduloju                                     *
//*             Last Modified: 3/2/2018                                    *
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

void error_message(int mess_num)
{
	
 string title;
 int nchar_in_string;
 //title.reserve(200);
scan_contents(title,nchar_in_string);

switch( mess_num ) 
 { 
   case 1 : 
     cout << " Program Terminated by user 1" << flush;
	 break;
   case 2 :
     cout << " >>> ERROR: wrong command 2{"<< title <<"}....skip....\n";
     break;
   case 3:
     cout << " Input file could" << title <<"} not be opened...\n" ;
     cout << " Please try again...\n" ;
     break;
   case 4:
     cout << ">>> ERROR: Total node 4{"<< title <<"} is not integer!\n";
     break;
   case 5:
     cout<< ">>> ERROR: Total pipe {"<< title <<"} convert to double failed!\n"; 
     //cout << " An over flow is about to occur \n ";
	// cout << " Job terminated...\n";
     break;
   case 6:
     cout << ">>> ERROR: wrong command 6{"<< title <<"}" << endl ;
     break;
   case 7:
     cout<< ">>> ERROR: fail to convert float pt 7{"<< title <<"} to double!\n";; 
     break;
   case 8:
     cout<< ">>> ERROR: length 8 {"<< title <<"} convert to double failed!\n"; 
     break;
   case 9:
     cout<< ">>> ERROR: diameter 9{"<< title <<"} convert to double failed!\n"; 
     break;
   case 10:
     cout<< ">>> ERROR: Hz_Ws_coeff. 10{"<< title <<"} convert to double failed!\n";
     break;
   case 11:
     cout << ">>> ERROR: start node 10{"<< title <<"} is not integer!\n";
     break;
   case 12:
     cout<< ">>> ERROR: end node 11{"<< title <<"} convert to double failed!\n"; 
     break;
   case 13:
     cout<< ">>> ERROR: flow {"<< title <<"} convert to double failed!\n";
     break;
   case 14:
     cout<< ">>> ERROR: head {"<< title <<"} convert to double failed!\n"; 
     break;
   case 15:
     cout<< ">>> ERROR: tolerance {"<< title <<"} convert to double failed!\n"; 
     break;
   case 16:
     cout << ">>> ERROR: iteration {"<< title <<"} is not integer!\n";
     break;
   case 17:
     cout<< ">>> ERROR: node no {"<< title <<"} greater than total nodes!\n"; 
     break;
   case 18:
     cout<< ">>> ERROR: pipe no {"<< title <<"} greater than total nodes!\n"; 
     break;
   case 30:
   cout<< ">>> ERROR: work on it later 12{"<< title <<"} is not a double!\n"; 
     break;

   default:
     cout << " invalid message number..../n please crosscheck...\n";
     break;
 }
return ;
}