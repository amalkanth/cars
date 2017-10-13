/*TO DESIGN A 2-PASS ASSEMBLER*/

#include<stdio.h>
#include<string.h>
//#include<conio.h>
 FILE *fp,*fp1;
 int i=0,j=0,found=0,k,z;
 int count=4100,hexval[100]={3,1,2,1,3,1,3,1,1,1,2,1},coun,m,val,flag=0,y=0;
 char b,opcode[100][10]={{"lda"},{"movb,a"},{"mvic"},{"addb"},{"jnc"},{"inrc"},{"sta"},{"mova,c"},{"subb"},{"cma"},{"adi"},{"hlt"}};
 char hex[100][4]={{"3A"},{"47"},{"0E"},{"80"},{"D2"},{"0C"},{"32"},{"79"},{"90"},{"2F"},{"C6"},{"76"}},ch[10],a[10],c[10],q[10];
 char label[10][10];
 int lblval[10],n,m,o,p,calad[10];
 
void main()
{
		char file[20],ch[50];
		int s,f=0;
		//printf("\n Enter input file name : ");
		//scanf("%s",file);
		fp=fopen("in.asm","r");
		fp1=fopen("in.asm","r");
		if(fp==NULL)
			{	printf("\n File open failed!\n");
				fclose(fp);
				return;
			}
		printf("\n File opened..");
			
		while((fscanf(fp1,"%s",ch))!=EOF)
		{
		f=0;
		for(i=0;i<100;i++)
					{
					if((strcmp(ch,opcode[i]))==0 && hexval[i]==1)
					{ 
					count++;
					f=1;
					break;
					}
					else if((strcmp(ch,opcode[i]))==0 && (hexval[i]==2))
					{
					count=count+2;
					fscanf(fp1,"%s",ch);
					f=1;
					break;
					}
					else if((strcmp(ch,opcode[i]))==0 && hexval[i]==3)
					{
					count=count+3;
					fscanf(fp1,"%s",ch);
					f=1;
					break;
					}
					
					}
					if(f!=1)
					{
					strcpy(label[y],ch);
					lblval[y++]=count;
					}
					
					
		}
		count=4100;
		while((fscanf(fp,"%s",ch))!=EOF)
			{		
					for(i=0;i<100;i++)
					{
					if((strcmp(ch,opcode[i]))==0)
					{ f=1;break;
					}
					}
					if(i=100)
					{
					strcpy(label[y],ch);
					lblval[y++]=count;
					}
										for(i=0;i<100;i++)
										{
										if(strcmp(ch,opcode[i])==0 && hexval[i]==2)
										{
										fscanf(fp,"%s",a);
										found=0;
										b=a[0];
										j=0;
										j=j+1;
										
										for(k=0;a[j]!='\0';j++)
										c[k++]=a[j];
										found=1;
										break;
										}
										else if(strcmp(ch,opcode[i])==0 && hexval[i]==1)
										{
										/*if(strcmp(opcode[i],"hlt")==0)
										count=calad*/
										found=1;break;
										}
										else if(strcmp(ch,opcode[i])==0&&hexval[i]==3)
										{
										fscanf(fp,"%s",q);
										/*if(strcmp(ch,"call")==0)
											strcpy(calad,q);*/
										found=1;
										break;
										}
							}
					
					if(found==1)
						{	coun=count;
							while(count!=coun+hexval[i])
							{
								if(hexval[i]==2)
								{
								
								printf("\n%d  %s ",count,hex[i]);
								count++;
								printf("\n%d  %s ",count,c);
								count++;
								 }	
								 if(hexval[i]==1)
								{
								
								printf("\n%d  %s ",count,hex[i]);
								count++;
								
								 }	
								if(hexval[i]==3)
								{
								
								for(z=0;z<y-1;z++)
								{
								if((strcmp(label[z],q))==0)
								{
								flag=1;
								break;
								}
								}
								if(flag==1)
								{
								//printf("%d",lblval[m]);
								val=lblval[z];
								m=val%10;
								val/=10;
								n=val%10;
								val/=10;
								o=val%10;
								val/=10;
								p=val%10;
								flag=0;
								printf("\n%d  %s ",count,hex[i]);
								count++;
								printf("\n%d  %d%d ",count,n,m);
								count++;
								printf("\n%d  %d%d",count,p,o);
								count++;
								}
								else
								{
								printf("\n%d  %s ",count,hex[i]);
								count++;
								printf("\n%d  %c%c ",count,q[2],q[3]);
								count++;
								printf("\n%d  %c%c",count,q[0],q[1]);
								count++;
								}
								}	
							 }						
						}
					//printf("\n %s",ch);
					strcpy(ch," ");					
					b=' ';
					for(i=0;i<10;i++)
					{
					c[i]=NULL;
					//printf("%s\n",c);
					//printf("%s\n",a);
					a[i]=NULL;		
					//printf("%s\n",a);
					}
					
			}
		fclose(fp);
		
}

