
#ifndef SCANLIB
#define SCANLIB 1
// 
// set flags for Windows (Visual C++) or Unix (C++,g++). There is one
// OS header file name different on the two systems. init_scan function
// uses this varible to include correct OS header
//
// #define WINDOWS
#define UNIX

// Definition of maximum record (line) length and maximum entity length
#define LINEWIDTH       81
#define TOKENLENGTH     80
// end of definition of maximum record length and maximum entity length

// ***************************************************
// *  Scan Library Function Prototypes               *
// *  (use static to hide from application programs  *
// ***************************************************

// Private functions
// -----------------

static void scan(void);

static bool isitem(const int &);

static void rdline(void);

static void scancl(void);

static void scanin(char *buff, int &reclen, int &errcod);

static void scanm(const int &errnum);

static void scanpk(void);

static void scanrd(void);

static void setin(const int &in);

static void wrnocr(const string& prompt);

static void scan_echo_line( int label, char * cardimage );


// end of private functions


// Public (documented) functions
// -----------------------------

void backsp(const int &nument);

void doscan(void);

bool endcrd( void );

bool endstr( void );

bool floatn( float &real );

void getstr( void );

void in_from_remote( void );

bool integr(int &integ);

void init_scan (const int  &nblank=LINEWIDTH,
                const int  &reclen=LINEWIDTH,
                const char &endchr = '$',
                const bool &promsw = true,
                const bool &echosw= true,
                const bool &comsw = true,
                const bool &atrdsw= false,
                const bool &eolsw = true,
                const bool &eofsw = false,
                const bool &signsw = false);

bool isstring(void);

void istrue(void);

bool label(void);

bool matchs(const string& cstr, const int &nc);

bool matchs_exact( const string& string );

bool name(void);

void noscan(void);

bool numd(double &double_prec);

bool numf(float &real);

bool numi(int &integr);

void open_input_file   (char fileid[], int &status);

void set_output_file( ofstream & user_output_file );

void out_to_remote();

void out_to_stdout();

void readsc (void);

void reset(void);

void scan_contents( char cstr[],int &nc );

void scan_contents( string &text ,int &nc);

void scandb(void);

bool sep(int &septyp);

void set_echo(const bool &echo_flag );

int sizlst ( const int list[], const int &nl );

void skpstr (void);

void trlist( int list[], const int &mlist, const int &iall,
             int &nlist, int &ierr );

void trxlst( int list[], const int &nlist, int &iplist,
             int &icn, int &next );

// End of Public functions

#endif












