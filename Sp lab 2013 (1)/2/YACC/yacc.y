/* SIMPLE CALCULATOR*/

%{
#include<stdio.h>
#include<ctype.h>
%}
%token DIGIT
%%
line:expr '\n' {printf("%d\n",$1);}
expr:expr '+' term {$$=$1+$3;}
	|term
	;
term:term '*' factor{$$=$1*$3;}
	|factor
	;
factor:'(' expr ')' {$$=$2;}
	|DIGIT
	;
%%
yylex(){
int c;
c=getchar();
if(isdigit(c)){
yylval=c-'0';
return DIGIT;
}
return c;
}
main()
{
return yyparse();
}
int yyerror(char *s)
{
fprintf(stderr,"%s\n",s);

}