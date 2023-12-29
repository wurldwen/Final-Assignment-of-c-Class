#include"mycrusor.h"
Cursor::Cursor(int x, int y, int w, int h, COLORREF color) :cursor(x, y, w, h, color)//这里初始化
{
	count = 0;
}

void Cursor::Show()
{
	static  int startTime = 0;
	int endTime = clock();
	if (endTime - startTime >= 20)
	{
		startTime = endTime;
		count++;	//用计数来控制绘制还是擦除
	}
	Draw();
	Clear();
}

void Cursor::Draw()
{
	if (count % 60 < 30)
	{
		setfillcolor(BLACK);
		rectangle(cursor.GetX(), cursor.GetY(),
			cursor.GetX() + cursor.GetW(), cursor.GetY() + cursor.GetH());
	}
}

void Cursor::Clear()
{
	if (count % 60 > 30)
	{
		//setfillcolor(WHITE);
		clearrectangle(cursor.GetX(), cursor.GetY(),
			cursor.GetX() + cursor.GetW(), cursor.GetY() + cursor.GetH());
	}
}

void Cursor::SetCurSor(int x, int y)
{
	cursor.SetX(x);
	cursor.SetY(y);
}