//��Ϸ�˺��࣬����������˺��Լ�����Ա�˺ţ�����Ա�˺Ż�δʵ��
#ifndef MYACCOUNT_H
#define MYACCOUNT_H//���©�����У��������ӹ���Ա�������ض�������

#include<iostream>
using namespace std;

#include"../codetools/mybutton.h"
#include"mygamebase.h"

class Account
{
public:
	HWND hwnd;
	string Name;
	string PIN;
	virtual void chooseui() = 0;
};

#endif // !MYACCOUNT_H

