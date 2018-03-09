#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
int i;
void drawboat()
{
line(0,350,100,350);
line(0,350,30,400);
line(30,400,70,400);
line(70,400,100,350);
circle(50,300,5);
line(50,305,50,350);
line(50,327,65,310);
line(50,327,65,340);
line(65,340,65,275);
arc(65,275,180,0,30);
line(35,275,95,275);
}
void rain()
{
int m,n,a,b;
for(m=0;m<700;m+=10)
for(n=0;n<700;n+=10)
{
//putpixel(0+m,0+n,WHITE);
a=random()%700;
b=random()%700;
if((a<35+i||a>95+i))
putpixel(a,b,WHITE);
if(b<275)
putpixel(a,b,WHITE);

}

}
void move()
{int y=1;
while(y)
{
for(i=0;i<550;i+=5)
{delay(200);
cleardevice();


setcolor(WHITE);
line(0+i,350,100+i,350);
line(0+i,350,30+i,400);
line(30+i,400,70+i,400);
line(70+i,400,100+i,350);
circle(50+i,300,5);
line(50+i,305,50+i,350);
line(50+i,327,65+i,310);
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
line(65+i,340,65+i,275);
arc(65+i,275,180,0,30);
line(35+i,275,95+i,275);
rain();
setcolor(BLUE);
bar(0,380,700,700);
}}
}

int main()
{

int gd=DETECT,gm,i,z=0;
initgraph(&gd,&gm,"");
setcolor(BLUE);
bar(0,380,700,700);
setcolor(WHITE);
drawboat();
rain();
move();
getch();
}

