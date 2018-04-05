#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
int main()
{

int gd=DETECT,gm,i,z=0;
initgraph(&gd,&gm,"");
setcolor(BLUE);
pieslice(100,100,30,180,30);
setcolor(YELLOW);
pieslice(65,275,180,360,30);
getch();
return 0;
}
