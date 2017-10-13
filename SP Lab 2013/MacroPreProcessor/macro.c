#include<stdio.h>
#include<string.h>
char comp();
char mname[20][20],mbody[10][10],mpara[10],c,ch[80],temp,a[20];
int i=0,j,k;
FILE *fp1,*fp2;

void main()
{
	fp1=fopen("def.c","r");
	while((fscanf(fp1,"%s",ch))!=EOF)
	{
		if((strcmp(ch,"#define"))==0)
		{
		j=0;
		c=getc(fp1);
		while((c=getc(fp1))!='(')
		{
			mname[i][j]=c;
			j++;
		}
		c=getc(fp1);
		mpara[i]=c;
		c=getc(fp1);
		fscanf(fp1,"%s",ch);
		strcpy(mbody[i],ch);
		i++;
		}
	}
	
	printf("\nMACRO\nMNAME\tMPARA\tMBODY\n");
	for(j=0;j<i;j++)
		{
		printf("%s\t%c\t%s\t\n",mname[j],mpara[j],mbody[j]);
		}
	printf("\npass1\n");
	fclose(fp1);
	fp1=fopen("def.c","r");
	fp2=fopen("pass1.txt","w+");
	while((c=getc(fp1))!=EOF)
	{
		if(c=='#')
		{
		while((c=getc(fp1))!='\n');
		}
		else
		putc(c,fp2);
	}
	rewind(fp2);

	while((c=getc(fp2))!=EOF)
	printf("%c",c);
	fclose(fp1);
	
	printf("\nPASS2\n\t");
	rewind(fp2);
	fp1=fopen("output.txt","w+");
	c=getc(fp2);
	while(c!=EOF)
	{
		if(isalnum(c))
		{
			j=0;
			while(isalnum(c))
			{
			a[j++]=c;
			a[j]='\0';
			c=getc(fp2);
			}

			if((k=comp())!=-1)
			{
				c=getc(fp2);
				temp=c;
				for(j=0;mbody[k][j]!='\0';j++)
				{
					if (mpara[k]==mbody[k][j])
					putc(temp,fp1);
					else
					putc(mbody[k][j],fp1);
				}
				c=getc(fp2);
				c=getc(fp2);
			}
			
			else
				fputs(a,fp1);
		}
		else
			{
			putc(c,fp1);
			c=getc(fp2);
			}
	}
	rewind(fp1);
	while((c=getc(fp1))!=EOF)
	{
		printf("%c",c);
	}
	fclose(fp1);
	fclose(fp2);
}


char comp()
{
	for(k=0;k<i;k++)
	{
	if((strcmp(a,mname[k]))==0)
	return(k);
	}
	return(-1);
}

		
