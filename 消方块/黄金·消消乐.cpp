#undef UNICODE
#define PURPLE RGB(85,26,139)
#define PINK RGB(255,20,147)
int COUNT=10;
int EVERY=48;
int color[30][30];
int score=0;
int heart=3;
int nowx,nowy;
#include <stdio.h>
#include <graphics.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include "basic.h"
#include "play.h"
#pragma comment(lib,"WINMM.LIB")
int main()
{
	PlaySound(TEXT("back.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
	randominit();
	welcome_func();
	initgraph(640,480);
	cleardevice();
	gameinit();
	while (1)
	{
		control_0();
	}
	return 0;
}