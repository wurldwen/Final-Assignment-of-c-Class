/*************************************************
		头文件		:工具箱
		#include	:包含
		stdio.h		:C语言标准头文件
		graphics.h	:图形库头文件
		conio.h		:按键处理
		time.h		:随机函数
		mmsystem.h  :多媒体库
**************************************************/
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <time.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
/*************************************************
					数据设计
**************************************************/
IMAGE background;
IMAGE bigBird[2];		//bigBird[0]  bigBird[1];
IMAGE endImg[2];
IMAGE down[2];
IMAGE up[2];
HWND hwnd;
//C语言结构体
struct bird
{
	int x;				//鸟的x和y坐标
	int y;
	int speed;			//鸟的速度
};
struct bird myBird = { 120, 10, 100 };
//加载资源：把图片和变量绑定一起
void loadResource()
{
	loadimage(&background, "background.bmp");
	loadimage(&bigBird[0], "birdy.bmp",48,48);
	loadimage(&bigBird[1], "bird.bmp",48,48); 
	loadimage(&endImg[0], "endy.bmp");
	loadimage(&endImg[1], "end.bmp");

	loadimage(&down[0], "downy.bmp");
	loadimage(&down[1], "down.bmp");

	loadimage(&up[0], "upy.bmp");
	loadimage(&up[1], "up.bmp");
}
/**************************************************
					鸟的模块
		1.绘制鸟的过程
		2.按键操作控制鸟的过程
		3.音乐部分---多线程
***************************************************/
//绘制鸟的过程
void drawBigBird(int x, int y)
{
	putimage(x, y, &bigBird[0], SRCAND);
	putimage(x, y, &bigBird[1], SRCPAINT);
}
//线程处理函数--->C语言中函数指针
DWORD WINAPI playMusic(LPVOID pVoid)
{
	mciSendString("open jump.mp3", 0, 0, 0);
	mciSendString("play jump.mp3 wait", 0, 0, 0);
	mciSendString("close jump.mp3", 0, 0, 0);
	return 0;
}
/****************************************************
		通用性技术:
				1.并发编程
				2.网络编程
				3.数据库编程
*****************************************************/
//按键交互
void  keyDown()
{
	char userKey = '\0';
	userKey = _getch();
	//暂停功能
	if (userKey == ' ')
	{
		while (_getch() != ' ');
	}
	switch (userKey)
	{
	case 72:	//小键盘
		myBird.y -= myBird.speed;
		CreateThread(NULL, NULL, playMusic, NULL, NULL, NULL);
		break;
	default:	//其他按键
		break;
	}
}
//碰地板和上边界处理
int hitFloor()
{
	if (myBird.y <= 0 || myBird.y >= (512 - 48))
		return 1;
	return 0;
}
//结束动画
void gameOverAction()
{
	int x = 60;
	int y = 608;
	while (y >= 240)
	{
		putimage(0, 0, &background); 
		putimage(x, y, &endImg[0], SRCAND);
		putimage(x, y, &endImg[1], SRCPAINT);
		y -= 50;
		Sleep(50);
	}
	MessageBox(hwnd, "GameOver!You die!!","over", MB_OK);
}
/******************************************************
					柱子部分
			1.画柱子
			2.初始化柱子
			3.移动柱子
******************************************************/
struct pillar
{
	//上面柱子的属性
	int x;
	int y;
	int h;	
	//能够推出下面柱子的属性:
	//Height-h;
};
struct pillar 柱子[3];
//初始化做完
void initPillar(struct pillar 柱子[], int i)
{
	柱子[i].h = rand() % 100 + 160;
	柱子[i].y = 0;
	柱子[i].x = 288;
}
void drawPillar(struct pillar 柱子)
{
	//上面的柱子
	putimage(柱子.x, 0, 52, 柱子.h, &down[0], 0, 320 - 柱子.h, SRCAND);
	putimage(柱子.x, 0, 52, 柱子.h, &down[1], 0, 320 - 柱子.h, SRCPAINT);

	//下面的柱子
	putimage(柱子.x, 512-(320-柱子.h), 52, 320-柱子.h, &up[0], 0, 0, SRCAND);
	putimage(柱子.x, 512 - (320 - 柱子.h), 52, 320 - 柱子.h, &up[1], 0, 0, SRCPAINT);
}

//通用性+重用性
/*************************************************
					入口函数
**************************************************/
int main()
{
	srand((unsigned int)time(NULL));
	loadResource();
	//1.创建窗口
	hwnd=initgraph(288, 608);
	//描述自由落体
	for (int i = 0; i < 3; i++)
	{
		initPillar(柱子, i);
		柱子[i].x = 288 + i * 150;
	}
	BeginBatchDraw();
	while (1)
	{
		putimage(0, 0, &background);
		drawBigBird(myBird.x, myBird.y);
		for (int i = 0; i < 3; i++)
		{
			柱子[i].x -= 10;
			if (柱子[i].x < (-52 - 150))
			{
				initPillar(柱子, i);
			}
		}
		for (int i = 0; i < 3; i++)
		{
			drawPillar(柱子[i]);
		}
		if (hitFloor())
		{
			gameOverAction();
			break;
		}
		myBird.y += 10;
		//只有有按键才处理，没有按键不能处理
		//kbhit():存在按键返回非零值
		if (_kbhit())
		{
			keyDown();
		}
		Sleep(50);		//延时函数
		FlushBatchDraw();
	}
	EndBatchDraw();
	_getch();			//等待用户按键
	//2.关闭窗口
	closegraph();
	return 0;
}

/*
	1.喜欢上课方式--->尊重老师
	2.坚持学习,直播课程 在腾讯课堂 6个月，没有 6个积累是学不会
	3.主动咨询问题, 高清录播+课堂笔记+代码  课后提供一对一解答
	4.完成作业！
	之所以学不会:不系统  不坚持  不练习
			边学边玩


*/