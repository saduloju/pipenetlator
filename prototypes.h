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

void read_project(array <int> &, vector<Real> &,vector<Real> &, vector<Real> &, 
				  vector<Real> &, vector<Real> &,int &,Real &,int &, string &,
				  bool &);
				  
void process_number(array <int> &, vector<Real> &,vector<Real> &, vector<Real> &,
				  vector<Real> &, vector<Real> &,const int , const int ,int &,
				  int &,bool &, bool &);
				  
void create_vectors(vector<Real> &, vector<Real> &,vector<Real> &, int &, int &,
				  bool &);
				  
void process_reservoir(int &, Real &, bool &, bool &);

void process_propties(array <int> &, vector<Real> &,vector<Real> &, vector<Real> &,
				  int &, int &, bool &, bool &);
				  
void process_parameters(array <int> &, vector <Real> &,vector <Real> &,
                  vector <Real> &,int &, int &, bool &);
				  
bool check_Len_diam_hw(int &, bool &);

void process_Len_diam_hw(Real &, Real &, Real &,int &, int &, bool &);

void process_node(array <int> &, vector<Real> &, vector<Real> &, vector<Real> &,
				  int &,Real &, Real &,Real, int &, int &, bool &);
				  
void user_trace( int, string );

void process_external( vector<Real> &, int &,bool &,bool &);

void process_initial(vector<Real> &, int &, bool &, bool &);

void process_convergence( Real &, const Real, const Real,bool &, bool &);

void process_iterations(int &, const int, const int, bool &, bool &);

void process_solve(array <int> &, vector<Real> &,vector<Real> &, vector<Real> &,
				  vector<Real> &, vector<Real> &,vector<Real> &, vector<Real> &,
				  vector<Real> &,int &, int &,int &, Real &,Real &,Real &,
				  const Real, const Real,int &,const int,bool &, bool &,bool &,
				  bool &, bool &);
					
bool data_check(array <int> &, vector<Real> &,vector<Real> &, vector<Real> &,
				  vector<Real> &, vector<Real> &,vector<Real> &, vector<Real> &,
				  vector<Real> &,int &, int &,int &, Real &,Real &,const Real,
				  const Real, int &,const int,bool &);
					
void solution_status( Real &, int &, bool &);	
				
void process_solve_data(array <int> &, vector<Real> &,vector<Real> &,
                  vector<Real> &,vector<Real> &,vector<Real> &,vector <Real> &,
				  vector <Real> &,vector<int> &,vector<int> &, int &,int &,int &,
		          Real &,Real &,bool &);
					
void compute_fvec(array <int> &, vector<Real> &,vector<Real> &, vector<Real> &,
                  vector<Real> &,vector<Real> &,vector<Real> &,vector <Real> &,
			      vector <Real> &, vector<int> &,vector<int> &, int,int,  bool &);	
			   
void compute_f(array <int> &, vector<Real> &,vector<Real> &,vector<Real> &,
                  vector<Real> &,vector<Real> &,vector<Real> &,vector <Real> &,
				  vector <Real> &, vector<int> &,vector<int> &, int &, int,int,
				  bool &);
			   
void compute_jmat(array <int> &, array <Real> &,vector <Real> &, vector<Real> &,
                  vector<Real> &, vector<Real> &,vector<Real> &,vector<Real> &,
			      vector<int> &,vector<int> &, int,int,  bool &);
				  
void compute_j(array <int> &, array <Real> &,vector <Real> &,vector<Real> &,
                  vector<Real> &, vector<Real> &,vector<Real> &,vector<Real> &,
				  vector<int> &,vector<int> &, int &, int,int, bool &);			   
					
int linear_solver(array<double> &, vector<double> &,vector<double> &, int,bool);
					 
void compute_flows(array <int> &, vector<Real> &,vector<Real> &, vector<Real> &,
				  vector<Real> &, vector<Real> &,vector<Real> &,vector <Real> &,
				  int &, int &,int &,Real &,Real &, bool &);
				   
bool linkup(int, int, bool,array<int> &node,vector<int> &ipt,vector<int> &);
			  
void process_output(array <int> &, vector<Real> &,vector<Real> &,vector<Real> &,
                   vector<Real> &, vector<Real> &,vector<Real> &final_heads, vector<Real> &flow_rates, vector<Real> &residuals,
					int &num_pipes,int &num_nodes,int &reservoir_node, Real &reservoir_head,
					Real &tol, int iter, Real &maxr, string &title, bool &iter_limit,bool &data_fail,
					bool &resolve, bool &output_reslt, bool &debug);
void process_output_data(array <int> &, vector<Real> &lengths,
                         vector<Real> &diameters, vector<Real> &hw_coeffs,
					     vector<Real> &external_flows, vector<Real> &initial_heads,
					     int &num_pipes, int &num_nodes,int reservoir_node, int reservoir_head,
					     Real &tol, int iter, string &title, bool &debug);

void process_output_results(vector<Real> &final_heads,vector<Real> &flow_rates, 
                            vector<Real> &residuals,Real &maxr,int &num_nodes,
                            int &num_pipes,string &title,bool &resolve, bool &debug);
							
void vectors_free(vector<Real> &final_heads,vector<Real> &residuals,
                  vector<Real> &flow_rates, bool &debug);
void process_debug( bool &debug);
//