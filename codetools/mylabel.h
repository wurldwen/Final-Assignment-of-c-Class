//�ı���ʽ���
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
	string text;			//���ֱ���
	COLORREF color;			//��ɫ
	int size;				//��С
	string style;			//������ʽ
};
#endif // !MYFONT_H

