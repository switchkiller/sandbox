#include<stdio.h>
#include<graphics.h>

int main()
{
 //clrscr();
 int gdriver = DETECT,gmode;
 initgraph(&gdriver,&gmode,NULL);
 int x,y,i;
 for(i=0;i<=getmaxx();i++)
 {
  //Stars//
  putpixel(50,10,WHITE);
  putpixel(200,50,WHITE);
  putpixel(270,40,WHITE);
  putpixel(360,15,WHITE);
  putpixel(475,25,WHITE);
  //Moon//
  setcolor(YELLOW);
  circle(50,50,25);
  //Train//

  outtextxy(0+i,getmaxy()-50, " BHOPAL EXPRESS ");
  setfillstyle(SOLID_FILL,RED);
  bar(0+i,getmaxy()-50,150+i,getmaxy()-100);                        //Train Block
  setcolor(DARKGRAY);
  circle(10+i,getmaxy()-40,10);                                     //Rear Tyre
  circle(140+i,getmaxy()-40,10);                                    //Front Tyre
  delay(10);
  cleardevice();
  //Tunnel//
  setfillstyle(SOLID_FILL,RED);
  bar(getmaxx()-50,getmaxy()-150,getmaxx(),getmaxy());                  //End Point of Train
  //Track//
  setfillstyle(LINE_FILL,DARKGRAY);
  bar(0,getmaxy()-30,getmaxx()-50,getmaxy()-10);                        //Track of Train
 }
 getch();
 closegraph();
 return 0;
}
