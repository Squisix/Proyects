/*
    \Name: Reino.cpp
    \Author: Marco Antonio Guerrero Vasquez // 219202704
    \Date: 18/03/21
    \brief: Archivo de implementación de la clase Reino
*/
#include <iostream>
#include <ctime>
#include <iomanip>
#include "Reino.h"
////*****************************************************************************************//
Reino::Reino(unsigned tAtencion /* = 120*/): Ocupado(false), TiempoAtencion(tAtencion){

}
////*****************************************************************************************//
Reino::~Reino(){
}
////*****************************************************************************************//
bool Reino::EstaOcupado() const{
    return Ocupado;
}
////*****************************************************************************************//
void Reino::IngresarACola(){
    Persona p;
    PorAntender.Push(p);
}
////*****************************************************************************************//
void Reino::Atender(const Persona &p){
    Atendiendo = p;
    PorAntender.Pop();
    Ocupado = true;
}
////*****************************************************************************************//
void Reino::Desatender(){
    Atendidos.Push(Atendiendo);
    Ocupado = false;
}
////*****************************************************************************************//
unsigned Reino::ObtenerTiempoAtencion()const{
    return TiempoAtencion;
}
////*****************************************************************************************//
void Reino::GestionarReino(){
    std::srand(time(NULL));
    static int tiempoServicio = 0, tiempoAtencionCiudadana = 5+rand()%11, tiempoTranscurrido = 0, tiempoReyAusente = 1+rand()%15;
    static int tiempoIngresarCola = 3+rand()%9;
    std::cout << "Tiempo: " << tiempoTranscurrido << std::endl;
    ++tiempoTranscurrido;
    ///Rey Ausente
    if(tiempoReyAusente > 0){
        std::cout << std::endl << std::setw(40) << "El Rey Arturo est\240 ausente...";
        --tiempoReyAusente;
    }else{
    ///  ----------------    Rey Ocupado
        if(EstaOcupado() && tiempoAtencionCiudadana > 0){ /* Caja ocupada*/
            std::cout << std::endl << std::setw(40) <<"Rey Arturo est\240 atendiendo a " << Atendiendo;
            std::cout << std::setw(30) << "Tiempo de atenci\242n: " << tiempoServicio;
            ++tiempoServicio;
            --tiempoAtencionCiudadana;
        }else if(EstaOcupado() && tiempoAtencionCiudadana == 0){
            std::cout << std::endl << std::setw(40) <<"Rey Arturo est\240 atendiendo a " << Atendiendo;
            std::cout << std::setw(30) << "Tiempo de atenci\242n: " << tiempoServicio;
            Desatender();
        }else if(!EstaOcupado() && tiempoAtencionCiudadana == 0) { /* Caja desocupada */
            tiempoServicio = 0;
            tiempoAtencionCiudadana = 5+rand()%11;
            std::cout << std::endl << std::setw(40) <<"Rey Arturo est\240 desocupado...";
        }else if(!EstaOcupado() && tiempoAtencionCiudadana > 0){
            std::cout << std::endl << std::setw(40) <<"Rey Arturo est\240 desocupado...";
            if(!PorAntender.Empty()){
                Atender(PorAntender.GetFirst());
            }
        }
    }

    std::cout << std::endl << std::endl << "En espera:" << std::endl;
    ImprimirPorAtender();

    if(tiempoIngresarCola > 1) --tiempoIngresarCola;
    else{
        tiempoIngresarCola = 3+rand()%9;
        IngresarACola();
    }
    --TiempoAtencion;


}
////*****************************************************************************************//
void Reino::ImprimirAtendidos()const{
    if(!Atendidos.Empty()){
        Atendidos.Print();
    }
}
////*****************************************************************************************//
void Reino::ImprimirPorAtender()const{
    if(!PorAntender.Empty()){
        PorAntender.Print();
    }

}
////*****************************************************************************************//
Persona Reino::SeEstaAtendiendo() const{
    return Atendiendo;
}
////*****************************************************************************************//
////*****************************************************************************************//

void Reino::ImprimirNumeroCiudadanosAtendidos() const{
    std::cout << "\n\nEl Rey Arturo atendi\242 a " << Atendidos.NoblesSize() << " Nobles." << std::endl;
    std::cout << "\nEl Rey Arturo atendi\242 a " << Atendidos.PlebeyosSize() << " Plebeyos." << std::endl;
    std::cout << "\nEl Rey Arturo atendi\242 a " << Atendidos.Size() << " Ciudadanos." << std::endl;
}
