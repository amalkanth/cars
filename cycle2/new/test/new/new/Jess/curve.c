/************************************************
 TITLE   : CURVE 
 AUTHOR  : KEVIN KURIAKOSE
 ROLL NO : 39
 DATE    : 08/02/2018
************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>
void bezier(int x[4],int y[4])
{
int i;
double t;
for(t=0.0;t<1.0;t+=0.0005)
{
double xt=pow(1-t,3)*x[0]+3*t*pow(1-t,2)*x[1]+3*pow(t,2)*(1-t)*x[2]+pow(t,3)*x[3];
double yt=pow(1-t,3)*y[0]+3*t*pow(1-t,2)*y[1]+3*pow(t,2)*(1-t)*y[2]+pow(t,3)*y[3];
putpixel(xt,yt,WHITE);
}
return;
}
void main()
{
int gd=DETECT,gm;
int a=0,b=50,c=100,d=150;
//int x5[4]={160,160,210,210},y5[4]={200,250,250,200};
//int x6[4]={210,210,210,210},y6[4]={200,250,250,200};
initgraph(&gd,&gm,"");
//bezier(x5,y5);
//bezier(x6,y6);
for(int i=0;i<100;i++)
{
//bezier(x1,y1);
int x2[4]={a,a,b,b},y2[4]={250,200,200,250};
int x3[4]={b,b,c,c},y3[4]={250,200,200,250};
int x4[4]={c,c,d,d},y4[4]={250,200,200,250};
cleardevice();
bezier(x2,y2);
bezier(x3,y3);
bezier(x4,y4);
a++;
b++;
c++;
d++;
getch();
}
getch();
}
