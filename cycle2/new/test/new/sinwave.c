#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
int main(){
int gd=DETECT,gm;
int angle=0;
double x,y;
initgraph(&gd,&gm,"");
line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
for(x=0;x<getmaxx();x+=3){
y=50*sin(angle*3.141/180);
y=getmaxy()/2-y;
putpixel(x,y,15);
delay(10);
angle+=30;
}
getch();
closegraph();
return 0;
}
