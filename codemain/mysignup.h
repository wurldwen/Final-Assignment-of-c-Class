#ifndef MYSIGNUP_H
#define MYSIGNUP_H

#include"myenter.h"

class SignupWidget :public Entrance
{
public:
	SignupWidget();
	void Init(vector<Player>& UserArray);
	~SignupWidget();
	bool CheckAccount(Edit* UserName);
	void Show();
	void OnEvent(vector<Player>& UserArray);
	void AddAccount(vector<Player>& UserArray,  Edit*UserName,Edit*UserPIN);
};
#endif // !MYSIGNUP_H

