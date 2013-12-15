/* 
 * File:   TablaSimbolos.c
 * Author: Marci
 *
 * Created on 13 de diciembre de 2013, 20:13
 */

#include <stdio.h>
#include <stdlib.h> 
#include "TablaSimbolos.h"

/*
 * 
 */

char* getNombreTipoNodo(TSNodo n){
    switch (n->entrada){
        case marca: return "marca";
        case funcion: return "funcion";
        case variable: return "variable";
        case tipo_person: return "tipo_person";
        case parametro_formal: return "parametro_formal";
    }
}
char* getNombreDatoNodo(TSNodo n){
    switch(n->tipo){
        case tstring: return "tstring";
        case tint: return "tint";
        case tchar: return "tchar";
        case tfloat: return "tfloat";
        case tboolean: return "tboolean";
        case tstack: return "tstack";
        case not_assigned: return "not_assigned";
        case unknown: return "unknown";
    }
}
char* getNombreTipoDatoNodo(TSNodo n){

}
int main(int argc, char** argv) {
    
    return (EXIT_SUCCESS);
}

