#pragma once
#ifndef MYMATRIX_H
#define MYMATRIX_H
#include <iostream>
using namespace std;



//重点：操作符的重载
//用什么定义matrix
//回答引用和指针的区别
//私有类，公共类，友元函数
//作用域操作符 '::' 
template<class T>
class matrix {
	template<class T> friend ostream& operator<<(ostream&,const matrix<T>&);
	public:
		matrix(int theRow=0,int theColums=0);
		matrix(const matrix<T>&);
		~matrix() { delete[] element; }
		int rows() const { return theRows; } 
		/*如果把不改变数据成员的函数都加上const关键字进行标识，不但可提高程序的可读性
		  它还能提高程序的可靠性，已定义成const的成员函数，一旦企图修改数据成员的值，
		则编译器按错误处理。*/
		int columns() const { return theColumns; }
		T& operator()(int i, int j)const;
		matrix<T> transpose()const;
		matrix<T>& operator=(const matrix<T>&) const;
		matrix<T> operator+(const matrix<T>&) const;
		matrix<T> operator+() const;
		matrix<T> operator-(const matrix<T>&) const;
		matrix<T> operator-() const;
		matrix<T> operator*(const matrix<T>&) const;
		//matrix<T>& operator+=(const T&);
private:
	int theRows;
	int theColumns;
	T* element;
};

template<class T>
ostream& operator<<(ostream& out, const matrix<T>& m) {
	int rows = m.theRows;
	int columns = m.theColumns;
	int k = 0;
	out << "[";
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if(i==0&&j==0) out<<" "<<m.element[k++]<<" ";
			else out << " "<<" " << m.element[k++] << " ";
		}
		out << endl;
	}
	out << " " << "]" << endl;
	return out;
}
template<class T>
matrix<T>::matrix(int theRows, int theColumns){
	if (theRows < 0 || theColumns < 0)
		throw "Rows and Columns must be >=0";
	if ((theColumns == 0 || theRows == 0) && (theRows != 0 || theColumns != 0))
		throw "Either both or neither rows and colums should be zero";
	this->theRows = theRows;
	this->theColumns = theColumns;
	element = new T[theRows * theColumns];
}

template<class T>
matrix<T>::matrix(const matrix<T>& m) {
	theRows = m.theRows;
	theColumns = m.theColumns;
	element = new T[theRows * theColumns];
	copy(m.element, m.element + theRows * theColumns,element);
}

template<class T>
matrix<T>& matrix<T>::operator=(const matrix<T>& m) const {
	//赋值操作 *this
	if (this != &m) {
		delete[] element;
		theRows = m.theRows;
		theColumns = m.theColumns;
		element = new T[theRows*theColumns];
		copy(m.element,m.element+theRows*theColumns,element);
	}
	return *this;
}

template<class T>
matrix<T> matrix<T>::transpose() const {
	int m=theRows;
	int n = theColumns;
	matrix<T> w(n, m);
	int k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			w.element[k++] = element[i + j*theColumns];
		}
	}
	
	return w;
	
}

template<class T>
T& matrix<T>::operator()(int i, int j) const
{
	if (i<1 || i>theRows || j<1 || j>theColumns)
		throw "matrixIndexOutOfBounds";
	return element[(i - 1) * theColumns + j - 1];
}

template<class T>
matrix<T> matrix<T>::operator+(const matrix<T>& m) const
{
	//返回矩阵 w=（*this）+ m
	if (theRows != m.theRows || theColumns != m.theColumns)
		throw "matrixsize Mismatch";
	matrix<T> w(theRows, theColumns);
	for (int i = 0; i < theRows * theColumns;i++)
		w.element[i] = element[i] + m.element[i];
	return w;
}

template<class T>
matrix<T> matrix <T>::operator+() const
{
	matrix<T> w(theRows, theColumns);
	for (int i = 0; i < theRows * theColumns;i++)
		w.element[i] = element[i];
	return w;
}
template<class T>
matrix<T> matrix<T>::operator-(const matrix<T>& m) const
{
	//返回矩阵 w=（*this）+ m
	if (theRows != m.theRows || theColumns != m.theColumns)
		throw "matrixsize Mismatch";
	matrix<T> w(theRows, theColumns);
	for (int i = 0; i < theRows * theColumns;i++)
		w.element[i] = element[i] - m.element;
	return w;
}

template<class T>
matrix<T> matrix<T>::operator-() const {
	matrix<T> w(theRows, theColumns);
	for (int i = 0; i < theRows * theColumns; i++)
		w.element[i] = -element[i];
	return w;
}


template<class T>
matrix<T> matrix<T>::operator*(const matrix<T>& m) const
{
	if (theColumns != m.theRows)
		throw "matrixszie mismatch";
	matrix<T> w(theRows,m.theColumns);
	//initialize 1-1
	//A[i][k]*B[k][j]
	//ct是第i行的第一个元素 
	//cm是第j列的第一个元素 
	int ct = 0, cm = 0, cw = 0; 
	for (int i = 1; i <= theRows; i++)
	{
		for (int j = 1; j <= m.theColumns; j++) {
			T sum = element[ct] * m.element[cm];
			for (int k = 2; k <=theColumns; k++) {
				ct++;
				cm += m.theColumns;
				sum += element[ct] * m.element[cm];
			}
			w.element[cw++] = sum;
			ct -=theColumns - 1;
			cm = j;
		}
		ct += theColumns;
		cm = 0;
		
	}
	return w;
}


#endif