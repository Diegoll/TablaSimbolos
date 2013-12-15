/* 
 * File:   TablaSimbolos.c
 * Author: Marci
 *
 * Created on 13 de diciembre de 2013, 20:13
 */

#include <stdio.h>
#include <stdlib.h> 
#include "TablaSimbolos.h"

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

TablaSimbolos newTablaSimbolos()
{
    TablaSimbolos *ts=(TablaSimbolos *) malloc (sizeof(TablaSimbolos));
    ts->tam=1000;
    ts->tam_log=0;
    
    return *ts;
};
void addNodo(TablaSimbolos *TS, TSNodo n)
{
    if(TS->tam_log<TS->tam)
    {
        TS->tabla[TS->tam_log]=n;
        TS->tam_log++;
    }
};

/*void deleteNodo(TablaSimbolos *TS)
{
 no esta hecho porque si eliminas un nodo hay que correr toa la pila pa bajo ese hueco
};
*/
void deleteBloque(TablaSimbolos *TS)
{
    int i, nohecho;
    nohecho=1;
    i=TS->tam_log-1;
    
    while((nohecho)&&(i>=0))
    {
        if(TS->tabla[i].entrada==marca)
        {
            nohecho=0;
        }
        TS->tam_log--;
        i--;
    }
};

void deleteTS(TablaSimbolos *TS){ free(TS);};

TSNodo *getNodo(TablaSimbolos *TS)
{
    //devuelve el ULTIMO nodo sin eliminarlo(es una pila)
    if(TS->tam_log>=0)
    {
        return &TS->tabla[TS->tam_log];
    }
};

//TSNodo comprobarInsercion(TablaSimbolos TS, char *nombre, int nres);
//ni idea de lo que hace eso. No es lo mismo que la de abajo?

int existeNodo(TablaSimbolos TS, char *nombre)
{
    //devolvia TSnodo pero venia muy mal. Ahora devuelve -1, o la posicion en la tabla simbolos
    
    int i, nohecho;
    nohecho=1;i=0;
    
    while((nohecho)&&(i<=TS.tam_log))
    {
        if(strcmp(TS.tabla[i].nombre, nombre)==0)
        {
            nohecho=0;
            return i;
        }
        i++;
    }
    return -1;
};

void tsMete(TablaSimbolos *TS, TSNodo n, char *resultado)
{
    //falta utilizar el argumento resultado que no se pa que sirve
    //que diferencia tiene esta funcion con addNodo????????
    if(TS->tam_log<TS->tam)
    {
        TS->tabla[TS->tam_log]=n;
        TS->tam_log++;
    }
};

TSNodo tsSaca(TablaSimbolos *TS){
    //saca el ULTIMO nodo, igual que getNodo pero lo elimina
    if(TS->tam_log>=0)
    {
        return TS->tabla[TS->tam_log];
        TS->tam_log--;
    }
};

int isEmpty(TablaSimbolos TS)
{
    if(TS.tam_log==0){
        return 1;
    }else{
        return 0;
    }
};

void mostrarTabla(TablaSimbolos TS){
    int i=0;
    for(i=0;i<TS.tam_log;i++)
    {
        mostrarNodo(TS.tabla[i]);
    }
    printf("Tam logico=%d", TS.tam_log);
}
