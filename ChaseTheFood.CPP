#include<graphics.h>
#include<process.h>
#include<dos.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void food();
void out();
void arena();
int maxx,maxy,ox=0,oy=0;
int fx,fy,i=450,j=250;
void main()
{
	int x=0,y=-1,ch;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	while(1)                                  //infinite loop
	{
			circle(i,j,20);
			setcolor(BLUE);
			arena();
			out();
			setcolor(WHITE);
			outtextxy(485,400,"Press Esc to Exit...");
			if(kbhit())                //checkif a key is pressed
			{
				ch=getch();
				if(ch==72)                      //move upward
				{
						x=0;
						y=-1;
				}

				if(ch==75)                      //move left
				{
						x=-1;
						y=0;

				}

				if(ch==77)                      //move right
				{
						x=1;
						y=0;
				}

				if(ch==80)                     //move downward
				{
						x=0;
						y=1;
				}

				if(ch==27)                      //exit when escpressed
				exit(0);
			}
				i=i+x;
				j=j+y;
				food();
				delay(20);
				cleardevice();
	}
}
void food()
{
	int fsize=3;
	circle(fx,fy,fsize);
	if(i==fx||j==fy)
	{
		cleardevice();
		fx=rand()%400+1;
		fy=rand()%400+1;
		circle(fx,fy,fsize);
		food();
	}
}
void arena()
{
	maxx=getmaxx();
	maxx=maxx-160;
	maxy=getmaxy();
	rectangle(0,0,maxx,maxy);
}
void out()
{
	if(i==20 || i==(maxx-20))
	{
		outtextxy(485,400,"Game Over,Plz Exit...");
		getch();
	}
	if(j==20 || i==(maxy-20))
	{
		outtextxy(485,400,"Game Over,Plz Exit...");
		getch();
	}
	if(i==(maxx-20) || i==(maxy-20))
	{
		outtextxy(485,400,"Game Over,Plz Exit...");
		getch();
	}
	if(j==20 || j==(maxy-20))
	{
		outtextxy(485,400,"Game Over,Plz Exit...");
		getch();
	}
}