
//***************************************************************************
//*                                                                         *
//*             function : error_message                                    *
//*             Author : Sunday Aduloju                                     *
//*             Last Modified: 3/22/2018                                     *
//*             This function calls out messages                            *
//*                                                                         *
//***************************************************************************
//
#include "system.h"
#include "prototypes.h"
//
//
//
//

void error_message(int err_num)
{
	
 string title;
 int nchar_in_string;
 //title.reserve(200);
scan_contents(title,nchar_in_string);

switch( err_num ) 
 { 
   case 1 : 
     cout << " Program Terminated by user " << flush;
	 break;
   case 2 :
     cout << " >>> ERROR: wrong command {"<< title <<"}....skip....\n";
     break;
   case 3:
     cout << ">>> ERROR: no of nodes {"<< title <<"} is not integer!\n";
     break;
   case 4:
     cout << ">>>CAUTION: no of nodes {"<< title <<"} > max_nodes = 2000";
	 cout << "...using max_nodes...\n" ;
     break;
   case 5:
     cout << ">>>CAUTION: no of nodes {"<< title <<"} is negative,";
	 cout<< "...using default...\n" ;
	 break;
   case 6:
     cout << ">>> ERROR: wrong command {"<< title <<"}" << endl ;
     break;
   case 7:
     cout<< ">>> ERROR: node number{"<< title <<"} not integer!\n";; 
     break;
   case 8:
     cout<< ">>> ERROR: length  {"<< title <<"} convert to double failed!\n"; 
     break;
   case 9:
     cout<< ">>> ERROR: diameter {"<< title <<"} convert to double failed!\n"; 
     break;
   case 10:
     cout<< ">>> ERROR: Hz_Ws_coeff. {"<< title <<"} convert to double failed!\n";
     break;
   case 11:
     cout << ">>> ERROR: start node {"<< title <<"} is not integer!\n";
     break;
   case 12:
     cout<< ">>> ERROR: end node {"<< title <<"} convert to double failed!\n"; 
     break;
   case 13:
     cout<< ">>> ERROR: flow {"<< title <<"} convert to double failed!\n";
     break;
   case 14:
     cout<< ">>> ERROR: head {"<< title <<"} convert to double failed!\n"; 
     break;
   case 15:
     cout << ">>> ERROR: pipe number {"<< title <<"} is not integer!\n"; 
     break;
   case 16:
     cout << ">>> ERROR: pipe number {"<< title <<"} > no of pipes!\n";
     break;
   case 17:
     cout<< ">>> ERROR: node no {"<< title <<"} greater than total nodes!\n"; 
     break;
   case 18:
     cout<< ">>> ERROR: start node no {"<< title <<"} greater than no of nodes!\n"; 
     break;
   case 19:
     cout<< ">>> ERROR: end node no {"<< title <<"} greater than no of nodes!\n"; 
     break;
   case 20:
     cout << ">>> ERROR: no of pipes {"<< title <<"} is not integer!\n";
     break;
   case 21:
     cout << ">>>CAUTION: no of pipes {"<< title <<"}"; 
	 cout << " max_pipes = 4000,...using max_pipes...\n" ;
     break;
   case 22:
     cout << ">>>CAUTION: no of pipes {"<< title <<"} is negative!\n" ;
	 break;
   case 23:
     cout << ">>>CAUTION: wrong keyword {"<< title <<"}, properties? \n" ;
	 break;
   case 24:
     cout << ">>>CAUTION: length {"<< title <<"} is negative!\n" ;
	 break;
   case 25:
     cout << ">>>CAUTION: diameter {"<< title <<"} is negative!\n" ;
	 break;
   case 26:
     cout << ">>>CAUTION: hz_williams {"<< title <<"} is negative!\n" ;
	 break;
   case 27:
     cout << ">>>CAUTION: length {"<< title <<"} is very small (<0.2ft)!\n" ;
	 break;
   case 28:
     cout << ">>>CAUTION: diameter {"<< title <<"} is very small (<0.5in)!\n" ;
	 break;
   case 29:
     cout << ">>>CAUTION: Hz williams {"<< title <<"} is very small (<0.005)!\n" ;
	 break;
   case 30:
     cout<< ">>> ERROR: head {"<< title <<"} convert to double failed!\n"; 
     break;
   case 31:
     cout<< ">>> ERROR: flow number {"<< title <<"} is negative!\n"; 
     break;
   case 32:
     cout<< ">>> ERROR: debug word {"<< title <<"} invalid!\n"; 
     break;
   case 35:
     cout<< ">>> ERROR: tolerance {"<< title <<"} convert to double failed!\n"; 
     break;
   case 36:
     cout << ">>> ERROR: iteration {"<< title <<"} is not integer!\n";
     break;
   case 37:
     cout << ">>> could not store flow {"<< title <<"} because no of nodes is negative!\n";
     break;
   case 38:
     cout << ">>> could not store {"<< title <<"} because no of pipes is negative!\n";
     break;
   case 40:
     cout << ">>>ERROR: reservoir node {"<< title <<"} is negative!\n";
     break;
   case 41:
     cout << ">>>ERROR: reservoir head {"<< title <<"} is negative!\n";
     break;
   case 42:
     cout << ">>>ERROR: External node  {"<< title <<"} is negative!\n";
     break;
   case 43:
     cout << ">>>ERROR: wrong command {"<< title <<"} for pipe properties!\n";
     break;
   case 44:
     cout << ">>>ERROR: Output invalid no of nodes is negative!\n";
     break;
   case 45:
     cout<< ">>> ERROR: External flow {"<< title <<"} is negative!\n";
     break;
   case 46:
     cout<< ">>> ERROR: initial nodal head {"<< title <<"} convert to double failed!\n";
     break;	 
   case 48:
     cout<< ">>> ERROR: head {"<< title <<"} is negative!\n";
     break;	 
   case 50:
     cout << ">>>ERROR: tolerance {"<< title <<"} > max_tol=10!\n";
     break;
   case 51:
     cout << ">>>ERROR: tolerance {"<< title <<"} < min_tol=0.0001!\n";
     break;
   case 52:
     cout << ">>>ERROR: iteration {"<< title <<"} > max_iter=30!\n";
     break;
   case 53:
     cout << ">>>ERROR: iteration {"<< title <<"} < min_iter=2!\n";
     break;	
   case 54:
     cout << ">>>ERRoR: unknown  {"<< title <<"} output keyword ";
     break;		 
   case 55:
     cout << ">>>just checking stuff  {"<< title <<"} delete later";
     break;	
	 case 60:
   cout<< ">>> ERROR: work on it later {"<< title <<"} is not a double!\n"; 
     break;
   default:
     cout << " invalid message number..../n please crosscheck...\n";
     break;
 }
return ;
}