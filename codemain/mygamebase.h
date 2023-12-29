//游戏基类，派生出飞翔的小鸟游戏，飞机游戏，羊了个羊游戏
#ifndef GAMEBASE_H
#define GAMEBASE_H
#define FILENAME "UserFile.txt"
#define ENTERW 500
#define ENTERH 400

#include"../codetools/mydelete.h"
#include <graphics.h>	
#include <mmsystem.h>
#include <math.h>
#include <ctime>
#include<vector>
#include<iostream>
#include<string>
#include<sstream>
#include"Windows.h"
#pragma comment(lib,"winmm.lib")

const int screenWidth = GetSystemMetrics(SM_CXSCREEN);
const int screenHeight = GetSystemMetrics(SM_CYSCREEN);

class game
{
public:
	HWND hwnd;
	int maxscore;
	int chooseLevel;				    //可供选择的最高关卡
	const bool collide (int x1, int x2, int y1, int y2,int w1,int h1,int w2,int h2 )const
	{
		return x1 + w1 > x2 && x1<x2+w2 && y1 + h1>y2 && y1 < y2 + h2;
	}
	virtual void playing()=0;
	virtual ~game(){}
};

#endif // !GAMEBASE_H