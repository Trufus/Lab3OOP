#ifndef VECTOR_H
#define VECTOR_H
#include <QtCore>
#include <iostream>

class Vector
{
    quint32 length;
    qint32 *values;
public:
    Vector();
    Vector(quint32);
    Vector(const Vector&);
    ~Vector();
    Vector& operator=(const Vector&);
    friend Vector operator-(Vector);
    friend Vector operator+(const Vector&,const Vector&);
    friend Vector operator-(const Vector&,const Vector&);
    Vector operator+=(const Vector&);
    Vector operator-=(const Vector&);
    friend qint32 operator*(const Vector&,const Vector&);
    qreal operator()();
    qint32& operator[](quint32);
    friend std::ostream& operator<<(std::ostream&,const Vector&);
};

#endif // VECTOR_H
