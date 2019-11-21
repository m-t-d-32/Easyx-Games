#include <graphics.h>
#if _MSC_VER >= 1200
#define getch _getch
#endif

int getrandomcolor()
{
	int r = 156 + 100 * rand() / 32768;
	int g = 156 + 100 * rand() / 32768;
	int b = 156 + 100 * rand() / 32768;
	return RGB(r, g, b);
}

void welcome_func()
{
	initgraph(480, 480);
	for (int i = 0; i<7; i++)
	{
		setbkcolor(getrandomcolor());
		cleardevice();
		Sleep(200);
	}
	settextcolor(PURPLE);
	settextstyle(50, 0, "楷体");
	outtextxy(80, 50, "消消乐");
	settextcolor(BLACK);
	settextstyle(20, 0, "楷体");
	outtextxy(260, 150, "Vista纪念专版");
	settextstyle(16, 0, "楷体");
	outtextxy(260, 180, "Powered By Windows 5.1");
	IMAGE vista;
	loadimage(&vista, "ima\\vista.jpg");
	putimage(0, 200, &vista);
	settextstyle(18, 0, "楷体");
	Sleep(2000);
	setbkcolor(BLACK);
	cleardevice();
	settextstyle(58, 0, "楷体");
	settextcolor(WHITE);
	outtextxy(30, 180, "按下任意键开始");
	getch();
	closegraph();
}
void draw_pic(int x, int y, int n)
{
	char part1[20] = "ima\\";
	char part2[5];
	char part3[5] = ".jpg";
	sprintf(part2, "%d", n);
	IMAGE picF;
	IMAGE *picpoint = &picF;
	strcat(part1, part2);
	strcat(part1, part3);
	loadimage(picpoint, part1);
	putimage(x, y, picpoint);
}


void printscore()
{
	setfillcolor(BLACK);
	bar(480,0,640,100);
	char lib[10];
	sprintf(lib,"%d",score);
	settextcolor(RED);
	settextstyle(30,0,"黑体");
	outtextxy(500,0,"你的得分");
	settextcolor(WHITE);
	settextstyle(40,0,"黑体");
	outtextxy(565-13*strlen(lib),50,lib);
}
void printheart()
{
	setfillcolor(BLACK);
	bar(480,420,640,480);
	char lib[10];
	sprintf(lib,"%d",heart);
	settextcolor(PINK);
	settextstyle(40,0,"黑体");
	outtextxy(565-13*strlen(lib),420,lib);
}
void printshow()
{
	settextcolor(WHITE);
	settextstyle(25,0,"隶书");
	outtextxy(490,140,"按下A键左移");
	outtextxy(490,165,"按下S键下移");
	outtextxy(490,190,"按下D键右移");
	outtextxy(490,215,"按下W键上移");
	outtextxy(485,240,"按下空格选中");
	settextcolor(YELLOW);
	settextstyle(20,0,"隶书");
	outtextxy(490,270,"连续三个或以上");
	outtextxy(500,290,"格子连成一线");
	outtextxy(500,310,"即可消去得分");
	settextcolor(WHITE);
	outtextxy(505,340,"按下E键重置");
	outtextxy(520,360,"整个画面");
	outtextxy(500,400,"剩余重置机会");
	printheart();
}
void gameover()
{
	cleardevice();
	settextcolor(PINK);
	settextstyle(50,0,"隶书");
	outtextxy(200,100,"游戏结束！");
	outtextxy(165,150,"您总共得分是");
	settextcolor(WHITE);
	char lib[10];
	sprintf(lib,"%d",score);
	settextstyle(70,0,"黑体");
	outtextxy(320-25*strlen(lib),250,lib);
	Sleep(1000);
	settextcolor(PINK);
	settextstyle(50,0,"隶书");
	outtextxy(165,350,"按任意键退出");
	getch();
	exit(0);
}
void redir()
{
	rectangle(nowx*EVERY,nowy*EVERY,nowx*EVERY+EVERY,nowy*EVERY+EVERY);
}
bool judge(int l,int c)
{
	int i,j;
	int sum=0;
	bool t=false;
	for (i=1;i<=COUNT;i++)
	{
		if (color[i][c]==color[i-1][c])
			sum++;
		else
		{
			if (sum>=2)
			{
				t=true;
				for (j=i-sum-1;j<COUNT;j++)
				{
					Sleep(100);
					if (j+sum+1<COUNT)
						color[j][c]=color[j+sum+1][c];
					else
						color[j][c]=rand()*12/32768+1;
						draw_pic(j*EVERY,c*EVERY,color[j][c]);
				}
				if (sum>=3)
				{
					heart++;
					printheart();
				}
				i=1;
			}
			sum=0;
		}
	}
	for (i=1;i<=COUNT;i++)
	{
		if (color[l][i]==color[l][i-1])
			sum++;
		else
		{
			if (sum>=2)
			{
				t=true;
				for (j=i-sum-1;j<COUNT;j++)
				{
					Sleep(100);
					if (j+sum+1<COUNT)
						color[l][j]=color[l][j+sum+1];
					else
						color[l][j]=rand()*12/32768+1;
						draw_pic(l*EVERY,j*EVERY,color[l][j]);
				}
				if (sum>=3)
				{
					heart++;
					printheart();
				}
				i=1;
			}
			sum=0;
		}
	}
	if (t)
	{
		score++;
		printscore();
		for (i=0;i<COUNT;i++)
		{
			judge(i,i);
		}
	}
	return t;
}
void swap(int ix,int iy,int jx,int jy)
{
	int i;
	int x1=ix*EVERY,x2=ix*EVERY+EVERY;
	int y1=iy*EVERY,y2=iy*EVERY+EVERY;
	int x3=jx*EVERY,x4=jx*EVERY+EVERY;
	int y3=jy*EVERY,y4=jy*EVERY+EVERY;
	setfillcolor(BLACK);
	const int bitx=(x3-x1)/EVERY;
	const int bity=(y3-y1)/EVERY;
	for (i=0;i<EVERY;i++)
	{
		bar(x1,y1,x2,y2);
		x1+=bitx;x2+=bitx;
		y1+=bity;y2+=bity;
		draw_pic(x1,y1,color[ix][iy]);
		bar(x3,y3,x4,y4);
		x3-=bitx;x4-=bitx;
		y3-=bity;y4-=bity;
		draw_pic(x3,y3,color[jx][jy]);
		Sleep(10);
	}
	int tmp=color[ix][iy];
	color[ix][iy]=color[jx][jy];
	color[jx][jy]=tmp;
	setcolor(BLACK);
	rectangle(x3,y3,x4,y4);
	setcolor(GREEN);
	rectangle(x1,y1,x2,y2);
	nowx=jx;nowy=jy;
}

void control_1()
{
	char t=getch();
	int tx=nowx,ty=nowy;
	switch (t)
	{
		case 'a':
		case 'A':
			{
				if (tx-1>=0)
				swap(tx,ty,tx-1,ty);
				if (!(judge(tx,ty) || judge(tx-1,ty)))
				swap(tx-1,ty,tx,ty);
				else
				redir();
				break;
			}
		case 'd':
		case 'D':
			{
				if (tx<COUNT-1)
				swap(tx,ty,tx+1,ty);
				if (!(judge(tx,ty) || judge(tx+1,ty)))
				swap(tx+1,ty,tx,ty);
				else
				redir();
				break;
			}
		case 'w':
		case 'W':
			{
				if (ty-1>=0)
				swap(tx,ty,tx,ty-1);
				if (!(judge(tx,ty) || judge(tx,ty-1)))
				swap(tx,ty-1,tx,ty);
				else
				redir();
				break;
			}
		case 's':
		case 'S':
			{
				if (ty<COUNT-1)
				swap(tx,ty,tx,ty+1);
				if (!(judge(tx,ty) || judge(tx,ty+1)))
				swap(tx,ty+1,tx,ty);
				else
				redir();
				break;
			}
		rectangle(nowx,nowy,nowx+EVERY,nowy+EVERY);
	}
}
void gameinit()
{
	int i,j,randnum;
	setcolor(GREEN);
	setlinestyle(0,3);
	for (i=0;i<COUNT;i++)
	{
		for (j=0;j<COUNT;j++)
		{
			randnum=rand()*12/32768+1;
			color[i][j]=randnum;
			draw_pic(i*EVERY,j*EVERY,randnum);
		}
	}
	printshow();
	for (i=0;i<COUNT;i++)
		judge(i,i);
	nowx=rand()*10/32768;
	nowy=rand()*10/32768;
	rectangle(EVERY*nowx,EVERY*nowy,EVERY*nowx+EVERY,EVERY*nowy+EVERY);
	printscore();
}
void control_0()
{
		char t=getch();
		switch (t)
		{
		case 'a':
		case 'A':
			{
				if (nowx>0)
				{
					setcolor(BLACK);
					rectangle(EVERY*nowx,EVERY*nowy,EVERY*nowx+EVERY,EVERY*nowy+EVERY);
					nowx--;
					setcolor(GREEN);
					rectangle(EVERY*nowx,EVERY*nowy,EVERY*nowx+EVERY,EVERY*nowy+EVERY);
				}
				break;
			}
		case 'd':
		case 'D':
			{
				if (nowx<COUNT-1)
				{
					setcolor(BLACK);
					rectangle(EVERY*nowx,EVERY*nowy,EVERY*nowx+EVERY,EVERY*nowy+EVERY);
					nowx++;
					setcolor(GREEN);
					rectangle(EVERY*nowx,EVERY*nowy,EVERY*nowx+EVERY,EVERY*nowy+EVERY);
				}
				break;
			}
		case 'w':
		case 'W':
			{
				if (nowy>0)
				{
					setcolor(BLACK);
					rectangle(EVERY*nowx,EVERY*nowy,EVERY*nowx+EVERY,EVERY*nowy+EVERY);
					nowy--;
					setcolor(GREEN);
					rectangle(EVERY*nowx,EVERY*nowy,EVERY*nowx+EVERY,EVERY*nowy+EVERY);
				}
				break;
			}
		case 's':
		case 'S':
			{
				if (nowy<COUNT-1)
				{
					setcolor(BLACK);
					rectangle(EVERY*nowx,EVERY*nowy,EVERY*nowx+EVERY,EVERY*nowy+EVERY);
					nowy++;
					setcolor(GREEN);
					rectangle(EVERY*nowx,EVERY*nowy,EVERY*nowx+EVERY,EVERY*nowy+EVERY);
				}
				break;
			}
		case 'e':
		case 'E':
			{
				if (heart>0)
				{
					heart--;
					gameinit();
				}
				break;
			}
		case 'q':
		case 'Q':
			{
				gameover();
			}
		case ' ':
			 {
				 control_1();
				 break;
			 }
		}
}
