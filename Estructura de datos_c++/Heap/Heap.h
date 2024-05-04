#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED
#include <stdexcept>

#define NO_ELEMENT -1 /**< Symbolic constant that determines the NO ELEMENT state in the Heap */

template <typename T>
bool minimum(const T &a, const T &b){
    return a <= b;
}
template <typename T>
bool maximum(const T &a, const T &b){
    return a >= b;
}


/** \class Heap
*   Heap of items. Can be Maximum or Minimum
*   \tparam T Type of items.
*   \tparam bool(*Order)(const T &a, const T &b) Fuction pointer then indicates the type of order in the heap
*/
template <typename T,bool(*Order)(const T &a, const T &b) = minimum>
class Heap{


    public:

        /** \brief Default constructor. Build an empty Heap.
        */
        Heap(); //Costructor

        /** \brief Copy Constructor. Copy all parameters from one Heap to another
        */
        Heap(const Heap<T,Order> &h);

        /** \brief Destructor
        */
        ~Heap();

        /** \brief Operator Function. Copy all parameters from one Heap to another
        *   \param Heap<T,Order>&h Heap to copy.
        *   \return Heap<T,Order>& The Heap reference to copy.
        */
        Heap<T,Order>& operator=(const Heap<T,Order> &h);

        /** \brief Add a new item to the Heap.
        * \param T Value Item to add.
        */
        void Push(const T& value); // Agregar Elemento


        /** \brief Remove an item from the Heap.
        * \exception Heap::EmptyHeap. When the Heap is Empty.
        */
        void Pop(); // Eliminar elemento

        /** \brief Clean the heap.
        */
        void Clear(); // Limpia la

        /** \brief Reveals the last item in the heap.
        *   \exception Heap::EmptyHeap. When the Heap is Empty.
        *   \return T The reference of the last item in the Heap.
        */
        const T& Top() const; // Conocer tope

        /** \brief Reveals the number of items in the Heap.
        *   \return unsigned Number of items in the Heap.
        */
        unsigned Size() const; //

        /** \brief Reveals if the Heap is empty.
        *   \return bool true If the Heap is empty. False if it contains at least one item.
        */
        bool Empty() const; // Conocer si esta vacio



        /** \brief Print the items in the heap. From the bottom to the top (for testing only)
        */
        void Print() const; /* ----Para pruebas ----*/

        /** \brief Reveals the Heap capacity
        *   \return const int The Heap Capacity number
        */
        const int Capacity() const;

        /** \brief Reveals the first item in the heap.
        *   \exception Heap::EmptyHeap. When the Heap is Empty.
        *   \return T The reference of the first item in the Heap.
        */
        const T& Root() const;

        /* Exceptions */


        /** \class EmptyHeap
        *   Exception thrown when trying to remove items in a stack
        */
        class EmptyHeap : public std::exception {
        public:
            virtual const char* what() const throw();
        };



    private:
        int top,cap; /**< Indicates the position of the last item of the heap */
        T *content; /**< Heap Item Container */

        /** \brief Resize the Heap when is full
        */
        void Resize();

        /** \brief Reveals if the Heap is full.
        *   \return bool true If the Heap is full. False if theres is space in the heap.
        */
        bool Full() const; // Conocer si esta lleno

        /** \brief Helper method that is in charge of sorting the values in the heap when an element is added
        *
        */
        void Push_Up();

        /** \brief Helper recursive method that is in charge of sorting the values in the heap when an element is removed
        *   \param i Index of the subtree to order
        */
        void Push_Down(int i);



};
#include "Heap.tpp"


#endif // HEAP_H_INCLUDED
