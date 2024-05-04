/*
    \Nombre: Matriz.h
    \Autor: Marco Antonio Guerrero Vasquez // 219202704
    \Fecha: 05/02/2021
    \Descripción: Archivo de cabecera donde se declara la clase Matriz
*/
#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

#include <stdexcept>
/** \brief Clase que representa una matriz anal@iacute;tica
 */
class Matriz{

    public:
        /** \brief Constructor por default de la clase
         * \pre No se permite la conversion automatica
         */
        explicit Matriz();// Constructor por default

        /** \brief Constructor para crear una Matriz cuadrada
         *
         * \param int mxn Orden cuadrada de la Matriz
         */
        explicit Matriz(int mxn);
        /** \brief Constructor para crear una Matriz de orden mxn
         *
         * \param int mxn N@uacute;mero de filas y columnas de la Matriz
         * \pre El n@uacute;mero de filas y columnas no deben ser menor a 1
         */
        Matriz(int m, int n);
        /** \brief Constructor para crear una Matriz de orden mxn con un valor inicial proporcionado
         *
         * \param int m N@uacute;mero de filas de la Matriz
         * \param int n N@uacute;mero de columnas de la Matriz
         * \param double valorInicial Valor con el que se llenar@aacute;la Matriz
         * \pre Tanto el n@uacute;mero de filas como de columnas no deben ser menor a 1
         */
        Matriz(int m, int n, double valorInicial);
        /** \brief Constructor de copias de la Matriz
         *
         * \param const Matriz &ma Recibe por referencia la Matriz a copiar
         */
        Matriz(const Matriz &ma); // Constructor de copias

        /** \brief Destructor de la clase Matriz
         */
        ~Matriz(); //Destructor


        /** \brief Metodo que permite redimensionar una Matriz
         * \param int m N@uacute;mero de filas de la matriz redimensionada
         * \param int n N@uacute;mero de columnas de la matriz redimensionada
         * \return void
         * \pre Tanto el n@uacute;mero de filas como de columnas no deben ser menor a 1
         */
        void Redimensionar (int m, int n);

        /** \brief Metodo que permite cambiar un elementi indizado de la matriz
         * \param int m N@uacute;mero de la fila del elemento a cambiar
         * \param int n N@uacute;mero de la columna del elemento a cambiar
         * \param double elem Nuevo elemento de la matriz
         * \return void
         * \pre Tanto el n@uacute;mero de filas como de columnas no deben ser menor a 1 ni mayores a las propias de la matriz
         * \exception std::out_of_range   Fila fuera de rango
         * \exception std::out_of_range   Columna fuera de rango
         */
        void EstablecerElemento(int m, int n,double elem);

        /** \brief Metodo que permite conocer el n@uacute;mero de filas de la matriz
         * \return int N@uacute;mero de filas
         */
        int ObtenerFilas() const;

        /** \brief Metodo que permite conocer el n@uacute;mero de columnas de la matriz
         * \return int N@uacute;mero de columnas
         */
        int ObtenerColumnas() const;

        /** \brief Metodo que permite conocer el elemento de la Matriz
         * \param int m N@uacute;mero de la fila del elemento a obstener
         * \param int n N@uacute;mero de la columna del elemento a obtener
         * \return double Elemento del @iacute;ndice mxn
         * \pre Tanto el n@uacute;mero de filas como de columnas no deben ser menor a 1
         * \exception std::out_of_range   Fila fuera de rango
         * \exception std::out_of_range   Columna fuera de rango
         */
        double ObtenerElemento(int m, int n) const;

        /** \brief Metodo que calcula la transpuesta de una matriz
         * \param int m N@uacute;mero de la fila del elemento a obstener
         * \param int n N@uacute;mero de la columna del elemento a obtener
         * \return double Elemento del @iacute;ndice mxn
         */
        Matriz Transpuesta();

        /** \brief Metodo que intercambia un renglones de la matriz
         * \param int renUno N@uacute;mero de la primera fila a intercambiar
         * \param int renDos N@uacute;mero de la segunda fila a intercambiar
         * \return void
         * \pre Tanto el renglon uno como el dos no pueden ser menores a 1 ni mayores al tamaño de la fila de la matriz
         * \exception std::out_of_range Fila fuera de rango
         */
        void IntercambiarRenglones(int renUno, int renDos);

        /** \brief Metodo que multiplica un renglon de la matriz por un escalar
         * \param int renglon N@uacute;mero de la a multiplicar
         * \param double multiplo Valor por el que se multiplicar@aacute; el renglon
         * \return void
         * \pre El renglon no puede ser menor a 1 ni mayor al tamaño de la fila de la matriz
         * \exception std::out_of_range Fila fuera de rango
         */
        void MultiplicarRenglon(int renglon, double multiplo);


        void SumarMultiplosRenglones(int renUno, int renDos, double multiplo);

        /** \brief Metodo que calcula la matriz inversa
         * \return Matriz La matriz inversa
         * \pre En algunos casos no se podra efectuar la matriz inversa
         * \exception std::logic_error La matriz no tiene inversa
         */
        Matriz Inversa() const;



        //Operaciones
        /** \brief Operador++ sobrecargado para la clase Matriz. Preincremento
         * \return Matriz La matriz pre incrementada
         */
        Matriz operator++();

        /** \brief Operador++ sobrecargado para la clase Matriz. Proincremento
         * \return Matriz La matriz post incrementada
         */
        Matriz operator++(int);

        //Sobrecarga de operadores
        /** \brief Operador+ sobrecargado para la clase Matriz.
         * \param const Matriz &ma Referencia de la matriz que se va a sumar
         * \return Matriz La matriz a sumar
         */
        Matriz operator+ (const Matriz &ma);

        /** \brief Operador- sobrecargado para la clase Matriz.
         * \param const Matriz &ma Referencia de la matriz que se va a restar
         * \return Matriz La matriz a restar
         */
        Matriz operator- (const Matriz &ma);

        /** \brief Operador= sobrecargado para la clase Matriz.
         * \param const Matriz &ma Referencia de la matriz que se va a restar
         * \return Matriz& La referencia de la matriz
         */
        Matriz& operator= (const Matriz &ma);


        /** \brief Operador* sobrecargado para la clase Matriz.
         * \param const Matriz &ma Referencia de la matriz a multiplicar con otra matriz
         * \return Matriz El producto de las matrices
         */
        Matriz operator* (const Matriz &ma) const;

        /** \brief Operador* sobrecargado para la clase Matriz.
         * \param const double Escalar con el que se va a multiplicar la matriz
         * \return Matriz La matriz multiplicada por escalar
         */
        Matriz operator* (double escalar) const;
        /** \brief Operador* sobrecargado para la clase Matriz. Conmutativo
         * \param const double Escalar con el que se va a multiplicar la matriz
         * \param const Matriz &ma referencia de la matriz que se va a multiplicar
         * \return Matriz La matriz multiplicada por escalar
         */
        friend Matriz operator* (double escalar, const Matriz &ma);

        /** \brief Operador<< sobrecargado para la clase Matriz.
         * \param std::ostream& &fSalida Referencia del Flujo de salida donde se mandaran los datos
         * \param const Matriz &ma Referencia de la matriz que entrará al flujo de datos
         * \return std::ostream& Flujo de salida con la matriz
         */
        friend std::ostream& operator<< (std::ostream &fSalida, const Matriz &ma);

        /** \brief Operador>> sobrecargado para la clase Matriz.
         * \param std::istream& &fEntrada Referencia del Flujo de entrada donde se campturaran los datos
         * \param const Matriz &ma Referencia de la matriz que entrará al flujo de datos
         * \return std::ostream& Flujo de entrada con la matriz
         */
        friend std::istream& operator>> (std::istream &fEntrada, Matriz &ma);

        /** \brief Operador[] sobrecargado para la clase Matriz. Rvalue
         * \param int m N@uacute;mero de columna al que se hará referencia en la matriz
         * \param const Matriz &ma Referencia de la matriz que entrará al flujo de datos
         * \return const double* Puntero constante donde se encuentra el valor del indice
         */
        const double* operator[] (int m) const; // rvalue

        /** \brief Operador[] sobrecargado para la clase Matriz. Lvalue
         * \param int m N@uacute;mero de columna al que se hará referencia en la matriz
         * \param const Matriz &ma Referencia de la matriz que entrará al flujo de datos
         * \return double* Puntero donde se encuentra el valor del indice
         */
        double* operator[](int m); // lvalue

    private:
        int fila;
        int columna;
        double **elemento;

        /** \brief Metodo de utileria que establece el orden de una Matriz
         * \param int m N@uacute;mero de la fila del elemento a establecer
         * \param int n N@uacute;mero de la columna del elemento a establecer
         * \return void
         * \pre Tanto el n@uacute;mero de filas como de columnas no deben ser menor a 1
         * \exception std::out_of_range   Fila fuera de rango
         * \exception std::out_of_range   Columna fuera de rango
         */
        void EstablecerOrden(int m, int n);

};







#endif // MATRIZ_H_INCLUDED
