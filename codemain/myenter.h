//��¼��ע��Ļ���
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
	Edit* pUserNameEdit;		//�����û���
	Edit* pPasswordEdit;		//��������
	Label* pUserNameLabel;		//�û�����ǩ
	Label* pPasswordLabel;		//�����ǩ
	Button* pEntranceButton;    //�����ť
	HWND hwnd;
public:
	virtual~Entrance() {}
	virtual void Init()=0;
};
#endif // !MYENTER_H
