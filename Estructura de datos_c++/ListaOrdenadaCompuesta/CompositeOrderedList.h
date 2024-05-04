/*
    \Name: CompositeOrderedList.h
    \Author: Marco Antonio Guerrero Vasquez // 219202704
    \Date: 03/20/21
    \brief: Header file where the CompositeOrderedList class is declared.
*/
#ifndef COMPOSITEORDEREDLIST_H_INCLUDED
#define COMPOSITEORDEREDLIST_H_INCLUDED
#include "DoubleLinkedList.h"
/** \class CompositeOrderedList
*   Ordered List type data structure. It can contain any type elements.
*   \tparam T Type of items.
*/
template <typename T>
class CompositeOrderedList{

    public:

        /** \brief Default constructor. Build an empty Composite Ordered List.
        */
        CompositeOrderedList(); //Costructor

        /** \brief Copy Constructor. Copy all parameters from one Composite Ordered List to another
        */
        CompositeOrderedList(const CompositeOrderedList<T> &l);

        /** \brief Destructor
        */
        ~CompositeOrderedList();

        /** \brief Operator Function. Copy all parameters from one Composite Ordered List to another
        *   \param const CompositeOrderedList<T> &l Composite Ordered List to copy.
        *   \return CompositeOrderedList<T>& The Composite Ordered List reference to copy.
        */
        CompositeOrderedList<T>& operator=(const CompositeOrderedList<T> &l);

        /** \brief Add a new item to the Ordered List.
        * \param T Value Item to add.
        */
        void Push(const T& value); // Agregar Elemento

        /** \brief Remove the indicated value from the list.
        * \param T Value to remove.
        */
        void Pop(const T& val);

        /** \brief Search an item from the list.
        *   \return bool true If the item is in the list. False if the item is not in the list.
        */
        bool Search(const T& val) const;


        /** \brief Clean the list.
        */
        void Clear();

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

        /** \brief Print the items in the list. From the top to the bottom (for testing only)
        */
        void ReversePrint() const;


        /* Exceptions */


        /** \class EmptyList
        *   Exception thrown when trying to remove items in a List
        */
        class EmptyList : public std::exception {
        public:
            virtual const char* what() const throw();
        };



    private:
        DoubleLinkedList<T> OrderedList; /*< Unordered list where the data will be stored */
};

#include "CompositeOrderedList.tpp"

#endif // COMPOSITEORDEREDLIST_H_INCLUDED
