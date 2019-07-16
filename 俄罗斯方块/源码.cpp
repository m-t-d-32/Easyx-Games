//谜の算法
//苟利国家生死以，岂因祸福避趋之。
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#pragma comment(lib,"WINMM.LIB")
#include <iostream>
using namespace std;
#include <algorithm>
#define up 30
#define left 40
#define wide 20
#define next_left 330
#define next_up 250
int screen[11][21];
int axis_x,axis_y;
int next_shape;
int backcolor;
int show_shape[4][2];
TCHAR key_score[4];
time_t timenow;
int score=0;
int mode;
struct rec
{
	int nowsquare;
	int x;
	int y;
	int color;
	bool axis_init;
};
rec square[4];
void redioactive()
{
	int i,j;
	setfillcolor(GREEN);
	for (i=0;i<11;i++)
	{
		for (j=0;j<21;j++)
		{
			if (screen[i][j]!=0)
			{
				bar(left+i*wide,up+j*wide,left+(i+1)*wide,up+(j+1)*wide);
			}
		}
	}
}
void radio(int u)
{
	int i,j;
	for (i=u;i>1;i--)
	{
		for (j=1;j<10;j++)
		{
			if (screen[j][i]==0)
			{
				setfillcolor(backcolor);
				bar(left+wide*j,up+wide*i,left+wide*(j+1),up+wide*(i+1));
			}
			else
			{
				setfillcolor(getpixel(left+j*20+10,up+(i-1)*20+10));
				bar(left+wide*j,up+wide*i,left+wide*(j+1),up+wide*(i+1));
				setcolor(WHITE);
				rectangle(left+wide*j,up+wide*i,left+wide*(j+1),up+wide*(i+1));
			}
		}
	}
}
void delete_line()
{
	bool t=false;
	int i,j,s;
	int ii,jj;
	for (i=1;i<20;i++)
	{
		t=true;
		for (j=1;j<10;j++)
		{
			if (screen[j][i]==0)
			{
				t=false;
				break;
			}
		}
		if (t==true)
		{
			score++;
			for (s=i;s>1;s--)
			{
				for (j=1;j<10;j++)
				{
					screen[j][s]=screen[j][s-1];
				}
			}
			radio(i);
			setfillcolor(backcolor);
			bar(320,100,480,200);
			_stprintf(key_score,_T("%d"),score);
			settextstyle(50,0,_T("黑体"));
			settextcolor(RGB(rand()%200+56,rand()%189+56,rand()%192+56));
			outtextxy(360-score/10*10,100,key_score);
			setcolor(WHITE);
			for (ii=1;ii<10;ii++)
			{
				for (jj=1;jj<20;jj++)
				{
					if (screen[ii][jj]!=0)
					{
						rectangle(left+ii*wide,up+jj*wide,left+ii*wide+wide,up+jj*wide+wide);
					}
				}
			}
		}
	}
}
void colorfull(bool t)
{
	int i;
	if (t==true)
	{
		setfillcolor(square[0].color);
		for (i=0;i<4;i++)
		screen[square[i].x][square[i].y]=1;
	}
	else
	{
		setfillcolor(backcolor);
		for (i=0;i<4;i++)
		screen[square[i].x][square[i].y]=0;
	}
	for (i=0;i<4;i++)
	{
		bar(left+wide*square[i].x,up+wide*square[i].y,left+wide*(square[i].x+1),up+wide*(square[i].y+1));
		if (t==true)
		{
			setcolor(WHITE);
			rectangle(left+wide*square[i].x,up+wide*square[i].y,left+wide*(square[i].x+1),up+wide*(square[i].y+1));
		}
	}
}
void spain()
{
	int i;
	if (square[0].nowsquare==6) return;
	int tmp[4][2];
	if (square[0].axis_init==false)
	{
		if (square[0].nowsquare==4 || square[0].nowsquare==5)
		{
			axis_x=square[0].x+1;
			axis_y=square[0].y;
		}
		else
		{
			axis_x=square[0].x+1;
			axis_y=square[0].y+1;
		}
	}
	for (i=0;i<4;i++)
	{
		tmp[i][0]=axis_x-(axis_y-square[i].y);
		tmp[i][1]=axis_y+(axis_x-square[i].x);
		if (screen[tmp[i][0]][tmp[i][1]]==99) return;
	}
	colorfull(false);
	for (i=0;i<4;i++)
	{
		square[i].x=tmp[i][0];
		square[i].y=tmp[i][1];
	}
	colorfull(true);
	square[0].axis_init=true;
}
void init(int randomx)
{
			square[0].x=randomx;
			square[0].y=1;
			square[1].x=square[0].x+1;
			square[1].y=1;
			square[2].x=square[1].x+1;
			square[2].y=1;
			square[3].x=square[0].x;
			square[3].y=2;
			if (square[0].nowsquare==0) return;
			square[3].x+=1;
			if (square[0].nowsquare==1) return;
			square[3].x+=1;
			if (square[0].nowsquare==2) return;
			square[2].x-=1;
			square[2].y+=1;
			if (square[0].nowsquare==3) return;
			square[0].y+=1;
			square[3].y-=1;
			if (square[0].nowsquare==4) return;
			square[1].x+=1;
			square[1].y+=1;
			square[3].x+=1;
			square[3].y+=1;
			if (square[0].nowsquare==5) return;
			square[1].x-=2;
			square[1].y--;
			square[3].x-=2;
			square[3].y--;
}
void next()
{
			show_shape[0][0]=0;
			show_shape[0][1]=1;
			show_shape[1][0]=show_shape[0][0]+1;
			show_shape[1][1]=1;
			show_shape[2][0]=show_shape[1][0]+1;
			show_shape[2][1]=1;
			show_shape[3][0]=show_shape[0][0];
			show_shape[3][1]=2;
			if (next_shape==0) return;
			show_shape[3][0]+=1;
			if (next_shape==1) return;
			show_shape[3][0]+=1;
			if (next_shape==2) return;
			show_shape[2][0]-=1;
			show_shape[2][1]+=1;
			if (next_shape==3) return;
			show_shape[0][1]+=1;
			show_shape[3][1]-=1;
			if (next_shape==4) return;
			show_shape[1][0]+=1;
			show_shape[1][1]+=1;
			show_shape[3][0]+=1;
			show_shape[3][1]+=1;
			if (next_shape==5) return;
			show_shape[1][0]-=2;
			show_shape[1][1]--;
			show_shape[3][0]-=2;
			show_shape[3][1]--;
}
void show_next()
{
	int i;
	setfillcolor(backcolor);
	bar(300,240,480,400);
	for (i=0;i<4;i++)
	{
		rectangle(next_left+wide*show_shape[i][0],next_up+wide*show_shape[i][1],next_left+wide*show_shape[i][0]+wide,next_up+wide*show_shape[i][1]+wide);
	}
}
int main()
{
	fill(screen[0],screen[0]+231,0);
	time(&timenow);
	srand(timenow);
	initgraph(640,480);
	loadimage(NULL,_T("BACK.BMP"));
	Sleep(2000);
	closegraph();
	system("cls");
	printf("Please input the mode you would like.\n");
	printf("1.Mode For old people\n");
	printf("2.Mode For ordinary people(Default Mode)\n");
	printf("3.Mode For really men\n");
	scanf("%d",&mode);
	int s_time;
	if (mode==1) s_time=300;
	else if (mode==3) s_time=100;
	else s_time=200;
	initgraph(640,480);
	PlaySound(TEXT("back.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
	settextstyle(30,0,_T("宋体"));
	outtextxy(200,200,_T("Welcome To Play!"));
	Sleep(2000);
	initgraph(480,480);
	backcolor=RGB(rand()%30,rand()%50,rand()%64);
	setbkcolor(backcolor);
	cleardevice();
	int i;
	TCHAR key_score[5];
	char keyboard;
	bool judge_down;
	bool judge_right;
	bool judge_left;
	bool judge_um_down;
	int down_num;
	int randomx;
	setcolor(YELLOW);
	rectangle(left,up,left+wide*11,up+wide*21);
	rectangle(left+wide,up+wide,left+wide*10,up+wide*20);
	settextstyle(20,0,_T("黑体"));
	outtextxy(320,30,_T("Your Score"));
	settextstyle(50,0,_T("黑体"));
	outtextxy(360,100,_T("0"));
	settextstyle(20,0,_T("黑体"));
	outtextxy(320,200,_T("Next Shape"));
	settextcolor(RED);
	outtextxy(300,400,_T("Press Q to exit"));
	for (i=0;i<11;i++)
	{
		screen[i][0]=99;
		screen[i][20]=99;
	}
	for (i=0;i<21;i++)
	{
		screen[0][i]=99;
		screen[10][i]=99;
	}
	redioactive();
	next_shape=rand()%7;
	while (1)
	{
		square[0].axis_init=false;
		down_num=0;
		square[0].nowsquare=next_shape;
		next_shape=rand()%7;
		setcolor(RGB(rand()%200+56,rand()%189+56,rand()%192+56));
		next();
		show_next();
		square[0].color=RGB(rand()%200+56,rand()%189+56,rand()%192+56);
		randomx=rand()%5+1;
		init(randomx);
		judge_down=true;
		colorfull(true);
		delete_line();
		while (1)
		{
			setcolor(YELLOW);
			rectangle(left,up,left+wide*11,up+wide*21);
			rectangle(left+wide,up+wide,left+wide*10,up+wide*20);
			Sleep(s_time);
			if (kbhit()==0)
			{
			for (i=0;i<4;i++)
			{
				if (screen[square[i].x][square[i].y+1]==99)
				{
					judge_down=false;
				}
			}
			if (judge_down==false) break;
			down_num++;
			colorfull(false);
			for (i=0;i<4;i++)
			{
				square[i].y++;
			}
			axis_y++;
			colorfull(true);
			}
			else
			{
				keyboard=getch();
				judge_right=true;
				judge_left=true;
				judge_um_down=true;
				if (keyboard=='D' || keyboard=='d')
				{
					for (i=0;i<4;i++)
					{
						if (screen[square[i].x+1][square[i].y]==99)
						{
							judge_right=false;
						}
					}
					colorfull(false);
					if (judge_right==true)
					{
						for (i=0;i<4;i++)
						{
							square[i].x++;
						}
						axis_x++;
					}
					colorfull(true);
				}
				else if (keyboard=='A' || keyboard=='a')
				{
					for (i=0;i<4;i++)
					{
						if (screen[square[i].x-1][square[i].y]==99)
						{
							judge_left=false;
						}
					}
					colorfull(false);
					if (judge_left==true)
					{
						for (i=0;i<4;i++)
						{
							square[i].x--;
						}
						axis_x--;
					}
					colorfull(true);
				}
				else if (keyboard=='S' || keyboard=='s')
				{
					for (i=0;i<4;i++)
					{
						if (screen[square[i].x][square[i].y+1]==99)
						{
							judge_down=false;
						}
					}
					if (judge_down==false) break;
					for (i=0;i<4;i++)
					{
						if (screen[square[i].x][square[i].y+2]==99)
						{
							judge_um_down=false;
						}
					}
					colorfull(false);
					if (judge_um_down==true)
					{
						for (i=0;i<4;i++)
						{
							square[i].y+=2;
							down_num+=2;
						}
						axis_y+=2;
					}
					else
					{
						for (i=0;i<4;i++)
						{
							square[i].y++;
							down_num++;
						}
						axis_y++;
					}
					colorfull(true);
				}
				else if (keyboard=='W' || keyboard=='w')
				{
					spain();
				}
				else if (keyboard=='Q' || keyboard=='q')
				{
					down_num=0;
					break;
				}
			}
		}
		for (i=0;i<4;i++)
		{
			screen[square[i].x][square[i].y]=99;
		}
		if (down_num==0) break;
	}
	_stprintf(key_score,_T("%d"),score);
	for (i=0;i<4;i++)
	{
	 cleardevice();
	 Sleep(100);
	 settextstyle(20,0,_T("黑体"));
	 outtextxy(200,150,_T("Game Over"));
	 outtextxy(190,180,_T("Final Score"));
	 Sleep(100);
	 settextstyle(50,0,_T("黑体"));
	 outtextxy(230-score/10*10,220,key_score);
	 Sleep(100);
	}
	PlaySound(NULL,NULL,NULL);
	settextstyle(20,0,_T("黑体"));
	outtextxy(145,400,_T("Press Any Key to Exit"));
	system("pause");
	return 0;
}
