//*****************************************************************************
//*             function : process_solve function                             *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/25/2018                                      *
//*                                                                           *
//*****************************************************************************

// lengths = stores the lengths of pipes
// diameters = stores the diameter of pipes
// hw_coeffs = stores the Hazen Williams coefficient
// link:       contains all pipes in node 1 first followed by node 2, etc.
// Node_table: defines the nodes connected to pipe and direction
// start:    For a given pipe,the node from which water flow start from
// end:      For a given pipe,the node from which water flow flow to
// frictn_ress:stores friction resistance to flow in pipes
// external_flows
// initial_heads
// final_heads
// residual
// flow_rates
// num_pipes= total number of pipes in the network
// num_nodes= total number of nodes in the netwerk
// reservoir_node= Reservoir's node 
// reservoir_head= The pressure at the reservoir
// maxr= maximum residuals
// tol= convergence tolrance
// min_tol= default minimum tolerance
// max_tol= default maximum tolerance/permissible
// iter= user set maximum iteration/permissible
// max_iter= default maximum iteration/permissible
// min_iter= default minimum iteration/ permissible
// iter_limit= stop solve when the solution does not convergence
// data_fail= controls solve not to provide solution if user gives wrong
//            input data 
// resolve:    contols the solve function to provide solution if modifications 
//             are made
// output_reslt:controls the output_result function to provide results only
//             new solutions are provided
// debug = help with debuging          
// max_nodes= maximum nodes permissible in a network
// max_pipes= maximum pipes permissible in a network
// kont = counter newton iterations
// check_link: checks if the pipes are properly connected to

const int max_nodes = 2000, max_pipes = 4000, max_iter=300, min_iter=2;; 
const Real max_tol=10.00, min_tol=0.0001; 
int i,j, counte=0, num_pipes, num_nodes, reservoir_node, iter, new_read; 
Real reservoir_head, tol, maxr; 
bool debug = false, resolve = false,output_reslt = false,iter_limit = false;
bool data_fail = false ;
array <int> node_table;
vector<Real> lengths, diameters, external_flows,initial_heads,final_heads;
vector<Real> hw_coeffs, residuals, flow_rates;
string title;