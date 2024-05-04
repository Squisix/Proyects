/*
    \Name: Heap.tpp
    \Author: Marco Antonio Guerrero Vasquez // 219202704
    \Date: 04/27/21
    \brief: Template file where the functions and operators of the Heap class are declared
*/

#include <iostream>

//*****************************************************//
template <typename T,bool (*Order)(const T &a, const T &b)>
const int Heap<T,Order>::Capacity() const{
    return cap;
}
//*****************************************************//
template <typename T,bool (*Order)(const T &a, const T &b)>
Heap<T,Order>::Heap():top(NO_ELEMENT),cap(31),content(new T[cap]){  //Costructor
}
//*****************************************************//
template <typename T,bool (*Order)(const T &a, const T &b)>
Heap<T,Order>::Heap(const Heap<T,Order> &h):top(NO_ELEMENT),cap(0),content(NULL){  //Costructor
    *this = h;
}

//*****************************************************//
template <typename T,bool (*Order)(const T &a, const T &b)>
Heap<T,Order>::~Heap(){  //Destructor
    delete [] content;
}
//*****************************************************//
template <typename T,bool (*Order)(const T &a, const T &b)>
Heap<T,Order>& Heap<T,Order>::operator=(const Heap<T,Order> &h){  //Costructor
    if(this == &h) return *this;
    delete [] content;
    top = h.top;
    cap = h.cap;
    content = new T[cap];
    for(int i = 0; i <= top; ++i)content[i] = h.content[i];
    return *this;
}
//*****************************************************//

template <typename T,bool (*Order)(const T &a, const T &b)>
void Heap<T,Order>::Resize(){
    T *aux = content;
    cap *= 2;
    content = new T[cap];
    for(int i = 0; i <= top; ++i) content[i] = aux[i];
    delete [] aux;
}

//*****************************************************//
template <typename T,bool (*Order)(const T &a, const T &b)>
void Heap<T,Order>::Push(const T& value){
    if(Full()) Resize();
    content[++top] = value;
    Push_Up();
}
//*****************************************************//
template <typename T,bool (*Order)(const T &a, const T &b)>
void Heap<T,Order>::Pop(){
    if(Empty()) throw EmptyHeap();
    std::swap(content[0],content[top]);
    Push_Down(0);
    --top;
}
//*****************************************************//
template <typename T,bool (*Order)(const T &a, const T &b)>
void Heap<T,Order>::Clear(){
    while(!Empty()) Pop();
}
//*****************************************************//
template <typename T,bool (*Order)(const T &a, const T &b)>
const T& Heap<T,Order>::Top()const{
    if(Empty()) throw EmptyHeap();
    return content[top];
}
//*****************************************************//
template <typename T,bool (*Order)(const T &a, const T &b)>
unsigned Heap<T,Order>::Size() const{
    return top+1;
}
//*****************************************************//
template <typename T,bool (*Order)(const T &a, const T &b)>
bool Heap<T,Order>::Empty() const{
    return top == NO_ELEMENT;
}
//*****************************************************//
template <typename T,bool (*Order)(const T &a, const T &b)>
bool Heap<T,Order>::Full() const{
    return top == cap-1;
}
//*****************************************************//
template <typename T,bool (*Order)(const T &a, const T &b)>
const char* Heap<T,Order>::EmptyHeap::what() const throw(){
    return "Empty Heap...";
}
//*****************************************************//
template <typename T,bool (*Order)(const T &a, const T &b)>
void Heap<T,Order>::Print() const{
    if(!std::is_pod<T>::value){
        for(unsigned i = 0; i < Size(); ++i)
            std::cout << content[i];
    }else{
        std::cout << "{";
        for(unsigned i = 0; i < Size(); ++i)
            std::cout << content[i] << ", ";
        if(Empty()) std::cout << "}" << std::endl;
        else std::cout << "\b\b}" << std::endl;
    }
}
//*****************************************************//
template <typename T, bool(*Order)(const T &a, const T &b)>
void Heap<T,Order>::Push_Up(){
    int i = top;
    int parent = (i-1)/2;
    while(i != 0 && !Order(content[parent],content[i])){
        std::swap(content[parent],content[top]);
        i = parent;
        parent = (i-1)/2;
    }
}
//*****************************************************//
template <typename T, bool(*Order)(const T &a, const T &b)>
void Heap<T,Order>::Push_Down(int i){
    int l = 2*i+1;
    int r = 2*i+2;
    int min_max = i;
    if (l < top && Order(content[l],content[i]))
        min_max = l;
    if (r < top && Order(content[r],content[min_max]))
        min_max = r;
    if (min_max != i)
    {
        std::swap(content[i], content[min_max]);
        Push_Down(min_max);
    }
}

template <typename T,bool (*Order)(const T &a, const T &b)>
const T& Heap<T,Order>::Root()const{
    if(Empty()) throw EmptyHeap();
    return content[0];
}
