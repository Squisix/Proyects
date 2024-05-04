/*
    \Name: main.cpp
    \Author: Marco Antonio Guerrero Vasquez // 219202704
    \Date: 02/21/21
    \brief: Main class where Linked Data Stack of different types are tested
*/
#include <iostream>
#include <ctime>
#include <string>
#include "LinkedDataStack.h"
#include "Matriz.h"

#define SIZE 20


int main()
{
    try{

        srand(time(NULL));
        int random = /*25;*/   2 + rand()%SIZE;
        LinkedDataStack<double> pila;
        std::cout << "Data type: Double" << std::endl;
        std::cout << "First Capacity: " << pila.Size() << std::endl;
        std::cout << "First Random Value: " << random << std::endl;
        for(int i = 0; i < random; ++i){
            pila.Push(i);
            pila.Print();
            std::cout << std::endl;
        }
        std::cout << "First Capacity: " << pila.Size() << std::endl;
        LinkedDataStack<double> anotherPila;
        anotherPila = pila;

        random = 2 + rand()%SIZE;
        std::cout << std::endl;


        std::cout << "Second Random Value: " << random << std::endl;
        for(int i = 0; i < random; ++i){
            std::cout << "Out: " << pila.Top() << std::endl;
            pila.Pop();
            pila.Print();
            std::cout << std::endl;
        }
        std::cout << "\nThe original Stack is:" << std::endl;
        anotherPila.Print();

        LinkedDataStack<double> morePilas(anotherPila);
        anotherPila.Clear();

        std::cout << "\n\nAnother Stack is: " << std::endl ;
        anotherPila.Print();
        std::cout << "\nNumber of items of Another Stacks is: " << anotherPila.Size() << std::endl;

        std::cout << "\n\nMore Stacks is: " << std::endl;
        morePilas.Print();
        std::cout << "\nNumber of items of More Stacks is: " << morePilas.Size() << std::endl;



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
        LinkedDataStack<char> pila;
        std::cout << "Data type: char" << std::endl;
        std::cout << "First Random Value: " << random << std::endl;
        for(int i = 0; i < random; ++i){
            pila.Push(i+'a');
            pila.Print();
            std::cout << std::endl;
        }

        std::cout << "First Capacity: " << pila.Size() << std::endl;
        LinkedDataStack<char> anotherPila;
        anotherPila = pila;

        random = 2 + rand()%SIZE;
        std::cout << std::endl;


        std::cout << "Second Random Value: " << random << std::endl;
        for(int i = 0; i < random; ++i){
            std::cout << "Out: " << pila.Top() << std::endl;
            pila.Pop();
            pila.Print();
            std::cout << std::endl;
        }
        std::cout << "\nThe original Stack is:" << std::endl;
        anotherPila.Print();

        LinkedDataStack<char> morePilas(anotherPila);
        anotherPila.Clear();

        std::cout << "\n\nAnother Stack is: " << std::endl ;
        anotherPila.Print();
        std::cout << "\nNumber of items of Another Stacks is: " << anotherPila.Size() << std::endl;

        std::cout << "\n\nMore Stacks is: " << std::endl;
        morePilas.Print();
        std::cout << "\nNumber of items of More Stacks is: " << morePilas.Size() << std::endl;
    }catch (std::exception &exc){
        std::cerr << exc.what() << std::endl;
    }catch (...){
        std::cerr << "An unexpected error has ocurred..." << std::endl;
    }
    std::cout <<"///////////////////////////////////////////////////////////" << std::endl;
    std::cout <<"///////////////////////////////////////////////////////////" << std::endl;
//*********************************************************
    try{
        srand(time(NULL));
        int random = 2 + rand()%SIZE;
        LinkedDataStack<Matriz> pila;
        //LinkedDataStack<int> p1;
        std::cout << "Data type: Matriz" << std::endl;
        std::cout << "First Random Value: " << random << std::endl;
        //for(int i = 0; i < 2; ++i) p1.Push(i);
        for(int i = 0; i < random; ++i){

            //std::cin >> matriz; // Para leer con espacios escribir getline(std::cin,cadena);
            std::cout << std::endl;
            pila.Push(Matriz(1+rand()%5,1+rand()%5,(double)i));

            pila.Print();
            std::cout << std::endl << std::endl;
            std::cout << "---------------" << std::endl;
        }

        LinkedDataStack<Matriz> anotherPila;
        anotherPila = pila;

        random = 2 + rand()%SIZE;
        std::cout << std::endl;


        std::cout << "Second Random Value: " << random << std::endl;
        for(int i = 0; i < random; ++i){
            std::cout << "Out: " << std::endl << pila.Top() << std::endl;
            pila.Pop();
            pila.Print();
            std::cout << std::endl << std::endl;
            std::cout << "---------------" << std::endl;
        }
        std::cout << "\nThe original Stack is:" << std::endl << "---------------" << std::endl;
        anotherPila.Print();

        LinkedDataStack<Matriz> morePilas(anotherPila);
        anotherPila.Clear();

        std::cout << "\n\nAnother Stack is: " << std::endl << "---------------"  << std::endl;
        anotherPila.Print();
        std::cout << "\nNumber of items of Another Stacks is:" << anotherPila.Size() << std::endl;

        std::cout << "\n\nMore Stacks is: " << std::endl << "---------------" << morePilas <<std::endl;

        std::cout << "\nNumber of items of More Stacks is: " << morePilas.Size() << std::endl;



    }catch(std::out_of_range &exc){
        std::cerr << "\nError: " << exc.what() << std::endl;
    }catch(std::logic_error &exc){
        std::cerr << "\nError: " << exc.what() << std::endl;
    }catch(std::bad_alloc &exc){
        std::cerr << "\nError: Falla en la asignaci\242n de memoria" << std::endl;
    }catch (std::exception &exc){
        std::cerr << exc.what() << std::endl;
    }catch (...){
        std::cerr << "An unexpected error has ocurred..." << std::endl;
    }
    return 0;
}
