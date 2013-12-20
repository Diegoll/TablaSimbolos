%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
/* Sección de producciones que definen la gramática */

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
func : tipo ID PIZ PDE funcs cuerpo |  tipo ID PIZ tipo ID PDE cuerpo
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
/* Aquí incluimos el fichero generado por el Flex, que implementa la función yylex() */
#include "lexyy.c"