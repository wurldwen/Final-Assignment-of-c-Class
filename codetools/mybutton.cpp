#include"mybutton.h"
void Button::Show()
{
    //矩形框
    setfillcolor(curColor);
   fillroundrect(x, y, x + w, y + h,h/3,h/3);//按钮加圆角更加美观
    //文字
    settextstyle(h-10, 0, "FZZJ-XHFTJW.TTF");
    int textw = textwidth(str.c_str());
    int texth = textheight(str.c_str());
    int xx = x + (w - textw) / 2;
    int yy = y + (h - texth) / 2;
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    outtextxy(xx, yy, str.c_str());
}
Button::Button(int xx, int yy, int ww, int hh, COLORREF color, std::string text)
{
    x = xx;
    y = yy;
    w = ww;
    h = hh;
    curColor = color;
    oldColor = color;
    str = text;
}

bool Button::InButton(ExMessage message)
{
    if (message.x >= x && message.x <= x + w && message.y >= y && message.y <= y + h)
    {
        curColor = LIGHTRED;
        return true;
    }
    curColor = oldColor;
    return false;
}

bool Button::OnClickButton(ExMessage m)
{
    if (InButton(m) && m.message == WM_LBUTTONDOWN)
    {
        return true;
    }
    return false;
}
