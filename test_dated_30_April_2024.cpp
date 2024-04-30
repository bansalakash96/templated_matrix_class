#include "matrix.h"

int main(){

int n=5;

matrix <double> a(n,n,0.0);
matrix <double> b(n,n,0.0);

for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
	a(i,j) = i+j+1;
	b(i,j) = i+j+10.1;
	}
}

std::cout << "a is " << std::endl;
std::cout << a << std::endl;
std::cout << std::endl;

std::cout << "b is " << std::endl;
std::cout << b << std::endl;
std::cout << std::endl;

matrix <double> r1 = a-b;
std::cout << "r1=a-b is " << std::endl;
std::cout << r1 << std::endl;
std::cout << std::endl;

matrix <double> r2(n,n,0.0);
r2 = a+b;

std::cout << "r2=a+b is " << std::endl;
std::cout << r2 << std::endl;
std::cout << std::endl;

complex zero;
std::cout << "zero in complex is " << zero << std::endl;

matrix <complex> matrix_c1(n,n,zero);

std::cout << "matrix_c1 initialized with complex no. zero is " << std::endl;
std::cout << matrix_c1 << std::endl;
std::cout << std::endl;

for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
		matrix_c1(i,j).real = i*i + (j+1)*(j-1) + 0.4;
	}
}

std::cout << "matrix_c1 updated with real parts is " << std::endl;
std::cout << matrix_c1 << std::endl;
std::cout << std::endl;

for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
		matrix_c1(i,j).imaginary = (i+1)*(i-1) + j*j + 0.4;
	}
}

std::cout << "matrix_c1 updated with imaginary parts is " << std::endl;
std::cout << matrix_c1 << std::endl;
std::cout << std::endl;


matrix <complex> matrix_c2(n,n,zero);

std::cout << "matrix_c2 initialized with complex no. zero is " << std::endl;
std::cout << matrix_c2 << std::endl;
std::cout << std::endl;

for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){

		matrix_c2(i,j).real = i + (j+1)*(j-1) + 0.3;
		matrix_c2(i,j).imaginary = i + j + 0.1;		
	}
}

std::cout << "matrix_c2 is " << std::endl;
std::cout << matrix_c2 << std::endl;
std::cout << std::endl;



matrix <complex> matrix_c3 = matrix_c1 + matrix_c2;
matrix <complex> matrix_c4 = matrix_c1 - matrix_c2;
matrix <complex> matrix_c5 = matrix_c1 * matrix_c2;

std::cout << "matrix_c3 = matrix_c1 + matrix_c2 is " << std::endl;
std::cout << matrix_c3 << std::endl;
std::cout << std::endl;

std::cout << "matrix_c4 = matrix_c1 - matrix_c2 is " << std::endl;
std::cout << matrix_c4 << std::endl;
std::cout << std::endl;

std::cout << "matrix_c5 = matrix_c1 * matrix_c2 is " << std::endl;
std::cout << matrix_c5 << std::endl;
std::cout << std::endl;



	return 0;
}