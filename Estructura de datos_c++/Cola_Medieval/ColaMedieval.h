/*
    \Name: ColaMedieval.h
    \Author: Marco Antonio Guerrero Vasquez // 219202704
    \Date: 18/03/21
    \brief: Archivo de cabecera donde se encuentra la clase Cola Medieval
*/
#ifndef COLAMEDIEVAL_H_INCLUDED
#define COLAMEDIEVAL_H_INCLUDED
#include <iostream>
#include "Persona.h"
#include "LinkedDataQueue.h"
/** \class ColaMedieval
*   Estructura de datos de tipo FIFO: Primero en entrar primero en salir. Contiene Personas.
*/
class ColaMedieval{

    public:

        /** \brief Constructor por default. Construye una cola medieval vacia.
        */
        ColaMedieval(); //Costructor

        /** \brief Constructor de copias. Copia todos los parametros de una cola medieval a otra
        */
        ColaMedieval(const ColaMedieval &cm);

        /** \brief Destructor
        */
        ~ColaMedieval();

        /** \brief Operador de Funcion. Coia todos los parametros de una Cola Medieval a otra
        *   \param const ColaMedieval &cm ColaMedieval a copiar.
        *   \return ColaMedieval& Referencia de la cola medieval a copiar.
        */
        ColaMedieval& operator=(const ColaMedieval &cm);

        /** \brief Agrega a una nueva persona a la cola.
        *   Si la persona es un noble tiene mayor prioridad que un plebeyo.
        * \param p Persona a agregar.
        */
        void Push(const Persona& p); // Agregar Elemento


        /** \brief Elimina a una persona de la cola
        * \exception ColaMedieval::EmptyQueue. Cuando la cola medieval esta vacia.
        */
        void Pop(); // Eliminar elemento

        /** \brief Limpia la cola medieval.
        */
        void Clear(); // Limpia la cola

        /** \brief Muestra el ultimo elemento de la cola medieval.
        *   \exception ColaMedieval::EmptyQueue. Cuando la cola medieval esta vacia.
        *   \return Persona& La referencia de la ultima persona de la cola.
        */
        const Persona& GetLast() const; // Conocer ultimo

        /** \brief Muestra el primer elemento de la cola medieval.
        *   \exception ColaMedieval::EmptySQueue. Cuando la cola medieval esta vacia.
        *   \return Persona& la referencia de la primera persona en la cola.
        */
        const Persona& GetFirst() const; // Conocer tope

        /** \brief Muestra el numero de elementos de la cola.
        *   \return unsigned Numero de elementos en la cola.
        */
        unsigned Size() const; // Tamaño de la cola

        /** \brief Muestra el numero total de nobles.
        *   \return unsigned Numero de nobles en la cola.
        */
        unsigned NoblesSize() const;

        /** \brief Muestra el numero total de plebeyos.
        *   \return unsigned Numero de elementos en la cola.
        */
        unsigned PlebeyosSize() const;

        /** \brief Muestra si la cola esta vacia.
        *   \return bool verdadero Si la cola mediaveal esta vacia. Falso si contiene al menos un elemento.
        */
        bool Empty() const; // Conocer si esta vacio



        /** \brief Imprime los elementos de la cola. Del primero al ultimo (for testing only)
        */
        void Print() const; /* ----Para pruebas ----*/

        /** \class EmptyQueue
        *   Excepcion lanzada cuando la cola medieval esta vacia.
        */
        class EmptyQueue : public std::exception {
        public:
            virtual const char* what() const throw();
        };


    private:
        LinkedDataQueue<Persona> Nobles; /*< Cola de datos enlazados de tipo Persona donde se guardan los Nobles*/
        LinkedDataQueue<Persona> Plebeyos; /*< Cola de datos enlazados de tipo Persona donde se guardan los Plebeyos*/
};



#endif // COLAMEDIEVAL_H_INCLUDED
