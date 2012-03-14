%{
#include <stdio.h>
#include "y.tab.h"
%}
 
%%

#.*\n		{;}

[=+\-*/()]	return *yytext;

[0-9]+		{ yylval = atoi(yytext); return INTEGER; }

[a-zA-z_$@][a-zA-Z0-9_$@]+ { yylval = yytext;return NAME; }
    
.|\n		{;}


%%


int main    (int argc,char** argv)
{
    slowa = 0;
    znaki = 0;

    my_argc = --argc;
    my_argv = ++argv;

    if(my_argc == 0)
	yyin = 0;
    else
    {
	yyin = fopen(*my_argv,"r");//(8)
	my_argc -= 1;
	++my_argv;
    }
    return yylex();
}
