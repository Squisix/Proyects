#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

class Stack {
    public:
        Stack(); //Costructor
        void Push(double x); // Agregar Elemento
        void Pop(); // Eliminar elemento
        void Clear(); // Limpia la pila
        double Top() const; // Conocer tope
        int Size() const; // Tamaño de la pila
        bool Empty() const; // Conocer si esta vacio
        bool Full() const; // Conocer si esta lleno
        void Print() const; /* ----Para pruebas ----*/



    private:
        int tope; //indice
        double contenido[50];




};


#endif // PILA_H_INCLUDED
