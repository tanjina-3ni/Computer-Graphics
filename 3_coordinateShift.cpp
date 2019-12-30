#include<graphics.h>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int gm=DETECT,gd;
    initgraph(&gm,&gd,"");

    int xm,ym;
    xm=getmaxx()/2;
    ym=getmaxy()/2;
    cout<<"xm "<<2*xm<<"\nym "<<2*ym<<endl;

    line(0,ym,2*xm,ym);///x axis
    line(xm,0,xm,2*ym);///y axis

    ///center (xm,ym)

    putpixel(xm+50,ym-50,YELLOW);///(50,50)

    getch();
    closegraph();

return 0;
}
