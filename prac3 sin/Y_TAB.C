#ifndef lint
static char yysccsid[] = "@(#)yaccpar     1.7 (Berkeley) 09/09/90";
#endif
#define YYBYACC 1
#line 2 "prueba.y"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int linea_actual = 0; 

void yyerror (char *msg)
{
fprintf(stderr, "\n");
fprintf(stderr,"Error de sintaxis en la linea: %d",linea_actual);
}
#line 17 "y_tab.c"
#define PDE 257
#define ASI 258
#define MAIN 259
#define PYC 260
#define ID 261
#define NUM 262
#define PIZ 263
#define CAD 264
#define FOR 265
#define IF 266
#define LIB 267
#define MODC 268
#define MODD 269
#define MODS 270
#define ELSE 271
#define WHILE 272
#define INT 273
#define CHAR 274
#define STRING 275
#define IB 276
#define FB 277
#define INCRE 278
#define DECRE 279
#define INC 280
#define DEF 281
#define TDEF 282
#define PRINTF 283
#define SCANF 284
#define STRCAT 285
#define STRNCAT 286
#define STRLEN 287
#define STRCMP 288
#define STRCPY 289
#define STRCHR 290
#define STREXT 291
#define DISTINTO 292
#define MENIGUAL 293
#define MENOR 294
#define MAYIGUAL 295
#define MAYOR 296
#define COMP 297
#define PTO 298
#define ALM 299
#define COMA 300
#define AMPER 301
#define TRUE 302
#define FALSE 303
#define NOT 304
#define SUM 305
#define RES 306
#define MUL 307
#define DIV 308
#define UMINUS 309
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    0,    1,    1,    1,    2,    2,    2,    2,    2,
    2,    2,    2,    3,    3,    9,    4,    4,   10,    5,
    6,    6,   14,   14,   13,   15,   15,    7,    7,   16,
   16,   18,   18,   19,   19,   19,   19,   19,   19,   12,
   12,   12,   17,   17,   17,   17,   25,   11,   11,   11,
   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   11,   11,   11,   20,   36,   36,   37,
   37,   21,   38,   38,   22,   22,   23,   24,   24,   24,
   24,   24,   24,   24,   24,   40,   40,   34,   34,   35,
   35,    8,   39,   39,   39,   26,   26,   27,   31,   28,
   29,   30,   32,   33,
};
short yylen[] = {                                         2,
    2,    1,    2,    1,    1,    4,    3,    3,    3,    2,
    2,    2,    1,    2,    1,    4,    2,    1,    3,    4,
    2,    1,    3,    1,    3,    3,    1,    2,    1,    5,
    7,    2,    1,    1,    1,    1,    1,    1,    2,    1,
    1,    1,    4,    3,    3,    2,    3,    3,    3,    2,
    3,    3,    3,    3,    3,    3,    3,    3,    1,    1,
    1,    1,    3,    2,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    5,    4,    1,    1,
    1,    5,    3,    1,    7,    5,    5,    6,    7,    7,
    7,    8,    8,    8,    9,    3,    1,    2,    2,    2,
    2,    5,    3,    1,    1,    3,    4,    6,    8,    4,
    6,    6,    6,    6,
};
short yydefred[] = {                                      0,
    0,   42,   40,    0,    0,    0,    0,    0,    2,    0,
    0,    0,    0,    0,   13,   15,   18,    0,   22,   29,
    0,    0,    0,   41,    0,    1,    0,   14,   17,    0,
    0,   10,    0,   11,   21,   12,    0,   28,    0,   27,
    0,    0,    0,    0,   61,    0,   73,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   59,   60,    0,    0,
    0,   76,   62,   66,   67,   68,   69,   70,   71,   72,
   74,   75,    0,    0,    7,    8,    9,    0,    0,    0,
   25,    0,    0,   16,    0,    0,   98,  100,    0,   99,
  101,    0,    0,    0,    0,    0,    0,    0,    0,   50,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   20,    6,    0,    0,    0,    0,   26,    0,  102,    0,
  106,    0,    0,   63,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   51,
   52,   30,    0,    0,    0,    0,   46,    0,    0,    0,
    0,    0,    0,   33,   34,   35,   36,   37,   38,  107,
    0,    0,    0,  110,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   45,    0,   39,   44,   32,    0,
    0,    0,    0,    0,    0,    0,   31,    0,    0,    0,
    0,   84,    0,   80,   81,    0,   79,   43,  108,    0,
  111,  112,  113,  114,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  105,
    0,  104,    0,   87,   82,    0,   77,    0,  109,   88,
    0,    0,    0,    0,    0,    0,    0,    0,   78,   91,
   90,    0,   89,    0,    0,    0,  103,   85,   94,   93,
   92,    0,   95,
};
short yydgoto[] = {                                       7,
    8,    9,   10,   11,   12,   13,   14,   15,   16,   17,
  151,   18,   19,   40,   41,   20,  119,  153,  222,  155,
  156,  157,  158,  159,   62,   63,   64,   65,   66,   67,
   68,   69,   70,   71,   72,  196,  197,  193,  223,  123,
};
short yysindex[] = {                                    -73,
 -170,    0,    0, -189, -149, -256,    0, -148,    0, -251,
 -166, -100, -100, -100,    0,    0,    0, -137,    0,    0,
 -143, -146,  713,    0, -133,    0, -166,    0,    0, -100,
 -100,    0, -100,    0,    0,    0, -132,    0, -219,    0,
 -246, -134, -144, -128,    0,  713,    0, -124,  -98, -102,
  -87,  -82,  -76,  -74,  -72,  -71,    0,    0,  713,  713,
 1072,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -70, -100,    0,    0,    0,  -60,  713, -241,
    0,  -68,  -66,    0,  713,   94,    0,    0, -197,    0,
    0,  713,  713,  713,  713,  713,  713,  713, -265,    0,
  713,  713,  713,  713,  713,  713,  713,  713,  713,  713,
    0,    0, 1072,  -66,  -50,  -46,    0,  482,    0, -265,
    0, 1072, -235,    0,  953,  970, -139,  987, 1004, 1021,
 1038, -265, -265, -265, -265, -265, -265, -206, -206,    0,
    0,    0,  -43,  -42,  -41,  -38,    0,  -37,  -36,  517,
  -27,  -68,  550,    0,    0,    0,    0,    0,    0,    0,
  713,  713,  713,    0,  713,  713,  713,  713,  -66,  383,
  713,  713,  -32,  -83,    0,  583,    0,    0,    0, 1072,
  -58, 1055,  -51,  -33,   -5,    1,    0,  415, -245,   19,
   25,    0, -208,    0,    0, -167,    0,    0,    0,  713,
    0,    0,    0,    0,  129,   69,  447,  351,  351,  -20,
  713,   -7,  -30,   42,  351, -164,  164,  199,  313,    0,
  682,    0,    6,    0,    0, 1072,    0,  -10,    0,    0,
  351,  351, -154,  351, -141,  234,  616,  351,    0,    0,
    0,  351,    0,  351,  351, -140,    0,    0,    0,    0,
    0,  351,    0,
};
short yyrindex[] = {                                      0,
   22,    0,    0,    0,    0,    0,    0,    0,    0,   70,
   96,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  128,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -234,    0,
    0,    0,    0,  -77,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -103,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  748,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -196,    0,    0, -234,    0,    0,    0,  776,
    0, -248,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  804,  832,  860,  888,  916,  944,  269,  297,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -247,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  649,    0,    0, -138,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,
};
short yygindex[] = {                                      0,
    0,  276,    0,  275,    0,  -11,  101,   -6,  294,   40,
  -23,   14,   -9,  204,    0,   17, -112, -145, -115,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  990, -159,
};
#define YYTABLESIZE 1380
short yytable[] = {                                      61,
   30,  142,  154,   35,  176,   32,   34,   36,   97,   96,
  189,   97,   96,   81,  207,  114,   24,    2,    3,   25,
   35,  160,   89,   75,   76,   24,   77,   37,    4,    5,
   38,   24,    2,    3,  154,   99,  100,  179,   79,  107,
  108,  109,  110,   80,   37,  216,   37,   38,  210,   38,
   29,   97,   96,   82,  161,  113,  187,  233,  235,  124,
  179,  120,  122,   23,  161,   24,   29,  112,  125,  126,
  127,  128,  129,  130,  131,  237,  246,  132,  133,  134,
  135,  136,  137,  138,  139,  140,  141,   37,   21,  212,
   38,  211,  231,  115,  101,  102,  103,  104,  105,  106,
  109,  110,  242,   23,   22,  154,  150,  107,  108,  109,
  110,   23,   31,   33,    5,  244,  252,  164,   83,   42,
   43,  179,   83,   39,    1,    2,    3,   73,   78,   85,
   74,  152,  213,    6,   86,  161,   90,  180,  181,  182,
   35,  183,  184,  185,  186,  161,  122,  190,  191,   87,
   88,   84,  101,  102,  103,  104,  105,  106,  161,  161,
   92,   83,   91,  152,  206,  107,  108,  109,  110,   19,
   19,   19,    1,    2,    3,   93,  214,   19,   19,   65,
   94,  122,   65,  219,  194,  195,   95,  226,   96,  111,
   97,   98,  116,  122,  122,   65,   65,   65,  199,    1,
    2,    3,   80,   65,   65,  201,    4,    5,    6,  118,
  143,   79,  122,  169,   65,   65,   65,   65,   65,   65,
  170,  171,   65,  202,  172,  173,  174,   65,   65,   65,
   65,  192,  177,  101,  102,  103,  104,  105,  106,  225,
  101,  102,  103,  104,  105,  106,  107,  108,  109,  110,
  239,  203,  227,  107,  108,  109,  110,  204,  101,  102,
  103,  104,  105,  106,  101,  102,  103,  104,  105,  106,
  228,  107,  108,  109,  110,  208,  238,  107,  108,  109,
  110,  209,   41,   26,   27,  117,  101,  102,  103,  104,
  105,  106,  101,  102,  103,  104,  105,  106,  229,  107,
  108,  109,  110,   28,    0,  107,  108,  109,  110,    0,
  101,  102,  103,  104,  105,  106,  101,  102,  103,  104,
  105,  106,    0,  107,  108,  109,  110,    0,  217,  107,
  108,  109,  110,  101,  102,  103,  104,  105,  106,    0,
    0,    0,    4,    4,    4,    0,  107,  108,  109,  110,
  121,    4,    0,    0,   44,   45,   46,   47,    0,    0,
  101,  102,  103,  104,  105,  106,    0,    0,    5,    5,
    5,   48,   49,  107,  108,  109,  110,    5,   50,   51,
   52,   53,   54,   55,   56,  215,    0,    0,    0,   44,
   45,   46,   47,    0,    0,   57,   58,   59,    0,   60,
    3,    3,    3,    0,    0,    0,   48,   49,    0,    3,
    0,    0,    0,   50,   51,   52,   53,   54,   55,   56,
  232,    0,    0,    0,   44,   45,   46,   47,    0,    0,
   57,   58,   59,    0,   60,    0,    0,    0,    0,    0,
    0,   48,   49,    0,    0,    0,    0,    0,   50,   51,
   52,   53,   54,   55,   56,  234,    0,    0,    0,   44,
   45,   46,   47,    0,    0,   57,   58,   59,    0,   60,
    0,    0,    0,    0,    0,    0,   48,   49,    0,    0,
    0,    0,    0,   50,   51,   52,   53,   54,   55,   56,
  245,    0,    0,    0,   44,   45,   46,   47,    0,    0,
   57,   58,   59,    0,   60,    0,    0,    0,    0,    0,
    0,   48,   49,    0,    0,    0,    0,    0,   50,   51,
   52,   53,   54,   55,   56,   48,    0,    0,   48,    0,
    0,    0,    0,    0,    0,   57,   58,   59,    0,   60,
    0,   48,   48,   48,    0,    0,    0,    0,    0,   48,
   48,    0,    0,   49,    0,    0,   49,    0,    0,    0,
   48,   48,   48,   48,   48,   48,    0,    0,   48,   49,
   49,   49,  236,   48,   48,    0,    0,   49,   49,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   49,   49,
   49,   49,   49,   49,    0,    0,   49,    0,    0,    0,
    0,   49,   49,    0,  101,  102,  103,  104,  105,  106,
  220,   44,   45,   46,   47,  144,  145,  107,  108,  109,
  110,    0,  146,    0,    0,    0,  221,    0,   48,   49,
    0,    0,    0,  148,  149,   50,   51,   52,   53,   54,
   55,   56,  188,   44,   45,   46,   47,    0,    0,    0,
    0,    0,   57,   58,   59,    0,   60,    0,    0,    0,
   48,   49,    0,    0,    0,    0,    0,   50,   51,   52,
   53,   54,   55,   56,  205,   44,   45,   46,   47,    0,
    0,    0,    0,    0,   57,   58,   59,    0,   60,    0,
    0,    0,   48,   49,    0,    0,    0,    0,    0,   50,
   51,   52,   53,   54,   55,   56,  218,   44,   45,   46,
   47,    0,    0,    0,    0,    0,   57,   58,   59,    0,
   60,    0,    0,    0,   48,   49,    0,    0,    0,    0,
    0,   50,   51,   52,   53,   54,   55,   56,    0,    0,
    0,    0,   44,   45,   46,   47,  144,  145,   57,   58,
   59,    0,   60,  146,   24,    2,    3,    0,  147,   48,
   49,    0,    0,    0,  148,  149,   50,   51,   52,   53,
   54,   55,   56,    0,    0,    0,    0,   44,   45,   46,
   47,  144,  145,   57,   58,   59,    0,   60,  146,   24,
    2,    3,    0,  175,   48,   49,    0,    0,    0,  148,
  149,   50,   51,   52,   53,   54,   55,   56,    0,    0,
   44,   45,   46,   47,  144,  145,    0,    0,   57,   58,
   59,  146,   60,    0,    0,    0,  178,   48,   49,    0,
    0,    0,  148,  149,   50,   51,   52,   53,   54,   55,
   56,    0,    0,   44,   45,   46,   47,  144,  145,    0,
    0,   57,   58,   59,  146,   60,    0,    0,    0,  198,
   48,   49,    0,    0,    0,  148,  149,   50,   51,   52,
   53,   54,   55,   56,    0,    0,   44,   45,   46,   47,
  144,  145,    0,    0,   57,   58,   59,  146,   60,    0,
    0,    0,  247,   48,   49,    0,    0,    0,  148,  149,
   50,   51,   52,   53,   54,   55,   56,    0,    0,   86,
   86,   86,   86,   86,   86,    0,    0,   57,   58,   59,
   86,   60,    0,    0,    0,   86,   86,   86,    0,    0,
    0,   86,   86,   86,   86,   86,   86,   86,   86,   86,
    0,    0,   44,   45,   46,   47,  144,  145,    0,    0,
   86,   86,   86,  146,   86,    0,    0,    0,    0,   48,
   49,    0,    0,    0,  148,  149,   50,   51,   52,   53,
   54,   55,   56,   44,   45,   46,   47,    0,    0,    0,
    0,    0,    0,   57,   58,   59,    0,   60,    0,    0,
   48,   49,    0,    0,    0,    0,    0,   50,   51,   52,
   53,   54,   55,   56,   64,    0,    0,   64,    0,    0,
    0,    0,    0,    0,   57,   58,   59,    0,   60,    0,
   64,   64,   64,    0,    0,    0,    0,    0,   64,   64,
    0,    0,   47,    0,    0,   47,    0,    0,    0,   64,
   64,   64,   64,   64,   64,    0,    0,   64,   47,   47,
   47,    0,    0,    0,    0,    0,   47,   47,    0,    0,
   57,    0,    0,   57,    0,    0,    0,   47,   47,   47,
   47,   47,   47,    0,    0,   47,   57,   57,   57,    0,
    0,    0,    0,    0,   57,   57,    0,    0,   56,    0,
    0,   56,    0,    0,    0,   57,   57,   57,   57,   57,
   57,    0,    0,   57,   56,   56,   56,    0,    0,    0,
    0,    0,   56,   56,    0,    0,   54,    0,    0,   54,
    0,    0,    0,   56,   56,   56,   56,   56,   56,    0,
    0,   56,   54,   54,   54,    0,    0,    0,    0,    0,
   54,   54,    0,    0,   55,    0,    0,   55,    0,    0,
    0,   54,   54,   54,   54,   54,   54,    0,    0,   54,
   55,   55,   55,    0,    0,    0,    0,    0,   55,   55,
    0,    0,   53,    0,    0,   53,    0,    0,    0,   55,
   55,   55,   55,   55,   55,    0,    0,   55,   53,   53,
   53,    0,    0,    0,    0,    0,   53,   53,  224,    0,
   58,    0,    0,   58,  230,    0,    0,   53,   53,   53,
   53,   53,   53,    0,    0,   53,   58,   58,   58,    0,
  240,  241,    0,  243,   58,   58,    0,  248,    0,    0,
    0,  249,    0,  250,  251,   58,   58,   58,   58,   58,
   58,  253,    0,   58,  101,  102,  103,  104,  105,  106,
    0,    0,  162,    0,    0,    0,    0,  107,  108,  109,
  110,  101,  102,  103,  104,  105,  106,    0,    0,  163,
    0,    0,    0,    0,  107,  108,  109,  110,  101,  102,
  103,  104,  105,  106,    0,    0,  165,    0,    0,    0,
    0,  107,  108,  109,  110,  101,  102,  103,  104,  105,
  106,    0,    0,  166,    0,    0,    0,    0,  107,  108,
  109,  110,  101,  102,  103,  104,  105,  106,    0,    0,
  167,    0,    0,    0,    0,  107,  108,  109,  110,  101,
  102,  103,  104,  105,  106,    0,    0,  168,    0,    0,
    0,    0,  107,  108,  109,  110,  101,  102,  103,  104,
  105,  106,    0,    0,  200,    0,    0,    0,    0,  107,
  108,  109,  110,  101,  102,  103,  104,  105,  106,    0,
    0,    0,    0,    0,    0,    0,  107,  108,  109,  110,
};
short yycheck[] = {                                      23,
   12,  114,  118,   13,  150,   12,   13,   14,  257,  257,
  170,  260,  260,  260,  260,  257,  273,  274,  275,    6,
   30,  257,   46,   30,   31,  260,   33,   14,  280,  281,
   14,  273,  274,  275,  150,   59,   60,  153,  258,  305,
  306,  307,  308,  263,   31,  205,   33,   31,  257,   33,
   11,  300,  300,  300,  300,   79,  169,  217,  218,  257,
  176,   85,   86,  260,  300,  300,   27,   74,   92,   93,
   94,   95,   96,   97,   98,  221,  236,  101,  102,  103,
  104,  105,  106,  107,  108,  109,  110,   74,  259,  257,
   74,  300,  257,   80,  292,  293,  294,  295,  296,  297,
  307,  308,  257,  300,  294,  221,  118,  305,  306,  307,
  308,  261,   12,   13,  281,  257,  257,  257,  257,  263,
  267,  237,  257,  261,  273,  274,  275,  261,  261,  258,
   30,  118,  300,  282,  263,  300,  261,  161,  162,  163,
  150,  165,  166,  167,  168,  300,  170,  171,  172,  278,
  279,  296,  292,  293,  294,  295,  296,  297,  300,  300,
  263,  300,  261,  150,  188,  305,  306,  307,  308,  273,
  274,  275,  273,  274,  275,  263,  200,  281,  282,  257,
  263,  205,  260,  207,  268,  269,  263,  211,  263,  260,
  263,  263,  261,  217,  218,  273,  274,  275,  257,  273,
  274,  275,  263,  281,  282,  257,  280,  281,  282,  276,
  261,  258,  236,  257,  292,  293,  294,  295,  296,  297,
  263,  263,  300,  257,  263,  263,  263,  305,  306,  307,
  308,  264,  260,  292,  293,  294,  295,  296,  297,  260,
  292,  293,  294,  295,  296,  297,  305,  306,  307,  308,
  261,  257,  260,  305,  306,  307,  308,  257,  292,  293,
  294,  295,  296,  297,  292,  293,  294,  295,  296,  297,
  301,  305,  306,  307,  308,  257,  271,  305,  306,  307,
  308,  257,  261,    8,   10,   82,  292,  293,  294,  295,
  296,  297,  292,  293,  294,  295,  296,  297,  257,  305,
  306,  307,  308,   10,   -1,  305,  306,  307,  308,   -1,
  292,  293,  294,  295,  296,  297,  292,  293,  294,  295,
  296,  297,   -1,  305,  306,  307,  308,   -1,  260,  305,
  306,  307,  308,  292,  293,  294,  295,  296,  297,   -1,
   -1,   -1,  273,  274,  275,   -1,  305,  306,  307,  308,
  257,  282,   -1,   -1,  261,  262,  263,  264,   -1,   -1,
  292,  293,  294,  295,  296,  297,   -1,   -1,  273,  274,
  275,  278,  279,  305,  306,  307,  308,  282,  285,  286,
  287,  288,  289,  290,  291,  257,   -1,   -1,   -1,  261,
  262,  263,  264,   -1,   -1,  302,  303,  304,   -1,  306,
  273,  274,  275,   -1,   -1,   -1,  278,  279,   -1,  282,
   -1,   -1,   -1,  285,  286,  287,  288,  289,  290,  291,
  257,   -1,   -1,   -1,  261,  262,  263,  264,   -1,   -1,
  302,  303,  304,   -1,  306,   -1,   -1,   -1,   -1,   -1,
   -1,  278,  279,   -1,   -1,   -1,   -1,   -1,  285,  286,
  287,  288,  289,  290,  291,  257,   -1,   -1,   -1,  261,
  262,  263,  264,   -1,   -1,  302,  303,  304,   -1,  306,
   -1,   -1,   -1,   -1,   -1,   -1,  278,  279,   -1,   -1,
   -1,   -1,   -1,  285,  286,  287,  288,  289,  290,  291,
  257,   -1,   -1,   -1,  261,  262,  263,  264,   -1,   -1,
  302,  303,  304,   -1,  306,   -1,   -1,   -1,   -1,   -1,
   -1,  278,  279,   -1,   -1,   -1,   -1,   -1,  285,  286,
  287,  288,  289,  290,  291,  257,   -1,   -1,  260,   -1,
   -1,   -1,   -1,   -1,   -1,  302,  303,  304,   -1,  306,
   -1,  273,  274,  275,   -1,   -1,   -1,   -1,   -1,  281,
  282,   -1,   -1,  257,   -1,   -1,  260,   -1,   -1,   -1,
  292,  293,  294,  295,  296,  297,   -1,   -1,  300,  273,
  274,  275,  260,  305,  306,   -1,   -1,  281,  282,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  292,  293,
  294,  295,  296,  297,   -1,   -1,  300,   -1,   -1,   -1,
   -1,  305,  306,   -1,  292,  293,  294,  295,  296,  297,
  260,  261,  262,  263,  264,  265,  266,  305,  306,  307,
  308,   -1,  272,   -1,   -1,   -1,  276,   -1,  278,  279,
   -1,   -1,   -1,  283,  284,  285,  286,  287,  288,  289,
  290,  291,  260,  261,  262,  263,  264,   -1,   -1,   -1,
   -1,   -1,  302,  303,  304,   -1,  306,   -1,   -1,   -1,
  278,  279,   -1,   -1,   -1,   -1,   -1,  285,  286,  287,
  288,  289,  290,  291,  260,  261,  262,  263,  264,   -1,
   -1,   -1,   -1,   -1,  302,  303,  304,   -1,  306,   -1,
   -1,   -1,  278,  279,   -1,   -1,   -1,   -1,   -1,  285,
  286,  287,  288,  289,  290,  291,  260,  261,  262,  263,
  264,   -1,   -1,   -1,   -1,   -1,  302,  303,  304,   -1,
  306,   -1,   -1,   -1,  278,  279,   -1,   -1,   -1,   -1,
   -1,  285,  286,  287,  288,  289,  290,  291,   -1,   -1,
   -1,   -1,  261,  262,  263,  264,  265,  266,  302,  303,
  304,   -1,  306,  272,  273,  274,  275,   -1,  277,  278,
  279,   -1,   -1,   -1,  283,  284,  285,  286,  287,  288,
  289,  290,  291,   -1,   -1,   -1,   -1,  261,  262,  263,
  264,  265,  266,  302,  303,  304,   -1,  306,  272,  273,
  274,  275,   -1,  277,  278,  279,   -1,   -1,   -1,  283,
  284,  285,  286,  287,  288,  289,  290,  291,   -1,   -1,
  261,  262,  263,  264,  265,  266,   -1,   -1,  302,  303,
  304,  272,  306,   -1,   -1,   -1,  277,  278,  279,   -1,
   -1,   -1,  283,  284,  285,  286,  287,  288,  289,  290,
  291,   -1,   -1,  261,  262,  263,  264,  265,  266,   -1,
   -1,  302,  303,  304,  272,  306,   -1,   -1,   -1,  277,
  278,  279,   -1,   -1,   -1,  283,  284,  285,  286,  287,
  288,  289,  290,  291,   -1,   -1,  261,  262,  263,  264,
  265,  266,   -1,   -1,  302,  303,  304,  272,  306,   -1,
   -1,   -1,  277,  278,  279,   -1,   -1,   -1,  283,  284,
  285,  286,  287,  288,  289,  290,  291,   -1,   -1,  261,
  262,  263,  264,  265,  266,   -1,   -1,  302,  303,  304,
  272,  306,   -1,   -1,   -1,  277,  278,  279,   -1,   -1,
   -1,  283,  284,  285,  286,  287,  288,  289,  290,  291,
   -1,   -1,  261,  262,  263,  264,  265,  266,   -1,   -1,
  302,  303,  304,  272,  306,   -1,   -1,   -1,   -1,  278,
  279,   -1,   -1,   -1,  283,  284,  285,  286,  287,  288,
  289,  290,  291,  261,  262,  263,  264,   -1,   -1,   -1,
   -1,   -1,   -1,  302,  303,  304,   -1,  306,   -1,   -1,
  278,  279,   -1,   -1,   -1,   -1,   -1,  285,  286,  287,
  288,  289,  290,  291,  257,   -1,   -1,  260,   -1,   -1,
   -1,   -1,   -1,   -1,  302,  303,  304,   -1,  306,   -1,
  273,  274,  275,   -1,   -1,   -1,   -1,   -1,  281,  282,
   -1,   -1,  257,   -1,   -1,  260,   -1,   -1,   -1,  292,
  293,  294,  295,  296,  297,   -1,   -1,  300,  273,  274,
  275,   -1,   -1,   -1,   -1,   -1,  281,  282,   -1,   -1,
  257,   -1,   -1,  260,   -1,   -1,   -1,  292,  293,  294,
  295,  296,  297,   -1,   -1,  300,  273,  274,  275,   -1,
   -1,   -1,   -1,   -1,  281,  282,   -1,   -1,  257,   -1,
   -1,  260,   -1,   -1,   -1,  292,  293,  294,  295,  296,
  297,   -1,   -1,  300,  273,  274,  275,   -1,   -1,   -1,
   -1,   -1,  281,  282,   -1,   -1,  257,   -1,   -1,  260,
   -1,   -1,   -1,  292,  293,  294,  295,  296,  297,   -1,
   -1,  300,  273,  274,  275,   -1,   -1,   -1,   -1,   -1,
  281,  282,   -1,   -1,  257,   -1,   -1,  260,   -1,   -1,
   -1,  292,  293,  294,  295,  296,  297,   -1,   -1,  300,
  273,  274,  275,   -1,   -1,   -1,   -1,   -1,  281,  282,
   -1,   -1,  257,   -1,   -1,  260,   -1,   -1,   -1,  292,
  293,  294,  295,  296,  297,   -1,   -1,  300,  273,  274,
  275,   -1,   -1,   -1,   -1,   -1,  281,  282,  209,   -1,
  257,   -1,   -1,  260,  215,   -1,   -1,  292,  293,  294,
  295,  296,  297,   -1,   -1,  300,  273,  274,  275,   -1,
  231,  232,   -1,  234,  281,  282,   -1,  238,   -1,   -1,
   -1,  242,   -1,  244,  245,  292,  293,  294,  295,  296,
  297,  252,   -1,  300,  292,  293,  294,  295,  296,  297,
   -1,   -1,  300,   -1,   -1,   -1,   -1,  305,  306,  307,
  308,  292,  293,  294,  295,  296,  297,   -1,   -1,  300,
   -1,   -1,   -1,   -1,  305,  306,  307,  308,  292,  293,
  294,  295,  296,  297,   -1,   -1,  300,   -1,   -1,   -1,
   -1,  305,  306,  307,  308,  292,  293,  294,  295,  296,
  297,   -1,   -1,  300,   -1,   -1,   -1,   -1,  305,  306,
  307,  308,  292,  293,  294,  295,  296,  297,   -1,   -1,
  300,   -1,   -1,   -1,   -1,  305,  306,  307,  308,  292,
  293,  294,  295,  296,  297,   -1,   -1,  300,   -1,   -1,
   -1,   -1,  305,  306,  307,  308,  292,  293,  294,  295,
  296,  297,   -1,   -1,  300,   -1,   -1,   -1,   -1,  305,
  306,  307,  308,  292,  293,  294,  295,  296,  297,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  305,  306,  307,  308,
};
#define YYFINAL 7
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 309
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"PDE","ASI","MAIN","PYC","ID",
"NUM","PIZ","CAD","FOR","IF","LIB","MODC","MODD","MODS","ELSE","WHILE","INT",
"CHAR","STRING","IB","FB","INCRE","DECRE","INC","DEF","TDEF","PRINTF","SCANF",
"STRCAT","STRNCAT","STRLEN","STRCMP","STRCPY","STRCHR","STREXT","DISTINTO",
"MENIGUAL","MENOR","MAYIGUAL","MAYOR","COMP","PTO","ALM","COMA","AMPER","TRUE",
"FALSE","NOT","SUM","RES","MUL","DIV","UMINUS",
};
char *yyrule[] = {
"$accept : prog",
"prog : dec1 dec2",
"prog : dec2",
"dec1 : incs defs",
"dec1 : incs",
"dec1 : defs",
"dec2 : tipos vars funcs main",
"dec2 : tipos vars main",
"dec2 : tipos funcs main",
"dec2 : vars funcs main",
"dec2 : tipos main",
"dec2 : vars main",
"dec2 : funcs main",
"dec2 : main",
"incs : incs inc",
"incs : inc",
"inc : INC MENOR LIB MAYOR",
"defs : defs def",
"defs : def",
"def : DEF ID expresion",
"tipos : TDEF tipo ID PYC",
"vars : vars var",
"vars : var",
"id_exp : ID ASI expresion",
"id_exp : ID",
"var : tipo id_exps PYC",
"id_exps : id_exps COMA id_exp",
"id_exps : id_exp",
"funcs : funcs func",
"funcs : func",
"func : tipo ID PIZ PDE cuerpo",
"func : tipo ID PIZ tipo ID PDE cuerpo",
"insts : insts inst",
"insts : inst",
"inst : leer",
"inst : escribir",
"inst : if",
"inst : while",
"inst : for",
"inst : expresion PYC",
"tipo : STRING",
"tipo : INT",
"tipo : CHAR",
"cuerpo : IB vars insts FB",
"cuerpo : IB insts FB",
"cuerpo : IB vars FB",
"cuerpo : IB FB",
"asig : ID ASI expresion",
"expresion : expresion SUM expresion",
"expresion : expresion RES expresion",
"expresion : RES expresion",
"expresion : expresion MUL expresion",
"expresion : expresion DIV expresion",
"expresion : expresion MAYOR expresion",
"expresion : expresion MENOR expresion",
"expresion : expresion MAYIGUAL expresion",
"expresion : expresion MENIGUAL expresion",
"expresion : expresion DISTINTO expresion",
"expresion : expresion COMP expresion",
"expresion : TRUE",
"expresion : FALSE",
"expresion : NUM",
"expresion : llamada_funcion",
"expresion : PIZ expresion PDE",
"expresion : NOT expresion",
"expresion : ID",
"expresion : concatenar",
"expresion : longitud",
"expresion : comparar",
"expresion : copiar",
"expresion : concatenarn",
"expresion : buscar",
"expresion : extraer",
"expresion : CAD",
"expresion : incremento",
"expresion : decremento",
"expresion : asig",
"leer : SCANF PIZ variables PDE PYC",
"variables : variables COMA AMPER ID",
"variables : modificador",
"modificador : MODC",
"modificador : MODD",
"escribir : PRINTF PIZ contenido PDE PYC",
"contenido : contenido COMA expresion",
"contenido : CAD",
"if : IF PIZ expresion PDE bloque ELSE bloque",
"if : IF PIZ expresion PDE bloque",
"while : WHILE PIZ expresion PDE bloque",
"for : FOR PIZ PYC PYC PDE bloque",
"for : FOR PIZ expresiones PYC PYC PDE bloque",
"for : FOR PIZ PYC expresion PYC PDE bloque",
"for : FOR PIZ PYC PYC expresiones PDE bloque",
"for : FOR PIZ expresiones PYC expresion PYC PDE bloque",
"for : FOR PIZ expresiones PYC PYC expresiones PDE bloque",
"for : FOR PIZ PYC expresion PYC expresiones PDE bloque",
"for : FOR PIZ expresiones PYC expresion PYC expresiones PDE bloque",
"expresiones : expresiones COMA expresion",
"expresiones : expresion",
"incremento : ID INCRE",
"incremento : INCRE ID",
"decremento : ID DECRE",
"decremento : DECRE ID",
"main : INT MAIN PIZ PDE cuerpo",
"bloque : IB insts FB",
"bloque : inst",
"bloque : PYC",
"llamada_funcion : ID PIZ PDE",
"llamada_funcion : ID PIZ expresiones PDE",
"concatenar : STRCAT PIZ expresion COMA expresion PDE",
"concatenarn : STRNCAT PIZ expresion COMA expresion COMA expresion PDE",
"longitud : STRLEN PIZ expresion PDE",
"comparar : STRCMP PIZ expresion COMA expresion PDE",
"copiar : STRCPY PIZ expresion COMA expresion PDE",
"buscar : STRCHR PIZ expresion COMA expresion PDE",
"extraer : STREXT PIZ expresion COMA expresion PDE",
};
#endif
#ifndef YYSTYPE
typedef int YYSTYPE;
#endif
#define yyclearin (yychar=(-1))
#define yyerrok (yyerrflag=0)
#ifdef YYSTACKSIZE
#ifndef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#endif
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 600
#define YYMAXDEPTH 600
#endif
#endif
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short yyss[YYSTACKSIZE];
YYSTYPE yyvs[YYSTACKSIZE];
#define yystacksize YYSTACKSIZE
#line 115 "prueba.y"
/* Aquí incluimos el fichero generado por el Flex, que implementa la función yylex() */
#include "lexyy.c"
#line 646 "y_tab.c"
#define YYABORT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse()
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register char *yys;
    extern char *getenv();

    if (yys = getenv("YYDEBUG"))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if (yyn = yydefred[yystate]) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("yydebug: state %d, reading %d (%s)\n", yystate,
                    yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("yydebug: state %d, shifting to state %d\n",
                    yystate, yytable[yyn]);
#endif
        if (yyssp >= yyss + yystacksize - 1)
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;
#ifdef lint
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#ifdef lint
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("yydebug: state %d, error recovery shifting\
 to state %d\n", *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yyss + yystacksize - 1)
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("yydebug: error recovery discarding state %d\n",
                            *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("yydebug: state %d, error recovery discards token %d (%s)\n",
                    yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("yydebug: state %d, reducing by rule %d (%s)\n",
                yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("yydebug: after reduction, shifting from state 0 to\
 state %d\n", YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("yydebug: state %d, reading %d (%s)\n",
                        YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("yydebug: after reduction, shifting from state %d \
to state %d\n", *yyssp, yystate);
#endif
    if (yyssp >= yyss + yystacksize - 1)
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    return (1);
yyaccept:
    return (0);
}
