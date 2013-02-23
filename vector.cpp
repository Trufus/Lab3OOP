#include "vector.h"

Vector::Vector()
{
    length=0;
    values=NULL;
}

Vector::Vector(quint32 n)
{
    length=n;
    values = new qint32[n];
    for (quint32 i=0;i<n;i++)
    {
       values[i]=0;
    }
}

Vector::Vector(const Vector& V)
{
    length=V.length;
    values = new qint32[length];
    for (quint32 i=0;i<length;i++)
    {
       values[i]=V.values[i];
    }
}

Vector::~Vector()
{
    length=0;
    delete [] values;
}

Vector& Vector::operator=(const Vector& V)
{
    if (this!=&V)
    {
        delete [] values;
        length=V.length;
        values = new qint32[length];
        for (quint32 i=0;i<length;i++)
        {
            values[i]=V.values[i];
        }
     }
    return *this;
}

Vector operator-(Vector V)
{
    for (quint32 i=0;i<V.length;i++)
    {
        V.values[i]=(-V.values[i]);
    }
    return V;
}

quint32 min(quint32 a,quint32 b)
{
    if (a>b) return b;
    else return a;
}

Vector operator+(const Vector &V1,const Vector &V2)
{
    if (V1.length==V2.length)
    {
        Vector V3(V1.length);
        for (quint32 i=0;i<V1.length;i++)
        {
            V3.values[i]=V1.values[i]+V2.values[i];
        }
        return V3;
    }
    else
    {
        quint32 c=min(V1.length,V2.length);
        Vector V3(c);
        std::cout<<"Lengths are different"<<std::endl;
        for (quint32 i=0;i<c;i++)
        {
            V3.values[i]=V1.values[i]+V2.values[i];
        }
        return V3;
    }
}

Vector operator-(const Vector &V1,const Vector &V2)
{
    if (V1.length==V2.length)
    {
        Vector V3(V1.length);
        for (quint32 i=0;i<V1.length;i++)
        {
            V3.values[i]=V1.values[i]-V2.values[i];
        }
        return V3;
    }
    else
    {
        quint32 c=min(V1.length,V2.length);
        Vector V3(c);
        std::cout<<"Lengths are different"<<std::endl;
        for (quint32 i=0;i<c;i++)
        {
            V3.values[i]=V1.values[i]-V2.values[i];
        }
        return V3;
    }
}

Vector Vector::operator+=(const Vector& V)
{
    if (length==V.length)
    {
        for (quint32 i=0;i<V.length;i++)
        {
           values[i]+=V.values[i];
        }
        return *this;
    }
    else
    {
        quint32 c=min(length,V.length);
        std::cout<<"Lengths are different"<<std::endl;
        for (quint32 i=0;i<c;i++)
        {
           values[i]+=V.values[i];
        }
        return *this;
    }
}

Vector Vector::operator-=(const Vector& V)
{
    if (length==V.length)
    {
        for (quint32 i=0;i<V.length;i++)
        {
           values[i]-=V.values[i];
        }
        return *this;
    }
    else
    {
        quint32 c=min(length,V.length);
        std::cout<<"Lengths are different"<<std::endl;
        for (quint32 i=0;i<c;i++)
        {
           values[i]-=V.values[i];
        }
        return *this;
    }
}

qint32 operator*(const Vector &V1,const Vector &V2)
{
    qint32 S=0;
    if (V1.length==V2.length)
    {
        for (quint32 i=0;i<V1.length;i++)
        {
            S+=V1.values[i]*V2.values[i];
        }
        return S;
    }
    else
    {
        quint32 c=min(V1.length,V2.length);
        std::cout<<"Lengths are different"<<std::endl;
        for (quint32 i=0;i<c;i++)
        {
            S+=V1.values[i]*V2.values[i];
        }
        return S;
    }
}

qreal Vector::operator()()
{
    qint32 S=0;
    for (quint32 i=0;i<length;i++)
    {
            S+=values[i]*values[i];
    }
    return qSqrt(S);
}

qint32& Vector::operator[](quint32 i)
{
    if (i<length) return values[i];
    else
    {
        qint32 A;
        std::cout<<"Index>length"<<std::endl;
        return A;
    }
}

std::ostream& operator<<(std::ostream& out,const Vector &B)
{
    for (quint32 i=0;i<B.length;i++)
    {
        out<<B.values[i]<<" ";
    }
    return out;
}
