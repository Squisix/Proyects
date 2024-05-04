/*
    \Name: main.cpp
    \Author: Marco Antonio Guerrero Vasquez // 219202704
    \Date: 14/04/21
    \brief: Clase principal donde se manipula un ABB
*/
#include <iostream>
#include "ABB.h"
#include "Utileria.h"
#include "windows.h"
using namespace std;

unsigned SeleccionOperaciones(unsigned tipoDeDato);
void GestionarOperaciones(unsigned seleccion, ABB<char> &a, ABB<int> &a2, MetodoImpresion &metodo, unsigned &tipoDeDato);
void ImprimirArbol(ABB<char> &a, ABB<int> &b, MetodoImpresion metodo, unsigned tipoDeDato);

int main()
{
    unsigned tipoDeDato = 0;
    ABB<char> A1;
    ABB<int> A2;
    cout << "Programa para operar ABB's..." << endl;
    cout << "Tipo de dato del ABB: Char" << endl;


    unsigned seleccion;
    MetodoImpresion metodo = ASCENDENTE;

    do{
        ImprimirArbol(A1,A2,metodo,tipoDeDato);
        seleccion = SeleccionOperaciones(tipoDeDato);
        cout << endl;
        GestionarOperaciones(seleccion, A1,A2, metodo,tipoDeDato);
        system("pause");
        system("cls");


    }while(seleccion != 0);


    return 0;
}

unsigned SeleccionOperaciones(unsigned tipoDeDato){
    cout << "Tipo de dato de ABB: ";
    if(tipoDeDato == 0) cout << "Char" << endl;
    else if(tipoDeDato == 1) cout << "Int" << endl;

    cout << "////////////////////////////////////////////////" << endl;
    cout << "//////////        Operaciones         //////////" << endl;
    cout << "////////////////////////////////////////////////" << endl;

    cout << "Agregar Valor --------------------------------- 1" << endl;
    cout << "Eliminar Valor -------------------------------- 2" << endl;
    cout << "Podar  ---------------------------------------- 3" << endl;
    cout << "Buscar Valor ---------------------------------- 4" << endl;
    cout << "Vaciar  --------------------------------------- 5" << endl;
    cout << "Cambiar Modo Impresi\242n --------------------- 6" << endl;
    cout << "Cambiar Tipo de Dato -------------------------- 7" << endl;
    cout << "Salir ----------------------------------------- 0" << endl;
    int seleccion;
    do{
        CapturaSegura(seleccion,"Que operaci\242n desea hacer?[0-7]: ");
        if(seleccion < 0 || seleccion > 7) cout << "Selecci\242n fuera de rango..." << endl;
    }while(seleccion < 0 || seleccion > 7);

    return seleccion;
}

void GestionarOperaciones(unsigned seleccion, ABB<char> &a, ABB<int> &a2, MetodoImpresion &metodo, unsigned &tipoDeDato){

    if(tipoDeDato == 0){
          switch(seleccion){
            case 1:{
                char id;
                cout << "Se agregar\240 un nodo..." << endl;
                CapturaSegura(id, "Ingrese el valor (char): ");
                if(a.Agregar(id)) cout << "Se agreg\242 el valor: " << id << endl;
                else  cout << "No se agreg\242 el valor: " << id << endl;
                break;
            }
            case 2:{
                char id;
                cout << "Se eliminar\240 un valor del ABB..." << endl;
                CapturaSegura(id, "Ingrese el valor (char): ");
                if(a.Eliminar(id)) cout << "Se elimin\242 el valor: " << id << endl;
                else  cout << "No se elimin\242 el valor: " << id << endl;
                break;
            }
            case 3:{
                char id;
                cout << "Se Podar\240 el ABB..." << endl;
                CapturaSegura(id, "Ingrese la subraiz donde se podar\240 (char): ");
                if(a.Podar(id)) cout << "Se pod\242 el ABB a partir de: " << id << endl;
                else  cout << "No se pod\242 el ABB... " << endl;
                break;
            }
            case 4:{
                char id;
                cout << "Se buscar\240 un valor del ABB..." << endl;
                CapturaSegura(id, "Ingrese el valor (char): ");
                if(a.Buscar(id)) cout << "El valor: " << id << " Se encuentra en el ABB" << endl;
                else  cout << "El valor: " << id << " NO se encuentra en el ABB" << endl;
                break;
            }
            case 5:{
                cout << "Se vaciar\240 el ABB..." << endl;
                a.Vaciar();
                break;
            }
            case 6:{
                cout << "////////////////////////////////////////////////" << endl;
                cout << "//////////     Metodos Impresion      //////////" << endl;
                cout << "////////////////////////////////////////////////" << endl;

                cout << "Ascendente --------------------------------- 0" << endl;
                cout << "Descendente -------------------------------- 1" << endl;
                cout << "Por Niveles  ------------------------------- 2" << endl;
                int seleccion;
                do{
                    CapturaSegura(seleccion,"Que metodo prefiere?[0-2]: ");
                    if(seleccion < 0 || seleccion > 2) cout << "Selecci\242n fuera de rango..." << endl;
                }while(seleccion < 0 || seleccion > 2);

                cout << "Metodo de impresi\242n: ";
                switch(seleccion){
                    case 0:{
                        cout << "ASCENDENTE" << endl;
                        metodo = ASCENDENTE;
                        break;
                    }
                    case 1:{
                        cout << "DESCENDENTE" << endl;
                        metodo = DESCENDENTE;
                        break;
                    }
                    case 2:{
                        cout << "POR NIVEL" << endl;
                        metodo = NIVELES;
                        break;
                    }
                }

                break;

            }
            case 7:{
                cout << "////////////////////////////////////////////////" << endl;
                cout << "//////////        Tipo de Dato        //////////" << endl;
                cout << "////////////////////////////////////////////////" << endl;

                cout << "Char --------------------------------- 0" << endl;
                cout << "Int ---------------------------------- 1" << endl;
                int seleccion;
                do{
                    CapturaSegura(seleccion,"Tipo de dato?[0-1]: ");
                    if(seleccion < 0 || seleccion > 1) cout << "Selecci\242n fuera de rango..." << endl;
                }while(seleccion < 0 || seleccion > 1);
                tipoDeDato = seleccion;
                break;
            }
        }
    }
    else if(tipoDeDato == 1){
        switch(seleccion){
            case 1:{
                int id;
                cout << "Se agregar\240 un nodo..." << endl;
                CapturaSegura(id, "Ingrese el valor (int): ");
                if(a2.Agregar(id)) cout << "Se agreg\242 el valor: " << id << endl;
                else  cout << "No se agreg\242 el valor: " << id << endl;
                break;
            }
            case 2:{
                char id;
                cout << "Se eliminar\240 un valor del ABB..." << endl;
                CapturaSegura(id, "Ingrese el valor (int): ");
                if(a2.Eliminar(id)) cout << "Se elimin\242 el valor: " << id << endl;
                else  cout << "No se elimin\242 el valor: " << id << endl;
                break;
            }
            case 3:{
                char id;
                cout << "Se Podar\240 el ABB..." << endl;
                CapturaSegura(id, "Ingrese la subraiz donde se podar\240 (int): ");
                if(a2.Podar(id)) cout << "Se pod\242 el ABB a partir de: " << id << endl;
                else  cout << "No se pod\242 el ABB... " << endl;
                break;
            }
            case 4:{
                char id;
                cout << "Se buscar\240 un valor del ABB..." << endl;
                CapturaSegura(id, "Ingrese el valor (int): ");
                if(a2.Buscar(id)) cout << "El valor: " << id << " Se encuentra en el ABB" << endl;
                else  cout << "El valor: " << id << " NO se encuentra en el ABB" << endl;
                break;
            }
            case 5:{
                cout << "Se vaciar\240 el ABB..." << endl;
                a.Vaciar();
                break;
            }
            case 6:{
                cout << "////////////////////////////////////////////////" << endl;
                cout << "//////////     Metodos Impresion      //////////" << endl;
                cout << "////////////////////////////////////////////////" << endl;

                cout << "Ascendente --------------------------------- 0" << endl;
                cout << "Descendente -------------------------------- 1" << endl;
                cout << "Por Niveles  ------------------------------- 2" << endl;
                int seleccion;
                do{
                    CapturaSegura(seleccion,"Que metodo prefiere?[0-2]: ");
                    if(seleccion < 0 || seleccion > 2) cout << "Selecci\242n fuera de rango..." << endl;
                }while(seleccion < 0 || seleccion > 2);

                cout << "Metodo de impresi\242n: ";
                switch(seleccion){
                    case 0:{
                        cout << "ASCENDENTE" << endl;
                        metodo = ASCENDENTE;
                        break;
                    }
                    case 1:{
                        cout << "DESCENDENTE" << endl;
                        metodo = DESCENDENTE;
                        break;
                    }
                    case 2:{
                        cout << "POR NIVEL" << endl;
                        metodo = NIVELES;
                        break;
                    }
                }

                break;

            }

                case 7:{
                    cout << "////////////////////////////////////////////////" << endl;
                    cout << "//////////        Tipo de Dato        //////////" << endl;
                    cout << "////////////////////////////////////////////////" << endl;

                    cout << "Char --------------------------------- 0" << endl;
                    cout << "Int ---------------------------------- 1" << endl;
                    int seleccion;
                    do{
                        CapturaSegura(seleccion,"Tipo de dato?[0-1]: ");
                        if(seleccion < 0 || seleccion > 1) cout << "Selecci\242n fuera de rango..." << endl;
                    }while(seleccion < 0 || seleccion > 1);
                    tipoDeDato = seleccion;
                    break;
                }

        }
    }

}

void ImprimirArbol(ABB<char> &a, ABB<int> &b, MetodoImpresion metodo, unsigned tipoDeDato){
    if(tipoDeDato == 0) {
        a.Imprimir(metodo);
        cout << "\nN\243mero de nodos: " << a.ObtenerNumNodos() << endl;
    }else if(tipoDeDato == 1) {
        b.Imprimir(metodo);
        cout << "\nN\243mero de nodos: " << b.ObtenerNumNodos() << endl;
    }

    cout << "Metodo de impresi\242n: ";
    switch(metodo){
        case ASCENDENTE:{
            cout << "ASCENDENTE" << endl;
            break;
        }
        case DESCENDENTE:{
            cout << "DESCENDENTE" << endl;
            break;
        }
        case NIVELES:{
            cout << "POR NIVEL" << endl;
            break;
        }
    }
}
