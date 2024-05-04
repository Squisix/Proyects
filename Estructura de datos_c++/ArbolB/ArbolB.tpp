/*
    \Name: ArbolB.tpp
    \Author: Marco Antonio Guerrero Vasquez // 219202704
    \Date: 09/05/21
    \brief: Archivo de Plantilla donde se encuentran
            declaradas las funciones y operadores de la clase Arbol B.
*/
////////////////////////////////////////////////////////////////////////////
template<typename T, int grado>
ArbolB<T,grado>::ArbolB():maximo(grado-1),minimo(maximo/2),numClaves(0),raiz(NULL),hijoChico(NULL){
}
////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
ArbolB<T,grado>::ArbolB(const ArbolB<T, grado> &arbol):numClaves(0),raiz(NULL),hijoChico(NULL){
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
    if(this == &arbol) return *this;
    Vaciar();
    raiz = Copiar(arbol.raiz);
    Nodo *aux = raiz;
    if(aux != NULL){
        while(!aux->EsHoja()) aux = aux->ObtenerHijo(0);
        hijoChico = aux;
    }



    return *this;
}

////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
unsigned ArbolB<T,grado>::ObtenerNumClaves(){
    return ObtenerNumClaves(raiz);
}
////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
void ArbolB<T,grado>::Vaciar(){
    Vaciar(raiz);
    numClaves = 0;
}
////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
void ArbolB<T,grado>::Imprimir(const FormaImpresion &s){
    if(!EstaVacio()){
        switch(s){
            case POR_NIVEL:{
                EscribirPorNivel(raiz,1);

                break;
            }
            case ASCENDENTE:{
                std::cout << "{";
                inOrden(raiz);
                std::cout << "\b\b}" << std::endl;
                break;
            }
            case DESCENDENTE:{
                std::cout << "{";
                posOrden(raiz);
                std::cout << "\b\b}" << std::endl;
                break;
            }
        }
    }else std::cout << "Arbol Vacio..." << std::endl;
}
////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
bool ArbolB<T,grado>::EstaVacio(){
    return raiz == NULL;
}
////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
ArbolB<T,grado>::Nodo::Nodo():siguiente(NULL),NumClavesNodo(0){
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
typename ArbolB<T,grado>::Nodo*& ArbolB<T,grado>::Nodo::ObtenerHijo(int i){
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
bool ArbolB<T,grado>::BuscarEnNodo(Nodo* actual, const T& val, int & k)
{
    int index;
    bool encontrado;

    if (val < actual->ObtenerClave(1)){
        encontrado = false;
        index = 0;
    }else{ // orden descendente
        index = actual->ObtenerNumClavesNodo();
        while (val < actual->ObtenerClave(index) && (index > 1))
            index--;
        encontrado = val == actual->ObtenerClave(index);
    }

    k = index;
    return encontrado;
}

////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
typename ArbolB<T,grado>::Nodo* ArbolB<T,grado>::BuscarNodo(Nodo*actual, const T& val, int &n){
    if(actual == NULL){
        return NULL;
        n = -1;
    }else{
        bool seEncuentra = BuscarEnNodo(actual,val,n);
        if(seEncuentra) return actual;
        else return BuscarNodo(actual->ObtenerHijo(n),val,n);
    }
}
////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
void ArbolB<T,grado>::Insertar(const T& val){
    raiz = Insertar(raiz,val);
    numClaves = ObtenerNumClaves(raiz);
}
////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
typename ArbolB<T,grado>::Nodo* ArbolB<T,grado>::Insertar(Nodo *raiz, const T& val){
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
        n->CambiarClave(1,mediana);
        n->CambiarHijo(0,raiz); // claves menores
        n->CambiarHijo(1,nd); // claves mayores
        if(raiz == NULL) hijoChico = n;
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
                DividirNodo(actual, mediana, nuevo, k);
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
    actual->CambiarHijo(k + 1, ramaDr);
    // incrementa el contador de claves almacenadas
    actual->CambiarNumClavesNodo(actual->ObtenerNumClavesNodo()+1) ;
}
//////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
void ArbolB<T,grado>::DividirNodo(Nodo* actual, T& mediana,Nodo *&nuevo, int pos){
    int i, k;
    Nodo *nuevoNodo;
    k = pos;
    // posición de clave mediana
    int posMdna = (k <= minimo) ? minimo : minimo + 1;
    nuevoNodo = new Nodo();
    for (i = posMdna+1; i < grado; i++){
    /* desplazada la mitad derecha al nuevo nodo, la clave
    mediana se queda en el nodo actual */
        nuevoNodo->CambiarClave(i - posMdna, actual->ObtenerClave(i));
        nuevoNodo->CambiarHijo(i - posMdna, actual->ObtenerHijo(i));
    }
    nuevoNodo->CambiarNumClavesNodo(maximo - posMdna); // claves de nuevo nodo
    actual->CambiarNumClavesNodo(posMdna); // claves en nodo de origen
    // inserta la clave y el hijo en el nodo que le corresponde

    if (k <= minimo) MeterNodo(actual, mediana, nuevo, pos); // en Nodo de origen
    else{
        pos = k - posMdna;
        MeterNodo(nuevoNodo, mediana, nuevo, pos); // en Nodo Nuevo
    }
    // extrae clave mediana del Nodo de origen
    mediana = actual->ObtenerClave(actual->ObtenerNumClavesNodo());
    if(actual->EsHoja()){
        BuscarEnNodo(nuevoNodo, mediana, pos);
        MeterNodo(nuevoNodo, mediana, nuevo, pos);
        nuevoNodo->siguiente = actual->siguiente;
        actual->siguiente = nuevoNodo;
    }
    // Hijo 0 del nuevo nodo es el hijo de la mediana
    nuevoNodo->CambiarHijo(0, actual->ObtenerHijo(actual->ObtenerNumClavesNodo()));
    actual->CambiarNumClavesNodo(actual->ObtenerNumClavesNodo() -1); // se quita la mediana

    nuevo = nuevoNodo; // devuelve la el nuevo nodo
}
//////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
void ArbolB<T,grado>::EscribirPorNivel(Nodo* raiz, int h){

    int i;
    if (raiz != NULL){
        EscribirPorNivel(raiz->ObtenerHijo(raiz->ObtenerNumClavesNodo()),h + 5);
        for (i = raiz->ObtenerNumClavesNodo() - 1; i > raiz->ObtenerNumClavesNodo()/2; --i){
            // llamadas recursivas a la mitad de los subárboles
            EscribirPorNivel(raiz->ObtenerHijo(i),h + 5);
            std::cout << std::endl;
        }
        // visualización de las claves del nodo apuntado por la raiz
        for (i = raiz->ObtenerNumClavesNodo(); i>= 1;--i){
            for (int j = 0; j <= h; j++) std::cout << " ";
            std::cout << "|" << raiz->ObtenerClave(i) << "|" <<  std::endl;
        }
        // llamadas recursivas a la otra mitad de los subárboles
        for (i = raiz->ObtenerNumClavesNodo() / 2 ; i >= 0; --i)
            EscribirPorNivel(raiz->ObtenerHijo(i),h + 5);
        std::cout << std::endl;
    }
}
///////////////////////////////////////////////////
template <typename T, int grado>
bool ArbolB<T,grado>::BuscarClave(const T& val){
    if(hijoChico != NULL){
        Nodo* aux = hijoChico;


        if(aux->ObtenerClave(1) > val) return false;
        else{
            while(aux != NULL){
                for(int i = 1; i <= aux->ObtenerNumClavesNodo(); ++i)
                    if(aux->ObtenerClave(i) == val) return true;
                aux = aux->siguiente;

            }
        }
    }

    return false;
}
//////////////////////////////////////////////////
template <typename T, int grado>
void ArbolB<T,grado>::Vaciar(Nodo *&actual){

    if(actual != NULL){
        Vaciar(actual->ObtenerHijo(0));
        for(int i = 1; i <= actual->ObtenerNumClavesNodo(); ++i){
            Vaciar(actual->ObtenerHijo(i));
        }

        delete actual;
        actual = NULL;
    }
}
//////////////////////////////////////////////////
template <typename T, int grado>
void ArbolB<T,grado>::inOrden(Nodo *actual){
    if (actual != NULL){
        inOrden(actual->ObtenerHijo(0));
        for (int i = 1; i <= actual->ObtenerNumClavesNodo(); ++i){
            std::cout << actual->ObtenerClave(i) << ", ";
            inOrden(actual->ObtenerHijo(i));
        }
    }
}
//////////////////////////////////////////////////
template <typename T, int grado>
void ArbolB<T,grado>::posOrden(Nodo *actual){
    if (actual != NULL){
        posOrden(actual->ObtenerHijo(actual->ObtenerNumClavesNodo()));
        for (int i = actual->ObtenerNumClavesNodo()-1; i >= 0; --i){
            std::cout << actual->ObtenerClave(i+1) << ", ";
            posOrden(actual->ObtenerHijo(i));
        }
    }
}

/////////////////////////////////////////////////
template <typename T, int grado>
typename ArbolB<T,grado>::Nodo* ArbolB<T,grado>::Copiar(Nodo *raizAO){
    if (raizAO != NULL){
        Nodo *Nuevo = new Nodo();

        Nuevo->CambiarHijo(0,Copiar(raizAO->ObtenerHijo(0)));

        for(int i = 1; i <= raizAO->ObtenerNumClavesNodo(); ++i){
            Nuevo->CambiarClave(i,raizAO->ObtenerClave(i));
            Nuevo->CambiarNumClavesNodo(raizAO->ObtenerNumClavesNodo());
            Nuevo->CambiarHijo(i,Copiar(raizAO->ObtenerHijo(i)));
        }

        return Nuevo;
    }
    return NULL;
}
/////////////////////////////////////////////////////
template <typename T, int grado>
int ArbolB<T,grado>::ObtenerNumClaves(Nodo *actual){
    int nClaves = 0;
    if (actual != NULL){
        nClaves += ObtenerNumClaves(actual->ObtenerHijo(0));
        for(int i = 1; i <= actual->ObtenerNumClavesNodo(); ++i){
            nClaves += ObtenerNumClaves(actual->ObtenerHijo(i));
        }
        nClaves += actual->ObtenerNumClavesNodo();
    }
    return nClaves;
}
///////////////////////////////////////////////////////
template <typename T, int grado>
void ArbolB<T,grado>::EliminarClave(const T& val){
    T mediana;
    Eliminar(raiz, val, mediana,0);

}

////////////////////////////////////////////////

template <typename T,int grado>
bool ArbolB<T,grado>::Eliminar(Nodo*& actual, const T& val, T &mediana, int indicePadre){
    int k;
    bool sube = false;

    if (actual != NULL){
        bool esta;
        esta = BuscarEnNodo(actual, val, k);
        if (!esta){
            sube = Eliminar(actual->ObtenerHijo(k), val, mediana, k);
            if(!sube) return false;

            if(actual->ObtenerHijo(k) == NULL) QuitarNodo(actual,k);

            if(actual != raiz){
                if(actual->ObtenerNumClavesNodo() >= minimo){
                    for(int i = 1; i <= actual->ObtenerNumClavesNodo(); ++i)
                        actual->CambiarClave(i,actual->ObtenerHijo(i)->ObtenerClave(1));
                }
            }



        }else{
            if(actual == raiz && actual->ObtenerNumClavesNodo() == 1 && actual->EsHoja()){
                delete actual;
                actual = NULL;
                hijoChico = actual;
            }else if(actual->EsHoja()){
                QuitarNodo(actual,k);

                if(actual->ObtenerNumClavesNodo() >= minimo){ // Bien
                    mediana = actual->ObtenerClave(1);
                    sube = true;

                }else{

                    Nodo* aux = hijoChico;
                    if(aux != actual)
                        while(aux->siguiente != actual)
                            aux = aux->siguiente;

                     //Prestar de la izquierda Bien
                    if(aux->ObtenerNumClavesNodo() > minimo && indicePadre > 0){

                        MeterNodo(actual, aux->ObtenerClave(aux->ObtenerNumClavesNodo()), actual->ObtenerHijo(1), 0);
                        aux->CambiarNumClavesNodo(aux->ObtenerNumClavesNodo()-1);
                        mediana = actual->ObtenerClave(1);


                    //prestar de la derecha Bien
                    }else if(actual->siguiente != NULL && actual->siguiente->ObtenerNumClavesNodo() > minimo){
                            MeterNodo(actual, actual->siguiente->ObtenerClave(1),
                                      actual->ObtenerHijo(actual->ObtenerNumClavesNodo()), actual->ObtenerNumClavesNodo());
                            QuitarNodo(actual->siguiente, 1);


                            mediana = actual->ObtenerClave(1);
                    }else{
                                //Mezclar
                        if(indicePadre > 0){
                                //Mezclar a la izquierda
                            for(int i = 1; i <= actual->ObtenerNumClavesNodo(); ++i){
                                aux->CambiarClave(aux->ObtenerNumClavesNodo()+i,actual->ObtenerClave(i));
                                aux->CambiarNumClavesNodo(aux->ObtenerNumClavesNodo()+1);
                            }
                            mediana = aux->ObtenerClave(1);
                        }else{
                             //Mezclar a la derecha
                            for(int i = actual->siguiente->ObtenerNumClavesNodo(); i >= 1; --i){
                                actual->siguiente->CambiarClave(i+actual->ObtenerNumClavesNodo(),actual->siguiente->ObtenerClave(i));
                            }
                            if(actual->ObtenerNumClavesNodo() > 0){
                                for(int i = 1; i <= actual->ObtenerNumClavesNodo(); ++i){
                                    actual->siguiente->CambiarClave(i,actual->ObtenerClave(i));
                                    actual->siguiente->CambiarNumClavesNodo(actual->siguiente->ObtenerNumClavesNodo()+1);
                                }
                            }
                            mediana = actual->siguiente->ObtenerClave(1);
                        }

                        if(hijoChico == actual) hijoChico = actual->siguiente;
                        else aux->siguiente = actual->siguiente;

                        delete actual;
                        actual = NULL;


                    }
                }
                return true;
            }else{
                sube = Eliminar(actual->ObtenerHijo(k), val, mediana, k);
                if(!sube) return false;
                if(actual->ObtenerHijo(k) == NULL) QuitarNodo(actual,k);


                    if(actual == raiz && actual->ObtenerHijo(0) != NULL && !actual->ObtenerHijo(0)->EsHoja()){
                        actual->CambiarClave(k,mediana);

                    }else{
                        for(int i = 1; i <= actual->ObtenerNumClavesNodo(); ++i)
                            actual->CambiarClave(i,actual->ObtenerHijo(i)->ObtenerClave(1));
                    }


            }


        }


            if(actual != NULL && actual->ObtenerHijo(k) != NULL && actual->ObtenerHijo(k)->ObtenerNumClavesNodo() < minimo){

                    Nodo *hijoIzq, *hijoDer, *hijoAux;
                    if(k > 0) hijoIzq = actual->ObtenerHijo(k-1);
                    if(k < actual->ObtenerNumClavesNodo()) hijoDer = actual->ObtenerHijo(k+1);

                    //Pedir prestado de la izquierda
                    if(k > 0 && hijoIzq->ObtenerNumClavesNodo() > minimo){
                        MeterNodo(actual->ObtenerHijo(k), actual->ObtenerClave(k),actual->ObtenerHijo(k)->ObtenerHijo(0) , 0);
                        actual->CambiarClave(k,hijoIzq->ObtenerClave(hijoIzq->ObtenerNumClavesNodo()));
                        hijoAux = hijoIzq->ObtenerHijo(hijoIzq->ObtenerNumClavesNodo());
                        hijoIzq->CambiarNumClavesNodo(hijoIzq->ObtenerNumClavesNodo()-1);
                        actual->ObtenerHijo(k)->CambiarHijo(0, hijoAux);

                    }else if(k < actual->ObtenerNumClavesNodo() && hijoDer->ObtenerNumClavesNodo() > minimo){
                            //Pedir prestado de la derecha
                        MeterNodo(actual->ObtenerHijo(k), actual->ObtenerClave(k+1),hijoDer->ObtenerHijo(0) ,actual->ObtenerHijo(k)->ObtenerNumClavesNodo() );
                        actual->CambiarClave(k+1,hijoDer->ObtenerClave(1));
                        hijoDer->CambiarHijo(0,hijoDer->ObtenerHijo(1));
                        QuitarNodo(hijoDer,1);
                    }else if(k > 0){
                            //Mezclar Izquierda
                            if(actual->ObtenerHijo(k)->ObtenerNumClavesNodo() > 0){
                                for(int i = 1; i <= actual->ObtenerHijo(k)->ObtenerNumClavesNodo(); ++i){
                                    hijoIzq->CambiarClave(hijoIzq->ObtenerNumClavesNodo()+i,actual->ObtenerHijo(k)->ObtenerClave(i));
                                    hijoIzq->CambiarHijo(hijoIzq->ObtenerNumClavesNodo()+i,actual->ObtenerHijo(k)->ObtenerHijo(i));
                                    hijoIzq->CambiarNumClavesNodo(hijoIzq->ObtenerNumClavesNodo()+1);
                                }
                            }
                            hijoAux = actual->ObtenerHijo(k)->ObtenerHijo(0);
                            delete actual->ObtenerHijo(k);

                            int i;
                            BuscarEnNodo(hijoIzq,actual->ObtenerClave(k),i);
                            MeterNodo(hijoIzq,actual->ObtenerClave(k),hijoAux,i);
                            QuitarNodo(actual,k);
                            if(actual == raiz && actual->ObtenerNumClavesNodo() == 0){
                                hijoAux = actual;
                                actual = hijoIzq;
                                delete hijoAux;


                            }

                    }else{
                        //Mezclar Derecha


                        hijoAux = hijoDer->ObtenerHijo(0);
                        MeterNodo(hijoDer,actual->ObtenerClave(k+1),hijoAux,0);
                        if(actual->ObtenerHijo(k)->ObtenerNumClavesNodo() > 0){
                            for(int i = actual->ObtenerHijo(k)->ObtenerNumClavesNodo(); i >= 1; --i){
                                MeterNodo(hijoDer,actual->ObtenerHijo(k)->ObtenerClave(i),actual->ObtenerHijo(k)->ObtenerHijo(i),0);
                            }
                        }
                        hijoDer->CambiarHijo(0, actual->ObtenerHijo(k)->ObtenerHijo(0));

                        delete actual->ObtenerHijo(k);

                        hijoAux = actual->ObtenerHijo(k+1);
                        QuitarNodo(actual,k+1);

                        if(actual == raiz && actual->ObtenerNumClavesNodo() == 0){
                            hijoAux = actual;
                            actual = hijoDer;
                            delete hijoAux;
                        }else actual->CambiarHijo(0, hijoAux);

                   }

            }else if(actual != NULL && actual == raiz && actual->ObtenerNumClavesNodo() == 0){
                Nodo *aux = actual;
                actual = actual->ObtenerHijo(0);
                hijoChico = actual;
                delete aux;

            }


    }
    return sube;
}
///////////////////////////////////////////////////////
template <typename T,int grado>
void ArbolB<T,grado>::QuitarNodo(Nodo* actual, int k){
    // desplaza a la izquierda los elementos para hacer un hueco
    for (int i = k; i <= actual->ObtenerNumClavesNodo()-1; ++i){
        actual->CambiarClave(i, actual->ObtenerClave(i+1));
        actual->CambiarHijo(i, actual->ObtenerHijo(i+1));
    }
    // incrementa el contador de claves almacenadas
    actual->CambiarNumClavesNodo(actual->ObtenerNumClavesNodo()-1) ;
}
