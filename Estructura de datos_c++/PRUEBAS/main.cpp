#include <iostream>


using namespace std;

int main()
{
    int mVieja = 3,nVieja = 3;
    double **aux;
    aux = new double *[mVieja];
    aux[0] = new double [mVieja*nVieja];
    for(int i = 1; i < mVieja; ++i) {
            aux[i] = aux[i-1] + nVieja;
    cout << endl;
    }
    for(int i = 0; i < mVieja; ++i){
        for(int j = 0; j < nVieja; ++j)
            cout << "   " << aux[i][j];
        cout << endl;
    }


    for(int i = 0; i < mVieja; ++i)
        for(int j = 0; j < nVieja; ++j)
            aux[i][j] = 1;

    for(int i = 0; i < mVieja; ++i){
        for(int j = 0; j < nVieja; ++j)
            cout << "   " << aux[i][j];
        cout << endl;
    }
    cout << endl;
//*******************************
    int m = 2, n = 5;
    double arreglo[m][n];
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            arreglo[i][j] = 0;

    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j)
            cout << "   " << arreglo[i][j];
        cout << endl;
    }
    cout << endl;
//*********************************************
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < nVieja; ++j){
            arreglo[i][j] = aux[i][j];
        }

    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j)
            cout << "   " << arreglo[i][j];
        cout << endl;
    }
    cout << endl;

        int a = 0;
        for(int i = 0; i < m; ++i)
            for(int j = nVieja; j < n; ++j){
                arreglo[i][j] = 2;
                ++a;
            }
//        for(int i = mVieja; i < m; ++i)
//            for(int j = 0; j < n; ++j){
//                arreglo[i][j] = 2;
//
//            }

            for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j)
            cout << "   " << arreglo[i][j];
        cout << endl;
    }
    cout << a << endl;
    cout << endl;
    delete [] aux[0];
    delete [] aux;
    return 0;
}
