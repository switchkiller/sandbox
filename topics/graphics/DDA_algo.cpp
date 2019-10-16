#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
//#include<ncurses.h>

using namespace std;
int main(){
  int gdriver=DETECT,gmode,errorcode;
  int x1=220,x2=500,y1=250,y2=100,m,i;
  initgraph(&gdriver,&gmode,NULL);
  /*errorcode=graphresult();
  if (errorcode!=grOk)
  {
    cout<<"Graphics error: "<<grapherrormsg(errorcode);
    cout<<"Press any key to halt...";
    getch();
    exit(0);
  }*/
  i=x1;
  m=( (y2-y1)/(x2-x1) );
  putpixel(x1,y1,1);
  for (;i<=x2;i++){
    if (m<=1){
      x1=x1+1;
      y1=y1+m+1;
    }
    else{
      x1=x1+(1/m)+1;
      y1=y1+1;
    }
    putpixel(x1,y1,1);
    delay(10);
  }
  //getch();

  getch();
  closegraph();
  return 0;
}
