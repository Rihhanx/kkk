#include<stdio. h> /*输入输出函数*/
#include<stdlib. h> /*包含系统函数， 定义杂项函数及内存
分配函数*/
#include<graphics. h> /*图像函数*/
#include<bios. h> /*存放有接口函数*/
#include<conio. h> /*定义了通过控制台进行数据输入和数据输出的函数,主要是一些用户通过按键盘产生的对应操作*/
#define LEFT 0x4b00 /*向左*/
#define RIGHT 0x4d00 /*向右*/
#define DOWN 0x5000 /*向下*/
#define UP 0x4800 /*向上*//*若想在游戏中途退出, 可按 Esc 键*/
#define ESC 0x011b /*退出键*//*SPACE 键表示落子*/
#define SPACE 0x3920 /*落子键*//*设置偏移量，即定义每一步光标移动的距离*/
#define OFFSET 20
#define OFFSET_x 4
#define OFFSET_y 3/*定义棋盘数组大小,即棋盘的大小，这里为 18x18 格*/
#define N 19/*定义全局变量*/
int status[N][N]; /*定义的数组，表示棋盘某点的状态（棋手1或棋手2）*/
int step_x, step_y; /*行走的坐标，即每一步光标移动的距离*/
int key; /*获取按下的键盘的键*/
int flag; /*玩家标志，当flag=0时，表示该点无棋子，flag=1表示玩家1的棋子，flag=2表示玩家2的棋子*//*自定义函数原型*/
void DrawBoard(); /*画棋盘函数*/
void DrawCircle(int x, int y, int color); /*画圆函数*/
void Alternation(); /*交换行棋方函数*/
void JudgePlayer(int x, int y); /*对不同的行棋方画不同颜色的圆函数*/
void Done(); /*执行下棋函数*/
int ResultCheck(int x, int y); /*判断当前行棋方是否获胜函数*/
void WelcomeInfo(); /*显示欢迎信息函数*/
void ShowMessage(); /*显示行棋方函数*/
/*定义函数*/
/*显示欢迎信息函数*/
void WelcomeInfo()
{
	char ch; /*定义显示欢迎函数数组*//*移动光标到指定位置*/
	gotoxy(12, 4); /*将当前字符屏幕的光标位置移动到x,y坐标位置*//*显示欢迎信息*/
	printf("Welcome you to wuziqi word!");
	gotoxy(12, 6);
	printf("1. up, down, left and right key to move , ");
	gotoxy(12, 8);
	printf(" Space key to move!");
	gotoxy(12, 10);
	printf("2. Esc key to exit !");
	gotoxy(12, 12);
	printf("3. Don not move the pieces out of the chessboard !");
	gotoxy(12, 14);
	printf(" continue ?(Y/N) ");
	ch = getchar(); /*从标准输入流读取一个字符并回显，读到回车符时退出*/
	/*判断程序是否要继续进行，按n表示退出，y表示继续玩游戏*/
	if (ch == ' n' || ch == ' N')/*如果不继续进行，则推出程序*/
		exit(0); /*程序中止执行， 返回调用过程*/
}/*画棋盘函数，用来画棋盘的格子和棋子，这里棋子用带某一颜色的圆圈表示*/
void DrawBoard()
{
	int x1, x2;
	int y1, y2;/*设置背景色*/
	setbkcolor(2);/*设置线条颜色*/
	setcolor(14); /*设置前景颜色 */
	setlinestyle(DOTTED_LINE, 3, 1); /*设置画线模式, linestyle 画线风格*/
	for (x1 = 1, y1 = 1, y2 = 18; x1 <= 18; x1++) /*line 用于画直线， x1, y1, x2, y2 直线的起点和终点坐标*/
		line((x1 + OFFSET_x) * OFFSET, (y1 + OFFSET_y) * OFFSET, (x1 + OFFSET_x) * OFFSET, (y2 + OFFSET_y) * OFFSET);
	for (x1 = 1, y1 = 1, x2 = 18; y1 <= 18; y1++)
		line((x1 + OFFSET_x) * OFFSET, (y1 + OFFSET_y) * OFFSET, (x2 + OFFSET_x) * OFFSET, (y1 + OFFSET_y) * OFFSET);/*将各个点的状态设置为 0*/
	for (x1 = 1; x1 <= 18; x1++)
		for (y1 = 1; y1 <= 18; y1++)
			status[x1][y1] = 0;/*显示帮助信息*/
	setcolor(150);/*设置字体、 大小*/
	settextstyle(1, 0, 4); /*设置图形模式下字符显示底字体、 方向和大小*/
	
	outtextxy((19 + OFFSET_x) * OFFSET, (2 + OFFSET_y) * OFFSET, "Player key: ");/*图形模式下在 x, y 坐标位置显示一行字符串*/
	setcolor(9);
	settextstyle(3, 0, 1);
	outtextxy((19 + OFFSET_x) * OFFSET, (4 + OFFSET_y) * OFFSET, "UP--up ");
	outtextxy((19 + OFFSET_x) * OFFSET, (6 + OFFSET_y) * OFFSET, "DOWN--down ");
	outtextxy((19 + OFFSET_x) * OFFSET, (8 + OFFSET_y) * OFFSET, "LEFT--left");
	outtextxy((19 + OFFSET_x) * OFFSET, (10 + OFFSET_y) * OFFSET, "RIGHT--right");
	outtextxy((19 + OFFSET_x) * OFFSET, (12 + OFFSET_y) * OFFSET, "ENTER--space");
	setcolor(14);
	settextstyle(1, 0, 1);
	outtextxy((19 + OFFSET_x) * OFFSET, (14 + OFFSET_y) * OFFSET, "Exit: ");
	setcolor(9);
	settextstyle(3, 0, 1);
	outtextxy((19 + OFFSET_x) * OFFSET, (16 + OFFSET_y) * OFFSET, "ESC");
}/*画圆函数，用来表示玩家的棋子*/
void DrawCircle(int x, int y, int color)
{
	setcolor(color);/*设置画圆线条的风格，宽度，这里设置为虚线*/
	setlinestyle(SOLID_LINE, 0, 5);
	x = (x + OFFSET_x) * OFFSET;
	y = (y + OFFSET_y) * OFFSET;/*以(x, y) 为圆心，8为半径画圆*/
	circle(x, y, 8);
}/*交换行棋方函数，即让玩家轮流下棋*/
void Alternation()
{
	if (flag == 1)
		flag = 2; /*如果此时为玩家1落棋，则下回换为玩家2落棋*/
	else
		flag = 1; /*如果此时为玩家2落棋，则下回换为玩家1落棋*/
}/*对不同的行棋方画不同颜色的圆函数，用于区分不同玩家的棋子*/
void JudgePlayer(int x, int y)
{
	if (flag == 1)
		DrawCircle(x, y, 15);
	if (flag == 2)
		DrawCircle(x, y, 4);
}/*判断当前行棋方是否获胜函数， 即判断是否有五个相同颜色的棋子已连成一条线*/
int ResultCheck(int x, int y)
{
	int j, k;
	int n1, n2;
	while (1)
	{
		/*对水平方向进行判断是否有 5 个同色的圆*/
		n1 = 0;
		n2 = 0;/*水平向左数*/
		for (j = x, k = y; j >= 1; j--)
		{
			if (status[j][k] == flag)
				n1++;
			else
				break;
		}/*水平向右数*/
		fr(j = x, k = y; j <= 18; j++)
		{
			if (status[j][k] == flag)
				n2++;
			else
				break;
		}
		if (n1 + n2 - 1 >= 5)
		{
			return(1);
		}/*对垂直方向进行判断是否有 5 个同色的圆*/
		n1 = 0;
		n2 = 0;/*垂直向上数*/
		for (j = x, k = y; k >= 1; k--)
		{
			if (status[j][k] == flag)
				n1++;
			else
				break;
		}/*垂直向下数*/
		for (j = x, k = y; k <= 18; k++)
		{
			if (status[j][k] == flag)
				n2++;
			else
				break;
		}
		if (n1 + n2 - 1 >= 5)
		{
			return(1);
		}/*从左上方到右下方进行判断是否有 5 个同色的圆*/
		n1 = 0;
		n2 = 0;/*向左上方数*/
		for (j = x, k = y; (j >= 1) && (k >= 1); j--, k--)
		{
			if (status[j][k] == flag)
				n1++;
			else
				break;
		}/*向右下方数*/
		for (j = x, k = y; (j <= 18) && (k <= 18); j++, k++)
		{
			if (status[j][k] == flag)
				n2++;
			else
				break;
		}
		if (n1 + n2 - 1 >= 5)
		{
			return(1);
		}/*从右上方到左下方进行判断是否有 5 个同色的圆*/
		n1 = 0;
		n2 = 0;/*向右上方数*/
		for (j = x, k = y; (j <= 18) && (k >= 1); j++, k--)
		{
			if (status[j][k] == flag)
				n1++;
			else
				break;
		}/*向左下方数*/
		for (j = x, k = y; (j >= 1) && (k <= 18); j--, k++)
		{
			if (status[j][k] == flag)
				n2++;
			else
				break;
		}
		if (n1 + n2 - 1 >= 5)
		{
			return(1);
		}
		return(0);
	}
}/*执行下棋函数*/
void Done()
{
	int i;
	int j;/*根据不同的 key 值进行不同的操作*/
	switch (key)
	{
		/*如果是向左移动的*/
	case LEFT:
		/*如果下一步超出棋盘左边界则什么也不作*/
		if (step_x - 1 < 0)
			break;
		else
		{
			for (i = step_x - 1, j = step_y; i >= 1; i--)
				if (status[i][j] == 0)
				{
					DrawCircle(step_x, step_y, 2);
					break;
				}
			if (i < 1)
				break;
			step_x = i;
			JudgePlayer(step_x, step_y);
			break;
		}/*如果是向右移动的*/
	case RIGHT:
		/*如果下一步超出棋盘右边界则什么也不作*/
		if (step_x + 1 > 18)
			break;
		else
		{
			for (i = step_x + 1, j = step_y; i <= 18; i++)
				if (status[i][j] == 0)
				{
					/*每移动一步画一个圆， 显示移动的过程*/
					DrawCircle(step_x, step_y, 2);
					break;
				}
			if (i > 18) break;
			step_x = i;/*根据不同的行棋者画不同颜色的圆*/
			JudgePlayer(step_x, step_y);/*显示行棋一方是谁*/
			break;
		}/*如果是向下移动的*/
	case DOWN:/*如果下一步超出棋盘下边界则什么也不作*/
		if ((step_y + 1) > 18)
			break;
		else
		{
			for (i = step_x, j = step_y + 1; j <= 18; j++)
				if (status[i][j] == 0)
				{
					DrawCircle(step_x, step_y, 2);
					break;
				}
			if (j > 18) break;
			step_y = j;
			JudgePlayer(step_x, step_y);
			break;
		}/*如果是向上移动的*/
	case UP:/*如果下一步超出棋盘上边界则什么也不作*/
		if ((step_y - 1) < 0)
			break;
		else
		{
			for (i = step_x, j = step_y - 1; j >= 1; j--)
				if (status[i][j] == 0)
				{
					DrawCircle(step_x, step_y, 2);
					break;
				}
			if (j < 1) break;
			step_y = j;
			JudgePlayer(step_x, step_y);
			break;
		}/*如果是退出键*/
	case ESC:
		break;/*如果是确定键*/
	case SPACE:/*如果操作是在棋盘之内*/
		if (step_x >= 1 && step_x <= 18 && step_y >= 1 && step_y <= 18)
		{
			/*按下确定键后，如果棋子当前位置的状态为0*/
			if (status[step_x][step_y] == 0)
			{
				/*则更改棋子当前位置的状态在 flag，表示是哪个行棋者行的棋*/
				status[step_x][step_y] = flag;/*如果判断当前行棋者获胜*/
				if (ResultCheck(step_x, step_y) == 1)
				{
					/*以指定频率打开 PC 扬声器*/
					sound(1000);/*扬声器的发生时间，为1秒钟*/
					delay(1000);
					nosound();
					gotoxy(30, 4);
					setbkcolor(BLUE);/*清除图形屏幕*/
					cleardevice(); /*清除屏幕显示，仅用于图形工作方式*//*为图形输出设置当前视口*/
					setviewport(100, 100, 540, 380, 1); /*设置图形模式下形函数操作的窗口大小 */
					setfillstyle(1, 2); /*设置填充模式和填充颜色*/
					setcolor(YELLOW);
					rectangle(0, 0, 439, 279); /*图形方式下， 在屏上画一个矩形*/
					floodfill(50, 50, 14); /*填充一个有边界的区域, x, y 要填充区域内的任意一点坐标*/
					setcolor(12);
					settextstyle(1, 0, 5);/*三重笔划字体,水平放大5倍*/
					outtextxy(20, 20, "Congratulation !");
					setcolor(15);
					settextstyle(3, 0, 4);/*如果是 Player1 获胜，显示获胜信息*/
					if (flag == 1)
					{
						/*无衬笔划字体, 水平放大5倍*/
						outtextxy(20, 120, "Player1 win the game !");
					}/*如果是 Player1 获胜，显示获胜信息*/
					if (flag == 2)
					{
						/*无衬笔划字体,水平放大 5 倍*/
						outtextxy(20, 120, "Player2 win the game !");
					}
					setcolor(14);
					settextstyle(2, 0, 8);
					getch(); /*从控制台读取字符，但不显示在屏幕上*/
					exit(0);
				}/*如果当前行棋者没有获胜，则交换行棋方，接着下棋*/
				Alternation();/*提示行棋方是谁，即显示正在落子的玩家*/
				ShowMessage();
				break;
			}
		}
		else
			break;
	}
}/*显示行棋方函数，用来显示正在落子的玩家*/
void ShowMessage()
{
	/*轮到 Player1 行棋*/
	if (flag == 1)
	{
		setcolor(2);
		settextstyle(1, 0, 1);
		gotoxy(100, 30);/*覆盖原有的字迹*/
		outtextxy(100, 30, "It' s turn to Player2 !");
		setcolor(12);
		settextstyle(1, 0, 1);
		outtextxy(100, 30, "It' s turn to Player1 !");
	}/*轮到 Player2 行棋*/
	if (flag == 2)
	{
		setcolor(2);
		settextstyle(1, 0, 1);/*覆盖原有的字迹*/
		outtextxy(100, 30, "It' s turn to Player1 !");
		setcolor(12);
		settextstyle(1, 0, 1);
		gotoxy(100, 20);
		outtextxy(100, 30, "It' s turn to Player2 !");
	}
}
/*主函数*/
int main()
{
	int gdriver;
	int gmode;
	int errorcode;/*清空文本模式窗口*/
	clrscr(); /*清除当前字符窗口所有字符*/
	/*显示欢迎信息*/
	WelcomeInfo();
	gdriver=DETECT;
	gmode = 0;/*初始化图形系统*/
	initgraph(&gdriver, &gmode, ""); /*初始化图形系统 */
  /*pathtodriver 图形驱动器文件路径，如不修改，图形驱动器文件在 TC 目录下*/
  /*返回最近一次图形操作的结果状态值*/
	if (errorcode != grOk)
	{
		/*根据错误代码输出错误信息串*/
		printf("\nNotice: Error occured when grphicsinitialization: % s\n", grapherrormsg(errorcode) ) ;
			printf("Press any key to quit!");
		getch();
		exit(1);
	}/*设置flag初始值，默认是Player1先行*/
	flag = 1;/*画棋盘*/
	DrawBoard();
	ShowMessage();
	do
	{
		step_x = 0;
		step_y = 0;
		JudgePlayer(step_x - 1, step_y - 1);
		do
		{
			/*如果没有键按下，则 bioskey(1) 函数将返回 0*/
			while (bioskey(1) == 0);/*获取从键盘按下的键值*/
			key = bioskey(0);/*根据获得的键值进行下棋操作*/
			Done();
		} while (key != SPACE && key != ESC);
	} while (key != ESC);/*关闭图形系统*/
	closegraph(); /*关闭图形工作方式*/
	return 0;
}