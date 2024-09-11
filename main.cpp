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
    cout << "\n\n\n=====================" << endl;
    return 0;
}
