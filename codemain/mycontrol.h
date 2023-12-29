#ifndef MYCONTROL_H
#define MYCONTROL_H


#include"myloign.h"
#include"mysignup.h"


class Control
{
public:
	Control();
	~Control();
private:
	vector<Player> UserArray;
	Entrance* tenter;
	LoginWidget* tlogin;
	SignupWidget* tsignup;
	Button* pLoginButton;	    //µÇÂ¼µã»÷µÄ°´Å¥
	Button* pSignupButton;
	Button* pExitButton;
	HWND hwnd;
	Entrance*Enter();
};

#endif // !MYCONTROL_H
