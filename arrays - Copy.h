
template <class T> class vector
{
public:

  vector ()
    {
      _data = (T*)-1;
    }

  ~vector ()
    {
        if ( _data != (T*) -1 ) free();
    }

  void create(int lower, int upper)
   {
     _lower = lower;
     _upper = upper;
     _data  = new T[upper-lower+1];
   }

  int lower()
     {
        return _lower;
     }

  int upper() 
     {
        return _upper;
     }

  T& operator() ( int i ) 
     {
        return _data[i-_lower];
     }

  void free()
     {
        _lower = _upper = 0;
        delete [] _data;
        _data = (T*) -1;
     }

  private:
     int _lower;
     int _upper;
     T *_data;

}; 

template <class T> class array
{
public:

  array ()
    {
      _data = (T**) -1;
    }

  ~array ()
    {
      if ( _data != (T**) -1 ) free();
    }

  void create(int lower_0, int upper_0, int lower_1, int upper_1)
   {
     int i;
     _lower[0] = lower_0; 
     _lower[1] = lower_1;
     _upper[0] = upper_0;
     _upper[1] = upper_1;
     _data     = new T*[_upper[0] - _lower[0]+1];
     for ( i=0; i < _upper[0]-_lower[0]+1; i++ ) 
        _data[i] = new T[_upper[1] - _lower[1]+1];
   }	

   T& operator() (int i, int j)
      {
         return  _data[i-_lower[0]][j-_lower[1]]; 
      }

   int lower( int dimension) 
     { 
        return _lower[dimension];
     }

   int upper( int dimension )
     {
        return _upper[dimension]; 
     }

   void free()
    {
       int i;
       for ( i=0; i < _upper[0]-_lower[0]+1; i++ ) 
	 {  delete [] _data[i]; _data[i] = (T*) (-1);}
       delete [] _data;
       _data = (T**) (-1);
       _lower[0] = _lower[1] = _upper[0] = _upper[1] = 0;
    }

private:
	int _lower[2];
	int _upper[2];
	T **_data;
};

