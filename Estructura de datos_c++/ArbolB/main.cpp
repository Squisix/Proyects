/*
    \Name: main.cpp
    \Author: Marco Antonio Guerrero Vasquez // 219202704
    \Date: 09/05/21
    \brief: Clase principal donde se manipula un ArbolB
*/
#include <iostream>
#include "ArbolB.h"
#include "Utileria.h"
#include "windows.h"
using namespace std;

unsigned SeleccionOperaciones(unsigned Grado);
void GestionarOperaciones(unsigned seleccion, ArbolB<int,3> &a, ArbolB<int,4> &b,ArbolB<int,5> &c, ArbolB<int,6> &d,ArbolB<int,7> &e ,
                           FormaImpresion &metodo, unsigned &grado);
void ImprimirArbol(ArbolB<int,3> &a, ArbolB<int,4> &b,ArbolB<int,5> &c, ArbolB<int,6> &d,ArbolB<int,7> &e ,FormaImpresion metodo, unsigned grado);

int main()
{

    unsigned grado = 3;
    ArbolB<int,3> A3;
    ArbolB<int,4> A4;
    ArbolB<int,5> A5;
    ArbolB<int,6> A6;
    ArbolB<int,7> A7;
    cout << "Programa para operar ArbolB..." << endl;
    cout << "Tipo de dato del ArbolB: int" << endl;


    unsigned seleccion;
    FormaImpresion metodo = POR_NIVEL;

    do{
        ImprimirArbol(A3,A4,A5,A6,A7,metodo,grado);
        seleccion = SeleccionOperaciones(grado);
        cout << endl;
        GestionarOperaciones(seleccion, A3,A4,A5,A6,A7,metodo,grado);
        system("pause");
        system("cls");


    }while(seleccion != 0);


    return 0;
}

unsigned SeleccionOperaciones(unsigned grado){
    cout << "Grado del ArbolB: " << grado << endl;


    cout << "////////////////////////////////////////////////" << endl;
    cout << "//////////        Operaciones         //////////" << endl;
    cout << "////////////////////////////////////////////////" << endl;

    cout << "Agregar Clave --------------------------------- 1" << endl;
    cout << "Eliminar Clave -----(No Sirve Profe :c )------- 2" << endl;
    cout << "Buscar Clave ---------------------------------- 3" << endl;
    cout << "Vaciar  --------------------------------------- 4" << endl;
    cout << "Cambiar Modo Impresi\242n --------------------- 5" << endl;
    cout << "Cambiar Grado del Arbol B --------------------- 6" << endl;
    cout << "Salir ----------------------------------------- 0" << endl;
    int seleccion;
    do{
        CapturaSegura(seleccion,"Que operaci\242n desea hacer?[0-7]: ");
        if(seleccion < 0 || seleccion > 7) cout << "Selecci\242n fuera de rango..." << endl;
    }while(seleccion < 0 || seleccion > 7);

    return seleccion;
}

void GestionarOperaciones(unsigned seleccion, ArbolB<int,3> &a, ArbolB<int,4> &b,ArbolB<int,5> &c, ArbolB<int,6> &d,ArbolB<int,7> &e ,
                           FormaImpresion &metodo, unsigned &grado){
    if(grado == 3){
          switch(seleccion){
            case 1:{
                int clave;
                cout << "Se agregar\240 una clave..." << endl;
                CapturaSegura(clave, "Ingrese el valor (int): ");
                if(a.BuscarClave(clave)) cout << "Clave repetida en el ArbolB: " << clave << endl;
                else{
                    a.Insertar(clave);

                    cout << "Se agreg\242 la clave: " << clave << endl;
                }
                break;
            }
            case 2:{
                int clave;
                cout << "Se eliminar\240 una clave del Arbol B..." << endl;
                CapturaSegura(clave, "Ingrese el valor (int): ");
                a.EliminarClave(clave);

                break;
            }
            case 3:{
                int clave;
                cout << "Se buscar\240 una clave del Arbol B..." << endl;
                CapturaSegura(clave, "Ingrese el valor (int): ");
                if(a.BuscarClave(clave)) cout << "La clave: " << clave << " Se encuentra en el Arbol B" << endl;
                else  cout << "La clave: " << clave << " NO se encuentra en el Arbol B" << endl;
                break;
            }
            case 4:{
                cout << "Se vaciar\240 el Arbol B..." << endl;
                a.Vaciar();
                break;
            }
            case 5:{
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
                        metodo = POR_NIVEL;
                        break;
                    }
                }

                break;

            }
            case 6:{
                cout << "////////////////////////////////////////////////" << endl;
                cout << "///////        Grado del Arbol B         ///////" << endl;
                cout << "////////////////////////////////////////////////" << endl;


                int seleccion;
                do{
                    CapturaSegura(seleccion,"Grado?[3-7]: ");
                    if(seleccion < 3 || seleccion > 7) cout << "Selecci\242n fuera de rango..." << endl;
                }while(seleccion < 3 || seleccion > 7);
                grado = seleccion;
                break;
            }

        }
    }
    else if(grado == 4){
        switch(seleccion){
            case 1:{
                int clave;
                cout << "Se agregar\240 una clave..." << endl;
                CapturaSegura(clave, "Ingrese el valor (int): ");
                if(b.BuscarClave(clave)) cout << "Clave repetida en el ArbolB: " << clave << endl;
                else{
                    b.Insertar(clave);
                    cout << "Se agreg\242 la clave: " << clave << endl;
                }
                break;
            }
            case 2:{

                int clave;
                cout << "Se eliminar\240 una clave del Arbol B..." << endl;
                CapturaSegura(clave, "Ingrese el valor (int): ");
                b.EliminarClave(clave);

                break;
            }
            case 3:{
                int clave;
                cout << "Se buscar\240 una clave del Arbol B..." << endl;
                CapturaSegura(clave, "Ingrese el valor (int): ");
                if(b.BuscarClave(clave)) cout << "La clave: " << clave << " Se encuentra en el Arbol B" << endl;
                else  cout << "La clave: " << clave << " NO se encuentra en el Arbol B" << endl;
                break;
            }
            case 4:{
                cout << "Se vaciar\240 el Arbol B..." << endl;
                b.Vaciar();
                break;
            }
            case 5:{
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
                        metodo = POR_NIVEL;
                        break;
                    }
                }

                break;

            }
            case 6:{
                cout << "////////////////////////////////////////////////" << endl;
                cout << "///////        Grado del Arbol B         ///////" << endl;
                cout << "////////////////////////////////////////////////" << endl;


                int seleccion;
                do{
                    CapturaSegura(seleccion,"Grado?[3-7]: ");
                    if(seleccion < 3 || seleccion > 7) cout << "Selecci\242n fuera de rango..." << endl;
                }while(seleccion < 3 || seleccion > 7);
                grado = seleccion;
                break;
            }

        }

    }
    else if(grado == 5){
        switch(seleccion){
            case 1:{
                int clave;
                cout << "Se agregar\240 una clave..." << endl;
                CapturaSegura(clave, "Ingrese el valor (int): ");
                if(c.BuscarClave(clave)) cout << "Clave repetida en el ArbolB: " << clave << endl;
                else{
                    c.Insertar(clave);
                    cout << "Se agreg\242 la clave: " << clave << endl;
                }
                break;
            }
            case 2:{

                int clave;
                cout << "Se eliminar\240 una clave del Arbol B..." << endl;
                CapturaSegura(clave, "Ingrese el valor (int): ");
                c.EliminarClave(clave);

                break;
            }
            case 3:{
                int clave;
                cout << "Se buscar\240 una clave del Arbol B..." << endl;
                CapturaSegura(clave, "Ingrese el valor (int): ");
                if(c.BuscarClave(clave)) cout << "La clave: " << clave << " Se encuentra en el Arbol B" << endl;
                else  cout << "La clave: " << clave << " NO se encuentra en el Arbol B" << endl;
                break;
            }
            case 4:{
                cout << "Se vaciar\240 el Arbol B..." << endl;
                c.Vaciar();
                break;
            }
            case 5:{
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
                        metodo = POR_NIVEL;
                        break;
                    }
                }

                break;

            }
            case 6:{
                cout << "////////////////////////////////////////////////" << endl;
                cout << "///////        Grado del Arbol B         ///////" << endl;
                cout << "////////////////////////////////////////////////" << endl;


                int seleccion;
                do{
                    CapturaSegura(seleccion,"Grado?[3-7]: ");
                    if(seleccion < 3 || seleccion > 7) cout << "Selecci\242n fuera de rango..." << endl;
                }while(seleccion < 3 || seleccion > 7);
                grado = seleccion;
                break;
            }

        }
    }
    else if(grado == 6){
        switch(seleccion){
            case 1:{
                int clave;
                cout << "Se agregar\240 una clave..." << endl;
                CapturaSegura(clave, "Ingrese el valor (int): ");
                if(d.BuscarClave(clave)) cout << "Clave repetida en el ArbolB: " << clave << endl;
                else{
                    d.Insertar(clave);
                    cout << "Se agreg\242 la clave: " << clave << endl;
                }
                break;
            }
            case 2:{

                int clave;
                cout << "Se eliminar\240 una clave del Arbol B..." << endl;
                CapturaSegura(clave, "Ingrese el valor (int): ");
                d.EliminarClave(clave);

                break;
            }
            case 3:{
                int clave;
                cout << "Se buscar\240 una clave del Arbol B..." << endl;
                CapturaSegura(clave, "Ingrese el valor (int): ");
                if(d.BuscarClave(clave)) cout << "La clave: " << clave << " Se encuentra en el Arbol B" << endl;
                else  cout << "La clave: " << clave << " NO se encuentra en el Arbol B" << endl;
                break;
            }
            case 4:{
                cout << "Se vaciar\240 el Arbol B..." << endl;
                d.Vaciar();
                break;
            }
            case 5:{
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
                        metodo = POR_NIVEL;
                        break;
                    }
                }

                break;

            }
            case 6:{
                cout << "////////////////////////////////////////////////" << endl;
                cout << "///////        Grado del Arbol B         ///////" << endl;
                cout << "////////////////////////////////////////////////" << endl;


                int seleccion;
                do{
                    CapturaSegura(seleccion,"Grado?[3-7]: ");
                    if(seleccion < 3 || seleccion > 7) cout << "Selecci\242n fuera de rango..." << endl;
                }while(seleccion < 3 || seleccion > 7);
                grado = seleccion;
                break;
            }

        }
    }
    else if(grado == 7){
        switch(seleccion){
            case 1:{
                int clave;
                cout << "Se agregar\240 una clave..." << endl;
                CapturaSegura(clave, "Ingrese el valor (int): ");
                if(e.BuscarClave(clave)) cout << "Clave repetida en el ArbolB: " << clave << endl;
                else{
                    e.Insertar(clave);
                    cout << "Se agreg\242 la clave: " << clave << endl;
                }
                break;
            }
            case 2:{

                int clave;
                cout << "Se eliminar\240 una clave del Arbol B..." << endl;
                CapturaSegura(clave, "Ingrese el valor (int): ");
                e.EliminarClave(clave);

                break;
            }
            case 3:{
                int clave;
                cout << "Se buscar\240 una clave del Arbol B..." << endl;
                CapturaSegura(clave, "Ingrese el valor (int): ");
                if(e.BuscarClave(clave)) cout << "La clave: " << clave << " Se encuentra en el Arbol B" << endl;
                else  cout << "La clave: " << clave << " NO se encuentra en el Arbol B" << endl;
                break;
            }
            case 4:{
                cout << "Se vaciar\240 el Arbol B..." << endl;
                e.Vaciar();
                break;
            }
            case 5:{
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
                        metodo = POR_NIVEL;
                        break;
                    }
                }

                break;

            }
            case 6:{
                cout << "////////////////////////////////////////////////" << endl;
                cout << "///////        Grado del Arbol B         ///////" << endl;
                cout << "////////////////////////////////////////////////" << endl;


                int seleccion;
                do{
                    CapturaSegura(seleccion,"Grado?[3-7]: ");
                    if(seleccion < 3 || seleccion > 7) cout << "Selecci\242n fuera de rango..." << endl;
                }while(seleccion < 3 || seleccion > 7);
                grado = seleccion;
                break;
            }

        }
    }
}

void ImprimirArbol(ArbolB<int,3> &a, ArbolB<int,4> &b,ArbolB<int,5> &c, ArbolB<int,6> &d,ArbolB<int,7> &e ,
                   FormaImpresion metodo, unsigned grado){
    if(grado == 3) {
        a.Imprimir(metodo);
        cout << "\nN\243mero de claves: " << a.ObtenerNumClaves() << endl;
    }else if(grado == 4) {
        b.Imprimir(metodo);
        cout << "\nN\243mero de claves: " << b.ObtenerNumClaves() << endl;
    }else if(grado == 5){
        c.Imprimir(metodo);
        cout << "\nN\243mero de claves: " << c.ObtenerNumClaves() << endl;
    }else if(grado == 6){
        d.Imprimir(metodo);
        cout << "\nN\243mero de claves: " << d.ObtenerNumClaves() << endl;
    }else if(grado == 7){
        e.Imprimir(metodo);
        cout << "\nN\243mero de claves: " << e.ObtenerNumClaves() << endl;
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
        case POR_NIVEL:{
            cout << "POR NIVEL" << endl;
            break;
        }
    }
}
