//���ƻ�ͼ���
#ifndef MYCRUSOR_H

#include"myreact.h"

class Cursor
{
public:
	Cursor(int x, int y, int w, int h, COLORREF color);
	void Show();
	void SetCurSor(int x, int y);
private:
	void Draw();
	void Clear();
	Rect cursor;
	int count;			//���ƻ���
};
#define MYCRUSOR_H
#endif // !MYCRUSOR_H

