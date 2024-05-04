/*
    \Name: Banco.cpp
    \Author: Marco Antonio Guerrero Vasquez // 219202704
    \Date: 03/06/21
    \brief: Archivo de implementación de la clase Banco
*/
#include <iostream>
#include <ctime>
#include <iomanip>
#include "Banco.h"
////*****************************************************************************************//
Banco::Banco(unsigned tAtencion /* = 120*/): EnUso(false), TiempoAtencion(tAtencion){

}
////*****************************************************************************************//
Banco::~Banco(){
}
////*****************************************************************************************//
bool Banco::EstaEnUso() const{
    return EnUso;
}
////*****************************************************************************************//
void Banco::IngresarACola(){
    Persona p;
    PorAntender.Push(p);
}
////*****************************************************************************************//
void Banco::Atender(const Persona &p){
    Atendiendo = p;
    PorAntender.Pop();
    EnUso = true;
}
////*****************************************************************************************//
void Banco::Desatender(){
    Atendidos.Push(Atendiendo);
    EnUso = false;
}
////*****************************************************************************************//
unsigned Banco::ObtenerTiempoAtencion()const{
    return TiempoAtencion;
}
////*****************************************************************************************//
void Banco::GestionarBanco(){
    std::srand(time(NULL));
    static int tiempoServicio = 0, tiempoTransaccion = 5+rand()%21, tiempoTranscurrido = 0, tiempoCajaCerrada = 1+rand()%15;
    static int tiempoIngresarCola = 2+rand()%9;
    std::cout << "Tiempo: " << tiempoTranscurrido << std::endl;
    ++tiempoTranscurrido;
    ///Caja cerrada
    if(tiempoCajaCerrada > 0){
        std::cout << std::endl << std::setw(40) << "Banco Azteca est\240 cerrado...";
        --tiempoCajaCerrada;
    }else{
    ///  ----------------    Caja abierta
        if(EstaEnUso() && tiempoTransaccion > 0){ /* Caja ocupada*/
            std::cout << std::endl << std::setw(40) <<"Banco Azteca est\240 atendiendo a " << Atendiendo;
            std::cout << std::setw(30) << "Tiempo de atenci\242n: " << tiempoServicio;
            ++tiempoServicio;
            --tiempoTransaccion;
        }else if(EstaEnUso() && tiempoTransaccion == 0){
            std::cout << std::endl << std::setw(40) <<"Banco Azteca est\240 atendiendo a " << Atendiendo;
            std::cout << std::setw(30) << "Tiempo de atenci\242n: " << tiempoServicio;
            Desatender();
        }else if(!EstaEnUso() && tiempoTransaccion == 0) { /* Caja desocupada */
            tiempoServicio = 0;
            tiempoTransaccion = 5+rand()%21;
            std::cout << std::endl << std::setw(40) <<"Banco Azteca est\240 desocupado...";
        }else if(!EstaEnUso() && tiempoTransaccion > 0){
            std::cout << std::endl << std::setw(40) <<"Banco Azteca est\240 desocupado...";
            if(!PorAntender.Empty()){
                Atender(PorAntender.GetFirst());
            }
        }
    }

    std::cout << std::endl << std::endl << "En espera:" << std::endl;
    ImprimirPorAtender();

    if(tiempoIngresarCola > 1) --tiempoIngresarCola;
    else{
        tiempoIngresarCola = 2+rand()%9;
        IngresarACola();
    }
    --TiempoAtencion;


}
////*****************************************************************************************//
void Banco::ImprimirAtendidos()const{
    if(!Atendidos.Empty()){
    std::cout << Atendidos;
    }
}
////*****************************************************************************************//
void Banco::ImprimirPorAtender()const{
    if(!PorAntender.Empty()){
        std::cout << PorAntender;
    }

}
////*****************************************************************************************//
Persona Banco::SeEstaAtendiendo() const{
    return Atendiendo;
}
////*****************************************************************************************//
