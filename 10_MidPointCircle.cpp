#include<graphics.h>
#include<bits/stdc++.h>

using namespace std;

void pixel(int xm,int ym,int x,int y)
{
	putpixel(xm+x,ym+y,YELLOW);
	putpixel(xm+x,ym-y,YELLOW);
	putpixel(xm-x,ym+y,YELLOW);
	putpixel(xm-x,ym-y,YELLOW);
	putpixel(xm+y,ym+x,YELLOW);
	putpixel(xm+y,ym-x,YELLOW);
	putpixel(xm-y,ym+x,YELLOW);
	putpixel(xm-y,ym-x,YELLOW);
}

int main(){

    int gm=DETECT,gd,xm,ym;
    initgraph(&gm,&gd,"");
    xm=getmaxx()/2;
    ym=getmaxy()/2;

    line(0,ym,2*xm,ym);
    line(xm,0,xm,2*ym);

    int r, x=0,y,p;
    cout<<"Enter radius of the circle"<<endl;
    cin>>r;
    y=r,p=1-r;
    while(x<=y){
        pixel(xm,ym,x,y);
        if(p<0){
            p=p+2*x+3;
        }
        else{
            p=p+2*(x-y)+5;
            y--;
        }
        x++;
    }


    getch();

closegraph();

return 0;
}
