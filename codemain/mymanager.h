//����Ա�࣬���幦�ܻ�δʵ��(������Ŀ����չ��������ͨ��ע���Ϊ����Ա������Ա��¼���Ϊ��¼ʱ���롰wurld��wenyang��
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
	virtual void chooseui(vector<Player>& UserArray);
	void SortUsers(int choice, vector<Player>& UserArray);// ���û���������ĸ���������
	void ManageUser(vector<Player>& UserArray);
	void SearchUser(vector<Player>& UserArray);//������չʾ���ϣ�˼�����ʵ��ģ��������
	void DeleteUser(vector<Player>& UserArray);//��δ���ͼ�λ������ʵ��
	void ClearUser(vector<Player>& UserArray);//����˻�
	void ShowUsers(bool isfind, vector<Player>& UserArray);//�����������ȷ�������ʽ���������ݶ����������һ����������Ľ�������Ż���
	void OnEvent(vector<Player>& UserArray);
private:
	Button* pReturnButton;
	Button* pManageButton;
	Button* sClearButton;
	Button* sDeleteButton;
	Button* sSearchButton;
	Button* sReturnButton;  //����ʱ�ķ��ذ�ť
	Button* sSortButton;
	Edit* pSearchEdit;
};
#endif // !MYMANAGER_H

