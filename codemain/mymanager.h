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
	virtual void chooseui();
	void SearchUser(vector<Player>& UserArray);//������չʾ���ϣ�˼�����ʵ��ģ��������
	void DeleteUser(vector < Player>& UserArray);//��δ���ͼ�λ������ʵ��
	void ShowUsers(bool isfind);//�����������ȷ�������ʽ���������ݶ����������һ����������Ľ�������Ż���
	void Show();//��ʾ���ܰ�ť
private:
	Button* pReturnButton;
	Button* pShowButton;
	Button* pSearchButton;
	Button* sReturnButton;  //����ʱ�ķ��ذ�ť
	Edit* pSearchEdit;
};
#endif // !MYMANAGER_H

