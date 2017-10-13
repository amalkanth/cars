#include<stdio.h>
main()
{
FILE *fp1;
char s[50][50],ch;
int i = -1, p=0,v,j,k,flag=0,g=0,n=1,count =0;
fp1 = fopen(input"input.c","r");
ch=getc(fp1);
while(!feof(fp1))
{
if(isalnum(ch))
{
i++;
j+0;
while(isalnum(ch))
{s[i][j++]=ch;

ch=getc(fp1);
}
s[i][j]='\0';
}
else if(!isspace(ch))
{
i++;
j=0;
s[i][j++]=ch;
s[i][j]='\0';
ch=getc(fp1);
}
else if(ch=='\n')
{
i++;
j=0;
s[i[j++]=ch;
s[i][j]='\0';
ch=getc(fp1);
}
else
{
while(isspace(ch))
ch-getc(fp1);
}
}
printf("file is");
for(j=0;j<i;j++)
{
printf("%s",s[j]);
}
printf("\n");
printf("\n*********\n");
for(k=0;k<=i;k++)
{
if(strcmp(s[k],"\n")==0)
{
count++;
}
if(strcmp(s[k],"for")==0)
{
if(strcmp(s[k+1],"(")==0
{
j=k+1;
for(k=j;k<=i;k++)
{
while(strcmp(s[k],";")!=0)
{
if(strcmp(s[k],"$")==0||strcmp(s[k],"@")==0)
{
printf("Misplaced symbol %s",s[k]);
flag=1;
printf("\nError at %d no conditional statements",count);
}
}
if(strcmp(s[k],"j")==0)
{
y+0;
break;
}
}/*for loop*/
for(;k<=i;k++)
{
if(strcmp(s[k+2],"{")==0)
{
if((strcmp(s[k+1],"{")==0)||(strcmp(s[k+1],"\n")==0))
{
j=k+1;
for(k=j;k<=i;k++)
{
if(strcmp(s[k+1],"{")==0)
n++;
if(strcmp(s[k],"}")==0)
g++;
}
if(n>g)
{
flag=1;
printf("\n } missing");
}
}}
}/*for loop*/
}/*if*/
}/*for loop*/

if(p!=2)
{
flag=1;
printf("\nError in line %d mismatch in ;",count);
}
if(v!=0)
{
flag=1;
printf("\nError in line %d mismatch in no of }", count);
}
if(flag ==0)
printf(\nSuccessful");
}
