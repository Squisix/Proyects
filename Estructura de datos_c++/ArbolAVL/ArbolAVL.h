/*
    \Name: ArbolAVL.h
    \Author: Marco Antonio Guerrero Vasquez // 219202704
    \Date: 22/04/21
    \brief: Archivo de Cabecera donde se definida la clase ArbolAVL
*/


#ifndef ARBOLAVL_H_INCLUDED
#define ARBOLAVL_H_INCLUDED
#include <iostream>
#include "LinkedDataQueue.h"
enum MetodoImpresion{
    ASCENDENTE,DESCENDENTE,NIVELES
};

/** \class ArbolAVL
*   Arbol de busqueda binaria Extendida: Balnaceada. Estructura de datos.
*   \tparam T Tipo de valor.
*/
template <typename T>
class ArbolAVL{

    public:
        /** \brief Constructor
        */
        ArbolAVL(); //
        /** \brief Constructor de copias
        */
        ArbolAVL(const ArbolAVL<T> &a); //

        /** \brief Destructor
        */
        ~ArbolAVL(); //

        /** \brief Operador de Función. Copia todos los parametros de un ArbolAVL a otro.
        *   \param const ArbolAVL<T> &a ArbolAVL a copiar.
        *   \return ArbolAVL<T>& Referencia a ArbolAVL a copiar.
        */
        ArbolAVL<T>& operator=(const ArbolAVL<T> &a); //

        /** \brief Permite agregar un dato en un ArbolAVL (sin repetición)
        *   \param const T& val El valor del dato a agregar
        *   \return bool True si se agregó el dato al ArbolAVL, false en caso contrario.
        */
        bool Agregar(const T &val);         //

        /** \brief Permite Eliminar un valor en un ArbolAVL, si el valor tiene hijos,
        *           este se sustituye por el Mayor de los menores.
        *   \param const T& val El valor a eliminar.
        *   \return bool True si se eliminó el valor del ArbolAVL, false en caso contrario.
        */
        bool Eliminar(const T &val);

        /** \brief Permite Eliminar todos los hijos del valor seleccionado, tanto como el valor seleccionado           este se sustituye por el Mayor de los menores.
        *   \param const T& val El valor a eliminar.
        *   \return bool True si se podó el valor del ArbolAVL, false en caso contrario.
        */
        bool Podar(const T &val);

        /** \brief Permite buscar si un valor se encuentra en el ArbolAVL.
        *   \param const T& val Valor del nodo a buscar.
        *   \return True si el nodo está en el ArbolAVL, false en caso contrario.
        */
        bool Buscar(const T &val);    //

        /** \brief Permite conocer el numero de nodos que hay en el ArbolAVL
        *   \return Numero de nodos en el ArbolAVL.
        */
        unsigned ObtenerNumNodos() const;       //

        /** \brief Permite conocer si un ArbolAVL está vacio
        *   \return true si el ArbolAVL esta vacio, false en caso contrario.
        */
        bool EstaVacia() const;

        /** \brief Metodo que vacia un ArbolAVL
        */
        void Vaciar();                          //

        /** \brief Metodo que imprime un ArbolAVL de distintas maneras seleccionables.
        *   \param const MetodoImpreion &s Elemento de tipo MetodoImpresion que
        *           permiten seleccionar la manera de imprimir los ArbolAVL.
        *           ASCENDENTE, DESCENDENTE y NIVELES.
        */
        void Imprimir(const MetodoImpresion &s) const;

        unsigned ObtenerAltura() const;


    private:
        unsigned numNodos; /*< Numero de nodos en el ArbolAVL*/

        struct Nodo{
            unsigned altura;
            int factorEquilibrio;

            T valor; /*< Valor que contiene el nodo */
            Nodo *hijoIzq, *hijoDer;    /*< Direcciones del nodo hijo izquierdo y derecho del propio nodo*/
            Nodo(T val, Nodo *Izq = NULL, Nodo *Der = NULL); /*< Constructor de nodo*/

            /** \brief Permite conocer si un nodo es hoja (no tiene hijos).
            *   \return true si el Nodo es hoja, false en caso contrario.
            */
            bool EsHoja() const;//

            /** \brief Permite conocer si un nodo tiene hijo izquierdo.
            *   \return true si el Nodo tiene hijo izquierdo, false en caso contrario.
            */
            bool TieneHijoIzq() const;//

            /** \brief Permite conocer si un nodo tiene hijo derecho.
            *   \return true si el Nodo tiene hijo derecho, false en caso contrario.
            */
            bool TieneHijoDer() const;//

        }*raiz; /*< Direccion de la raiz de un ArbolAVL*/

        /** \brief Procedimiento auxiliar recursivo que permite agregar un nodo
        *           en un ArbolAVL (sin repetición) a partir de una subraiz
        *   \param Nodo*& subraiz Referencia a puntero de la subraiz donde se agregará el nodo.
        *   \param const T& val El valor del dato a agregar
        *   \return bool True si se agregó el nodo al ArbolAVL, false en caso contrario.
        */
        bool Agregar(Nodo*& subraiz, const T &val); //

        /** \brief Procedimiento auxiliar que permite imprimir un ArbolAVL apartir de una subraiz en entreorden
        *   \param Nodo* subraiz subraiz desde donde se imprimirá el ArbolAVL
        */
        void ImprimirEntreorden(Nodo* subraiz) const; //

        /** \brief Procedimiento auxiliar que permite imprimir un ArbolAVL apartir de una subraiz en entreorden inverso
        *   \param Nodo* subraiz subraiz desde donde se imprimirá el ArbolAVL
        */
        void ImprimirEntreordenInverso(Nodo* subraiz) const; //

        /** \brief Procedimiento auxiliar que permite imprimir un ArbolAVL apartir de una subraiz por nivel
        *   \param Nodo* subraiz subraiz desde donde se imprimirá el ArbolAVL
        */
        void ImprimirPorNivel(Nodo* subraiz) const;

        /** \brief Procedimiento auxiliar que permite copiar un ArbolAVL apartir de una subraiz en preorden
        *   \param Nodo* subraiz subraiz desde donde se copiará el ArbolAVL
        */
        void CopiarPreorden(Nodo *subraiz); //

        /** \brief Procedimiento auxiliar que permite podar un ArbolAVL apartir de una subraiz de manera recursiva
        *   \param Nodo*& subraiz subraiz desde donde se podará el ArbolAVL
        */
        void Podar(Nodo*& subraiz); //

        /** \brief Procedimiento auxiliar que permite eliminar un nodo de un ArbolAVL
        *           apartir de una subraiz de manera recursiva
        *   \param Nodo*& subraiz subraiz desde donde se eliminará el nodo del ArbolAVL
        *   \param const T& val Valor que se eliminará del ArbolAVL
        *   \return true si se eliminó el elemento, false en caso contrario
        */
        bool Eliminar(Nodo*& subraiz, const T &val); //

        /** \brief Procedimiento auxiliar que permite obtener el nodo con mayor valor de un ArbolAVL
        *           apartir de una subraiz de manera recursiva
        *   \param Nodo*& subraiz subraiz desde donde se buscara el nodo mayor el nodo del ArbolAVL
        *   \return Nodo*& Dirección del nodo mayor
        */
        Nodo*& BuscarDirMayor(Nodo*& subraiz) const; //

        /** \brief Procedimiento auxiliar que permite obtener la direccion de un nodo de acuerdo al valor en un ArbolAVL
        *           apartir de una subraiz de manera recursiva
        *   \param Nodo*& subraiz subraiz desde donde se buscara el nodo del ArbolAVL
        *   \param const T& val Valor del nodo que se va a buscar
        *   \return Nodo*& Direccion del nodo buscado, Si no se encuentra se regresa NULL
        */
        Nodo*& BuscarDirNodo(Nodo*& subraiz, const T &val) const; //

        /** \brief Procedimiento auxiliar que actualiza la altura de un nodo
                y calcula el factor de equilibrio
        *   \param Nodo*& subraiz subraiz a la que se actualizara la altura
        */
        void ActualizarAltura(Nodo*& subraiz);

        /** \brief Procedimiento auxiliar que administra el balanceo de una subraiz
        *       de acuerdo a su factor de equilibrio
        *   \param Nodo*& subraiz subraiz que se balanceara
        */
        void Balancear(Nodo*& subraiz);

        /** \brief Procedimiento auxiliar que efectua una rotación simple a la izquierda
        *   \param Nodo*& subraiz subraiz a rotar
        */
        void RSI(Nodo*& subraiz);

        /** \brief Procedimiento auxiliar que efectua una rotación simple a la derecha
        *   \param Nodo*& subraiz subraiz a rotar
        */
        void RSD(Nodo*& subraiz);

};

#include "ArbolAVL.tpp"


#endif // ARBOLAVL_H_INCLUDED
