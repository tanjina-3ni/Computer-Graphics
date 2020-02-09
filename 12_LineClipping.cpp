#include<graphics.h>
#include<bits/stdc++.h>

using namespace std;



void BresenhamLine(int x1,int y1,int x2,int y2){
    int xm,ym;
    xm=getmaxx()/2;
    ym=getmaxy()/2;
int x,y,dx,dy,dx1,dy1,px,py,xe,ye,i,c=1;
 dx=x2-x1;
 dy=y2-y1;
 dx1=fabs(dx);
 dy1=fabs(dy);
 px=2*dy1-dx1;
 py=2*dx1-dy1;
 if(dy1<=dx1)
 {
  if(dx>=0)
  {
   x=x1;
   y=y1;
   xe=x2;
  }
  else
  {
   x=x2;
   y=y2;
   xe=x1;
  }
  putpixel(x+xm,ym-y,YELLOW);
  for(i=0;x<xe;i++)
  {
   x=x+1;
   if(px<0)
   {
    px=px+2*dy1;
   }
   else
   {
    if((dx<0 && dy<0) || (dx>0 && dy>0))
        {
     y=y+1;
    }
    else
    {
     y=y-1;
    }
    px=px+2*(dy1-dx1);
   }
   delay(0);
   putpixel(x+xm,ym-y,YELLOW);
  }
 }
 else
 {
  if(dy>=0)
  {
   x=x1;
   y=y1;
   ye=y2;
  }
  else
  {
   x=x2;
   y=y2;
   ye=y1;
  }
  putpixel(x+xm,ym-y,YELLOW);
  for(i=0;y<ye;i++)
  {
   y=y+1;
   if(py<=0)
   {
    py=py+2*dx1;
   }
   else
   {
    if((dx<0 && dy<0) || (dx>0 && dy>0))
    {
     x=x+1;
    }
    else
    {
     x=x-1;
    }
    py=py+2*(dx1-dy1);
   }
   delay(0);
   putpixel(x+xm,ym-y,YELLOW);
  }
 }


}


void window(int Xmin, int Ymin, int Xmax, int Ymax){

    BresenhamLine(Xmin,Ymin,Xmax,Ymin);

    BresenhamLine(Xmin,Ymin,Xmin,Ymax);

    BresenhamLine(Xmax,Ymin,Xmax,Ymax);

    BresenhamLine(Xmin,Ymax,Xmax,Ymax);
    /*line(Xmin,Ymin,Xmax,Ymin);
    line(Xmin,Ymin,Xmin,Ymax);
    line(Xmax,Ymin,Xmax,Ymax);
    line(Xmin,Ymax,Xmax,Ymax);*/
}


int ClipLine(int x, int y,int x1,int y1,int x2,int y2,int f ){
    int m;
    m=int((y2-y1)/(x2-x1));
    if (f==1){
        y=0;
        y=y1+(m*(x-x1));
        return(y);
    }
    else{
        x=0;
        x=x1+((y-y1)/m);
        return(x);
    }


}

int RegionCode(int x1, int y1, int x2, int y2, int Xmin, int Ymin, int Xmax, int Ymax){

    int b1,b2,b3,b4,a1,a2,a3,a4,flag=0;
    int a,x,y,X,Y,x3,y3;
    a=y1-Ymax;
    if(a>=0){
        b1=1;
        y=Ymax;
    }
    else
        b1=0;

    a=Ymin-y1;
    if(a>=0){
        b2=1;
        y=Ymin;
    }

    else
        b2=0;

    a=x1-Xmax;
    if(a>=0){
        b3=1;
        x=Xmax;
       }
    else
        b3=0;

    a=Xmin-x1;
    if(a>=0){
        b4=1;
        x=Xmin;}
    else
        b4=0;
       //x2 y2

    a=y2-Ymax;
    if(a>=0){
        a1=1;
        Y=Ymax;
    }
    else
        a1=0;

    a=Ymin-y2;
    if(a>=0){
        a2=1;
        Y=Ymin;
    }
    else
        a2=0;

    a=x2-Xmax;
    if(a>=0){
        a3=1;
        X=Xmax;
    }
    else
        a3=0;

    a=Xmin-x2;
    if(a>=0){
        a4=1;
        X=Xmin;
    }

    else
        a4=0;

    //code=b1+b2+b3+b4;
     //cout<<code<<endl;

    //stringstream geek(code);
    //geek>>c; ///TODO:string to boolean
    cout<<endl<<"Region Code:"<<endl<<"b1 b2 b3 b4"<<"  "<<b1<<b2<<b3<<b4<<endl;
    cout<<"a1 a2 a3 a4"<<"  "<<a1<<a2<<a3<<a4<<endl;


    if(a1==0 && b1==0 &&a2==0 &&b2==0 &&a3==0 &&b3==0 &&a4==0 &&b4==0 )
        cout<<"Visible"<<endl;
    else if((a1&b1)==0 && (a2&b2)==0 && (a3&b3)==0 && (a4&b4)==0)
            {
                cout<<"Candidate"<<endl;



            }
    else
            {
                cout<<"Not Visible"<<endl;
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
    int x1,x2,y1,y2,flag;
    cout<<"Enter Xmin Ymin Xmax Ymax"<<endl;
    cin>>Xmin>>Ymin>>Xmax>>Ymax;

    window(Xmin, Ymin, Xmax, Ymax);

//   c3=c1&c2;
    cout<<"Enter end points of Line please"<<endl<<"x1,y1,x2,y2"<<endl;
   cin>>x1>>y1>>x2>>y2;
    BresenhamLine(x1,y1,x2,y2);

    RegionCode(x1, y1, x2, y2, Xmin, Ymin, Xmax, Ymax);
    //cout<<flag<<endl;

    getch();
    closegraph();
return 0;
}




