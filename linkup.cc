//*****************************************************************************
//*             function : linkup function                                    *
//*             Author : Prof. Dodds                                          *
//*             Modified by: Sunday Aduloju                                   *                    
//*             Last Modified: 3/25/2018                                      *
//*****************************************************************************
#include "header.h"
#include "prototypes.h"
//
//             create, zero then build the vector to store the number
//             of branches attached to each node
//

bool linkup( int num_branches, int num_nodes, bool debug,
              array<int> &node,vector<int> &ipt, vector<int> &link )
{
//
//             locals
//
  int local_error = false;
  int node_id, branch_id, first, pos_node, neg_node;
  vector<int> kount;
  string text="The Folowing Nodes are Not Connected to Any Branch";

  if(debug){user_trace( 1, "linkup");}
  
  kount.create(1,num_nodes);
//
  for( node_id=1; node_id<=num_nodes; node_id++ ) kount(node_id) = 0;
  for( branch_id=1; branch_id<=num_branches; branch_id++)
    {
      pos_node = node(branch_id,2);
      neg_node = node(branch_id,1);
      ++kount(pos_node);
      ++kount(neg_node);
    }
//
//             check for nodes with no branches attached. print a
//             message and quit if this of branches attached to each node
//
  first = true;
  for( node_id=1; node_id<=num_nodes; node_id++ )
    {
      if ( kount(node_id) != 0 ) continue;
      if ( first ) { cout << endl << text << endl;}
      cout << setw(10) << node_id << endl;
      first = false;
	  local_error = true;
    }
  if ( local_error ) {  kount.free(); return(false); };
//
//             all nodes have at least one branch attached.
//             using one pass over the node array, transform
//             ipt into final form while filling the link vector
//
  ipt(1) = kount(1) + 1;
//
  for( node_id=2; node_id<=num_nodes; node_id++ )
    ipt(node_id) = ipt(node_id-1) + kount(node_id);
//
  ipt(num_nodes+1) = ipt(num_nodes);
//
  for( branch_id=1; branch_id<=num_branches; branch_id++ )
    {
      pos_node = node(branch_id,2);
      neg_node = node(branch_id,1);
      --ipt(pos_node);
      link(ipt(pos_node)) = branch_id;
      --ipt(neg_node);
      link(ipt(neg_node)) = -branch_id;
    }
//
//             all done. free the temporary kount vector and leave
//
  kount.free();
  
  if(debug){user_trace( 2, "linkup");}
  
  return( true );
}
