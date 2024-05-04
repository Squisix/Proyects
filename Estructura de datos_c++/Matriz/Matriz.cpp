/*
Nombre: Matriz.cpp
Autor: Marco Antonio Guerrero Vasquez // 219202704
Fecha: 05/05/2021
Descripción: Archivo de implementación de Matriz.h
*/
#include "Matriz.h"
#include <iostream>
#include <cmath>

//Privada
void Matriz::EstablecerOrden(int m, int n){
    if(m < 1) throw std::logic_error("Fila fuera de rango");
    if(n < 1) throw std::logic_error("Columna fuera de rango");
    fila = m;
    columna = n;
}
//
//*************************************************************//
Matriz::Matriz(){
    EstablecerOrden(1,1);

    elemento = new double *[fila];
    elemento[0] = new double [fila*columna];
    for(int i = 1; i < fila; ++i) elemento[i] = elemento[i-1] + columna;

    for(int i = 0; i < fila; ++i)
        for(int j = 0; j < columna; ++j){
            elemento[i][j] = 0;
    }

}

//*********************************************************//
Matriz::Matriz(int mxn){
    EstablecerOrden(mxn,mxn);

    elemento = new double* [fila];
    elemento[0] = new double [fila*columna];
    for(int i = 1; i < fila; ++i) elemento[i] = elemento[i-1] + columna;

    for(int i = 0; i < fila; ++i)
        for(int j = 0; j < columna; ++j){
            elemento[i][j] = 0;
        }
}

//***********************************************************//
Matriz::Matriz(int m, int n){
    EstablecerOrden(m,n);
    elemento = new double* [fila];
    elemento[0] = new double [fila*columna];
    for(int i = 1; i < fila; ++i) elemento[i] = elemento[i-1] + columna;

    for(int i = 0; i < fila; ++i)
        for(int j = 0; j < columna; ++j){
            elemento[i][j] = 0;
        }
}
//***********************************************************//
Matriz::Matriz(int m, int n, double valorInicial){
    EstablecerOrden(m,n);
    elemento = new double* [fila];
    elemento[0] = new double [fila*columna];
    for(int i = 1; i < fila; ++i) elemento[i] = elemento[i-1] + columna;

    for(int i = 0; i < fila; ++i)
        for(int j = 0; j < columna; ++j){
            elemento[i][j] = valorInicial;
        }

}
//************************************************************//
Matriz::Matriz(const Matriz &ma):fila(1),columna(1), elemento(NULL){
    *this = ma;
}

//*********************************************************//
Matriz::~Matriz(){
    delete [] elemento[0];
    delete [] elemento;
}
//******************************************************************************************
//******************************************************************************************
//************************************************************//
void Matriz::Redimensionar (int m, int n){
    if(m == fila && n == columna) return;
    int mVieja = fila, nVieja = columna;
    double **aux = elemento;

    EstablecerOrden(m,n);

    elemento = new double* [fila];
    elemento[0] = new double[fila*columna];
    for(int i = 1; i < fila; ++i) elemento[i] = elemento[i-1] + columna;

    if(fila <= mVieja && columna <= nVieja){
        for(int i = 0; i < fila; ++i)
            for(int j = 0; j < columna; ++j){
                elemento[i][j] = aux[i][j];
            }

    }else if (fila >= mVieja && columna >= nVieja){
        for(int i = 0; i < mVieja; ++i)
            for(int j = 0; j < nVieja; ++j){
                elemento[i][j] = aux[i][j];
            }

        for(int i = 0; i < fila; ++i)
            for(int j = nVieja; j < columna; ++j){
                elemento[i][j] = 0;
            }
        for(int i = mVieja; i < fila; ++i)
            for(int j = 0; j < columna; ++j){
                elemento[i][j] = 0;
            }

    }else if (fila < mVieja && columna > nVieja){
        for(int i = 0; i < fila; ++i)
            for(int j = 0; j < nVieja; ++j){
                elemento[i][j] = aux[i][j];
            }

        for(int i = 0; i < fila; ++i)
            for(int j = nVieja; j < columna; ++j){
                elemento[i][j] = 0;
            }

    }else if (fila > mVieja && columna < nVieja){
        for(int i = 0; i < mVieja; ++i)
            for(int j = 0; j < columna; ++j){
                elemento[i][j] = aux[i][j];
            }

        for(int i = mVieja; i < fila; ++i)
            for(int j = 0; j < columna; ++j){
                elemento[i][j] = 0;
            }
    }
    delete [] aux[0];
    delete [] aux;
}


void Matriz::EstablecerElemento(int m, int n, double elem){
    if(m < 0 || m >= fila) throw std::out_of_range("Fila fuera de rango");
    if(n < 0 || n >= columna) throw std::out_of_range("Columna fuera de rango");
    elemento[m][n] = elem;
}
//*************************************************************//

int Matriz::ObtenerFilas() const{
    return fila;
}
//*************************************************************//
int Matriz::ObtenerColumnas() const{
    return columna;
}
//*************************************************************//
double Matriz::ObtenerElemento(int m, int n) const{
    if(m < 1 || m >= fila) throw std::out_of_range("Fila fuera de rango");
    if(n < 1 || n >= columna) throw std::out_of_range("Columna fuera de rango");
    return elemento[m][n];

}
//*************************************************************//
Matriz Matriz::Transpuesta(){
    Matriz transpuesta(columna,fila);

    for(int i = 0; i < columna; ++i)
        for(int j = 0; j < fila; ++j)
            transpuesta[i][j] = elemento[j][i];

    return transpuesta;
}
//*************************************************************//
void Matriz::IntercambiarRenglones(int renUno, int renDos){
    if(renUno < 1 || renUno >= fila) throw std::out_of_range("Fila fuera de rango");
    if(renDos < 1 || renDos >= fila) throw std::out_of_range("Fila fuera de rango");
    double Aux;
    for(int j = 0; j < fila; ++j) {
        Aux = elemento[renUno][j];
        elemento[renUno][j] = elemento[renDos][j];
        elemento[renDos][j] = Aux;
    }
}
//*************************************************************//
void Matriz::MultiplicarRenglon(int renglon, double multiplo){
    if(renglon < 1 || renglon >= fila) throw std::out_of_range("Fila fuera de rango");
    for(int j = 0; j < columna; ++j)
        elemento[renglon][j] = elemento[renglon][j] * multiplo;
}
//*************************************************************//
void Matriz::SumarMultiplosRenglones(int renUno, int renDos, double multiplo){
    for(int j = 0; j < columna; ++j)
        elemento[renUno][j] += elemento[renDos][j] * multiplo;
}
//*************************************************************//
Matriz Matriz::Inversa() const{
    if(fila != columna) throw std::logic_error("La matriz no es cuadrada");
    Matriz Aux;
    Aux = *this;

    Aux.Redimensionar(fila,2*fila);
    for (int i = 0; i < fila ; ++i) Aux[i][fila+i] = 1;

    for(int i = 0; i < fila; ++i) {
        if (Aux[i][i] == 0) {
            bool esInvertible = false;
            for (int j = i + 1; j < fila; ++j) {
                if (Aux[j][i] != 0) {
                    Aux.IntercambiarRenglones(i, j);
                    esInvertible = true;
                    break;
                }
            }
            if (!esInvertible) {
                throw std::logic_error("Matriz no invertible");
            }
       }
        Aux.MultiplicarRenglon(i, 1 / Aux[i][i]);
        for (int j = 0; j < i; ++j) Aux.SumarMultiplosRenglones(j, i, -Aux[j][i]);
        for (int j = i + 1; j < fila; ++j) Aux.SumarMultiplosRenglones(j, i, -Aux[j][i]);

    }
    Matriz inversa(fila,fila);
    for (int i = 0; i < fila; ++i)
        for(int j = 0; j < fila; ++j)
            inversa[i][j] = Aux[i][fila+j];
    return inversa;
}



//Operaciones
//OPERADORES SOBRECARGADOS
//******************************************************************************************
Matriz& Matriz::operator= (const Matriz &ma){
    if(this == &ma) return *this;
    if(elemento != NULL){
        delete [] elemento[0];
        delete [] elemento;
    }

    EstablecerOrden(ma.fila,ma.columna);
    elemento = new double* [fila];
    elemento[0] = new double[fila*columna];
    for(int i = 1; i < fila; ++i) elemento[i] = elemento[i-1] + columna;

    for(int i = 0; i < fila; ++i)
        for (int j = 0; j < columna; ++j){
            elemento[i][j] = ma.elemento[i][j];
        }
    return *this;
}
//******************************************************************************************
Matriz Matriz::operator++(){
    for(int i = 0; i < fila; ++i)
        for(int j = 0; j < columna; ++j)
            ++elemento[i][j];

    return *this;
}
//******************************************************************************************
Matriz Matriz::operator++(int){
    Matriz c = *this;
    for(int i = 0; i < fila; ++i)
        for(int j = 0; j < columna; ++j){
            ++elemento[i][j];
        }
    return c;
}
//******************************************************************************************
//******************************************************************************************
//******************************************************************************************
//Funcion externa // funcion amiga
Matriz Matriz::operator* (double escalar) const{  //Escalar
    Matriz maProducto(fila,columna);
    for(int i = 0; i < fila; ++i)
        for(int j = 0; j < columna; ++j){
            maProducto.elemento[i][j] = elemento[i][j]*escalar;
        }
    return maProducto;
}
//***************************************************************************
Matriz Matriz::operator* (const Matriz &ma) const{
    if(columna != ma.fila) throw std::logic_error("Orden incompatible para la multiplicacion de vectores");

    Matriz maProducto(fila,ma.columna,0);

    for(int i = 0; i < fila; ++i)
        for(int j = 0; j < ma.columna; ++j)
            for(int k = 0; k < columna; ++k)
            maProducto[i][j] += elemento[i][k] * ma.elemento[k][j];

    return maProducto;
}
//***************************************************************************
Matriz operator* (double escalar, const Matriz &ma){
    return ma * escalar;
}

std::ostream& operator<< (std::ostream &fSalida, const Matriz &ma){
    for(int i = 0; i < ma.fila; ++i){
        for(int j = 0; j < ma.columna; ++j)
            fSalida << "   " << ma.elemento[i][j];
        fSalida << std::endl;
    }
    return fSalida;
}
//******************************************************************************************
std::istream& operator>> (std::istream &fEntrada, Matriz &ma){
    for(int i = 0; i < ma.fila; ++i)
        for(int j = 0; j < ma.columna; ++j){
            std::cout << "Elemento[" << i+1 << "][" << j+1 << "]: ";
            fEntrada >> ma.elemento[i][j];
        }
    return fEntrada;
}
//******************************************************************************************
Matriz Matriz::operator+ (const Matriz &ma){
    if(fila != ma.fila && columna != ma.columna) throw std::logic_error("Orden incompatible para la suma");
    Matriz maSuma(fila,columna);
    for(int i = 0; i < fila; ++i)
        for(int j = 0; j < columna; ++j){
            maSuma.elemento[i][j] = elemento[i][j]+ma.elemento[i][j];
        }
    return maSuma;
}
//******************************************************************************************
Matriz Matriz::operator- (const Matriz &ma){
    if(fila != ma.fila && columna != ma.columna) throw std::logic_error("Orden incompatible para la resta");
    Matriz maResta(fila,columna);
    for(int i = 0; i < fila; ++i)
        for(int j = 0; j < columna; ++j){
            maResta.elemento[i][j] = elemento[i][j]-ma.elemento[i][j];
        }
    return maResta;
}
//******************************************************************************************

//******************************************************************************************
const double* Matriz::operator[] (int m) const{
    if(m < 0 || m >= fila) throw std::out_of_range("Fila fuera de rango");
    return elemento[m];
}
////******************************************************************************************
double* Matriz::operator[] (int m){
    if(m < 0 || m >= fila) throw std::out_of_range("Fila fuera de rango");
    return elemento[m];
}
