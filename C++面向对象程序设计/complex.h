#ifndef __COMPLEX__
#define __COMPLEX__

#include <iostream>
class complex {
public:
    complex(double r = 0, double i = 0) : re(r), im(i) {}

    complex& operator+=(const complex &);

//    complex operator+(const complex &,const complex &);

    double real() const { return re; }

    double imag() const { return im; }

    friend complex& __doapl(complex *, const complex &);

private:
    double re, im;
};

inline complex& __doapl(complex* ths, const complex& r) {
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}

inline double
imag (const complex& x)
{
    return x.imag ();
}

inline double
real (const complex& x)
{
    return x.real ();
}


inline complex& complex::operator+=(const complex &r) {
    return __doapl(this, r);
}

inline complex operator +(const complex& x,const complex& y){
    return complex(real(x)+real(y),imag(x)+imag(y));
}

inline complex operator +(const complex& x,double y){
    return complex(real(x)+y,imag(x));
}

inline complex operator +(double x,const complex& y){
    return complex(x+real(y),imag(y));
}

//ostream& operator << (ostream& os,const complex& x){
//return os<<'('real(x)<<','<<imag(x)<<')';
//}
#endif