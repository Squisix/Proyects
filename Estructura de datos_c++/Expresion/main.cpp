#include <iostream>
#include "Expresion.h"
using namespace std;

int main()
{
    try{
        char infija[TAM];
        do{

            cin.getline(infija,TAM);

            Expresion expresion(infija);
            cout << endl << endl;
        }while(infija[0] != 's');

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
