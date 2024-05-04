/*
Nombre: main.cpp
Autor: Marco Antonio Guerrero Vasquez // 219202704
Fecha: 05/02/2021
Descripción: Programa que hace operaciones basicas con matrices
*/
#include <iostream>
#include "Matriz.h"
using namespace std;
void GestionMenuMatrices(int eleccion);

int main()
{
    try{
        Matriz m(3,3,0);
        cout << m << endl;
        cout << m++ << endl;
        cout << m << endl;

//        enum opciones {salir = 0, sumar, restar, productoEscalar,
//        productoMatriz, cambiarElemento, transpuesta, inversa,
//        redimensionar };
//
//        int eleccion = 0;
//        do{
//            cout << "MATRICES - ESTRUCTURA DE DATOS" << endl;
//            cout << "\250Que desea hacer?" << endl;
//            cout << "Sumar -------------- 1" << endl;
//            cout << "Restar ------------- 2" << endl;
//            cout << "Producto x Escalar - 3" << endl;
//            cout << "Producto x Matriz -- 4" << endl;
//            cout << "Cambiar Elemento --- 5" << endl;
//            cout << "Transpuesta -------- 6" << endl;
//            cout << "Inversa ------------ 7" << endl;
//            cout << "Redimensionar ------ 8" << endl;
//            cout << "Salir -------------- 0" << endl;
//            do{
//                cout << "Elecci\242n[0-8]: ";
//                cin >> eleccion;
//                if(eleccion < 0 || eleccion > 8)
//                cout << "Elecci\242n fuera de rango" << endl;
//            }while(eleccion < 0 || eleccion > 8);
//
//            GestionMenuMatrices(eleccion);
//            system("cls");
//
//        }while(eleccion != 0);
//
    }catch(out_of_range &exc){
        cerr << "\nError: " << exc.what() << endl << endl;
    }catch(logic_error &exc){
        cerr << "\nError: " << exc.what() << endl;
    }catch(bad_alloc &exc){
        cerr << "\nError: Falla en la asignaci\242n de memoria" << endl;
    }


    cout << "\n\n\n";
    return 0;
}
//
//void GestionMenuMatrices(int eleccion){
//    try{
//        switch(eleccion) {
//        case 1:
//        {
//            cout << "Se proceder\240 a sumar dos Matrices..." << endl;
//
//
//            int filas, columnas;
//            cout << "Cantidad de Filas(m): ";
//            cin >> filas;
//            cout << "\nCantidad de columnas(n): ";
//            cin >> columnas;
//            Matriz a(filas,columnas), b(filas, columnas), c;
//            cout << "\nLo siquiente es ingresar los datos de la primer Matriz." << endl;
//            cin >> a;
//            cout << "\nAhora los datos de la segunda Matriz." << endl;
//            cin >> b;
//
//
//            //Sumamos ambos.
//            c = a+b;
//            //Mostramos el resultado.
//            cout << "La suma de las Matrices se muestra a continuaci\242n:\n\n ";
//
//            cout << "Matriz A = " << endl << a << endl;
//            cout << "Matriz B = " << endl << b << endl;
//            cout << "Matriz A + B = " << endl << c << endl;
//            system("pause");
//            break;
//        }
//        case 2:
//        {
//            cout << "Se proceder\240 a restar dos Matrices..." << endl;
//
//
//            int filas, columnas;
//            cout << "Cantidad de Filas(m): ";
//            cin >> filas;
//            cout << "\nCantidad de columnas(n): ";
//            cin >> columnas;
//            Matriz a(filas,columnas), b(filas, columnas), c;
//            cout << "\nLo siquiente es ingresar los datos de la primer Matriz." << endl;
//            cin >> a;
//            cout << "\nAhora los datos de la segunda Matriz." << endl;
//            cin >> b;
//
//
//            //Restamos ambos.
//            c = a-b;
//            //Mostramos el resultado.
//            cout << "La resta Matrices se muestra a continuaci\242n:\n\n ";
//
//            cout << "Matriz A = " << endl << a << endl;
//            cout << "Matriz B = " << endl << b << endl;
//            cout << "Matriz A - B = " << endl << c << endl;
//            system("pause");
//            break;
//        }
//        case 3:
//        {
//            cout << "Se proceder\240 al producto Matriz x Escalar..." << endl;
//
//
//            int filas, columnas;
//            double escalar;
//            cout << "Cantidad de Filas(m): ";
//            cin >> filas;
//            cout << "\nCantidad de columnas(n): ";
//            cin >> columnas;
//            Matriz a(filas,columnas), b;
//            cout << "\nLo siquiente es ingresar los datos de la Matriz." << endl;
//            cin >> a;
//            cout << "Ahora el escalar: ";
//            cin >> escalar;
//
//            //Multiplicamos ambos.
//            b = a*escalar;
//            //Mostramos el resultado.
//            cout << "El producto Matriz x Escalar se muestra a continuaci\242n:\n\n ";
//            cout << "Matriz A = " << endl << a << endl;
//            cout << "Matriz (A)" << escalar << "= " << endl << b << endl;
//            system("pause");
//            break;
//        }
//        case 4:
//        {
//            int filasM1, n1m2, columnasM2;
//            cout << "Se proceder\240 a calcular el producto entre Matrices..." << endl;
//            cout << "N\243mero de Filas de la Matriz 1 (m): ";
//            cin >> filasM1;
//            cout << "\nN\243mero de Columnas de la Matriz 1(n): ";
//            cin >> n1m2;
//            Matriz a(filasM1,n1m2);
//            cout << "\nEl n\243mero de columnas de la primer matriz(n) son igual" << endl;
//            cout << "al n\243mero de filas de la segunda matriz(m): " << n1m2 << endl;
//            cout << "Ingrese el n\243mero de columnas de la seguna Matriz: ";
//            cin >> columnasM2;
//            Matriz b(n1m2, columnasM2);
//
//            cout << "\n Ahora ingrese los datos de la primer matriz:" << endl;
//            cin >> a;
//            cout << "\n Ahora ingrese los datos de la segunda matriz:" << endl;
//            cin >> b;
//
//            Matriz c;
//            c = a*b;
//            //Mostramos el resultado.
//            cout << "El producto de Matrices se muestra a continuaci\242n:\n\n ";
//            cout << "Matriz A = " << endl << a << endl;
//            cout << "Matriz B = " << endl << b << endl;
//            cout << "Matriz A x B = " << endl << c << endl;
//            system("pause");
//            break;
//
//        }
//        case 5:
//        {
//            cout << "Se cuenta con una Matriz de orden 3x3: " << endl;
//            Matriz a(3,3);
//            int x = 0;
//            for(int i = 0; i < a.ObtenerFilas(); ++i)
//                for(int j = 0; j < a.ObtenerColumnas(); ++j)
//                    a[i][j] = ++x;
//            cout << a << endl;
//            cout << "\nIngrese la fila y la columna del elemento a cambiar [1-3].." << endl;
//            cout << "Fila: ";
//            int fila;
//            cin >> fila;
//            cout << "\nColumna: ";
//            int columna;
//            cin >> columna;
//            cout << "\nIngrese el valor del elemento a cambiar: ";
//            double elemento;
//            cin >> elemento;
//            a[fila-1][columna-1] = elemento;
//            cout << "\nMatriz con el elemento [" << fila << "][" << columna <<"] cambiado: ";
//            cout << endl << a;
//            system("pause");
//            break;
//        }
//        case 6:
//        {
//            cout << "Se proceder\240 a calcular la Matriz transpuesta..." << endl;
//
//
//            int filas, columnas;
//            cout << "Cantidad de Filas(m): ";
//            cin >> filas;
//            cout << "\nCantidad de columnas(n): ";
//            cin >> columnas;
//            Matriz a(filas,columnas), b;
//            cout << "\nLo siquiente es ingresar los datos de la Matriz." << endl;
//            cin >> a;
//
//            b = a.Transpuesta();
//            //Mostramos el resultado.
//            cout << "La Transpuesta de la Matriz se muestra a continuaci\242n:\n\n ";
//
//            cout << "Matriz A = " << endl << a << endl;
//            cout << "Matriz Transpuesta = " << endl << b << endl;
//            system("pause");
//            break;
//        }
//        case 7:
//        {
//            cout << "Se proceder\240 a calcular la Inversa de una Matriz..." << endl;
//
//
//            int mxm;
//            cout << "Cantidad de Filas y Columnas(mxm) (Matriz Cuadrada): ";
//            cin >> mxm;
//            Matriz a(mxm), b;
//            cout << "\nLo siquiente es ingresar los datos de la Matriz." << endl;
//            cin >> a;
//
//            b = a.Inversa();
//            //Mostramos el resultado.
//            cout << "La Inversa de la Matriz se muestra a continuaci\242n:\n\n ";
//
//            cout << "Matriz A = " << endl << a << endl;
//            cout << "Matriz Inversa = " << endl << b << endl;
//            system("pause");
//            break;
//        }
//        case 8:
//        {
//         cout << "Se proceder\240 a redimensionar Matriz de orden 3x3..." << endl;
//            Matriz a(3,3);
//            int x = 0;
//            for(int i = 0; i < a.ObtenerFilas(); ++i)
//                for(int j = 0; j < a.ObtenerColumnas(); ++j)
//                    a[i][j] = ++x;
//            cout << a << endl;
//            cout << "\nIngrese el nuevo orden de la matriz(mxn).." << endl;
//            cout << "Fila(m): ";
//            int fila;
//            cin >> fila;
//            cout << "\nColumna(n): ";
//            int columna;
//            cin >> columna;
//            a.Redimensionar(fila,columna);
//            cout << "\nMatriz Redimensionada de orden " << fila << "x" << columna <<"]" <<endl;
//            cout << a;
//            system("pause");
//            break;
//        }
//        case 0:
//        {
//            return;
//        }
//    }

//}catch(out_of_range &exc){
//        cerr << "\nError: " << exc.what() << endl << endl;
//}catch(logic_error &exc){
//        cerr << "\nError: " << exc.what() << endl;
//}catch(bad_alloc &exc){
//        cerr << "\nError: Falla en la asignaci\242n de memoria" << endl;
//    }
//}
