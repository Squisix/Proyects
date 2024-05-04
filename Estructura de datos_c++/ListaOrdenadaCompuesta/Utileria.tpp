// Nombre: Plantillas.tpp
// Autor: Marco Antonio Guerrero Vasquez
// Fecha: 04/04/2020
// Descripción: Archivo donde se guardan plantillas de función

#include <iostream>
#include <limits>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

/**
 * @brief Plantilla de función que se encarga de Capturar un dato de forma segura
 * @tparam tipo Parametro del tipo de valor qeu se ingresará
 * @param n Variable que se leerá
 * @param mensaje Mensaje personalizado para la captura del valor, en caso de omitirse no se escribirá nada
 */
template <typename tipo>
void CapturaSegura(tipo &n, const char mensaje [] /* = "" */)
{
    while(true){
        cout << mensaje;
        cin >> n;

        if(cin.bad()){
            cout << "Ocurri\242 un error irrecuperable en el flujo de entrada" << endl;
            system("pause");
            exit(1);
        }
        if(cin.fail()){
            cout << "Error: no es un n\243mero. Introduzca de nuevo..." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<int>::max(), '\n');
            continue;
        }
        break;
    }
}

