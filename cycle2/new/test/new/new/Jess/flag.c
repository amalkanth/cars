#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
void dda(float x0,float y0, float x1, float y1)
{
 float dx=x1-x0;
 float dy=y1-y0;
 float steps;
 int k;
 float xi,yi,x=x0,y=y0;
 if(x1==x0 && y1==y0)
 {
  putpixel(x,y,RED);
  return;
 }
 if(abs(dx)>abs(dy))
  steps=abs(dx);
 else
  steps=abs(dy);
 xi=dx/steps;
 yi=dy/steps;
 putpixel(x,y,RED);
 for(k=0;k<steps;k++)
 {
  x+=xi;
  y+=yi;
  putpixel(x,y,RED);
 }
}

void bezier(int x[4],int y[4])
{
int i;
double t;
for(t=0.0;t<1.0;t+=0.0005)
{
double xt=pow(1-t,3)*x[0]+3*t*pow(1-t,2)*x[1]+3*pow(t,2)*(1-t)*x[2]+pow(t,3)*x[3];
double yt=pow(1-t,3)*y[0]+3*t*pow(1-t,2)*y[1]+3*pow(t,2)*(1-t)*y[2]+pow(t,3)*y[3];
putpixel(xt,yt,GREEN);
}
return;
}

void dda1(float x0,float y0, float x1, float y1)
{
 float dx=x1-x0;
 float dy=y1-y0;
 float steps;
 int k;
 float xi,yi,x=x0,y=y0;
 if(x1==x0 && y1==y0)
 {
  putpixel(x,y,BLACK);
  return;
 }
 if(abs(dx)>abs(dy))
  steps=abs(dx);
 else
  steps=abs(dy);
 xi=dx/steps;
 yi=dy/steps;
 putpixel(x,y,BLACK);
 for(k=0;k<steps;k++)
 {
  x+=xi;
  y+=yi;
  putpixel(x,y,BLACK);
 }
}

void dda2(float x0,float y0, float x1, float y1)
{
 float dx=x1-x0;
 float dy=y1-y0;
 float steps;
 int k;
 float xi,yi,x=x0,y=y0;
 if(x1==x0 && y1==y0)
 {
  putpixel(x,y,BLACK);
  return;
 }
 if(abs(dx)>abs(dy))
  steps=abs(dx);
 else
  steps=abs(dy);
 xi=dx/steps;
 yi=dy/steps;
 putpixel(x,y,BLACK);
 for(k=0;k<steps;k++)
 {
  x+=xi;
  y+=yi;
  putpixel(x,y,BLACK);
 }
}

void plot(int xc,int yc,int x,int y)
{
 putpixel(xc+x,yc+y,BLACK);
 putpixel(xc+x,yc-y,BLACK);
 putpixel(xc-x,yc-y,BLACK);
 putpixel(xc-x,yc+y,BLACK);
 putpixel(xc+y,yc+x,BLACK);
 putpixel(xc+y,yc-x,BLACK);
 putpixel(xc-y,yc-x,BLACK);
 putpixel(xc-y,yc+x,BLACK);
}

void cdda(int xc,int yc,int r)
{
 int x=0,y=r,p=1-r;
 plot(xc,yc,x,y);
 while(x<y)
 {
  x++;
  if(p<0)
   p+=2*x+1;
  else
  {
   y--;
   p+=2*(x-y)+1;
  }
  plot(xc,yc,x,y);
 }
}

void main()
{
 int gdriver,gmode,ch;
 detectgraph(&gdriver,&gmode);
 initgraph(&gdriver, &gmode, "" );
 setbkcolor(WHITE);
 int i;
 cleardevice();
 for(i=250;i>50;i--)
 {
  cleardevice();
  cdda(60,250,7);
  dda1(60,257,60,280);
  dda1(60,280,45,300);
  dda1(60,280,75,300);
  if(i%2==0)
  {
   dda1(60,265,41,265);
   dda1(60,265,41,270);
  }
  else
  {
   dda1(60,265,41,265);
   dda1(60,265,41,260);
  }
  cdda(35,52,2);
  dda1(34,52,45,265);
  dda1(20,40,30,40);
  dda1(30,40,30,300);
  dda1(20,300,20,40);
  dda(31,i,38,i);
  dda(31,i+1,38,i+1);
  dda(31,i+2,38,i+2);
  dda(31,i+3,38,i+3);
  dda(31,i+4,38,i+4);
  dda(31,i+5,38,i+5);
  dda(38,i,38,i+5);
  delay(100);
  dda2(31,i,38,i);
  dda2(31,i+5,38,i+5);
  dda2(38,i,38,i+5);
 }
 float x,y,angle,x1,y1,m,n;
 int k,flag=0;
 int abc,xyz=0;
 dda2(60,265,45,270);
 dda2(60,265,45,265);
 dda2(60,265,45,260);
 dda2(60,265,50,280);
 dda2(60,265,70,280);
 for(abc=30;abc<150;abc=abc+10)
 {
  for(m=50;m<=65;m++)
  {
   for(x=30;x<abc;x++)
   {
     y = 5*sin(angle*3.14/60);
     y = m -y;
     putpixel(x,y,GREEN);
     angle+=1;  
   }
  }
  if(xyz<14)
   dda2(34,52,45-xyz,265+xyz);
  delay(40);
 }
 for(k=0;k<300;k++)
 {
  cleardevice();
  cdda(32,52,2);
  dda1(34,95,34,280);
  dda1(20,40,30,40);
  dda1(30,40,30,300);
  dda1(30,300,20,300);
  dda1(20,300,20,40);
  cdda(60,250,7);
  dda1(60,257,60,280);
  dda1(60,280,45,300);
  dda1(60,280,75,300);
  dda1(60,265,50,280);
  dda1(60,265,70,280);
  if(flag%2==0)
  {
   for(m=50;m<=65;m++)
   {
   for(x=30;x<150;x++)
   {
     y = 5*sin(angle*3.14/60);
     y = m -y;
     putpixel(x,y,RED);
     angle+=1;  
   }
  }
  x1=x;
  y1=y;
  for(m=85;m<=100;m++)
  {
   for(x=30;x<150;x++)
   {
     y = 5*sin(angle*3.14/60);
     y = m -y;
     putpixel(x,y,GREEN);
     angle+=1;  
   }
  }
 }
 if(flag%2==1)
 {
  for(m=50;m<=65;m++)
  {
   for(x=30;x<150;x++)
   {
     y = 5*cos(angle*3.14/60);
     y = m -y;
     putpixel(x,y,RED);
     angle+=1;  
   }
  }
  x1=x;
  y1=y;
  for(m=85;m<=100;m++)
   for(x=30;x<150;x++)
   {
     y = 5*cos(angle*3.14/60);
     y = m -y;
     putpixel(x,y,GREEN);
     angle+=1;  
   }
 }
  flag++;
  delay(200);
 }
 getch();
}
  





