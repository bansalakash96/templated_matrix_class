#include<iostream>
#include<cmath>
using namespace std;

class complex  // Way to define set
{
 
public:  
    double real;
    double imaginary; 
complex(double a, double b){  //Constructor with 2 arguments
real = a;
imaginary =b;
}; 

complex(){  // Initialized Constructor without any arguments 
real =0.0;
imaginary=0.0;};

complex  (const complex &c1) // Copy Constructor
       {
real = c1.real;
imaginary =c1.imaginary;
}
      };
 
complex conjugate(complex c1){
    complex temp;
    temp.real      =  c1.real;
    temp.imaginary = -c1.imaginary;
    return temp;
}

/******MODULUS*****/
 double mod(complex c1){
    double temp;
   temp= sqrt(c1.real*c1.real + c1.imaginary*c1.imaginary); 
return temp;
 }     


/****SQUARE ROOT OF COMPLEX NUMBER****/
 complex sqrtcomplex(complex c1)
{
complex temp;

if(c1.imaginary==0 && c1.real>=0)
{ temp.real = sqrt(c1.real);
  temp.imaginary= 0;}

if(c1.imaginary==0 && c1.real<0)
{     temp.real = 0;  
      temp.imaginary= sqrt(-c1.real);}

if(c1.imaginary !=0)
{ 
      temp.real =  sqrt((mod(c1) + c1.real)/2);
 temp.imaginary =     (c1.imaginary/fabs(c1.imaginary))*sqrt((mod(c1) - c1.real)/2);}

return temp;
}




  complex operator + (complex c1, complex c2)
       {
            complex temp;
             temp.real = c1.real + c2.real;
           temp.imaginary = c1.imaginary + c2.imaginary;
           return temp;
       }


       complex operator + (complex c1, double c2)
       {
             complex temp;
             temp.real = c1.real + c2;
           temp.imaginary = c1.imaginary ;
           return temp;
       }

       complex operator + (double c1, complex c2)
       {
             complex temp;
             temp.real = c1 + c2.real;
           temp.imaginary = c2.imaginary;
           return temp;
       }

       complex operator - (complex c1, complex c2)
       {
             complex temp;
             temp.real = c1.real - c2.real;
           temp.imaginary = c1.imaginary - c2.imaginary;
           return temp;
       }

       complex operator - (complex c1, double c2)
       {
             complex temp;
             temp.real = c1.real - c2;
           temp.imaginary = c1.imaginary ;
           return temp;
       }


       complex operator - (double c1, complex c2)
       {
            complex temp;
             temp.real = c1 - c2.real;
           temp.imaginary = c2.imaginary;
           return temp;
       }


       complex operator * (complex c1, complex c2)
       {
             complex temp;
             temp.real = c1.real* c2.real-c2.imaginary* c1.imaginary;
           temp.imaginary = c1.real* c2.imaginary+c2.real* c1.imaginary;
           return temp;
       }

       complex operator / (complex c1, complex c2)
       {
             complex temp;
             temp.real = (c1.real* c2.real + c2.imaginary* c1.imaginary) / (pow(c2.real,2)+ pow(c2.imaginary,2))  ;
           temp.imaginary = (c2.real* c1.imaginary - c1.real* c2.imaginary) / (pow(c2.real,2)+ pow(c2.imaginary,2))  ;
           return temp;
       }


       complex operator * (complex c2,double c1) 
       {
             complex temp;
             temp.real = c1* c2.real;
           temp.imaginary = c1* c2.imaginary;
           return temp;
       }

       complex operator * (double c1,complex c2) 
       {
             complex temp;
             temp.real = c1* c2.real;
           temp.imaginary = c1* c2.imaginary;
           return temp;
       }      

       complex operator / ( complex c2,double c1)
       {
             complex temp;
             temp.real = c2.real / c1;
           temp.imaginary = c2.imaginary / c1;
           return temp;
       }


       complex operator / (double c1,complex c2)
       {
             complex temp;
             temp.real = c2.real / c1;
             temp.imaginary = c2.imaginary / c1;
            return temp;
       }      

  //istream is any valid input stream
  istream &operator>>(istream  &input,complex &z ) { 
 cout<<"enter the real and imaginary part"<<endl;
 input>> z.real;
 input>> z.imaginary;
return input;
}; 

//ostream is any valid output stream
ostream &operator<<(ostream  &output,const complex &z ) { 
    output<<z.real<<  std::showpos <<z.imaginary<<" I"<<" ";
return output;
}; 



 