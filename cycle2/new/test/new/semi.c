#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
void bezier(int x[],int y[]);

/*int r=10;
void dda(float xc,float yc,float r)
{
int xd,yd,j=0;
float xc1,xc2,yc1,yc2,eps,sx,sy;
float val,i=0;
xc1=r;
yc1=0;
sx=xc1;
sy=yc1;

do
{
val=pow(2,i);
i++;
}
while(val<r);
eps=1/(pow(2,i-1));
do
{
xc2=xc1+yc1*eps;
yc2=yc1-eps*xc2;
xd=sin(j)*r;
yd=sin(90-j)*r;
circle(xc-xc2,yc-yc2,10);
line(xc-xc2-xd,yc-yc2+10+10+2+yd,xc-xc2+xd,yc-yc2+10+2+10-yd);
delay(500);
cleardevice();
if(yc-yc2>yc)
break;

xc1=xc2;
yc1=yc2;
j+=5;
}
while((yc1-sy)<eps||(sx-xc1)>eps);
//drawcircle(xc,yc,xc2,yc2);
delay(5000);
}
void bezier(int x[],int y[])
{
double t;
int j,k,xd,yd;
for(t=0.0,j=0,k=0;t<1.0;t+=0.0005,k++)
{
double xt=pow(1-t,3)*x[0]+3*t*pow(1-t,2)*x[1]+3*pow(t,2)*(1-t)*x[2]+pow(t,3)*x[3];
double yt=pow(1-t,3)*y[0]+3*t*pow(1-t,2)*y[1]+3*pow(t,2)*(1-t)*y[2]+pow(t,3)*y[3];
putpixel(xt,yt,RED);
/*setcolor(YELLOW);void bounce(int x[],int y[])
{
double t;
for(t=0.0;t<1.0;t+=0.0005)
{
double xt=pow(1-t,3)*x[0]+3*t*pow(1-t,2)*x[1]+3*pow(t,2)*(1-t)*x[2]+pow(t,3)*x[3];
double yt=pow(1-t,3)*y[0]+3*t*pow(1-t,2)*y[1]+3*pow(t,2)*(1-t)*y[2]+pow(t,3)*y[3];
setcolor(GREEN);
fillellipse(xt,yt,8,8);
fillellipse(xt-gl,yt,8,8);
fillellipse(xt+gl,yt+10,8,8);
delay(.5);
setcolor(BLACK);
fillellipse(xt,yt,8,8);
fillellipse(xt-gl,yt,8,8);
fillellipse(xt+gl,yt+10,8,8);
gl+=.08;
setcolor(BROWN);
bar(90,100,110,400);
}
}

if(k%50==0)
j++;
xd=cos(j)*r;
yd=cos(90-j)*r;
circle(xt,yt,r);
line(xt-xd,yt+yd,xt+xd,yt-yd);
delay(1);
cleardevice();
/*
setcolor(BLACK);
circle(xt,yt,10);
line(xt-xd,yt+yd,xt+xd,yt-yd);
*/
/*}
}
void main()
{
int gd=DETECT,gm,i,j,k,l=0,m,p;
double t;
int xd,yd;
initgraph(&gd,&gm,"");
int x=100,y=400;
int x1[]={100,150,200,350};
int y1[]={400,350,300,400};
int x2[]={400,356,250,100};
int y2[]={100,206,250,100};



setcolor(YELLOW);
line(50,100+r+1,400,100+r+1);
setcolor(RED);
for(i=400,p=100,j=0;i>100;i=i-5,p+=5,j+=10){
xd=cos(j)*r;
yd=cos(90-j)*r;
circle(i,100,r);
line(i-xd,100+yd,i+xd,100-yd);
setcolor(RED);
xd=sin(j)*r;
yd=sin(90-j)*r;
circle(p,100+r+2+r,r);
line(p-xd,100+r+r+2+yd,p+xd,100+r+2+r-yd);
delay(100);
cleardevice();
setcolor(YELLOW);
line(50,100+r+1,400,100+r+1);
}



//while(1){
//bezier(x1,y1);
bezier(x2,y2);
//}
dda(175,100+r+1,150);
getch();
}
*/
void main()
{
int gd=DETECT,gm,i,j,k,l=0,m,p;
double t;
int xd,yd;
initgraph(&gd,&gm,"");

int x[]={100,120,140,160,180};
int y[]={100,80,60,80,100};
bezier(x,y);

delay(1000);
closegraph();
getch();
}
/*void bounce(int x[],int y[])
{
double t;
for(t=0.0;t<1.0;t+=0.0005)
{
double xt=pow(1-t,4)*x[0]+4*t*pow(1-t,3)*x[1]+6*pow(t,2)*pow(1-t,2)*x[2]+4*pow(t,3)*(1-t)*x[3]+pow(t,4)*x[4];
double yt=pow(1-t,4)*y[0]+4*t*pow(1-t,3)*y[1]+6*pow(t,2)*pow(1-t,2)*y[2]+4*pow(t,3)*(1-t)*y[3]+pow(t,4)*y[4];
setcolor(GREEN);
fillellipse(xt,yt,8,8);
fillellipse(xt-gl,yt,8,8);
fillellipse(xt+gl,yt+10,8,8);
delay(.5);
setcolor(BLACK);
fillellipse(xt,yt,8,8);
fillellipse(xt-gl,yt,8,8);
fillellipse(xt+gl,yt+10,8,8);
gl+=.08;
setcolor(BROWN);
bar(90,100,110,400);
}
}*/
void bezier(int x[],int y[])
{
double t;
for(t=0.0;t<1.0;t+=0.0005)
{
double xt=pow(1-t,4)*x[0]+4*t*pow(1-t,3)*x[1]+6*pow(t,2)*pow(1-t,2)*x[2]+4*pow(t,3)*(1-t)*x[3]+pow(t,4)*x[4];
double yt=pow(1-t,4)*y[0]+4*t*pow(1-t,3)*y[1]+6*pow(t,2)*pow(1-t,2)*y[2]+4*pow(t,3)*(1-t)*y[3]+pow(t,4)*y[4];
putpixel(xt,yt,GREEN);
}
}

