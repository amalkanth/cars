#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
void bezier(int x[],int y[])
{
double t;
for(t=0.0;t<1.0;t+=0.0005)
{
double xt=pow(1-t,3)*x[0]+3*t*pow(1-t,2)*x[1]+3*pow(t,2)*(1-t)*x[2]+pow(t,3)*x[3];
double yt=pow(1-t,3)*y[0]+3*t*pow(1-t,2)*y[1]+3*pow(t,2)*(1-t)*y[2]+pow(t,3)*y[3];
putpixel(xt,yt,GREEN);
}
}

int main()
{
int gd=DETECT,gm;
int x[]={50,400,225,50};
int y[]={100,100,275,100};
initgraph(&gd,&gm,"");
bezier(x,y);
getch();
return 0;
}
