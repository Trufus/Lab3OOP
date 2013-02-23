#include <QCoreApplication>
#include "matrix.h"

using namespace std;

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    Matrix A(3,5);
    Matrix D(3,5);

    cout<<endl;

    Matrix* B = new Matrix(3,5);

    Matrix C(4,4);
    B->foo();
    (*B)[3][2]=10;
    (*B)[1][1]=5;
    A=*B;
    C=-(~A);
    A[1][1]=17;
    D[2][2]=7;
    cout<<A<<endl;
    //cout<<(A+(*B)-C)<<endl;
    cout<<endl;
    A-=D;
    cout<<A<<endl;
    cout<<endl;
    cout<<C<<endl;

    return 0;
    //return a.exec();
}
