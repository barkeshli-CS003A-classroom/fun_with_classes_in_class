#ifndef BARKESHLI__FUN_H__
#define BARKESHLI__FUN_H__

#include <iostream>
#include <iomanip>
using namespace std;


class Counter{
public:
  //ctors:
  Counter();
  Counter(int c);
  //mutators:
  void inc();
  void dec();

  //accessors:
  int count();
  void print();

private:
  int _count;

};

#endif // BARKESHLI__FUN_H__
