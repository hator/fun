%{
#include <stdio.h>

%}
 
%%

#.*/n {;}
[a-zA-z_$@][a-zA-Z0-9_$@]+  return *yytext;		    
[=+-*/]		return *yytext;

.|\n            {;}


%%


int     main    (int argc,char** argv)
        {
        slowa = 0;
        znaki = 0;
        //kopiujemy argc i argv bez nazwy aplikacji
        my_argc = --argc;//(6)
        my_argv = ++argv;
        if      (my_argc == 0)//(7)
                yyin = 0;
        else
                {
                yyin = fopen(*my_argv,"r");//(8)
                my_argc -= 1;
                ++my_argv;
                }
        return yylex();
        }