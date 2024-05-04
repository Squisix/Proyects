#include <string.h>
#include <iostream>
#include <ctype.h>
#include "Expresion.h"
Expresion::Expresion():valida(false){
    infija[0] = '\0';
    posfija[0] = '\0';
}

Expresion::Expresion(char expresion[TAM]):valida(false){
    strcpy(infija,expresion);
    Validar();
    if(valida) InfijoToPosfijo();
    std::cout << valida << std::endl;
    std::cout  << infija << std::endl;
    std::cout << std::endl << posfija;
}

void Expresion::Validar(){


    LinkedDataStack<char> corchetes;
    bool hayNumero = false, hayCorcheteCerrado = false, hayOperador = false;
    unsigned nPuntos = 0, nSimbolosNegativos = 0;

    valida = true;
    for(int i = 0; infija[i]!= '\0'; ++i){

        if(isdigit(infija[i])){
            if(hayCorcheteCerrado){
                valida = false;
                break;
            }else{
                hayNumero = true;
                hayOperador = false;
                nSimbolosNegativos = 0;
            }
        }

        if(infija[i]== '.') {
                ++nPuntos;
            if(nPuntos > 1){
                valida = false;
                break;
            }
        }

        if(esCorcheteAbierto(infija[i])) corchetes.Push(infija[i]);

        if(esCorcheteCerrado(infija[i])){
            hayCorcheteCerrado = true;
            if(corchetes.Empty()){
                valida = false;
                break;
            }
            if(!hayNumero){
                valida = false;
                break;
            }
            if(hayOperador){
                valida = false;
                break;
            }
                switch(infija[i]){
                    case ']':{
                        if(corchetes.Top()=='['){
                            corchetes.Pop();
                            nPuntos = 0;
                        }else break;
                        break;
                    }
                    case '}':{
                        if(corchetes.Top()=='{') {
                            corchetes.Pop();
                            nPuntos = 0;
                        }else break;
                        break;
                    }
                    case ')':{
                        if(corchetes.Top()=='(') {
                            corchetes.Pop();
                        nPuntos = 0;
                        }else break;
                        break;
                    }
                }
            }

        if(esOperador(infija[i])){
            hayOperador = true;
            switch(infija[i]){
                case '+':
                case '*':
                case '/':
                case '^':{
                    if(hayNumero) {
                        hayNumero = false;
                        hayCorcheteCerrado = false;
                        nPuntos = 0;
                    }else{
                        valida = false;
                        break;
                    }
                    break;

                }
                case '-':{
                    ++nSimbolosNegativos;
                    if(hayNumero){
                        hayNumero = false;
                        hayCorcheteCerrado = false;
                        nPuntos = 0;
                    }
                    if(nSimbolosNegativos > 1){
                        valida = false;
                        break;
                    }
                    break;
                }

           }
        }



    }
    if(corchetes.Size() != 0) valida = false;
    if(hayOperador) valida = false;
}

bool Expresion::esOperador(char c){
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


bool Expresion::esCorcheteAbierto(char c){
    switch(c){
        case '{':
        case '[':
        case '(':
            return true;
        default:
            return false;
    }
}

bool Expresion::esCorcheteCerrado(char c){
    switch(c){
        case '}':
        case ']':
        case ')':
            return true;
        default:
            return false;
    }
}

unsigned Expresion::NivelDePresedenciaOp(char op){
    switch(op){
        case '(':
        case '[':
        case '{':{
            return 0;
            break;
        }

        case '+':
        case '-':{
            return 1;
            break;
        }
        case '*':
        case '/':{
            return 2;
            break;
        }
        case '^':{
            return 3;
            break;
        }
    }
    return 0;
}

void Expresion::InfijoToPosfijo(){
    char caracteres[TAM];
    int aux = 0;
    LinkedDataStack<char> simbolos;
    for(int i = 0; infija[i] != '\0'; ++i){

        if(isdigit(infija[i]) || infija[i] == '.'){
            caracteres[aux] = infija[i];
        }

        if(esCorcheteAbierto(infija[i])){
            simbolos.Push(infija[i]);
            simbolos.Print();
        }

        if(esOperador(infija[i])){
            caracteres[aux] = ',';
            if(simbolos.Empty()){
                simbolos.Push(infija[i]);
            }else if(!simbolos.Empty()){
                if(NivelDePresedenciaOp(infija[i]) < NivelDePresedenciaOp(simbolos.Top())){
                    caracteres[aux] = simbolos.Top();
                    simbolos.Pop();
                    simbolos.Push(infija[i]);
                }
                if(NivelDePresedenciaOp(infija[i]) > NivelDePresedenciaOp(simbolos.Top())){
                    simbolos.Push(infija[i]);
                }

                if(NivelDePresedenciaOp(infija[i]) == NivelDePresedenciaOp(simbolos.Top())){
                   if(infija[i] == '^'){
                        simbolos.Push(infija[i]);
                    }else {
                        caracteres[aux] = simbolos.Top();
                        simbolos.Pop();
                        simbolos.Push(infija[i]);
                    }
                }
            }
        }

        if(esCorcheteCerrado(infija[i])){
            caracteres[aux] = ',';
            while(!esCorcheteAbierto(simbolos.Top())){
                caracteres[aux] = simbolos.Top();
                ++aux;
                simbolos.Pop();
            }
        }
        ++aux;

    }
    caracteres[aux] = '\0';

    strcpy(posfija,caracteres);
}
