#include<iostream>
#include"complex.h"

using namespace std;


class Account {
public:
    static double m_rate;*
    static void set_rate(const double &x) {
        m_rate = x;
    }


};

double Account::m_rate = 8.0;

int main() {
    Account::set_rate(50);
    Account a;
    a.set_rate(7.0);

}




//
//
//int main() {
//    complex c1(2, 1);
//    complex c2 = complex(2, 1);
//    complex c3=c1+c2;
//    cout<<c3.imag()<<c3.real();
//
//
//}
