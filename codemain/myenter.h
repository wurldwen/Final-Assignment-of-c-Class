//登录与注册的基类
#ifndef MYENTER_H
#define MYENTER_H

#include "../codetools/myedit.h"
#include "../codetools/mylabel.h"
#include "../codetools/mybutton.h"
#include"mygamebase.h"
#include"myplayer.h"
#include"mymanager.h"


class Entrance
{
protected:
	Edit* pUserNameEdit;		//输入用户名
	Edit* pPasswordEdit;		//输入密码
	Label* pUserNameLabel;		//用户名标签
	Label* pPasswordLabel;		//密码标签
	Button* pEntranceButton;    //点击按钮
	HWND hwnd;
public:
	virtual~Entrance() {}
	virtual void Init()=0;
};
#endif // !MYENTER_H
