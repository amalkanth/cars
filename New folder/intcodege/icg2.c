/*Write a pgm to represent a given arithmetic expression in tuples and quadruples*/

#include<stdio.h>
#include<string.h>
int priority(char);
void push(char);
char pop();
void postfix();
void generate();
int stack[50],top=-1,n1=0,b=0,r=0;
char expr[50],post[50],table[50][50],quad[50][50];
char p[20]={'1','2','3','4','5','6','7'};
main()
{
 int i,j;
 printf("\nenter the expression\n");
 scanf("%s",expr);
 postfix();
 printf("\npostfix expression is %s\n",post);
 generate();
 printf("\ntriple form is\n");
 for(i=0;i<=n1;i++)
{
 for(j=0;j<4;j++)
{
 printf("%c\t",table[i][j]);
}
printf("\n");
}/*triple */

for(i=0;i<=n1;i++)
{
 
  quad[i][0]=table[i][1];
  quad[i][1]=table[i][2];
  quad[i][2]=table[i][3];
}
 

printf("\nquadriple form is\n");
 for(i=0;i<=n1;i++)
{
 
 for(j=0;j<3;j++)
{
 if(isdigit(quad[i][j]))
 {
  printf("T");
 }
 printf("%c\t",quad[i][j]);
}
if(r!=0)
{
printf("T");
 printf("%d\t",r);
}
 r++;
printf("\n");
}/*quadriple */ 
}/* close main*/
void push(char a)

{
 top++;
 stack[top]=a;
 }
 char pop()
{
 char r;
 r=stack[top];
 top--;
 return r;
}
int priority(char a)
{
 if(a=='^')
 return 4;
 else if(a=='/'||a=='*')
 return 3;
 else if(a=='+'||a=='-')
 return 2;
 else
 return 1;
}
void postfix()
{
 int k=0,ps,pr,l,j;
 char t;
 l=strlen(expr);
 for(j=0;j<l;j++)
 {
 if(expr[j]!='('&&expr[j]!=')')
 {
  ps=priority(stack[top]);
  pr=priority(expr[j]);
  if(isalpha(expr[j])!=0)
  {
  
   post[k++]=expr[j];
  }
  else if((top==-1)||(ps<pr))
  push(expr[j]);

  else
  {
   t=pop();
   push(expr[j]);
   
   post[k++]=t;
  }
 }
 }
 for(;top>-1;)
 {
  post[k++]=pop();
 } 
 while(top>-1)
 {
 post[k++]=pop();
 }
 post[k]='\0';
}
void generate()
{
 char a1,a2,a3,x;
 int l,j,flag=0,h;
 l=strlen(post);
 for(j=0;j<l;j++)
 {
  if(isalpha(post[j]))
  {
   push(post[j]);
  }
  else
  {
   flag=0;
   a1=pop();
   if(top!=-1)
   a2=pop();
   for(h=0;h<n1;h++)
   {
    if(post[j]==table[h][1]&&a1==table[h][2]&&a2==table[h][3])
    {
     x=h;
     flag=1;
    }
    else if(post[j]==table[h][1]&&a1==table[h][3]&&a3==table[h][2])
    {
     x=h;
     flag=1;
    }
    else
    flag=0;
   }
    if(flag==0)
    {
     n1++;
    table[n1][0]=p[b];
    table[n1][1]=post[j];
    table[n1][2]=a1;
    table[n1][3]=a2;
    push(p[b]);
    b++;
    }
   }
  
}
}


   















   



