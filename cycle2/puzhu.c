
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>

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
int lx[4]={50,200,260,240};
int ly[4]={320,250,250,230};
bezier(lx,ly);
 setcolor(GREEN);
 fillellipse(250,250,80,30);
 setcolor(RED);
 int flag1=0,j;
 double radius = 4.0;
 int xmax = getmaxx(); 
 for(int i=0;i<xmax;i++)
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
  if(x>leaf1-80&&x<leaf1+80)
  {
    xincrement+=0.0001;
    radius = radius+.009;
    setcolor(BLACK);
    setcolor(RED);
    flag1=1;
  }
  tempx = xcord[0];
  tempy = ycord[0];
  setcolor(BLACK);
  //fillellipse(tempx,tempy,radius+1,radius+1);
  circle(tempx,tempy,radius);

  setcolor(RED);
 // fillellipse(tempx+(radius-.002)*2,tempy,radius-.002,radius-.002);
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
 setcolor(BLACK);
 bar(0,0,700,290); 
 getch();
}
