/*Perform common subexpression elimination for a given intermediate code*/

#include<stdio.h>
#include<string.h>
#include<string.h>
int val[100],line=0,idno=0,i=0,j,l,after=0,k,val1,val2,val3,val4,x,y;
char id[100],cur[100],c,rig[100][100],chk[100];
int check(int a,int b)
{
	//printf("%d,%d",a,b);
	c=rig[a][0];
	//printf("%c",c);
	for(x=a-1;x>0;x--)
	{
		//printf("%d ,%c ",x,id[x]);
		if(c==id[x])
			{val1=val[x];	break;}
	}
	c=rig[a][2];
		//printf("%c",c);
	for(x=a-1;x>0;x--)
	{
		if(c==id[x])
			{val2=val[x];	break;}
	}
	c=rig[b][0];
		//printf("%c",c);
	for(x=b-1;x>0;x--)
	{
		if(c==id[x])
			{val3=val[x];break;}
	}
	c=rig[b][2];
		//printf("%c",c);
	for(x=b-1;x>0;x--)
	{
		if(c==id[x])
			{val4=val[x];break;}
	}
	if((val1==val3)&&(val2==val4))
		return 1;
	else
		return 0;
}
main()
{
	FILE *fp;
	fp=fopen("input.txt","r");
	while((fgets(cur,100,fp))!=NULL)
	{
		after=0;
		for(i=0;cur[i]!='\0';i++)
		{
			c=cur[i];
			//printf("%c ",c);
			if(c=='=')
			{
				k=0;
				after=1;
				i++;
				while(cur[i]!='\0')
					rig[line][k++]=cur[i++];
				rig[line][k]='\0';
			}
			if((isalnum(c))&&after==0)
			{
				//printf("%c ",c);
				id[idno]=c;
				val[idno]=line;
				idno++;
			}
		}
		line++;
	}
	for(i=0;i<idno;i++)
	{
		printf("%c,%d\n",id[i],val[i]);
	}
	for(i=0;i<line;i++)
		printf("%s",rig[i]);
	rewind(fp);
	for(i=0;i<line;i++)
	{
		y=0;
		k=0;
		for(j=0;rig[i][j]!='\0';j++)
		{
			chk[k++]=rig[i][j];
		}
		chk[k]='\0';
		//printf("%s",chk);
		for(l=i+1;l<line;l++)
		{
			//printf("%s",rig[l]);
			if(strcmp(chk,rig[l])==0)
			{
				y=check(i,l);
				break;
			}
		}
		if(y==1)
		{
			for(l;l<line;l++)
			{
				strcpy(rig[l],rig[l+1]);
				id[l]=id[l+1];
				val[l]=val[l+1];
			}
			idno--;
			line--;i--;
		}
	}
	for(i=0;i<line;i++)
	{
		printf("%c,%d %s\n",id[i],val[i],rig[i]);
	}
}
