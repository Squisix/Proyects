/*
    \Name: main.cpp
    \Author: Marco Antonio Guerrero Vasquez // 219202704
    \Date: 18/03/21
    \brief: Programa que simula el proceso de un reino para atender personas en una cola
*/
#include <iostream>
#include "Reino.h"
#include <windows.h>
#include "Utileria.h"

using namespace std;

int main()
{
    char eleccion;
    int tiempo = 120;
    cout << "Se generar\240 la simulaci\242n de un Reino..." << endl;
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
    Reino MonarquiaEspanola(tiempo);

    while(MonarquiaEspanola.ObtenerTiempoAtencion() > 0){
        MonarquiaEspanola.GestionarReino();
        Sleep(1000);
        system("cls");
    }

    if(MonarquiaEspanola.EstaOcupado()){
        cout << "El Rey Arturo terminar\240 de atender a " << MonarquiaEspanola.SeEstaAtendiendo() << " y cerrar\240" << endl;
        MonarquiaEspanola.Desatender();
    }
    cout << "Se atendieron a todos los ciudadanos por hoy..." << endl << endl;

    cout << "\n\nLos siguientes ciudadanos ser\240n atendidos ma\244ana:" << endl;
    MonarquiaEspanola.ImprimirPorAtender();

    cout << "\n\nSe atendieron a los siguientes Ciudadanos en el respectivo orden:" << endl;
    MonarquiaEspanola.ImprimirAtendidos();

    MonarquiaEspanola.ImprimirNumeroCiudadanosAtendidos();

    return 0;
}
