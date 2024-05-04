#include <iostream>
template <typename U, unsigned a>
std::ostream& operator<< (std::ostream& outflow, const Stack<U,a> &stck){
    outflow << "{";
    for(unsigned i = 0; i < stck.Size(); ++i)
        outflow << stck.content[i] << ", ";
    if(stck.Empty()) outflow << "}" << std::endl;
    else outflow << "\b\b}" << std::endl;
    return outflow;
}
//*****************************************************//
template <typename T, unsigned s>
Stack<T,s>::Stack():top(NO_ELEMENT){  //Costructor
}
//*****************************************************//
template <typename T, unsigned s>
bool Stack<T,s>::Push(T value){
    if(Full()) throw FullStack();
    content[++top] = value;
    return true;
}
//*****************************************************//
template <typename T, unsigned s>
bool Stack<T,s>::Pop(){
    if(Empty()) throw EmptyStack();
    --top;
    return true;
}
//*****************************************************//
template <typename T, unsigned s>
void Stack<T,s>::Clear(){
    top = NO_ELEMENT;
}
//*****************************************************//
template <typename T, unsigned s>
const T& Stack<T,s>::Top()const{
    if(Empty()) throw EmptyStack();
    return content[top];
}
//*****************************************************//
template <typename T, unsigned s>
unsigned Stack<T,s>::Size() const{
    return top+1;
}
//*****************************************************//
template <typename T /* = int*/, unsigned s /* = 10*/>
bool Stack<T,s>::Empty() const{
    return top == NO_ELEMENT;
}
//*****************************************************//
template <typename T, unsigned s>
bool Stack<T,s>::Full() const{
    return top == s

     - 1;
}
//*****************************************************//
template <typename T, unsigned s>
const char* Stack<T,s>::FullStack::what() const throw(){
    return "Full Stack...";
}
//*****************************************************//
template <typename T, unsigned s>
const char* Stack<T,s>::EmptyStack::what() const throw(){
    return "Empty Stack...";
}
//*****************************************************//
template <typename T, unsigned s>
void Stack<T,s>::Print() const{
    std::cout << *this;
}
//*****************************************************//
