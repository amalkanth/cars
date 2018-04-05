#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void bezier(int x[2],int y[2])
{
int i;
double t;
for(t=0.0;t<1.0;t+=0.0005)
{
double xt=pow(1-t,3)*x[0]+3*t*pow(1-t,2)*x[1];
double yt=pow(1-t,3)*y[0]+3*t*pow(1-t,2)*y[1];
putpixel(xt,yt,WHITE);
}
}
void main(){
int x[]={10,100};
int y[]={10,0};
int gd=DETECT,gm;
initgraph(&gd,&gm,"");
bezier(x,y);
getch();
}
