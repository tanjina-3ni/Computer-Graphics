#include<graphics.h>
#include<bits/stdc++.h>

using namespace std;




void BresenhamLine(int x1,int y1,int x2,int y2,int xm, int ym){
int x,y,dx,dy,w,z,p;

    dx = x2-x1;
    dy = y2-y1;

            w=2*dx;
            z=2*dy;
            p=z-dx;
            x=x1;
            y=y1;
    if(dx>dy){
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
    }
    else{
            do{
                putpixel(xm+x,ym-y,YELLOW);
                if(p>0){
                    p=p+z;
                    y=y+1;///changed here
                }
                else{
                    p=p+z-w;
                    x=x+1;
                    y=y+1;
                }
            }while(y<=y2);///changed here
        }

}


void window(int Xmin, int Ymin, int Xmax, int Ymax, int xm, int ym){

    BresenhamLine(Xmin,Ymin,Xmax,Ymin,xm,ym);

    BresenhamLine(Xmin,Ymin,Xmin,Ymax,xm,ym);

    BresenhamLine(Xmax,Ymin,Xmax,Ymax,xm,ym);

    BresenhamLine(Xmin,Ymax,Xmax,Ymax,xm,ym);
    /*line(Xmin,Ymin,Xmax,Ymin);
    line(Xmin,Ymin,Xmin,Ymax);
    line(Xmax,Ymin,Xmax,Ymax);
    line(Xmin,Ymax,Xmax,Ymax);*/
}



void RegionCode(int X, int Y, int Xmin, int Ymin, int Xmax, int Ymax){

    string b1,b2,b3,b4,code;
    bool c;
    int a;
    a=Y-Ymax;
    if(a>0)
        b1='1';
    else
        b1='0';

    a=Ymin-Y;
    if(a>0)
        b2='1';
    else
        b2='0';

    a=X-Xmax;
    if(a>0)
        b3='1';
    else
        b3='0';

    a=Xmin-X;
    if(a>0)
        b4='1';
    else
        b4='0';

    code=b1+b2+b3+b4;
    istringstream("code") >> c; ///TODO:string to boolean
    cout<<c<<endl;

    return c;

}


void candidate(int x1,int y1, int x2, int y2, int Xmin, int Ymin, int Xmax, int Ymax){
    bool a,b;
    a = RegionCode( x1, y1,Xmin, Ymin, Xmax, Ymax);
    b = RegionCode( x2, y2,Xmin, Ymin, Xmax, Ymax);

    if(a==0&&b==0){
        cout<"Visible"<<endl;
    }
    else
    {
        if(a and b==0)
        {
                   cout<"Candidate"<<endl;
                   ///TODO: clip. then line draw

        }
        else
        {
                    cout<" NOT Visible"<<endl;
        }
    }

}


int main(){
    int xm,ym,xc,yc;
    int gm=DETECT,gd;
    initgraph(&gm,&gd,"");
    xm=getmaxx()/2;
    ym=getmaxy()/2;

    line(0,ym,2*xm,ym);
    line(xm,0,xm,2*ym);

    int Xmax, Xmin, Ymax, Ymin;
    cout<<"Enter Xmin Ymin Xmax Ymax"<<endl;
    cin>>Xmin>>Ymin>>Xmax>>Ymax;

    window(Xmin, Ymin, Xmax, Ymax, xm, ym);
    int X=-50,Y=-50;
    RegionCode( X, Y,Xmin, Ymin, Xmax, Ymax);


    getch();
    closegraph();
return 0;
}




