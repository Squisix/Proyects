#ifndef EXPRESION_H_INCLUDED
#define EXPRESION_H_INCLUDED

#include "LinkedDataStack.h"

#define TAM 100
class Expresion{
    public:
    Expresion();
    explicit Expresion(char expresion[TAM]);
    void Validar();




    private:
    char infija[TAM];
    bool valida;
    char posfija[TAM];


    bool esOperador(char c);
    bool esCorcheteAbierto(char c);
    bool esCorcheteCerrado(char c);
    unsigned NivelDePresedenciaOp(char op);
    void InfijoToPosfijo();
};


#endif // EXPRESION_H_INCLUDED
