#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
void draw();
void drawflag();
void drawf();
void main(){
int gd=DETECT,gm,i,j,k;
initgraph(&gd,&gm,"");
setcolor(RED);
fillellipse(110,350,10,40);
for(i=0,j=350;i<50;i=i+5){
cleardevice();
j=j-i;
draw();
setcolor(RED);
fillellipse(110,j,10,40);
delay(500);
}
cleardevice();
draw();
drawflag();
for(i=0;i<10;i++){
cleardevice();
draw();
if(i%2==0)
drawflag();
else
drawf();
delay(1000);
}
getch();
closegraph();
}
void draw()
{
setcolor(WHITE);
bar(100,100,102,400);
fillellipse(102,400,50,2);
}
void drawf(){
int i=0;
for(i=0;i<10;i=i+2){
delay(1000);
cleardevice();
draw();
setcolor(RED);
bar(102,100,140,120);
setcolor(WHITE);
bar(102,120,140,140);
setcolor(GREEN);
bar(102,140,140,160);
setcolor(BLUE);
setcolor(RED);
bar(140,100-i,200-i-5,120);
setcolor(WHITE);
bar(140,120-i,200-i-5,140);
setcolor(GREEN);
bar(140,140-i,200-i-5,150-i);

}
for(i=0;i<10;i=i+2){
delay(1000);
cleardevice();
draw();
setcolor(RED);
bar(102,100,140,120);
setcolor(WHITE);
bar(102,120,140,140);
setcolor(GREEN);
bar(102,140,140,160);
setcolor(RED);
bar(140,90+i,190+i+5,120);
setcolor(WHITE);
bar(140,110+i,19+i+5,140);
setcolor(GREEN);
bar(140,130+i,190+i+5,150+i);

}
setcolor(BLUE);
//circle(150,130,5);
}

void drawflag()
{
setcolor(RED);
bar(102,100,200,120);
setcolor(WHITE);
bar(102,120,200,140);
setcolor(GREEN);
bar(102,140,200,160);
setcolor(BLUE);
circle(150,130,5);
}
