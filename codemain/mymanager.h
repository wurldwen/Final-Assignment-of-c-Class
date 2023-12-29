//管理员类，具体功能还未实现(功能数目待扩展），不能通过注册成为管理员，管理员登录入口为登录时输入“wurld，wenyang”
#ifndef MYMANAGER_H
#define MYMANAGER_H

#include"myaccount.h"
#include"myplayer.h"

#include"../codetools/myedit.h"
class Manager :public Account
{
public:
	Manager();
	~Manager();
	virtual void chooseui();
	void SearchUser(vector<Player>& UserArray);//查找与展示相结合（思考如何实现模糊搜索）
	void DeleteUser(vector < Player>& UserArray);//暂未想好图形化该如何实现
	void ShowUsers(bool isfind);//根据搜索结果确定输出格式，所有数据都输出，但第一行输出搜索的结果（待优化）
	void Show();//显示功能按钮
private:
	Button* pReturnButton;
	Button* pShowButton;
	Button* pSearchButton;
	Button* sReturnButton;  //查找时的返回按钮
	Edit* pSearchEdit;
};
#endif // !MYMANAGER_H

