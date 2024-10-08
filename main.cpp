#include <iostream>
#include <iomanip>
#include "includes/class_fun/fun.h"

void operators();
void print_counters(Counter c1, Counter c2);
void fun_with_classes();
void bogus();
void default_ctor_assign();
void pass_object(Counter c);
void force_destructor();
void change_here(Counter& counter, int i, char c);
void whats_here(const Counter& counter, int i);
using namespace std;

int main(int argv, char **argc)
{
    Counter c("abcdef", 5);
    cout << c << endl;
    change_here(c, 2, 'z');
    cout << c << endl;

    cout << "\n\n\n=====================" << endl;
    return 0;
}
void whats_here(const Counter& counter, int i){
    cout << counter[i] << endl;
}
void change_here(Counter& counter, int i, char c){

    cout<< "c at position "<<i<< " is "<< counter[i] << endl;
    counter[i] = c;
}
void bracket_at(){
    Counter c("ABCDE", 4);
    cout << c << endl;
    cout << "c at 0: " << c[0] << endl;
    cout << "c at 3: " << c[3] << endl;
    //test assert: 
    //cout << "c at 30: " << c[30] << endl;
    c.at(1) = 'b';
    c[3] = 'd';
    cout << c << endl;

}
void assignment(){
    Counter c1("c1", 10);
    Counter c2("c2", 5);
    int i = 0;
    c1 = c1;            //self assignment
    while (i++ < INT_MAX)
    {
         // crashes with no destructor
        {
            c1 = c2;                //repeated assignment test...
            cout << "(" << i << "/" << INT_MAX << ") " << c1 << "  " << c2 << endl;
        }
    }
}
void assign_copy_ctor(){
    Counter c5("c5", 11);   //c5: //["X6000", 11]
    // Counter c6(c5);         //c6: //["X6000", 11]
    Counter c6 = c5;
    cout << "c5: " << c5 << endl;
    cout << "c6" << c6 << endl;
    c6 = c5;    //assignment: NOT COPY CTOR!
    cout << "c5: " << c5 << endl;
    cout << "c6" << c6 << endl;

}

void pass_object(Counter c){
    cout << "pass_object(" << c << ")" << endl;
}


void force_destructor(){
    cout << "\n\n"<< endl;
    int i = 0;
    // {
    //     Counter c5("c5", 5);
    //     cout << c5 << endl;
    // }
    while (i++ < INT_MAX)
    {
         // crashes with no destructor
        {
        Counter c1("c1", 10);
        Counter c2("c2", 5);
        bogus();
        cout <<"("<<i<<"/"<<INT_MAX<<") " << c1 << "  " << c2 << endl;
        }
    }
    //----------------
    Counter c6;
    
}
void default_ctor_assign(){

    Counter c1(10);
    Counter c2(5);
    bogus();
    cout << "enter c1: ";
    cin >> c1;
    cout << c1 << "  " << c2 << endl;

    //exactly the same: Calls Copy CTOR:
    Counter c3(c1);
    Counter c4 = c1;
    cout << "c3: " << c3 <<", c4: "<<c4<< endl;
    //- - - -


    //NOT the same as those other two.
    //Here the object already exists.
    //And you are assigning it to another
    //object.

    Counter c5(7);
    cout << "c5: " << c5 << endl;
    c5 = c1;
    cout << "c5 after assignment: " << c5 << endl;

}
void bogus(){
    int i = 6;
    int j = 12;
    int a[20] = {2, 3, 5, 6};
    int size = 4;
    cout << "bogus(): i: " << i << ",j: " << j << endl;
}

void operators(){
    //do not like the one arg add function.
    //  not intuitive

    Counter c1(10);
    Counter c2(5);
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
}

void print_counters(Counter c1, Counter c2){
    cout << "c1: ";
    c1.print();
    cout << ", and c2: ";
    c2.print();

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

int int_and_char_arrays(){
    int scores[100] = {90, 95, 97};
    cout << "here are the scores: " << scores << endl;
    char name[25];
    cout << ":";
    cin >> name;
    cout << name << endl;
    ;
    return 0;
}
