%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TablaSimbolos.h"
int linea_actual = 0; 

void yyerror (char *msg)
{
fprintf(stderr, "\n");
fprintf(stderr,"Error de sintaxis en la linea: %d",linea_actual);
}
%}


%start prog
%token PDE ASI MAIN PYC ID NUM PIZ CAD FOR IF LIB MODC MODD MODS ELSE WHILE INT CHAR STRING FLOAT BOOLEAN STACK IB FB INCRE DECRE
%token INC DEF TDEF PRINTF SCANF STRCAT STRNCAT STRLEN STRCMP STRCPY STRCHR STREXT DISTINTO 
%token MENIGUAL MENOR MAYIGUAL MAYOR COMP PTO ALM COMA AMPER TRUE FALSE NOT 

%left MENOR MAYOR MENIGUAL MAYIGUAL DISTINTO NOT PIZ PDE COMP ASI
%left SUM RES
%left MUL DIV 
%left UMINUS

%%
/* Secci�n de producciones que definen la gram�tica */

prog :  dec1 dec2 | dec2
;
dec1:  incs defs| incs | defs 
;
dec2 : tipos vars funcs main | tipos vars main | tipos funcs main | vars funcs main | tipos main | vars main | funcs main | main
;
incs : incs inc | inc
;
inc : INC MENOR LIB MAYOR
;
defs : defs def | def
;
def : DEF ID expresion
;
tipos : TDEF tipo ID PYC | TDEF stack ID PYC
;
vars : vars var | var
;
id_exp :  ID  ASI expresion | ID
;
var :  tipo id_exps PYC | stack id_exps PYC
;
id_exps : id_exps COMA id_exp | id_exp
;
funcs : funcs func | func
;
func : tipo ID PIZ args PDE{
	tdev=unknown;
	nfallos=0;
	tam = getTamTabla(ts);
	i=tam-$4.num_param;
	while(i<tam){
		ent=getNodoxPosicion(ts,i);
		if(ent->TDato!=error){
			j=i+1;
			while(j<tam){
				entaux=getNodoxPosicion(ts, j);
				if(entaux->TDato!=error){
					if(strcmp(ent->nombre, entaux->nombre)==0){
						printf("\nError: linea %d: ya existe un parametro con este mismo nombre: %s, funcion: %s", $2.linea, entaux->nombre, $2.nombre);
						setTipoDatoxPos(ts, j, error, not_assigned);
					}
				}
				j++;
			}
		}
		i++;
	}

	ent=comprobarInsercion(ts, $2.nombre, ncons+nres);
	if(ent==NULL){
		ent=checkNodoxNombre(ts, $1.nombre, ncons, nres);
		if(ent!=NULL){
			ent=newNodo($2.nombre, funcion, ent->TDato, $4.num_param, ent->TPila);
			addNodo(ts, ent);
			ent=newNodo("{", marca, unknown, 0, not_assigned);
			addNodo(ts, ent);
			$$.control=0;
		}else{
			if($1.TDato!=unknown){
				ent=newNodo($2.nombre, funcion, $1.TDato, $4.num_param, not_assigned);
				addNodo(ts, ent);
				ent=newNodo("{", marca, unknown, 0, not_assigned);
				addNodo(ts, ent);
				$$.control=0;
			}else{
				printf("\nError: linea %d: no existe nigun tipo definido con este nombre: %s, funcion: %s", $2.linea, $1.nombre, $2.nombre);
				ent=newNodo($2.nombre, funcion, error, $4.num_param, not_assigned);
				addNodo(ts, ent);
				ent=newNodo("{", marca, unknown, 0, not_assigned);
				addNodo(ts, ent);
				$$.control=1;
			}
		}
	}else{
		printf("\nError: linea %d: ya existe una variable declarada con este nombre: %s", $2.linea, $2.nombre);
		ent=newNodo($2.nombre, funcion, error, $4.num_param, not_assigned);
		addNodo(ts, ent);
		ent=newNodo("{", marca, unknown, 0, not_assigned);
		addNodo(ts, ent);
		$$.control=1;
		nfallos=1;
	}
}
funcs cuerpo {
	if(tdev==unknown){
		printf("\nError: linea %d: falta el devuelve en la funcion %s.", $2.linea, $2.nombre);
	}else{
		ent=checkDeclaracion(ts, $2.nombre);
		if(ent->TDato!=error){
			if(tdev!=ent->TDato){
				if(ent->TDato==tfloat && (tdev==tint || tdev==tfloat)){

				}else{
					printf("\nError: linea %d: el tipo del devuelve no coincide con el de la funcion %s.", $2.linea, $2.nombre);
				}
			}else{
				if(ent->TDato==tstack){
					if(ent->TPila!=tpiladev){
						printf("\nError: linea %d: tipo tda incompatibles al devolver el dato en la funcion %s", $2.linea, $2.nombre);
					}
				}
			}
		}
		
	}
	deleteBloque(&ts);
	ent=getNodoxPosicion(ts, getTamTabla(ts)-1);
	if(ent->TDato==error){
		deleteFuncionIncorrecta(&ts);
	}

}
|tipo ID PIZ PDE	{
    tdes = unknown;
    ent = comprobarInsercion(ts,$2.nombre, ncons+nres);
    if(ent == NULL){
        ent = checkNombrexNodo(ts, $1.nombre, ncons, nres);
        if(ent!=NULL){
            ent=NewNodo($2.nombre, funcion, ent->TDato, 0, ent->TPila);
            addNodo(ts,ent);
            ent = newNodo("{", marca, unknown, 0, not_assigned);
            addNodo(ts, ent);
            $$.control=0;
        }else{
        	if($1.TDato!=unknown){
        		ent=newNodo($2.nombre, funcion, $1.TDato, 0, not_assigned);
        		addNodo(ts, ent);
        		ent=newNodo("{", marca,unknown, 0,not_assigned);
        		addNodo(ts, ent);
        		$$.control=0;
        	}else{
        		printf("\nError: linea %d: el tipo %s no se encuentra definido", $2.linea, $1.nombre);
        		ent=newNodo($5.nombre, funcion, error, 0, not_assigned);
        		addNodo(ts, ent);
        		ent= newNodo("{", marca, unknown, 0, not_assigned);
        		addNodo(ts, ent);
        		$$.control=1;
        	}
        }
    }else{
    	printf("\nError: linea %d: ya existe una variable declarada con este nombre: %s", $5.linea, $5.nombre);
    	ent=newNodo($5.nombre, funcion, error, 0, not_assigned);
    	addNodo(ts,ent);
    	ent=newNodo("{", marca, unknown, 0, not_assigned);
    	addNodo(ts, ent);
    	$$.control=1;
    }
}funcs cuerpo {
	if(tdev==unknown){
		printf("\nError: linea %d: la función %s no devuelve nada.", $2.linea, $2.nombre);
	}else{
		ent=checkDeclaracion(ts, $2.nombre);
		if(ent->TDato!=error){
			if(tdev!=ent->TDato){
				if(ent->TDato==tfloat && (tdev==tint || tdev==tfloat)){

				}else{
					printf("\nError: linea %d: el tipo devuelto no coincide con el de la funcion %s", $2.linea, $2.nombre);
				}
			}else{
				if(ent->TDato==tstack){
					if(ent->TPila!=tpiladev){
						printf("\nError: linea %d: tipo tda incompatible al devolver el dato de la función %S", $2.linea, $2.nombre);
					}
				}
			}
		}
	}
	deleteNodo(&ts);
	ent=getNodoxPosicion(ts, getTamTabla(ts)-1);
	if(ent->TDato==error){
		deleteFuncionIncorrecta(&ts);
	}
	
}|  STACK MENOR tipo MAYOR ID PIZ args PDE {
		tdev=unknown;
		tpiladev=not_assigned;
		tope=getTopeTS(ts);
		i=tope-$7.num_param;
		while(i<tope){
			ent=getEntradaPos(ts, i);
			if(ent->TDato!=error){
				j=i+1;
				while(j<tope){
					entaux=getEntradaPos(ts, j);
					if(entaux->TDato!=error){
						if(strcmp(ent->nombre, entaux->nombre)==0){
							printf("\nError: linea %d: ya existe un parametro con este mismo nombre: %s", $5.linea, entaux->nombre);
							setTipoDatoPos(ts, j, error, not_assigned);
						}
					}
					j++;
				}
			}
			i++;
		}
		ent=checkParaInsertar(ts, $5.nombre, ncons+nres);
		if(ent==NULL){
			ent=checkNombreDefTipo(ts, $3.nombre, ncons, nres);
			if(ent!=NULL){
				if(ent->TDato!=pila){
					ent=newNodo($5.nombre, funcion, pila, $7.num_param, ent->TDato);
					addNodo(ts, ent);
					ent=newNodo("{", marca, unknown, 0, not_assigned);
					addNodo(ts, ent);
					$$.control=0;
				}else{
					printf("\nError: linea %d: no se permite el encadenamiento de tda's en las funciones.", $5.linea);
					ent=newNodo($5.nombre, funcion, error, $7.num_param, ent->TDato);
					addNodo(ts, ent);
					ent=newNodo("{", marca, unknown, 0, not_assigned);
					addNodo(ts, ent);
					$$.control=1;
				}
			}else{
				if($3.TDato!=unknown){
					ent=newNodo($5.nombre, funcion, pila, $7.num_param, $3.TDato);
					addNodo(ts, ent);
					ent=newNodo("{", marca, unknown, 0, not_assigned);
					addNodo(ts, ent);
					$$.control=0;
				}else{
					printf("\nError: linea %d: no existe nigun tipo definido con este nombre: %s", $5.linea, $3.nombre);
					ent=newNodo($5.nombre, funcion, error, $7.num_param, $3.TDato);
					addNodo(ts, ent);
					ent=newNodo("{", marca, unknown, 0, not_assigned);
					addNodo(ts, ent);
					$$.control=1;
				}
			}
		}else{
			printf("\nError: linea %d: ya existe una variable declarada con este nombre: %s", $5.linea, $5.nombre);
			ent=newNodo($5.nombre, funcion, error, $7.num_param, $3.TDato);
			addNodo(ts, ent);
			ent=newNodo("{", marca, unknown, 0, not_assigned);
			addNodo(ts, ent);
			$$.control=1;
		}
	}
	funcs cuerpo {
		if(tdev==unknown){
			printf("\nError: linea %d: falta el devuelve en la funcion %s.", $5.linea, $5.nombre);
		}else{
			if(tdev==pila){
				ent=checkConsulta(ts, $5.nombre);
				if(ent->tPila!=tpiladev){
					printf("\nError: linea %d: tipo tda incompatibles al devolver el dato en la funcion %s", $5.linea, $5.nombre);
				}
			}else{
				printf("\nError: linea %d: tipo incompatible en el devuelve de la funcion %s", $5.linea, $5.nombre);
			}
		}
		//si pasa el bloque "todo ha ido bien", borramos el bloque e insertamos el nombre de la función
		deleteBloque(&ts);
		ent=getEntradaPos(ts, getTopeTS(ts)-1);
		if(ent->TDato==error){
			deleteFuncionErronea(&ts);
		}
	}
	| STACK MENOR tipo MAYOR ID PIZ PDE {
		tdev=unknown;
		tpiladev=not_assigned;
		ent=comprobarInsercion(ts, $5.nombre, ncons+nres);
		if(ent==NULL){
			ent=checkNombrexNodo(ts, $3.nombre, ncons, nres);
			if(ent!=NULL){
				if(ent->TDato!=pila){
					ent=newNodo($5.nombre, funcion, pila, 0, ent->TDato);
					addNodo(ts, ent);
					ent=newNodo("{", marca, unknown, 0, not_assigned);
					addNodo(ts, ent);
					$$.control=0;
				}else{
					printf("\nError: linea %d: no se permite el encadenamiento de tda's en las funciones.", $5.linea);
					ent=newNodo($5.nombre, funcion, error, 0, ent->TDato);
					addNodo(ts, ent);
					ent=newNodo("{", marca, unknown, 0, not_assigned);
					addNodo(ts, ent);
					$$.control=1;
				}
			}else{
				if($3.TDato!=unknown){
					ent=newNodo($5.nombre, funcion, pila, 0, $3.TDato);
					addNodo(ts, ent);
					ent=newNodo("{", marca, unknown, 0, not_assigned);
					addNodo(ts, ent);
					$$.control=0;
				}else{
					printf("\nError: linea %d: no existe nigun tipo definido con este nombre: %s", $5.linea, $3.nombre);
					ent=newNodo($5.nombre, funcion, error, 0, $3.TDato);
					addNodo(ts, ent);
					ent=newNodo("{", marca, unknown, 0, not_assigned);
					addNodo(ts, ent);
					$$.control=1;
				}
			}
		}else{
			printf("\nError: linea %d: ya existe una variable declarada con este nombre: %s", $5.linea, $5.nombre);
			ent=newNodo($5.nombre, funcion, error, 0, $3.TDato);
			addNodo(ts, ent);
			ent=newNodo("{", marca, unknown, 0, not_assigned);
			addNodo(ts, ent);
			$$.control=1;
		}
	}
	funcs cuerpo {
		if(tdev==unknown){
			printf("\nError: linea %d: falta el devuelve en la funcion %s.", $5.linea, $5.nombre);
		}else{
			if(tdev==pila){
				ent=checkConsulta(ts, $5.nombre);
				if(ent->tPila!=tpiladev){
					printf("\nError: linea %d: tipo tda incompatibles al devolver el dato en la funcion %s", $5.linea, $5.nombre);
				}
			}else{
				printf("\nError: linea %d: tipo incompatible en el devuelve de la funcion %s", $5.linea, $5.nombre);
			}
		}
		deleteBloque(&ts);
		ent=getEntradaPos(ts, getTopeTS(ts)-1);
		if(ent->TDato==error){
			deleteFuncionErronea(&ts);
		}
	}
	;
args: COMA arg {$$.num_param=$1.num_param+1;}
	| arg {$$.num_param=1;}
;
arg: tipo ID{
	ent=checkNombrexNodo(ts,$1.nombre, ncons, nres);
	if(ent==NULL){
		if($1.TDato==unknown){
			printf("\nError: linea %d: no se ha declarado el tipo anteriormente: %s",$2.linea, $1.nombre);
			ent=newNodo($2.nombre, parametro_formal, error, 0, not_assigned);
			addNodo(ts, ent);
		}else{
			ent=newNodo($2.nombre, parametro_formal, $1.TDato, 0, not_assigned);
			addNodo(ts, ent);
		}
	}else{
		ent=newNodo($2.nombre,parametro_formal, ent->TDato, 0, ent->TPila);
		addNodo(ts,ent);
	}
| STACK MENOR tipo MAYOR ID {
	ent=checkNombreDefTipo(ts, $3.nombre, ncons, nres);
	if(ent==NULL){
		if($3.TDato==unknown){
			printf("\nError: linea %d: no se ha declarado el tipo anteriormente: %s", $5.linea, $3.nombre);
			ent=newNodo($5.nombre, parametro_formal, error, 0, not_assigned);
			addNodo(ts, ent);
		}else{
			ent=newNodo($5.nombre, parametro_formal, tstack, 0, $3.TDato);
			addNodo(ts, ent);
		}
	}else{
		if(ent->TDato!=tstack){
			ent=NewNodo($2.nombre, parametro_formal, tstack, 0, ent->TDato);
			addNodo(ts, ent);
		}else{
			printf("\nError: linea %d: no se permiten pilas encadenadas. Parametro: %s", $5.linea, $5.nombre);
			ent=newNodo($5.nombre, parametro_formal, error, 0, not_assigned);
			addNodo(ts, ent);
		}
	}
}
;
insts: insts inst | inst
;
inst : leer | escribir | if | while | for | expresion PYC | mete
;
tipo : STRING | INT | CHAR | FLOAT | BOOLEAN 
;
stack : STACK MENOR tipo MAYOR
;
cuerpo : IB vars insts FB | IB insts FB | IB vars FB | IB  FB | IB vars funcs insts FB | IB vars funcs FB | IB funcs insts FB | IB funcs FB 
;
asig : ID ASI expresion
;
expresion :  expresion SUM expresion | expresion RES expresion | RES expresion %prec UMINUS| expresion MUL expresion | expresion DIV expresion | expresion MAYOR expresion | expresion MENOR expresion | expresion MAYIGUAL expresion | expresion MENIGUAL expresion | expresion DISTINTO expresion | expresion COMP expresion | TRUE | FALSE | NUM | llamada_funcion | PIZ expresion PDE | NOT expresion | ID | concatenar|longitud |comparar|copiar|concatenarn|buscar|extraer|CAD| incremento | decremento |asig | saca | longitud_pila  
;
leer : SCANF PIZ variables PDE PYC 
;
variables : variables COMA AMPER ID | modificador
;
modificador : MODC | MODD
;
escribir : PRINTF PIZ contenido PDE PYC 
;
contenido : contenido COMA expresion | CAD
;
if : IF  PIZ expresion PDE  bloque ELSE bloque | IF  PIZ expresion PDE bloque
;
while : WHILE  PIZ expresion PDE  bloque
;
for : FOR PIZ PYC PYC PDE bloque | FOR PIZ expresiones PYC PYC PDE bloque | FOR PIZ PYC expresion PYC PDE bloque | FOR PIZ PYC PYC expresiones PDE bloque | FOR PIZ expresiones PYC expresion PYC PDE bloque | FOR PIZ expresiones PYC PYC expresiones PDE bloque | FOR PIZ PYC expresion PYC expresiones PDE bloque | FOR PIZ expresiones PYC expresion PYC expresiones PDE bloque
;
expresiones : expresiones COMA expresion | expresion
;
incremento :  ID INCRE | INCRE ID
;
decremento : ID DECRE | DECRE ID
;
main : INT MAIN PIZ PDE cuerpo
;
bloque : IB insts FB | inst  | PYC
;
llamada_funcion : ID PIZ PDE | ID PIZ expresiones PDE
;
concatenar : STRCAT PIZ expresion COMA expresion PDE
;
concatenarn : STRNCAT PIZ expresion COMA expresion COMA expresion PDE
;
longitud :  STRLEN PIZ expresion PDE
;
comparar : STRCMP PIZ expresion COMA expresion PDE
;
copiar : STRCPY PIZ expresion COMA expresion PDE
;
buscar : STRCHR PIZ expresion COMA expresion PDE
;
extraer : STREXT PIZ expresion COMA expresion PDE
;
pila_mete : PUSH PIZ expresion COMA expresion PDE
;
pila_saca : POP PIZ expresion PDE
;
longitud_pila : SIZE PIZ expresion PDE
;
pila_dest : DELETE PIZ ID PDE
;
%%
/* Aqu� incluimos el fichero generado por el Flex, que implementa la funci�n yylex() */
#include "lexyy.c"