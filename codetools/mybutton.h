//°´Å¥×é¼þ
#ifndef MYBUTTON_H
#define MYBUTTON_H
#include"../codemain/mygamebase.h"
class Button
{
public:
	void Show();
	Button(int xx, int yy, int ww, int hh, COLORREF color, std::string text);
	bool InButton(ExMessage message);
	bool OnClickButton(ExMessage message);
private:
	int x;
	int y;
	int w;
	int h;
	COLORREF curColor;
	COLORREF oldColor;
	std::string str;
};
#endif // !MYBUTTON_H
