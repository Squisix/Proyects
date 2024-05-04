/*
    \Name: CompositeOrderedList.h
    \Author: Marco Antonio Guerrero Vasquez // 219202704
    \Date: 03/26/21
    \brief: Header file where the DoubleCircularList class is declared.
*/
#ifndef DOUBLECIRCULARLIST_H_INCLUDED
#define DOUBLECIRCULARLIST_H_INCLUDED
/** \class DoubleCircularList
*   Double Circular List type data structure. It can contain any type elements.
*   \tparam T Type of items.
*/
template <typename T>
class DoubleCircularList{


        /** \brief Operator Function. Helper to print the list (for testing only).
        *   Print the items in the list from the bottom to the top.
        *   \param std::ostream& outflow Data stream where the list will be printed.
        *   \param const DoubleLinkedList<U> &q list to print.
        *   \return std::ostream The same stream received. Allows operator cascading application.
        */
        template <typename U>
        friend std::ostream& operator<< (std::ostream& outflow, const DoubleCircularList<U> &l);
    public:

        /** \brief Default constructor. Build an empty Double Circular List.
        */
        DoubleCircularList(); //Costructor

        /** \brief Copy Constructor. Copy all parameters from one Composite Ordered List to another
        */
        DoubleCircularList(const DoubleCircularList<T> &l);

        /** \brief Destructor
        */
        ~DoubleCircularList();

        /** \brief Operator Function. Copy all parameters from one Composite Ordered List to another
        *   \param const CompositeOrderedList<T> &l Composite Ordered List to copy.
        *   \return CompositeOrderedList<T>& The Composite Ordered List reference to copy.
        */
        DoubleCircularList<T>& operator=(const DoubleCircularList<T> &l);

        /** \brief Add a new item to the Double circular List (next to the head).
        * \param T Value Item to add.
        */
        void Push(const T& value); // Agregar Elemento

        /** \brief Remove the value in the head and move this to the next element.
        */
        void Pop();

        /** \brief Removes the first occurrence of an item in the list
        *   \param The value to delete
        */
        void DeleteElement(const T& value);

        /** \brief Removes all occurrence of an item in the list
        *   \param The value to delete
        */
        void DeleteRepeatedElement(const T& value);

        /** \brief Search an item from the list.
        *   \return bool true If the item is in the list. False if the item is not in the list.
        */
        bool Search(const T& value) const;

        /** \brief Clean the list.
        */
        void Clear();

        /** \brief Moves the head fordward
        */
        void MoveHeadForward();

        /** \brief Moves the head backward
        */
        void MoveHeadBackward();

        /** \brief Get the head value of the list
        *   \return The head value of the list
        */
        const T& GetHead() const;

        /** \brief Modify the head value
        *   \param The value to change in the head
        */
        void ModifyHead(const T& value);

        /** \brief Reveals the number of items in the List.
        *   \return unsigned Number of items in the list.
        */
        unsigned Size() const;

        /** \brief Reveals if the List is empty.
        *   \return bool true If the list is empty. False if it contains at least one item.
        */
        bool Empty() const; // Conocer si esta vacio


        /** \brief Print the items in the list. From the bottom to the top (for testing only)
        */
        void Print() const; /* ----Para pruebas ----*/



        /* Exceptions */


        /** \class EmptyList
        *   Exception thrown when trying to remove items in a List
        */
        class EmptyList : public std::exception {
        public:
            virtual const char* what() const throw();
        };



    private:
        unsigned lSize; /**< Indicates the list size */

        /** \struct Node
        *   Node where the list value and the address of the next and previous node on the list are stored.
        *   \tparam T Type of items.
        */
        struct Node{
            T value; /**< Value to store */
            Node *next; /**< Adrees of the next node on the list */
            Node *previous; /**< Adrees of the next node on the list */

            /** \brief Constructor. Build an new Node.
            *   \param const T& Value to store in the list
            *   \param Node *n Adress of the next node on the list. Default Value = NULL.
            *   \param Node *p Adress of the previous node on the list. Default Value = NULL.
            */
            Node(const T& val, Node *n = NULL, Node *p = NULL);
        };
        Node *head; /**< Indicates the head on the circular list */
        /** \brief Auxiliar fuction to obtain the node direction of the first value founded on the list
        *   \param A constant reference of the value to search
        *   \return The node direcction of the value. If the value is not on the list return NULL.
        */
        Node* SearchDir(const T& val) const;
};

#include "DoubleCircularList.tpp"



#endif // DOUBLECIRCULARLIST_H_INCLUDED
