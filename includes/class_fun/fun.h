#ifndef BARKESHLI__FUN_H__
#define BARKESHLI__FUN_H__

#include <iostream>
#include <iomanip>
#include <limits>
#include <cassert>
using namespace std;


class Counter{
public:
  //ctors:
  Counter();                      //default CTOR
  Counter(int c);
  Counter(char *name,int c);
  Counter(const Counter &other);  //copy CTOR
  ~Counter();                     //Destructor
  Counter &operator=(const Counter &RHS);
  // mutators:
  void inc();
  void dec();
  void set_name(char* name);
  void add(Counter other);
  
  //c1.add(c1, c2)
  Counter add(const Counter &left, const Counter &right);
  

  
  friend Counter add(const Counter &left, const Counter &right);
  friend Counter operator+(const Counter &left, const Counter &right);
  friend Counter operator-(const Counter &left, const Counter &right);
  friend Counter operator*(const Counter &left, int m);
  friend ostream& operator<<(ostream& outs, const Counter& c);
  friend istream& operator>>(istream& ins, Counter& c);
  
  char& operator[](int index){
    assert(index < strlen(_name) && "index cannot be larger than strig length");
    return _name[index];
  }
  char& at(int index){
    assert(index < strlen(_name));
    return _name[index];
  }
  // accessors:
  int count();
  void print();

private:
  char *_name;
  int _count;
  int _error;
};

#endif // BARKESHLI__FUN_H__
