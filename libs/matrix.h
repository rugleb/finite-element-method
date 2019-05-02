#ifndef MATRIX_H
#define MATRIX_H


#include <vector>
#include <iostream>


typedef std::vector<double> Vector;
typedef std::vector<Vector> Matrix;


void print(const Vector& v);
void print(const Matrix& m);

Vector gauss(const Matrix &m, const Vector& v);


#endif
