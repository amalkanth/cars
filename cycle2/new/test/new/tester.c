#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
float gl=15;
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
int gd=DETECT,gm;
initgraph(&gd,&gm,"");
//int x[]={100,140,180,220,260};
//int y[]={100,140,180,140,100};
int x1[]={0,0.5519150244,1,1};
int y1[]={1,1,0.5519150244,0};
int x2[]={1,1,0.5519150244,0};
int y2[]={0,-0.5519150244,-1,-1};
int x3[]={0,-0.5519150244,-1,-1};
int y3[]={-1,-1,-0.5519150244,0};
int x4[]={-1,-1,-0.5519150244,0};
int y4[]={0,0.5519150244,1,1};
bezier(x1,y1);
bezier(x2,y2);
bezier(x3,y3);
bezier(x4,y4);
getch();

}

/*P_0 = (0,1), P_1 = (c,1), P_2 = (1,c), P_3 = (1,0)

P_0 = (1,0), P_1 = (1,-c), P_2 = (c,-1), P_3 = (0,-1)

P_0 = (0,-1), P_1 = (-c,-1), P_3 = (-1,-c), P_4 = (-1,0)

P_0 = (-1,0), P_1 = (-1,c), P_2 = (-c,1), P_3 = (0,1)
c = 
*/
