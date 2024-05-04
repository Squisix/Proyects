#ifndef LINKEDDATASTACK_H_INCLUDED
#define LINKEDDATASTACK_H_INCLUDED

/** \class ResizableStack
*   LIFO type data structure: Last in first out. It can contain any type elements.
*   It has a maximum size defined by SIZE.
*   \tparam T Type of items.
*/
template <typename T = int>
class LinkedDataStack{

        /* Operator Overload */
        /** \brief Operator Function. Helper to print the stack (for testing only).
        *   Print the items in the stack from the bottom to the top.
        *   \param std::ostream& outflow Data stream where the stack will be printed.
        *   \param const Stack<U> &s Stack to print.
        *   \return std::ostream The same stream received. Allows operator cascading application.
        */
        template <typename U>
        friend std::ostream& operator<< (std::ostream& outflow, const LinkedDataStack<U> &s);

    public:

        /** \brief Default constructor. Build an empty Resizable Stack.
        */
        LinkedDataStack(); //Costructor

        /** \brief Copy Constructor. Copy all parameters from one Resizable Stack to another
        */
        LinkedDataStack(const LinkedDataStack<T> &s);

        /** \brief Destructor
        */
        ~LinkedDataStack();

        /** \brief Operator Function. Copy all parameters from one Resizable Stack to another
        *   \param const ResizableStack<T> &s Resizable Stack to copy.
        *   \return ResizableStack<T>& The resizable Stack reference to copy.
        */
        LinkedDataStack<T>& operator=(const LinkedDataStack<T> &s);

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


        /* Exceptions */


        /** \class EmptyStack
        *   Exception thrown when trying to remove items in a stack
        */
        class EmptyStack : public std::exception {
        public:
            virtual const char* what() const throw();
        };



    private:
        unsigned sSize; /**< Indicates the stack capacity */
        struct Node{
            T value;
            Node *next;
            Node(T val, Node *n = NULL);
        };
        Node *top; /**< Indicates the item on the top of the stack */
};

#include "LinkedDataStack.tpp"


#endif // LINKEDDATASTACK_H_INCLUDED
