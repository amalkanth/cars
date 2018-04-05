#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
float gl=15;
int i;
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

void bounce(int x[],int y[])
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

void drawtree()
{
setcolor(BROWN);
bar(100,100,120,400);
int x[4]={20,40,80,100};
int y[4]={100,80,80,100};
int x1[4]={100,120,160,180};
int y1[4]={100,80,80,100};
int x2[4]={40,50,80,100};
int y2[4]={50,45,60,100};
int x3[4]={100,120,140,160};
int y3[4]={100,60,45,50};
setcolor(GREEN);
line(100,100,100,40);
fillellipse(105,108,8,8);
fillellipse(111,108,8,8);
fillellipse(115,108,8,8);
//fillellipse(99,105,8,8);
//fillellipse(105,105,8,8);
//fillellipse(113,105,8,8);


bezier(x,y);
bezier(x1,y1);
bezier(x2,y2);
bezier(x3,y3);
}
void drawman()
{
setcolor(WHITE);
circle(110,340,10);
line(110,350,110,380);//body

line(110,360,120,385);//hand
line(110,360,100,385);
line(110,380,120,400);//leg
line(110,380,100,400);
}
void drawman2()
{
setcolor(WHITE);
circle(110,340,10);
line(110,350,110,380);//body

line(110,360,120,355);//hand
line(110,360,100,355);
line(110,380,120,370);//leg
line(110,380,100,370);
}
void climb()
{
drawtree();
drawman();
delay(100);
for(i=0;i<250;i=i+10)
{
cleardevice();
drawtree();


setcolor(WHITE);
circle(110,340-i,10);
line(110,350-i,110,380-i);//body

line(110,360-i,120,385-i);//hand
line(110,360-i,100,385-i);
line(110,380-i,120,400-i);//leg
line(110,380-i,100,400-i);
delay(100);
cleardevice();
drawtree();

setcolor(WHITE);
circle(110,340-i,10);
line(110,350-i,110,380-i);//body

line(110,360-i,120,355-i);//hand
line(110,360-i,100,355-i);
line(110,380-i,120,370-i);//leg
line(110,380-i,100,370-i);
delay(100);


}

}
void drawtree2()
{
setcolor(BROWN);
bar(100,100,120,400);
int x[4]={20,40,80,100};
int y[4]={100,80,80,100};
int x1[4]={100,120,160,180};
int y1[4]={100,80,80,100};
int x2[4]={40,50,80,100};
int y2[4]={50,45,60,100};
int x3[4]={100,120,140,160};
int y3[4]={100,60,45,50};
setcolor(GREEN);
line(100,100,100,40);
//fillellipse(105,108,8,8);
//fillellipse(111,108,8,8);
//fillellipse(115,108,8,8);
//fillellipse(99,105,8,8);
//fillellipse(105,105,8,8);
//fillellipse(113,105,8,8);


bezier(x,y);
bezier(x1,y1);
bezier(x2,y2);
bezier(x3,y3);
}
void drawman3()
{
i=250;
setcolor(WHITE);
circle(110,340-i,10);
line(110,350-i,110,380-i);//body

line(110,360-i,120,355-i);//hand
line(110,360-i,100,355-i);
line(110,380-i,120,370-i);//leg
line(110,380-i,100,370-i);

}
void pluck()
{
setcolor(BLACK);
fillellipse(105,108,8,8);
fillellipse(111,108,8,8);
fillellipse(115,108,8,8);
for(i=0;i<15;i++)
{
cleardevice();
drawtree2();
drawman3();
setcolor(GREEN);
fillellipse(105+i,108+i,8,8);
fillellipse(111+i,108+i,8,8);
fillellipse(115+i,108+i,8,8);
delay(1000);


setcolor(BLACK);
fillellipse(105+i,108+i,8,8);
fillellipse(111+i,108+i,8,8);
fillellipse(115+i,108+i,8,8);
drawtree2();
drawman3();
delay(1000);
}
}

void main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"");
//drawtree();
//drawman2();
climb();
delay(100);
pluck();
delay(8000);
closegraph();

}

