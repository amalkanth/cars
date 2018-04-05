/************************************************
TITLE : WORM EATING LEAF
NAME  : JESS JOSEPH BENNY
ROLLNO: 30
DATE : 1/02/2018
************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>
void main()
{
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"");
 double s;
 double x=10;
 double y=250,angle;
 double yfactor =10;
 double xincrement = 0.1;
 double leaf1 = 250.0;
 double ycord[720],xcord[720];
 setcolor(GREEN);
 fillellipse(250,250,40,15);
 setcolor(RED);
 int flag1=0,j;
 double radius = 4.0;
 int xmax = getmaxx(); 
 for(int i=0;i<720;i++)
 {
   angle = i%180;
   s = sin(angle*3.14/180);
   //printf("Sin %i is %f\n",i,y);
   xcord[i] = x;
   ycord[i] = y+s*yfactor;
   circle(x,y+s*yfactor,radius);
   x=x+xincrement; 
 }
 for(int i=0;i<5000;i++)
 {
  double tempx,tempy;
  x = x+xincrement;
  if(x>=xmax-6)
    break;
  if(x>leaf1-40&&x<leaf1+40)
  {
    xincrement+=0.0001;
    radius = radius+.01;
    setcolor(BLACK);
    setcolor(RED);
    flag1=1;
  }
  tempx = xcord[0];
  tempy = ycord[0];
  setcolor(BLACK);
  fillellipse(tempx,tempy,radius+1,radius+1);
  setcolor(RED);
  //fillellipse(tempx+radius,tempy,radius+1,radius+1);
  for(int k=0;k<719;k++)
   {
     xcord[k] = xcord[k+1];
     ycord[k] = ycord[k+1];
   }
  angle = i%180;
  xcord[719] = x;
  s = sin(angle*3.14/180);
  ycord[719] = y+s*yfactor;
  circle(xcord[719],ycord[719],radius);
  delay(5);
 }  
 getch();
}
