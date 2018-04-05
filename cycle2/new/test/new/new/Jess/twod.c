/************************************************
 TITLE   : TWO DIMENSIONAL TRANSFORMATION
 AUTHOR  : KEVIN KURIAKOSE
 ROLL NO : 39
 DATE    : 16/02/2018
************************************************/
#include<stdio.h>
#include<stdio.h>
#include<graphics.h>
#include<math.h>

int points[10][2];
int vertices=0;
void dda(int x1,int y1,int x2,int y2)
{
int k;
float steps,dx,dy,x,y,a,b;
dx=x2-x1;
dy=y2-y1;
if(abs(dx)>abs(dy))
steps=abs(dx);
else
steps=abs(dy);
if(steps!=0)
{
a=dx/steps;
b=dy/steps;
}
x=x1;
y=y1;
putpixel(x,y,3);
for(k=1;k<steps;k++)
{
x+=a;
y+=b;
putpixel((int)x,(int)y,3);
}
delay(1000);
}
void displaypoly()
{
int i;
for(i=0;i<vertices-1;i++)
{
dda(points[i][0],points[i][1],points[i+1][0],points[i+1][1]);
}
dda(points[vertices-1][0],points[vertices-1][1],points[0][0],points[0][1]);

}
void scale()
{
int i;
float sx,sy;
printf("\nSCALING\n ");
printf("ENTER SCALING FACTOR : ");
scanf("%f%f",&sx,&sy);
for(i=0;i<vertices;i++)
{
points[i][0]*=sx;
points[i][1]*=sy;
}
displaypoly();
}
void reflect()
{
int i,c,rx,ry;
do
{
printf("\nREFLECTION\n ");
printf("1.ABOUT X AXIS\t2.ABOUT Y AXIS");
printf("\nENTER CHOICE : ");
scanf("%i",&c);
if(c==1)
{
printf("\nY VALUE : ");
scanf("%i",&ry);
for(i=0;i<vertices;i++)
{
int t=ry-points[i][1];
points[i][1]+=2*t;
}
} 
else if(c==2)
{
printf("\nX VALUE ");
scanf("%i",&rx);
for(i=0;i<vertices;i++)
{
int t=rx-points[i][0];
points[i][0]+=2*t;
}
} 
displaypoly();
}
while(c<3);
}

void rotate()
{
int i,t1,t2,xa,ya,r;
float c;
printf("\nROTATION\n ");
printf("ENTER FIXED POINT (xf,yf): ");
scanf("%d%d",&xa,&ya);
printf("\nANGLE ");
scanf("%i",&r);
c=r*(3.14/180);
delay(1000);
for(i=0;i<vertices;i++)
{
t1=(xa+((points[i][0]-xa)*cos(c)-(points[i][1]-ya)*sin(c)));

t2=(ya+((points[i][0]-xa)*sin(c)+(points[i][1]-ya)*cos(c)));
points[i][0]=t1;
points[i][1]=t2;
delay(1000);
}
displaypoly();
}
void shear()
{
int i,ch,shx,shy,xref,yref;
do
{
printf("\nSHEARING\n ");
printf("ENTER REF POINT (xref,yref): ");
scanf("%d%d",&xref,&yref);
printf("\n1.WITH X AXIS\t2.WITH Y AXIS");
scanf("%i",&ch);
if(ch==1)
{
printf("\nENTER SHEAR FACTOR shx : ");
scanf("%i",&shx);
for(i=0;i<vertices;i++)
{
points[i][0]=points[i][0]+shx*(points[i][1]-yref);
points[i][1]=points[i][1];
}
displaypoly();
} 
else if(ch==2)
{
printf("\nENTER SHEAR FACTOR shy : ");
scanf("%i",&shy);
for(i=0;i<vertices;i++)
{
points[i][1]=points[i][1]+shx*(points[i][0]-xref);
points[i][0]=points[i][0];
}
displaypoly();
} 
}
while(ch<3);
}
void translate()
{
int tx,ty,i;
printf("\nTRANSLATION\n ");
printf("ENTER TRANSLATION VECTOR(tx,ty) : ");
scanf("%i%i",&tx,&ty);
for(i=0;i<vertices;i++)
{
points[i][0]+=tx;
points[i][1]+=ty;
}
displaypoly();
}
void main()
{
int gd=DETECT,gm=VGAMAX,i,choice;
printf("\nENTER NO. OF SIDES IN POLYGON : ");
scanf("%d",&vertices);
printf("\nENTER VERTICES\n");
for(i=0;i<vertices;i++)
	scanf("%i%i",&points[i][0],&points[i][1]);
initgraph(&gd,&gm,NULL);
displaypoly();
printf("\n***MENU***\n ");
printf("1.TRANSLATION\n2.ROTATION\n3.SCALING\n4.REFLECTION\n5.SHEARING\n6.EXIT");
do
{
printf("\nENTER CHOICE : ");
scanf("%i",&choice);
if(choice==6)
break;
else if(choice==1)
translate();
else if(choice==2)
rotate();
else if(choice==3)
scale();
else if(choice==4)
reflect();
else if(choice==5)
shear();
}while(choice<6);
delay(5000);
closegraph();
getch();
}
