/*******************************************************
 Title : Sunflower 
 Name  : Dona Mariya Shaju
 Rollno: 20
 Date  : 15/03/2018
*******************************************************/ 
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>
void bezier(int x[4],int y[4])
{
int i;
double t;
for(t=0.0;t<1.0;t+=0.010)
{
double xt=pow(1-t,3)*x[0]+3*t*pow(1-t,2)*x[1]+3*pow(t,2)*(1-t)*x[2]+pow(t,3)*x[3];
double yt=pow(1-t,3)*y[0]+3*t*pow(1-t,2)*y[1]+3*pow(t,2)*(1-t)*y[2]+pow(t,3)*y[3];
putpixel(xt,yt,GREEN);
}
return;
}
void main()
{
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"");
 double FlowerRadius=15,SunRadius,SunAngle,CircleCenterx,CircleCentery;
 int xmax = getmaxx();
 line(0,400,xmax,400);
 setcolor(GREEN);
 double xmid = xmax/2;
 double ymid = 400;
 double SunCenterx=xmax-50-xmid,SunCentery=0,si,co,xcord,ycord;
 line(300,400,300,300);
 int x[4] = {300,300,335,335},y[4] = {300,290,290,300};
 bezier(x,y);
 CircleCenterx = 335;
 CircleCentery = 300;
 setcolor(YELLOW);
 fillellipse(CircleCenterx,CircleCentery,FlowerRadius,FlowerRadius);
 fillellipse(CircleCenterx+FlowerRadius*2*si,CircleCentery,10,4);
 fillellipse(CircleCenterx,CircleCentery+FlowerRadius*2,4,10);
 fillellipse(CircleCenterx,CircleCentery-FlowerRadius*2,4,10);
 fillellipse(CircleCenterx-FlowerRadius*2,CircleCentery,10,4);
 setcolor(RED);
 fillellipse(xmid+SunCenterx,430+SunCentery,30,30);
 setcolor(BLACK);
 fillellipse(xmid+SunCenterx,430+SunCentery,30,30);
 setcolor(RED);
 for(int i=0;i<180;i++)
 {
   cleardevice();
   line(0,400,xmax,400);
   setcolor(GREEN);
   line(300,400,300,300);
   si = sin(i*3.14/180);
   co = cos(i*3.14/180);
   xcord = SunCenterx*co;
   ycord = SunCenterx*si;
   int x[4] = {300,300,CircleCenterx,CircleCenterx},y[4] = {300,CircleCentery-10,CircleCentery-10,300};
   bezier(x,y);
   setcolor(RED);
   fillellipse(xmid+xcord,370-ycord,30,30);
   double xflower = co*35;
   double yflower = si*35;
   CircleCenterx = 300 + xflower; 
   CircleCentery = 300 - yflower;
   FlowerRadius = 15 + 5*si;
   setcolor(YELLOW);
   fillellipse(CircleCenterx-8+FlowerRadius*2*si,CircleCentery,20*si,15*si);
   fillellipse(CircleCenterx,CircleCentery-8+FlowerRadius*2*si,15*si,20*si);
   fillellipse(CircleCenterx,CircleCentery+8-FlowerRadius*2*si,15*si,20*si);
   fillellipse(CircleCenterx+8-FlowerRadius*2*si,CircleCentery,20*si,15*si);
   fillellipse(CircleCenterx,CircleCentery,FlowerRadius,FlowerRadius);
   setcolor(RED);
   fillellipse(CircleCenterx,CircleCentery,13,13);
   setcolor(WHITE);
   outtextxy(400,50, "SUNFLOWER");
   //moveto(400+xflower,200);
   delay(100);
 }  
 getch();
}
