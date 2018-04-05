
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
int xc,yc,m,n,k;
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

int main()
{
int gd=DETECT,gm,i;
initgraph(&gd,&gm,"");
int j,K,p,d;
int x[4]={300,280,260,240};
int y[4]={320,300,250,230};
int x1[4]={260,300,420,440};
int y1[4]={250,200,330,300};
int x2[4]={260,300,420,440};
int y2[4]={250,220,390,300};
int x3[4]={260,300,420,440};
int y3[4]={250,200,280,300};

bezier(x,y);
bezier(x1,y1);
bezier(x2,y2);
bezier(x3,y3);

j=1;
k=1;
for(i=0;i<15;i+=2)
{
setcolor(WHITE);
ellipse(430-k,300-j,0,360,10+i,3+j);
fillellipse(430-k,300-j,10+i,3+j);
setcolor(BLACK);
circle(430-k,300-j,3);
fillellipse(430-k,300-j,3,3);
line(430-k-i,305-j,420-k-i,310-j);
line(430-k-i,295-k-i,290-j,290-j);
delay(1000);
for(p=390-k;p<=460;p++)
for(d=303;d<=330;d++)
 putpixel(p,d,BLACK);
setcolor(BLACK);
ellipse(430-k,300-j,0,360,10+i,3+j);
fillellipse(430-k,300-j,10+i,3+j);
circle(430-k,300-j,3);
fillellipse(430-k,300-j,3,3);
line(430-k-i,305-j,420-k-i,310-j);
line(430-k-i,290-j,420-k-i,285-j);
k=k+4;
j++;
}
}
