#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
float gl=15;
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


void drawman()
{
setcolor(WHITE);
circle(120,355,7);
line(120,362,120,390);//body
line(120,390,110,390);//legs
line(120,390,110,398);
line(120,375,110,375);//hands
line(120,375,110,368);
line(117,380,123,380);

}
void drawman2()
{
setcolor(WHITE);
circle(120,95,7);
line(120,102,120,130);//body
line(120,130,110,130);//legs
line(120,130,110,138);
line(120,115,110,115);//hands
line(120,115,110,108);
line(110,105,110,111);
mount c /home
}
void drawtree()
{
setcolor(BROWN);

bar(90,100,110,400);
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
fillellipse(105,100,8,8);
fillellipse(111,100,8,8);
//fillellipse(95,100,8,8);
//fillellipse(99,105,8,8);
//fillellipse(105,105,8,8);
fillellipse(113,105,8,8);


bezier(x,y);
bezier(x1,y1);
bezier(x2,y2);
bezier(x3,y3);
}

void drawtree2()
{
setcolor(BROWN);

bar(90,100,110,400);
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

bezier(x,y);
bezier(x1,y1);
bezier(x2,y2);
bezier(x3,y3);
}


void climb()
{
int i;

for(i=0;i<265;i+=5)
{
cleardevice();
drawtree();
setcolor(WHITE);
circle(120,355-i+5,7);
line(120,362-i+5,120,390-i+5);//body
line(120,390-i+5,110,390-i-5);//legs
line(120,390-i+5,110,398-i-5);
line(120,375-i+5,110,375-i-5);//hands
line(120,375-i+5,110,368-i-5);
line(117,380-i+5,123,380-i+5);
delay(100);
cleardevice();
drawtree();
setcolor(WHITE);
circle(120,355-i,7);
line(120,362-i,120,390-i);//body
line(120,390-i,110,390-i);//legs
line(120,390-i,110,398-i);
line(120,375-i,110,375-i);//hands
line(120,375-i,110,368-i);
line(117,380-i,123,380-i);
delay(50);

}
line(120,115,110,108);
delay(200);
line(120,115,117,120);
delay(200);
line(120,115,110,108);
line(110,105,110,111);
}
void drawtop()
{
int j,k;
for(j=0;j<295;j+=5)
{
cleardevice();
drawtree2();
drawman2();
setcolor(GREEN);
fillellipse(100+30,100+j,8,8);
fillellipse(106+30,100+j,8,8);
//fillellipse(90+30,100+j,5,5);
//fillellipse(94+30,105+j,5,5);
//fillellipse(100+30,105+j,5,5);
fillellipse(108+30,105+j,8,8);
delay(50);
}
setcolor(BLACK);
fillellipse(130,390,8,8);
fillellipse(136,390,8,8);
fillellipse(138,395,8,8);
/*
setcolor(GREEN);
delay(500);
fillellipse(150,370,8,8);
fillellipse(116,370,8,8);
fillellipse(138,395,8,8);
setcolor(BLACK);
delay(500);
fillellipse(150,370,8,8);
fillellipse(116,370,8,8);
fillellipse(138,395,8,8);

setcolor(GREEN);
delay(500);
fillellipse(190,390,8,8);
fillellipse(86,390,8,8);
fillellipse(138,395,8,8);

/*for(k=0;k<50;k+=10)
{
cleardevice();
drawtree2();
drawman2();
setcolor(GREEN);
fillellipse(100+k+40,395,5,5);
fillellipse(106+k+20,395,5,5);
fillellipse(90+k,395,5,5);
fillellipse(94+k+10,400,5,5);
fillellipse(100-k-10,400,5,5);
fillellipse(108-k,400,5,5);
delay(400);
}*/
int x7[4]={130,150,170,190};
int y7[4]={390,360,370,390};
bounce(x7,y7);
setcolor(GREEN);
fillellipse(10,390,8,8);
fillellipse(190,390,8,8);
fillellipse(375,400,8,8);

}


int main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"");
drawtree();
drawman();
climb();
drawtop();
getch();

}


