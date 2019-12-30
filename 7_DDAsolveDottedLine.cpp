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

    int x1=-50,y1=-100,x2=80,y2=150;
    int x=x1, y=y1;
    float m,b;

    m=1.0*(y2-y1)/(x2-x1);
    b=y1-m*x1;

    if(m<=1){
            do{
               putpixel(xm+x,ym-y,YELLOW);
               x=x+1;
               y=int(m*x+b);
               }while(x<=x2);
    }
    else{
        do{
               putpixel(xm+x,ym-y,YELLOW);
               y=y+1;
               x=int((y-b)/m);
               }while(y<=y2);
    }

    getch();
    closegraph();
return 0;
}





