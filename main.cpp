/* 
 * File:   main.cpp
 * Author: Marci
 *
 * Created on 13 de diciembre de 2013, 20:12
 */

#include <cstdlib>
#include "TablaSimbolos.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    //para probar las funciones hacemos 3 nodos (2 de ellos iguales))
    //los mostramos y los metemos en la tabla de simbolos si son diferentes
    
    TSNodo n1 = nuevaEntrada(variable,"contador",tint,0,10);
    TSNodo n2 = nuevaEntrada(variable,"contador",tint,0,11);
    TSNodo n3 = nuevaEntrada(variable,"cadena1",tchar,0,15);
    
    mostrarNodo(n1);
    mostrarNodo(n2);
    mostrarNodo(n3);

    return 0;
}

