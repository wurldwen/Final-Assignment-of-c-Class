//文本样式组件
#ifndef MYFONT_H
#define MYFONT_H
#include"../codemain/mygamebase.h"
using namespace std;
class Label
{
public:
	Label(string text) ;
	void SetTextStyle(int size, string style, COLORREF color,string text) ;
	void Show(int x, int y) ;
private:
	string text;			//文字本身
	COLORREF color;			//颜色
	int size;				//大小
	string style;			//字体样式
};
#endif // !MYFONT_H

