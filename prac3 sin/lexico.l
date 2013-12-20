%{ 
/* Analizador de léxico */ 
#include <stdlib.h> 
#include <stdio.h> 
#define STDC 
char *msg;
%} 
letra [a-zA-Z] 
digito [0-9] 
alphanum [a-zA-Z_0-9] 
todos . 

%x comentario 
%% 
"main" return MAIN;  
"(" return PIZ; 
")" return PDE; 
"+" return SUM; 
"-" return RES; 
"*" return MUL; 
"/" return DIV;
"!=" return DISTINTO;
"<=" return MENIGUAL;
"<" return MENOR;
">=" return MAYIGUAL;
">" return MAYOR;
"==" return COMP; 
"=" return ASI; 
";" return PYC;
"." return PTO;
"," return COMA;
"#" return ALM;
"for" return FOR;
"if" return IF;
"else" return ELSE;
"while" return WHILE;
"int" return INT;
"char" return CHAR;
"string" return STRING;
"float" return FLOAT;
"boolean" return BOOLEAN;
"stack" return PILA;
"{" return IB;
"}" return FB;
"++" return INCRE;
"--" return DECRE;
"\"%c\"" return MODC;
"\"%d\"" return MODD;
"\"%s\"" return MODS;
"#include" return INC;
"#define" return DEF;
"typedef" return TDEF;
"printf" return PRINTF;
"scanf" return SCANF;
"strcat" return STRCAT;
"strncat" return STRNCAT;
"strlen" return STRLEN;
"strcmp" return STRCMP;
"strcpy" return STRCPY;
"strchr" return STRCHR;
"strext" return STREXT;
"&" return AMPER;
"true" return TRUE;
"false" return FALSE;
"return" return RET;
{digito}+ return NUM;
{digito}*"."{digito}+ return REAL;
{letra}{alphanum}* return ID; 
\"(([^\n\"])|(\\\"))*\" return CAD;
{letra}*"."h return LIB;


" "+ ; 
\n linea_actual++; 
\t ; 
"/*" {yymore(); BEGIN(comentario); } 
<comentario>[^*\n]* yymore() 
<comentario>"*"+[^*/\n]* yymore() 
<comentario>\n {++linea_actual; yymore()} 
<comentario>"*"+"/" {BEGIN(INITIAL);}  
{todos} yyerror(msg); 
%% 

