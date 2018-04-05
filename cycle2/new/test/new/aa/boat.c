#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>
int i;
void drawboat(int i)
{
line(0+i,350,100+i,350);
line(0+i,350,30+i,400);
line(30+i,400,70+i,400);
line(70+i,400,100+i,350);
circle(50+i,300,5);
line(50+i,305,50+i,350);
line(50+i,327,65+i,310);
line(65+i,340,65+i,275);
setcolor(YELLOW);
pieslice(65+i,275,180,360,30);
setcolor(WHITE);
}
void rain()
{
int m,j,n,a,b,maxx,maxy,x,y;
maxx=getmaxx();
maxy=getmaxy();
setlinestyle(DASHED_LINE,0,1);
for(j=10,n=10,a=0,b=0;j<maxx&&n<maxy;j+=10,n+=10){
if((65+i-j)*n==(275*-j))
line(j,0,0,276);
else
line(j,0,0,n);
}/*
if(n>maxy)
while(a<maxx){
a+=10;
line(j,0,a,n);
j+=10;
}*/
//setlinestyle(SOLID_LINE,0,1);
}
void move()
{int y=1;
while(y)
{
for(i=0;i<550;i+=5)
{delay(20);
cleardevice();


setcolor(WHITE);
drawboat(i);
if((i%2)==0)
{
line(50+i,327,65+i,340);
line(65+i,340,50+i,395);
}
else
{
line(50+i,327,65+i,327);
line(65+i,327,70+i,395);
}

rain();
setcolor(CYAN);
bar(0,380,700,700);
}}
}
int main()
{

int gd=DETECT,gm,i=0,z=0;
initgraph(&gd,&gm,"");
setcolor(CYAN);
bar(0,370,700,700);
setcolor(WHITE);
drawboat(0);
rain();
move();
getch();
closegraph();
return 0;
}

