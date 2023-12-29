#include"mylabel.h"
Label::Label(string text)
{
	this->text = text;
	this->color = BLACK;
	this->size = 25;
	this->style = "ºÚÌå";			
}


void Label::SetTextStyle(int size, string style, COLORREF color,string text)
{
	this->size = size;
	this->style = style;
	this->color = color;
	this->text = text;
}

void Label::Show(int x, int y)
{
	settextstyle(size, 0, _T(style.c_str()));
	setbkmode(TRANSPARENT);
	outtextxy(x, y, _T(text.c_str()));
}