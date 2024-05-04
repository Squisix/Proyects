/*
    \Name: Grafica.h
    \Author: Marco Antonio Guerrero Vasquez // 219202704
    \Date: 14/04/21
    \brief: Archivo de Plantilla donde se encuentran
            declaradas las funciones y operadores de la clase ABB.
*/
///////////////////////////////////////////////////////////////////
template <typename T>
ABB<T>::ABB():numNodos(0),raiz(NULL){
}
 ///////////////////////////////////////////////////////////////////
template <typename T>
ABB<T>::ABB(const ABB<T> &a):numNodos(0),raiz(NULL){
    *this = a;
}
///////////////////////////////////////////////////////////////////
template<typename T>
ABB<T>::~ABB(){
    Vaciar();
}
///////////////////////////////////////////////////////////////////
template <typename T>
ABB<T>& ABB<T>::operator=(const ABB<T> &a){
    if(this == &a) return *this;
    Vaciar();
    CopiarPreorden(a.raiz);
    return *this;
}
///////////////////////////////////////////////////////////////////
template <typename T>
bool ABB<T>::Agregar(const T &val){
    return Agregar(raiz,val);
}
///////////////////////////////////////////////////////////////////
template <typename T>
bool ABB<T>::Agregar(Nodo*& subraiz, const T &val){
    if(subraiz == NULL){
        subraiz = new Nodo(val);
        ++numNodos;
        return true;

    }else if (val == subraiz->valor) return false;
    else return Agregar(val < subraiz->valor ? subraiz->hijoIzq:subraiz->hijoDer, val);

}
///////////////////////////////////////////////////////////////////
template <typename T>
bool ABB<T>::Eliminar(const T &val){
    return Eliminar(raiz,val);
}
///////////////////////////////////////////////////////////////////
template <typename T>
void ABB<T>::Imprimir(const MetodoImpresion &s) const{

    switch(s){
        case ASCENDENTE:{
            ImprimirEntreorden(raiz);
            std::cout << "\b\b.";
            break;
        }
        case DESCENDENTE:{
            ImprimirEntreordenInverso(raiz);
            std::cout << "\b\b.";
            break;
        }
        case NIVELES:{
            ImprimirPorNivel(raiz);
            break;
        }

    }
}
///////////////////////////////////////////////////////////////////
template <typename T>
void ABB<T>::ImprimirEntreorden(Nodo* subraiz) const{
    if(subraiz != NULL){
        ImprimirEntreorden(subraiz->hijoIzq);
        std::cout << subraiz->valor << ", ";
        ImprimirEntreorden(subraiz->hijoDer);
    }

}
///////////////////////////////////////////////////////////////////
template <typename T>
void ABB<T>::ImprimirEntreordenInverso(Nodo* subraiz) const{
    if(subraiz != NULL){
        ImprimirEntreordenInverso(subraiz->hijoDer);
        std::cout << subraiz->valor << ", ";
        ImprimirEntreordenInverso(subraiz->hijoIzq);
    }

}
///////////////////////////////////////////////////////////////////
template <typename T>
void ABB<T>::ImprimirPorNivel(Nodo* subraiz) const{
    if (raiz == NULL) return;
    LinkedDataQueue<Nodo*> cAux;
    cAux.Push(raiz);
    while(!cAux.Empty()){
        Nodo* nAux = cAux.GetFirst();
        std::cout << nAux->valor << ", ";
        if(nAux->hijoIzq != NULL) cAux.Push(nAux->hijoIzq);
        if(nAux->hijoDer != NULL) cAux.Push(nAux->hijoDer);
        cAux.Pop();
    }
    std::cout << "\b\b.";
}
///////////////////////////////////////////////////////////////////
template <typename T>
void ABB<T>::CopiarPreorden(Nodo* subraiz){
     if(subraiz != NULL){
        Agregar(subraiz->valor);
        CopiarPreorden(subraiz->hijoIzq);
        CopiarPreorden(subraiz->hijoDer);
     }
}
///////////////////////////////////////////////////////////////////
template <typename T>
unsigned ABB<T>::ObtenerNumNodos() const{
    return numNodos;
}

///////////////////////////////////////////////////////////////////
//template <typename T>
//unsigned ABB<T>::ObtenerAltura() const{
//    return altura;
//}
///////////////////////////////////////////////////////////////////
template <typename T>
bool ABB<T>::EstaVacia() const{
    return numNodos == 0;
}
///////////////////////////////////////////////////////////////////
template <typename T>
void ABB<T>::Vaciar(){
    Podar(raiz);
}
///////////////////////////////////////////////////////////////////
template <typename T>
bool ABB<T>::Podar(const T& val){
    if(!Buscar(val)) return false;
    Podar(BuscarDirNodo(raiz,val));
    return true;
}

///////////////////////////////////////////////////////////////////
template <typename T>
void ABB<T>::Podar(Nodo*& subraiz){
    if(subraiz != NULL){
        Podar(subraiz->hijoIzq);
        Podar(subraiz->hijoDer);
        delete subraiz;
        subraiz = NULL;
        --numNodos;
    }
}
///////////////////////////////////////////////////////////////////
template <typename T>
bool ABB<T>::Nodo::EsHoja() const{
    return (hijoIzq == NULL && hijoDer == NULL);
}
///////////////////////////////////////////////////////////////////
template <typename T>
bool ABB<T>::Nodo::TieneHijoIzq() const{
    return hijoIzq != NULL;
}
///////////////////////////////////////////////////////////////////
template <typename T>
bool ABB<T>::Nodo::TieneHijoDer() const{
    return hijoDer != NULL;
}
///////////////////////////////////////////////////////////////////
template <typename T>
bool ABB<T>::Eliminar(Nodo*& subraiz, const T &val){
    if(subraiz == NULL) return false;
    if(val == subraiz->valor){

        Nodo* porSalir = subraiz;
        if(subraiz->EsHoja()) subraiz = NULL;
        else if(subraiz->TieneHijoIzq() && !subraiz->TieneHijoDer()) subraiz = porSalir->hijoIzq;
        else if(!subraiz->TieneHijoIzq() && subraiz->TieneHijoDer()) subraiz = porSalir->hijoDer;
        else if(subraiz->TieneHijoIzq() && subraiz->TieneHijoDer()){
            Nodo*& dirMayor = BuscarDirMayor(subraiz->hijoIzq);
            subraiz->valor = dirMayor->valor;
            return Eliminar(dirMayor, dirMayor->valor);
        }
        delete porSalir;
        --numNodos;
        return true;


    }else return Eliminar(val < subraiz->valor ? subraiz->hijoIzq:subraiz->hijoDer, val);
}
///////////////////////////////////////////////////////////////////
template <typename T>
bool ABB<T>::Buscar(const T& val){
    Nodo*& nodoBuscar = BuscarDirNodo(raiz,val);
    return nodoBuscar != NULL;

}
///////////////////////////////////////////////////////////////////
template <typename T>
typename ABB<T>::Nodo*& ABB<T>::BuscarDirMayor(Nodo *&subraiz) const{
    if(subraiz->hijoDer==NULL)return subraiz;
    return BuscarDirMayor(subraiz->hijoDer);

}
///////////////////////////////////////////////////////////////////
template <typename T>
ABB<T>::Nodo::Nodo(T val, Nodo *Izq /*= NULL*/, Nodo *Der /*= NULL*/):valor(val),hijoIzq(Izq),hijoDer(Der){
}
///////////////////////////////////////////////////////////////////
//template <typename T>
//unsigned ABB<T>::EstablecerAltura(const Nodo* subraiz){
//
//}
///////////////////////////////////////////////////////////////////
template <typename T>
typename ABB<T>::Nodo*& ABB<T>::BuscarDirNodo(Nodo *&subraiz, const T& val) const{
    if(subraiz == NULL || subraiz->valor == val) return subraiz;
    else return BuscarDirNodo(val < subraiz->valor ? subraiz->hijoIzq:subraiz->hijoDer, val);

}
///////////////////////////////////////////////////////////////////

