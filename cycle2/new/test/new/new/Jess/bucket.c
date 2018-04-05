/**************************************************
Title : Water from Tap
Name  : Jess Joseph Benny
Rollno: 30
Date  : 09-03-2018
**************************************************/
#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
void bezier(int x[4],int y[4])
{
int i;
double t;
for(t=0.0;t<1.0;t+=0.0005)
{
double xt=pow(1-t,3)*x[0]+3*t*pow(1-t,2)*x[1]+3*pow(t,2)*(1-t)*x[2]+pow(t,3)*x[3];
double yt=pow(1-t,3)*y[0]+3*t*pow(1-t,2)*y[1]+3*pow(t,2)*(1-t)*y[2]+pow(t,3)*y[3];
putpixel(xt,yt,BLUE);
}
return;
}

void bezier1(int x[4],int y[4])
{
int i;
double t;
for(t=0.0;t<1.0;t+=0.0005)
{
double xt=pow(1-t,3)*x[0]+3*t*pow(1-t,2)*x[1]+3*pow(t,2)*(1-t)*x[2]+pow(t,3)*x[3];
double yt=pow(1-t,3)*y[0]+3*t*pow(1-t,2)*y[1]+3*pow(t,2)*(1-t)*y[2]+pow(t,3)*y[3];
putpixel(xt,yt,BLACK);
}
return;
}

void dda(float x0,float y0, float x1, float y1)
{
 float dx=x1-x0;
 float dy=y1-y0;
 float steps;
 int k;
 float xi,yi,x=x0,y=y0;
 if(x1==x0 && y1==y0)
 {
  putpixel(x,y,15);
  return;
 }
 if(abs(dx)>abs(dy))
  steps=abs(dx);
 else
  steps=abs(dy);
 xi=dx/steps;
 yi=dy/steps;
 putpixel(x,y,15);
 for(k=0;k<steps;k++)
 {
  x+=xi;
  y+=yi;
  putpixel(x,y,15);
 }
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
  putpixel(x,y,15);
  return;
 }
 if(abs(dx)>abs(dy))
  steps=abs(dx);
 else
  steps=abs(dy);
 xi=dx/steps;
 yi=dy/steps;
 putpixel(x,y,BLUE);
 for(k=0;k<steps;k++)
 {
  x+=xi;
  y+=yi;
  putpixel(x,y,BLUE);
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
  putpixel(x,y,15);
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

int main()
{
 int gdriver,gmode,ch;
 detectgraph(&gdriver,&gmode);
 initgraph(&gdriver, &gmode, "" );
 int f =0;
 int x1[4]={100,90,80,80},y;
 int y1[4]={150,140,200,300};
 dda(100,100,100,300);
 dda(100,300,250,300);
 dda(250,300,250,100);
 dda(300,300,400,300);
 dda(400,300,400,10);
 dda(400,10,300,10);
 dda(300,10,300,300);
 dda(300,30,200,30);
 dda(200,30,200,70);
 dda(200,70,210,70);
 dda(210,70,210,70);
 dda(210,50,300,50);
 putpixel(100,150,BLACK);
 putpixel(100,149,BLACK);
 for(y=71;y<=299;y++)
 {
  dda1(203,y,207,y);
  delay(10);
 }
 int i =299;
 while(i>150)
 {
   dda1(101,i,249,i);
   i--;
   delay(100);
 }
 while(i>100)
 {
  x1[3]=(i-70);
  x1[2]=(i-70);
  x1[1]=(i-60);
  if(x1[3]>0)
  {
   bezier(x1,y1);
  }
  dda1(101,i,249,i);
  i--;
  delay(200);
  if(x1[3]>0)
   bezier1(x1,y1);
 }
 for(y=71;y<=100;y++)
  dda2(203,y,207,y);
 while(i<=150)
 {
  x1[3]=(i-70);
  x1[2]=(i-70);
  x1[1]=(i-60);
  if(x1[3]<80)
   bezier(x1,y1);
  if(x1[3]>80)
   f++;
  dda2(101,i,249,i);
  i++;
  delay(200);
  if(x1[3]<80)
   bezier1(x1,y1);
  if(f==1)
  {
   bezier(x1,y1);
   f++;
  }
 }
 getch();
}
  
   
