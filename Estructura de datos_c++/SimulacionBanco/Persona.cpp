/*
    \Name: Persona.cpp
    \Author: Marco Antonio Guerrero Vasquez // 219202704
    \Date: 03/06/21
    \brief: Archivo de implementación de la clase Persona
*/
#include <iostream>
#include <ctime>
#include "Persona.h"
////*****************************************************************************************//

std::ostream& operator<< (std::ostream &fSalida, const Persona &p){
    fSalida << p.ObtenerNombre() << " " << p.ObtenerApellido();
    return fSalida;
}
////*****************************************************************************************//

Persona::Persona(){
    std::srand(time(NULL));

    int aleatorio;
    static char Nombres[][25] = {"Marco","Antonio","Lenika","Janeth","Margarita","Guadalupe","Sebasti\240n","Jes\243s", "Mart\241n",
                                    "Karim","Alan","\263ngel","Erika","Nayeli","Oscar","Ram\242n","Rom\240n","Emiliano","Karen",
                                    "Andrea","Celina","Gustavo","Benjam\241n","HERIBERTO","Malcom","Rodrigo","Santiago","Armando",
                                    "Giovanni","Carolina","Roc\241o","Leijla","Nadia","Alma","Jorge","Pedro","J\243an","Dulce",
                                    "Concepci\242n", "\326rene","\326talo","German","Rosa","Flor","Adrian","Ariel","Abraham","Lu\241s",
                                    "Daniela","Daniel"};

    static char Apellidos[][25] = {"Guarista","Lozano","Guerrero","Vasquez","Mireles","Garc\241a","Encinas","Hermosillo","Ur\241as",
                                    "P\240ramo","Meztyanek","Villalba","Ces\241n","Romero","Aguilar","Valenzuela","Valencia","Rodr\241guez",
                                    "Navarrete","Corrales","Rosas","Gonz\240lez","Vazquez","G\242mez","Fern\240ndez","Escobar","Nevarez",
                                    "L\242pez","D\241az","P\202rez","Aello","S\240nchez","Sosa","Torres","P\241neda","Ruiz","Benitez",
                                    "Acosta","Medina","Carre\242n","Herrera","Aguirre","Gim\202nez","Guti\202rrez","Pereyra","Molina",
                                    "Quintanar","Ort\241z","Nu\244ez","Morales"};


    aleatorio = rand()%50;
    Nombre = Nombres[aleatorio];

    aleatorio = rand()%50;
    Apellido = Apellidos[aleatorio];

}
////*****************************************************************************************//

Persona::~Persona(){
}
////*****************************************************************************************//

Persona& Persona::operator=(const Persona &p){
    if(this == &p) return *this;
    Nombre = p.Nombre;
    Apellido = p.Apellido;
    return *this;
}
////*****************************************************************************************//

char* Persona::ObtenerNombre() const{
    return Nombre;
}
////*****************************************************************************************//

char* Persona::ObtenerApellido() const{
    return Apellido;
}
////*****************************************************************************************//
