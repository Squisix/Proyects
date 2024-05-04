/*
    \Name: ResizableStack.tpp
    \Author: Marco Antonio Guerrero Vasquez // 219202704
    \Date: 02/21/21
    \brief: Template file where the functions and operators of the LinkedDataStack class are declared
*/

#include <iostream>
template <typename U>
std::ostream& operator<< (std::ostream& outflow, const SimpleList<U> &l){
    typename SimpleList<U>::Node *Aux = l.first;
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
SimpleList<T>::SimpleList():lSize(0), last(NULL),first(NULL){ //Costructor
}
//*****************************************************//
template <typename T>
SimpleList<T>::SimpleList(const SimpleList<T> &l):lSize(0),last(NULL),first(NULL){  //Costructor
    *this = l;
}

//*****************************************************//
template <typename T>
SimpleList<T>::~SimpleList(){  //Destructor
    Clear();
}
//*****************************************************//
template <typename T>
SimpleList<T>::Node::Node(const T& val, Node *n /*=NULL*/):value(val),next(n){
}
//*****************************************************//
template <typename T>
SimpleList<T>& SimpleList<T>::operator=(const SimpleList<T> &l){  //Costructor
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
void SimpleList<T>::Push_Front(const T& value){
    Node *nNode = new Node(value);
    if(Empty()){
       first = last = nNode;
    }else{
        nNode -> next = first;
        first = nNode;
    }
    ++lSize;
}
//*****************************************************//
template <typename T>
void SimpleList<T>::Push_Back(const T& value){
    Node *nNode = new Node(value);
    if(Empty()){
       first = last = nNode;
    }else{
        last -> next = nNode;
        last = nNode;
    }
    ++lSize;
}
//*****************************************************//
template <typename T>
void SimpleList<T>::Push_In_Pos(int pos, const T& val){
    if(!Empty()){
        while(pos < -1) pos += lSize+1;
        while(pos > (int)lSize-1) pos -= lSize;
    }else pos = 0;


    if(pos == 0) Push_Front(val);
    else if(pos == -1) Push_Back(val);
    else{
        Node *prev = first;
        for(int i = 1; i < pos; ++i) prev = prev -> next;
        Node *nNode = new Node(val, prev -> next);
        prev -> next = nNode;
        ++lSize;
    }

}
//*****************************************************//
template <typename T>
void SimpleList<T>::Pop_Front(){
    if(Empty()) throw EmptyList();
    Node *out = first;
    if(first->next == NULL) last = NULL;
    first = first -> next;
    delete out;

    --lSize;

}
//*****************************************************//
template <typename T>
void SimpleList<T>::Pop_Back(){
    if(Empty()) throw EmptyList();
    Node *prev = first;
    while(prev != last && prev->next != last) prev = prev->next;
    prev->next = NULL;
    delete last;
    last = lSize == 1 ? first = NULL : prev;
    --lSize;
}
//*****************************************************//
template <typename T>
void SimpleList<T>::Pop_In_Pos(int pos){
    if(Empty())throw EmptyList();

    while(pos < -1) pos += lSize+1;
    while(pos > (int)lSize-1) pos -= lSize;

    if(pos == 0) Pop_Front();
    else if(pos == -1) Pop_Back();
    else{
        Node *prev = first;
        for(int i = 1; i < pos; ++i) prev = prev -> next;
        Node *out = prev->next;
        prev -> next = out->next;
        delete out;
        --lSize;
    }
}
//*****************************************************//
template <typename T>
void SimpleList<T>::Clear(){
    while(!Empty()) Pop_Front();
}
//*****************************************************//
template <typename T>
bool SimpleList<T>::Search(const T& val) const{
    Node *aux = first;
    while(aux!=NULL && aux->value!=val) aux = aux->next;
    return aux != NULL;
}
//*****************************************************//
template <typename T>
int SimpleList<T>::Search_Pos(const T& val) const{
    int pos = 0;
    Node *aux = first;
    while(aux!=NULL && aux->value!=val) {
            aux = aux->next;
            ++pos;
    }
    if (aux == NULL) return -1;
    else return pos;
}
//*****************************************************//
template <typename T>
const T& SimpleList<T>::GetLast()const{
    if(Empty()) throw EmptyList();
    return last -> value;
}
//*****************************************************//
template <typename T>
const T& SimpleList<T>::GetFirst() const{
   if(Empty()) throw EmptyList();
    return first -> value;
}
//*****************************************************//
template <typename T>
const T& SimpleList<T>::GetPos(int pos) const{
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
void SimpleList<T>::ModifyPos(int pos, const T& val){
   if(Empty())throw EmptyList();

   while(pos < -1) pos += lSize+1;
   while(pos > lSize-1) pos -= lSize;

   if(pos == 0) val = GetFirst();
   else if(pos == -1) val = GetLast();
   else{
       Node *prev = first;
       for(int i = 1; i < pos; ++i) prev = prev -> next;
       prev -> next -> value = val;
    }
}
//*****************************************************//
template <typename T>
unsigned SimpleList<T>::Size() const{
    return lSize;
}
//*****************************************************//
template <typename T /* = int*/>
bool SimpleList<T>::Empty() const{
    return lSize == 0;
}
//*****************************************************//
template <typename T>
const char* SimpleList<T>::EmptyList::what() const throw(){
    return "Empty List...";
}
//*****************************************************//
template <typename T>
void SimpleList<T>::Print() const{
    std::cout << *this << std::endl;
}
//*****************************************************//
template <typename T>
const T& SimpleList<T>::operator[] (int pos) const{
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
T& SimpleList<T>::operator[] (int pos){
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
