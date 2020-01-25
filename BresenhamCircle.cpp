#include<graphics.h>
#include<bits/stdc++.h>

using namespace std;

void pixel(int xc,int yc,int x,int y)
{
	putpixel(xc+x,yc+y,YELLOW);
	putpixel(xc+x,yc-y,YELLOW);
	putpixel(xc-x,yc+y,YELLOW);
	putpixel(xc-x,yc-y,YELLOW);
	putpixel(xc+y,yc+x,YELLOW);
	putpixel(xc+y,yc-x,YELLOW);
	putpixel(xc-y,yc+x,YELLOW);
	putpixel(xc-y,yc-x,YELLOW);
}

int main(){
    int gm,gd,xm,ym,xc,yc;
    initgraph(&gm,&gd,"");

    xm=getmaxx()/2;
    ym=getmaxy()/2;

    line(0,ym,2*xm,ym);
    line(xm,0,xm,2*ym);

    xc=xm;
    yc=ym;



    int x=0, r=80, y,t, d;
    y=r;
    d= 3-(2*r);
    //printf("%d",d);


        while(x<=y){
                pixel(xc,yc,x,y);
        printf("(%d,%d)\n",x,y);
        printf("%d\n",d);
        if(d<0){
            d=d+(4*x)+6;
        }
        else
        {
            d=d+4*(x-y)+10;
            y--;
        }
        x++;
      }
getch();
closegraph();

return 0;
}
