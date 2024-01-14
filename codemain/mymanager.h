//管理员类，具体功能还未实现(功能数目待扩展），不能通过注册成为管理员，管理员登录入口为登录时输入“wurld，wenyang”
#ifndef MYMANAGER_H
#define MYMANAGER_H

#include"myaccount.h"
#include"myplayer.h"

#include"../codetools/myedit.h"
class Manager :public Account
{
public:
	//Manager();
	//~Manager();
	//virtual void chooseui(vector<Player>& UserArray);
	//void SortUsers(int choice, vector<Player>& UserArray);// 对用户依据首字母或分数排序
	//void ManageUser(vector<Player>& UserArray);
	//void SearchUser(vector<Player>& UserArray);//查找与展示相结合（思考如何实现模糊搜索）
	//void DeleteUser(vector<Player>& UserArray);//暂未想好图形化该如何实现
	//void ClearUser(vector<Player>& UserArray);//清空账户
	//void ShowUsers(bool isfind, vector<Player>& UserArray);//根据搜索结果确定输出格式，所有数据都输出，但第一行输出搜索的结果（待优化）
	//void OnEvent(vector<Player>& UserArray);
	public:
	Manager(vector<Player>& UserArray);
	~Manager();
	virtual void chooseui();
private:
	vector<Player>& UserArray;
	Button* pReturnButton;
	Button* pManageButton;
	Button* sClearButton;
	Button* sDeleteButton;
	Button* sSearchButton;
	Button* sReturnButton;  //查找时的返回按钮
	Button* sSortButton;
	Edit* pSearchEdit;
	void SortUsers(int choice);// 对用户依据首字母或分数排序
	void ManageUser();
	void SearchUser();//查找与展示相结合（思考如何实现模糊搜索）
	void DeleteUser();//暂未想好图形化该如何实现
	void ClearUsers();//清空账户
	void ShowUsers(bool isfind);//根据搜索结果确定输出格式，所有数据都输出，但第一行输出搜索的结果（待优化）
	void OnEvent();
};
#endif // !MYMANAGER_H

