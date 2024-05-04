/*
    \Name: main.cpp
    \Author: Marco Antonio Guerrero Vasquez // 219202704
    \Date: 03/26/21
    \brief: Main class where DoubleCircularList of different types are tested
*/
#include <iostream>
#include <ctime>
#include <string>
#include "DoubleCircularList.h"
#include "Persona.h"
#include "Utileria.h"
#include <windows.h>

#define SIZE 20


int main()
{
    try{
        srand(time(NULL));
        double valor;
        int random = 2 + rand()%SIZE;
        DoubleCircularList<double> lista;

        std::cout << "Tipo de dato: Double" << std::endl;
        std::cout << "Se agregar\240n valores aleatorios a una lista circular doble..." << std::endl;
        std::cout << "Cantidad de elemetos a agregar: " << random << std::endl;
        for(int i = 0; i < random; ++i){
            valor = -5+rand()%11;
            std::cout << "Entra: " << valor << std::endl;
            lista.Push(valor);
            lista.Print();
        }
        std::cout << "\n\"lista\" con " << random << " valores aleatorios: " << std::endl;
        lista.Print();

        std::cout << "Se crea una nueva lista con el nombre \"otraLista\" y se le asigna \"lista\"" << std::endl << std::endl;
        DoubleCircularList<double> otraLista;
        otraLista = lista;

        random = 2 + rand()%SIZE;
        std::cout << std::endl;

        lista.Print();
        std::cout << "\nSe eliminan 5 valores de \"lista...\"" << std::endl;
        for(int i = 0; i < 5; ++i){
            lista.MoveHeadForward();
            std::cout << "Sale: " << lista.GetHead() << std::endl;
            lista.MoveHeadBackward();
            lista.Pop();
            lista.Print();
        }

        CapturaSegura(valor,"\nBusque un elemento en \"lista\": ");
        if(lista.Search(valor)) std::cout << "El elemento: " << valor << " se encuentra en \"lista\"" << std::endl;
        else std::cout << "El elemento: " << valor << " no se encuentra en \"lista\"" << std::endl;

        CapturaSegura(valor,"\nElimine un elemento en \"lista\": ");
        lista.DeleteElement(valor);
        std::cout << std::endl;
        std::cout << "La lista es: " << std::endl;
        lista.Print();

        CapturaSegura(valor,"\nElimine toda ocurrencia del elemento en \"lista\": ");
        lista.DeleteRepeatedElement(valor);
        std::cout << std::endl;
        std::cout << "La lista es: " << std::endl;
        lista.Print();



        std::cout << "\nSe vacia \"lista\"... " << std::endl;
        lista.Clear();

        std::cout << "\"lista\" es:" << std::endl;
        lista.Print();

        std::cout << "\nLa lista inicial es:" << std::endl;
        otraLista.Print();

        std::cout << "\nNumero de elementos: " << otraLista.Size() << std::endl;


    }catch (std::exception &exc){
        std::cerr << exc.what() << std::endl;
    }catch (...){
        std::cerr << "An unexpected error has ocurred..." << std::endl;
    }

    std::cout <<"////////////////////////////////////////////////////////////////////" << std::endl;
    std::cout <<"////////////////////////////////////////////////////////////////////" << std::endl;
    std::cout <<"Se efectuar\240 el mismo procedimiento con un tipo de valor distinto" << std::endl;
    std::cout <<"////////////////////////////////////////////////////////////////////" << std::endl;
    std::cout <<"////////////////////////////////////////////////////////////////////" << std::endl;
    system("pause");
    system("cls");
////***************************************************
    try{
        srand(time(NULL));
        char valor;
        int random = 2 + rand()%SIZE;
        DoubleCircularList<char> lista;
        std::cout << "Tipo de dato: Char" << std::endl;
        std::cout << "Se agregar\240n valores aleatorios a una lista cisrcular doble..." << std::endl;
        std::cout << "Cantidad de elemetos a agregar: " << random << std::endl;
        for(int i = 0; i < random; ++i){
            valor = 65+rand()%21;
            std::cout << "Entra: " << valor << std::endl;
            lista.Push(valor);
            lista.Print();
        }
        std::cout << "\n\"lista\" con " << random << " valores aleatorios: " << std::endl;
        lista.Print();

        std::cout << "Se crea una nueva lista con el nombre \"otraLista\" y se le asigna \"lista\"" << std::endl << std::endl;
        DoubleCircularList<char> otraLista;
        otraLista = lista;

        random = 2 + rand()%SIZE;
        std::cout << std::endl;

        lista.Print();
        std::cout << "\nSe eliminan 5 valores de \"lista...\"" << std::endl;
        for(int i = 0; i < 5; ++i){
            lista.MoveHeadForward();
            std::cout << "Sale: " << lista.GetHead() << std::endl;
            lista.MoveHeadBackward();
            lista.Pop();
            lista.Print();
        }

        CapturaSegura(valor,"\nBusque un elemento en \"lista\": ");
        if(lista.Search(valor)) std::cout << "El elemento: " << valor << " se encuentra en \"lista\"" << std::endl;
        else std::cout << "El elemento: " << valor << " no se encuentra en \"lista\"" << std::endl;

        CapturaSegura(valor,"\nElimine un elemento en \"lista\": ");
        lista.DeleteElement(valor);
        std::cout << std::endl;
        std::cout << "La lista es: " << std::endl;
        lista.Print();

        CapturaSegura(valor,"\nElimine toda ocurrencia del elemento en \"lista\": ");
        lista.DeleteRepeatedElement(valor);
        std::cout << std::endl;
        std::cout << "La lista es: " << std::endl;
        lista.Print();



        std::cout << "\nSe vacia \"lista\"... " << std::endl;
        lista.Clear();

        std::cout << "\"lista\" es:" << std::endl;
        lista.Print();

        std::cout << "\nLa lista inicial es:" << std::endl;
        otraLista.Print();

        std::cout << "\nNumero de elementos: " << otraLista.Size() << std::endl;


    }catch (std::exception &exc){
        std::cerr << exc.what() << std::endl;
    }catch (...){
        std::cerr << "An unexpected error has ocurred..." << std::endl;
    }

    std::cout <<"////////////////////////////////////////////////////////////////////" << std::endl;
    std::cout <<"////////////////////////////////////////////////////////////////////" << std::endl;
    std::cout <<"Se efectuar\240 el mismo procedimiento con un tipo de valor distinto" << std::endl;
    std::cout <<"////////////////////////////////////////////////////////////////////" << std::endl;
    std::cout <<"////////////////////////////////////////////////////////////////////" << std::endl;
    system("pause");
//////*********************************************************
    try{
        srand(time(NULL));
        int random = 2 + rand()%SIZE;
        DoubleCircularList<Persona> lista;
        std::cout << "Tipo de dato: Persona" << std::endl;
        std::cout << "Se agregar\240n valores aleatorios a una lista circular doble..." << std::endl;
        std::cout << "Cantidad de elemetos a agregar: " << 5 << std::endl;
        for(int i = 0; i < 5; ++i){
            Persona p;
            std::cout << "Se agrega a: " << p << std::endl;
            lista.Push(p);
             std::cout << "---------------" << std::endl;
            lista.Print();
             std::cout << "---------------" << std::endl;
            Sleep(1000);

        }

        std::cout << std::endl << std::endl;
        std::cout << "---------------" << std::endl;
        std::cout << "\n\"lista\" con valores aleatorios: " << random << std::endl;
        lista.Print();
        std::cout << std::endl << std::endl;
        std::cout << "---------------" << std::endl;

        std::cout << "\nSe van a copiar los datos de \"lista\" en \"otraLista\"..." << std::endl;
        DoubleCircularList<Persona> otraLista = lista;


        std::cout << std::endl << std::endl;
        std::cout << "---------------" << std::endl;
        std::cout << "\nSe eliminan 3 elementos de \"lista\"..." << std::endl;
        for(int i = 0; i < 3; ++i){
            lista.MoveHeadForward();
            std::cout << "Sale: " << lista.GetHead() << std::endl;
            lista.MoveHeadBackward();
            lista.Pop();
            std::cout << std::endl << std::endl;
            std::cout << "---------------" << std::endl;
            lista.Print();
            std::cout << "---------------" << std::endl;
        }
        lista.Print();
        std::cout << std::endl << std::endl;
        std::cout << "---------------" << std::endl;



        Sleep(1000);
        Persona a;


        std::cout << "---------------" << std::endl;
        std::cout << "\nSe agrega " << a << " a \"lista\" 5 veces..." << std::endl;
        for(int i = 0; i < 5; ++i)
            lista.Push(a);

        std::cout << "---------------" << std::endl;
        lista.Print();
        std::cout << "---------------" << std::endl;
        Sleep(1000);
        std::cout << "\nSe busca a " << a << " en \"lista\"..." << std::endl;

        if(lista.Search(a)) std::cout << a << " Se encuentra en \"lista\" " << std::endl;

        std::cout << "\nSe busca a " << a << " en \"otraLista\"..." << std::endl;

        if(!otraLista.Search(a)) std::cout << a << " NO se encuentra en \"lista\" " << std::endl;

        std::cout << "\nSe elimina a " << a << " en \"lista\"..." << std::endl;
        lista.DeleteElement(a);
        std::cout << "---------------" << std::endl;
        lista.Print();
        std::cout << "---------------" << std::endl;

        std::cout << "\nSe elimina toda ocurrencia de " << a << " en \"lista\"..." << std::endl;
        lista.DeleteRepeatedElement(a);
        std::cout << "---------------" << std::endl;
        lista.Print();
        std::cout << "---------------" << std::endl;



        std::cout << "\nSe vacia \"lista\"..." << std::endl;
        lista.Clear();

        std::cout << "---------------" << std::endl;
        std::cout << "\"lista\":" << std::endl;
        lista.Print();
        std::cout << "---------------" << std::endl;



        std::cout << "\nLa lista inicial es: " << std::endl << "---------------"  << std::endl;
        otraLista.Print();
        std::cout << "\nNumero de elementos:" << otraLista.Size() << std::endl;




    }catch (std::exception &exc){
        std::cerr << exc.what() << std::endl;
    }catch (...){
        std::cerr << "An unexpected error has ocurred..." << std::endl;
    }
    return 0;
}
