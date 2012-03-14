%{
    #include <stdlib.h>
    #include <stdio.h>
    int yylex(void); 
    void yyerror(char* );
%}
%token INTEGER
%token NAME

%%

%%

int main()
{
    yyparse();
    return 0;
}