#include "Vector.h"
#include <iostream>
#include <cmath>
Vector::Vector(char n /*= 'X' */): nombre(n){
    EstablecerDimension(1);
    componente = new double[dimension];
    componente[0] = 0;
}

//*********************************************************//
Vector::Vector(int dim,char n /*= 'X' */):nombre(n){
    EstablecerDimension(dim);
    componente = new double[dim];
    for(int i = 0; i < dimension; ++i) componente[i] = 0;
}
//***********************************************************//
Vector::Vector(int dim, double valorInicial,char n /*= 'X' */):nombre(n){
    EstablecerDimension(dim);
    componente = new double[dim];
    for(int i = 0; i < dimension; ++i) componente[i] = valorInicial;
}
//************************************************************//
Vector::Vector(const Vector &v):dimension(1),componente(NULL), nombre(v.nombre){
    *this = v;
}

//*********************************************************//
 Vector::~Vector(){
     delete [] componente;
}
//******************************************************************************************
//******************************************************************************************
//************************************************************//
void Vector::EstablecerComponente(int i,double comp){
    if(i < 0 || i >= dimension) throw std::out_of_range("\214ndice fuera de rango");
    componente[i] = comp;
}
//*************************************************************//
void Vector::EstablecerDimension(int dim){
    if(dim < 1 || dim > MAXDIM) throw std::logic_error("Dimensi\242n fuera de rango");
    dimension = dim;

}
//*************************************************************//
int Vector::ObtenerDimension() const{
    return dimension;
}
//*************************************************************//
double Vector::ObtenerComponente(int i){
    if(i < 1 || i >= dimension) throw std::out_of_range("\214ndice fuera de rango");
    return componente[i];

}
//*************************************************************//
void Vector::Redimensionar (int dim){
    if(dim == dimension) return;
    int dimVieja = dimension;
    double *aux = componente;
    EstablecerDimension(dim);
    componente = new double[dimension];
    if(dimension < dimVieja){
        for(int i = 0; i < dimension; ++i) componente[i] = aux[i];
    }else if (dimension > dimVieja){
        for(int i = 0; i < dimVieja; ++i) componente[i] = aux[i];
        for(int i = dimVieja; i < dimension; ++i) componente[i] = 0;
    }
    delete [] aux;
}


//Operaciones
//OPERADORES SOBRECARGADOS
//******************************************************************************************
Vector& Vector::operator= (const Vector &v){
    if(this == &v) return *this;
    delete [] componente;
    EstablecerDimension(v.dimension);
    componente = new double[dimension];
    for(int i = 0; i < dimension; ++i) componente[i] = v.componente[i];
    return *this;
}
//******************************************************************************************
Vector Vector::operator++(){
    for(int i = 0; i < dimension; ++i) ++componente[i];
    return *this;
}
//******************************************************************************************
Vector Vector::operator++(int){
    Vector c = *this;
    for(int i = 0; i < dimension; ++i) ++componente[i];
    return c;
}
//******************************************************************************************
//******************************************************************************************
//******************************************************************************************
//Funcion externa // funcion amiga
Vector operator* (double escalar, const Vector &v){
    return v * escalar;
}
std::ostream& operator<< (std::ostream &fSalida, const Vector &v){
    fSalida << "(";
    for(int i = 0; i < v.dimension; ++i) fSalida << v.componente[i] << ", ";
    return fSalida << "\b\b)";
}
//******************************************************************************************
std::istream& operator>> (std::istream &fEntrada, Vector &v){
    for(int i = 0; i < v.dimension; ++i) {
        std::cout << "Componente #" << i+1 << ": ";
        fEntrada >> v.componente[i];
    }
    return fEntrada;
}
//******************************************************************************************
Vector Vector::operator+ (const Vector &v){
    if(dimension != v.dimension) throw std::logic_error("Dimensiones incompatibles para la suma");
    Vector vSuma(dimension);
    for(int i = 0; i < dimension; ++i){
        vSuma.componente[i] = componente[i]+v.componente[i];
    }
    return vSuma;
}
//******************************************************************************************
Vector Vector::operator- (const Vector &v){
    if(dimension != v.dimension) throw std::logic_error("Dimensiones incompatibles para la resta");
    Vector vResta(dimension);
    for(int i = 0; i < dimension; ++i){
        vResta.componente[i] = componente[i]+v.componente[i];
    }
    return vResta;
}
//******************************************************************************************
Vector Vector::operator* (double escalar) const{  //Escalar
    Vector vProducto(dimension);
    for(int i = 0; i < dimension; ++i) vProducto.componente[i] = componente[i]*escalar;
    return vProducto;
}
//******************************************************************************************
//******************************************************************************************
double Vector::Magnitud() const{
    double suma = 0;
    for(int i = 0; i < dimension; ++i) suma+= componente[i]*componente[i];
    return std::sqrt(suma);
}
//******************************************************************************************
const double& Vector::operator[] (int i) const{
    if(i < 1 || i >= dimension) throw std::out_of_range("\214ndice fuera de rango");
    return componente[i];
}
//******************************************************************************************
double& Vector::operator[] (int i){
    if(i < 1 || i >= dimension) throw std::out_of_range("\214ndice fuera de rango");
    return componente[i];
}
