// Nombre:
// Autor: Marco Antonio Guerrero Vasquez
// Fecha:
// Descripción:

#ifndef UTILERIA_H_INCLUDED
#define UTILERIA_H_INCLUDED

/**
 * @brief Plantilla de función que se encarga de Capturar un dato de forma segura
 * @tparam tipo Parametro del tipo de valor qeu se ingresará
 * @param n Variable que se leerá
 * @param mensaje Mensaje personalizado para la captura del valor, en caso de omitirse no se escribirá nada
 */
template <typename tipo>
void CapturaSegura(tipo &n, const char mensaje [] = "");



#include "Utileria.tpp"

#endif
