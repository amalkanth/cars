 
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int no=0,top=-1;
char stack[50];
void error1();
void error2();
void push(char x)
{
stack[++top]=x;
}
char pop()
{
char x=stack[top];
top--;
return(x);
}
int priority(char x)
{
if(x=='*'||x=='/')
return 2;
else if(x=='+'||x=='-')
return 1;
else
return 0;
}
void main()
  {
int i,flag1=0,flag=0,j=0,n,len,z=0,op=0;
char str[50],le[20],x,y,oparray[20],right[20],post[50];
printf("enter the no of producions");
scanf("%d",&n);
for(i=0;i<n;i++)
{
 printf("enter left\t");
 scanf("%s",le);
printf("enter right\t");
scanf("%s",right);
if(right[0]=='(')
flag=1;
else if((right[1]=='+')||(right[1]=='-')||(right[1]=='*')||(right[1]=='/'))
{
oparray[op]=right[1];
op++;
}
}
printf("\nexpression\t");
scanf("%s",str);
len=strlen(str);
for(i=0;i<len;i++)
  {
    if(isalpha(str[i]))
    {
      post[j]=str[i];
      j++;
    }
else if(str[i]=='(')
    {
    if(flag==0)
       error1();
    else
   { 
       push(str[i]);printf("%s\n",stack);
       }
       
       
    }
 else if(str[i]==')')
   {
  char x=pop();
  while(x!='(')
   {
     post[j]=x;
     x=pop();
     j++;
   }
  }
else
  {
    if(top==-1)
    {
     push(str[i]);printf("%s\n",stack);
     }
   else if(priority(str[i])>priority(stack[top]))
       { printf("%s\n",stack);push(str[i]);}
       else
       {
         char x=pop();
         while(priority(x)>priority(str[i]))
            {
              post[j++]=x;
              x=pop();
             }
           push(str[i]);
           printf("%s\n",stack);
        }
     }
  }
  while(top!=-1)
    {
     post[j++]=pop();
    }
   post[j]='\0';
   for(i=0;i<strlen(post);i++)
       {
         if(isalpha(post[i]))
          { 
            push(post[i]);
            printf("%s\n",stack);
            }
         else
           {
            x=pop();
            y=pop();
            if((isalpha(x))&&(isalpha(y)))
             {
              flag1=0;
              for(z=0;z<op;z++)
                {
                  if(post[i]==oparray[z])
                    flag1=1;
                 }
              if(flag1==0)
                 error2();
              else{
              
                push(x);
                   printf("%s\n",stack);
                   }
             }
             else
              error1();
        }
       }
    if(top==-1||top==0)
	printf("valid\n");
   else

      printf("invalid\n");
  getch();
  }

void error1()
   {
     printf("\nsystem error");
     
   }
void error2()
   {
     printf("\n invalid operator");
    
   }
