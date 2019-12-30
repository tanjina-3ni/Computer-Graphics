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

    int x1=-150,y1=-100,x2=180,y2=150;
    int x=x1;
    float m,y;
    y=y1;

    m=1.0*(y2-y1)/(x2-x1);

    do{
        putpixel(xm+x,ym-y,YELLOW);
        x=x+1;
        y=y+m;
    }while(x<=x2);



    getch();
    closegraph();
return 0;
}

///line is not that good. we get dotted line when it is close to vertical
///faster than Direct Line Drawing Algorithm


