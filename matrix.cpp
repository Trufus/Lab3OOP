#include "matrix.h"

Matrix::Matrix()
{
    width=0;
    height=0;
    Lines = NULL;
}

Matrix::Matrix(quint32 W, quint32 H)
{
    width=W;
    height=H;
    Lines = new Vector* [H];
    for (quint32 i=0;i<H;i++)
    {
        Lines[i] = new Vector(W);
    }
    /*for (quint32 i=0;i<H;i++)
    {
        std::cout<<(*Lines[i])<<std::endl;
    }*/
}

Matrix::Matrix(const Matrix& M)
{
    width=M.width;
    height=M.height;
    Lines = new Vector* [height];
    for (quint32 i=0;i<height;i++)
    {
        Lines[i] = new Vector(width);
    }

    for (quint32 i=0;i<height;i++)
    {
        for (quint32 j=0;j<width;j++)
            (*Lines[i])[j]=(*M.Lines[i])[j];
    }
    /*for (quint32 i=0;i<height;i++)
    {
        std::cout<<(*Lines[i])<<std::endl;
    }*/
}

Matrix::~Matrix()
{
    for (quint32 i=0;i<height;i++)
    {
        delete Lines[i];
    }
    delete [] Lines;
    width=0;
    height=0;
}

Matrix Matrix::foo()
{
    return *this;
}

Matrix& Matrix::operator= (const Matrix &M)
{
    if (this!=&M)
    {
        for (quint32 i=0;i<height;i++)
        {
            delete Lines[i];
        }
        delete [] Lines;

        height=M.height;
        width=M.width;
        Lines = new Vector*[height];
        for (quint32 i=0;i<height;i++)
        {
            Lines[i] = new Vector(width);
        }
        for (quint32 i=0;i<height;i++)
        {
            for (quint32 j=0;j<width;j++)
            {
                (*Lines[i])[j]=(*M.Lines[i])[j];
            }
        }

     }
    return *this;
}

Vector& Matrix::operator[](quint32 i)
{
    if (i<height) return *(Lines[i]);
    else
    {
        Vector A;
        std::cout<<"Index>height"<<std::endl;
        return A;
    }
}

std::ostream& operator<<(std::ostream& out,const Matrix& M)
{
    for (quint32 i=0;i<M.height;i++)
    {
        out<<*M.Lines[i]<<std::endl;
    }
    return out;
}

Matrix operator~(Matrix M)
{
    Matrix N(M.height,M.width);
    for (quint32 i=0;i<M.height;i++)
    {
        for (quint32 j=0;j<M.width;j++)
        {
            N[j][i]=M[i][j];
        }
    }
    return N;
}

Matrix operator-(Matrix M)
{
    for (quint32 i=0;i<M.height;i++)
    {

            M[i]=-M[i];
    }
    return M;
}

quint32 min(quint32 a,quint32 b);

Matrix operator+(const Matrix &M1,const Matrix &M2)
{
    if (M1.height==M2.height)
    {
        Matrix M3(M1.width,M1.height);
        for (quint32 i=0;i<M1.height;i++)
        {
            *M3.Lines[i]=*M1.Lines[i]+*M2.Lines[i];
        }
        return M3;
    }
    else
    {
        quint32 c=min(M1.height,M2.height);
        Matrix M3(M1.width,c);
        std::cout<<"Heights are different"<<std::endl;
        for (quint32 i=0;i<c;i++)
        {
            *M3.Lines[i]=*M1.Lines[i]+*M2.Lines[i];
        }
        return M3;
    }
}

Matrix operator-(const Matrix &M1,const Matrix &M2)
{
    if (M1.height==M2.height)
    {
        Matrix M3(M1.width,M1.height);
        for (quint32 i=0;i<M1.height;i++)
        {
            *M3.Lines[i]=*M1.Lines[i]-*M2.Lines[i];
        }
        return M3;
    }
    else
    {
        quint32 c=min(M1.height,M2.height);
        Matrix M3(M1.width,c);
        std::cout<<"Heights are different"<<std::endl;
        for (quint32 i=0;i<c;i++)
        {
            *M3.Lines[i]=*M1.Lines[i]-*M2.Lines[i];
        }
        return M3;
    }
}

Matrix Matrix::operator+=(const Matrix& M)
{
    if (M.height==height)
    {
        for (quint32 i=0;i<height;i++)
        {
           *Lines[i]+=*(M.Lines[i]);
        }
        return *this;
    }
    else
    {
        quint32 c=min(height,M.height);
        std::cout<<"Heights are different"<<std::endl;
        for (quint32 i=0;i<c;i++)
        {
           *Lines[i]+=*(M.Lines[i]);
        }
        return *this;
    }
}

Matrix Matrix::operator-=(const Matrix& M)
{
    if (M.height==height)
    {
        for (quint32 i=0;i<height;i++)
        {
           *Lines[i]-=*(M.Lines[i]);
        }
        return *this;
    }
    else
    {
        quint32 c=min(height,M.height);
        std::cout<<"Heights are different"<<std::endl;
        for (quint32 i=0;i<c;i++)
        {
           *Lines[i]-=*(M.Lines[i]);
        }
        return *this;
    }
}
