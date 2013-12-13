/* 
 * File:   TablaSimbolos.h
 * Author: Marci
 *
 * Created on 13 de diciembre de 2013, 20:13
 */

#ifndef TABLASIMBOLOS_H
#define	TABLASIMBOLOS_H

#ifdef	__cplusplus
extern "C" {
#endif



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Tipo de dato de las entradas para cada entrada de la tabla
 */
typedef enum {
    marca,      //La entrada es el principio de un bloque
    funcion,    //La entrada es una función
    variable,   //La entrada es una variable local
    constante,  //La entrada es una constante
    tipo_person,        //La entrada es un tipo personalizado
    parametro_formal    //parametro_formal de un procedure o funcion de una entrada anterior de la tabla
} TEntrada;


/**
 * Tipos de datos disponibles en nuestro lenguaje para el caso en que las
 * entradas se refieran a funciones, variables o parametros
 */
typedef enum {
    tstring, tint, tchar, tfloat, tboolean, tstack, not_assigned, unknown
}TDato;

/**
 * Estructura de cada nodo de la pila
 */
struct entradas {
	TEntrada entrada;	//tipo de la entrada
	char nombre[100];		//identificador de la entrada, si es una marca es nulo
	TDato tipo;		//tipo de dato al que hace referencia la entrada en caso de que las entradas se refieran a funciones, variables o parametros
	int num_param;			//numero de parametros de las funciones, si no es una funcion es -1
	int linea;				//linea donde se declara o se usa por primera vez
};
typedef struct entradas TSNodo;


/**
 * Estructura de la pila
 */
struct pila {
	TSNodo tabla[1000];
	int tam_log;
	int tam;
};
typedef struct pila TablaSimbolos;


///////////////////////////////////////////     Metodos sobre los nodos

TSNodo nuevaEntrada(TEntrada entrada, char *nombre, TDato Dato, int parametros, int linea);
char* getNombreNodo(TSNodo n);
TEntrada getTipoNodo(TSNodo n);
TDato getTipoDatoNodo(TSNodo n);
int getNParNodo(TSNodo n);
int getLineaNodo(TSNodo n);
char* getNombreTipoNodo(TSNodo n);
char* getNombreDatoNodo(TSNodo n);
char* getNombreTipoDatoNodo(TSNodo n);
int compararNodos(TSNodo n1, TSNodo n2);
void asignarTipoDatoNodo(TSNodo *n, TDato tipo);
void incrementarNumParNodo(TSNodo *n);
void borrarNodo(TSNodo *n);
void mostrarNodo(TSNodo);


/////////////////////////////////////////////////


/////////////////////////////////////////////     Métodos sobre la Tabla 
TablaSimbolos newTablaSimbolos();
void addNodo(TablaSimbolos TS, TSNodo n);
void deleteNodo(TablaSimbolos *TS);
void deleteBloque(TablaSimbolos *TS);
void deleteTS(TablaSimbolos *TS);
TSNodo *getNodo(TablaSimbolos TS);
TSNodo comprobarInsercion(TablaSimbolos TS, char *nombre, int nres);
TSNodo existeNodo(TablaSimbolos TS, char *nombre);


void tablaSimbolos_mete(TablaSimbolos *p, TipoEntrada entrada, char *nombre, TipoDato tipoDato, int parametros, int linea, char *resultado);
Tentrada tablaSimbolos_saca(TablaSimbolos *p);
int tablaSimbolos_vacia(TablaSimbolos p);
///////////////////////////////////////////


/**
 * Otros metodos publicos auxiliares
 */
int existeIDEnAmbito(TablaSimbolos t, char *nombreIdentificador);
int esPalabraReservada (char *nombreIdentificador);
Tentrada* buscaEntradaTPCons(TablaSimbolos t, char *nombreIdentificador);
void muestraTabla(TablaSimbolos t);
//void comprobarLlamadaFuncion(TablaSimbolos *t);

//void modificaNParametros(TablaSimbolos *t, char *nombre, int n);

/////////////////////////////////

#ifdef	__cplusplus
}
#endif

#endif	/* TABLASIMBOLOS_H */

