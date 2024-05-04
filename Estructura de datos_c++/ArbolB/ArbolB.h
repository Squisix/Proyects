/*
    \Name: ArbolAVL.h
    \Author: Marco Antonio Guerrero Vasquez // 219202704
    \Date: 09/05/21
    \brief: Archivo de Cabecera donde se definida la clase ArbolB
*/
#ifndef ARBOLB_H_INCLUDED
#define ARBOLB_H_INCLUDED
enum FormaImpresion {ASCENDENTE, DESCENDENTE, POR_NIVEL};


/** \class ArbolB
*   Arbol balanceado de b�squeda; Cada nodo puede poseer hasta n hijos.
*   Cada Nodo contiene como m�ximo n-1 Claves y como m�nimo (n-1)/2 claves.
*   \tparam T Tipo de valor.
*   \tparam int grado Grado del ArbolB. 5 por default.
*/
template <typename T, int grado = 5>
class ArbolB{

public:
    /** \brief Constructor
    */
    ArbolB();

    /** \brief Constructor de copias
    */
    ArbolB(const ArbolB<T, grado> &arbol);

    /** \brief Destructor
    */
    ~ArbolB();

    /** \brief Operador de Funci�n. Copia todos los parametros de un ArbolB a otro.
    *   \param const ArbolB<T,grado> &arbol ArbolB a copiar.
    *   \return ArbolB<T,grado>& Referencia a ArbolB a copiar.
    */
    ArbolB<T,grado>& operator=(const ArbolB<T,grado> &arbol);

    /** \brief Permite insertar un dato en un ArbolB (sin repetici�n)
    *   \param const T& val El valor del dato a insertar
    */
    void Insertar(const T& val);



    /** \brief Permite buscar si una clave se encuentra en el ArbolB.
    *   \param const T& val Valor del nodo a buscar.
    *   \return True si la clave est� en el ArbolB, false en caso contrario.
    */
    bool BuscarClave(const T& val);

    /** \brief Permite conocer el numero de claves que hay en el ArbolB
    *   \return Numero de claves en el ArbolAVL.
    */
    unsigned ObtenerNumClaves();

    /** \brief Metodo que vacia un ArbolB
    */
    void Vaciar();
    /** \brief Metodo que imprime un ArbolB de distintas maneras seleccionables.
    *   \param const FormaImpresion &s Elemento de tipo FormaImpresion que
    *           permiten seleccionar la manera de imprimir los ArbolAVL.
    *           ASCENDENTE, DESCENDENTE y POR_NIVEL.
    */
    void Imprimir(const FormaImpresion &s);

    /** \brief Permite conocer si un ArbolB est� vacio
    *   \return true si el ArbolB esta vacio, false en caso contrario.
    */
    bool EstaVacio();


    void EliminarClave(const T& val);



private:
    int maximo; /*< N�mero m�ximo de claves que puede tener un nodo*/
    int minimo; /*< N�mero m�nimo de claves que puede tener un nodo*/
    int numClaves;  /*< N�mero de claves Totales*/


    /** \struct Nodo
     *          Estructura qeu almacena n claves denotadas por grado, as� como de n hijos.
     *          Permite almacenar datos en el arbolB asi como acceder a sus hijos.
     *
     */
    struct Nodo{

        /** \brief Constructor de Nodo
        */
        Nodo();
        T clave[grado];    /*< Arreglo de tama�o Grado donde se almacenan las claves de tipo T*/ // Esto evita que tengan que generar los arreglos din�micamente
        Nodo* hijo[grado];  /*< Arreglo de tama�o grado que almacena los punteros a Nodo de los hijos de ese mismo nodo*/
        Nodo* siguiente;
        int NumClavesNodo;  /*< Numero de claves del nodo*/

        /** \brief Permite conocer si el nodo se encuentra lleno
        *   \return True si el nodo esta lleno, false en caso contrario
        */
        bool NodoLleno();

        /** \brief Permite conocer si el nodo tiene mas elementos que el minimo
        *   \return True si el nodo esta lleno, false en caso contrario
        */
        bool NodoSemiLleno();

        /** \brief Permite conocer la clave almacenada en un indice concreto
        *   \param int i Indice de donde se sacar� el valor
        *   \return const T& Clave obtenida del indice
        */
        const T& ObtenerClave(int i) const;

        /** \brief Permite cambiar la clave almacenada en un indice concreto
        *   \param int i Indice de donde se sacar� el valor
        *   \param  const T& val Valor por el que sera cambiada la clave
        */
        void CambiarClave(int i, const T& val);

        /** \brief Permite obtener la direcci�n referenciada del hijo obteniendo el indice de este.
        *   \param int i Indice de donde se sacar� el valor
        *   \return Puntero del nodo hijo obtenido por el indice
        */
        Nodo*& ObtenerHijo(int i);

        /** \brief Permite cambiar la direcci�n del hijo obteniendo el indice de este.
        *   \param int i Indice de donde se sacar� el nodo
        *   \param Puntero del nodo hijo que reemplazara al actual
        */
        void CambiarHijo(int i, Nodo* n);

        /** \brief Permite obtener El numero de claves enh el nodo.
        *   \return Numero de claves del nodo
        */
        int ObtenerNumClavesNodo() const;

        /** \brief Permite cambiar El numero de claves en el nodo.
        *   \param int _NumClavesNodo Nuevo valor de claves en el nodo
        */
        void CambiarNumClavesNodo(int _NumClavesNodo);

        /** \brief Permite conocer si un nodo es hoja.
        *   \return true en caso de ser un nodo hoja, false en caso contrario.
        */
        bool EsHoja() const;

    }*raiz, *hijoChico; /*< Puntero a nodo que almacena la direccion del nodo raiz del arbol*/




    /** \brief Busca un valor en el nodo que se le mande buscar, recibe un indice auxiliar que almacenar� la posicion
            de inserci�n del valor buscado
    *   \param Nodo* Actual direccion del nodo donde se buscar� el valor
    *   \param const T& val Valor buscado en el nodo
    *   \param int &k Indice auxiliar que indica la posicion de insercion de un valor
    *   \return true si el valor se encuentra en el nodo, false en caso contrario.
    */
    bool BuscarEnNodo(Nodo * actual, const T& val, int &k);

    /** \brief Busca un la direccion de un nodo con el valor que se le mande buscar, recibe un indice auxiliar que almacenar� la posicion
            de inserci�n del valor buscado
    *   \param Nodo* Actual direccion del nodo donde se busca el valor.
    *   \param const T& val Valor buscado en el nodo
    *   \param int &n Indice auxiliar que indica la posicion de busqueda de un nodo deacuerdo a los hijos.
    *   \return Nodo Buscado, en caso de no encontrarlo regresa NULL
    */
    Nodo* BuscarNodo(Nodo * actual, const T& val, int &n);

    /** \brief Funci�n auxiliar para insertar un valor
    *   \param Nodo* Direccion donde se iniciara el proceso de inserci�n
    *   \param const T& val valor a insertar
    *   \return La direcci�n del nodo raiz
    */
    Nodo* Insertar(Nodo* raiz, const T& val);

    /** \brief Funci�n auxiliar que permite conocer si s va a empujar un elemento hacia arriba del arbol
    *   \param Nodo* Direccion donde se iniciara el proceso de empuje
    *   \param const T& val valor a insertar
    *   \param T& Mediana Valor que se encuentra en la mitad de las claves
    *   \param Nodo *&nuevo referencia a puntero a nodo de un nuevo nodo auxiliar que sera ingresado en
    *           caso de empujar un valor como el hijo derecho del mismo
    *   \return true si el valor ser� empujado hacia arriba, fasle en caso contrario
    */
    bool Empujar(Nodo* actual, const T& val, T& mediana, Nodo *& nuevo);

    /** \brief Funci�n auxiliar que permite meter un elemento en un nodo
    *   \param Nodo* Direccion donde se iniciara el proceso de empuje
    *   \param const T& val valor a insertar
    *   \param Nodo* direccion del hijo derecho del valor
    *   \param int k indice donde se insertar� el elemento
    */
    void MeterNodo(Nodo* actual, const T& val,Nodo *hijoDr, int k);

    /** \brief Funci�n auxiliar que permite meter dividir un nodo
    *   \param Nodo* Direccion donde se la division del nodo
    *   \param const T& mediana Valor que ssubir� una ves se divida el nodo
    *   \param Nodo* direccion del nuevo nodo creado al partir el nodo inicial
    *   \param int pos posicion del elemento
    */
    void DividirNodo(Nodo* actual, T& mediana,Nodo *&nuevo, int pos);

    /** \brief Funci�n auxiliar que permite imprimir un ArbolB por niveles
    *   \param Nodo* raiz direccion del nodo que se imprimira
    *   \param int h numero de espacios de impresion
    */
    void EscribirPorNivel(Nodo* raiz, int h);
    /** \brief Funcion Auxiliar que vacia el arbol de manera recursiva
    *   \param Nodo*& puntero a nodo actual donde se hara el proceso de vaciado
    */
    void Vaciar(Nodo*& actual);

    /** \brief Funcion auxiliar que recorre el Arbol B de manera recursiva e imprime los valores de foram ascendente
    *   \param Nodo*& puntero a nodo actual donde se hara el proceso de impresion
    */
    void inOrden(Nodo *actual);

    /** \brief Funcion auxiliar que recorre el Arbol B de manera recursiva e imprime los valores de forma descendente
    *   \param Nodo*& puntero a nodo actual donde se hara el proceso de impresion
    */
    void posOrden(Nodo *actual);

    /** \brief Funcion Auxiliar que se encarga del proceso de copiado de un nodo en otro
    *   \param Nodo *raizAO direccion de la raiz del arbol original
    *   \return direccion del nuevo nodo copiado de la raiz original
    */
    Nodo* Copiar(Nodo *raizAO);

    /** \brief Funci�n recursiva que permita obtener el numero de claves del Arbol
    *   \param Nodo* actual Direccion del nodo en el que se encuentra inicialmente
    *   \return Numero de claves del arbol
    */
    int ObtenerNumClaves(Nodo *actual);






    bool Eliminar(Nodo*& actual, const T& val, T &mediana, int indicePadre);

    void QuitarNodo(Nodo* actual, int k);



};

#include "ArbolB.tpp"
#endif // ARBOLB_H_INCLUDED
