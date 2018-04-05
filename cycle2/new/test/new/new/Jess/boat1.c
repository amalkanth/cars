/********************************
TITLE   : ROWING A BOAT
NAME    : JESS JOSEPH BENNY
ROLL NO : 30
DATE    : 01/03/2018
*********************************/
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int main()
{
   int gd=DETECT,gm;
   initgraph(&gd,&gm,"");
   setcolor(RED);
   int x1=400,x2=600,x3=650,x4=350,xm1=500,xmh1=480,xmh2=520,xum1=535,rx,p,q,m,n,s;
   int y1=400,y2=400,y3=350,y4=350,ym1=350,ym2=325,ymh=335,yum1=290,i,k,j,ry;
   int flag=0;
   
   x1-=300;
   x2-=300;
   x3-=300;
   x4-=300;
   xm1-=300;
   xmh1-=300;
   xmh2-=300;
   xum1-=300;
   
   for(i=0;i<250;i++)
   {
     setcolor(WHITE);
     
     for(j=0;j<500;j++)
     {
       rx=rand()%639;
       ry=rand()%439;
       s=sqrt(pow(rx-xum1,2)+pow(ry-yum1,2));
       if((rx>=xum1-70)&&(rx<=xum1+70)&&(ry>=yum1+70)&&(ry<=y4)||(s<70))    continue;
        line(rx+1,ry-1,rx,ry);
     }
   setcolor(RED);
   line(x1,y1,x2,y2);//boat
   line(x1,y1,x4,y4);
   line(x2,y2,x3,y3);
   line(x3,y3,x4,y4);
   
   setcolor(BLUE);//water
   bar(0,y1+1,800,900);
   
   setcolor(YELLOW);//man
   line(xm1,ym1,xm1,ym2);
   circle(xm1,315,10);
   line(xm1,ymh,xmh2,ymh);
   if(flag==0){
   
   q=ymh+20;
   n=ymh+80;
   p=xm1-20;
   m=xm1+30;
   flag=1;
   }
   
   
   line(xm1,ymh,p,q);
   setcolor(YELLOW);
   line(p,q,m,n);
    circle(m+10,n+10,10);
    
   setcolor(GREEN);//umberlla
   line(xmh2,ymh,xum1,yum1);
   arc(xum1,yum1,180,360,70); 
   line(xum1-70,yum1,xum1+70,yum1);
   x1++;
   x2++;
   x3++;
   x4++;
   xm1++;
   xmh1++;
   xmh2++;
   xum1++;
   if(q>ymh)
   {
    q--;
    n--;
   }
   else
   {
     n+=10;
     q+=10;
   }
   if(p>xm1-20)
   {
    p-=5;
    m-=5;
   }
   else
   {
    p+=50;
    m+=50;
   }
    delay(50);
    setbkcolor(BLACK);
  }
   return(0);
}   
