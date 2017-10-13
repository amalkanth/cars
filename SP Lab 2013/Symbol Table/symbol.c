#include<stdio.h>
#include<ctype.h>
#include<string.h>
struct symbol
{
char variable[10];
char type[10];
int size;
int initial_value;
char scope[10];
}s[20];
main()
{FILE *fp,*fp1;
char ch,a[20],b[20],id=0,scop[20]="main",p;
int i=0,j=0,flag=0,no=0,m=0,siz=0,n=0;
fp=fopen("input.c","r");
fp1=fopen("output.c","w");
fprintf(fp1,"variable\t datatype \t size \t initialvalue \t scope \n");
label:while((!feof(fp)))
{
ch=fgetc(fp);
if(isalpha(ch)!=0)
{
a[i]=ch;
i++;
}
else
{
a[i]='\0';
i=0;
if((strcmp(a,"int")==0)||(strcmp(a,"char")==0)||(strcmp(a,"float")==0))
{
id='$';
j=0;
ch=getc(fp);
while(isalpha(ch)!=0)
{
b[j]=ch;
j++;
ch=getc(fp);
}
b[j]='\0';
if(ch=='(')
{
p=getc(fp);
if(p==')')
{
flag=1;
strcpy(scop,b);
}
goto label;
}
siz=0;
if(ch=='[')
{
p=getc(fp);
while(p!=']')
{
n=p-48;
siz=siz*10+n;
p=getc(fp);
}
}
else
siz=1;
if(ch=='=')
id=getc(fp);
strcpy(s[no].variable,b);
strcpy(s[no].type,a);
s[no].size=siz;
s[no].initial_value=id;
if(flag==0)
strcpy(s[no].scope,"global");
else
strcpy(s[no].scope,scop);
no++;
flag=0;
}
}
}
for(n=0;n<no;n++)
{
fprintf(fp1,"%s\t\t",s[n].variable);
fprintf(fp1,"%s\t\t",s[n].type);
if(strcmp(s[n].type,"int")==0)
m=2;
else if(strcmp(s[n].type,"char")==0)
m=1;
else if(strcmp(s[n].type,"float")==0)
m=4;
else if(strcmp(s[n].type,"double")==0)
m=8;
else
m=0;
fprintf(fp1,"%d\t\t",m*s[n].size);
if(strcmp(s[n].type,"float")==0)
fprintf(fp1,"%c.0\t\t",s[n].initial_value);
else
fprintf(fp1,"%c\t\t",s[n].initial_value);
fprintf(fp1,"%s\n",s[n].scope);
}
fclose(fp);
fclose(fp1);
}




