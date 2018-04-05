#include<stdio.h>
#include<graphics.h>
#include<math.h>
int r=10;
void movered(int x,int y,int a){
int xd,yd;
setcolor(RED);
xd=cos(a)*r;
yd=cos(90-a)*r;
circle(x,y+r+2+r,r);
line(x-xd,y+r+r+2+yd,x+xd,y+r+2+r-yd);

}
void moveyellow(int x,int y,int a){
int xd,yd;
setcolor(YELLOW);
xd=cos(a)*r;
yd=cos(90-a)*r;
circle(x,y,r);
line(x-xd,y+yd,x+xd,y-yd);
}
void drawskel()
{
setcolor(YELLOW);
line(50,100+r+1,400,100+r+1);
arc(225,100+r+1,0,180,175);
}
void movehoriz(int i,int p){
int j,k,m;
for(j=0;p<400-r-2;i=i-5,p+=5,j+=10){
cleardevice();
drawskel();
moveyellow(i,100,j);
movered(p,100,j);
delay(100);
}
m=j;
for(k=0;k<4;i-=5,j+=10,k++)
{
cleardevice();
drawskel();
moveyellow(i,100,j);
movered(p,100,m);
delay(100);
}
cleardevice();
drawskel();
moveyellow(i,100,j);
movered(p,100,m);
delay(100);
}
void rotate(){
int i,j,k,xd,xd1,yd,yd1;
for(i=3,j=0,k=182;k>0;i++,j+=10,k--)
{
xd=cos(i*3.142857143/180.0)*(175-r-1)+225;
yd=sin(i*3.142857143/180.0)*(175-r-1)+100-r;
movered(xd,yd,j);
xd=cos(k*3.142857143/180.0)*(175+r+1)+225;
yd=sin(k*3.142857143/180.0)*(175+r+1)+100+r+1;
moveyellow(xd,yd,j);
delay(100);
cleardevice();
drawskel();
}
}
void move(){
int i,j1=0,k,m,l,n,f1=0,f2=0,p;
int xd,yd,j2=0,ri=3,rk=182;
i=50;
p=400;
while(1){
drawskel();
if(i<400-r)
f1=0;
else
f1=1;
if(p>50+r&&p<400-r)
f2=0;
else
f2=1;
if(f1==0){
movered(i,100,j1);
i+=5;
j1+=10;
}
else{
if(ri<182){
xd=cos(ri*3.142857143/180.0)*(175+r+1)+225;
yd=sin(ri*3.142857143/180.0)*(175+r+1)+100+r;
movered(xd,yd,j1);
ri++;
j1+=10;
}else{
i=51;
ri=3;
f1=0;
}
}
/*if(f2=0)
{
movered(p,100,j2);
j2+=10;
p+=5;
}
else{
if(rk>-2){
xd=cos(ri*3.142857143/180.0)*(175-r-1)+225;
yd=sin(ri*3.142857143/180.0)*(175-r-1)+100-r;
movered(xd,yd,j2);
ri--;
j2+=10;
}else{
p=400;
rk=182;
f2=0;
}
}*/
delay(100);
cleardevice();
}
}

void main()
{
int gd=DETECT,gm,i,j,k,l=0,m,p;
double t;
int xd,yd,xd1,yd1;
initgraph(&gd,&gm,"");
int x=100,y=400;
/*movehoriz(400,50);
drawskel();
rotate();
*/
move();
getch();
}
