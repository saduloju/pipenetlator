//*****************************************************************************
//*             CEE 691                                                       *
//*             project: Input Translator for PipeNetwork Simulator           *
//*             --------Prototype------------                                 *
//*             Author : Sunday Aduloju                                       *
//*             submitted to Prof. Dodds                                      *
//*             Last Modified: 3/25/2018                                      *
//*                                                                           *
//*****************************************************************************
typedef double Real;

void error_message(int);

void user_mess(int);

void read_project(array <int> &, vector<Real> &,vector<Real> &, vector<Real> &, 
				  vector<Real> &, vector<Real> &,int &,Real &,int &, string &,
				  bool);
				  
void process_number(array <int> &, vector<Real> &,vector<Real> &, vector<Real> &,
				  vector<Real> &, vector<Real> &,const int , const int ,int &,
				  int &,bool &, bool);
				  
void create_vectors(vector<Real> &, vector<Real> &,vector<Real> &, int &, int &,
				  bool);
				  
void process_reservoir(int &, Real &, bool &, bool);

void process_propties(array <int> &, vector<Real> &,vector<Real> &,
                  vector<Real> &,int &, int &, bool &, bool);
				  
void process_parameters(array <int> &, vector <Real> &,vector <Real> &,
                  vector <Real> &,int &, int &, bool);
				  
bool check_Len_diam_hw(int &, bool);

void process_Len_diam_hw(Real &, Real &, Real &,int &, int &, bool);

void process_node(array <int> &, vector<Real> &, vector<Real> &, vector<Real> &,
				  int &,Real &, Real &,Real, int &, int &, bool);
				  
void user_trace( int, string );

void process_external( vector<Real> &, int &,bool &,bool);

void process_initial(vector<Real> &, int &, bool &, bool);

void process_convergence( Real &, const Real, const Real,bool &, bool);

void process_iterations(int &, const int, const int, bool &, bool);

void process_solve(array <int> &, vector<Real> &,vector<Real> &, vector<Real> &,
				  vector<Real> &, vector<Real> &,vector<Real> &, vector<Real> &,
				  vector<Real> &,int , int ,int , Real ,Real &,Real ,
				  const Real, const Real,int &,const int,bool &, bool &,bool &,
				  bool &, bool);
	
bool data_check(array <int> &, vector<Real> &,vector<Real> &, vector<Real> &,
				  vector<Real> &, vector<Real> &,vector<Real> &, vector<Real> &,
				  vector<Real> &,int &, int &,int &, Real &,Real &,const Real,
				  const Real, int &,const int,bool);
					
void solution_status( Real , int , bool );	
				
void process_solve_data(array <int> &, vector<Real> &,vector<Real> &,
                  vector<Real> &,vector<Real> &,vector<Real> &,vector <Real> &,
				  vector <Real> &,vector<int> &,vector<int> &, int, int, int,
		          Real ,Real &,bool);

				  
void compute_fvec(array <int> &, vector<Real> &,vector<Real> &, vector<Real> &,
                  vector<Real> &,vector<Real> &,vector<Real> &,vector <Real> &,
			      vector <Real> &, vector<int> &,vector<int> &, int,int,  bool);	
			   
void compute_f(array <int> &, vector<Real> &,vector<Real> &,vector<Real> &,
                  vector<Real> &,vector<Real> &,vector<Real> &,vector <Real> &,
				  vector <Real> &, vector<int> &,vector<int> &, int &, int,int,
				  bool);
			   
void compute_jmat(array <int> &, array <Real> &,vector <Real> &, vector<Real> &,
                  vector<Real> &, vector<Real> &,vector<Real> &,vector<Real> &,
			      vector<int> &,vector<int> &, int,int,  bool);
				  
void compute_j(array <int> &, array <Real> &,vector <Real> &,vector<Real> &,
                  vector<Real> &, vector<Real> &,vector<Real> &,vector<Real> &,
				  vector<int> &,vector<int> &, int &, int,int, bool);			   
					
int linear_solver(array<double> &, vector<double> &,vector<double> &, int,bool);
					 
void compute_flows(array <int> &, vector<Real> &,vector<Real> &, vector<Real> &,
				  vector<Real> &, vector<Real> &,vector<Real> &,vector <Real> &,
				  int, int,int,Real, bool);
				  				   
bool linkup(int, int, bool,array<int> &node,vector<int> &ipt,vector<int> &);
			  
void process_output(array <int> &, vector<Real> &,vector<Real> &,vector<Real> &,
                  vector<Real> &, vector<Real> &,vector<Real> &, vector<Real> &,
				  vector<Real> &,int,int, int,Real, Real, int, Real &, string &,
				  bool &,bool &,bool &, bool &, bool);
					
void process_output_data(array <int> &, vector<Real> &,vector<Real> &,
                  vector<Real> &,vector<Real> &, vector<Real> &,int, int,int,
				  int,Real, int, string &, bool);

void process_output_results(vector<Real> &,vector<Real> &,vector<Real> &,
                  Real &,int,int, string &,bool &, bool);
							
void vectors_free(vector<Real> &,vector<Real> &,vector<Real> &, bool);

void process_debug( bool &debug);
//