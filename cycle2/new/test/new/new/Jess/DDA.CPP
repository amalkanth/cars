
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>

void linedda(float x0,float y0, float x1, float y1)
{
float dx=x1-x0;
float dy=y1-y0;
float steps;
int k;

float xi,yi,x=x0,y=y0;
if(x1==x0 && y1==y0)
{
putpixel(x,y,RED);
return;
}
if(abs(dx)>abs(dy))
  steps=abs(dx);
else
 steps=abs(dy);

xi=dx/steps;
yi=dy/steps;
     // printf("\n[%f,%f]",x,y);
putpixel(x,y,RED);

for(k=0;k<steps;k++)
{
x+=xi;
y+=yi;
putpixel(x,y,RED);
}
}

void bres(float x1,float y1,float x2,float y2)
{
float dx,dy,di,ds,dt;
dx=x2-x1;
dy=y2-y1;
di=2*dy-dx;
dt=2*(dy-dx);
ds=2*dy;

putpixel(x1,y1,RED);
if(dx==0)
{
  while(y1<y2){
   y1++;
   putpixel(x1,y1,RED);
   }
}

if(x1<x2)
{ while(x1<x2)
  {
   x1++;
   if(di<0)
    di=di+ds;
   else{
    y1++;
    di=di+dt;
   }
   putpixel(x1,y1,RED);
  }
}
else if(y1<y2)
{
  while(x1>x2)
  { x1--;
    if(di<0)
      di=di+ds;
    else
    { y1++;
      di=di+dt;
    }
    putpixel(x1,y1,RED);
  }
}

}

void main()
{
float x1,x2,y1,y2;

int gdriver , gmode,ch;

detectgraph(&gdriver,&gmode);
initgraph(&gdriver, &gmode, "" );

do{
printf("\n1. DDA\n2. Bressenhams\n0. EXIT\n Enter Choice: ");
scanf("%i",&ch);
if(ch==0)
 exit(0);

printf("\nEnter The coordinates:\n point 1: ");
scanf("%f%f",&x1,&y1);
printf("\n point 2: ");
scanf("%f%f",&x2,&y2);
clrscr();
if(ch==1)
  linedda(x1,y1,x2,y2);
else if(ch==2)
  linedda(x1,y1,x2,y2);
}while(ch!=0);
closegraph();
}
