#ifndef MYSIGNUP_H
#define MYSIGNUP_H

#include"myenter.h"

class SignupWidget :public Entrance
{
public:
	SignupWidget(vector<Player>& UserArray);
	virtual void Init();
	~SignupWidget();
	
private:
	vector<Player>& UserArray;
	bool CheckAccount(Edit* UserName);
	void Show();
	void OnEvent();
	void AddAccount( Edit*UserName,Edit*UserPIN);
};
#endif // !MYSIGNUP_H

