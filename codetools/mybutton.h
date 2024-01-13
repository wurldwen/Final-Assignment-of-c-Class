//按钮组件
#ifndef MYBUTTON_H
#define MYBUTTON_H
#include"../codemain/mygamebase.h"
class Button
{
public:
	void Show();
	Button(int xx, int yy, int ww, int hh, COLORREF color, std::string text);
	bool InButton(ExMessage message);//鼠标悬浮
	bool OnClickButton(ExMessage message);//鼠标按下
private:
	int x;
	int y;
	int w;//按钮宽度
	int h;//按钮高度
	COLORREF curColor;//鼠标未悬浮时的颜色
	COLORREF oldColor;//鼠标悬浮后的颜色
	std::string str;//按钮内部文字
};
#endif // !MYBUTTON_H
