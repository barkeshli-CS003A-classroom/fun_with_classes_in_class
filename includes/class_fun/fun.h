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
  void add(Counter other);
  Counter add(const Counter &left, const Counter &right);
  friend Counter add(const Counter &left, const Counter &right);
  friend Counter operator+(const Counter &left, const Counter &right);
  friend Counter operator-(const Counter &left, const Counter &right);
  friend Counter operator*(const Counter &left, int m);
  friend ostream& operator<<(ostream& outs, const Counter& c);
  friend istream& operator>>(istream& ins, Counter& c);
  
  // accessors:
  int count();
  void print();

private:
  int _count;
  int _error;
};

#endif // BARKESHLI__FUN_H__
