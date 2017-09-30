// This program was made by Windows 5.1,
// Copyright 1992-2006,All rights reserved.
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <time.h>
#include <dos.h>
#define Up 50
#define Left 50
#define wide 30
#pragma comment(lib,"WINMM.LIB")
int show[10][10];
char text[3];
int square[10][10];
float suiji(int M)
{
	time_t a;
	time(&a);
	srand(a+M);
	float b;
	int t;
	t=rand()%10;
	b=t/10.0;
	return b;
}
void digui(int p,int q,int &kind)
{
if (show[p+1][q]==0 && p+1<=9 && square[p+1][q]==0){setcolor(BLACK);
	settextstyle(29, 29, _T("宋体"));itoa(show[p+1][q],text,10);
	outtextxy((p+1)*wide+Left+1,q*wide+Up+1,text);square[p+1][q]=99;kind--;
	digui(p+1,q,kind);}
	else if (p+1<=9 && square[p+1][q]==0){setcolor(BLACK);
	settextstyle(29, 29, _T("宋体"));itoa(show[p+1][q],text,10);
	outtextxy((p+1)*wide+Left+1,q*wide+Up+1,text);square[p+1][q]=99;kind--;}
if (show[p-1][q]==0 && p-1>=0 && square[p-1][q]==0){setcolor(BLACK);
	settextstyle(29, 29, _T("宋体"));itoa(show[p-1][q],text,10);
	outtextxy((p-1)*wide+Left+1,q*wide+Up+1,text);square[p-1][q]=99;kind--;
	digui(p-1,q,kind);}
	else if (p-1>=0 && square[p-1][q]==0){setcolor(BLACK);
	settextstyle(29, 29, _T("宋体"));itoa(show[p-1][q],text,10);
	outtextxy((p-1)*wide+Left+1,q*wide+Up+1,text);square[p-1][q]=99;kind--;}
if (show[p][q+1]==0 && q+1<=9 && square[p][q+1]==0){setcolor(BLACK);
	settextstyle(29, 29, _T("宋体"));itoa(show[p][q+1],text,10);
	outtextxy(p*wide+Left+1,(q+1)*wide+Up+1,text);square[p][q+1]=99;kind--;
	digui(p,q+1,kind);}
	else if (q+1<=9 && square[p][q+1]==0){setcolor(BLACK);
	settextstyle(29, 29, _T("宋体"));itoa(show[p][q+1],text,10);
	outtextxy(p*wide+Left+1,(q+1)*wide+Up+1,text);square[p][q+1]=99;kind--;}
if (show[p][q-1]==0 && q-1>=0 && square[p][q-1]==0){setcolor(BLACK);
	settextstyle(29, 29, _T("宋体"));itoa(show[p][q-1],text,10);
	outtextxy(p*wide+Left+1,(q-1)*wide+Up+1,text);square[p][q-1]=99;kind--;
	digui(p,q-1,kind);}
	else if (q-1>=0 && square[p][q-1]==0){setcolor(BLACK);
	settextstyle(29, 29, _T("宋体"));itoa(show[p][q-1],text,10);
	outtextxy(p*wide+Left+1,(q-1)*wide+Up+1,text);square[p][q-1]=99;kind--;}
if (show[p+1][q+1]==0 && p+1<=9 && q+1<=9 && square[p+1][q+1]==0){setcolor(BLACK);
	settextstyle(29, 29, _T("宋体"));itoa(show[p+1][q+1],text,10);
	outtextxy((p+1)*wide+Left+1,(q+1)*wide+Up+1,text);square[p+1][q+1]=99;kind--;
	digui(p+1,q+1,kind);}
	else if (p+1<=9 && q+1<=9 && square[p+1][q+1]==0){setcolor(BLACK);
	settextstyle(29, 29, _T("宋体"));itoa(show[p+1][q+1],text,10);
	outtextxy((p+1)*wide+Left+1,(q+1)*wide+Up+1,text);square[p+1][q+1]=99;kind--;}
if (show[p-1][q+1]==0 && p-1>=0 && q+1<=9 && square[p-1][q+1]==0){setcolor(BLACK);
	settextstyle(29, 29, _T("宋体"));itoa(show[p-1][q+1],text,10);
	outtextxy((p-1)*wide+Left+1,(q+1)*wide+Up+1,text);square[p-1][q+1]=99;kind--;
	digui(p-1,q+1,kind);}
	else if (p-1>=0 && q+1<=9 && square[p-1][q+1]==0){setcolor(BLACK);
	settextstyle(29, 29, _T("宋体"));itoa(show[p-1][q+1],text,10);
	outtextxy((p-1)*wide+Left+1,(q+1)*wide+Up+1,text);square[p-1][q+1]=99;kind--;}
if (show[p+1][q-1]==0 && p+1<=9 && q-1>=0 && square[p+1][q-1]==0){setcolor(BLACK);
	settextstyle(29, 29, _T("宋体"));itoa(show[p+1][q-1],text,10);
	outtextxy((p+1)*wide+Left+1,(q-1)*wide+Up+1,text);square[p+1][q-1]=99;kind--;
	digui(p+1,q-1,kind);}
	else if (p+1<=9 && q-1>=0 && square[p+1][q-1]==0){setcolor(BLACK);
	settextstyle(29, 29, _T("宋体"));itoa(show[p+1][q-1],text,10);
	outtextxy((p+1)*wide+Left+1,(q-1)*wide+Up+1,text);square[p+1][q-1]=99;kind--;}
if (show[p-1][q-1]==0 && p-1>=0 && q-1>=0 && square[p-1][q-1]==0){setcolor(BLACK);
	settextstyle(29, 29, _T("宋体"));itoa(show[p-1][q-1],text,10);
	outtextxy((p-1)*wide+Left+1,(q-1)*wide+Up+1,text);square[p-1][q-1]=99;kind--;
	digui(p,q-1,kind);}
	else if (p-1>=0 && q-1>=0 && square[p-1][q-1]==0){setcolor(BLACK);
	settextstyle(29, 29, _T("宋体"));itoa(show[p-1][q-1],text,10);
	outtextxy((p-1)*wide+Left+1,(q-1)*wide+Up+1,text);square[p-1][q-1]=99;kind--;}
}
void mybar(int x,int y,int xx,int yy,int z)
{
setcolor(z);
int i;
for (i=y;i<=yy;i++)
{
 line(x,i,xx,i);
}
}
void boom(int x,int y,int &pds)
{
	int i;
	x=x*wide+Left+15;
	y=y*wide+Up+15;
	setcolor(BLACK);
	for (i=0;i<60;i++)
	{
		circle(x,y,i);
	}
	settextstyle(40, 0, _T("宋体"));
	outtextxy(100,380," You Lose!");
	Sleep(1000);
	pds=1;
}
int main()
{
	system("logo.exe");
	memset(square,0,100*sizeof(int));
	memset(show,0,100*sizeof(int));
	int n;
	int num;
	int select[2]={0,0};
	system("cls");
	printf("Please input the mode you would like:\n");
	printf("1.Mode for old people\n");
	printf("2.Mode for ordinary people(default)\n");
	printf("3.Mode for really men\n");
	printf("4.Mode for yourself\n");
	scanf("%d",&n);
	PlaySound(TEXT("back.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
	if (n==1) num=5;
	else if (n==3) num=20;
	else if (n==4)
	{
		printf("Please input the number of landmines you want.\n");
		scanf("%d",&num);
		while (num<=0 || num>49)
		{
			printf("The number doesn't seem correct,Please input the number which ranges from 1 to 49.\n");
			scanf("%d",&num);
		}
	}
	else num=10;
	initgraph(570,450);
	setbkcolor(YELLOW);
	cleardevice();
	setcolor(BLUE);
	settextstyle(42,0,_T("黑体"));
	outtextxy(10,0,"Mine Sweeping");
	settextstyle(18,0,_T("黑体"));
	outtextxy(100,400,"Powered By Windows 5.1");
	setcolor(LIGHTRED);
	settextstyle(25,0,_T("黑体"));
	outtextxy(380,20,"Press A to");
	outtextxy(380,50,"turn left.");
	outtextxy(380,80,"Press D to");
	outtextxy(380,110,"turn right.");
	outtextxy(380,140,"Press W to");
	outtextxy(380,170,"turn up.");
	outtextxy(380,200,"Press S to");
	outtextxy(380,230,"turn down.");
	outtextxy(380,260,"Press SPACE");
	outtextxy(380,290,"to sweep.");
	outtextxy(380,320,"Press R to");
	outtextxy(380,350,"mark it.");
	outtextxy(380,380,"Press Q to");
	outtextxy(380,410,"quit.");
	int i,j,s;
	int m=5;
	int kind=10*10-num;
	for (i=0;i<num;i++)
	{
		int tmp1=(int)(10*suiji(m));
		int tmp2=(int)(10*suiji(m*m));
		m++;
		if (m>100) m-=100;
		if (square[tmp1][tmp2]==1) i--;
		else square[tmp1][tmp2]=1;
	}
	for (i=0;i<10;i++)
	{
		for (j=0;j<10;j++)
		{
			s=0;
			if (square[i-1][j-1]==1 && i>=1 && j>=1) s++;
			if (square[i][j-1]==1 && j>=1) s++;
			if (square[i+1][j-1]==1 && j>=1 && i<=8) s++;
			if (square[i-1][j]==1 && i>=1) s++;
			if (square[i+1][j]==1 && i<=8) s++;
			if (square[i-1][j+1]==1  && i>=1 && j<=8) s++;
			if (square[i][j+1]==1 && j<=8) s++;
			if (square[i+1][j+1]==1 && i<=8 && j<=8) s++;
			show[i][j]=s;
		}
	}
	for (i=0;i<10;i++)
	{
		for (j=0;j<10;j++)
		{
			mybar(Left+j*wide+1,Up+i*wide+1,Left+j*wide+29,Up+i*wide+29,GREEN);
		}
	}
	int pds=0;
	setcolor(RED);
	rectangle(Left,Up,Left+wide,Up+wide);
	while (pds==0)
	{
		if (kind==0)
		{
			settextstyle(40,0,_T("宋体"));
			setcolor(RED);
			outtextxy(100,380," You Win! ");
			Sleep(1000);
			break;
		}
		char p=getch();
		if (p=='q' || p=='Q') 
		{
			pds=1;
			setbkcolor(BLACK);
			cleardevice();
			setcolor(RED);
			settextstyle(40,0,_T("黑体"));
			outtextxy(30,150,"You have stopped the game.");
			outtextxy(30,250,"Press any key to exit it.");
		}
		else if (p=='a' || p=='A')
		{
			if (select[0]-1>=0)
			{
				setcolor(YELLOW);
				rectangle(Left+select[0]*wide,Up+select[1]*wide,Left+wide+select[0]*wide,Up+wide+select[1]*wide);
				select[0]-=1;
				setcolor(RED);
				rectangle(Left+select[0]*wide,Up+select[1]*wide,Left+wide+select[0]*wide,Up+wide+select[1]*wide);
			}
		}
		else if (p=='d' || p=='D')
		{
			if (select[0]+1<=9)
			{
				setcolor(YELLOW);
				rectangle(Left+select[0]*wide,Up+select[1]*wide,Left+wide+select[0]*wide,Up+wide+select[1]*wide);
				select[0]+=1;
				setcolor(RED);
				rectangle(Left+select[0]*wide,Up+select[1]*wide,Left+wide+select[0]*wide,Up+wide+select[1]*wide);
			}
		}
		else if (p=='w' || p=='W')
		{
			if (select[1]-1>=0)
			{
				setcolor(YELLOW);
				rectangle(Left+select[0]*wide,Up+select[1]*wide,Left+wide+select[0]*wide,Up+wide+select[1]*wide);
				select[1]-=1;
				setcolor(RED);
				rectangle(Left+select[0]*wide,Up+select[1]*wide,Left+wide+select[0]*wide,Up+wide+select[1]*wide);
			}
		}
		else if (p=='s' || p=='S')
		{
			if (select[1]+1<=9)
			{
				setcolor(YELLOW);
				rectangle(Left+select[0]*wide,Up+select[1]*wide,Left+wide+select[0]*wide,Up+wide+select[1]*wide);
				select[1]+=1;
				setcolor(RED);
				rectangle(Left+select[0]*wide,Up+select[1]*wide,Left+wide+select[0]*wide,Up+wide+select[1]*wide);
			}
		}
		else if (p==' ')
		{
			if (getpixel(select[0]*wide+Left+15,select[1]*wide+Up+15)==BLUE)
			mybar(select[0]*wide+Left+1,select[1]*wide+Up+1,select[0]*wide+Left+29,select[1]*wide+Up+29,GREEN);
			else
			{
			if (square[select[0]][select[1]]==1)
			boom(select[0],select[1],pds);
			else
			{
				itoa(show[select[0]][select[1]],text,10);
				setcolor(BLACK);
				settextstyle(29, 29, _T("宋体"));
				outtextxy(select[0]*wide+Left+1,select[1]*wide+Up+1,text);
			 if (square[select[0]][select[1]]==0)
				{
					square[select[0]][select[1]]=99;
					kind--;
				}
				if(show[select[0]][select[1]]==0)
				{
					digui(select[0],select[1],kind);
				}
			}
		}
		}
		else if (p=='R' || p=='r')
		{
			mybar(select[0]*wide+Left+1,select[1]*wide+Up+1,select[0]*wide+Left+29,select[1]*wide+Up+29,BLUE);
		}
	}
	closegraph();
	system("cls");
	if (pds==0) printf("YOU WIN!\n");
	else printf("YOU LOSE!\n");
	system("pause");
	return 0;
}
