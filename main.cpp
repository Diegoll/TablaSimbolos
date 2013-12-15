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
    
    printf("crear tabla 1 \n");
    TablaSimbolos ts1 = newTablaSimbolos();
    printf("\ncrear tabla 2 \n");
    TablaSimbolos ts2 = newTablaSimbolos();

    printf("\ncrear nodo 1 \n");
    TSNodo n1 = nuevaEntrada(variable,"contador",tint,0,10);
    mostrarNodo(n1);
    printf("\ncrear nodo 2 \n");
    TSNodo n2 = nuevaEntrada(variable,"contador",tint,0,11);
    mostrarNodo(n2);
    printf("\ncrear nodo 3 \n");
    TSNodo n3 = nuevaEntrada(variable,"cadena1",tchar,0,15);
    mostrarNodo(n3);
    printf("\ncrear nodo 4 (marca) \n");
    TSNodo n4 = nuevaEntrada(marca,"marca1",unknown,0,20);
    mostrarNodo(n4);
    
    printf("\n\nMete nodos n1 n3 n4 n2 en tabla 1\n");
    addNodo(&ts1,n1);
    addNodo(&ts1,n3);
    addNodo(&ts1,n4);
    addNodo(&ts1,n2);
    
    printf("\n\nMostrar tabla 1\n");
    mostrarTabla(ts1);
    printf("\n\nMostrar tabla 2\n");
    mostrarTabla(ts2);
    printf("\nt1 esta vacia? %d\n",isEmpty(ts1));
    printf("\nt2 esta vacia? %d\n",isEmpty(ts2));
    
    printf("\n Existe nodo cadena1 en t1? pos %d\n",existeNodo(ts1,"cadena1"));
    printf("\n Existe nodo contador en t1? pos %d\n",existeNodo(ts1,"contador"));
    printf("\n Existe nodo cadena1 en t2? pos %d\n",existeNodo(ts2,"cadena1"));
    
    printf("\n\nBorrar t1 hasta marca\n");
    deleteBloque(&ts1);
    printf("\n\nMostrar tabla 1\n");
    mostrarTabla(ts1);

    

    return 0;
}

