/*
    \Name: LinkedDataStack.h
    \Author: Marco Antonio Guerrero Vasquez // 219202704
    \Date: 02/21/21
    \brief: Header file where the LinkedDataStack class is declared.
*/
#ifndef DOUBLELINKEDLIST_H_INCLUDED
#define DOUBLELINKEDLIST_H_INCLUDED
/** \class LinkedDataQueue
*   FIFO type data structure: First in first out. It can contain any type elements.
*   \tparam T Type of items.
*/
template <typename T>
class DoubleLinkedList{

        /** \brief Operator Function. Helper to print the list (for testing only).
        *   Print the items in the list from the bottom to the top.
        *   \param std::ostream& outflow Data stream where the list will be printed.
        *   \param const DoubleLinkedList<U> &q list to print.
        *   \return std::ostream The same stream received. Allows operator cascading application.
        */
        template <typename U>
        friend std::ostream& operator<< (std::ostream& outflow, const DoubleLinkedList<U> &q);
    public:

        /** \brief Default constructor. Build an empty Double Linked list.
        */
        DoubleLinkedList(); //Costructor

        /** \brief Copy Constructor. Copy all parameters from one Double Linked List to another
        */
        DoubleLinkedList(const DoubleLinkedList<T> &l);

        /** \brief Destructor
        */
        ~DoubleLinkedList();

        /** \brief Operator Function. Copy all parameters from Double Linked List Stack to another
        *   \param const DoubleLinkedList<T> &s Double Linked List to copy.
        *   \return DoubleLinkedList<T>& The Double Linked List reference to copy.
        */
        DoubleLinkedList<T>& operator=(const DoubleLinkedList<T> &l);

        /** \brief Add a new item to the list in the first position.
        * \param T Value Item to add.
        */
        void Push_Front(const T& value); // Agregar Elemento

        /** \brief Add a new item to the list in the last position.
        * \param T Value Item to add.
        */
        void Push_Back(const T& value); // Agregar Elemento

        /** \brief Add a new item to the list in the indicated position.
        * \param int pos Position to add an element.
        * \param T Value Item to add.
        */
        void Push_In_Pos(int pos, const T& val);


        /** \brief Remove an item from the list in the first position.
        * \exception DoubleLinkedList::EmptyList. When the list is Empty.
        */
        void Pop_Front(); // Eliminar elemento

        /** \brief Remove an item from the list in the last position.
        * \exception DoubleLinkedList::EmptyList. When the list is Empty.
        */
        void Pop_Back(); // Eliminar elemento

        /** \brief Remove an item from the list.
        * \param int pos Position to remove an element.
        * \exception DoubleLinkedList::EmptyList. When the list is Empty.
        */
        void Pop_In_Pos(int pos);

        /** \brief Clean the list.
        */
        void Clear(); // Limpia la lista

        /** \brief Search an item from the list.
        *   \param const T& val The item to search.
        *   \return bool true If the item is in the list. False if the item is not in the list.
        */
        bool Search(const T& val) const; // Conocer si esta vacio

        /** \brief Search an item position from the list.
        *   \param const T& val The item to search
        *   \return The position of the element in the list, if the element is not in the list return -1.
        */
        int Search_Pos(const T& val) const;

        /** \brief Reveals the last item of the list.
        *   \exception DoubleLinkedList::EmptyList. When the list is Empty.
        *   \return T The reference of the last item of the list.
        */
        const T& GetLast() const; // Conocer tope

        /** \brief Reveals the first item at the list.
        *   \exception DoubleLinkedList::EmptyList. When the list is Empty.
        *   \return T The reference of the first item of the list.
        */
        const T& GetFirst() const; // Conocer tope

        /** \brief Reveals the item in the indicated position at the list.
        *   \param int pos Position to reveal an item.
        *   \exception DoubleLinkedList::EmptyList. When the list is Empty.
        *   \return T The reference of the item in the indicated position of the list.
        */
        const T& GetPos(int pos) const;

        /** \brief Modify the item in the indicated position at the list.
        *   \param int pos Position to reveal an item.
        *   \param const T& val New value of the item to change.
        *   \exception DoubleLinkedList::EmptyList. When the list is Empty.
        */
        void ModifyPos(int pos, const T& val);

        /** \brief Reveals the number of items in the list.
        *   \return unsigned Number of items in the list.
        */
        unsigned Size() const; // Tamaño de la pila

        /** \brief Reveals if the list is empty.
        *   \return bool true If the list is empty. False if it contains at least one item.
        */
        bool Empty() const; // Conocer si esta vacio

        /**
        *
        */
        bool IsRepeated(const T& val);



        /** \brief Print the items in the stack. From the bottom to the top (for testing only)
        */
        void Print() const; /* ----Para pruebas ----*/

        void ReversePrint() const;

        void DeleteElement(const T& val);

        void DeleteElementIf(const T& val, bool (*)(const T&));

        void DeleteRepeatedElements();

        void SortAscending();

        void Exchange(DoubleLinkedList &l);

        void Transfer(DoubleLinkedList &l);

        void TransferSince(DoubleLinkedList &l, int pos);

        void TransferSinceTo(DoubleLinkedList &l, int iPos, int fPos);

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
            Node *previous;

            /** \brief Constructor. Build an new Node.
            *   \param const T& Value to store in the stack
            *   \param Node *n Adress of the next node on the stack. Default Value = NULL.
            */
            Node(const T& val, Node *n = NULL, Node *p = NULL);
        };
        Node *last, *first; /**< Indicates the item on the top of the stack */
        Node* SearchPosDir(int pos) const;
};

#include "DoubleLinkedList.tpp"



#endif // DOUBLELINKEDLIST_H_INCLUDED
