#include<graphics.h>
#include<bits/stdc++.h>

using namespace std;



void BresenhamLine(int x1,int y1,int x2,int y2,int xm, int ym){
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
          //cout<<"m<1 "<<endl;
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
        //cout<<"m>1 "<<endl;
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


int calculateAND(int a1,int b1,int a2,int b2,int a3,int b3,int a4,int b4){
    int flag=0;
    if((a1&b1)==0 && (a2&b2)==0 && (a3&b3)==0 && (a4&b4)==0)
    {
        cout<<"Candidate"<<endl;
        flag=1;
    }
    else
    {
        cout<<"Not Visible"<<endl;
    }
    return(flag);
}


int RegionCode(int x1, int y1, int x2, int y2, int Xmin, int Ymin, int Xmax, int Ymax){

    int b1,b2,b3,b4,a1,a2,a3,a4,flag;
    int a;
    a=y1-Ymax;
    if(a>0)
        b1=1;
    else
        b1=0;

    a=Ymin-y1;
    if(a>0)
        b2=1;
    else
        b2=0;

    a=x1-Xmax;
    if(a>0)
        b3=1;
    else
        b3=0;

    a=Xmin-x1;
    if(a>0)
        b4=1;
    else
        b4=0;
       //x2 y2

    a=y2-Ymax;
    if(a>0)
        a1=1;
    else
        a1=0;

    a=Ymin-y2;
    if(a>0)
        a2=1;
    else
        a2=0;

    a=x2-Xmax;
    if(a>0)
        a3=1;
    else
        a3=0;

    a=Xmin-x2;
    if(a>0)
        a4=1;
    else
        a4=0;

    //code=b1+b2+b3+b4;
     //cout<<code<<endl;

    //stringstream geek(code);
    //geek>>c; ///TODO:string to boolean
    //cout<<c<<endl;

    if(a1==0 && b1==0 &&a2==0 &&b2==0 &&a3==0 &&b3==0 &&a4==0 &&b4==0 )
        cout<<"Visible"<<endl;
    else
        flag=calculateAND(a1,b1,a2,b2,a3,b3,a4,b4);


}


/*void candidate(int x1,int y1, int x2, int y2, int Xmin, int Ymin, int Xmax, int Ymax){
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

}*/


int main(){
    int xm,ym,xc,yc;
    int gm=DETECT,gd;
    initgraph(&gm,&gd,"");
    xm=getmaxx()/2;
    ym=getmaxy()/2;

    line(0,ym,2*xm,ym);
    line(xm,0,xm,2*ym);

    int Xmax, Xmin, Ymax, Ymin;
    int x1,x2,y1,y2;
    cout<<"Enter Xmin Ymin Xmax Ymax"<<endl;
    cin>>Xmin>>Ymin>>Xmax>>Ymax;

    window(Xmin, Ymin, Xmax, Ymax, xm, ym);

//   c3=c1&c2;
    cout<<"Enter end points of Line please"<<endl<<"x1,y1,x2,y2"<<endl;
   cin>>x1>>y1>>x2>>y2;
    BresenhamLine(x1,y1,x2,y2,xm,ym);
    RegionCode(x1, y1, x2, y2, Xmin, Ymin, Xmax, Ymax);


    getch();
    closegraph();
return 0;
}




