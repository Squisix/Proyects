/*
    \Name: LinkedDataStack.h
    \Author: Marco Antonio Guerrero Vasquez // 219202704
    \Date: 02/21/21
    \brief: Header file where the LinkedDataStack class is declared.
*/
#ifndef SIMPLELIST_H_INCLUDED
#define SIMPLELIST_H_INCLUDED
/** \class LinkedDataQueue
*   FIFO type data structure: First in first out. It can contain any type elements.
*   \tparam T Type of items.
*/
template <typename T>
class SimpleList{

        /** \brief Operator Function. Helper to print the stack (for testing only).
        *   Print the items in the stack from the bottom to the top.
        *   \param std::ostream& outflow Data stream where the stack will be printed.
        *   \param const Stack<U> &s Stack to print.
        *   \return std::ostream The same stream received. Allows operator cascading application.
        */
        template <typename U>
        friend std::ostream& operator<< (std::ostream& outflow, const SimpleList<U> &q);
    public:

        /** \brief Default constructor. Build an empty Linked Data Stack.
        */
        SimpleList(); //Costructor

        /** \brief Copy Constructor. Copy all parameters from one Linked Data Stack to another
        */
        SimpleList(const SimpleList<T> &l);

        /** \brief Destructor
        */
        ~SimpleList();

        /** \brief Operator Function. Copy all parameters from one Linked Data Stack to another
        *   \param const LinkedDataStack<T> &s Linked Data Stack Stack to copy.
        *   \return LinkedDataStack<T>& The Linked Data Stack Stack reference to copy.
        */
        SimpleList<T>& operator=(const SimpleList<T> &l);

        /** \brief Add a new item to the Stack.
        * \param T Value Item to add.
        */
        void Push_Front(const T& value); // Agregar Elemento

        /** \brief Add a new item to the Stack.
        * \param T Value Item to add.
        */
        void Push_Back(const T& value); // Agregar Elemento

        /** \brief Add a new item to the Stack.
        * \param T Value Item to add.
        */
        void Push_In_Pos(int pos, const T& val);


        /** \brief Remove an item from the Stack.
        * \exception Stack::EmptyStack. When the stack is Empty.
        */
        void Pop_Front(); // Eliminar elemento

        /** \brief Remove an item from the Stack.
        * \exception Stack::EmptyStack. When the stack is Empty.
        */
        void Pop_Back(); // Eliminar elemento

        /** \brief Remove an item from the Stack.
        * \exception Stack::EmptyStack. When the stack is Empty.
        */
        void Pop_In_Pos(int pos);

        /** \brief Clean the stack.
        */
        void Clear(); // Limpia la pila

        /** \brief Reveals if the Stack is empty.
        *   \return bool true If the stack is empty. False if it contains at least one item.
        */
        bool Search(const T& val) const; // Conocer si esta vacio

        /**
        */
        int Search_Pos(const T& val) const;

        /** \brief Reveals the item at the top of the stack.
        *   \exception Stack::EmptyStack. When the stack is Empty.
        *   \return T The reference of the item at the top of the stack.
        */
        const T& GetLast() const; // Conocer tope

        /** \brief Reveals the item at the top of the stack.
        *   \exception Stack::EmptyStack. When the stack is Empty.
        *   \return T The reference of the item at the top of the stack.
        */
        const T& GetFirst() const; // Conocer tope

        /**
        */
        const T& GetPos(int pos) const;

        /**
        */
        void ModifyPos(int pos, const T& val);

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

        /** \brief Operador[] sobrecargado para la clase Matriz. Rvalue
         * \param int m N@uacute;mero de columna al que se hará referencia en la matriz
         * \param const Matriz &ma Referencia de la matriz que entrará al flujo de datos
         * \return const double* Puntero constante donde se encuentra el valor del indice
         */
        const T& operator[] (int pos) const; // rvalue

        /** \brief Operador[] sobrecargado para la clase Matriz. Lvalue
         * \param int m N@uacute;mero de columna al que se hará referencia en la matriz
         * \param const Matriz &ma Referencia de la matriz que entrará al flujo de datos
         * \return double* Puntero donde se encuentra el valor del indice
         */
        T& operator[](int m); // lvalue


        /* Exceptions */


        /** \class EmptyStack
        *   Exception thrown when trying to remove items in a Queue
        */
        class EmptyList : public std::exception {
        public:
            virtual const char* what() const throw();
        };



    private:
        unsigned lSize; /**< Indicates the stack size */

        /** \struct Node
        *   Node where the stack value and the address of the next node on the stack are stored.
        *   \tparam T Type of items.
        */
        struct Node{
            T value; /**< Value to store */
            Node *next; /**< Adrees of the next node on the stack */

            /** \brief Constructor. Build an new Node.
            *   \param const T& Value to store in the stack
            *   \param Node *n Adress of the next node on the stack. Default Value = NULL.
            */
            Node(const T& val, Node *n = NULL);
        };
        Node *last, *first; /**< Indicates the item on the top of the stack */
};

#include "SimpleList.tpp"


#endif // SIMPLELIST_H_INCLUDED
