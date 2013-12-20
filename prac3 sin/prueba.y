%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TablaSimbolos.h"
int linea_actual = 0; 

TablaSimbolos ts;
TSNodo nodo;
TSNodo nodoaux, nodoaux2, nodoaux3;
TDato tret;
int posicion, posicion2, posicion3, flag, anidamiento;

void yyerror (char *msg)
{
fprintf(stderr, "\n");
fprintf(stderr,"Error de sintaxis en la linea: %d",linea_actual);
}
%}


%start prog
%token PDE ASI MAIN PYC ID NUM PIZ CAD FOR IF LIB MODC MODD MODS ELSE WHILE INT CHAR STRING FLOAT BOOLEAN STACK IB FB INCRE DECRE
%token INC DEF TDEF PRINTF SCANF STRCAT STRNCAT STRLEN STRCMP STRCPY STRCHR STREXT DISTINTO 
%token MENIGUAL MENOR MAYIGUAL MAYOR COMP PTO ALM COMA AMPER TRUE FALSE NOT RET REAL

%left MENOR MAYOR MENIGUAL MAYIGUAL DISTINTO NOT PIZ PDE COMP ASI
%left SUM RES
%left MUL DIV 
%left UMINUS

%%
/* Secci�n de producciones que definen la gram�tica */

prog :  {ts = newTablaSimbolos();} 
	dec1 dec2 {deleteTSimbolos(&ts);}
	| dec2{deleteTSimbolos(&ts);}
;
dec1:  incs const | const | incs 
;
dec2 : tipos vars funcs main | tipos vars main | tipos funcs main | vars funcs main | tipos main | vars main | funcs main | main
;

const : const | cons PYC
;

cons: DEF ID expresion 
	{
		if(existeNodo(ts,$2.nombre)!=-1)
		{
			printf("\nError: linea %d: La constante %s ya existe", $2.linea, $2.nombre);
		}else{
			if($3.error==0)
			{
				nodo=nuevaEntrada(constante, $2.nombre, $3.tipo, 0,  $2.linea, $3.tipopila);
				addNodo(&ts,nodo);
				$$.error=0;
			}else{
				$$.error=1;
			}
			
		}
	}
;

incs : incs inc | inc
;
inc : INC MENOR LIB MAYOR
;
tipos : TDEF tipo ID PYC | TDEF stack ID PYC
;
vars : vars var | var
;
id_exp :  ID  ASI expresion 
		{
			if($3.error==0)
			{
				if(existeNodo(ts,$1.nombre)!=-1)
				{
					printf("\nError: linea %d: La variable %s ya existe", $1.linea, $1.nombre);
				}else{
					if($3.error==0)
					{
						nodo=nuevaEntrada(variable, $1.nombre, not_assigned, 0,  $1.linea, unknown);
						addNodo(&ts,nodo);
						$$.error=0;
					}else{
						$$.error=1;
					}
				}
			}
			else{
				$$.error=1;
			}
	}
	| ID
	{
		if(existeNodo(ts,$1.nombre)!=-1)
		{
			printf("\nError: linea %d: La variable %s ya existe", $1.linea, $1.nombre);
		}else{
			if($3.error==0)
			{
				nodo=nuevaEntrada(variable, $1.nombre, not_assigned, 0,  $1.linea, unknown);
				addNodo(&ts,nodo);
				$$.error=0;
			}else{
				$$.error=1;
			}
		}
	}
;
var :  tipo id_exps PYC 
	{
		asignarTipoDatoNodo(ts.tabla[existeNodo(ts,$1.nombre)], $1.tipo);
		asignarTipoPilaNodo(ts.tabla[existeNodo(ts,$1.nombre)], $1.tipopila);
	}
	| stack id_exps PYC
	{
		asignarTipoDatoNodo(ts.tabla[existeNodo(ts,$1.nombre)], $1.tipo);
		asignarTipoPilaNodo(ts.tabla[existeNodo(ts,$1.nombre)], $1.tipopila);
	}
;
id_exps : id_exps COMA id_exp {anidamiento++;} | id_exp {anidamiento=1;}
;
funcs : funcs func | func
;
func : tipo ID PIZ PDE funcs cuerpo |  tipo ID PIZ tipo ID PDE cuerpo
;
insts: insts inst | inst
;
inst : leer | escribir | if | while | for | expresion PYC | mete
;

tipo : STRING{$$.tipo=tstring; $$.tipopila=tstring;} 
	| INT{$$.tipo=tint; $$.tipopila=tint;} 
	| CHAR{$$.tipo=tchar;$$.tipopila=tchar;} 
	| FLOAT {$$.tipo=tfloat;$$.tipopila=tfloat;}
	| BOOLEAN {$$.tipo=tboolean;$$.tipopila=tboolean;}
;
stack : STACK MENOR tipo MAYOR {$$.tipo=tstack; $$.tipopila=$3.tipopila;}
;
cuerpo : IB vars insts FB | IB insts FB | IB vars FB | IB  FB | IB vars funcs insts FB | IB vars funcs FB | IB funcs insts FB | IB funcs FB 
;
asig : ID ASI expresion
	{
		if($3.error==0)
		{
			if(existeNodoScope(ts,$1.nombre)==-1)
			{
				$$.error=1;
				$$.tipo=unknown;
				printf("\nError: linea %d: La variable %s no esta definida en este bloque", $1.linea, $1.nombre);
			}else{
				nodoaux=ts.tabla[existeNodoScope(ts,$1.nombre)];
				if((nodoaux.tipo==$3.tipo)&&(nodoaux.tipopila==$3.tipopila)
				{
					$$.nombre=$1.nombre;
					$$.error=0;
					$$.tipo=nodoaux.tipo;
					$$.tipopila=nodoaux.tipopila;
					$$.entrada=nodoaux.entrada;
				}else{
					printf("\nError: linea %d: Asignacion de tipos diferentes", $1.linea);
					$$.error=1;
				}
			}
		}else{
			$$.error=1;
		}
	}
;

devuelve :RET PIZ exp PDE PYC
{		
	if($3.error==0)
	{
		$$.error=0
		tret=$3.tipo;
	}else{
		$$.error=1;
	}
}
;

expresion :  expresion SUM expresion 
			{
				if(($1.error!=1)&&($3.error!=1))
				{
					if(($1.tipo==tstack)||($3.tipo==tstack)){
						printf("\nError: linea %d: Una Stack no se puede operar", $1.linea);
						$$.error=1;
					}else{
						if(($1.tipo==tstring)||($3.tipo==tstring)){
							printf("\nError: linea %d: Una String no se puede sumar, utiliza op de cadena", $1.linea);
							$$.error=1;
						}else{
							if(($1.tipo==tchar)||($3.tipo==tchar)){
								printf("\nError: linea %d: Un char no se puede operar", $1.linea);
								$$.error=1;
							}else{
								if(($1.tipo==tboolean)||($3.tipo==tboolean)){
									printf("\nError: linea %d: Un boolean no se puede operar aritmeticamente", $1.linea);
									$$.error=1;
								}else{
									if(($1.tipo==tfloat)||($3.tipo==tfloat)){
										$$.tipo=tfloat;
									}else{
										$$.tipo=tint;
									}
								}
							
							}
						}
					}
				}
			}
		| expresion RES expresion 
			{
				if(($1.error!=1)&&($3.error!=1))
				{
					if(($1.tipo==tstack)||($3.tipo==tstack)){
						printf("\nError: linea %d: Una Stack no se puede operar", $1.linea);
						$$.error=1;
					}else{
						if(($1.tipo==tstring)||($3.tipo==tstring)){
							printf("\nError: linea %d: Una String no se puede sumar, utiliza op de cadena", $1.linea);
							$$.error=1;
						}else{
							if(($1.tipo==tchar)||($3.tipo==tchar)){
								printf("\nError: linea %d: Un char no se puede operar", $1.linea);
								$$.error=1;
							}else{
								if(($1.tipo==tboolean)||($3.tipo==tboolean)){
									printf("\nError: linea %d: Un boolean no se puede operar aritmeticamente", $1.linea);
									$$.error=1;
								}else{
									if(($1.tipo==tfloat)||($3.tipo==tfloat)){
										$$.tipo=tfloat;
									}else{
										$$.tipo=tint;
									}
								}
							
							}
						}
					}
				}
			}
		| RES expresion %prec UMINUS
			{
				if($2.tipo==tint || $2.tipo==tfloat){
					$$.tipo=$2.tipo;
				}else{
					if($2.error!=1){
						printf("\nError: linea %d: expresion con tipos incompatibles", $1.linea);
					}
					$$.error=1;
				}
			}
		| expresion MUL expresion 
			{
				if(($1.error!=1)&&($3.error!=1))
				{
					if(($1.tipo==tstack)||($3.tipo==tstack)){
						printf("\nError: linea %d: Una Stack no se puede operar", $1.linea);
						$$.error=1;
					}else{
						if(($1.tipo==tstring)||($3.tipo==tstring)){
							printf("\nError: linea %d: Una String no se puede sumar, utiliza op de cadena", $1.linea);
							$$.error=1;
						}else{
							if(($1.tipo==tchar)||($3.tipo==tchar)){
								printf("\nError: linea %d: Un char no se puede operar", $1.linea);
								$$.error=1;
							}else{
								if(($1.tipo==tboolean)||($3.tipo==tboolean)){
									printf("\nError: linea %d: Un boolean no se puede operar aritmeticamente", $1.linea);
									$$.error=1;
								}else{
									if(($1.tipo==tfloat)||($3.tipo==tfloat)){
										$$.tipo=tfloat;
									}else{
										$$.tipo=tint;
									}
								}
							
							}
						}
					}
				}
			}
		| expresion DIV expresion 
			{
				if(($1.error!=1)&&($3.error!=1))
				{
					if(($1.tipo==tstack)||($3.tipo==tstack)){
						printf("\nError: linea %d: Una Stack no se puede operar", $1.linea);
						$$.error=1;
					}else{
						if(($1.tipo==tstring)||($3.tipo==tstring)){
							printf("\nError: linea %d: Una String no se puede sumar, utiliza op de cadena", $1.linea);
							$$.error=1;
						}else{
							if(($1.tipo==tchar)||($3.tipo==tchar)){
								printf("\nError: linea %d: Un char no se puede operar", $1.linea);
								$$.error=1;
							}else{
								if(($1.tipo==tboolean)||($3.tipo==tboolean)){
									printf("\nError: linea %d: Un boolean no se puede operar aritmeticamente", $1.linea);
									$$.error=1;
								}else{
									if(($1.tipo==tfloat)||($3.tipo==tfloat)){
										$$.tipo=tfloat;
									}else{
										$$.tipo=tint;
									}
								}
							
							}
						}
					}
				}
			}
		| expresion MAYOR expresion 
		{
				if(($1.error!=1)&&($3.error!=1))
				{
					if(($1.tipo==tstack)||($3.tipo==tstack)){
						printf("\nError: linea %d: Una Stack no se puede comparar", $1.linea);
						$$.error=1;
					}else{
						if(($1.tipo==tstring)||($3.tipo==tstring)){
							printf("\nError: linea %d: Una String no se puede operar, utiliza op de cadena", $1.linea);
							$$.error=1;
						}else{
							if(($1.tipo==tchar)||($3.tipo==tchar)){
								printf("\nError: linea %d: Un char no se puede operar mayorq", $1.linea);
								$$.error=1;
							}else{
								if((($1.tipo==tboolean)&&($3.tipo!=tboolean))||(($3.tipo==tboolean)&&($1.tipo!=tboolean))){
									printf("\nError: linea %d: Un boolean no se puedecomparar con numeros", $1.linea);
									$$.error=1;
								}else{
									$$.tipo=tboolean;
								}
							
							}
						}
					}
				}
			}
		| expresion MENOR expresion 
		{
				if(($1.error!=1)&&($3.error!=1))
				{
					if(($1.tipo==tstack)||($3.tipo==tstack)){
						printf("\nError: linea %d: Una Stack no se puede comparar", $1.linea);
						$$.error=1;
					}else{
						if(($1.tipo==tstring)||($3.tipo==tstring)){
							printf("\nError: linea %d: Una String no se puede operar, utiliza op de cadena", $1.linea);
							$$.error=1;
						}else{
							if(($1.tipo==tchar)||($3.tipo==tchar)){
								printf("\nError: linea %d: Un char no se puede operar mayorq", $1.linea);
								$$.error=1;
							}else{
								if((($1.tipo==tboolean)&&($3.tipo!=tboolean))||(($3.tipo==tboolean)&&($1.tipo!=tboolean))){
									printf("\nError: linea %d: Un boolean no se puedecomparar con numeros", $1.linea);
									$$.error=1;
								}else{
									$$.tipo=tboolean;
								}
							
							}
						}
					}
				}
			}
		| expresion MAYIGUAL expresion 
		{
				if(($1.error!=1)&&($3.error!=1))
				{
					if(($1.tipo==tstack)||($3.tipo==tstack)){
						printf("\nError: linea %d: Una Stack no se puede comparar", $1.linea);
						$$.error=1;
					}else{
						if(($1.tipo==tstring)||($3.tipo==tstring)){
							printf("\nError: linea %d: Una String no se puede operar, utiliza op de cadena", $1.linea);
							$$.error=1;
						}else{
							if(($1.tipo==tchar)||($3.tipo==tchar)){
								printf("\nError: linea %d: Un char no se puede operar mayorq", $1.linea);
								$$.error=1;
							}else{
								if((($1.tipo==tboolean)&&($3.tipo!=tboolean))||(($3.tipo==tboolean)&&($1.tipo!=tboolean))){
									printf("\nError: linea %d: Un boolean no se puedecomparar con numeros", $1.linea);
									$$.error=1;
								}else{
									$$.tipo=tboolean;
								}
							
							}
						}
					}
				}
			}
		| expresion MENIGUAL expresion 
		{
				if(($1.error!=1)&&($3.error!=1))
				{
					if(($1.tipo==tstack)||($3.tipo==tstack)){
						printf("\nError: linea %d: Una Stack no se puede comparar", $1.linea);
						$$.error=1;
					}else{
						if(($1.tipo==tstring)||($3.tipo==tstring)){
							printf("\nError: linea %d: Una String no se puede operar, utiliza op de cadena", $1.linea);
							$$.error=1;
						}else{
							if(($1.tipo==tchar)||($3.tipo==tchar)){
								printf("\nError: linea %d: Un char no se puede operar mayorq", $1.linea);
								$$.error=1;
							}else{
								if((($1.tipo==tboolean)&&($3.tipo!=tboolean))||(($3.tipo==tboolean)&&($1.tipo!=tboolean))){
									printf("\nError: linea %d: Un boolean no se puedecomparar con numeros", $1.linea);
									$$.error=1;
								}else{
									$$.tipo=tboolean;
								}
							
							}
						}
					}
				}
			}
		| expresion DISTINTO expresion 
		{
				if(($1.error!=1)&&($3.error!=1))
				{
					if(($1.tipo==tstack)||($3.tipo==tstack)){
						printf("\nError: linea %d: Una Stack no se puede comparar", $1.linea);
						$$.error=1;
					}else{
						if(($1.tipo==tstring)||($3.tipo==tstring)){
							printf("\nError: linea %d: Una String no se puede operar, utiliza op de cadena", $1.linea);
							$$.error=1;
						}else{
							if(($1.tipo==tchar)||($3.tipo==tchar)){
								printf("\nError: linea %d: Un char no se puede operar mayorq", $1.linea);
								$$.error=1;
							}else{
								if((($1.tipo==tboolean)&&($3.tipo!=tboolean))||(($3.tipo==tboolean)&&($1.tipo!=tboolean))){
									printf("\nError: linea %d: Un boolean no se puedecomparar con numeros", $1.linea);
									$$.error=1;
								}else{
									$$.tipo=tboolean;
								}
							
							}
						}
					}
				}
			}
		| expresion COMP expresion 
		{
				if(($1.error!=1)&&($3.error!=1))
				{
					if(($1.tipo==tstack)||($3.tipo==tstack)){
						printf("\nError: linea %d: Una Stack no se puede comparar", $1.linea);
						$$.error=1;
					}else{
						if(($1.tipo==tstring)||($3.tipo==tstring)){
							printf("\nError: linea %d: Una String no se puede operar, utiliza op de cadena", $1.linea);
							$$.error=1;
						}else{
							if(($1.tipo==tchar)||($3.tipo==tchar)){
								printf("\nError: linea %d: Un char no se puede operar mayorq", $1.linea);
								$$.error=1;
							}else{
								if((($1.tipo==tboolean)&&($3.tipo!=tboolean))||(($3.tipo==tboolean)&&($1.tipo!=tboolean))){
									printf("\nError: linea %d: Un boolean no se puedecomparar con numeros", $1.linea);
									$$.error=1;
								}else{
									$$.tipo=tboolean;
								}
							
							}
						}
					}
				}
			}
		| TRUE {$$.tipo=tboolean;}
		| FALSE {$$.tipo=tboolean;}
		| NUM {$$.tipo=tint;}
		| llamada_funcion
			{
				if($1.tipo==unknown){
					$$.error=1;
					printf("\nError: linea %d: Error en la llamada a funcion", $1.linea);
				}else{
					$$.tipo=nodoaux.tipo;
					$$.entrada=nodoaux.entrada;
					$$.tipopila=nodoaux.tipopila;
					$$.error=0;
				}
			}
		| PIZ expresion PDE 
			{		
				$$.tipo=$2.tipo;
				$$.tipopila=$2.tipopila;
				$$.entrada=$2.entrada;
				$$.error=$2.error;
			}
		| NOT expresion 
			{
				if($2.error!=1)
				{
					if($2.tipo==tboolean){
						$$.tipo=tboolean;
					}else{
						printf("\nError: linea %d: expresion con tipos incompatibles", $1.linea);
						$$.error=1;
					}
				}
			}
		| ID 
			{
				if(existeNodoScope(ts,$1.nombre)==-1)
				{
					$$.error=1;
					$$.tipo=unknown;
					printf("\nError: linea %d: La variable %s no esta definida en este bloque", $1.linea, $1.nombre);
				}else{
					nodoaux=ts.tabla[existeNodoScope(ts,$1.nombre)];
					$$.tipo=nodoaux.tipo;
					$$.entrada=nodoaux.entrada;
					$$.tipopila=nodoaux.tipopila;
					$$.error=nodoaux.error;
				}
			}

		|concatenar			
			{
				if($1.error!=1)
				{
					$$.tipo=tstring;
					$$.error=0;
				}else{
					$$.error=1;	
				}
			}
		|longitud 
			{
				if($1.error!=1)
				{
					$$.tipo=tint;
					$$.error=0;
				}else{
					$$.error=1;	
				}
			}
		|comparar
			{
				if($1.error!=1)
				{
					$$.tipo=tint;
					$$.error=0;
				}else{
					$$.error=1;	
				}
			}
		|copiar
			{
				if($1.error!=1)
				{
					$$.tipo=unknown;
					$$.error=0;
				}else{
					$$.error=1;	
				}
			}
		|concatenarn
			{
				if($1.error!=1)
				{
					$$.tipo=unknown;
					$$.error=0;
				}else{
					$$.error=1;	
				}
			}
		|buscar
			{
				if($1.error!=1)
				{
					$$.tipo=tint;
					$$.error=0;
				}else{
					$$.error=1;	
				}
			}
		|extraer
			{
				if($1.error!=1)
				{
					$$.tipo=tstring;
					$$.error=0;
				}else{
					$$.error=1;	
				}
			}
		|CAD
			{
				$$.tipo=tstring;
				$$.error=0;
			}
		|incremento 			
			{
				if($1.error!=1)
				{
					$$.tipo=tint;
					$$.error=0;
				}else{
					$$.error=1;	
				}
			}
		|decremento 			
			{
				if($1.error!=1)
				{
					$$.tipo=tint;
					$$.error=0;
				}else{
					$$.error=1;	
				}
			}
		|asig {
				$$.error=$1.error;
			}
		|pila_saca 			
			{
				if($1.error!=1)
				{
					$$.tipo=$1.tipopila;
					$$.error=0;
				}else{
					$$.error=1;	
				}
			}
		|longitud_pila  			
		{
				if($1.error!=1)
				{
					$$.tipo=tint;
					$$.error=0;
				}else{
					$$.error=1;	
				}
			}
;



leer : SCANF PIZ MODC COMA ID PDE PYC 
		{
			if(existeNodoScope(ts,$5.nombre)==-1)
			{
				$$.error=1;
				$$.tipo=unknown;
				printf("\nError: linea %d: La variable %s no esta definida en este bloque", $5.linea, $5.nombre);
			}else{
				nodoaux=ts.tabla[existeNodoScope(ts,$5.nombre)];
				if((nodoaux.tipo=tstring)||(nodoaux.tipo=tchar))
				{
					$$.error=0;
				}else{
					$$.error=1;
					$$.tipo=unknown;
					printf("\nError: linea %d: se esperaba variable char o string", $5.linea, $5.nombre);
				}
			}
		}
	| SCANF PIZ MODD COMA ID PDE PYC
		{
			if(existeNodoScope(ts,$5.nombre)==-1)
			{
				$$.error=1;
				$$.tipo=unknown;
				printf("\nError: linea %d: La variable %s no esta definida en este bloque", $5.linea, $5.nombre);
			}else{
				nodoaux=ts.tabla[existeNodoScope(ts,$5.nombre)];
				if(nodoaux.tipo=tint)
				{
					$$.error=0;
				}else{
					$$.error=1;
					$$.tipo=unknown;
					printf("\nError: linea %d: se esperaba una variable int", $5.linea, $5.nombre);
				}
			}
		}
;

escribir : PRINTF PIZ contenido PDE PYC 
;
contenido : contenido COMA expresion 	
	{
		if($3.tipo==pila){
			printf("\nError: linea %d: no se puede escribir un STACK.", $3.linea);
		}
	}
	| CAD
;

if : IF  PIZ expresion PDE  bloque ELSE bloque | IF  PIZ expresion PDE bloque
;
while : WHILE  PIZ expresion PDE  bloque
;
for : FOR PIZ PYC PYC PDE bloque | FOR PIZ expresiones PYC PYC PDE bloque | FOR PIZ PYC expresion PYC PDE bloque | FOR PIZ PYC PYC expresiones PDE bloque | FOR PIZ expresiones PYC expresion PYC PDE bloque | FOR PIZ expresiones PYC PYC expresiones PDE bloque | FOR PIZ PYC expresion PYC expresiones PDE bloque | FOR PIZ expresiones PYC expresion PYC expresiones PDE bloque
;
expresiones : expresiones COMA expresion | expresion
;
incremento :  ID INCRE	{
		if(existeNodoScope(ts,$1.nombre)==-1)
		{
			$$.error=1;
			$$.tipo=unknown;
			printf("\nError: linea %d: La variable %s no esta definida en este bloque", $1.linea, $1.nombre);
		}else{
			nodoaux=ts.tabla[existeNodoScope(ts,$1.nombre)];
			$$.error=0;
			$$.tipo=tint;
		}
	} 
	| INCRE ID 	{
		if(existeNodoScope(ts,$2.nombre)==-1)
		{
			$$.error=1;
			$$.tipo=unknown;
			printf("\nError: linea %d: La variable %s no esta definida en este bloque", $2.linea, $2.nombre);
		}else{
			nodoaux=ts.tabla[existeNodoScope(ts,$2.nombre)];
			$$.error=0;
			$$.tipo=tint;
		}
	} 
;
decremento : ID DECRE {
		if(existeNodoScope(ts,$1.nombre)==-1)
		{
			$$.error=1;
			$$.tipo=unknown;
			printf("\nError: linea %d: La variable %s no esta definida en este bloque", $1.linea, $1.nombre);
		}else{
			nodoaux=ts.tabla[existeNodoScope(ts,$1.nombre)];
			$$.error=0;
			$$.tipo=tint;
		}
	} 
	| DECRE ID{
		if(existeNodoScope(ts,$2.nombre)==-1)
		{
			$$.error=1;
			$$.tipo=unknown;
			printf("\nError: linea %d: La variable %s no esta definida en este bloque", $2.linea, $2.nombre);
		}else{
			nodoaux=ts.tabla[existeNodoScope(ts,$2.nombre)];
			$$.error=0;
			$$.tipo=tint;
		}
	} 	
;
main : INT MAIN PIZ PDE {
		tret=unknown;
		nodoaux=nuevaEntrada(funcion, $2.nombre, entero, 0, $2.linea, unknown);
		addEntrada(ts, nodoaux);
		nodoaux=nuevaEntrada(marca, "{", unknown, 0, $2.linea, unknown);
		addEntrada(ts, nodoaux);
	} cuerpo {		
		if(tret==unknown){
			printf("\nError: linea %d: falta el return en el main.", $2.linea);
		}else{
			if(tret!=tint){
				printf("\nError: linea %d: main debe devolver entero", $1.linea);
			}
		}
		deleteBloque(&ts);
	}
;
bloque : IB insts FB | inst  | PYC
;
llamada_funcion : ID PIZ PDE 
	{
		if(existeNodo(ts,$1.nombre)==-1)
		{
			$$.error=1;
			printf("\nError: linea %d: La funcion no ha sido definida", $1.linea);
		}else{
			nodoaux=getNodoi(&ts,existeNodo(ts,$1.nombre));
			if(nodoaux.numparam!=0){
				$$.error=1;
				printf("\nError: linea %d: Numero incorrecto de parametros", $1.linea);
			}else{
				if(nodoaux.entrada!=funcion)
				{
					$$.error=1;
					printf("\nError: linea %d: La funcion no ha sido definida como funcion", $1.linea);
				}else{
					$$.error=0;
					$$.tipo=nodoaux.tipo;
					$$.tipopila=nodoaux.tipopila;
				}	
			}
		}
	}
	| ID PIZ expresiones PDE
	{
		posicion=existeNodo(ts,$1.nombre);
		if(posicion==-1)
		{
			$$.error=1;
			printf("\nError: linea %d: La funcion no ha sido definida", $1.linea);
		}else{
			nodoaux=getNodoi(&ts,posicion);
			if(nodoaux.numparam!=$3.numparam){
				$$.error=1;
				printf("\nError: linea %d: Numero incorrecto de parametros, se esperaban %d", $1.linea, $3.numparam);
			}else{
				if(nodoaux.entrada!=funcion)
				{
					$$.error=1;
					printf("\nError: linea %d: La funcion no ha sido definida como funcion", $1.linea);
				}else{
					posicion2=ts.tamlog-nodoaux.numparam;
					flag=0;
					for(int i=1;i<=nodoaux.numparam;i++)
					{
						if(flag=0){
							nodoaux2=getNodoi(&ts,posicion+i);
							nodoaux3=getNodoi(&ts,posicion2+i);

							if(nodoaux2.tipo!=nodoaux3.tipo){
								$$.error=1;
								flag=1;
								printf("\nError: linea %d: El argumento %d es de tipo incorrecto", $1.linea, i);
							}else{
								if(nodoaux2.tipopila!=nodoaux3.tipopila){
									flag=1;
									$$.error=1;
									printf("\nError: linea %d: El argumento %d tiene tipo de pila incorrecto", $1.linea, i);
								}else{
									$$.error=0;
								}
							}
						}
					}

					$$.error=0;
					$$.tipo=nodoaux.tipo;
					$$.tipopila=nodoaux.tipopila;
				}	
			}
		}
	}
;
concatenar : STRCAT PIZ expresion COMA expresion PDE
	{
		if(($3.error!=1)&&($5.error!=1))
		{
			if($3.tipo!=tstring){
				printf("\nError: linea %d: error en argumento 1, se encontro un tipo distinto de cadena", $3.linea);
				$$.error=1;
			}else{
				if($5.tipo!=tstring){
					printf("\nError: linea %d: error en argumento 2, se encontro un tipo distinto de cadena", $3.linea);
					$$.error=1;
				}else{
					$$.tipo=tstring;
				}
			}
		}
	}
;
concatenarn : STRNCAT PIZ expresion COMA expresion COMA expresion PDE
	{
		if(($3.error!=1)&&($5.error!=1)&&($7.error!=1))
		{
			if($3.tipo!=tstring){
				printf("\nError: linea %d: error en argumento 1, se encontro un tipo distinto de cadena", $3.linea);
				$$.error=1;
			}else{
				if($5.tipo!=tstring){
					printf("\nError: linea %d: error en argumento 2, se encontro un tipo distinto de cadena", $5.linea);
					$$.error=1;
				}else{
					if($7.tipo!=tint){
						printf("\nError: linea %d: error en argumento 3, se encontro un tipo distinto de entero", $7.linea);
						$$.error=1;
					}else{
						$$.tipo=tstring;
					}
				}
			}
		}
	}
;
longitud :  STRLEN PIZ expresion PDE
	{
		if($3.error!=1)
		{
			if($3.tipo!=tstring){
				printf("\nError: linea %d: se encontro un tipo distinto de cadena", $3.linea);
				$$.error=1;
			}else{
				$$.tipo=tint;
				$$.error=0;
			}
		}
	}
;
comparar : STRCMP PIZ expresion COMA expresion PDE
	{
		if(($3.error!=1)&&($5.error!=1))
		{
			if($3.tipo!=tstring){
				printf("\nError: linea %d: argumento 1, se encontro un tipo distinto de cadena", $3.linea);
				$$.error=1;
			}else{
				if($5.tipo!=tstring){
					printf("\nError: linea %d: argumento 2, se encontro un tipo distinto de cadena", $5.linea);
					$$.error=1;
				}else{
					$$.tipo=tint;
					$$.error=0;
				}
			}
		}
	}
;
copiar : STRCPY PIZ expresion COMA expresion PDE
	{
		if(($3.error!=1)&&($5.error!=1))
		{
			if($3.tipo!=tstring){
				printf("\nError: linea %d: argumento 1, se encontro un tipo distinto de cadena", $3.linea);
				$$.error=1;
			}else{
				if($5.tipo!=tstring){
					printf("\nError: linea %d: argumento 2, se encontro un tipo distinto de cadena", $5.linea);
					$$.error=1;
				}else{
					$$.error=0;
				}
			}
		}
	}
;
buscar : STRCHR PIZ expresion COMA expresion PDE
	{
		if(($3.error!=1)&&($5.error!=1))
		{
			if($3.tipo!=tstring){
				printf("\nError: linea %d: argumento 1, se encontro un tipo distinto de cadena", $3.linea);
				$$.error=1;
			}else{
				if($5.tipo!=tstring){
					printf("\nError: linea %d: argumento 2, se encontro un tipo distinto de cadena", $5.linea);
					$$.error=1;
				}else{
					$$.tipo=tint;
					$$.error=0;
				}
			}
		}
	}
;
extraer : STREXT PIZ expresion COMA expresion PDE
	{
		if(($3.error!=1)&&($5.error!=1))
		{
			if($3.tipo!=tstring){
				printf("\nError: linea %d: argumento 1, se encontro un tipo distinto de cadena", $3.linea);
				$$.error=1;
			}else{
				if($5.tipo!=tint){
					printf("\nError: linea %d: argumento 2, se encontro un tipo distinto de entero", $5.linea);
					$$.error=1;
				}else{
					$$.tipo=tstring;
					$$.error=0;
				}
			}
		}
	}
;

pila_mete : PUSH PIZ ID COMA expresion PDE
	{
		if($5.error!=1)
		{
			if(existeNodoScope(ts,$3.nombre)==-1)
			{
				$$.error=1;
				$$.tipo=unknown;
				printf("\nError: linea %d: La variable %s no esta definida en este bloque",  $3.linea, $3.nombre);
			}else{
				nodoaux=ts.tabla[existeNodoScope(ts,$1.nombre)];
				if($5.tipo!=nodoaux.tipopila)
				{
					$$.error=1;
					$$.tipo=unknown;
					printf("\nError: linea %d: La variable %s es de tipo no admitido por la pila", $5.linea, $5.nombre);
				}else
				{
					$$.error=0;
				}
			}
		}
	}
;
pila_saca : POP PIZ ID PDE
	{
		if(existeNodoScope(ts,$3.nombre)==-1)
		{
			$$.error=1;
			$$.tipo=unknown;
			printf("\nError: linea %d: La variable %s no esta definida en este bloque", $3.linea, $3.nombre);
		}else{
			nodoaux=ts.tabla[existeNodoScope(ts,$1.nombre)];
			$$.error=0;
			$$.tipo=nodoaux.tipopila;
		}
	}
;
longitud_pila : SIZE PIZ ID PDE
	{
		if(existeNodoScope(ts,$3.nombre)==-1)
		{
			$$.error=1;
			$$.tipo=unknown;
			printf("\nError: linea %d: La variable %s no esta definida en este bloque", $3.linea, $3.nombre);
		}else{
			$$.error=0;
			$$.tipo=tint;
		}
	}
;
pila_dest : DELETE PIZ ID PDE
	{
		if(existeNodoScope(ts,$3.nombre)==-1)
		{
			$$.error=1;
			$$.tipo=unknown;
			printf("\nError: linea %d: La variable %s no esta definida en este bloque", $3.linea, $3.nombre);
		}else{
			$$.error=0;
		}
	}
;
%%
/* Aqu� incluimos el fichero generado por el Flex, que implementa la funci�n yylex() */
#include "lexyy.c"
