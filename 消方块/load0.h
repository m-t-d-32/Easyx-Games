int getrandomcolor()
{
	int r=156+100*rand()/32768;
	int g=156+100*rand()/32768;
	int b=156+100*rand()/32768;
	return RGB(r,g,b);
}
void welcome_func()
{
	initgraph(480,480);
	for (int i=0;i<7;i++)
	{
		setbkcolor(getrandomcolor());
		cleardevice();
		Sleep(200);
	}
	settextcolor(PURPLE);
	settextstyle(50,0,"楷体");
	outtextxy(80,50,"消消乐");	
	settextcolor(BLACK);
	settextstyle(20,0,"楷体");
	outtextxy(260,150,"Vista纪念专版");
	settextstyle(16,0,"楷体");
	outtextxy(260,180,"Powered By Windows 5.1");
	IMAGE vista;
	loadimage(&vista,"ima\\vista.jpg");
	putimage(0,200,&vista);
	settextstyle(18,0,"楷体");
	Sleep(2000);
	setbkcolor(BLACK);
	cleardevice();
	settextstyle(58,0,"楷体");
	settextcolor(WHITE);
	outtextxy(30,180,"按下任意键开始");
	getch();
	closegraph();
}
void draw_pic(int x,int y,int n)
{
	char part1[20]="ima\\";
	char part2[5];
	char part3[5]=".jpg";
	sprintf(part2,"%d",n);
	IMAGE picF;
	IMAGE *picpoint=&picF;
	strcat(part1,part2);
	strcat(part1,part3);
	loadimage(picpoint,part1);
	putimage(x,y,picpoint);
}