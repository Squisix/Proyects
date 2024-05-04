
/*
    \Name: DoubleCircularList.tpp
    \Author: Marco Antonio Guerrero Vasquez // 219202704
    \Date: 03/26/21
    \brief: Template file where the functions and operators of the DoubleCircularList
            class are declared
*/
template <typename U>
std::ostream& operator<< (std::ostream& outflow, const DoubleCircularList<U> &l){
    if(!std::is_pod<U>::value){
            if(l.Empty()){
                outflow << "Empty List..." << std::endl;
            }else{
            typename DoubleCircularList<U>::Node *Aux = l.head;
                do{
                    outflow << Aux -> value << std::endl;
                    Aux = Aux -> next;
                }while(Aux != l.head);
            }

    }else{
        outflow << "Head->{";
        if(l.Empty()) outflow << "}" << std::endl;
        else{
            typename DoubleCircularList<U>::Node *Aux = l.head;
            do{
                outflow << Aux -> value << ", ";
                Aux = Aux -> next;
            }while(Aux != l.head);
            outflow << "\b\b}" << std::endl;
        }


    }
    return outflow;
}
//*****************************************************//
template <typename T>
DoubleCircularList<T>::DoubleCircularList():lSize(0),head(NULL){
}
//*****************************************************//
template <typename T>
DoubleCircularList<T>::DoubleCircularList(const DoubleCircularList<T> &l):lSize(0),head(NULL){
    *this = l;
}
//*****************************************************//
template <typename T>
DoubleCircularList<T>::~DoubleCircularList(){
    Clear();
}
//*****************************************************//
template <typename T>
DoubleCircularList<T>::Node::Node(const T& val, Node *n /*=NULL*/, Node *p /*=NULL*/):value(val),next(n), previous(p){
}
//*****************************************************//
template <typename T>
DoubleCircularList<T>& DoubleCircularList<T>::operator=(const DoubleCircularList<T> &l){
    if(this == &l) return *this;
    Clear();
    if(!l.Empty()){
        Node *aux = l.head;
        do{
            Push(aux -> value);
            aux = aux -> next;
            head = head -> next;
        }while(aux != l.head);
    head = head->next;
    }
    return *this;
}

//*****************************************************//
template <typename T>
void DoubleCircularList<T>::Push(const T& value){
    if(Empty()){
        Node *nNode = new Node(value);

        head = nNode;
        nNode->next = nNode;
        nNode->previous = nNode;
    }else{
        Node *nNode = new Node(value, head->next, head);
        head->next->previous = nNode;
        head->next = nNode;
    }
    ++lSize;
}
//*****************************************************//
template <typename T>
void DoubleCircularList<T>::Pop(){
    if(Empty()) throw EmptyList();

    Node *out = head->next;
    if(head != out){
        head->next = out->next;
        out->next->previous = head;
    }else head = NULL;

    delete out;

    --lSize;

}
//*****************************************************//
template <typename T>
bool DoubleCircularList<T>::Search(const T& val) const{
    if(Empty()) return false;
    Node *aux = head->next;

    while(aux!=head && aux->value!=val)aux = aux->next;
    return aux->value == val;
}
//*****************************************************//
template <typename T>
void DoubleCircularList<T>::Clear(){
    while(!Empty()) Pop();
}
//*****************************************************//
template <typename T>
unsigned DoubleCircularList<T>::Size() const{
    return lSize;
}

//*****************************************************//
template <typename T>
bool DoubleCircularList<T>::Empty() const{
    return lSize == 0;
}
//*****************************************************//
template <typename T>
void DoubleCircularList<T>::Print() const{
    std::cout << *this;
}

//*****************************************************//

template <typename T>
const char* DoubleCircularList<T>::EmptyList::what() const throw(){
    return "Empty List...";
}

template <typename T>
void DoubleCircularList<T>::MoveHeadForward(){
    if(Empty()) throw EmptyList();
    head = head -> next;
}

template <typename T>
void DoubleCircularList<T>::MoveHeadBackward(){
    if(Empty()) throw EmptyList();
    head = head -> previous;
}

template <typename T>
const T& DoubleCircularList<T>::GetHead() const{
    if(Empty()) throw EmptyList();
    return head->value;
}

template <typename T>
void DoubleCircularList<T>::ModifyHead(const T& value){
    if(Empty()) throw EmptyList();
    head->value = value;
}

template <typename T>
void DoubleCircularList<T>::DeleteElement(const T& value){
    if(Empty()) throw EmptyList();

    if(Search(value)){
        if(head == SearchDir(value)){
            MoveHeadBackward();
            Pop();
        }else{
            Node *aux = head;
            head = SearchDir(value)->previous;
            Pop();
            head = aux;
        }
    }
}

template <typename T>
void DoubleCircularList<T>::DeleteRepeatedElement(const T& value){
    if(Empty()) throw EmptyList();
    while(Search(value)) DeleteElement(value);
}


template <typename T>
typename DoubleCircularList<T>::Node* DoubleCircularList<T>::SearchDir(const T& val) const{
    if(Search(val)){
        Node *aux = head->next;
        while(aux!=head && aux->value!=val)aux = aux->next;
        return aux;
    }else return NULL;
}
