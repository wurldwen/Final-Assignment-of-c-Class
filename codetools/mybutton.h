//��ť���
#ifndef MYBUTTON_H
#define MYBUTTON_H
#include"../codemain/mygamebase.h"
class Button
{
public:
	void Show();
	Button(int xx, int yy, int ww, int hh, COLORREF color, std::string text);
	bool InButton(ExMessage message);//�������
	bool OnClickButton(ExMessage message);//��갴��
private:
	int x;
	int y;
	int w;//��ť���
	int h;//��ť�߶�
	COLORREF curColor;//���δ����ʱ����ɫ
	COLORREF oldColor;//������������ɫ
	std::string str;//��ť�ڲ�����
};
#endif // !MYBUTTON_H
