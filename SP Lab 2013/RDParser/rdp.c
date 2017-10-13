#include<stdio.h>
void parser();
void E();
void EPRIME();
void T();
void TPRIME();
void F();
void advance();
void errors();
int t=0;
int i,f;
char c;
char a[100];

void parser()
{
 int i=0,f=0;
 printf("\n enter the string \n");
 scanf("%s",a);
 c=a[i];
 E();
 if(c=='\0'&&f==0)
  printf("\n ACCEPTED \n");
 else
  errors();
}

void E()
{
 T();
 EPRIME();
}

void EPRIME()
{
 if(c=='+')
  {
   advance();
   T();
   EPRIME();
  }
}


void T()
{
 F();
 TPRIME();
}

void TPRIME()
{
 if(c=='*')
  {
    advance();
    F();
    TPRIME();
  }
}

void F()
{
  if(c=='(')
   {
    advance();
    E();
    if(c==')')
     advance();
    else
     errors();
   }
  else
   {
    if(isalpha(c)||isdigit(c))
     advance();
    else
     errors();
   }
}

void advance()
{
  i++;
  c=a[i];
}
 
void errors()
{
  if(t!=1)
   {
    printf("\n INVALID \n");
    t=1;
    f=1;
   }
}

void main()
{
  parser();
}

