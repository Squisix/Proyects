/*
    \Name: LinkedDataQueue.h
    \Author: Marco Antonio Guerrero Vasquez // 219202704
    \Date: 03/06/21
    \brief: Header file where the LinkedDataQueue class is declared.
*/
#ifndef LINKEDDATAQUEUE_H_INCLUDED
#define LINKEDDATAQUEUE_H_INCLUDED
/** \class LinkedDataQueue
*   FIFO type data structure: First in first out. It can contain any type elements.
*   \tparam T Type of items.
*/
template <typename T = int>
class LinkedDataQueue{

        /** \brief Operator Function. Helper to print the Queue (for testing only).
        *   Print the items in the Qeue from the first to the last.
        *   \param std::ostream& outflow Data stream where the Queue will be printed.
        *   \param const LinkedDataQueue<U> &q Queue to print.
        *   \return std::ostream The same stream received. Allows operator cascading application.
        */
        template <typename U>
        friend std::ostream& operator<< (std::ostream& outflow, const LinkedDataQueue<U> &q);
    public:

        /** \brief Default constructor. Build an empty Linked Data Queue.
        */
        LinkedDataQueue(); //Costructor

        /** \brief Copy Constructor. Copy all parameters from one Linked Data Queue to another
        */
        LinkedDataQueue(const LinkedDataQueue<T> &q);

        /** \brief Destructor
        */
        ~LinkedDataQueue();

        /** \brief Operator Function. Copy all parameters from one Linked Data Queue to another
        *   \param const LinkedDataQueue<T> &q Linked Data Stack Queue to copy.
        *   \return LinkedDataQueue<T>& The Linked Data Queue reference to copy.
        */
        LinkedDataQueue<T>& operator=(const LinkedDataQueue<T> &q);

        /** \brief Add a new item to the Stack.
        * \param T Value Item to add.
        */
        void Push(const T& value); // Agregar Elemento


        /** \brief Remove an item from the Queue.
        * \exception LinkedDataQueue::EmptyQueue. When the Queue is Empty.
        */
        void Pop(); // Eliminar elemento

        /** \brief Clean the Queue
        */
        void Clear(); // Limpia la pila

        /** \brief Reveals the last item in the Queue.
        *   \exception LinkedDataQueue::EmptyQueue. When the Queue is Empty.
        *   \return T The reference of the last item of the Queue.
        */
        const T& GetLast() const; // Conocer tope

        /** \brief Reveals the first item in the Queue.
        *   \exception LinkedDataQueue::EmptySQueue. When the Queue is Empty.
        *   \return T The reference of the first item of the Queue.
        */
        const T& GetFirst() const; // Conocer tope

        /** \brief Reveals the number of items in the Queue.
        *   \return unsigned Number of items in the Queue.
        */
        unsigned Size() const; // Tamaño de la pila

        /** \brief Reveals if the Queue is empty.
        *   \return bool true If the Queue is empty. False if it contains at least one item.
        */
        bool Empty() const; // Conocer si esta vacio



        /** \brief Print the items in the Queue. From the first to the last (for testing only)
        */
        void Print() const; /* ----Para pruebas ----*/


        /* Exceptions */


        /** \class EmptyQueue
        *   Exception thrown when trying to remove items in a Queue
        */
        class EmptyQueue : public std::exception {
        public:
            virtual const char* what() const throw();
        };



    private:
        unsigned qSize; /**< Indicates the Queue size */

        /** \struct Node
        *   Node where the Queue value and the address of the next node on the Queue are stored.
        *   \tparam T Type of items.
        */
        struct Node{
            T value; /**< Value to store */
            Node *next; /**< Adrees of the next node on the Queue */

            /** \brief Constructor. Build an new Node.
            *   \param const T& Value to store in the Queue.
            *   \param Node *n Adress of the next node on the Queue. Default Value = NULL.
            */
            Node(const T& val, Node *n = NULL);
        };
        Node *last; /**< Indicates the last item on the Queue */
};

#include "LinkedDataQueue.tpp"


#endif // LINKEDDATAQUEUE_H_INCLUDED
