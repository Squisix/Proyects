/*
    \Name: main.cpp
    \Author: Marco Antonio Guerrero Vasquez // 219202704
    \Date: 02/21/21
    \brief: Main class where Linked Data Stack of different types are tested
*/
#include <iostream>
#include <ctime>
#include <string>
#include "LinkedDataQueue.h"
#include "Matriz.h"

#define SIZE 20


int main()
{
    try{

        srand(time(NULL));
        int random = /*25;*/   2 + rand()%SIZE;
        LinkedDataQueue<double> cola;
        std::cout << "Data type: Double" << std::endl;
        std::cout << "First Size: " << cola.Size() << std::endl;
        std::cout << "First Random Value: " << random << std::endl;
        for(int i = 0; i < random; ++i){
            cola.Push(i);
            cola.Print();
            std::cout << std::endl;
        }
        std::cout << "First Capacity: " << cola.Size() << std::endl;
        LinkedDataQueue<double> anotherCola;
        anotherCola = cola;

        random = 2 + rand()%SIZE;
        std::cout << std::endl;


        std::cout << "Second Random Value: " << random << std::endl;
        for(int i = 0; i < random; ++i){
            std::cout << "Out: " << cola.GetFirst() << std::endl;
            cola.Pop();
            cola.Print();
            std::cout << std::endl;
        }
        std::cout << "\nThe original Queue is:" << std::endl;
        anotherCola.Print();

        LinkedDataQueue<double> moreColas(anotherCola);
        anotherCola.Clear();

        std::cout << "\n\nAnother Queue is: " << std::endl ;
        anotherCola.Print();
        std::cout << "\nNumber of items of Another Queue is: " << anotherCola.Size() << std::endl;

        std::cout << "\n\nMore Queues is: " << std::endl;
        moreColas.Print();
        std::cout << "\nNumber of items of More Queue is: " << moreColas.Size() << std::endl;



    }catch (std::exception &exc){
        std::cerr << exc.what() << std::endl;
    }catch (...){
        std::cerr << "An unexpected error has ocurred..." << std::endl;
    }

    std::cout <<"///////////////////////////////////////////////////////////" << std::endl;
    std::cout <<"///////////////////////////////////////////////////////////" << std::endl;
//***************************************************
    try{
        srand(time(NULL));
        int random = 2 + rand()%SIZE;
        LinkedDataQueue<char> cola;
        std::cout << "Data type: char" << std::endl;
        std::cout << "First Random Value: " << random << std::endl;
        for(int i = 0; i < random; ++i){
            cola.Push(i+'a');
            cola.Print();
            std::cout << std::endl;
        }

        std::cout << "First Capacity: " << cola.Size() << std::endl;
        LinkedDataQueue<char> anotherCola;
        anotherCola = cola;

        random = 2 + rand()%SIZE;
        std::cout << std::endl;


        std::cout << "Second Random Value: " << random << std::endl;
        for(int i = 0; i < random; ++i){
            std::cout << "Out: " << cola.GetFirst() << std::endl;
            cola.Pop();
            cola.Print();
            std::cout << std::endl;
        }
        std::cout << "\nThe original Stack is:" << std::endl;
        anotherCola.Print();

        LinkedDataQueue<char> moreColas(anotherCola);
        anotherCola.Clear();

        std::cout << "\n\nAnother Stack is: " << std::endl ;
        anotherCola.Print();
        std::cout << "\nNumber of items of Another Stacks is: " << anotherCola.Size() << std::endl;

        std::cout << "\n\nMore Stacks is: " << std::endl;
        moreColas.Print();
        std::cout << "\nNumber of items of More Stacks is: " << moreColas.Size() << std::endl;
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
        LinkedDataQueue<Matriz> cola;
        //LinkedDataStack<int> p1;
        std::cout << "Data type: Matriz" << std::endl;
        std::cout << "First Random Value: " << random << std::endl;
        //for(int i = 0; i < 2; ++i) p1.Push(i);
        for(int i = 0; i < random; ++i){

            //std::cin >> matriz; // Para leer con espacios escribir getline(std::cin,cadena);
            std::cout << std::endl;
            cola.Push(Matriz(1+rand()%5,1+rand()%5,(double)i));

            cola.Print();
            std::cout << std::endl << std::endl;
            std::cout << "---------------" << std::endl;
        }

        LinkedDataQueue<Matriz> anotherCola;
        anotherCola = cola;

        random = 2 + rand()%SIZE;
        std::cout << std::endl;


        std::cout << "Second Random Value: " << random << std::endl;
        for(int i = 0; i < random; ++i){
            std::cout << "Out: " << std::endl << cola.GetFirst() << std::endl;
            cola.Pop();
            cola.Print();
            std::cout << std::endl << std::endl;
            std::cout << "---------------" << std::endl;
        }
        std::cout << "\nThe original Stack is:" << std::endl << "---------------" << std::endl;
        anotherCola.Print();

        LinkedDataQueue<Matriz> moreColas(anotherCola);
        anotherCola.Clear();

        std::cout << "\n\nAnother Stack is: " << std::endl << "---------------"  << std::endl;
        anotherCola.Print();
        std::cout << "\nNumber of items of Another Stacks is:" << anotherCola.Size() << std::endl;

        std::cout << "\n\nMore Stacks is: " << std::endl << "---------------" << moreColas <<std::endl;

        std::cout << "\nNumber of items of More Stacks is: " << moreColas.Size() << std::endl;



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
