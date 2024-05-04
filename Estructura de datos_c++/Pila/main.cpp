#include <iostream>
#include <ctime>
#include <string>
#include "Stack.h"

#define SIZE 10

using namespace std;

int main()
{
    try{
        srand(time(NULL));
        int random = 2 + rand()%SIZE;
        Stack<double, 10> pila;


        std::cout << "First Random Value: " << random << std::endl;
        for(int i = 0; i < random; ++i){
            pila.Push(i);

//            pila.Print();
            std::cout << pila << std::endl;
        }

        Stack<double, 10> anotherPila;
        anotherPila = pila;

        random = 2 + rand()%SIZE;
        std::cout << std::endl;


        std::cout << "Second Random Value: " << random << std::endl;
        for(int i = 0; i < random; ++i){
            std::cout << "Out: " << pila.Top() << std::endl;
            pila.Pop();
            //pila.Print();
            std::cout << pila <<std::endl;
        }
        std::cout << "\nThe original Stack is:" << std::endl << anotherPila;
        //anotherPila.Print();

        Stack<double, 10> morePilas(anotherPila);
        anotherPila.Clear();

        std::cout << "\n\n Another Stack is:" << std::endl << anotherPila;
        //anotherPila.Print();
        std::cout << "\n Number of itmes of More Stacks is:" << anotherPila.Size() << std::endl;

        std::cout << "\n\n More Stacks is:" << morePilas <<std::endl;
        //morePilas.Print();
        std::cout << "\n Number of itmes of More Stacks is:" << morePilas.Size() << std::endl;



    }catch (std::exception &exc){
        std::cerr << exc.what() << std::endl;
    }catch (...){
        std::cerr << "An unexpected error has ocurred..." << std::endl;
    }

    try{
        srand(time(NULL));
        int random = 2 + rand()%SIZE;
        Stack<char,15> pila;

        std::cout << "First Random Value: " << random << std::endl;
        for(int i = 0; i < random; ++i){
            pila.Push(i+'a');

//            pila.Print();
            std::cout << pila << std::endl;
        }

        Stack<char,15> anotherPila;
        anotherPila = pila;

        random = 2 + rand()%SIZE;
        std::cout << std::endl;


        std::cout << "Second Random Value: " << random << std::endl;
        for(int i = 0; i < random; ++i){
            std::cout << "Out: " << pila.Top() << std::endl;
            pila.Pop();
            //pila.Print();
            std::cout << pila <<std::endl;
        }
        std::cout << "\nThe original Stack is:" << std::endl << anotherPila;
        //anotherPila.Print();

        Stack<char,15> morePilas(anotherPila);
        anotherPila.Clear();

        std::cout << "\n\n Another Stack is:" << std::endl << anotherPila;
        //anotherPila.Print();
        std::cout << "\n Number of itmes of More Stacks is:" << anotherPila.Size() << std::endl;

        std::cout << "\n\n More Stacks is:" << morePilas <<std::endl;
        //morePilas.Print();
        std::cout << "\n Number of itmes of More Stacks is:" << morePilas.Size() << std::endl;



    }catch (std::exception &exc){
        std::cerr << exc.what() << std::endl;
    }catch (...){
        std::cerr << "An unexpected error has ocurred..." << std::endl;
    }

    try{
        srand(time(NULL));
        int random = 2 + rand()%SIZE;
        Stack<std::string,8> pila;

        std::string cadena;


        std::cout << "First Random Value: " << random << std::endl;
        for(int i = 0; i < random; ++i){
            std::cin >> cadena; // Para leer con espacios escribir getline(std::cin,cadena);
            pila.Push(cadena);

//            pila.Print();
            std::cout << pila << std::endl;
        }

        Stack<std::string,8> anotherPila;
        anotherPila = pila;

        random = 2 + rand()%SIZE;
        std::cout << std::endl;


        std::cout << "Second Random Value: " << random << std::endl;
        for(int i = 0; i < random; ++i){
            std::cout << "Out: " << pila.Top() << std::endl;
            pila.Pop();
            //pila.Print();
            std::cout << pila <<std::endl;
        }
        std::cout << "\nThe original Stack is:" << std::endl << anotherPila;
        //anotherPila.Print();

        Stack<std::string,8> morePilas(anotherPila);
        anotherPila.Clear();

        std::cout << "\n\n Another Stack is:" << std::endl << anotherPila;
        //anotherPila.Print();
        std::cout << "\n Number of itmes of More Stacks is:" << anotherPila.Size() << std::endl;

        std::cout << "\n\n More Stacks is:" << morePilas <<std::endl;
        //morePilas.Print();
        std::cout << "\n Number of itmes of More Stacks is:" << morePilas.Size() << std::endl;



    }catch (std::exception &exc){
        std::cerr << exc.what() << std::endl;
    }catch (...){
        std::cerr << "An unexpected error has ocurred..." << std::endl;
    }
    return 0;
}
