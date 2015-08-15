#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<ncurses.h>

int main()
{
	/*request autodetection*/
	int gdriver=DETECT, gmode, errcode;
	int midx, midy;
	int stangle=4, endangle=135;
	int radius=100;

	/* intialize graphics and local variables */
	initgraph(&gdriver,&gmode, NULL);
	/* read result of initialization */
	errcode=graphresult();
	if (errcode!=grOK) {
	printf("Graphs error");
	getch();
	exit(1);
	}
	midx=getmaxx()/2;
	midy=getmaxy()/2;
	setcolor(getmaxcolor());

	arc(midx,midy,stangle,endangle,radius);
	getch();
	closegraph();
	return 0;
}
	
	
