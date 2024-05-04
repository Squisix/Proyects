/*
    \Name: Grafica.h
    \Author: Marco Antonio Guerrero Vasquez // 219202704
    \Date: 09/04/21
    \brief: Archivo de Plantilla donde se ecnuentran declaradas las funciones y operadores de la clase Grafica.
*/

#include <iostream>
template <typename T>
Grafica<T>::Grafica():numNodos(0),numAristas(0),primero(NULL),ultimo(NULL){
}
/////////////////////////////////////////////////////////////////////////////////
template <typename T>
Grafica<T>::Grafica(const Grafica<T> &g):numNodos(0),numAristas(0),primero(NULL),ultimo(NULL){
    *this = g;
}
////////////////////////////////////////////////////////////////////////////////////
template <typename T>
Grafica<T>::~Grafica(){
    Vaciar();
}
////////////////////////////////////////////////////////////////////////////////////
template <typename T>
Grafica<T>& Grafica<T>::operator=(const Grafica<T> &g){
    if(this == &g) return *this;
    Vaciar();
    Nodo *auxNodo = g.primero;
    while(auxNodo != NULL){
        Agregar(auxNodo->id);
        auxNodo = auxNodo->siguiente;
    }
    auxNodo = g.primero;
    while(auxNodo != NULL){
        typename Nodo::Arista *auxArista = auxNodo->primera;
        while(auxArista != NULL){
            if(!Buscar(auxNodo->id, auxArista->adyacente->id))
                Agregar(auxNodo->id, auxArista->adyacente->id);
            auxArista = auxArista->siguiente;
        }
        auxNodo = auxNodo->siguiente;
    }
    return *this;
}
//////////////////////////////////////////////////////////////////////////////////
template <typename T>
bool Grafica<T>::Agregar(const T& _id){
    if(Buscar(_id)) return false;
    Nodo *nuevo = new Nodo(_id);
    if(numNodos == 0) primero = nuevo;
    else ultimo->siguiente = nuevo;
    ultimo = nuevo;
    ++numNodos;
    return true;
}
//////////////////////////////////////////////////////////////////////////////////
template <typename T>
bool Grafica<T>::Agregar(const T& inicio, const T& fin){
    typename Grafica<T>::Nodo* dirNodoInicio = DireccionNodo(inicio);
    if(dirNodoInicio == NULL) return false;
    Nodo* dirNodoFin = DireccionNodo(fin);
    if(dirNodoFin == NULL) return false;

    if(!dirNodoInicio->Agregar(dirNodoFin)) return false;
    if(!dirNodoFin->Agregar(dirNodoInicio)) return false;
    ++numAristas;
    return true;
}
/////////////////////////////////////////////////////////////////////////////////
template <typename T>
bool Grafica<T>::Nodo::Agregar(Nodo *_adyacente){
    if(Nodo::Buscar(_adyacente)) return false;
    typename Grafica<T>::Nodo::Arista *nueva = new Grafica<T>::Nodo::Arista(_adyacente);
    if(grado == 0) Nodo::primera = nueva;
    else Nodo::ultima->siguiente = nueva;
    Nodo::ultima = nueva;
    ++grado;
    return true;
}
/////////////////////////////////////////////////////////////////////////////////
template <typename T>
bool Grafica<T>::Eliminar(const T& _id){

    Nodo *ant, *porSalir = DireccionNodo(_id, &ant);

    if(porSalir == NULL) return false;

    Vaciar(_id);

    if(ant == NULL) primero = primero->siguiente;
    else ant->siguiente = porSalir->siguiente;
    if(primero == NULL) ultimo = NULL;
    delete porSalir;

    --numNodos;
    return true;
}
/////////////////////////////////////////////////////////////////////////////////
template <typename T>
bool Grafica<T>::Eliminar(const T& inicio, const T& fin){
    Nodo* dirNodoInicio = DireccionNodo(inicio);
    if(dirNodoInicio == NULL) return false;
    Nodo* dirNodoFin = DireccionNodo(fin);
    if(dirNodoFin == NULL) return false;

    if(!dirNodoInicio->Eliminar(dirNodoFin)) return false;
    if(!dirNodoFin->Eliminar(dirNodoInicio)) return false;
    --numAristas;
    return true;
}
////////////////////////////////////////////////////////////////////////////////
template <typename T>
bool Grafica<T>::Nodo::Eliminar(Nodo *_adyacente){
    Arista *ant, *aux = DireccionArista(_adyacente, &ant);
    if(aux == NULL) return false;
    if(ant == NULL) primera = primera->siguiente;
    else ant->siguiente = aux->siguiente;
    if(primera == NULL) ultima = NULL;
    delete aux;
    --grado;
    return true;
}
////////////////////////////////////////////////////////////////////////////////
template <typename T>
bool Grafica<T>::Buscar(const T& _id) const{
    Nodo* aux = primero;
    while(aux != NULL && aux->id != _id) aux = aux->siguiente;
    return aux != NULL;
}

////////////////////////////////////////////////////////////////////////////////
template <typename T>
bool Grafica<T>::Buscar(const T& inicio, const T& fin) const{
    Nodo* dirNodoInicio = DireccionNodo(inicio);
    if(dirNodoInicio == NULL) return false;
    Nodo* dirNodoFin = DireccionNodo(fin);
    if(dirNodoFin == NULL) return false;
    return dirNodoInicio->Buscar(dirNodoFin);
}
////////////////////////////////////////////////////////////////////////////////
template <typename T>
bool Grafica<T>::Nodo::Buscar(Nodo *_adyacente) const{

    typename Grafica<T>::Nodo::Arista* aux = primera;

    while(aux != NULL && aux->adyacente != _adyacente) aux = aux->siguiente;
    return aux != NULL;
}
//////////////////////////////////////////////////////////////////////////////////
template <typename T>
typename Grafica<T>::Nodo::Arista* Grafica<T>::Nodo::DireccionArista(typename Grafica<T>::Nodo *_adyacente,
                                                                     typename Grafica<T>::Nodo::Arista **pAnt /*=NULL*/) const{
    typename Grafica<T>::Nodo::Arista *aux = primera;
    if(pAnt != NULL) *pAnt = NULL;
    while(aux != NULL && aux->adyacente != _adyacente){
        if(pAnt != NULL) *pAnt=aux;
        aux=aux->siguiente;
    }
    return aux;
}
///////////////////////////////////////////////////////////////////////////////////
template <typename T>
typename Grafica<T>::Nodo* Grafica<T>::DireccionNodo(const T& _id, Nodo **pAnt /*=NULL*/) const{

    typename Grafica<T>::Nodo *aux = primero;
    if(pAnt != NULL) *pAnt = NULL;
    while(aux != NULL && aux->id != _id){
        if(pAnt != NULL) *pAnt = aux;
        aux = aux->siguiente;
    }
    return aux;
}
////////////////////////////////////////////////////////////////////////////////////
template <typename T>
unsigned Grafica<T>::ObtenerNumNodos() const{
    return numNodos;
}
////////////////////////////////////////////////////////////////////////////////////
template <typename T>
unsigned Grafica<T>::ObtenerNumAristas() const{
    return numAristas;
}
////////////////////////////////////////////////////////////////////////////////////
template <typename T>
int Grafica<T>::ObtenerGrado(const T& _id) const{
    if(!Buscar(_id) || EstaVacia()) return -1;
    Nodo *aux = primero;
    while(aux->id!=_id)
        aux = aux->siguiente;
    return aux->grado;
}
////////////////////////////////////////////////////////////////////////////////////
template <typename T>
void Grafica<T>::Imprimir() const{


    if(!EstaVacia()){
        Nodo *auxNodo = primero;
        while(auxNodo != NULL){
            std::cout << "["<< auxNodo->id << "]->";
            typename Grafica<T>::Nodo::Arista *auxArista = auxNodo->primera;
            while(auxArista != NULL){
                std::cout << "[" << auxArista->adyacente->id << "]";
                auxArista = auxArista->siguiente;
            }
            std::cout << std::endl;
            auxNodo = auxNodo->siguiente;
        }
    }else std::cout << "Grafica Vacia..." << std::endl;
}
///////////////////////////////////////////////////////////////////////////////////
template <typename T>
bool Grafica<T>::EstaVacia() const{
    return numNodos == 0;
}
///////////////////////////////////////////////////////////////////////////////////
template <typename T>
void Grafica<T>::Vaciar(){
    if(!EstaVacia()){
        Grafica<T>::Nodo *aux = primero;
        while(aux != NULL){
            Eliminar(aux->id);
            aux = primero;
        }
    }
}
///////////////////////////////////////////////////////////////////////////////////
template <typename T>
void Grafica<T>::Vaciar(const T& _id){
    if(!Buscar(_id) || EstaVacia()) return;

    Nodo *auxNodo = DireccionNodo(_id);
    typename Grafica<T>::Nodo::Arista *auxArista = auxNodo->primera;
    while(auxArista != NULL){
        Eliminar(auxNodo->id,auxArista->adyacente->id);
        auxArista = auxNodo->primera;
    }
}
////////////////////////////////////////////////////////////////////////////////////
template <typename T>
Grafica<T>::Nodo::Nodo(const T& _id, Nodo *sig /*=NULL*/):id(_id),siguiente(sig),grado(0),primera(NULL),ultima(NULL){
}
////////////////////////////////////////////////////////////////////////////////////
template <typename T>
Grafica<T>::Nodo::Arista::Arista(Nodo *_adyacente, Arista *sig /*=NULL*/):adyacente(_adyacente),siguiente(sig){
}
////////////////////////////////////////////////////////////////////////////////////
template <typename T>
void Grafica<T>::AlgoritmoFleury(const T& _idInicial){
    if(!Buscar(_idInicial)||EstaVacia()){
        std::cout << "No se encuentra el Nodo..." << std::endl;
        return;
    }
    Grafica<T> aux = *this;
    Nodo* v_c = aux.DireccionNodo(_idInicial);

    Nodo *w, *k, *v_p = v_c;
    LinkedDataQueue<T> Cola;
    LinkedDataStack<T> Pila;
    Cola.Push(v_c->id);
    Pila.Push(v_p->id);

    while(v_c->grado != 0 && v_p->grado != 0){
        typename Grafica<T>::Nodo::Arista *auxArista = v_c->primera;

        if(v_c->grado != 0){
            while(auxArista != NULL && auxArista->adyacente->grado == 1){
                auxArista = auxArista->siguiente;
            }
            if(auxArista != NULL){
                w = auxArista->adyacente;
                Cola.Push(w->id);
                aux.Eliminar(v_c->id,w->id);
                v_c = w;
            }

        }

        if(v_p->grado == 1){
            k = v_p->primera->adyacente;
            aux.Eliminar(v_p->id,k->id);
            Pila.Push(k->id);
            v_p = k;
        }

    }

    while(!Cola.Empty()){
        std::cout << "(" << Cola.GetFirst() << ")\257";
        Cola.Pop();
    }
    Pila.Pop();
    while(!Pila.Empty()){
        std::cout <<"(" << Pila.Top() << ")\257";
        Pila.Pop();
    }
    std::cout << "\b " <<std::endl;

}
