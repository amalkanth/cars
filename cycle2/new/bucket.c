#include<stdio.h>
#include<graphics.h>
#include<math.h>
int bl=200,br=350,bu=200,bb=400;
void bezier(int x[],int y[],int h)
{
double t;
for(t=0.0;t<1.0;t+=0.0005)
{
double xt=pow(1-t,3)*x[0]+3*t*pow(1-t,2)*x[1]+3*pow(t,2)*(1-t)*x[2]+pow(t,3)*x[3];
double yt=pow(1-t,3)*y[0]+3*t*pow(1-t,2)*y[1]+3*pow(t,2)*(1-t)*y[2]+pow(t,3)*y[3];
putpixel(xt,yt,h);
}
}
void drawbucket()
{
line(bl,bu,bl,bb);
line(bl,bb,br,bb);
line(br,bb,br,bu);
setcolor(BLACK);
line(bl,bu+40,bl,bu+44);
}
void drawpipe(){
setcolor(WHITE);
int pu=bu-60,pl=br+60,pr=br+100,pb=bb;
bar(pl,pu,pr,pb);
rectangle((br-bl)/2+bl-10,pu+5,pl,pu+20);
rectangle((br-bl)/2+bl-5,pu+20,(br-bl)/2+bl,pu+40);
bar((br-bl)/2+bl-5,pu-5,(br-bl)/2+bl,pu+3);
setcolor(WHITE);
fillellipse((br-bl)/2+bl-2,pu-6,10,3);
}
void flowin(int i)
{
setcolor(BLUE);
line(bl+1,i,br-1,i);
}
void flowout(int i){
setcolor(BLACK);
line(bl+1,i,br-1,i);
}
void main(){
int gd=DETECT,gm,i,j,k,l=0,m;
int y[4]={bu+40,bu+80,bu+120,bb};
int x[4]={bl,bl-20,bl-25,bl-20};
initgraph(&gd,&gm,"");
drawbucket();
drawpipe();
for(i=bb-2,j=0,k=0,m=0;i>bu+1;i-=2)
{
setcolor(BLUE);
line((br-bl)/2+bl-4,bu-60+40,(br-bl)/2+bl-4,i);
flowin(i);
flowin(i+1);
bezier(x,y,BLACK);
if(i+1<bu+40){
flowout(i);
if(m<120){
y[0]=bu+40;
y[1]=bu+80-k-2;
y[2]=bu+120+k;
y[3]=bb;
x[0]=bl;
x[1]=bl-(20+l);
x[2]=bl-(25+l-4);
x[3]=bl-l-9;
l+=1;
k+=1;
m+=3;
}
bezier(x,y,BLUE);

j=j+2;
i++;
}
delay(60);
}
setcolor(BLACK);
line((br-bl)/2+bl-4,bu-60+40,(br-bl)/2+bl-4,i-1);
k--;
l--;
for(i=bu+1,m=0;i<bu+40;i++){
bezier(x,y,BLACK);
flowout(i);
if(m<150){
y[0]=bu+40;
y[1]=bu+80-k-2;
y[2]=bu+120+k;
y[3]=bb;
x[0]=bl;
x[1]=bl-(20+l);
x[2]=bl-(25+l-4);
x[3]=bl-l-9;
m+=3;
//if(m%2==0)
k-=1;
l-=1;
}
bezier(x,y,BLUE);
delay(60);
}
bezier(x,y,BLACK);

getch();
closegraph();
}
