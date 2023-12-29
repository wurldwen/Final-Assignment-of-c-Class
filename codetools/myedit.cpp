#include"myedit.h"
Edit::Edit(int x, int y, int w, int h, COLORREF color) :rect(x, y, w, h, color), cursor(x, y, 1, h - 4, color)
{
    this->inputState = false;
    this->textw = 0;
    this->type = TextEdit;
}

void Edit::Show()
{
    rect.Show();        //矩形
    //处理文字
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    settextstyle(20, 0, "黑体");
    textw = textwidth(text.c_str());
    int texth = textheight(text.c_str());
    int y = (rect.GetH() - texth) / 2;
    //怎么显示
    if (type == TextEdit)
    {
        outtextxy(rect.GetX() + 10, rect.GetY() + y, text.c_str());
    }
    if (type == PsdEdit)
    {
        //密码隐藏
        std::string str;
        for (int i = 0; i < text.size(); i++)
        {
           // str += "●";
            str += "*";
        }
        textw = textwidth(str.c_str());
        outtextxy(rect.GetX() + 10, rect.GetY() + y, str.c_str());
    }
    //光标
    if (inputState == true)
    {
        cursor.SetCurSor(rect.GetX() + textw + 10, rect.GetY() + 2);
        cursor.Show();
    }
}

void Edit::SetEditType(EditType type)
{
    this->type = type;
}

bool Edit::InEdit(ExMessage msg)
{
    return rect.InRect(msg);
}

void Edit::OnEvent(ExMessage msg)
{
    switch (msg.message)
    {
    case WM_LBUTTONDOWN:            //鼠标消息
        if (InEdit(msg))
        {
            rect.SetColor(WHITE);
            inputState = true;      //点击编辑框，编辑状态改为可编辑状态
        }
        else
        {
            rect.RestoreColor();    //还原颜色
            inputState = false;
        }
        break;
    case WM_CHAR:                   //按键输入的字符消息
        if (inputState == true)     //一定是可输入状态
        {
            switch (msg.ch)
            {
            case '\b':              //删除
                if (!text.empty())
                {
                    text.pop_back();    //字符串尾部删除
                }
                break;
            case '\r':                  //确认输入
            case '\n':
                rect.RestoreColor();
                inputState = false;
                break;
            default:                    //其他字符
                text.push_back(msg.ch);
                break;
            }
        }
        break;
    }
}

std::string Edit::GetText()
{
    return text;
}
