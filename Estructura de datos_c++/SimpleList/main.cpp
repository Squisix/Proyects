/*
    \Name: main.cpp
    \Author: Marco Antonio Guerrero Vasquez // 219202704
    \Date: 02/21/21
    \brief: Main class where Linked Data Stack of different types are tested
*/
#include <iostream>
#include <ctime>
#include <string>
#include "SimpleList.h"
#include "Matriz.h"

#define SIZE 20


int main()
{
    try{

        srand(time(NULL));
        int random = /*25;*/   2 + rand()%SIZE;
        SimpleList<double> lista;
        std::cout << "Data type: Double" << std::endl;
        std::cout << "First Size: " << lista.Size() << std::endl;
        std::cout << "First Random Value: " << random << std::endl;
        for(int i = 0; i < random; ++i){
            lista.Push_Back(i);
            lista.Print();
            std::cout << std::endl;
        }
        random = 2 + rand()%SIZE;
        std::cout << "\nPush front: " << random << std::endl;
        lista.Push_Front(random);
        lista.Print();

        random = 2 + rand()%SIZE;
        std::cout << "\nPush Back: " << random << std::endl;
        lista.Push_Back(random);
        lista.Print();

        random = 2 + rand()%SIZE;
        std::cout << "\nPush in " << random << std::endl;
        lista.Push_In_Pos(random,random);
        lista.Print();

        std::cout << "First Capacity: " << lista.Size() << std::endl;
        SimpleList<double> anotherLista;
        anotherLista = lista;

        random = 2 + rand()%SIZE;
        std::cout << std::endl;

        std::cout << "\nPop front: " << anotherLista.GetFirst() << std::endl;
        anotherLista.Pop_Front();
        anotherLista.Print();

        std::cout << "\nPop Back: " << anotherLista.GetLast() << std::endl;
        anotherLista.Pop_Back();
        anotherLista.Print();

        random = 2 + rand()%SIZE;
        std::cout << "\nPop in " << random << ": " << anotherLista[random] << std::endl;
        lista.Pop_In_Pos(random);
        anotherLista.Print();

        random = 2 + rand()%SIZE;
        std::cout << "Modify in: " << anotherLista[random] << " val: " << random << std::endl;
        anotherLista[random] = random;
        anotherLista.Print();


        for(int i = 0; i < random; ++i){
            std::cout << "Out: " << lista.GetFirst() << std::endl;
            lista.Pop_Front();
            lista.Print();
            std::cout << std::endl;
        }
        std::cout << "\nThe original List is:" << std::endl;
        anotherLista.Print();

        SimpleList<double> moreListas(anotherLista);
        anotherLista.Clear();

        std::cout << "\n\nAnother List is: " << std::endl ;
        anotherLista.Print();
        std::cout << "\nNumber of items of Another List is: " << anotherLista.Size() << std::endl;

        std::cout << "\n\nMore Lists is: " << std::endl;
        moreListas.Print();
        std::cout << "\nNumber of items of More List is: " << moreListas.Size() << std::endl;



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
        SimpleList<char> lista;
        std::cout << "Data type: char" << std::endl;
        std::cout << "First Random Value: " << random << std::endl;
        for(int i = 0; i < random; ++i){
            lista.Push_Back(i+'a');
            lista.Print();
            std::cout << std::endl;
        }

        random = 2 + rand()%SIZE;
        std::cout << "\nPush front: " << (char)random << std::endl;
        lista.Push_Front((char)random);
        lista.Print();

        random = 2 + rand()%SIZE;
        std::cout << "\nPush Back: " << (char)random << std::endl;
        lista.Push_Back((char)random);
        lista.Print();

        random = 2 + rand()%SIZE;
        std::cout << "\nPush in " << random << std::endl;
        lista.Push_In_Pos(random,(char)random);
        lista.Print();

        std::cout << "First Capacity: " << lista.Size() << std::endl;
        SimpleList<char> anotherLista;
        anotherLista = lista;

        random = 2 + rand()%SIZE;
        std::cout << std::endl;

        std::cout << "\nPop front: " << anotherLista.GetFirst() << std::endl;
        anotherLista.Pop_Front();
        anotherLista.Print();

        std::cout << "\nPop Back: " << anotherLista.GetLast() << std::endl;
        anotherLista.Pop_Back();
        anotherLista.Print();

        random = 2 + rand()%SIZE;
        std::cout << "\nPop in " << random << ": " << anotherLista[random] << std::endl;
        lista.Pop_In_Pos(random);
        anotherLista.Print();

        random = 2 + rand()%SIZE;
        std::cout << "Modify in: " << anotherLista[random] << " val: " << (char)random << std::endl;
        anotherLista[random] = (char)random;
        anotherLista.Print();


        for(int i = 0; i < random; ++i){
            std::cout << "Out: " << lista.GetFirst() << std::endl;
            lista.Pop_Front();
            lista.Print();
            std::cout << std::endl;
        }
        std::cout << "\nThe original List is:" << std::endl;
        anotherLista.Print();

        SimpleList<char> moreListas(anotherLista);
        anotherLista.Clear();

        std::cout << "\n\nAnother List is: " << std::endl ;
        anotherLista.Print();
        std::cout << "\nNumber of items of Another List is: " << anotherLista.Size() << std::endl;

        std::cout << "\n\nMore Lists is: " << std::endl;
        moreListas.Print();
        std::cout << "\nNumber of items of More List is: " << moreListas.Size() << std::endl;

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
        SimpleList<Matriz> lista;
        std::cout << "Data type: Matriz" << std::endl;
        std::cout << "First Random Value: " << random << std::endl;
        for(int i = 0; i < random; ++i){

            std::cout << std::endl;
            lista.Push_Back(Matriz(1+rand()%5,1+rand()%5,(double)i));

            lista.Print();
            std::cout << std::endl << std::endl;
            std::cout << "---------------" << std::endl;
        }

        random = 2 + rand()%SIZE;
        Matriz a(1+rand()%5,1+rand()%5,(double)random);
        std::cout << "\nPush front: " << std::endl << a << std::endl;
        std::cout << "---------------" << std::endl;
        lista.Push_Front(a);
        lista.Print();

        random = 2 + rand()%SIZE;
        Matriz b(1+rand()%5,1+rand()%5,(double)random);
        std::cout << "\nPush Back: " << std::endl << b << std::endl;
        std::cout << "---------------" << std::endl;
        lista.Push_Back(b);
        lista.Print();

        random = 2 + rand()%SIZE;
        std::cout << "\nPush in " << random << std::endl;
        Matriz c(1+rand()%5,1+rand()%5,(double)random);
        lista.Push_In_Pos(random,c);
        lista.Print();
        std::cout << "---------------" << std::endl;

        SimpleList<Matriz> anotherLista;
        anotherLista = lista;

        random = 2 + rand()%SIZE;
        std::cout << std::endl;

        std::cout << "\nPop front: " << std::endl << anotherLista.GetFirst() << std::endl;
        std::cout << "---------------" << std::endl;
        anotherLista.Pop_Front();
        anotherLista.Print();

        std::cout << "\nPop Back: " << std::endl << anotherLista.GetLast() << std::endl;
        std::cout << "---------------" << std::endl;
        anotherLista.Pop_Back();
        anotherLista.Print();

        random = 2 + rand()%SIZE;
        std::cout << "\nPop in " << random << ": " << std::endl << anotherLista[random] << std::endl;
        lista.Pop_In_Pos(random);
        anotherLista.Print();

        random = 2 + rand()%SIZE;
        Matriz d(1+rand()%5,1+rand()%5,(double)random);
        std::cout << "Modify in: " << anotherLista[random] << " val: " << std::endl << d << std::endl;
        std::cout << "---------------" << std::endl;
        anotherLista[random] = d;
        anotherLista.Print();


        std::cout << "Second Random Value: " << random << std::endl;
        for(int i = 0; i < random; ++i){
            std::cout << "Out: " << std::endl << lista.GetFirst() << std::endl;
            lista.Pop_Front();
            lista.Print();
            std::cout << std::endl << std::endl;
            std::cout << "---------------" << std::endl;
        }
        std::cout << "\nThe original List is:" << std::endl << "---------------" << std::endl;
        anotherLista.Print();

        SimpleList<Matriz> moreLista(anotherLista);
        anotherLista.Clear();

        std::cout << "\n\nAnother List is: " << std::endl << "---------------"  << std::endl;
        anotherLista.Print();
        std::cout << "\nNumber of items of Another List is:" << anotherLista.Size() << std::endl;

        std::cout << "\n\nMore List is: " << std::endl << "---------------" << moreLista <<std::endl;

        std::cout << "\nNumber of items of More List is: " << moreLista.Size() << std::endl;



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
