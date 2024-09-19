#include "fun.h"
//===========================================================
//                  C T O R S
//===========================================================

  Counter::Counter(){
    bool debug = false;
    if (debug)
      cout << "Counter() fired" << endl;
    _count = 0;
    _error = 0;
  }
  Counter::Counter(int c):_count(c),_error(0){
    bool debug = false;
    if (debug)
      cout << "Counter("<<c<<") fired" << endl;
    
    //blank!
  }

  Counter::Counter(char* name, int c):_count(c),_error(0){
    bool debug = false;
    if (debug)
      cout << "Counter("<<c<<") fired" << endl;
    //_name = name;
    _name = new char[INT_MAX];
    strcpy(_name, name);
    }
//====================== BIG THREE =====================================

  Counter::~Counter(){
    cout << "~Counter() fired!" << endl;
    delete[] _name;
  }
  
  Counter &Counter::operator=(const Counter &RHS){

    /*
      Counter c1;
      Counter c2(4);
      c1 = c2; //c1 exists before this line
      c1(c2);  //can this be done?
    */
   if (this == &RHS){
     return *this;
   }
    delete[] _name; //clean up the allocated space
    // allocate new space;
    _count = RHS._count;
    _error = RHS._error;
    _name = new char[INT_MAX];
    strcpy(_name, RHS._name);

    return *this;
  }

  Counter::Counter(const Counter &other){
    /*
      Counter c1(4);
      Counter c2 = c1;
      Counter c3(c1);
    */
    cout << "Copy CTOR CALLED" << endl;
    _count = other._count;
    _error = other._error;
    _name = new char[INT_MAX];
    strcpy(_name, other._name);
  }


    //mutators:
  void Counter::inc(){
    bool debug = false;
    if (debug)
      cout << "Counter::inc() fired" << endl;
    _count++;
  }
  void Counter::dec(){
    bool debug = false;
    if (debug)
      cout << "Counter::dec() fired" << endl;
    _count--;
  }
  void Counter::set_name(char* name){
    strcpy(_name, name);
  }
  //accessors:
  int Counter::count(){
    bool debug = false;
    if (debug)
      cout << "Counter::count() fired" << endl;
    return _count;
  }
  void Counter::print(){
    bool debug = false;
    if (debug)
      cout << "print() fired" << endl;
    cout <<setw(3)<< _count<<" ";
  }


//================ add() variations: ====================================

  void Counter::add(Counter other){
    //other's _count is private, but is accessible to 'me' in 
    //  this function because we are inside of the class.
    //  noted by Counter::
    _count += other._count;

  }
  Counter Counter::add(const Counter &left, const Counter &right){

    int count = left._count + right._count;
    Counter return_me(count);
    return return_me;

    //shorter version:
    Counter c(left._count + right._count);
    return c;

    //for TV hacker:
    return Counter(left._count + right._count);

    // bad: bypasses the ctor: REALLY bad idea
    Counter c1;
    c1._count = left._count + right._count;
    return c1;
  }

Counter add(const Counter &left, const Counter &right){
  // friend function has access to all private member variables
  //   and functions of the class:
  // notice the absence of Counter::
  // and notice the absence of a 'this' object in the call:
  // no need for c3.add(c1, c2); can simply do: add(c1, c2)
  Counter c(left._count + right._count);
  return c;
}


//===========================================================
//                  O P E R A T O R S
//===========================================================
  //overloaded + operator:
 Counter operator+(const Counter &left, const Counter &right){
   return add(left, right);
 }
Counter operator-(const Counter &left, const Counter &right){
  Counter c = left + right * -1;

  // //------------------------------------
  //Counter c(left + right * -1);
  // or...
  // Counter c_1 = left + right * -1;
  // Counter c = c_1;  //built in copy constructor:
  //                   //constructs one object based on another.
  // Counter c(c_1);   //alternate syntax
  // //------------------------------------

  return c;
}
Counter operator*(const Counter &left, int m){
  Counter c(left._count * m);
  return c;
}



ostream& operator<<(ostream& outs, const Counter& c){
  /*
    ostream cout; //in std namespace

    cout<<c;
    operator <<(cout, c);
    operator <<(ostream&, Counter)
    ---------
    x();
    cout<<"======"<<endl;
    y = x();
    cout<<"======"<<endl;

  */
  outs << '{'<<c._name<<": "<<'['<<setw(4)<<setfill('0')<<c._count<<", "<<c._error<<" ] } ";
  return outs;
}


istream& operator>>(istream& ins, Counter& c){
  //    > 5/8
  char junk;
  ins >> c._count >> junk >> c._error;
  return ins;
}
