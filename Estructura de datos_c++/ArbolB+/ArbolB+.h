/*
    \Nombre: ArbolB+.h
    \Authores:
                Marco Antonio Guerrero Vasquez // 219202704
                Jesús Israel Urías Páramo      // 219217598
                José Isaías Olmos Morales      // 219212278
                Luis Gerardo Ortiz Quintana    // 219220371

    \Fecha: 18/05/21
    \brief: Archivo de Cabecera donde se definida la clase ArbolBMas
*/

#ifndef ARBOLBMAS_H_INCLUDED
#define ARBOLBMAS_H_INCLUDED

enum FormaImpresion {ASCENDENTE, DESCENDENTE, POR_NIVEL};


/** \class ArbolBMas
*   Arbol balanceado de búsqueda; Cada nodo puede poseer hasta n hijos.
*   Cada Nodo contiene como máximo n-1 Claves y como mínimo (n-1)/2 claves.
*   \tparam T Tipo de valor.
*   \tparam int grado Grado del ArbolB. 5 por default.
*/
template <typename T, int grado = 5>
class ArbolBMas{

public:
    /** \brief Constructor
    */
    ArbolBMas();

    /** \brief Constructor de copias
    */
    ArbolBMas(const ArbolBMas<T, grado> &arbol);

    /** \brief Destructor
    */
    ~ArbolBMas();

    /** \brief Operador de Función. Copia todos los parametros de un ArbolBMas a otro.
    *   \param const ArbolBMas<T,grado> &arbol ArbolBMas a copiar.
    *   \return ArbolBMas<T,grado>& Referencia a ArbolBMas a copiar.
    */
    ArbolBMas<T,grado>& operator=(const ArbolBMas<T,grado> &arbol);

    /** \brief Permite insertar un dato en un ArbolBMas (sin repetición)
    *   \param const T& val El valor del dato a insertar
    */
    void Insertar(const T& val);



    /** \brief Permite buscar si una clave se encuentra en el ArbolBMas.
    *   \param const T& val Valor del nodo a buscar.
    *   \return True si la clave está en el ArbolBMas, false en caso contrario.
    */
    bool BuscarClave(const T& val);

    /** \brief Permite conocer el numero de claves que hay en el ArbolBMas
    *   \return Numero de claves en el ArbolBMas.
    */
    unsigned ObtenerNumClaves();

    /** \brief Metodo que vacia un ArbolBMas
    */
    void Vaciar();
    /** \brief Metodo que imprime un ArbolBMas de distintas maneras seleccionables.
    *   \param const FormaImpresion &s Elemento de tipo FormaImpresion que
    *           permiten seleccionar la manera de imprimir los ArbolBMas.
    *           ASCENDENTE, DESCENDENTE y POR_NIVEL.
    */
    void Imprimir(const FormaImpresion &s);

    /** \brief Permite conocer si un ArbolBMas está vacio
    *   \return true si el ArbolBMas esta vacio, false en caso contrario.
    */
    bool EstaVacio();

    /** \brief Permite eliminar un dato en un ArbolBMas
    *   \param const T& val El valor del dato a eliminar
    */
    void EliminarClave(const T& val);



private:
    int maximo; /*< Número máximo de claves que puede tener un nodo*/
    int minimo; /*< Número mínimo de claves que puede tener un nodo*/
    int numClaves;  /*< Número de claves Totales*/


    /** \struct Nodo
     *          Estructura qeu almacena n claves denotadas por grado, así como de n hijos.
     *          Permite almacenar datos en el arbolB asi como acceder a sus hijos.
     *
     */
    struct Nodo{

        /** \brief Constructor de Nodo
        */
        Nodo();
        T clave[grado];    /*< Arreglo de tamaño Grado donde se almacenan las claves de tipo T*/ // Esto evita que tengan que generar los arreglos dinámicamente
        Nodo* hijo[grado];  /*< Arreglo de tamaño grado que almacena los punteros a Nodo de los hijos de ese mismo nodo*/
        Nodo* siguiente;    /*< Direccion del nodo siguiente, esta direccion solo se guarda cuando el nodo es hoja*/
        int NumClavesNodo;  /*< Numero de claves del nodo*/

        /** \brief Permite conocer si el nodo se encuentra lleno
        *   \return True si el nodo esta lleno, false en caso contrario
        */
        bool NodoLleno();


        /** \brief Permite conocer la clave almacenada en un indice concreto
        *   \param int i Indice de donde se sacará el valor
        *   \return const T& Clave obtenida del indice
        */
        const T& ObtenerClave(int i) const;

        /** \brief Permite cambiar la clave almacenada en un indice concreto
        *   \param int i Indice de donde se sacará el valor
        *   \param  const T& val Valor por el que sera cambiada la clave
        */
        void CambiarClave(int i, const T& val);

        /** \brief Permite obtener la dirección referenciada del hijo obteniendo el indice de este.
        *   \param int i Indice de donde se sacará el valor
        *   \return Puntero del nodo hijo obtenido por el indice
        */
        Nodo*& ObtenerHijo(int i);

        /** \brief Permite cambiar la dirección del hijo obteniendo el indice de este.
        *   \param int i Indice de donde se sacará el nodo
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

    }*raiz, *hijoChico; /*< Puntero a nodo que almacena la direccion del nodo raiz y del nodo hoja mas chico del arbol*/




    /** \brief Busca un valor en el nodo que se le mande buscar, recibe un indice auxiliar que almacenará la posicion
            de inserción del valor buscado
    *   \param Nodo* Actual direccion del nodo donde se buscará el valor
    *   \param const T& val Valor buscado en el nodo
    *   \param int &k Indice auxiliar que indica la posicion de insercion de un valor
    *   \return true si el valor se encuentra en el nodo, false en caso contrario.
    */
    bool BuscarEnNodo(Nodo * actual, const T& val, int &k);

    /** \brief Busca un la direccion de un nodo con el valor que se le mande buscar, recibe un indice auxiliar que almacenará la posicion
            de inserción del valor buscado
    *   \param Nodo* Actual direccion del nodo donde se busca el valor.
    *   \param const T& val Valor buscado en el nodo
    *   \param int &n Indice auxiliar que indica la posicion de busqueda de un nodo deacuerdo a los hijos.
    *   \return Nodo Buscado, en caso de no encontrarlo regresa NULL
    */
    Nodo* BuscarNodo(Nodo * actual, const T& val, int &n);

    /** \brief Función auxiliar para insertar un valor
    *   \param Nodo* Direccion donde se iniciara el proceso de inserción
    *   \param const T& val valor a insertar
    *   \return La dirección del nodo raiz
    */
    Nodo* Insertar(Nodo* raiz, const T& val);

    /** \brief Función auxiliar que permite conocer si s va a empujar un elemento hacia arriba del arbol
    *   \param Nodo* Direccion donde se iniciara el proceso de empuje
    *   \param const T& val valor a insertar
    *   \param T& Mediana Valor que se encuentra en la mitad de las claves
    *   \param Nodo *&nuevo referencia a puntero a nodo de un nuevo nodo auxiliar que sera ingresado en
    *           caso de empujar un valor como el hijo derecho del mismo
    *   \return true si el valor será empujado hacia arriba, fasle en caso contrario
    */
    bool Empujar(Nodo* actual, const T& val, T& mediana, Nodo *& nuevo);

    /** \brief Función auxiliar que permite meter un elemento en un nodo
    *   \param Nodo* Direccion donde se iniciara el proceso de empuje
    *   \param const T& val valor a insertar
    *   \param Nodo* direccion del hijo derecho del valor
    *   \param int k indice donde se insertará el elemento
    */
    void MeterNodo(Nodo* actual, const T& val,Nodo *hijoDr, int k);

    /** \brief Función auxiliar que permite meter dividir un nodo
    *   \param Nodo* Direccion donde se la division del nodo
    *   \param const T& mediana Valor que ssubirá una ves se divida el nodo
    *   \param Nodo* direccion del nuevo nodo creado al partir el nodo inicial
    *   \param int pos posicion del elemento
    */
    void DividirNodo(Nodo* actual, T& mediana,Nodo *&nuevo, int pos);

    /** \brief Función auxiliar que permite imprimir un ArbolB por niveles
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
    void Ascendente();

    /** \brief Funcion auxiliar que recorre el Arbol B de manera recursiva e imprime los valores de forma descendente
    *   \param Nodo*& puntero a nodo actual donde se hara el proceso de impresion
    */
    void Descendente();

    /** \brief Funcion Auxiliar que se encarga del proceso de copiado de un nodo en otro
    *   \param Nodo *raizAO direccion de la raiz del arbol original
    *   \return direccion del nuevo nodo copiado de la raiz original
    */
    Nodo* Copiar(Nodo *raizAO);

    /** \brief Función recursiva que permita obtener el numero de claves del Arbol
    *   \param Nodo* actual Direccion del nodo en el que se encuentra inicialmente
    *   \return Numero de claves del arbol
    */
    int ObtenerNumClaves(Nodo *actual);





    /** \brief Función que hace todos los procesos de eliminado en el ArbolB+
    *   \param Nodo*& Referencia a puntero del nodo actual
    *   \param const T& val Referencia contstante de tipo T del valor a eliminar
    *   \param T& valSube Valor que sube al padre en caso de ser modificado
    *   \param int indicePadre Indice desde donde se accedio al nodo actual
    *   \return true En caso de eliminar un elemento, false en caso contrario
    */
    bool Eliminar(Nodo*& actual, const T& val, T &valSube, int indicePadre, int numClavesPadre);


    /** \brief Función auxiliar que permite quitar un elemento en un nodo
    *   \param Nodo* actual Direccion del nodo donde se eliminara un elemento
    *   \param int k indice donde se encuentra el elemento a eliminar el elemento
    */
    void QuitarNodo(Nodo* actual, int k);



};

#include "ArbolB+.tpp"


#endif // ARBOLB+_H_INCLUDED
