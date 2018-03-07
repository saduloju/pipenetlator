//
// function prototypes
//void get_input_file_and_open(void);
//void get_values_from_file( string &, vector <Real> &, int &);
//void compute_statistics( vector<Real> &, int, Real &, Real &);
//void output_results( string,vector<Real>&, int, Real, Real );
typedef double Real;

void error_message(int);
void process_nodal_data(array<Real> &);
void process_nodal_loads(array<Real> &);
void read_project(bool &debug);
void process_number(array <int> &node_table, vector<Real> &lengths,
                    vector<Real> &diameters, vector<Real> &hw_coeffs,
					vector<Real> &extermal_flows, vector<Real> &initial_heads, 
					int &max_pipes, int &max_nodes,
					int &num_pipes, int &num_nodes, int default_num, bool &debug);
void process_reservoir(bool &debug);
void process_propties(array <int> &node_table, vector<Real> &lengths, 
                      vector<Real> &diameters, vector<Real> &hw_coeffs,
					  int &num_pipes, int &num_nodes, bool &debug);
void process_parameters(array <int> &node_table, vector <Real> &lengths,
                        vector <Real> &diameters, vector <Real> &hw_coeffs,
						int &num_pipes, int &num_nodes, bool &debug);
bool check_Len_diam_hw(int &LDH, bool &debug);
void process_Len_diam_hw(Real &length_value, Real &diam_value, 
                         Real &hz_w_value, int &LDH, bool &debug);
void process_node(array <int> &node_table, vector<Real> &lengths, 
                 vector<Real> &diameters, vector<Real> &hw_coeffs,
				 int &pipe_number,Real &length_value, Real &diam_value,
				 Real &hz_w_value, int &num_pipes, int &num_nodes, bool &debug);
void user_trace( int, string );
void process_external( vector<Real> &extermal_flows, int &num_nodes,
                       bool &debug);
void process_initial( bool &debug);
void process_convergence( bool &debug);
void process_iterations(bool &debug);
void process_solve(bool &debug);
void process_output(bool &debug);
void process_output_data(bool &debug);
void process_output_results(bool &debug);
void process_debug( bool &debug);
//