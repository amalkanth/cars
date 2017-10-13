/*Write a YACC program to implement complex calculator*/

%{
#include<stdio.h>
#include<ctype.h>
#define YYSTYPE double
%}
%token DIGIT
%left '+' '-'
%left '*' '/'
%right UMINUS
%%
lines :  lines expr '\n' {printf("%g\n",$2);}
	|lines '\n'
	|/*empty*/
	|error '\n'{yyerror("reenter last line");yyerrok;}
	;

expr: expr '+' expr {$$ = $1 + $3 ; }
	| expr '-' expr {$$ = $1 - $3 ; }
	| expr '*' expr {$$ = $1 * $3 ; }
	| expr '/' expr {$$ = $1 / $3 ; }
	| '(' expr ')' {$$=$2;}
	| '-' expr %prec UMINUS {$$ = - $2; }
	| DIGIT
	;

%%
//#include "lex.yy.c"
yylex(){
int c;
while((c=getchar())== ' ');
if((c=='.')||(isdigit(c))){
ungetc(c,stdin);
scanf("%lf",&yylval);
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
