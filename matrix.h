#ifndef MATRIX_H
#define MATRIX_H

#include "vector.h"

class Matrix
{
    quint32 height;
    quint32 width;
    Vector **Lines;
public:
    Matrix();//
    Matrix(quint32,quint32);//
    Matrix(const Matrix&);//
    ~Matrix();//
    Matrix foo();//
    Matrix& operator=(const Matrix&);//
    friend Matrix operator~(Matrix);//
    friend Matrix operator+(const Matrix&, const Matrix&);//
    friend Matrix operator-(const Matrix&, const Matrix&);//
    friend Matrix operator*(const Matrix&, const Matrix&);
    friend Matrix operator-(Matrix);//
    Matrix operator+=(const Matrix&);//
    Matrix operator-=(const Matrix&);//
    Vector& operator[](quint32);//
    friend std::ostream& operator<<(std::ostream&,const Matrix&);//
};

#endif // MATRIX_H
