//游戏账号类，派生出玩家账号以及管理员账号，管理员账号还未实现
#ifndef MYACCOUNT_H
#define MYACCOUNT_H//起初漏了这行，导致增加管理员类后出现重定义问题

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

