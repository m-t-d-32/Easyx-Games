#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
#include <time.h>
int panduan(int a,int daoshu2,int zuihou)
{
	int k=1;
   if (a==1 && daoshu2==zuihou-10) k=0;
   else if (a==2 && daoshu2==zuihou+10) k=0;
   else if (a==3 && daoshu2==zuihou+10) k=0;
   else if (a==4 && daoshu2==zuihou-10) k=0;
   return k;
}
double suiji(int m)
{
	time_t a;
	time(&a);
	srand(a+m);
	double b;
	b=rand()%100;
	b/=100.0;
	return b;
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
int main()
{
 int jifen=0;
 char jifenxx[10];
 int pds=0;
 int pdsw=0;
 int cd=4;
 system("cls");
 printf("Please input the mode you would like.\n");
 printf("1.Mode for old people\n");
 printf("2.Mode for ordinary people(Default Mode)\n");
 printf("3.Mode for REALLY MEN\n");
 int mode=2;
 scanf("%d",&mode);
 system("cls");
 printf("Are you ready?");
 system("pause");
 system("cls");
 initgraph(640,490);
 char detect;
 int shiwux,shiwuy;
 int a[1000][2]={{80,90},{70,90},{60,90},{60,80}};
 int i;
 int random=3;
 int j;
 int tmp1,tmp2;
 setbkcolor(WHITE);
 itoa(jifen,jifenxx,10);
 setcolor(BLACK);
 setcolor(BLUE);
 setcolor(GREEN);
 for (i=1;i<cd;i++)
 {
  rectangle(a[i][0],a[i][1],a[i][0]+10,a[i][1]+10);
 }
 setcolor(YELLOW);
 rectangle(a[0][0],a[0][1],a[0][0]+10,a[0][1]+10);
 setcolor(RED);
 shiwux=int(580*suiji(random)+50);
 shiwux/=10;
 shiwux*=10;
 shiwuy=int(440*suiji(random*2)+30);
 shiwuy/=10;
 shiwuy*=10;
 mybar(shiwux,shiwuy,shiwux+10,shiwuy+10,RED);
 while (pds!=1)
 {
 for (i=0;i<64;i++)
{
	bar(10*i,0,10*i+10,10);
	bar(10*i,470,10*i+10,490);
 }
 bar(10,10,50,30);
 for (i=0;i<48;i++)
 {
	bar(0,10*i,10,10*i+10);
	bar(630,10*i,640,10*i+10);
 }
 setcolor(BLUE);
  settextstyle(20,0,_T("ËÎÌו"));
 outtextxy(0,470,"Powered By Windows 5.1");
 if (mode==1)
 {
 bar(0,0,45,15);
 setcolor(RED);
 settextstyle(25,10,_T("ËÎÌו"));
 }
 outtextxy(0,0,jifenxx);
   random++;
   if (a[0][0]==shiwux && a[0][1]==shiwuy)
   {
	 jifen++;
	 itoa(jifen,jifenxx,10);
	 if (mode==1)
	 bar(0,0,45,15);
	 else
	 bar(0,0,30,10);
	 mybar(shiwux,shiwuy,shiwux+10,shiwuy+10,BLACK);
	 setcolor(BLUE);
	 outtextxy(0,0,jifenxx);
	 if (a[cd-2][0]==a[cd-1][0] && a[cd-2][1]>a[cd-1][1])
	 {
		a[cd][0]=a[cd-1][0];
		a[cd][1]=a[cd-1][1]-10;
	 }
	 else if (a[cd-2][0]==a[cd-1][0] && a[cd-2][1]<a[cd-1][1])
	 {
		a[cd][0]=a[cd-1][0];
		a[cd][1]=a[cd-1][1]+10;
	 }
	 else if (a[cd-2][1]==a[cd-1][1] && a[cd-2][0]>a[cd-1][0])
	 {
		a[cd][1]=a[cd-1][1];
		a[cd][0]=a[cd-1][0]-10;
	 }
	 else if (a[cd-2][1]==a[cd-1][1] && a[cd-2][0]>a[cd-1][0])
	 {
		a[cd][1]=a[cd-1][1];
		a[cd][0]=a[cd-1][0]+10;
	 }
	 setcolor(GREEN);
	 rectangle(a[cd][0],a[cd][1],a[cd][0]+10,a[cd][1]+10);
	  cd++;
	 setcolor(RED);
	 do
	 {
	tmp1=int(620*suiji(random)+10);
	tmp1/=10;
	tmp1*=10;
	tmp2=int(460*suiji(random*2-1)+10);
	tmp2/=10;
	tmp2*=10;
	pdsw=0;
	for (i=0;i<=cd;i++)
	{
	  if (tmp1==a[i][0] && tmp2==a[i][1]) {pdsw=1;break;}
	}
	 } while ((tmp1==shiwux && tmp2==shiwuy) || pdsw==1);
     shiwux=tmp1;
     shiwuy=tmp2;
     mybar(shiwux,shiwuy,shiwux+10,shiwuy+10,RED);
   }
   if (mode==1)
   Sleep(300);
   else if (mode==3)
   Sleep(50);
   else
   Sleep(200);
   if (kbhit()!=0)
   {detect=getch();
    
   if (detect=='A'|| detect=='a')
   {
     if (panduan(1,a[1][0],a[0][0])==1)
     {
       setcolor(BLACK);
       for (i=0;i<cd;i++)
       {
       rectangle(a[i][0],a[i][1],a[i][0]+10,a[i][1]+10);
       }
       for (i=cd-1;i>0;i--)
       {
	     a[i][0]=a[i-1][0];
	     a[i][1]=a[i-1][1];
       }
		a[0][0]-=10;
       for (i=1;i<cd;i++)
       {
		 setcolor(GREEN);
	     rectangle(a[i][0],a[i][1],a[i][0]+10,a[i][1]+10);
       }
       setcolor(YELLOW);
       rectangle(a[0][0],a[0][1],a[0][0]+10,a[0][1]+10);
     }
   }
   else if (detect=='D' || detect=='d')
   {
     if (panduan(2,a[1][0],a[0][0])==1)
     {
	setcolor(BLACK);
       for (i=0;i<cd;i++)
       {
       rectangle(a[i][0],a[i][1],a[i][0]+10,a[i][1]+10);
       }
       for (i=cd-1;i>0;i--)
       {
	     a[i][0]=a[i-1][0];
	     a[i][1]=a[i-1][1];
       }
		a[0][0]+=10;
       for (i=1;i<cd;i++)
       {
	   setcolor(GREEN);
	   rectangle(a[i][0],a[i][1],a[i][0]+10,a[i][1]+10);
       }
       setcolor(YELLOW);
       rectangle(a[0][0],a[0][1],a[0][0]+10,a[0][1]+10);
     }
   }
   else if (detect=='S' || detect=='s')
   {
     if (panduan(3,a[1][1],a[0][1])==1)
     {
	   setcolor(BLACK);
       for (i=0;i<cd;i++)
       {
       rectangle(a[i][0],a[i][1],a[i][0]+10,a[i][1]+10);
       }
       for (i=cd-1;i>0;i--)
       {
	     a[i][0]=a[i-1][0];
	     a[i][1]=a[i-1][1];
       }
		a[0][1]+=10;
       for (i=1;i<cd;i++)
       {
	   setcolor(GREEN);
	   rectangle(a[i][0],a[i][1],a[i][0]+10,a[i][1]+10);
       }
       setcolor(YELLOW);
       rectangle(a[0][0],a[0][1],a[0][0]+10,a[0][1]+10);
     }
   }
   else if (detect=='W' || detect=='w')
   {
     if (panduan(4,a[1][1],a[0][1])==1)
     {
	   setcolor(BLACK);
       for (i=0;i<cd;i++)
       {
       rectangle(a[i][0],a[i][1],a[i][0]+10,a[i][1]+10);
       }
       for (i=cd-1;i>0;i--)
       {
	     a[i][0]=a[i-1][0];
	     a[i][1]=a[i-1][1];
       }
		a[0][1]-=10;
       for (i=1;i<cd;i++)
       {
		 setcolor(GREEN);
	     rectangle(a[i][0],a[i][1],a[i][0]+10,a[i][1]+10);
       }
       setcolor(YELLOW);
       rectangle(a[0][0],a[0][1],a[0][0]+10,a[0][1]+10);
     }
   }
   else if (detect=='Q' || detect=='q') break;
   }
   else
   {
	if (a[0][0]==a[1][0] && a[0][1]>a[1][1])
	{
		setcolor(BLACK);
       for (i=0;i<cd;i++)
       {
       rectangle(a[i][0],a[i][1],a[i][0]+10,a[i][1]+10);
       }
       for (i=cd-1;i>0;i--)
       {
	     a[i][0]=a[i-1][0];
	     a[i][1]=a[i-1][1];
       }
		a[0][1]+=10;
       for (i=1;i<cd;i++)
       {
	   setcolor(GREEN);
	   rectangle(a[i][0],a[i][1],a[i][0]+10,a[i][1]+10);
       }
       setcolor(YELLOW);
       rectangle(a[0][0],a[0][1],a[0][0]+10,a[0][1]+10);
	}
   else if (a[0][0]==a[1][0] && a[0][1]<a[1][1])
   {
	   setcolor(BLACK);
       for (i=0;i<cd;i++)
       {
       rectangle(a[i][0],a[i][1],a[i][0]+10,a[i][1]+10);
       }
       for (i=cd-1;i>0;i--)
       {
	     a[i][0]=a[i-1][0];
	     a[i][1]=a[i-1][1];
       }
		a[0][1]-=10;
       for (i=1;i<cd;i++)
       {
		 setcolor(GREEN);
	     rectangle(a[i][0],a[i][1],a[i][0]+10,a[i][1]+10);
       }
       setcolor(YELLOW);
       rectangle(a[0][0],a[0][1],a[0][0]+10,a[0][1]+10);
   }
   else if(a[0][1]==a[1][1] && a[0][0]>a[1][0])
   {
	   setcolor(BLACK);
       for (i=0;i<cd;i++)
       {
       rectangle(a[i][0],a[i][1],a[i][0]+10,a[i][1]+10);
       }
       for (i=cd-1;i>0;i--)
       {
	     a[i][0]=a[i-1][0];
	     a[i][1]=a[i-1][1];
       }
		a[0][0]+=10;
       for (i=1;i<cd;i++)
       {
	   setcolor(GREEN);
	   rectangle(a[i][0],a[i][1],a[i][0]+10,a[i][1]+10);
       }
       setcolor(YELLOW);
       rectangle(a[0][0],a[0][1],a[0][0]+10,a[0][1]+10);
   }
   else if(a[0][1]==a[1][1] && a[0][0]<a[1][0])
   {
       setcolor(BLACK);
       for (i=0;i<cd;i++)
       {
       rectangle(a[i][0],a[i][1],a[i][0]+10,a[i][1]+10);
       }
       for (i=cd-1;i>0;i--)
       {
	     a[i][0]=a[i-1][0];
	     a[i][1]=a[i-1][1];
       }
		a[0][0]-=10;
       for (i=1;i<cd;i++)
       {
		 setcolor(GREEN);
	     rectangle(a[i][0],a[i][1],a[i][0]+10,a[i][1]+10);
       }
       setcolor(YELLOW);
       rectangle(a[0][0],a[0][1],a[0][0]+10,a[0][1]+10);
	}
   }
   for (i=1;i<cd;i++)
   {
	if (a[0][0]==a[i][0] && a[0][1]==a[i][1])
	{
	   pds=1;
	   break;
	}
   }
   if (a[0][0]<=0 || a[0][0]>=630 || a[0][1]<=0 || a[0][1]>=470) break;
 }
 closegraph();
 system("cls");
 printf("Game over\n");
 printf("You have got %d scores!\n",jifen);
 system("pause");
 return 0;
}
