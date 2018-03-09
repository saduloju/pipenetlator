//
// function prototypes
//void get_input_file_and_open(void);
//void get_values_from_file( string &, vector <Real> &, int &);
//void compute_statistics( vector<Real> &, int, Real &, Real &);
//void output_results( string,vector<Real>&, int, Real, Real );
typedef double Real;

void error_message(int);
void read_project(array <int> &node_table, vector<Real> &lengths, 
                  vector<Real> &diameters, vector<Real> &hw_coeffs, 
				  vector<Real> &external_flows, vector<Real> &initial_heads,
				  int &counte, string &title, bool &debug);
void process_number(array <int> &node_table, vector<Real> &lengths,
                    vector<Real> &diameters, vector<Real> &hw_coeffs,
					vector<Real> &external_flows, vector<Real> &initial_heads, 
					const int max_pipes, const int max_nodes,
					int &num_pipes, int &num_nodes, bool &debug);
void process_reservoir(int &reservoir_node, Real &reservoir_head, bool &debug);
void process_propties(array <int> &node_table, vector<Real> &lengths, 
                      vector<Real> &diameters, vector<Real> &hw_coeffs,
					  int &num_pipes, int &num_nodes, bool &debug);
void process_parameters(array <int> &node_table, vector <Real> &lengths,
                        vector <Real> &diameters, vector <Real> &hw_coeffs,
						int &num_pipes, int &num_nodes, bool &debug);
bool check_Len_diam_hw(int &LDH, bool &debug);
void process_Len_diam_hw(Real &length_value, Real &diam_value, 
                         Real &hz_w_value,int &num_nodes, int &LDH, bool &debug);
void process_node(array <int> &node_table, vector<Real> &lengths, 
                 vector<Real> &diameters, vector<Real> &hw_coeffs,
				 int &pipe_number,Real &length_value, Real &diam_value,
				 Real &hz_w_value, int &num_pipes, int &num_nodes, bool &debug);
void user_trace( int, string );
void process_external( vector<Real> &external_flows, int &num_nodes,
                       bool &debug);
void process_initial(vector<Real> &initial_heads, int &num_nodes,
                     bool &debug);
void process_convergence( Real &tol, const Real min_tol, const Real max_tol, bool &debug);
void process_iterations(bool &debug);
void process_solve(bool &debug);
void process_output(array <int> &node_table, vector<Real> &lengths,
                    vector<Real> &diameters, vector<Real> &hw_coeffs,
					vector<Real> &external_flows, vector<Real> &initial_heads, 
					const int max_pipes, const int max_nodes,
					int &num_pipes, int &num_nodes,int reservoir_node, int reservoir_head,
					Real &tol,string &title, bool &debug);
void process_output_data(array <int> &node_table, vector<Real> &lengths,
                    vector<Real> &diameters, vector<Real> &hw_coeffs,
					vector<Real> &external_flows, vector<Real> &initial_heads, 
					const int max_pipes, const int max_nodes,
					int &num_pipes, int &num_nodes,int reservoir_node, int reservoir_head,
					Real &tol,string &title, bool &debug);
void process_output_results(bool &debug);
void process_debug( bool &debug);
//