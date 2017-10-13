/*Write a program to identify identifiers,keywords etc*/

digit [0-9]
letter [a-zA-Z]
space [ ]
quote ["]
%%
{space} {}
"<"|">"|"<="|">="|"!="|"==" {printf("\n%s : RELATIONAL OPERATOR",yytext);}
"+"|"-"|"*"|"/" {printf("\n%s : ARITHMETIC OPERATOR",yytext);}
"=" {printf("\n%s : ASSIGNMENT OPERATOR",yytext);}
"#"|","|";"|":"|"["|"{"|"("|")"|"}"|"]"|"&"|{quote} {printf("\n%s : SPEACIAL SYMBOL",yytext);}
"%d"|"%c"|"%f"|"%s" {printf("\n%s : FORMAT SPECIFIER",yytext);}
"int"|"float"|"char"|"if"|"void"|"for"|"while"|"printf"|"scanf"|"include"|"stdio.h" {printf("\n%s : KEYWORD",yytext);}
{letter}({letter}|{digit})*("11")+ {printf("\n%s : IDENTIFIER",yytext);}
{digit}+"."{digit}+ {printf("\n%s :  FLOATING POINT NUMBER",yytext);}
{digit}+ {printf("\n%s : INTEGER",yytext);}
. {printf("\n%s : UN IDENTIFIED LEXEME",yytext);}
%%
main(int argc,char* argv[])
{
 yyin=fopen(argv[1],"r");
 yylex();
}

