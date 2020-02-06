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

    int x1=-15,y1=-15,x2=15,y2=150;
    int x,y,dx,dy,w,z,p;

    dx = x2-x1;
    dy = y2-y1;

            w=2*dx;
            z=2*dy;

            x=x1;
            y=y1;
    if(dx>dy){
            p=z-dx;
            do{
                putpixel(xm+x,ym-y,YELLOW);
                if(p<0){
                    p=p+z;
                    x=x+1;
                }
                else{
                    p=p+z-w;
                    x=x+1;
                    y=y+1;
                }
            }while(x<=x2);
          cout<<"m<1 "<<endl;
    }
    else{
            p=w-dy;
            do{
                putpixel(xm+x,ym-y,YELLOW);
                if(p<0){///changed here
                    p=p+w;
                    y=y+1;///changed here
                }
                else{
                    p=p+w-z;
                    x=x+1;
                    y=y+1;
                }
            }while(y<=y2);///changed here
        cout<<"m>1 "<<endl;
    }


    getch();
    closegraph();
return 0;
}

///no multiplication, no round off.


