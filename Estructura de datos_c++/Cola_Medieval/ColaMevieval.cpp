/*
    \Name: ColaMedieval.cpp
    \Author: Marco Antonio Guerrero Vasquez // 219202704
    \Date: 18/03/21
    \brief: Archivo de cabecera donde se encuentra la clase Cola Medieval
*/
#include "ColaMedieval.h"
//*****************************************************//
ColaMedieval::ColaMedieval(){ //Costructor
}
//*****************************************************//
ColaMedieval::ColaMedieval(const ColaMedieval &cm){  //Costructor
    *this = cm;
}
//*****************************************************//
ColaMedieval::~ColaMedieval(){  //Destructor
}
//*****************************************************//
ColaMedieval& ColaMedieval::operator=(const ColaMedieval &cm){  //Costructor
    if(this == &cm) return *this;
    Nobles = cm.Nobles;
    Plebeyos = cm.Plebeyos;
    return *this;
}

//*****************************************************//
void ColaMedieval::Push(const Persona& p){
    if(!p.ObtenerEsPlebeyo()){
        Nobles.Push(p);
    }else{
        Plebeyos.Push(p);
    }
}
//*****************************************************//
void ColaMedieval::Pop(){
    if(!Nobles.Empty()){
        Nobles.Pop();
    }else{
        Plebeyos.Pop();
    }

}
//*****************************************************//
void ColaMedieval::Clear(){
    while(!Nobles.Empty()) Nobles.Pop();
    while(!Plebeyos.Empty()) Plebeyos.Pop();
}
//*****************************************************//
const Persona& ColaMedieval::GetLast()const{
    if(Empty()) throw EmptyQueue();

    if(Plebeyos.Empty()) return Nobles.GetLast();
    else return Plebeyos.GetLast();
}
//*****************************************************//
const Persona& ColaMedieval::GetFirst() const{
    if(Empty()) throw EmptyQueue();

    if(!Nobles.Empty()) return Nobles.GetFirst();
    else return Plebeyos.GetFirst();
}
//*****************************************************//
unsigned ColaMedieval::PlebeyosSize() const{
    return Plebeyos.Size();
}
//*****************************************************//
unsigned ColaMedieval::NoblesSize() const{
    return Nobles.Size();
}
//*****************************************************//
unsigned ColaMedieval::Size() const{
    return Nobles.Size() + Plebeyos.Size();
}
//*****************************************************//
bool ColaMedieval::Empty() const{
    return (Plebeyos.Empty() && Nobles.Empty());
}
//*****************************************************//
const char* ColaMedieval::EmptyQueue::what() const throw(){
    return "Cola Medieval Vacia...";
}
//*****************************************************//
void ColaMedieval::Print() const{
    Nobles.Print();
    Plebeyos.Print();
}
//*****************************************************//

