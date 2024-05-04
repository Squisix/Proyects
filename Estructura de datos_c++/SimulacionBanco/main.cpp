/*
    \Name: main.cpp
    \Author: Marco Antonio Guerrero Vasquez // 219202704
    \Date: 03/06/21
    \brief: Programa que simula el proceso de un banco para atender personas en una cola
*/
#include <iostream>
#include "Banco.h"
#include <windows.h>
#include "Utileria.h"

using namespace std;

int main()
{
    char eleccion;
    int tiempo = 120;
    cout << "Se generar\240 la simulaci\242n de un banco..." << endl;
    cout << "El tiempo se refiere a minutos transcurridos (Equivalente a segundos en la vida real)" << endl;
    cout << "El tiempo de la simulaci\240n es por defecto de 120" << endl;
    do{
        CapturaSegura(eleccion,"Desea cambiar el tiempo de ejecuci\242n de la simulaci\242? (S/N): ");
        if((eleccion != 'S') && (eleccion != 's') && (eleccion != 'N') && (eleccion != 'n')){
            cout << "\nEleccion equivocada..." << endl;
        }


    }while((eleccion != 'S') && (eleccion != 's') && (eleccion != 'N') && (eleccion != 'n'));

    if(eleccion == 'S'||eleccion =='s'){
        do{
            CapturaSegura(tiempo,"Ingrese el tiempo de la simulaci\242n (t > 0): ");
            if(tiempo < 0) cout << "\nError: El tiempo no puede ser negativo..." << endl;
            else break;
        }while(tiempo < 0);
    }

    system("cls");
    Banco BancoAzteca(tiempo);

    while(BancoAzteca.ObtenerTiempoAtencion() > 0){
        BancoAzteca.GestionarBanco();
        Sleep(1000);
        system("cls");
    }

    if(BancoAzteca.EstaEnUso()){
        cout << "Banco Azteca terminar\240 de atender a " << BancoAzteca.SeEstaAtendiendo() << " y cerrar\240" << endl;
        BancoAzteca.Desatender();
    }
    cout << "Se atendieron a todos los clientes por hoy..." << endl << endl;

    cout << "\n\nLos siguientes clientes ser\240n atendidos ma\244ana:" << endl;
    BancoAzteca.ImprimirPorAtender();

    cout << "\n\nSe atendieron a los siguientes clientes en el respectivo orden:" << endl;
    BancoAzteca.ImprimirAtendidos();

    return 0;
}
