win_flex lexico.l
win_bison.exe -v -t -y sintaxis.y
gcc y.tab.c tabla_simbolos.c main.c -o sintac.exe

sintac.exe prueba4.jds

pause