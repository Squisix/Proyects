/*
    \Name: Grafica.h
    \Author: Marco Antonio Guerrero Vasquez // 219202704
    \Date: 09/04/21
    \brief: Archivo de cabecera donde se encuentra definida la clase Grafica.
*/

#ifndef GRAFICA_H_INCLUDED
#define GRAFICA_H_INCLUDED
#include "LinkedDataQueue.h"
#include "LinkedDataStack.h"
template <typename T>
class Grafica{
    public:

        /** \brief Constructor
        */
        Grafica(); //

        /** \brief Constructor de copias
        */
        Grafica(const Grafica<T> &g); //

        /** \brief Destructor
        */
        ~Grafica(); //

        /** \brief Operador de Funci�n. Copia todos los parametros de una Grafica a otra.
        *   \param const Grafica<T> &g Grafica a copiar.
        *   \return Grafica<T>& Referencia a Grafica a copiar.
        */
        Grafica<T>& operator=(const Grafica<T> &g); //

        /** \brief Permite agregar un Nodo en una Gr�fica (sin repetici�n)
        *   \param const T& id El id del nodo a agregar
        *   \return bool True si se agreg� el nodo a la grafica, false en caso contrario.
        */
        bool Agregar(const T& id); //

        /** \brief Permite agregar una arista en una Gr�fica (sin repetici�n)
        *   \param const T& inicio El id del nodo inicial de la arista.
        *   \param const T& fin El id del nodo final de la arista.
        *   \return bool True si se agreg� la arista a la grafica, false en caso contrario.
        */
        bool Agregar(const T& inicio, const T& fin); //

        /** \brief Permite Eliminar un Nodo en una Gr�fica (incluyendo aristas)
        *   \param const T& id El id del nodo a eliminar.
        *   \return bool True si se elimin� la arista a la grafica, false en caso contrario.
        */
        bool Eliminar(const T& id); //

        /** \brief Permite eliminar una arista en una Gr�fica.
        *   \param const T& inicio El id del nodo inicial de la arista.
        *   \param const T& fin El id del nodo final de la arista.
        *   \return bool True si se elimin� la arista a la grafica, false en caso contrario.
        */
        bool Eliminar(const T& inicio, const T& fin); //

        /** \brief Permite conocer el numero de nodos de la que hay en la gr�fica
        *   \return Numero de nodos en la grafica.
        */
        unsigned ObtenerNumNodos() const; //

        /** \brief Permite conocer el numero de aristas de la que hay en la gr�fica
        *   \return Numero de aristas en la grafica.
        */
        unsigned ObtenerNumAristas() const; //

        /** \brief Permite conocer el grado de un Nodo.
        *   \param const T& _id Id del nodo al que se le obtendra el grado.
        *   \return Grado del nodo, en caso de no encontrarse el nodo en la gr�fica devuelve -1
        */
        int ObtenerGrado(const T& _id) const; //

        /** \brief Permite conocer si un Nodo se encuentra en la gr�fica.
        *   \param const T& _id Id del nodo a buscar.
        *   \return True si el nodo est� en la gr�fica, false en caso contrario.
        */
        bool Buscar(const T& _id) const; //

        /** \brief Permite conocer si una arista se encuentra en la gr�fica.
        *   \param const T& inicio Id del nodo a inicial de la arista.
        *   \param const T& fin Id del nodo final de la arista.
        *   \return True si la arista est� en la gr�fica, false en caso contrario.
        */
        bool Buscar(const T& inicio, const T& fin) const; //

        /** \brief Metodo que muestra la gr�fica en pantalla.
        */
        void Imprimir() const; //

        /** \brief Permite conocer si la gr�fica est� vacia.
        *   \return bool True si Esta vacia, false si se encuentra al menos un nodo.
        */
        bool EstaVacia() const; //

        /** \brief Metodo que vacia una gr�fica
        */
        void Vaciar();  //

        /** \brief Metodo que vacia un Nodo
        *   \param const T& _id Id del nodo a vaciar.
        */
        void Vaciar(const T& _id); //

        /** \brief Metodo que Imprime el paseo de Euler de una gr�fica con el m�todo de Fleury
        *   \param const T& Id del nodo donde se iniciar� el recorrido.
        */
        void AlgoritmoFleury(const T& _idInicial);


    private:

        unsigned numNodos, numAristas; /*< Numero de nodos y de aristas en la gr�fica */

        /** \struct Nodo
        *   Estructura que almacena los datos de un nodo en una gr�fica.
        *   \tparam T Type of items.
        */
        struct Nodo{
            /** Constructor de Nodo
            */
            Nodo(const T& _id, Nodo *sig = NULL);
            T id; /*< Id de Nodo*/
            Nodo *siguiente; /*< Puntero del siguiente nodo en la lista */
            int grado; /*< Grado el nodo*/

                /** \struct Arista
                *   Estructura donde se almacena los datos de una arista en un Nodo.
                *   \tparam T Type of items.
                */
                struct Arista{
                    /** Constructor de Arista
                    */
                    Arista(Nodo *_adyacente, Arista *sig = NULL);
                    Nodo *adyacente; /*< Direccion del nodo adyacente al nodo principal*/
                    Arista *siguiente; /*< Direcci�n de la siguiente arista en la lista*/
                }*primera,*ultima; /*< Direccion donde se guarda la primer y ultima arista*/

            /** \brief Metodo auxiliar que permite agregar un Nodo adyacente a la lista de vertices de un nodo
            *   \param Nodo *_adyacente Direccion del nodo adyacente al que se agregar�
            *   \return bool True si se agreg� el nodo adyacente, false en caso contrario.
            */
            bool Agregar(Nodo *_adyacente); //

            /** \brief Metodo auxiliar que permite eliminar un Nodo adyacente a la lista de vertices de un nodo
            *   \param Nodo *_adyacente Direccion del nodo adyacente al que se eliminar�
            *   \return bool True si se elimin� el nodo adyacente, false en caso contrario.
            */
            bool Eliminar(Nodo *_adyacente); //

            /** \brief Metodo auxiliar que permite buscar un Nodo adyacente a la lista de vertices de un nodo
            *   \param Nodo *_adyacente Direccion del nodo adyacente al que se buscar�
            *   \return bool True si se encontr� el nodo adyacente, false en caso contrario.
            */
            bool Buscar(Nodo *_adyacente) const; //

            /** \brief Metodo auxiliar que permite concocer la direcci�n de una arista
            *   \param Nodo *_adyacente Direccion del nodo adyacente al que esta conectado.
            *   \param Arista **pAnt Puntero a puntero donde se guarda la direccion anterior de la
            *           arista a conocer, NULL por default
            *   \return Arista* Direcci�n de la arista.
            */
            Arista *DireccionArista(Nodo *_adyacente, Arista **pAnt = NULL) const; //

        }*primero, *ultimo; /*< Direccion del primer y ultimo nodo en la lista*/

        /** \brief Metodo auxiliar que permite concocer la direcci�n de un Nodo
        *   \param const T&_id Referencia constante del id del nodo al que se busca la direcci�n.
        *   \param Nodo **pAnt Puntero a puntero donde se guarda la direccion anterior del
        *           nodo a conocer, NULL por default.
        *   \return Nodo* Direcci�n del nodo.
        */
        Nodo *DireccionNodo(const T&_id, Nodo **pAnt = NULL) const; //


};

#include "Grafica.tpp"
#endif // GRAFICA_H_INCLUDED
