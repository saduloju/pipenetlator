//*****************************************************************************
//*             CEE 691                                                       *
//*             project: Input Translator for PipeNetwork Simulator           *
//*             prototype                                                     *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/9/2018                                       *
//*                                                                           *
//*****************************************************************************
typedef double Real;

void error_message(int);
void user_mess(int);
void read_project(array <int> &node_table, vector<Real> &lengths, 
                  vector<Real> &diameters, vector<Real> &hw_coeffs, 
				  vector<Real> &external_flows, vector<Real> &initial_heads,
				  int &counte,Real &tol,int iter, string &title, bool &debug);
void process_number(array <int> &node_table, vector<Real> &lengths,
                    vector<Real> &diameters, vector<Real> &hw_coeffs,
					vector<Real> &external_flows, vector<Real> &initial_heads, 
					const int max_pipes, const int max_nodes,
					int &num_pipes, int &num_nodes,bool &resolve, bool &debug);
void create_vectors(vector<Real> &final_heads, vector<Real> &residuals,
                    vector<Real> &flow_rates , int &num_nodes, int &num_pipes,
					bool &debug);
void process_reservoir(int &reservoir_node, Real &reservoir_head, bool &resolve, bool &debug);
void process_propties(array <int> &node_table, vector<Real> &lengths, 
                      vector<Real> &diameters, vector<Real> &hw_coeffs,
					  int &num_pipes, int &num_nodes, bool &resolve, bool &debug);
void process_parameters(array <int> &node_table, vector <Real> &lengths,
                         vector <Real> &diameters, vector <Real> &hw_coeffs,
				  int &num_pipes, int &num_nodes, bool &debug);
bool check_Len_diam_hw(int &LDH, bool &debug);
void process_Len_diam_hw(Real &length_value, Real &diam_value, 
                  Real &hz_w_value,int &num_nodes, int &LDH, bool &debug);
void process_node(array <int> &node_table, vector<Real> &lengths, 
                  vector<Real> &diameters, vector<Real> &hw_coeffs,
				  int &pipe_number,Real &length_value, Real &diam_value,
				  Real hz_w_value, int &num_pipes, int &num_nodes, bool &debug);
void user_trace( int, string );
void process_external( vector<Real> &external_flows, int &num_nodes,bool &resolve,
                       bool &debug);
void process_initial(vector<Real> &initial_heads, int &num_nodes, bool &resolve,
                     bool &debug);
void process_convergence( Real &tol, const Real min_tol, const Real max_tol,
                         bool &resolve, bool &debug);
void process_iterations(int &iter, const int min_iter, const int max_iter, bool &resolve,
                         bool &debug);
void process_solve(array <int> &node_table, vector<Real> &lengths,
                   vector<Real> &diameters, vector<Real> &hw_coeffs,
				   vector<Real> &external_flows, vector<Real> &initial_heads, 
				   vector<Real> &final_heads, vector<Real> &residuals,
				   vector<Real> &flow_rates,int &num_pipes, int &num_nodes,
				   int &reservoir_node, Real &reservoir_head,Real &maxr,
				   Real &tol,const Real min_tol, const Real max_tol,int &iter,
				   const int max_iter,bool &iter_limit, bool &data_fail,
				   bool &resolve, bool &output_reslt, bool &debug);
					
bool data_check(array <int> &node_table, vector<Real> &lengths,
                   vector<Real> &diameters, vector<Real> &hw_coeffs,
				   vector<Real> &external_flows, vector<Real> &initial_heads, 
				   vector<Real> &final_heads, vector<Real> &residuals,
				   vector<Real> &flow_rates,int &num_pipes, int &num_nodes,
				   int &reservoir_node, Real &reservoir_head,Real &tol,
				   const Real min_tol,const Real max_tol, int &iter,
  				   const int max_iter,bool &debug);
					
void solution_status( Real & maxr, int &kont, bool &debug);	
				
void process_solve_data(array <int> &node_table, vector<Real> &lengths,
         vector<Real> &diameters, vector<Real> &hw_coeffs,
		 vector<Real> &external_flows,vector<Real> &initial_heads,
		 vector <Real> &residuals,vector <Real> &frictn_ress,vector<int> &ipt,
		 vector<int> &link, int &num_pipes,int &num_nodes,int &reservoir_node,
		 Real &reservoir_head,Real &maxr,bool &debug);
					
void compute_fvec(array <int> &node_table, vector<Real> &lengths,vector<Real> &diameters, vector<Real> &hw_coeffs,
               vector<Real> &initial_heads,vector<Real> &external_flows,vector<Real> & frictn_ress,vector <Real> &residuals,
			   vector <Real> &residualsneg, vector<int> &ipt,
			   vector<int> &link, int reservoir_node,int num_nodes,  bool &debug);	
			   
void compute_f(array <int> &node_table, vector<Real> &lengths,vector<Real> &diameters,
               vector<Real> &hw_coeffs,vector<Real> &initial_heads,
			   vector<Real> &external_flows,vector<Real> &frictn_ress,
			   vector <Real> &residuals,vector <Real> &residualsneg, vector<int> &ipt,
			   vector<int> &link, int &node, int reservoir_node,int num_nodes,  bool &debug);
			   
void compute_jmat( array <int> &node_table, array <Real> &J,vector <Real> &beta, vector<Real> &lengths,vector<Real> &diameters, vector<Real> &hw_coeffs,
               vector<Real> &initial_heads,vector<Real> &frictn_ress,
			   vector<int> &ipt,
			   vector<int> &link, int reservoir_node,int num_nodes,  bool &debug);
void compute_j(array <int> &node_table, array <Real> &J,vector <Real> &beta, 
                vector<Real> &lengths,vector<Real> &diameters, vector<Real> &hw_coeffs,
                vector<Real> &initial_heads,vector<Real> &frictn_ress, vector<int> &ipt,
			    vector<int> &link, int &node, int reservoir_node,int num_nodes,  bool &debug);			   
					
int linear_solver( array<double> &a, vector<double> &x,
                     vector<double> &b, int neqns, bool debug );
					 

void compute_flows(array <int> &node_table, vector<Real> &lengths,
                   vector<Real> &diameters, vector<Real> &hw_coeffs,
				   vector<Real> &external_flows, vector<Real> &final_heads, 
				   vector<Real> &flow_rates,vector <Real> &frictn_ress,
				   int &num_pipes, int &num_nodes,int &reservoir_node, 
				   Real &reservoir_head,Real &maxr, bool &debug);					 
bool linkup(int num_branches, int num_nodes, bool debug,array<int> &node,vector<int> &ipt,
                    vector<int> &link );
			  
void process_output(array <int> &node_table, vector<Real> &lengths,vector<Real> &diameters,
                    vector<Real> &hw_coeffs,vector<Real> &external_flows, vector<Real> &initial_heads, 
					vector<Real> &final_heads, vector<Real> &flow_rates, vector<Real> &residuals,
					int &num_pipes,int &num_nodes,int &reservoir_node, Real &reservoir_head,
					Real &tol, int iter, Real &maxr, string &title, bool &iter_limit,bool &data_fail,
					bool &resolve, bool &output_reslt, bool &debug);
void process_output_data(array <int> &node_table, vector<Real> &lengths,
                         vector<Real> &diameters, vector<Real> &hw_coeffs,
					     vector<Real> &external_flows, vector<Real> &initial_heads,
					     int &num_pipes, int &num_nodes,int reservoir_node, int reservoir_head,
					     Real &tol, int iter, string &title, bool &debug);

void process_output_results(vector<Real> &final_heads,vector<Real> &flow_rates, 
                            vector<Real> &residuals,Real &maxr,int &num_nodes,
                            int &num_pipes,bool &resolve, bool &debug);
							
void vectors_free(vector<Real> &final_heads,vector<Real> &residuals,
                  vector<Real> &flow_rates, bool &debug);
void process_debug( bool &debug);
//