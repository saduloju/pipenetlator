
#include "system.h"
#include "prototypes.h"


int linear_solver( array<double> &a, vector<double> &x,
                     vector<double> &b, int neqns, bool debug );


/********************************************************************
 *                                                                  *
 *    purpose: solve a linear set of simultaneous equations using   *
 *             gauss elimination with partial pivoting. one rhs     *
 *             is permitted. the coefficient matrix may be non-symm *
 *             etric. the coefficient matrix is replaced by it's    *
 *             triangulated form.                                   *
 *             solves: [a] {x} = {b}                                *
 *                                                                  *
 *    written by:  r. h. dodds                                      *
 *    last revision: rhd  11/21/10 -- original coding               *
 *    parameters: (double precision unless noted)                   *
 *        a       -- coefficient matrix of size neqns by neqns      *
 *        x       -- vector to receive computed solution            *
 *        b       -- vector containing the right hand side          *
 *        neqns   -- (integer) number of linear equations           *
 *        debug   -- (bool) debug flag set by calling routine       *
 *                                                                  *
 ********************************************************************/

  int linear_solver( array<double> &a, vector<double> &x,
                     vector<double> &b, int neqns, bool debug )
{
    int i, k, ll, lk, j;
    vector <int>    iwork ;
    vector <double> dwork;
    double tolerance, workmax, rmax, r, xmult, sum, zero;
//
    if ( debug )
      cout << "  > entering linear_solver..." << endl << flush;
//
//            set up the pivoting indexes and vector to store
//            maximum term on each row. create work vectors.
//
      zero      = 0.0;
      tolerance = 1.0e-20; 
      iwork.create(1,neqns);
      dwork.create(1,neqns);
      for ( i=1; i<=neqns; i++ )
       {
         iwork(i) = i;
         workmax  = zero;
         for ( j=1; j<=neqns; j++ )
          if ( fabs(a(i,j)) > workmax ) workmax = fabs(a(i,j));
         dwork(i) = workmax;
       }
//                 
//           perform triangulation of the coefficient matrix
//           with parital pivoting. terminate if a divide by zero
//           diagonal occurs even after the pivoting.
//      
      for( k=1; k<=(neqns-1); k++)
       {
        rmax = zero;
        for( i=k; i<=neqns; i++ )
         {
          ll = iwork(i);
          if ( dwork(ll) <= tolerance )
           { iwork.free(); dwork.free(); return(1); } 
          r  = fabs( a(ll,k) ) / dwork(ll);
          if ( r > rmax ) 
             { rmax = r; j = i; }
         }
//                    
        lk       = iwork(j);
        iwork(j) = iwork(k);
        iwork(k) = lk;
//
        for(i=k+1; i<=neqns; i++)
         {
           ll = iwork(i);
           if ( fabs( a(lk,k) ) <= tolerance )
             { iwork.free(); dwork.free(); return(1); }
           xmult = a(ll,k) / a(lk,k);
           for(j=k+1; j<=neqns; j++)
             a(ll,j) = a(ll,j) - xmult * a(lk,j);
           a(ll,k) = xmult;
         }
       }
//
//           perform forward reduction of the rhs.
//
      for(k=1; k<=neqns-1; k++)
       {
         for(i=k+1; i<=neqns; i++)
          {
            ll = iwork(i);
            b(ll) = b(ll) - a(ll,k) * b(iwork(k));
          }
       }
//
//
//           perform back substitution to recover solution vector
//
      x(neqns) = b(iwork(neqns)) / a(iwork(neqns),neqns);
      for(i=neqns-1; i>=1; i--)
        {
         ll  = iwork(i);
         sum = b(ll);
         for(j=i+1; j<=neqns; j++)
            sum = sum - a(ll,j) * x(j);
         x(i) = sum / a(ll,i);
        }
//
      if ( debug )
        {
          cout << "  > leaving linear_solver...";
          cout << endl << flush;
        }
//
      iwork.free();
      dwork.free();
//
      return(0);
}
