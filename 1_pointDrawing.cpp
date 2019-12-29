#include<graphics.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
 int gm=DETECT,gd;
 initgraph(&gm,&gd," ");
 putpixel(50,100,YELLOW);
 getch();
 closegraph();
return 0;
}
