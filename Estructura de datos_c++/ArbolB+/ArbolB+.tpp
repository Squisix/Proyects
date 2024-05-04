/*
    \Nombre: ArbolB+.tpp
    \Authores:
                Marco Antonio Guerrero Vasquez // 219202704
                Jesús Israel Urías Páramo      // 219217598
                José Isaías Olmos Morales      // 219212278
                Luis Gerardo Ortiz Quintana    // 219220371

    \Fecha: 18/05/21
    \brief: Archivo de Plantilla donde se encuentran
            declaradas las funciones y operadores de la clase ArbolBMas.
*/
////////////////////////////////////////////////////////////////////////////
template<typename T, int grado>
ArbolBMas<T,grado>::ArbolBMas():maximo(grado-1),minimo(maximo/2),numClaves(0),raiz(NULL),hijoChico(NULL){
}
////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
ArbolBMas<T,grado>::ArbolBMas(const ArbolBMas<T, grado> &arbol):numClaves(0),raiz(NULL),hijoChico(NULL){
    *this = arbol;
}
////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
ArbolBMas<T,grado>::~ArbolBMas(){
    Vaciar();
}
////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
ArbolBMas<T,grado>& ArbolBMas<T,grado>::operator=(const ArbolBMas<T,grado> &arbol){
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
unsigned ArbolBMas<T,grado>::ObtenerNumClaves(){
    return ObtenerNumClaves(raiz);
}
////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
void ArbolBMas<T,grado>::Vaciar(){
    Vaciar(raiz);
    numClaves = 0;
}
////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
void ArbolBMas<T,grado>::Imprimir(const FormaImpresion &s){
    if(!EstaVacio()){
        switch(s){
            case POR_NIVEL:{
                EscribirPorNivel(raiz,1);

                break;
            }
            case ASCENDENTE:{
                std::cout << "{";
                Ascendente();
                std::cout << "\b\b}" << std::endl;
                break;
            }
            case DESCENDENTE:{
                std::cout << "{";
                Descendente();
                std::cout << "\b\b}" << std::endl;
                break;
            }
        }
    }else std::cout << "Arbol Vacio..." << std::endl;
}
////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
bool ArbolBMas<T,grado>::EstaVacio(){
    return raiz == NULL;
}
////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
ArbolBMas<T,grado>::Nodo::Nodo():siguiente(NULL),NumClavesNodo(0){
    for(int i = 0; i < grado; ++i) hijo[i] = NULL;
}
/////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
bool ArbolBMas<T,grado>::Nodo::NodoLleno(){
    return NumClavesNodo == (grado - 1);
}


/////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
const T& ArbolBMas<T,grado>::Nodo::ObtenerClave(int i) const{
    return clave[i];
}
/////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
void ArbolBMas<T,grado>::Nodo::CambiarClave(int i, const T& val){
    clave[i] = val;
}
/////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
typename ArbolBMas<T,grado>::Nodo*& ArbolBMas<T,grado>::Nodo::ObtenerHijo(int i){
    return hijo[i];
}
/////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
void ArbolBMas<T,grado>::Nodo::CambiarHijo(int i, Nodo* n){
    hijo[i] = n;
}
/////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
int ArbolBMas<T,grado>::Nodo::ObtenerNumClavesNodo() const{
    return NumClavesNodo;
}
/////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
void ArbolBMas<T,grado>::Nodo::CambiarNumClavesNodo(int _NumClavesNodo){
    NumClavesNodo = _NumClavesNodo;
}
/////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
bool ArbolBMas<T, grado>::Nodo::EsHoja() const{
    for(int i = 0; i < grado; ++i)
        if(hijo[i] != NULL) return false;
    return true;
}
////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
bool ArbolBMas<T,grado>::BuscarEnNodo(Nodo* actual, const T& val, int & k)
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
typename ArbolBMas<T,grado>::Nodo* ArbolBMas<T,grado>::BuscarNodo(Nodo*actual, const T& val, int &n){
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
void ArbolBMas<T,grado>::Insertar(const T& val){
    raiz = Insertar(raiz,val);
    numClaves = ObtenerNumClaves(raiz);
}
////////////////////////////////////////////////////////////////////////////
template<typename T,int grado>
typename ArbolBMas<T,grado>::Nodo* ArbolBMas<T,grado>::Insertar(Nodo *raiz, const T& val){
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
bool ArbolBMas<T,grado>::Empujar(Nodo* actual,const T& val, T &mediana, Nodo *& nuevo){
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
void ArbolBMas<T,grado>::MeterNodo(Nodo* actual, const T& val,Nodo *ramaDr, int k){
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
void ArbolBMas<T,grado>::DividirNodo(Nodo* actual, T& mediana,Nodo *&nuevo, int pos){
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
void ArbolBMas<T,grado>::EscribirPorNivel(Nodo* raiz, int h){

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
bool ArbolBMas<T,grado>::BuscarClave(const T& val){
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
void ArbolBMas<T,grado>::Vaciar(Nodo *&actual){

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
void ArbolBMas<T,grado>::Ascendente(){
    if (hijoChico != NULL){
        Nodo *aux = hijoChico;
        while(aux != NULL){
            for (int i = 1; i <= aux->ObtenerNumClavesNodo(); ++i)
                std::cout << aux->ObtenerClave(i) << ", ";
            aux = aux->siguiente;
        }
    }
}
//////////////////////////////////////////////////
template <typename T, int grado>
void ArbolBMas<T,grado>::Descendente(){
    if (hijoChico != NULL){
        Nodo *aux = hijoChico, *recorrido;

        while(aux->siguiente != NULL)
            aux = aux->siguiente;

        while(aux != hijoChico){
            recorrido = hijoChico;
            for (int i = aux->ObtenerNumClavesNodo(); i >= 1; --i)
                std::cout << aux->ObtenerClave(i) << ", ";

            while(recorrido->siguiente != aux)
                recorrido = recorrido->siguiente;
            aux = recorrido;


        }
        for (int i = aux->ObtenerNumClavesNodo(); i >= 1; --i)
                std::cout << aux->ObtenerClave(i) << ", ";



    }
}

/////////////////////////////////////////////////
template <typename T, int grado>
typename ArbolBMas<T,grado>::Nodo* ArbolBMas<T,grado>::Copiar(Nodo *raizAO){
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
int ArbolBMas<T,grado>::ObtenerNumClaves(Nodo *actual){
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
void ArbolBMas<T,grado>::EliminarClave(const T& val){
    T mediana;
    Eliminar(raiz, val, mediana,0,0);

}

////////////////////////////////////////////////

template <typename T,int grado>
bool ArbolBMas<T,grado>::Eliminar(Nodo*& actual, const T& val, T &valSube, int indicePadre, int numClavesPadre){
    int k;
    bool sube = false;

    if (actual != NULL){
        bool esta;

        //Busca el valor en el nodo
        esta = BuscarEnNodo(actual, val, k);
        if (!esta){

                //Si no encuentra el valor se vuelve a llamar el proceso de eliminado con la dirección
                //donde buscará el valor
            sube = Eliminar(actual->ObtenerHijo(k), val, valSube, k, actual->ObtenerNumClavesNodo());
            if(!sube) return false;

            //Si el hijo en la posición donde se elimino un elemento es igual a nulo significa que se
            //mezclaron los nodos por lo que se debe de eliminar el elemento en la posición indice K
            if(actual->ObtenerHijo(k) == NULL) QuitarNodo(actual,k);

            //Si el nodo actual no es la raiz se actualizan los valores de los nodos internos
            if(actual != raiz){
                if(actual->ObtenerNumClavesNodo() >= minimo){
                    for(int i = 1; i <= actual->ObtenerNumClavesNodo(); ++i)
                        actual->CambiarClave(i,actual->ObtenerHijo(i)->ObtenerClave(1));
                }
            }



        }else{
            //En caso de encontrar el elemento
            if(actual == raiz && actual->ObtenerNumClavesNodo() == 1 && actual->EsHoja()){
                    //Si solo queda un elemento en la raiz y no tiene hijos se elimina el nodo raiz
                delete actual;
                actual = NULL;
                hijoChico = actual;
            }else if(!actual->EsHoja()){
                //Si encontró el valor y no es hoja se vuelve a llamar al proceso de eliminado con el
                //con la direccion del nodo hijo en la posición esperada
                sube = Eliminar(actual->ObtenerHijo(k), val, valSube, k, actual->ObtenerNumClavesNodo());
                if(!sube) return false;  //Si no encuentra el valor no hace nada y termina el proceso

                //Si el hijo en la posición donde se elimino un elemento es igual a nulo significa que se
                //mezclaron los nodos por lo que se debe de eliminar el elemento en la posición indice K
                if(actual->ObtenerHijo(k) == NULL) QuitarNodo(actual,k);


                    //Se actualizan los valores de los nodos internos y de la raíz
                    if(actual == raiz && actual->ObtenerHijo(0) != NULL && !actual->ObtenerHijo(0)->EsHoja()){
                        actual->CambiarClave(k,valSube);

                    }else{
                        for(int i = 1; i <= actual->ObtenerNumClavesNodo(); ++i)
                            actual->CambiarClave(i,actual->ObtenerHijo(i)->ObtenerClave(1));

                        actual->CambiarClave(k,valSube);
                    }

            }else{
                //Si el elemento encontrado está en un nodo hoja se elimina del nodo en la posición K
                QuitarNodo(actual,k);

                if(actual->ObtenerNumClavesNodo() >= minimo){
                    //Si el nodo tiene mas o igual elementos que el minimo establecido solo se manda el nuevo
                    // valor que debe subir
                    valSube = actual->ObtenerClave(1);
                    sube = true;

                }else{
                    //Si el Nodo donde se eliminó se queda con menos del minimo hacemos los siguientes procesos:

                    //Declaramos un Nodo Aux que almacenará la posición del hermano izquierdo donde se elimino un elemento
                    Nodo* aux = hijoChico;
                    if(aux != actual)
                        while(aux->siguiente != actual)
                            aux = aux->siguiente;



                     //Prestar de la izquierda
                    if(aux->ObtenerNumClavesNodo() > minimo && indicePadre > 0){
                            //Si el hermano de la izquierda tiene valores para prestar y el nodo donde se elimino
                            //no es el primer nodo hoja de un subarbol entonces se presta un elemento de la izquierda

                        MeterNodo(actual, aux->ObtenerClave(aux->ObtenerNumClavesNodo()), actual->ObtenerHijo(1), 0);
                        aux->CambiarNumClavesNodo(aux->ObtenerNumClavesNodo()-1);
                        valSube = actual->ObtenerClave(1);


                    //prestar de la derecha
                    }else if(actual->siguiente != NULL && actual->siguiente->ObtenerNumClavesNodo() > minimo && indicePadre < numClavesPadre){

                            //Si el hermano de la izquierda no tiene valores para prestar entonces se analiza el de la derecha
                            //siempre y cuando el nodo de donde eliminamos no seal el ultimo nodo hoja de todo el arbol

                            MeterNodo(actual, actual->siguiente->ObtenerClave(1),
                                      actual->ObtenerHijo(actual->ObtenerNumClavesNodo()), actual->ObtenerNumClavesNodo());
                            QuitarNodo(actual->siguiente, 1);
                            valSube = actual->ObtenerClave(1);

                    }else{
                        //Mezclar
                        //Si ninguno de los casos anteriores se cumple se procedera a mezclar los nodos
                        //Siempre se intentará mezclar a la izquierda, la unica situación en la que se
                        //mezclara a la derecha será cuando el nodo hoja donde se eliminó un elemento
                        //sea el más chico del subarbol
                        if(indicePadre > 0){


                                //Mezclar a la izquierda
                                //Se agregan los valores en el nodo izquierdo de donde se elimina
                            for(int i = 1; i <= actual->ObtenerNumClavesNodo(); ++i){
                                aux->CambiarClave(aux->ObtenerNumClavesNodo()+i,actual->ObtenerClave(i));
                                aux->CambiarNumClavesNodo(aux->ObtenerNumClavesNodo()+1);
                            }
                            valSube = aux->ObtenerClave(1);
                        }else{
                             //Mezclar a la derecha
                             //Se desplazan los valores del nodo derecho para agregar los que quedan en donde se elimina
                            for(int i = actual->siguiente->ObtenerNumClavesNodo(); i >= 1; --i){
                                actual->siguiente->CambiarClave(i+actual->ObtenerNumClavesNodo(),actual->siguiente->ObtenerClave(i));
                            }
                            //Si el nodo donde se elimino el valor no esta vacio agrega los valores en el nodo derecho
                            if(actual->ObtenerNumClavesNodo() > 0){
                                for(int i = 1; i <= actual->ObtenerNumClavesNodo(); ++i){
                                    actual->siguiente->CambiarClave(i,actual->ObtenerClave(i));
                                    actual->siguiente->CambiarNumClavesNodo(actual->siguiente->ObtenerNumClavesNodo()+1);
                                }
                            }
                            valSube = actual->siguiente->ObtenerClave(1);
                        }

                        // Si el nodo actual es el mas chico de todo el arbol se redirecciona el hijo chico al nodo derecho
                        if(hijoChico == actual) hijoChico = actual->siguiente;
                        else aux->siguiente = actual->siguiente; //Si no, se conecta el nodo izquierdo con el nodo derecho de donde se elimino

                        delete actual; //Se elimina el nodo actual y apunta a nulo
                        actual = NULL;


                    }
                }
                //Regresa verdadero al eliminar
                return true;



            }


        }

            //Una vez hecho el proceso de eliminado se verifica si es un nodo interno que no tiene como hijo un nodo hoja
            // y el numero de datos en el nodo
            if(actual != NULL && actual->ObtenerHijo(k) != NULL && actual->ObtenerHijo(k)->ObtenerNumClavesNodo() < minimo){

                    //Si el nodo interno tiene menos elementos que el minimo establecido hace un proceso de balanceo

                    //Obtenemos la direccion del hijo derecho y del hijo izquierdo
                    Nodo *hijoIzq, *hijoDer, *hijoAux;
                    if(k > 0) hijoIzq = actual->ObtenerHijo(k-1);
                    if(k < actual->ObtenerNumClavesNodo()) hijoDer = actual->ObtenerHijo(k+1);



                    //Si el elemento que eliminamos no se encuentra en el nodo menor del subarbol verificamos si el
                    //hermano izquierdo nos puede prestar elementos (mayor al minimo de elementos)

                    //Pedir prestado de la izquierda
                    if(k > 0 && hijoIzq->ObtenerNumClavesNodo() > minimo){
                        MeterNodo(actual->ObtenerHijo(k), actual->ObtenerClave(k),actual->ObtenerHijo(k)->ObtenerHijo(0) , 0);
                        actual->CambiarClave(k,hijoIzq->ObtenerClave(hijoIzq->ObtenerNumClavesNodo()));
                        hijoAux = hijoIzq->ObtenerHijo(hijoIzq->ObtenerNumClavesNodo());
                        hijoIzq->CambiarNumClavesNodo(hijoIzq->ObtenerNumClavesNodo()-1);
                        actual->ObtenerHijo(k)->CambiarHijo(0, hijoAux);

                    }else if(k < actual->ObtenerNumClavesNodo() && hijoDer->ObtenerNumClavesNodo() > minimo){

                        //Si el hermano izquierdo no nos pudo prestar verificamos que el hermano derecho nos pueda prestar


                            //Pedir prestado de la derecha
                        MeterNodo(actual->ObtenerHijo(k), actual->ObtenerClave(k+1),hijoDer->ObtenerHijo(0) ,actual->ObtenerHijo(k)->ObtenerNumClavesNodo() );
                        actual->CambiarClave(k+1,hijoDer->ObtenerClave(1));
                        hijoDer->CambiarHijo(0,hijoDer->ObtenerHijo(1));
                        QuitarNodo(hijoDer,1);
                    }else if(k > 0){

                            //Si ninguno de los hermanos nos pudo prestar valores debemos mezclar los nodos internos
                            //Siempre verificamos primero a la izquierda, cuando el elemento eliminado no se encuentre
                            //el nodo menor del subarbol

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
                        //En caso contrario se Mezcla a la derecha
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
                //Si el Nodo actual es igual a la raíz y esta ya no tiene elementos, entonces se cambia
                // la dirección de la raíz y del hijo mas chico del arbol
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
void ArbolBMas<T,grado>::QuitarNodo(Nodo* actual, int k){
    // desplaza a la izquierda los elementos para hacer un hueco
    for (int i = k; i <= actual->ObtenerNumClavesNodo()-1; ++i){
        actual->CambiarClave(i, actual->ObtenerClave(i+1));
        actual->CambiarHijo(i, actual->ObtenerHijo(i+1));
    }
    // incrementa el contador de claves almacenadas
    actual->CambiarNumClavesNodo(actual->ObtenerNumClavesNodo()-1) ;
}

