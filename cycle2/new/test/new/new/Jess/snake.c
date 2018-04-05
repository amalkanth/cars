#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>
void main()
{
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"");
 double xincrement = 0.1;
 double x=10;
 double y=250,angle;
 double yfactor =10,s;
 double radius = 4.0;
 int xmax = getmaxx();
 double ycord[720],xcord[720];
 char key;
 for(int i=0;i<720;i++)
 {
   angle = i%180;
   s = sin(angle*3.14/180);
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
  tempx = xcord[0];
  tempy = ycord[0];
  setcolor(BLACK);
  fillellipse(tempx,tempy,radius+1,radius+1);
  setcolor(RED);
  for(int k=0;k<719;k++)
   {
     xcord[k] = xcord[k+1];
     ycord[k] = ycord[k+1];
   }
  scanf("%c",&key);
  if(key == 'e')
  {
   angle = i%180;
   xcord[719] = x;
   s = sin(angle*3.14/180);
   ycord[719] = y+s*yfactor;
   circle(xcord[719],ycord[719],radius);
  }
 }  
}
