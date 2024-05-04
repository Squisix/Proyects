/*
    \Name: main.cpp
    \Author: Marco Antonio Guerrero Vasquez // 219202704
    \Date: 02/21/21
    \brief: Main class where Linked Data Stack of different types are tested
*/
#include <iostream>
#include <ctime>
#include <string>
#include "DoubleLinkedList.h"
#include "Persona.h"
#include <windows.h>

#define SIZE 20


int main()
{
    try{
        srand(time(NULL));
        int random = /*25;*/   2 + rand()%SIZE;
        DoubleLinkedList<double> lista;
        std::cout << "Tipo de dato: Double" << std::endl;
        std::cout << "Primer Numero Random: " << random << std::endl;
        for(int i = 0; i < random; ++i){
            lista.Push_Back(-20+rand()%100);
        }
        std::cout << "\n\"lista\" con valores aleatorios: " << random << std::endl;
        lista.Print();

        random = 2 + rand()%SIZE;
        std::cout << "\nAgregar al inicio: " << random << std::endl;
        lista.Push_Front(random);
        lista.Print();

        random = 2 + rand()%SIZE;
        std::cout << "\nAgregar al final: " << random << std::endl;
        lista.Push_Back(random);
        lista.Print();

        random = 2 + rand()%SIZE;
        std::cout << "\nAgregar en la posici\243n: " << random << std::endl;
        lista.Push_In_Pos(random,random);
        lista.Print();

        std::cout << "Tamaño de \"lista\": " << lista.Size() << std::endl;
        DoubleLinkedList<double> otraLista;
        otraLista = lista;

        random = 2 + rand()%SIZE;
        std::cout << std::endl;

        std::cout << "\nEliminar del inicio: " << otraLista.GetFirst() << std::endl;
        otraLista.Pop_Front();
        otraLista.Print();

        std::cout << "\nEliminar del final: " << otraLista.GetLast() << std::endl;
        otraLista.Pop_Back();
        otraLista.Print();

        random = 2 + rand()%SIZE;
        std::cout << "\nEliminar de la posici\243n: " << random << ": " << otraLista[random] << std::endl;
        otraLista.Pop_In_Pos(random);
        otraLista.Print();

        random = 2 + rand()%SIZE;
        std::cout << "Modificar en posici\243: " << random << std::endl;
        otraLista[random] = random;
        otraLista.Print();


        for(int i = 0; i < random; ++i){
            std::cout << "Sale: " << lista.GetFirst() << std::endl;
            lista.Pop_Front();
            lista.Print();
            std::cout << std::endl;
        }
        std::cout << "\nLa lista original es is:" << std::endl;
        otraLista.Print();

        DoubleLinkedList<double> masListas(otraLista);
        otraLista.Clear();

        std::cout << "\n\nOtra lista es: " << std::endl ;
        otraLista.Print();
        std::cout << "\nNumero de elementos de otra lista: " << otraLista.Size() << std::endl;

        std::cout << "\n\nMas Listas es: " << std::endl;
        masListas.Print();
        std::cout << "\nNumero de elementos de mas listas es: " << masListas.Size() << std::endl;



    }catch (std::exception &exc){
        std::cerr << exc.what() << std::endl;
    }catch (...){
        std::cerr << "An unexpected error has ocurred..." << std::endl;
    }

    std::cout <<"///////////////////////////////////////////////////////////" << std::endl;
    std::cout <<"///////////////////////////////////////////////////////////" << std::endl;
////***************************************************
    try{
        srand(time(NULL));
        int random = 2 + rand()%SIZE;
        DoubleLinkedList<char> lista;
        std::cout << "Tipo de dato: Char" << std::endl;
        std::cout << "Primer Numero Random: " << random << std::endl;
        for(int i = 0; i < random; ++i){
            lista.Push_Back(rand()%20+'a');
        }

        std::cout << "\n\"lista\" con valores aleatorios: " << random << std::endl;
        lista.Print();

        random = 2 + rand()%SIZE;
        std::cout << "\nAgregar al inicio: " << (char)random << std::endl;
        lista.Push_Front((char)random);
        lista.Print();

        random = 2 + rand()%SIZE;
        std::cout << "\nAgregar al final: " << (char)random << std::endl;
        lista.Push_Back((char)random);
        lista.Print();

        random = 2 + rand()%SIZE;
        std::cout << "\nAgregar en la posici\243n: " << random << std::endl;
        lista.Push_In_Pos(random,(char)random);
        lista.Print();

        std::cout << "Tamaño de \"lista\": " << lista.Size() << std::endl;
        DoubleLinkedList<char> otraLista;
        otraLista = lista;

        random = 2 + rand()%SIZE;
        std::cout << std::endl;

        std::cout << "\nEliminar del inicio: " << otraLista.GetFirst() << std::endl;
        otraLista.Pop_Front();
        otraLista.Print();

        std::cout << "\nEliminar del final: " << otraLista.GetLast() << std::endl;
        otraLista.Pop_Back();
        otraLista.Print();

        random = 2 + rand()%SIZE;
        std::cout << "\nEliminar de la posici\243n: " << random << ": " << otraLista[random] << std::endl;
        otraLista.Pop_In_Pos(random);
        otraLista.Print();

        random = 2 + rand()%SIZE;
        std::cout << "Modificar en posici\243: " << random << std::endl;
        otraLista[random] = (char)random;
        otraLista.Print();


        for(int i = 0; i < random; ++i){
            std::cout << "Sale: " << lista.GetFirst() << std::endl;
            lista.Pop_Front();
            lista.Print();
            std::cout << std::endl;
        }
        std::cout << "\nLa lista original es is:" << std::endl;
        otraLista.Print();

        DoubleLinkedList<char> masListas(otraLista);
        otraLista.Clear();

        std::cout << "\n\nOtra lista es: " << std::endl ;
        otraLista.Print();
        std::cout << "\nNumero de elementos de otra lista: " << otraLista.Size() << std::endl;

        std::cout << "\n\nMas Listas es: " << std::endl;
        masListas.Print();
        std::cout << "\nNumero de elementos de mas listas es: " << masListas.Size() << std::endl;

    }catch (std::exception &exc){
        std::cerr << exc.what() << std::endl;
    }catch (...){
        std::cerr << "An unexpected error has ocurred..." << std::endl;
    }
    std::cout <<"///////////////////////////////////////////////////////////" << std::endl;
    std::cout <<"///////////////////////////////////////////////////////////" << std::endl;
////*********************************************************
    try{
        srand(time(NULL));
        int random = 2 + rand()%SIZE;
        DoubleLinkedList<Persona> lista;
        std::cout << "Tipo de dato: Persona" << std::endl;
        std::cout << "Primer Numero Random: " << random << std::endl;
        for(int i = 0; i < random; ++i){

            std::cout << std::endl;
            Persona p;
            lista.Push_Back(p);
            Sleep(1000);

        }
        std::cout << std::endl << std::endl;
        std::cout << "---------------" << std::endl;
        std::cout << "\n\"lista\" con valores aleatorios: " << random << std::endl;
        lista.Print();
        std::cout << std::endl << std::endl;
        std::cout << "---------------" << std::endl;
        Sleep(1000);
        Persona a;

        std::cout << "\nAgregar al inicio: "  << a << std::endl;
        std::cout << "---------------" << std::endl;
        lista.Push_Front(a);
        lista.Print();

        Sleep(1000);
        Persona b;

        std::cout << "\nAgregar al final: " << b << std::endl;
        std::cout << "---------------" << std::endl;
        lista.Push_Back(b);
        lista.Print();

        random = 2 + rand()%SIZE;
        std::cout << "\nAgregar en posici\242n: " << random << std::endl;
        Sleep(1000);
        Persona c;

        lista.Push_In_Pos(random,c);
        lista.Print();
        std::cout << "---------------" << std::endl;

        DoubleLinkedList<Persona> otraLista;
        otraLista = lista;

        random = 2 + rand()%SIZE;
        std::cout << std::endl;

        std::cout << "\nEliminar del inicio: " << otraLista.GetFirst() << std::endl;
        otraLista.Pop_Front();
        otraLista.Print();

        std::cout << "\nEliminar del final: " << otraLista.GetLast() << std::endl;
        otraLista.Pop_Back();
        otraLista.Print();

        random = 2 + rand()%SIZE;
        std::cout << "\nEliminar de la posici\243n: " << random << ": " << otraLista[random] << std::endl;
        otraLista.Pop_In_Pos(random);
        otraLista.Print();

        random = 2 + rand()%SIZE;
        std::cout << "Modificar en posici\243: " << random << std::endl;
        Sleep(1000);
        Persona d;
        otraLista[random] = d;
        otraLista.Print();



        std::cout << "Second Random Value: " << random << std::endl;
        for(int i = 0; i < random; ++i){
            std::cout << "Sale: " << lista.GetFirst() << std::endl;
            lista.Pop_Front();
            lista.Print();
            std::cout << std::endl << std::endl;
            std::cout << "---------------" << std::endl;
        }
        std::cout << "\nLa lista original es:" << std::endl << "---------------" << std::endl;
        otraLista.Print();

        DoubleLinkedList<Persona> masLista(otraLista);
        otraLista.Clear();

        std::cout << "\n\nOtra Lista es: " << std::endl << "---------------"  << std::endl;
        otraLista.Print();
        std::cout << "\nNumero de elementos en otra lista:" << otraLista.Size() << std::endl;

        std::cout << "\n\nMas Listas es: " << std::endl << "---------------" << masLista <<std::endl;

        std::cout << "\nNumero de elementos de mas listas " << masLista.Size() << std::endl;



    }catch (std::exception &exc){
        std::cerr << exc.what() << std::endl;
    }catch (...){
        std::cerr << "An unexpected error has ocurred..." << std::endl;
    }
    return 0;
}
