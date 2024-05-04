#include "Stack.h"
#include <iostream>

Stack::Stack():top(-1){  //Costructor
}
//*****************************************************//
bool Stack::Push(double value){
    if(Full()) throw FullStack();
    content[++top] = value;
    return true;
}
//*****************************************************//
bool Stack::Pop(){
    if(Empty()) throw EmptyStack();
    --top;
    return true;
}
//*****************************************************//
void Stack::Clear(){
    top = NO_ELEMENT;
}
//*****************************************************//
double Stack::Top()const{
    if(Empty()) throw EmptyStack();
    return content[top];
}
//*****************************************************//
int Stack::Size() const{
    return top+1;
}
//*****************************************************//
bool Stack::Empty() const{
    return top == NO_ELEMENT;
}
//*****************************************************//
bool Stack::Full() const{
    return top == SIZE - 1;
}
//*****************************************************//
void Stack::Print() const{
    std::cout << "{";
    for(int i = 0; i <= top; ++i)
        std::cout << content[i] << ", ";
    if(Empty()) std::cout << "}" << std::endl;
    else std::cout << "\b\b}" << std::endl;
}
//*****************************************************//

const char* Stack::FullStack::what() const throw(){
    return "Full Stack, impossible to add new items...";
}

const char* Stack::EmptyStack::what() const throw(){
    return "Empty Stack, impossible to remove items...";
}
