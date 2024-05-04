/*
    \Name: ResizableStack.tpp
    \Author: Marco Antonio Guerrero Vasquez // 219202704
    \Date: 02/11/21
    \brief: Template file where the functions and operators of the ResizableStack class are declared
*/

#include <iostream>
//template <typename U>
//std::ostream& operator<< (std::ostream& outflow, const LinkedDataStack<U> &s){
//    Node *Aux = s.top;
//    if(!std::is_pod<U>::value){
//        while(Aux!=NULL){
//            outflow << Aux -> value << ", ";
//            Aux = Aux -> next;
//        }
//    }else{
//        outflow << "Top->{";
//        while(Aux!=NULL){
//            outflow << Aux -> value << ", ";
//            Aux = Aux -> next;
//        }
//        if(s.Empty()) outflow << "}" << std::endl;
//        else outflow << "\b\b}" << std::endl;
//    }
//    return outflow;
//}
//*****************************************************//
template <typename T>
LinkedDataStack<T>::LinkedDataStack():sSize(0), top(NULL){ //Costructor
}
//*****************************************************//
template <typename T>
LinkedDataStack<T>::LinkedDataStack(const LinkedDataStack<T> &s):sSize(0),top(NULL){  //Costructor
    *this = s;
}

//*****************************************************//
template <typename T>
LinkedDataStack<T>::~LinkedDataStack(){  //Destructor
    Clear();
}
//*****************************************************//
template <typename T>
LinkedDataStack<T>::Node::Node(T val, Node *n /*=NULL*/):value(val),next(n){
}
//*****************************************************//
template <typename T>
LinkedDataStack<T>& LinkedDataStack<T>::operator=(const LinkedDataStack<T> &s){  //Costructor
    if(this == &s) return *this;
    Clear();
    Node *aux = s.top, **auxCopy = &top;
    while(aux != NULL){
        *auxCopy = new Node(aux->value);
        auxCopy = &((*auxCopy)->next);
        aux = aux -> next;
    }
    sSize = s.sSize;
    return *this;
}

//*****************************************************//
template <typename T>
void LinkedDataStack<T>::Push(const T& value){
    Node *newN = new Node(value,top);
    top = newN;
    ++sSize;
}
//*****************************************************//
template <typename T>
void LinkedDataStack<T>::Pop(){
    if(Empty()) throw EmptyStack();
    Node *out = top;
    top = top -> next;
    delete out;
    --sSize;
}
//*****************************************************//
template <typename T>
void LinkedDataStack<T>::Clear(){
    while(!Empty()) Pop();
}
//*****************************************************//
template <typename T>
const T& LinkedDataStack<T>::Top()const{
    if(Empty()) throw EmptyStack();
    return top -> value;
}
//*****************************************************//
template <typename T>
unsigned LinkedDataStack<T>::Size() const{
    return sSize;
}
//*****************************************************//
template <typename T /* = int*/>
bool LinkedDataStack<T>::Empty() const{
    return top == NULL;
}
//*****************************************************//
template <typename T>
const char* LinkedDataStack<T>::EmptyStack::what() const throw(){
    return "Empty Stack...";
}
//*****************************************************//
template <typename T>
void LinkedDataStack<T>::Print() const{
    Node *Aux = top;
    if(!std::is_pod<T>::value){
        while(Aux!=NULL){
            std::cout << Aux -> value << std::endl;
            Aux = Aux -> next;
        }
    }else{
        std::cout << "Top->{";
        while(Aux!=NULL){
            std::cout << Aux -> value << ", ";
            Aux = Aux -> next;
        }
        if(Empty()) std::cout << "}" << std::endl;
        else std::cout << "\b\b}" << std::endl;
    }
}
//*****************************************************//

