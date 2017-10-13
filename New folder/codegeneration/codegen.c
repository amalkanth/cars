/*Generate code for 8085 for an arithmetic operation*/

#include<stdio.h>
#include<ctype.h>
#include<string.h>
void push(char);
void output(char);
int isp(char);
char pop();
void code();
char exp[100],s[100],rex[100],item,x;
int count=20480,i=0,z=0,addr,addr1,l,top=0;
void main()
{
printf("\nenter the expression\n");  //READING EXPRESSION
gets(exp);
push('#');  //PUSHING END MARKER


while((item=exp[i])!='\0')      //INFIX TO POSTFIX CONVERSION
{
if((item>='a'&&item<'z')||(item>='A'&&item<'Z'))
output(item);
else if(item=='(')
push(item);
else if(item==')')
{
while((x=pop())!='(')
output(x);
}
else if(isp(x=pop())<isp(item))    //?which of 2 element's priority is checked?//
{
push(x);
push(item);
}
else
{
output(x);    //?x or item?//
push(item);
}
i++;
}


while((x=pop())!='#')
output(x);
printf("\nthe postfix expression is %s",rex);   //DISPLAY POSTFIX
printf("\n\n");
printf("499d LXI H,6000");//CODE GENERATION
l=strlen(rex);
for(i=0;i<l;i++)
{
if(isalnum(rex[i]))
{
printf("\n%x MVI A,%c\n",count,rex[i]);
count=count+2;
printf("%x PUSH A",count++);
}
else if(!isalnum(rex[i]))
{
printf("\n%x POP B\n",count++);
printf("%x POP A\n",count++);
code();
}
}  //for
printf("%x HLT\n",count);

} //main


void push(char item)             //PUSHING TO STACK
{	top=top+1;
	s[top]=item;
}


char pop()    //POPING FROM STACK
{
char item;
item=s[top];
top=top-1;
return item;
}


void output(char item)               //OUTPUT STACK
{
rex[z++]=item;
}


int isp(char item)                         //CHECKING PRIORITIES
{
if((item=='+')||(item=='-'))
return(1);
if((item=='*')||(item=='/'))
return(2);
if(item=='^')
return(3);
else return(0);
}
void code()                          //CODE GENERATION
{
if(rex[i]=='+')
printf("%x ADD B\n",count++);
else if(rex[i]=='-')
printf("%x SUB B\n",count++);
else if(rex[i]=='*')
{
printf("%x MOV C,A\n",count++);
printf("%x MVI A,00\n",count++);
count=count+2;
addr=count;
printf("%x ADD B\n",count++);
printf("%x DCR C\n",count++);
printf("%x JNZ %x\n",count,addr);
count=count+3;
}
else if(rex[i]=='/')
{
printf("%x MVI C,00\n",count++);
count=count+2;
addr1=count;
printf("%x INR C\n",count++);
printf("%x SUB B\n",count++);
printf("%x JNZ %x\n",count,addr1);
count=count+3;
printf("%x MOV A,C\n",count++);
}
printf("%x PUSH A\n",count++);
}
