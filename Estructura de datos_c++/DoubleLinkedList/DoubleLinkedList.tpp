
/*
    \Name: ResizableStack.tpp
    \Author: Marco Antonio Guerrero Vasquez // 219202704
    \Date: 02/21/21
    \brief: Template file where the functions and operators of the LinkedDataStack class are declared
*/

#include <iostream>
template <typename U>
std::ostream& operator<< (std::ostream& outflow, const DoubleLinkedList<U> &l){
    typename DoubleLinkedList<U>::Node *Aux = l.first;
    if(!std::is_pod<U>::value){
            while(Aux != NULL){
                outflow << Aux -> value << std::endl;
                Aux = Aux -> next;
            }
    }else{
        outflow << "First->{";

        while(Aux != NULL){
            outflow << Aux -> value << ", ";
            Aux = Aux -> next;
        }
        if(!l.Empty()) outflow << "\b\b}<- Last" << std::endl;
        else outflow << "}<- Last" << std::endl;
    }
    return outflow;
}
//*****************************************************//
template <typename T>
DoubleLinkedList<T>::DoubleLinkedList():lSize(0), last(NULL),first(NULL){ //Costructor
}
//*****************************************************//
template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(const DoubleLinkedList<T> &l):lSize(0),last(NULL),first(NULL){  //Costructor
    *this = l;
}

//*****************************************************//
template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList(){  //Destructor
    Clear();
}
//*****************************************************//
template <typename T>
DoubleLinkedList<T>::Node::Node(const T& val, Node *n /*=NULL*/, Node *p):value(val),next(n), previous(p){
}
//*****************************************************//
template <typename T>
DoubleLinkedList<T>& DoubleLinkedList<T>::operator=(const DoubleLinkedList<T> &l){  //Costructor
    if(this == &l) return *this;
    Clear();

    Node *aux = l.first;
    while(aux != NULL){
            Push_Back(aux -> value);
            aux = aux -> next;
    }
    return *this;
}

//*****************************************************//
template <typename T>
void DoubleLinkedList<T>::Push_Front(const T& value){
    Node *nNode = new Node(value);

    if(Empty()){
       first = last = nNode;
    }else{
        nNode -> next = first;
        first -> previous = nNode;
        first = nNode;
    }
    ++lSize;
}
//*****************************************************//
template <typename T>
void DoubleLinkedList<T>::Push_Back(const T& value){
    Node *nNode = new Node(value);

    if(Empty()){
       first = last = nNode;
    }else{
        last -> next = nNode;
        nNode -> previous = last;
        last = nNode;
    }
    ++lSize;
}
//*****************************************************//
template <typename T>
void DoubleLinkedList<T>::Push_In_Pos(int pos, const T& val){

    if(!Empty()){
        while(pos < -1) pos += lSize+1;
        while(pos > (int)lSize-1) pos -= lSize;
    }else pos = 0;

    if(pos == 0) Push_Front(val);
    else if(pos == -1) Push_Back(val);
    else{
        Node *aux = SearchPosDir(pos);
        Node *nNode = new Node(val,aux,aux->previous);
        aux->previous = aux->previous->next = nNode;
        ++lSize;

    }

}
//*****************************************************//
template <typename T>
void DoubleLinkedList<T>::Pop_Front(){
    if(Empty()) throw EmptyList();
    Node *out = first;
    first = first -> next;
    (first == NULL ? last : first->previous) = NULL;
    delete out;

    --lSize;

}
//*****************************************************//
template <typename T>
void DoubleLinkedList<T>::Pop_Back(){
    if(Empty()) throw EmptyList();
    Node *out = last;
    last = last -> previous;
    (last == NULL ? first : last->next) = NULL;
    delete out;

    --lSize;
}
//*****************************************************//
template <typename T>
void DoubleLinkedList<T>::Pop_In_Pos(int pos){
    if(Empty())throw EmptyList();

    while(pos < -1) pos += lSize+1;
    while(pos > (int)lSize-1) pos -= lSize;

    if(pos == 0) Pop_Front();
    else if(pos == -1 || pos == (int)lSize-1) Pop_Back();
    else{
        Node *out = SearchPosDir(pos);
        out->previous->next = out->next;
        out->next->previous = out->previous;
        delete out;
        --lSize;
    }
}
//*****************************************************//
template <typename T>
void DoubleLinkedList<T>::Clear(){
    while(!Empty()) Pop_Front();
}
//*****************************************************//
template <typename T>
bool DoubleLinkedList<T>::Search(const T& val) const{
    Node *aux = first;
    while(aux!=NULL && aux->value!=val) aux = aux->next;
    return aux != NULL;
}
//*****************************************************//
template <typename T>
int DoubleLinkedList<T>::Search_Pos(const T& val) const{
    int pos = 0;
    Node *aux = first;
    for(pos = 0; aux != NULL && aux->value != val; ++pos) aux = aux->next;
    return aux != NULL ? pos : -1;
}
//*****************************************************//
template <typename T>
const T& DoubleLinkedList<T>::GetLast()const{
    if(Empty()) throw EmptyList();
    return last -> value;
}
//*****************************************************//
template <typename T>
const T& DoubleLinkedList<T>::GetFirst() const{
   if(Empty()) throw EmptyList();
    return first -> value;
}
//*****************************************************//
template <typename T>
const T& DoubleLinkedList<T>::GetPos(int pos) const{
   if(Empty())throw EmptyList();
   return SearchPosDir(pos)->value;
}
//*****************************************************//
template <typename T>
void DoubleLinkedList<T>::ModifyPos(int pos, const T& val){
   if(Empty())throw EmptyList();
   SearchPosDir(pos)->value = val;
}
//*****************************************************//
template <typename T>
unsigned DoubleLinkedList<T>::Size() const{
    return lSize;
}
//*****************************************************//
template <typename T /* = int*/>
bool DoubleLinkedList<T>::Empty() const{
    return lSize == 0;
}
//*****************************************************//
template <typename T>
const char* DoubleLinkedList<T>::EmptyList::what() const throw(){
    return "Empty List...";
}
//*****************************************************//
template <typename T>
void DoubleLinkedList<T>::Print() const{
    std::cout << *this << std::endl;
}
//*****************************************************//
template <typename T>
void DoubleLinkedList<T>::ReversePrint() const{
    Node *Aux = last;
    if(!std::is_pod<T>::value){
            while(Aux != NULL){
                std::cout << Aux -> value << std::endl;
                Aux = Aux -> previous;
            }
    }else{
        std::cout << "Last->{";

        while(Aux != NULL){
            std::cout << Aux -> value << ", ";
            Aux = Aux -> previous;
        }
        if(!Empty()) std::cout << "\b\b}<- First" << std::endl;
        else std::cout << "}<- Last" << std::endl;
    }
}
//*****************************************************//
template <typename T>
const T& DoubleLinkedList<T>::operator[] (int pos) const{
    if(Empty())throw EmptyList();

    T& val;
    while(pos < -1) pos += lSize+1;
    while(pos > lSize-1) pos -= lSize;

    if(pos == 0) val = GetFirst();
    else if(pos == -1) val = GetLast();
    else{
        Node *prev = first;
        for(int i = 1; i < pos; ++i) prev = prev -> next;
        val = prev -> next -> value;
    }
    return val;
}
//*****************************************************//
template <typename T>
T& DoubleLinkedList<T>::operator[] (int pos){
    if(Empty())throw EmptyList();

    while(pos < -1) pos += lSize+1;
    while(pos > (int)lSize-1) pos -= lSize;

    if(pos == 0) return first->value;
    else if(pos == -1) return last->value;
    else{
        Node *prev = first;
        for(int i = 1; i < pos; ++i) prev = prev -> next;
        return prev -> next -> value;
    }
}
//*****************************************************//

template <typename T>
typename DoubleLinkedList<T>::Node* DoubleLinkedList<T>::SearchPosDir(int pos) const{
    if(!Empty()){
        while(pos < -1) pos += lSize+1;
        while(pos > (int)lSize-1) pos -= lSize;
    }else pos = 0;

    Node *aux;
    if(pos == -1) aux = last;
    else if(pos < (int)lSize/2){
        aux = first;
        for(int i = 0; i < pos; ++i) aux = aux -> next;
    }else{
        aux = last;
        for(int i = (int)lSize - pos; i > 1; --i) aux = aux -> previous;
    }
    return aux;
}
//*****************************************************//
template <typename T>
void DoubleLinkedList<T>::DeleteElement(const T& val){
    if(Empty()) throw EmptyList();
    while(Search(val)){
        Pop_In_Pos(Search_Pos(val));
    }
}

//*****************************************************//
template <typename T>
void DoubleLinkedList<T>::DeleteElementIf(const T& val, bool (*Condition)(const T&)){
    if(Empty()) throw EmptyList();
    if(Condition) DeleteElement(val);
}
//*****************************************************//
template <typename T>
bool DoubleLinkedList<T>::IsRepeated(const T& val){
    int valCont = 0;
    Node *aux = first;
    if(!Search(val)) return false;
    while(aux!=NULL){
        if(aux->value == val) ++valCont;
        if(valCont > 1) return true;
        aux = aux->next;
    }
    return false;
}
//*****************************************************//
template <typename T>
void DoubleLinkedList<T>::DeleteRepeatedElements(){
    Node *aux = first;
    while(aux!=NULL){
        if(IsRepeated(aux->value)) Pop_In_Pos(Search(aux->value));
        aux = aux->next;
    }
}
//*****************************************************//
template <typename T>
void DoubleLinkedList<T>::SortAscending(){
    bool itIsOrdered = false;
    T temp;
    for(int i = 1; i < (int)lSize && !itIsOrdered; ++i){
        itIsOrdered = true;
        for(int j = 0; j < (int)lSize - i; ++j){
            if((*this)[j] > (*this)[j+1]){
                temp = (*this)[j];
                (*this)[j] = (*this)[j+1];
                (*this)[j+1] = temp;
                itIsOrdered = false;
            }
        }
    }
}
//*****************************************************//
template <typename T>
void DoubleLinkedList<T>::Exchange(DoubleLinkedList &l){
    DoubleLinkedList aux = *this;
    *this = l;
    l = aux;
}
//*****************************************************//
template <typename T>
void DoubleLinkedList<T>::Transfer(DoubleLinkedList &l){
    while(!l.Empty()){
        Push_Back(l.GetFirst());
        l.Pop_Front();
    }
}
//*****************************************************//
template <typename T>
void DoubleLinkedList<T>::TransferSince(DoubleLinkedList &l, int pos){

    while((l.SearchPosDir(pos-1))->next!=NULL){
        Push_Back(l.GetPos(pos));
        l.Pop_In_Pos(pos);
    }
}
//*****************************************************//
template <typename T>
void DoubleLinkedList<T>::TransferSinceTo(DoubleLinkedList &l, int iPos, int fPos){
    while(iPos < -1) iPos += l.Size()+1;
    while(iPos > (int)l.Size()-1) iPos -= l.Size();

    while(fPos < -1) fPos += l.Size()+1;
    while(fPos > (int)l.Size()-1) fPos -= l.Size();

    if(iPos > fPos){
        int temp = iPos;
        iPos = fPos;
        fPos = temp;
    }

    Node *aux1 = (l.SearchPosDir(iPos-1))->next, *aux2 = l.SearchPosDir(fPos+1);

    while(aux1 != aux2){
        Push_Back(l.GetPos(iPos));
        l.Pop_In_Pos(iPos);
    }
}

