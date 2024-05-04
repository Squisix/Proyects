/*
    \Name: Heap.h
    \Author: Marco Antonio Guerrero Vasquez // 219202704
    \Date: 04/27/21
    \brief: Header file where the functions and operators of the Heap class are declared
*/


#include <iostream>
#include "Heap.h"
#include "Utileria.h"
#include "windows.h"
using namespace std;

unsigned SeleccionOperaciones(unsigned tipoDeMonticulo);
void GestionarOperaciones(unsigned seleccion, Heap<int,minimum> &a, Heap<int,maximum> &b, unsigned &tipoDeMonticulo);
void ImprimirArbol(Heap<int,minimum> &a, Heap<int,maximum> &b, unsigned tipoDeMonticulo);

int main()
{
    try{
        unsigned tipoDeMonticulo = 0;
        Heap<int,minimum> A1;
        Heap<int,maximum> A2;
        cout << "Programa para operar Monticulos Minimos y Maximos..." << endl;


        unsigned seleccion;


        do{
            ImprimirArbol(A1,A2,tipoDeMonticulo);
            seleccion = SeleccionOperaciones(tipoDeMonticulo);
            cout << endl;
            GestionarOperaciones(seleccion, A1,A2,tipoDeMonticulo);
            system("pause");
            system("cls");


        }while(seleccion != 0);

    }catch (std::exception &exc){
        std::cerr << exc.what() << std::endl;
    }catch (...){
        std::cerr << "An unexpected error has ocurred..." << std::endl;
    }
    return 0;
}

unsigned SeleccionOperaciones(unsigned tipoDeMonticulo){
    int seleccion = 0;
    try{
        cout << "Tipo de dato del monticulo: Int" << endl;
        cout << "Tipo de monticulo: ";
        if(tipoDeMonticulo == 0) cout << "Minimo" << endl;
        else cout << "Maximo" << endl;


        cout << "////////////////////////////////////////////////" << endl;
        cout << "//////////        Operaciones         //////////" << endl;
        cout << "////////////////////////////////////////////////" << endl;

        cout << "Agregar Valor --------------------------------- 1" << endl;
        cout << "Eliminar Valor -------------------------------- 2" << endl;
        cout << "Vaciar  --------------------------------------- 3" << endl;
        cout << "Cambiar Tipo de Monticulo --------------------- 4" << endl;
        cout << "Salir ----------------------------------------- 0" << endl;

        do{
            CapturaSegura(seleccion,"Que operaci\242n desea hacer?[0-4]: ");
            if(seleccion < 0 || seleccion > 4) cout << "Selecci\242n fuera de rango..." << endl;
        }while(seleccion < 0 || seleccion > 4);
    }catch (std::exception &exc){
        std::cerr << exc.what() << std::endl;
    }catch (...){
        std::cerr << "An unexpected error has ocurred..." << std::endl;
    }
    return seleccion;
}

void GestionarOperaciones(unsigned seleccion, Heap<int,minimum> &a, Heap<int,maximum> &b, unsigned &tipoDeMonticulo){
    try{
        if(tipoDeMonticulo == 0){
              switch(seleccion){
                case 1:{
                    int val;
                    cout << "Se agregar\240 un dato al monticulo minimo..." << endl;
                    CapturaSegura(val, "Ingrese el valor (int): ");
                    a.Push(val);
                    cout << "Se agreg\242 el valor: " << val << endl;
                    break;
                }
                case 2:{
                    cout << "Se eliminar\240 el valor: " << a.Root() << " del monticulo minimo..." << endl;
                    a.Pop();
                    break;
                }
                case 3:{
                    cout << "Se Vaciar\240 el Monticulo minimo..." << endl;
                    a.Clear();
                    break;
                }
                case 4:{
                    cout << "////////////////////////////////////////////////" << endl;
                    cout << "//////////     Tipo de Monticulo      //////////" << endl;
                    cout << "////////////////////////////////////////////////" << endl;

                    cout << "Minimo --------------------------------- 0" << endl;
                    cout << "Maximo --------------------------------- 1" << endl;
                    int seleccion;
                    do{
                        CapturaSegura(seleccion,"Que tipo prefiere?[0-1]: ");
                        if(seleccion < 0 || seleccion > 1) cout << "Selecci\242n fuera de rango..." << endl;
                    }while(seleccion < 0 || seleccion > 1);

                    cout << "Tipo de Monticulo: ";
                    if(seleccion == 0) cout << "Minimo" << endl;
                    else cout << "Maximo" << endl;

                    break;
                }



            }
        }
        else if(tipoDeMonticulo == 1){
            switch(seleccion){
                case 1:{
                    int val;
                    cout << "Se agregar\240 un dato al monticulo maximo..." << endl;
                    CapturaSegura(val, "Ingrese el valor (int): ");
                    b.Push(val);
                    cout << "Se agreg\242 el valor: " << val << endl;
                    break;
                }
                case 2:{
                    cout << "Se eliminar\240 el valor: " << b.Root() << " del monticulo maximo..." << endl;
                    b.Pop();
                    break;
                }
                case 3:{
                    cout << "Se Vaciar\240 el Monticulo maximo..." << endl;
                    b.Clear();
                    break;
                }
                case 4:{
                    cout << "////////////////////////////////////////////////" << endl;
                    cout << "//////////     Tipo de Monticulo      //////////" << endl;
                    cout << "////////////////////////////////////////////////" << endl;

                    cout << "Minimo --------------------------------- 0" << endl;
                    cout << "Maximo --------------------------------- 1" << endl;
                    int seleccion;
                    do{
                        CapturaSegura(seleccion,"Que tipo prefiere?[0-1]: ");
                        if(seleccion < 0 || seleccion > 1) cout << "Selecci\242n fuera de rango..." << endl;
                    }while(seleccion < 0 || seleccion > 1);

                    cout << "Tipo de Monticulo: ";
                    if(seleccion == 0) cout << "Minimo" << endl;
                    else cout << "Maximo" << endl;

                    break;
                }



            }
        }
    }catch (std::exception &exc){
        std::cerr << exc.what() << std::endl;
    }catch (...){
        std::cerr << "An unexpected error has ocurred..." << std::endl;
    }

}

void ImprimirArbol(Heap<int,minimum> &a, Heap<int,maximum> &b, unsigned tipoDeMonticulo){
    try{
        if(tipoDeMonticulo == 0) {
            a.Print();
            cout << "\nN\243mero de elementos: " << a.Size() << endl;
            cout << "\nN\243mero minimo: " << a.Root() << endl;
        }else if(tipoDeMonticulo == 1) {
            b.Print();
            cout << "\nN\243mero de elementos: " << b.Size() << endl;
            cout << "\nN243mero maximo: " << b.Root() << endl;
        }
    }catch (std::exception &exc){
        std::cerr << exc.what() << std::endl;
    }catch (...){
        std::cerr << "An unexpected error has ocurred..." << std::endl;
    }


}



