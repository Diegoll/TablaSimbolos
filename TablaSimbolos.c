/* 
 * File:   TablaSimbolos.c
 * Author: Marci
 *
 * Created on 13 de diciembre de 2013, 20:13
 */

#include <stdio.h>
#include <stdlib.h>

#include "TablaSimbolos.h"

/*//////////////////////////////////////////
 * Funciones de los nodos
 */////////////////////////////////////////

TSNodo nuevaEntrada(TEntrada entrada, char *nombre, TDato Dato, int parametros, int linea)
{
    TSNodo *n=(TSNodo *) malloc (sizeof(TSNodo));
    n->entrada=entrada;
    strcpy(n->nombre,nombre);
    n->tipo=Dato;
    n->num_param=parametros;
    n->linea=linea;
    
    return *n;
};

char* getNombreNodo(TSNodo *n){ return n->nombre; };

TEntrada getTipoNodo(TSNodo n){ return n.entrada; };

TDato getTipoDatoNodo(TSNodo n) {return n.tipo;};

//int getNParNodo(TSNodo n);

int getLineaNodo(TSNodo n) {return n.linea;};

//char* getNombreTipoNodo(TSNodo n);

//char* getNombreDatoNodo(TSNodo n);

//char* getNombreTipoDatoNodo(TSNodo n);

int compararNodos(TSNodo n1, TSNodo n2)
{
    if((n1.entrada==n2.entrada)&&(n1.num_param=n2.num_param)&&(n1.tipo==n2.tipo)&&(strcmp(n1.nombre,n2.nombre)==0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
};

void asignarTipoDatoNodo(TSNodo *n, TDato tipo) {n->tipo=tipo;};

//void incrementarNumParNodo(TSNodo *n);

void borrarNodo(TSNodo *n){free(n);};

void mostrarNodo(TSNodo n)
{
    printf("linea:%d  tipoE:%d %s \t %d tipoD:%d \n",n.linea,n.entrada,n.nombre,n.num_param, n.tipo);
    fflush(stdout);
};


/*//////////////////////////////////////////////////7
 // Funciones de la tabla de simbolos
 */