#include "fun.h"

  Counter::Counter(){
    bool debug = true;
    if (debug)
      cout << "Counter() fired" << endl;
    _count = 0;
  }
  Counter::Counter(int c):_count(c){
    bool debug = true;
    if (debug)
      cout << "Counter("<<c<<") fired" << endl;
    //blank!
  }
  //mutators:
  void Counter::inc(){
    bool debug = true;
    if (debug)
      cout << "Counter::inc() fired" << endl;
    _count++;
  }
  void Counter::dec(){
    bool debug = true;
    if (debug)
      cout << "Counter::dec() fired" << endl;
    _count--;
  }

  //accessors:
  int Counter::count(){
    bool debug = true;
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
