#include "system.h"
#include "prototypes.h"


void process_nodal_loads(array<double> &inten)
{
int nodnum, idir,iadd;



while (true)
{
	readsc();
	if (! integr(nodnum)) return;
	if (matchs( "forces", 3))
		idir=0;
	else if ( matchs( "moments", 3))
		idir =3;
	else
	{
		//error_message();
		cout<< "error to work on2\n";
		continue;
	}
	if( matchs( "x", 1))
		iadd = 1;
	else if( matchs( "y", 1))
		iadd = 2;
	else if( matchs ( "z", 1))
		iadd = 3;
	else 
	{ 
       // error_message();
	   cout << "error to work on 3\n";
	   continue;
	}
	if( !numd(inten(idir+iadd,nodnum)))
//		error_message();
        cout << "error to work on 4\n";
	
}
return;
}