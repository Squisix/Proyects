/*
    \Name: main.cpp
    \Author: Marco Antonio Guerrero Vasquez // 219202704
    \Date: 05/05/21
    \brief: Programa que hace un paseo de Euler con el algoritmo de Fleury
*/
#include <iostream>
#include "Grafica.h"
#include "Utileria.h"
#include "windows.h"
#include <fstream>
using namespace std;

void GestionarOperaciones(unsigned seleccion, Grafica<char> &g);
void ImprimirGrafica(Grafica<char> &g);

int main()
{
    Grafica<char> G1;
    cout << "Programa que hace un paseo de Euler con el algoritmo de Fleury..." << endl;
    cout << "Tipo de dato de grafica: char" << endl;

    int seleccion;

    do{
        ImprimirGrafica(G1);
        cout << "Algoritmo de Fleury -------------------------- 1" << endl;
        cout << "Salir ---------------------------------------- 0" << endl;
        do{
            CapturaSegura(seleccion,"Que operaci\242n desea hacer?[0-1]: ");
            if(seleccion < 0 || seleccion > 1) cout << "Selecci\242n fuera de rango..." << endl;
        }while(seleccion < 0 || seleccion > 1);
        cout << endl;
        if(seleccion == 1){
            cout << "Algoritmo de Fleury..." << endl;
            cout << "Se recorrer\240 la grafica a partir de un nodo..." << endl;
            char id;
            CapturaSegura(id, "Ingrese el Id del nodo (char): ");
            cout << endl;
            G1.AlgoritmoFleury(id);
        }
        system("pause");
        system("cls");


    }while(seleccion != 0);


    return 0;
}


void ImprimirGrafica(Grafica<char> &g){
    char caracter1, caracter2;

    ifstream grafica("GraficaTest.txt");
    if (!grafica) {
        cout << "Error: La grafica no pudo ser leida... " << endl;
        system("pause");
        grafica.close();
        return;
    }

    grafica >> caracter1;
    while(caracter1 != '*'){
        g.Agregar(caracter1);
        grafica >> caracter1;
    }

    grafica >> caracter1;
    grafica >> caracter2;
    while(caracter1 != '*' && caracter2 != '*'){
        g.Agregar(caracter1,caracter2);
        grafica >> caracter1;
        grafica >> caracter2;
    }
    grafica.close();
    g.Imprimir();
    cout << "\nN\243mero de nodos: " << g.ObtenerNumNodos() << endl;
    cout << "N\243mero de aristas: " << g.ObtenerNumAristas() << endl;
}
