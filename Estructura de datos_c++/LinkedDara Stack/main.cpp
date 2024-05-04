/*
    \Name: main.cpp
    \Author: Marco Antonio Guerrero Vasquez // 219202704
    \Date: 02/11/21
    \brief: Main class where resizable arrays of different types are tested
*/
#include <iostream>
#include <ctime>
#include <string>
#include "LinkedDataStack.h"
//#include "Matriz.h"

#define SIZE 20

bool Corchetes(char entrada[50], LinkedDataStack<char> simbolos);
int main()
{
    try{
        LinkedDataStack<char> simbolos;
        char entrada[50];
        std::cout << "Entrada: ";
        std::cin >> entrada;
        if(Corchetes(entrada,simbolos)) std::cout << "\nEntrada correcta" << std::endl;
        else std::cout << "\nEntrada incorrecta" << std::endl;
        std::cout << "Entrada: ";
        std::cin >> entrada;
        if(Corchetes(entrada,simbolos)) std::cout << "\nEntrada correcta" << std::endl;
        else std::cout << "\nEntrada incorrecta" << std::endl;
        std::cout << "Entrada: ";
        std::cin >> entrada;
        if(Corchetes(entrada,simbolos)) std::cout << "\nEntrada correcta" << std::endl;
        else std::cout << "\nEntrada incorrecta" << std::endl;
        //std::cout << std::endl << '{';

////        srand(time(NULL));
////        int random = /*25;*/   2 + rand()%SIZE;
////        LinkedDataStack<double> pila;
////
////        std::cout << "First Capacity: " << pila.Size() << std::endl;
////        std::cout << "First Random Value: " << random << std::endl;
////        for(int i = 0; i < random; ++i){
////            pila.Push(i);
////           pila.Print();
////            std::cout << /* pila << */ std::endl;
////        }
////        std::cout << "First Capacity: " << pila.Size() << std::endl;
////        LinkedDataStack<double> anotherPila;
////        anotherPila = pila;
//////
////        random = 2 + rand()%SIZE;
////        std::cout << std::endl;
//////
//////
////        std::cout << "Second Random Value: " << random << std::endl;
////        for(int i = 0; i < random; ++i){
////            std::cout << "Out: " << pila.Top() << std::endl;
////            pila.Pop();
////            pila.Print();
////            std::cout << /*pila << */ std::endl;
////        }
////        std::cout << "\nThe original Stack is:" << std::endl /*<< anotherPila*/;
////        anotherPila.Print();
//////
////        LinkedDataStack<double> morePilas = anotherPila;
////        anotherPila.Clear();
//////
////        std::cout << "\n\nAnother Stack is: " << std::endl /*<< anotherPila*/;
////        anotherPila.Print();
////        std::cout << "\nNumber of items of Another Stacks is:" << anotherPila.Size() << std::endl;
//////
////        std::cout << "\n\nMore Stacks is: " << /* morePilas <<*/std::endl;
////        morePilas.Print();
////        std::cout << "\nNumber of items of More Stacks is: " << morePilas.Size() << std::endl;
//////
//////
//////
////    }catch (std::exception &exc){
////        std::cerr << exc.what() << std::endl;
////    }catch (...){
////        std::cerr << "An unexpected error has ocurred..." << std::endl;
////    }
////***************************************************
//    try{
//        srand(time(NULL));
//        int random = 2 + rand()%SIZE;
//        LinkedDataStack<char> pila;
//
//        std::cout << "First Random Value: " << random << std::endl;
//        for(int i = 0; i < random; ++i){
//            pila.Push(i+'a');
//
////            pila.Print();
//            std::cout << pila << std::endl;
//        }
//
//        LinkedDataStack<char> anotherPila;
//        anotherPila = pila;
//
//        random = 2 + rand()%SIZE;
//        std::cout << std::endl;
//
//
//        std::cout << "Second Random Value: " << random << std::endl;
//        for(int i = 0; i < random; ++i){
//            std::cout << "Out: " << pila.Top() << std::endl;
//            pila.Pop();
//            //pila.Print();
//            std::cout << pila <<std::endl;
//        }
//        std::cout << "\nThe original Stack is:" << std::endl << anotherPila;
//        //anotherPila.Print();
//
//        LinkedDataStack<char> morePilas(anotherPila);
//        anotherPila.Clear();
//
//        std::cout << "\n\nAnother Stack is: " << std::endl << anotherPila;
//        //anotherPila.Print();
//        std::cout << "\nNumber of items of More Stacks is:" << anotherPila.Size() << std::endl;
//
//        std::cout << "\n\nMore Stacks is: " << morePilas <<std::endl;
//        //morePilas.Print();
//        std::cout << "\nNumber of items of More Stacks is: " << morePilas.Size() << std::endl;
//
//
//
//    }catch (std::exception &exc){
//        std::cerr << exc.what() << std::endl;
//    }catch (...){
//        std::cerr << "An unexpected error has ocurred..." << std::endl;
//    }

//    try{
//        srand(time(NULL));
//        int random = 2 + rand()%SIZE;
//        ResizableStack<Matriz> pila;
//
//
//        std::cout << "First Random Value: " << random << std::endl;
//        for(int i = 0; i < random; ++i){
//
//            Matriz matriz(2,2,(double)i);
//            //std::cin >> matriz; // Para leer con espacios escribir getline(std::cin,cadena);
//            pila.Push(matriz);
//
////            pila.Print();
//            std::cout << pila << std::endl;
//            std::cout << std::endl;
//            std::cout << "---------------" << std::endl;
//        }
//
//        ResizableStack<Matriz> anotherPila;
//        anotherPila = pila;
//
//        random = 2 + rand()%SIZE;
//        std::cout << std::endl;
//
//
//        std::cout << "Second Random Value: " << random << std::endl;
//        for(int i = 0; i < random; ++i){
//            std::cout << "Out: " << std::endl << pila.Top() << std::endl;
//            pila.Pop();
//            //pila.Print();
//            std::cout << pila <<std::endl;
//            std::cout << std::endl;
//            std::cout << "---------------" << std::endl;
//        }
//        std::cout << "\nThe original Stack is:" << std::endl << "---------------" << std::endl << anotherPila;
//        //anotherPila.Print();
//
//        ResizableStack<Matriz> morePilas(anotherPila);
//        anotherPila.Clear();
//
//        std::cout << "\n\nAnother Stack is: " << std::endl << "---------------"  << std::endl << anotherPila;
//        //anotherPila.Print();
//        std::cout << "\nNumber of items of More Stacks is:" << anotherPila.Size() << std::endl;
//
//        std::cout << "\n\nMore Stacks is: " << std::endl << "---------------" << morePilas << std::endl <<std::endl;
//        //morePilas.Print();
//        std::cout << "\nNumber of items of More Stacks is: " << morePilas.Size() << std::endl;
//
//
//
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

bool Corchetes(char entrada[50], LinkedDataStack<char> simbolos){
    for(int i = 0; entrada[i]!= '\0'; ++i){
            if(entrada[i] == '[' || entrada[i] == '{' || entrada[i] == '(')
                simbolos.Push(entrada[i]);

            if(entrada[i] == ']' || entrada[i] == '}' || entrada[i] == ')'){
                if(simbolos.Empty()) return false;
                    switch(entrada[i]){
                        case ']':{
                            if(simbolos.Top()=='[') simbolos.Pop();
                            else break;
                            break;
                        }
                        case '}':{
                            if(simbolos.Top()=='{') simbolos.Pop();
                            else break;
                            break;
                        }
                        case ')':{
                            if(simbolos.Top()=='(') simbolos.Pop();
                            else break;
                            break;
                        }
                    }
                }

        }
        if(simbolos.Size() == 0) return true;
        else return false;

}
bool esOperador(char c){
    switch(c){
        case '+':
        case '-':
        case '/':
        case '*':
        case '^':
            return true;
        default:
            return false;
    }
}
