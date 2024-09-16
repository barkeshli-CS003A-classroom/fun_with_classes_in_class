#include "fun.h"

  Counter::Counter(){
    bool debug = false;
    if (debug)
      cout << "Counter() fired" << endl;
    _count = 0;
  }
  Counter::Counter(int c):_count(c){
    bool debug = false;
    if (debug)
      cout << "Counter("<<c<<") fired" << endl;
    //blank!
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

  outs << '['<<setw(4)<<setfill('0')<<c._count<<" ]";
  return outs;
}


istream& operator>>(istream& ins, Counter& c){
  //    > 5/8
  char junk;
  ins >> c._count >> junk >> c.fake;
  return ins;
}
