#include<graphics.h>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int gm=DETECT,gd;
    initgraph(&gm,&gd,"");

    int xm,ym;
    xm=getmaxx()/2;
    ym=getmaxy()/2;

    line(0,ym,2*xm,ym);///x axis
    line(xm,0,xm,2*ym);///y axis

    int x1=-50,y1=-100,y2=80;
    int x=x1, y=y1;

    do{
        putpixel(xm+x,ym-y,YELLOW);
        y=y+1;
    }while(y<=y2);



    getch();
    closegraph();
return 0;
}
