																																	#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
	   /* request  auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int midx, midy, top, left, right, bottom;
   int radius = 50;

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "C:\\turboc3\\bgi");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }

   midx = getmaxx() / 2;
   midy = getmaxy() / 2;
   left = getmaxx() / 2 - 50;
   top = getmaxy() / 2 + 50;
   right = getmaxx() / 2 + 50 ;
   bottom = getmaxy() / 2 - 50;
   rectangle(left,top,right,bottom);
   setcolor(28);

   /* draw the circle */
   line(midx-20,midy-80,midx+20,midy-80);
   rectangle(left-50,top-60,left,bottom);
   rectangle(right,top-60,right+50,bottom);
   rectangle(left,top+80,right-70,bottom+100);
   rectangle(left+70,top+80,right,bottom+100);
   circle(midx, midy-100, radius);
   putpixel(midx-25,midy-115,WHITE);
   putpixel(midx+25,midy-115,WHITE);
   outtextxy(midx-35,midy-180,"SUPERMAN");


   /* clean up */
   getch();
   closegraph();
   return 0;
}