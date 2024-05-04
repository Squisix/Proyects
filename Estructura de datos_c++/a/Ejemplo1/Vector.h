
#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
#include <stdexcept>

#define MAXDIM 100


/** \brief Clase que representa a un Vector anal@iacute;tico
 *  \param i Indica la componente
 *  \param componente double
 */
class Vector{

    public:
        Vector(char n = 'X');           // Constructor por default
        explicit Vector(int dim, char n = 'X');    // Constructor u operador de conversión implicita
        Vector(int dim, double valorInicial, char n = 'X');
        Vector(const Vector &v); // Constructor de copias

        ~Vector(); //Destructor
        void Redimensionar (int dim);
        void EstablecerComponente(int i,double comp);
        int ObtenerDimension() const;
        double ObtenerComponente(int i);
        //void Imprimir()const;
        //void Capturar();


        //Operaciones
        //Vector Sumar(Vector v) const;
        Vector Resta(Vector v) const;
        Vector Multiplicar(double escalar) const;
        double Multiplicar(Vector v) const;
        double Magnitud() const;
        Vector operator++();
        Vector operator++(int);

        //Sobrecarga de operadores
        Vector operator+ (const Vector &v);
        Vector operator- (const Vector &v);
        Vector& operator= (const Vector &v);
        Vector operator* (double escalar) const;
        friend Vector operator* (double escalar, const Vector &v);
        friend std::ostream& operator<< (std::ostream &fSalida, const Vector &v);
        friend std::istream& operator>> (std::istream &fEntrada, Vector &v);
        const double &operator[] (int i) const; // rvalue
        double& operator[] (int i); // lvalue

    private:
        int dimension;
        double *componente;
        const char nombre;
        void EstablecerDimension(int dim);

};



#endif // VECTOR_H_INCLUDED
