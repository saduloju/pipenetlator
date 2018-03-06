//
// function prototypes
//void get_input_file_and_open(void);
//void get_values_from_file( string &, vector <double> &, int &);
//void compute_statistics( vector<double> &, int, double &, double &);
//void output_results( string,vector<double>&, int, double, double );
void error_message(int);
void process_nodal_data(array<double> &);
void process_nodal_loads(array<double> &);
void read_project();
void process_number(array <int> &node, vector<double> &length_vector,
                    vector<double> &diam_vector, vector<double> &hz_coeff_vector,
					vector<double> &flow_vector, vector<double> &ihead_vector, int &num_pipes, int &num_nodes);
void process_reservoir();
void process_propties(array <int> &node, vector<double> &length_vector, vector<double> &diam_vector, vector<double> &hz_coeff_vector, int &num_pipes, int &num_nodes);
void process_parameters(array <int> &node, vector <double> &length_vector,  vector <double> &diam_vector, vector <double> &hz_coeff_vector, int &num_pipes, int &num_nodes);
bool check_Len_diam_hw(int & );
void process_Len_diam_hw(double &length_value, double &diam_value, double &hz_w_value, int &LDH);
void process_node(array <int> &node, vector<double> &length_vector, vector<double> &diam_vector, vector<double> &hz_coeff_vector, int &pipe_number,
                   double &length_value,  double &diam_value,  double &hz_w_value, int num_pipes, int num_nodes);
void user_trace( int, string );
void process_external( vector<double> &flow_vector, int &num_nodes);
void process_initial();
void process_convergence();
void process_iterations();
void process_solve();
void process_output();
void process_output_data();
void process_output_results();
//