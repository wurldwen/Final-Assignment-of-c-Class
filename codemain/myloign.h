//µÇÂ¼¹¦ÄÜ
#ifndef MYLOGIN_H
#define MYLOGIN_H

#include"myenter.h"

class LoginWidget:public Entrance
{
public:
	LoginWidget(vector<Player>& UserArray);
	void Init();
	~LoginWidget();
	
private:
	vector<Player>& UserArray;
	Manager manager;
	void Show();
	void OnEvent();
    bool CheckAccount( Edit* UserName, Edit* UserPIN);
};

#endif // !MYLOGIN_H

