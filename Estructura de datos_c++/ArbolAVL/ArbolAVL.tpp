/*
    \Name: ArbolAVL.tpp
    \Author: Marco Antonio Guerrero Vasquez // 219202704
    \Date: 22/04/21
    \brief: Archivo de Plantilla donde se encuentran
            declaradas las funciones y operadores de la clase ArbolAVL.
*/
///////////////////////////////////////////////////////////////////
template <typename T>
ArbolAVL<T>::ArbolAVL():numNodos(0),raiz(NULL){
}
 ///////////////////////////////////////////////////////////////////
template <typename T>
ArbolAVL<T>::ArbolAVL(const ArbolAVL<T> &a):numNodos(0),raiz(NULL){
    *this = a;
}
///////////////////////////////////////////////////////////////////
template<typename T>
ArbolAVL<T>::~ArbolAVL(){
    Vaciar();
}
///////////////////////////////////////////////////////////////////
template <typename T>
ArbolAVL<T>& ArbolAVL<T>::operator=(const ArbolAVL<T> &a){
    if(this == &a) return *this;
    Vaciar();
    CopiarPreorden(a.raiz);
    return *this;
}
///////////////////////////////////////////////////////////////////
template <typename T>
bool ArbolAVL<T>::Agregar(const T &val){
    return Agregar(raiz,val);
}
///////////////////////////////////////////////////////////////////
template <typename T>
bool ArbolAVL<T>::Agregar(Nodo*& subraiz, const T &val){
    bool aux;
    if(subraiz == NULL){
        subraiz = new Nodo(val);
        ++numNodos;
        return true;

    }else if (val == subraiz->valor) return false;
    else {
        aux = Agregar(val < subraiz->valor ? subraiz->hijoIzq:subraiz->hijoDer, val);
        ActualizarAltura(subraiz);
        Balancear(subraiz);
        return aux;
    }
}
///////////////////////////////////////////////////////////////////
template <typename T>
bool ArbolAVL<T>::Eliminar(const T &val){
    return Eliminar(raiz,val);
}
///////////////////////////////////////////////////////////////////
template <typename T>
void ArbolAVL<T>::Imprimir(const MetodoImpresion &s) const{

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
void ArbolAVL<T>::ImprimirEntreorden(Nodo* subraiz) const{
    if(subraiz != NULL){
        ImprimirEntreorden(subraiz->hijoIzq);
        std::cout << subraiz->valor << ", ";
        ImprimirEntreorden(subraiz->hijoDer);
    }

}
///////////////////////////////////////////////////////////////////
template <typename T>
void ArbolAVL<T>::ImprimirEntreordenInverso(Nodo* subraiz) const{
    if(subraiz != NULL){
        ImprimirEntreordenInverso(subraiz->hijoDer);
        std::cout << subraiz->valor << ", ";
        ImprimirEntreordenInverso(subraiz->hijoIzq);
    }

}
///////////////////////////////////////////////////////////////////
template <typename T>
void ArbolAVL<T>::ImprimirPorNivel(Nodo* subraiz) const{
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
void ArbolAVL<T>::CopiarPreorden(Nodo* subraiz){
     if(subraiz != NULL){
        Agregar(subraiz->valor);
        CopiarPreorden(subraiz->hijoIzq);
        CopiarPreorden(subraiz->hijoDer);
     }
}
///////////////////////////////////////////////////////////////////
template <typename T>
unsigned ArbolAVL<T>::ObtenerNumNodos() const{
    return numNodos;
}

///////////////////////////////////////////////////////////////////
template <typename T>
unsigned ArbolAVL<T>::ObtenerAltura() const{
    return raiz->altura;
}
///////////////////////////////////////////////////////////////////
template <typename T>
bool ArbolAVL<T>::EstaVacia() const{
    return numNodos == 0;
}
///////////////////////////////////////////////////////////////////
template <typename T>
void ArbolAVL<T>::Vaciar(){
    Podar(raiz);
}
///////////////////////////////////////////////////////////////////
template <typename T>
bool ArbolAVL<T>::Podar(const T& val){
    if(!Buscar(val)) return false;
    Podar(BuscarDirNodo(raiz,val));
    return true;
}

///////////////////////////////////////////////////////////////////
template <typename T>
void ArbolAVL<T>::Podar(Nodo*& subraiz){
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
bool ArbolAVL<T>::Nodo::EsHoja() const{
    return (hijoIzq == NULL && hijoDer == NULL);
}
///////////////////////////////////////////////////////////////////
template <typename T>
bool ArbolAVL<T>::Nodo::TieneHijoIzq() const{
    return hijoIzq != NULL;
}
///////////////////////////////////////////////////////////////////
template <typename T>
bool ArbolAVL<T>::Nodo::TieneHijoDer() const{
    return hijoDer != NULL;
}
///////////////////////////////////////////////////////////////////
template <typename T>
bool ArbolAVL<T>::Eliminar(Nodo*& subraiz, const T &val){
    bool aux;
    if(subraiz == NULL) return false;
    if(val == subraiz->valor){

        Nodo* porSalir = subraiz;
        if(subraiz->EsHoja()) subraiz = NULL;
        else if(subraiz->TieneHijoIzq() && !subraiz->TieneHijoDer()) subraiz = porSalir->hijoIzq;
        else if(!subraiz->TieneHijoIzq() && subraiz->TieneHijoDer()) subraiz = porSalir->hijoDer;
        else if(subraiz->TieneHijoIzq() && subraiz->TieneHijoDer()){
            Nodo*& dirMayor = BuscarDirMayor(subraiz->hijoIzq);
            subraiz->valor = dirMayor->valor;
            return Eliminar(subraiz->hijoIzq, dirMayor->valor);
        }
        delete porSalir;
        --numNodos;
        return true;


    }else{
        aux = Eliminar(val < subraiz->valor ? subraiz->hijoIzq:subraiz->hijoDer, val);
        ActualizarAltura(subraiz);
        Balancear(subraiz);
        return aux;
    }
}

///////////////////////////////////////////////////////////////////
template <typename T>
bool ArbolAVL<T>::Buscar(const T& val){
    Nodo*& nodoBuscar = BuscarDirNodo(raiz,val);
    return nodoBuscar != NULL;

}
///////////////////////////////////////////////////////////////////
template <typename T>
typename ArbolAVL<T>::Nodo*& ArbolAVL<T>::BuscarDirMayor(Nodo *&subraiz) const{
    if(subraiz->hijoDer==NULL)return subraiz;
    return BuscarDirMayor(subraiz->hijoDer);

}
///////////////////////////////////////////////////////////////////
template <typename T>
ArbolAVL<T>::Nodo::Nodo(T val, Nodo *Izq /*= NULL*/, Nodo *Der /*= NULL*/):altura(1),factorEquilibrio(0),valor(val),hijoIzq(Izq),hijoDer(Der){
}
///////////////////////////////////////////////////////////////////
//template <typename T>
//unsigned ABB<T>::EstablecerAltura(const Nodo* subraiz){
//
//}
///////////////////////////////////////////////////////////////////
template <typename T>
typename ArbolAVL<T>::Nodo*& ArbolAVL<T>::BuscarDirNodo(Nodo *&subraiz, const T& val) const{
    if(subraiz == NULL || subraiz->valor == val) return subraiz;
    else return BuscarDirNodo(val < subraiz->valor ? subraiz->hijoIzq:subraiz->hijoDer, val);

}
///////////////////////////////////////////////////////////////////
template <typename T>
void ArbolAVL<T>::ActualizarAltura(Nodo *& subraiz){
    unsigned aIzq, aDer;
    if(subraiz == NULL) return;
    aIzq = subraiz->TieneHijoIzq() ? subraiz->hijoIzq->altura:0;
    aDer = subraiz->TieneHijoDer() ? subraiz->hijoDer->altura:0;

    if(aIzq >= aDer){
        subraiz->altura = aIzq + 1;
    }else subraiz->altura = aDer + 1;
    subraiz->factorEquilibrio = aDer-aIzq;

}
///////////////////////////////////////////////////////////////////
template <typename T>
void ArbolAVL<T>::Balancear(Nodo*& subraiz){
    if(subraiz == NULL) return;
    if(subraiz->factorEquilibrio == 2){
        if((subraiz->hijoDer->factorEquilibrio == 0) || (subraiz->hijoDer->factorEquilibrio == 1)){
            RSI(subraiz);
        }else if(subraiz->hijoDer->factorEquilibrio == -1){
            RSD(subraiz->hijoDer);
            RSI(subraiz);
        }
    }else if(subraiz->factorEquilibrio == -2){
        if((subraiz->hijoIzq->factorEquilibrio == 0) || (subraiz->hijoIzq->factorEquilibrio == -1)){
            RSD(subraiz);
        }else if(subraiz->hijoIzq->factorEquilibrio == 1){
            RSI(subraiz->hijoIzq);
            RSD(subraiz);
        }
    }
}
///////////////////////////////////////////////////////////////////
template <typename T>
void ArbolAVL<T>::RSI(Nodo*& subraiz){
    Nodo* aux = subraiz->hijoDer;
    subraiz->hijoDer = aux->hijoIzq;
    aux->hijoIzq = subraiz;
    subraiz = aux;
}
///////////////////////////////////////////////////////////////////
template <typename T>
void ArbolAVL<T>::RSD(Nodo*& subraiz){
    Nodo* aux = subraiz->hijoIzq;
    subraiz->hijoIzq = aux->hijoDer;
    aux->hijoDer = subraiz;
    subraiz = aux;
}
///////////////////////////////////////////////////////////////////

