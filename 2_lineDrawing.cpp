#include<graphics.h>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int gm=DETECT,gd;
    initgraph(&gm,&gd,"");
    line(10,20,100,150);
    getch();
    closegraph();
return 0;
}
