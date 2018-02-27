
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
int main()
{
float x,y,x1,y1,x2,y2,dx,dy,steps,p;
int i,gd=DETECT,gm,ch;
printf("\nENTER ENDPOINTS(x1,y1) : ");
scanf("%f%f",&x1,&y1);
printf("\nENTER ENDPOINTS(x2,y2) : ");
scanf("%f%f",&x2,&y2);
printf("\n1.BRESENHAM 2. DDA");
scanf("%d",&ch);
detectgraph(&gd,&gm);
initgraph(&gd,&gm,"");
if(ch==2)
{
dx=abs(x2-x1);
dy=abs(y2-y1);
if(dx>=dy)
steps=dx;
else
steps=dy;
dx=dx/steps;
dy=dy/steps;
x=x1;
y=y1;
i=1;
putpixel(x,y,33);
while(i<=steps)
{
if(x<=x2)
x=x+dx;
else
x=x-dx;
if(y<=y2)
y=y+dy;
else
y=y-dy;
i=i+1;
delay(100);
putpixel(x,y,33);
}
}
else
{
dx=abs(x2-x1);
dy=abs(y2-y1);
p=2*dy-dx;
x=x1;
y=y1;
putpixel(x,y,5);
if(x==x2 && y==y2) {delay(10000);exit(0);}
while(x<=x2||y<=y2)
{
if(p>=0)
{
p=p+2*dy-2*dx;
y=y+1;
}else
{
p=p+2*dy;
y=y;
}
if(x<=x2)
x=x+1;
if(x>x2)
x=x-1;
delay(100);
putpixel(x,y,5);
if(x==x2 &&y==y2)break;
}
delay(100);
}
getch();
closegraph();
return 0;
}

