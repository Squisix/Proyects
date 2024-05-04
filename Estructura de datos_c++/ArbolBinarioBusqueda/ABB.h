/*
    \Name: Grafica.h
    \Author: Marco Antonio Guerrero Vasquez // 219202704
    \Date: 14/04/21
    \brief: Archivo de cabecera donde se encuentra definida la clase ABB.
*/
#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED
#include <iostream>
#include "LinkedDataQueue.h"
enum MetodoImpresion{
    ASCENDENTE,DESCENDENTE,NIVELES
};

/** \class ABB
*   Arbol de busqueda binaria. Estructura de datos.
*   \tparam T Tipo de valor.
*/
template <typename T>
class ABB{

    public:
        /** \brief Constructor
        */
        ABB(); //
        /** \brief Constructor de copias
        */
        ABB(const ABB<T> &a); //

        /** \brief Destructor
        */
        ~ABB(); //

        /** \brief Operador de Función. Copia todos los parametros de un ABB a otro.
        *   \param const ABB<T> &a ABB a copiar.
        *   \return ABB<T>& Referencia a ABB a copiar.
        */
        ABB<T>& operator=(const ABB<T> &a); //

        /** \brief Permite agregar un dato en un ABB (sin repetición)
        *   \param const T& val El valor del dato a agregar
        *   \return bool True si se agregó el dato al ABB, false en caso contrario.
        */
        bool Agregar(const T &val);         //

        /** \brief Permite Eliminar un valor en un ABB, si el valor tiene hijos,
        *           este se sustituye por el Mayor de los menores.
        *   \param const T& val El valor a eliminar.
        *   \return bool True si se eliminó el valor del ABB, false en caso contrario.
        */
        bool Eliminar(const T &val);

        /** \brief Permite Eliminar todos los hijos del valor seleccionado, tanto como el valor seleccionado           este se sustituye por el Mayor de los menores.
        *   \param const T& val El valor a eliminar.
        *   \return bool True si se podó el valor del ABB, false en caso contrario.
        */
        bool Podar(const T &val);

        /** \brief Permite buscar si un valor se encuentra en el ABB.
        *   \param const T& val Valor del nodo a buscar.
        *   \return True si el nodo está en el ABB, false en caso contrario.
        */
        bool Buscar(const T &val);    //

        /** \brief Permite conocer el numero de nodos que hay en el ABB
        *   \return Numero de nodos en el ABB.
        */
        unsigned ObtenerNumNodos() const;       //

        /** \brief Permite conocer si un ABB está vacio
        *   \return true si el ABB esta vacio, false en caso contrario.
        */
        bool EstaVacia() const;

        /** \brief Metodo que vacia un ABB
        */
        void Vaciar();                          //

        /** \brief Metodo que imprime un ABB de distintas maneras seleccionables.
        *   \param const MetodoImpreion &s Elemento de tipo MetodoImpresion que
        *           permiten seleccionar la manera de imprimir los ABB.
        *           ASCENDENTE, DESCENDENTE y NIVELES.
        */
        void Imprimir(const MetodoImpresion &s) const;


    private:
        unsigned numNodos; /*< Numero de nodos en el ABB*/

        struct Nodo{
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

        }*raiz; /*< Direccion de la raiz de un ABB*/

        /** \brief Procedimiento auxiliar recursivo que permite agregar un nodo
        *           en un ABB (sin repetición) a partir de una subraiz
        *   \param Nodo*& subraiz Referencia a puntero de la subraiz donde se agregará el nodo.
        *   \param const T& val El valor del dato a agregar
        *   \return bool True si se agregó el nodo al ABB, false en caso contrario.
        */
        bool Agregar(Nodo*& subraiz, const T &val); //

        /** \brief Procedimiento auxiliar que permite imprimir un ABB apartir de una subraiz en entreorden
        *   \param Nodo* subraiz subraiz desde donde se imprimirá el ABB
        */
        void ImprimirEntreorden(Nodo* subraiz) const; //

        /** \brief Procedimiento auxiliar que permite imprimir un ABB apartir de una subraiz en entreorden inverso
        *   \param Nodo* subraiz subraiz desde donde se imprimirá el ABB
        */
        void ImprimirEntreordenInverso(Nodo* subraiz) const; //

        /** \brief Procedimiento auxiliar que permite imprimir un ABB apartir de una subraiz por nivel
        *   \param Nodo* subraiz subraiz desde donde se imprimirá el ABB
        */
        void ImprimirPorNivel(Nodo* subraiz) const;

        /** \brief Procedimiento auxiliar que permite copiar un ABB apartir de una subraiz en preorden
        *   \param Nodo* subraiz subraiz desde donde se copiará el ABB
        */
        void CopiarPreorden(Nodo *subraiz); //

        /** \brief Procedimiento auxiliar que permite podar un ABB apartir de una subraiz de manera recursiva
        *   \param Nodo*& subraiz subraiz desde donde se podará el ABB
        */
        void Podar(Nodo*& subraiz); //

        /** \brief Procedimiento auxiliar que permite eliminar un nodo de un ABB
        *           apartir de una subraiz de manera recursiva
        *   \param Nodo*& subraiz subraiz desde donde se eliminará el nodo del ABB
        *   \param const T& val Valor que se eliminará del ABB
        *   \return true si se elimin´p el elemento, false en caso contrario
        */
        bool Eliminar(Nodo*& subraiz, const T &val); //

        /** \brief Procedimiento auxiliar que permite obtener el nodo con mayor valor de un ABB
        *           apartir de una subraiz de manera recursiva
        *   \param Nodo*& subraiz subraiz desde donde se buscara el nodo mayor el nodo del ABB
        *   \return Nodo*& Dirección del nodo mayor
        */
        Nodo*& BuscarDirMayor(Nodo*& subraiz) const; //

        /** \brief Procedimiento auxiliar que permite obtener la direccion de un nodo de acuerdo al valor en un ABB
        *           apartir de una subraiz de manera recursiva
        *   \param Nodo*& subraiz subraiz desde donde se buscara el nodo del ABB
        *   \param const T& val Valor del nodo que se va a buscar
        *   \return Nodo*& Direccion del nodo buscado, Si no se encuentra se regresa NULL
        */
        Nodo*& BuscarDirNodo(Nodo*& subraiz, const T &val) const; //





};

#include "ABB.tpp"
#endif // ABB_H_INCLUDED
