#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdexcept>

//#define SIZE 15 /**< Symbolic constant that determines the maximum size of the item container in the stack */
#define NO_ELEMENT -1 /**< Symbolic constant that determines the NO ELEMENT state in the stack */

/** \class Stack
*   LIFO type data structure: Last in first out. It can contain any type elements.
*   It has a maximum size defined by SIZE.
*   \tparam T Type of items.
*   \param s Size of stack container.
*/
template <typename T = int, unsigned s = 10>
class Stack{

    /* Operator Overload */
    /** \brief Operator Fuction. Helper to print the stack (for testing only).
        *   Print the items in the stack from the bottom to the top.
        *   \param std::ostream& outflow Data stream where the stack will be printed.
        *   \param const Stack<T> &s Stack to print.
        *   \return std::ostream The same stream received. Allows operator cascading application.
        */
        template <typename U, unsigned a>
        friend std::ostream& operator<< (std::ostream& outflow, const Stack<U,a> &stck);

    public:

        /** \brief Default constructor. Build an empty Stack.
        */
        Stack(); //Costructor

        /** \brief Add a new item to the Stack.
        * \param T Value Item to add.
        * \exception Stack::FullStack. When the stack is Full.
        * \return bool True if an item could be added to the stack
        */
        bool Push(T value); // Agregar Elemento


        /** \brief Remove an item from the Stack.
        * \exception Stack::EmptyStack. When the stack is Empty.
        * \return bool True if an item could be removed to the stack
        */
        bool Pop(); // Eliminar elemento

        /** \brief Clean the stack.
        */
        void Clear(); // Limpia la pila

        /** \brief Reveals the item at the top of the stack.
        *   \exception Stack::EmptyStack. When the stack is Empty.
        *   \return T The reference of the item at the top of the stack.
        */
        const T& Top() const; // Conocer tope

        /** \brief Reveals the number of items in the Stack.
        *   \return unsigned Number of items in the stack.
        */
        unsigned Size() const; // Tamaño de la pila

        /** \brief Reveals if the Stack is empty.
        *   \return bool true If the stack is empty. False if it contains at least one item.
        */
        bool Empty() const; // Conocer si esta vacio

        /** \brief Reveals if the Stack is full.
        *   \return bool true If the stack is full. False if theres is space in the stack.
        */
        bool Full() const; // Conocer si esta lleno

        /** \brief Print the items in the stack. From the bottom to the top (for testing only)
        */
        void Print() const; /* ----Para pruebas ----*/


        /* Exceptions */
        /** \class FullStack
        *   Exception thrown when trying to add items to a stack
        */
        class FullStack : public std::exception {
        public:
            virtual const char* what() const throw();
        };

        /** \class EmptyStack
        *   Exception thrown when trying to remove items in a stack
        */
        class EmptyStack : public std::exception {
        public:
            virtual const char* what() const throw();
        };



    private:
        int top; /**< Indicates the position of the item on the top of the stack */
        T content[s]; /**< Stack Item Container */




};
#include "Stack.tpp"
#endif // STACK_H_INCLUDED
