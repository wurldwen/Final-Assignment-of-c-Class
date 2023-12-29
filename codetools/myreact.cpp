#include"myreact.h"
Rect::Rect(int x, int y, int w, int h, COLORREF color)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->curColor = color;
    this->oldColor = color;
}

const int Rect::GetX()const
{
    return x;
}

const int Rect::GetY()const
{
    return y;
}

const int Rect::GetW()const
{
    return w;
}

const int Rect::GetH()const
{
    return h;
}

const int Rect::GetColor()const
{
    return curColor;
}

const bool Rect::InRect(ExMessage msg)const
{
    return (msg.x >= x && msg.x <= x + w && msg.y >= y && msg.y <= y + h) ;
}

void Rect::SetColor(COLORREF color)
{
    this->curColor = color;
}

void Rect::SetX(int x)
{
    this->x = x;
}

void Rect::SetY(int y)
{
    this->y = y;
}

void Rect::SetW(int w)
{
    this->w = w;
}

void Rect::SetH(int h)
{
    this->h = h;
}

void Rect::RestoreColor()
{
    this->curColor = oldColor;
}

void Rect::Show()
{
    setfillcolor(this->curColor);
    setlinecolor(BLACK);
    fillrectangle(x, y, x + w, y + h);
}


