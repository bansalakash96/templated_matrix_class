#include "matrix.h"

int main(){


matrix <double> a(3,3,0);
a(0,0)=1;
a(0,1)=2;
a(0,2)=3;
a(1,0)=4;
a(1,1)=5;
a(1,2)=6;
a(2,0)=7;
a(2,1)=8;
a(2,2)=9;
cout << a<< endl;

matrix <double> b(3,3,0);
b(0,0)=5;
b(0,1)=6;
b(0,2)=7;
b(1,0)=-2;
b(1,1)=-4;
b(1,2)=-8;
b(2,0)=-9;
b(2,1)=-9;
b(2,2)=-8;
cout << b << endl;

cout <<"a+b "<<a+b <<endl;
cout <<"a-b "<<a-b <<endl;
cout <<"a*b "<<a*b <<endl;

complex c1(2,3),c2(5,6),c3(8,9),c4(-1,2);
matrix<complex> m(2,2,c1);
m(0,1)=c2;m(1,0)=c3;m(1,1)=c4;
cout << m << endl;

complex d1(-2,0),d2(-5,67),d3(-8,-9),d4(1,2);
matrix<complex> d(2,2,d1);
d(0,1)=d2;d(1,0)=d3;d(1,1)=d4;
cout << d << endl;

cout <<"m+d "<<m+d <<endl;
cout <<"m-d "<<m-d <<endl;
cout <<"m*d "<<m*d <<endl;

return 0;

}