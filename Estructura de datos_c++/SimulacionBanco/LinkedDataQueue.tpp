/*
    \Name: ResizableStack.tpp
    \Author: Marco Antonio Guerrero Vasquez // 219202704
    \Date: 02/21/21
    \brief: Template file where the functions and operators of the LinkedDataStack class are declared
*/

#include <iostream>
template <typename U>
std::ostream& operator<< (std::ostream& outflow, const LinkedDataQueue<U> &q){
    typename LinkedDataQueue<U>::Node *Aux = q.last -> next;
    if(!std::is_pod<U>::value){
        if(!q.Empty()){
            do{
                outflow << Aux -> value << std::endl;
                Aux = Aux -> next;
            }while(Aux != q.last -> next);
        }else{
            outflow << " ";
        }

    }else{
        outflow << "First->{";
        if(!q.Empty()){
            do{
                outflow << Aux -> value << ", ";
                Aux = Aux -> next;
            }while(Aux != q.last -> next);
            outflow << "\b\b}<- Last" << std::endl;

        } else outflow << "}<- Last" << std::endl;

    }
    return outflow;
}
//*****************************************************//
template <typename T>
LinkedDataQueue<T>::LinkedDataQueue():qSize(0), last(NULL){ //Costructor
}
//*****************************************************//
template <typename T>
LinkedDataQueue<T>::LinkedDataQueue(const LinkedDataQueue<T> &q):qSize(0),last(NULL){  //Costructor
    *this = q;
}

//*****************************************************//
template <typename T>
LinkedDataQueue<T>::~LinkedDataQueue(){  //Destructor
    Clear();
}
//*****************************************************//
template <typename T>
LinkedDataQueue<T>::Node::Node(const T& val, Node *n /*=NULL*/):value(val),next(n){
}
//*****************************************************//
template <typename T>
LinkedDataQueue<T>& LinkedDataQueue<T>::operator=(const LinkedDataQueue<T> &q){  //Costructor
    if(this == &q) return *this;
    Clear();
    if(!q.Empty()){
        Node *aux = (q.last) -> next;
        do{
            Push(aux -> value);
            aux = aux -> next;
        }while(aux != (q.last) -> next);
    }
    return *this;
}

//*****************************************************//
template <typename T>
void LinkedDataQueue<T>::Push(const T& value){
    Node *nNode = new Node(value);
    if(Empty()){
       nNode -> next = nNode;
    }else{
        nNode -> next = last -> next;
        last -> next = nNode;
    }
    last = nNode;
    ++qSize;
}
//*****************************************************//
template <typename T>
void LinkedDataQueue<T>::Pop(){
    if(Empty()) throw EmptyQueue();
    Node *out = last -> next;
    last -> next = last -> next -> next;
    delete out;

    --qSize;

}
//*****************************************************//
template <typename T>
void LinkedDataQueue<T>::Clear(){
    while(!Empty()) Pop();
}
//*****************************************************//
template <typename T>
const T& LinkedDataQueue<T>::GetLast()const{
    if(Empty()) throw EmptyQueue();
    return last -> value;
}
//*****************************************************//
template <typename T>
const T& LinkedDataQueue<T>::GetFirst() const{
   if(Empty()) throw EmptyQueue();
    return last -> next -> value;
}
//*****************************************************//
template <typename T>
unsigned LinkedDataQueue<T>::Size() const{
    return qSize;
}
//*****************************************************//
template <typename T /* = int*/>
bool LinkedDataQueue<T>::Empty() const{
    return qSize == 0;
}
//*****************************************************//
template <typename T>
const char* LinkedDataQueue<T>::EmptyQueue::what() const throw(){
    return "Empty Queue...";
}
//*****************************************************//
template <typename T>
void LinkedDataQueue<T>::Print() const{
    std::cout << *this << std::endl;
}
//*****************************************************//


