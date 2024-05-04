/*
    \Name: ResizableStack.tpp
    \Author: Marco Antonio Guerrero Vasquez // 219202704
    \Date: 02/11/21
    \brief: Template file where the functions and operators of the ResizableStack class are declared
*/

#include <iostream>
template <typename U>
std::ostream& operator<< (std::ostream& outflow, const ResizableStack<U> &s){
    if(!std::is_pod<U>::value){
        for(unsigned i = 0; i < s.Size(); ++i)
            outflow << s.content[i];
    }else{
        outflow << "{";
        for(unsigned i = 0; i < s.Size(); ++i)
            outflow << s.content[i] << ", ";
        if(s.Empty()) outflow << "}" << std::endl;
        else outflow << "\b\b}" << std::endl;
    }
    return outflow;
}
//*****************************************************//
template <typename T>
const int ResizableStack<T>::Capacity() const{
    return cap;
}
//*****************************************************//
template <typename T>
ResizableStack<T>::ResizableStack():top(NO_ELEMENT),cap(10),content(new T[cap]){  //Costructor
}
//*****************************************************//
template <typename T>
ResizableStack<T>::ResizableStack(const ResizableStack<T> &s):top(NO_ELEMENT),cap(0),content(NULL){  //Costructor
    *this = s;
}

//*****************************************************//
template <typename T>
ResizableStack<T>::~ResizableStack(){  //Destructor
    delete [] content;
}
//*****************************************************//
template <typename T>
ResizableStack<T>& ResizableStack<T>::operator=(const ResizableStack<T> &s){  //Costructor
    if(this == &s) return *this;
    delete [] content;
    top = s.top;
    cap = s.cap;
    content = new T[cap];
    for(int i = 0; i <= top; ++i)content[i] = s.content[i];
    return *this;
}
//*****************************************************//

template <typename T>
void ResizableStack<T>::Resize(){
    T *aux = content;
    cap *= 2;
    content = new T[cap];
    for(int i = 0; i <= top; ++i) content[i] = aux[i];
    delete [] aux;
}

//*****************************************************//
template <typename T>
void ResizableStack<T>::Push(const T& value){
    if(Full()) Resize();
    content[++top] = value;
}
//*****************************************************//
template <typename T>
void ResizableStack<T>::Pop(){
    if(Empty()) throw EmptyStack();
    --top;
}
//*****************************************************//
template <typename T>
void ResizableStack<T>::Clear(){
    top = NO_ELEMENT;
}
//*****************************************************//
template <typename T>
const T& ResizableStack<T>::Top()const{
    if(Empty()) throw EmptyStack();
    return content[top];
}
//*****************************************************//
template <typename T>
unsigned ResizableStack<T>::Size() const{
    return top+1;
}
//*****************************************************//
template <typename T /* = int*/>
bool ResizableStack<T>::Empty() const{
    return top == NO_ELEMENT;
}
//*****************************************************//
template <typename T>
bool ResizableStack<T>::Full() const{
    return top == cap-1;
}
//*****************************************************//
template <typename T>
const char* ResizableStack<T>::EmptyStack::what() const throw(){
    return "Empty Stack...";
}
//*****************************************************//
template <typename T>
void ResizableStack<T>::Print() const{
    std::cout << *this;
}
//*****************************************************//

