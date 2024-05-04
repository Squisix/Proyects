/*
    \Name: ResizableStack.h
    \Author: Marco Antonio Guerrero Vasquez // 219202704
    \Date: 02/11/21
    \brief: Header file where the stack class is declared.
*/

#ifndef RESIZABLESTACK_H_INCLUDED
#define RESIZABLESTACK_H_INCLUDED

#include <stdexcept>

#define NO_ELEMENT -1 /**< Symbolic constant that determines the NO ELEMENT state in the stack */

/** \class ResizableStack
*   LIFO type data structure: Last in first out. It can contain any type elements.
*   It has a maximum size defined by SIZE.
*   \tparam T Type of items.
*/
template <typename T = int>
class ResizableStack{

        /* Operator Overload */
        /** \brief Operator Function. Helper to print the stack (for testing only).
        *   Print the items in the stack from the bottom to the top.
        *   \param std::ostream& outflow Data stream where the stack will be printed.
        *   \param const Stack<U> &s Stack to print.
        *   \return std::ostream The same stream received. Allows operator cascading application.
        */
        template <typename U>
        friend std::ostream& operator<< (std::ostream& outflow, const ResizableStack<U> &s);

    public:

        /** \brief Default constructor. Build an empty Resizable Stack.
        */
        ResizableStack(); //Costructor

        /** \brief Copy Constructor. Copy all parameters from one Resizable Stack to another
        */
        ResizableStack(const ResizableStack<T> &s);

        /** \brief Destructor
        */
        ~ResizableStack();

        /** \brief Operator Function. Copy all parameters from one Resizable Stack to another
        *   \param const ResizableStack<T> &s Resizable Stack to copy.
        *   \return ResizableStack<T>& The resizable Stack reference to copy.
        */
        ResizableStack<T>& operator=(const ResizableStack<T> &s);

        /** \brief Add a new item to the Stack.
        * \param T Value Item to add.
        */
        void Push(const T& value); // Agregar Elemento


        /** \brief Remove an item from the Stack.
        * \exception Stack::EmptyStack. When the stack is Empty.
        * \return bool True if an item could be removed to the stack
        */
        void Pop(); // Eliminar elemento

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



        /** \brief Print the items in the stack. From the bottom to the top (for testing only)
        */
        void Print() const; /* ----Para pruebas ----*/

        /** \brief Reveals the Stack Capacity
        *   \return const int The Stack Capacity number
        */
        const int Capacity() const;

        /* Exceptions */


        /** \class EmptyStack
        *   Exception thrown when trying to remove items in a stack
        */
        class EmptyStack : public std::exception {
        public:
            virtual const char* what() const throw();
        };



    private:
        int top,cap; /**< Indicates the position of the item on the top of the stack */
        T *content; /**< Stack Item Container */

        /** \brief Resize the Stack when is full
        */
        void Resize();

        /** \brief Reveals if the Stack is full.
        *   \return bool true If the stack is full. False if theres is space in the stack.
        */
        bool Full() const; // Conocer si esta lleno





};
#include "ResizableStack.tpp"




#endif // RESIZABLESTACK_H_INCLUDED
