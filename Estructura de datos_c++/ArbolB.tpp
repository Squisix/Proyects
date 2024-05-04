////////////////////////////////////////////////////////////////////////////
template<typename T, int grado>
ArbolB<T,grado>::ArbolB():maximo(grado-1),minimo(maximo/2),numClaves(0),raiz(NULL){
}
////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
ArbolB<T,grado>::ArbolB(const ArbolB<T, grado> &arbol):numClaves(0),raiz(NULL){
    *this = arbol;
}
////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
ArbolB<T,grado>::~ArbolB(){
    Vaciar();
}
////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
ArbolB<T,grado>& ArbolB<T,grado>::operator=(const ArbolB<T,grado> &arbol){
}
////////////////////////////////////////////////////////////////////////////
//template<typename T,int grado>
//bool ArbolB<T,grado>::AgregarClave(const T& val){
//    Agregar(raiz,val);
//}
////////////////////////////////////////////////////////////////////////////
//template<typename T,int grado>
//bool ArbolB<T,grado>::EliminarClave(const T& val){
//}
////////////////////////////////////////////////////////////////////////////
//template<typename T,int grado>
//bool ArbolB<T,grado>::BuscarClave(const T& val){
//}
////////////////////////////////////////////////////////////////////////////
//template<typename T,int grado>
//unsigned ArbolB<T,grado>::ObtenerNumClaves() const{
//}
////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
void ArbolB<T,grado>::Vaciar(){
}
////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
void ArbolB<T,grado>::Imprimir(const FormaImpresion &s){
    switch(s){
        case POR_NIVEL:{
            EscribirPorNivel(raiz,1);
            break;
        }
    }
}
////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
bool ArbolB<T,grado>::EstaVacio(){
    return raiz == NULL;
}
////////////////////////////////////////////////////////////////////////////
//template<typename T,int grado>
//bool ArbolB<T,grado>::Nodo::Agregar(Nodo*&subraiz, const T& val){
//
//}
////////////////////////////////////////////////////////////////////////////
//template<typename T,int grado>
//bool ArbolB<T,grado>::Nodo::Eliminar(Nodo*&subraiz, const T& val){
//}
////////////////////////////////////////////////////////////////////////////
//template<typename T,int grado>
//void ArbolB<T,grado>::Nodo::Ordenar(Nodo *&subraiz, int izq, int der){
//}
////////////////////////////////////////////////////////////////////////////
//template<typename T,int grado>
//void ArbolB<T,grado>::Nodo::Partir(Nodo *&subraiz){
//}
////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
ArbolB<T,grado>::Nodo::Nodo():NumClavesNodo(0){
    for(int i = 0; i < grado; ++i) hijo[i] = NULL;
}
/////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
bool ArbolB<T,grado>::Nodo::NodoLleno(){
    return NumClavesNodo == (grado - 1);
}
/////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
bool ArbolB<T,grado>::Nodo::NodoSemiLleno(){
    return NumClavesNodo < minimo;
}
/////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
const T& ArbolB<T,grado>::Nodo::ObtenerClave(int i) const{
    return clave[i];
}
/////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
void ArbolB<T,grado>::Nodo::CambiarClave(int i, const T& val){
    clave[i] = val;
}
/////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
typename ArbolB<T,grado>::Nodo* ArbolB<T,grado>::Nodo::ObtenerHijo(int i){
    return hijo[i];
}
/////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
void ArbolB<T,grado>::Nodo::CambiarHijo(int i, Nodo* n){
    hijo[i] = n;
}
/////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
int ArbolB<T,grado>::Nodo::ObtenerNumClavesNodo() const{
    return NumClavesNodo;
}
/////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
void ArbolB<T,grado>::Nodo::CambiarNumClavesNodo(int _NumClavesNodo){
    NumClavesNodo = _NumClavesNodo;
}
/////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
bool ArbolB<T, grado>::Nodo::EsHoja() const{
    for(int i = 0; i < grado; ++i)
        if(hijo[i] != NULL) return false;
    return true;
}
////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
bool ArbolB<T,grado>::BuscarEnNodo(Nodo*& actual, const T& val, int & k)
{
    int index;
    bool encontrado;
    if (val < actual->ObtenerClave(0)){
        encontrado = false;
        index = 0;
    }else{ // orden descendente
        index = actual->ObtenerNumClavesNodo()-1;
        while (val < actual->ObtenerClave(index) && (index > 0))
            index--;
        encontrado = val == actual->ObtenerClave(index);
    }
    k = index;
    return encontrado;
}
////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
typename ArbolB<T,grado>::Nodo*& ArbolB<T,grado>::BuscarNodo(const T& val, int &n){
    return BuscarNodo(raiz,val,n);
}
////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
typename ArbolB<T,grado>::Nodo*& ArbolB<T,grado>::BuscarNodo(Nodo *& actual, const T& val, int &n){
    if(actual == NULL){
        return NULL;
    }else{
        bool seEncuentra = BuscarEnNodo(actual,val,n);
        if(seEncuentra) return actual;
        else return buscar(actual->ObtenerHijo(n),val,n);
    }
}
////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
void ArbolB<T,grado>::Insertar(const T& val){
    raiz = InsertarRaiz(raiz,val);
}
////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
typename ArbolB<T,grado>::Nodo* ArbolB<T,grado>::InsertarRaiz(Nodo *raiz, const T& val){
    bool subeArriba;
    T mediana;
    Nodo* nd;
    subeArriba = Empujar(raiz, val, mediana, nd);
    if(subeArriba){
        // El árbol crece en altura por la raíz.
        // sube una nueva clave mediana y un nuevo hijo derecho nd
        // en la implementación se mantiene que las claves que son
        // menores que mediana se encuentran en raiz y las mayores en nd
        Nodo* n;
        n = new Nodo(); // nuevo nodo
        n->CambiarNumClavesNodo(1); // tiene una sola clave
        n->CambiarClave(0,mediana);
        n->CambiarHijo(0,raiz); // claves menores
        n->CambiarHijo(1,nd); // claves mayores
        raiz = n;
    }
    return raiz;
}
/////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
bool ArbolB<T,grado>::Empujar(Nodo* actual,const T& val, T &mediana, Nodo *& nuevo){
    int k;
    bool subeArriba = false;
    if (actual == NULL){
        // envía hacia arriba la clave cl y su rama derecha NULL
        // para que se inserte en la Página padre
        subeArriba = true;
        mediana = val;
        nuevo = NULL;
        // el dato Página de nuevo está a NULL
    }else{
        bool esta;
        esta = BuscarEnNodo(actual, val, k);
        if (esta) return false;
        // siempre se ejecuta
        subeArriba = Empujar(actual->ObtenerHijo(k), val, mediana, nuevo);
        // devuelve control; vuelve por el camino de búsqueda
        if(subeArriba){

            if (actual->NodoLleno()){ // hay que dividir la página
                MeterNodo(actual, mediana, nuevo, k);
                DividirNodo(actual,mediana, nuevo);
            }else{
            //cabe en la página, se inserta la mediana y su rama derecha
                subeArriba = false;
                MeterNodo(actual, mediana, nuevo, k);
            }
        }
    }
    return subeArriba;

}
/////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
void ArbolB<T,grado>::MeterNodo(Nodo* actual, const T& val,Nodo *ramaDr, int k){
     // desplaza a la derecha los elementos para hacer un hueco
    for (int i = actual->ObtenerNumClavesNodo(); i >= k + 1; i--){
        actual->CambiarClave(i + 1, actual->ObtenerClave(i));
        actual->CambiarHijo(i + 1, actual->ObtenerHijo(i));
    }
    // pone la clave y la rama derecha en la posición k+1
    actual->CambiarClave(k + 1, val);

    // incrementa el contador de claves almacenadas
    if(actual->ObtenerNumClavesNodo() != maximo)
        actual->CambiarNumClavesNodo(actual->ObtenerNumClavesNodo()+1) ;
        actual->CambiarHijo(k + 1, ramaDr);
}
//////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
void ArbolB<T,grado>::DividirNodo(Nodo* actual, T& mediana,Nodo *&nuevo){
    int i;
    Nodo *nuevoNodo;

    // posición de clave mediana
    nuevoNodo = new Nodo();
    for (i = minimo+1; i < grado; ++i){
    /* desplazada la mitad derecha a la nueva Página, la clave
    mediana se queda en Página actual */
        nuevoNodo->CambiarClave(i - (minimo+1), actual->ObtenerClave(i));
        nuevoNodo->CambiarNumClavesNodo(nuevoNodo->ObtenerNumClavesNodo() + 1); // claves de nueva Página
        nuevoNodo->CambiarHijo(i - (minimo+1), actual->ObtenerHijo(i));
    }
    // extrae clave mediana de la Página origen
    mediana = actual->ObtenerClave(minimo);
    actual->CambiarNumClavesNodo(minimo); // claves en Página origen
    // Rama0 del nuevo nodo es la rama de la mediana
    nuevoNodo->CambiarHijo(0, actual->ObtenerHijo(actual->ObtenerNumClavesNodo()));
    nuevo = nuevoNodo; // devuelve la nueva Página
}
//////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
void ArbolB<T,grado>::EscribirPorNivel(Nodo* raiz, int h){

    int i;
    if (raiz != NULL){
        EscribirPorNivel(raiz->ObtenerHijo(0),h + 5);
        for (i = 1; i <= raiz->ObtenerNumClavesNodo()/2;i++){
            // llamadas recursivas a la mitad de los subárboles
            EscribirPorNivel(raiz->ObtenerHijo(i),h + 5);
            std::cout << std::endl;
        }
        // visualización de las claves de la página apuntada por r
        for (i = 0; i < raiz->ObtenerNumClavesNodo();i++){
            for (int j = 0; j <= h; j++) std::cout << " ";
            std::cout << raiz->ObtenerClave(i) << std::endl;
        }
        // llamadas recursivas a la otra mitad de los subárboles
        for (i = raiz->ObtenerNumClavesNodo() / 2 + 1 ; i <= raiz->ObtenerNumClavesNodo(); i++)
            EscribirPorNivel(raiz->ObtenerHijo(i),h + 5);
        std::cout << std::endl;
    }
}
