#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include<iomanip>
#include <fstream>
using namespace std;
#include "complex.h"

 template<class dataType>
 class matrix
{
  public:
matrix(int nR, int nC, dataType scalar){

numRow = nR;
numCol = nC;
numElem = (nR)*(nC);
data = new dataType[(nR)*(nC)];
for(int row=0;row<nR;row++)
	for(int col=0;col<nC;col++)
		(*this)(row,col)= scalar;
}
 
~matrix()
  {
	   if (this->numElem > 0)
	   {
		    for(int i =0;i<numRow;i++)
          data[i].~dataType();
        delete  data; 
  }
  }
   
// copy constructor
matrix   (const matrix & tmp)	{	
    numRow  = tmp.numRow;
	numCol  = tmp.numCol;
	numElem = tmp.numElem;
	data = new dataType[numRow* numCol]; 	
	std::memcpy(data , tmp.data, numRow* numCol* sizeof(dataType));
	 
	}
	
	matrix & operator=(const matrix & tmp)	{	
    numRow  = tmp.numRow;
	numCol  = tmp.numCol;
	numElem = tmp.numElem;
	 
	 if (&tmp == this){
          return *this;
      }   
       
      for(int row=0;row<numRow;row++)
	for(int col=0;col<numCol;col++)
		(*this)(row,col)=tmp(row,col);
        return *this; 
	}
	
	 
  dataType& operator()(int row, int col){
return data[row * numCol + col];
}
const dataType operator()(int row, int col) const{
  
    return data[row * numCol + col];
}

int nRow() const{return numRow;}
int nCol()const{return numCol;}
 
  
matrix    operator/(const  dataType  &second)
{   matrix    result( nRow(),  nCol(),0.0);
          for (int i=0; i < nRow(); i++)
            for (int  j=0; j <  nCol(); j++)
               result(i,j)= (*this)(i, j) / second;
        return result;
}
	
matrix    operator*(const  dataType  &second)
{      matrix    result( nRow(),  nCol(),0.0);
          for (int i=0; i < nRow(); i++)
            for (int  j=0; j <  nCol(); j++)
               result(i,j)= (*this)(i, j) *second;
        return result;
}

 template<class T>
friend std::ostream& operator << (std::ostream& os, const matrix<T> m);
template<class T>
friend matrix<T>  operator+(const matrix<T>  &first, const matrix<T> &second);
template<class T>
friend matrix<T>  operator*(const matrix<T>  &first, const matrix<T> &second);

private:
  dataType *data; 
  int numElem;
  int numRow;
  int numCol;
 
};

   template<class dataType>
std::ostream& operator << (std::ostream& os, const matrix<dataType>  input)	{ 
os << "(" << input.nRow() << "x" << input.nCol() << ") matrix:";
	for (unsigned i= 0; i< input.nRow(); i++)
	{	os << std::endl;		// new row
		for (unsigned j= 0; j< input.nCol(); j++)
			os << std::setw(11) << std::right << input(i,j) << " " ;}
	return os;}
	
	
	template<class dataType>
	   matrix<dataType>   operator+(const matrix<dataType>  &first, const matrix<dataType>  &second)
    { dataType o;
       matrix<dataType>   result(first.nRow(), first.nCol(),o);
        for (int i=0; i <first.nRow(); i++)
            for (int  j=0; j < first.nCol(); j++)
                result(i, j) = first(i, j) + second(i, j);
        return result;
    }
	
	
	template<class dataType>
	   matrix<dataType>   operator-(const matrix<dataType>  &first, const matrix<dataType>  &second)
    {dataType o;
        matrix<dataType>   result(first.nRow(), first.nCol(),o);
        for (int i=0; i <first.nRow(); i++)
            for (int  j=0; j < first.nCol(); j++)
                result(i, j) = first(i, j) - second(i, j);
        return result;
    }
	
	
	template<class dataType>
	   matrix<dataType>   operator*(const matrix<dataType>  &first, const matrix<dataType>  &second)
    {
      dataType o;
        matrix<dataType>   result(first.nRow(), second.nCol(),o);
		 
        for (int i=0; i <result.nRow(); i++)
            for (int  j=0; j < result.nCol(); j++){
				result(i, j) = o;
				for (int  m=0; m < first.nCol(); m++)
                result(i, j) = result(i,j)+ first(i, m)*second(m, j);
			}
        return result;
    }


 
