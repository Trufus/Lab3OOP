#include <QCoreApplication>
#include "matrix.h"

using namespace std;

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    Matrix A(4,4);
    Matrix D(4,6);
    Matrix K(8,5);
    cout<<endl;

    Matrix* B = new Matrix(4,4);

    Matrix C(4,4);
    B->foo();
    D[1][3]=4;
    D[3][2]=10;
    D[1][1]=5;
    K[2][2]=11;
    K[1][3]=4;
    K[3][1]=2;
    A=*B;
    //C=-(~A);
    K[1][1]=17;
    D[2][1]=7;
    //cout<<A<<endl;
    //cout<<(A+(*B)-C)<<endl;
    cout<<endl;
    //A-=D;
    cout<<D<<endl;
    cout<<endl;
    cout<<K<<endl;
    cout<<endl;
    cout<<D*K<<endl;

    return 0;
    //return a.exec();
}
