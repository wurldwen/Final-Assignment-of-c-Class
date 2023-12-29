#include"myedit.h"
Edit::Edit(int x, int y, int w, int h, COLORREF color) :rect(x, y, w, h, color), cursor(x, y, 1, h - 4, color)
{
    this->inputState = false;
    this->textw = 0;
    this->type = TextEdit;
}

void Edit::Show()
{
    rect.Show();        //����
    //��������
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    settextstyle(20, 0, "����");
    textw = textwidth(text.c_str());
    int texth = textheight(text.c_str());
    int y = (rect.GetH() - texth) / 2;
    //��ô��ʾ
    if (type == TextEdit)
    {
        outtextxy(rect.GetX() + 10, rect.GetY() + y, text.c_str());
    }
    if (type == PsdEdit)
    {
        //��������
        std::string str;
        for (int i = 0; i < text.size(); i++)
        {
           // str += "��";
            str += "*";
        }
        textw = textwidth(str.c_str());
        outtextxy(rect.GetX() + 10, rect.GetY() + y, str.c_str());
    }
    //���
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
    case WM_LBUTTONDOWN:            //�����Ϣ
        if (InEdit(msg))
        {
            rect.SetColor(WHITE);
            inputState = true;      //����༭�򣬱༭״̬��Ϊ�ɱ༭״̬
        }
        else
        {
            rect.RestoreColor();    //��ԭ��ɫ
            inputState = false;
        }
        break;
    case WM_CHAR:                   //����������ַ���Ϣ
        if (inputState == true)     //һ���ǿ�����״̬
        {
            switch (msg.ch)
            {
            case '\b':              //ɾ��
                if (!text.empty())
                {
                    text.pop_back();    //�ַ���β��ɾ��
                }
                break;
            case '\r':                  //ȷ������
            case '\n':
                rect.RestoreColor();
                inputState = false;
                break;
            default:                    //�����ַ�
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
