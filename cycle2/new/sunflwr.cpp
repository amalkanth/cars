#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>


void bezierarc(int xin,int yin)
{
  int i,x[4]={320,320,320}, y[4]={350,330,300};
  double t,xt,yt;
x[3]=xin;
y[3]=yin;
for(t=0;t<1;t+=.0005){
 xt=pow(1-t,3)*x[0] + 3*t*pow(1-t,2)*x[1]+ 3*pow(t,2)*(1-t)*x[2] + pow(t,3)*x[3];
 yt=pow(1-t,3)*y[0] + 3*t*pow(1-t,2)*y[1]+ 3*pow(t,2)*(1-t)*y[2] + pow(t,3)*y[3];
 putpixel(xt,yt,GREEN);
}

}

void bgskeleton()
{
line(0,400,getmaxx(),400);
setcolor(GREEN);
line(320,400,320,350);
setcolor(WHITE);
}

void flower(int x,int y)
{
/* setcolor(WHITE);
ellipse(430-k,300-j,0,360,10+i,3+j);
fillellipse(430-k,300-j,10+i,3+j);
setcolor(RED);
circle(430-k,300-j,3);
fillellipse(430-k,300-j,3,3);*/
setcolor(YELLOW);
fillellipse(x+18,y,13,11);
fillellipse(x,y-18,11,13);
fillellipse(x-18,y,13,11);
fillellipse(x,y+18,11,13);
setcolor(RED);
if((x+80)<320)
 fillellipse(x,y,5-(x/(640/11)),10);
else
 fillellipse(x,y,3+(x/(640/11)),10);
}

void drawsun(int i)
{
 setcolor(RED);
fillellipse(250+i*9,120+abs(i),15,15);
}

int main()
{
int gd=DETECT,gm,i;
initgraph(&gd,&gm,"");
bgskeleton();
bezierarc(320-(1.2*35),280+35);
for(i=-35;i<36;i++)
{
setcolor(BLACK);
fillellipse(300,230,300,300);

bgskeleton();
bezierarc(320+(1.2*i),280+abs(i));
flower(320+(1.2*i),280+abs(i));
drawsun(i);
delay(1000);
}
getch();
closegraph();
return 0;
}

