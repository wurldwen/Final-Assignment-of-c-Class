//控制交互功能，鼠标信息
#ifndef MYREACT_H

#include"../codemain/mygamebase.h"
#define EDIT_W 200
#define EDIT_H 25

class Rect
{
public:
	Rect(int x = 0, int y = 0, int w = EDIT_W, int h = EDIT_H, COLORREF = RGB(238, 238, 238));
	const int GetX()const;
	const int GetY()const;
	const int GetW()const;
	const int GetH()const;
	const int GetColor()const;
	const bool InRect(ExMessage msg)const;
	void SetColor(COLORREF color);
	void SetX(int x);
	void SetY(int y);
	void SetW(int w);
	void SetH(int h);
	void RestoreColor();		//还原颜色
	void Show();
private:
	int x;
	int y;
	int w;
	int h;
	COLORREF curColor;
	COLORREF oldColor;
};

#define MYREACT_H
#endif // !MYREACT_H

