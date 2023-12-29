//µÇÂ¼¹¦ÄÜ
#ifndef MYLOGIN_H
#define MYLOGIN_H

#include"myenter.h"

class LoginWidget:public Entrance
{
public:
	LoginWidget();
	void Init(vector<Player>& UserArray);
	~LoginWidget();
	void Show();
	void OnEvent(vector<Player>& UserArray);
    bool CheckAccount( Edit* UserName, Edit* UserPIN);
private:
	Manager manager;
};

#endif // !MYLOGIN_H

