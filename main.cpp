#include <iostream>
#include <iomanip>
#include "includes/class_fun/fun.h"

using namespace std;
void print_counters(Counter c1, Counter c2){
    cout << "c1: ";
    c1.print();
    cout << ", and c2: ";
    c2.print();

}
int main(int argv, char** argc) {
    cout << "\n\n"
         << endl;

    Counter c1(10);
    Counter c2(5);

    //do not like the one arg add function.
    //  not intuitive
    c1.add(c2);
    c1.print();  //c1 is 15

    //now we have THREE args!
    c1.add(c1, c2);
    c1.print(); //25

    //much better with a friend func:
    //notice no self (this) object.
    Counter c3 = add(c1, c2);
    c3.print();


    //the best:
    c3 = c1 + c2;
    c3 = operator+(c1, c2);
    Counter c4 = c1 + c2 + c3;
    cout << "c4: ";
    c4.print();

    c4 = c3 + 100;
    cout << "c4 is now: "<<c4<<endl;
    
    //same thing, strange syntax
    // why doesn't this work? 
    //operator<<(operator<<(cout, c4), endl);

    
    c4 = c3 * 10;
    cout << "c4 is now: " << c4 << endl;
    
    c4 = c3 - c2;
    cout << "c4 is now: " <<c4 << endl;
    cout << "\n\n\n=====================" << endl;
    return 0;
}
void fun_with_classes(){
    Counter c1;
    Counter c2(5);
    cout << "here are your counters: " << endl;
    print_counters(c1, c2);
    cout << "incrementing counters: " << endl;
    cout << "---------" << endl;
    for (int i = 0; i < 7; i++){

        c1.inc();
        c2.inc();

        print_counters(c1, c2);
    }
    cout << "now, decrementing: " << endl;
    c1.dec();
    c2.dec();
    print_counters(c1, c2);
}