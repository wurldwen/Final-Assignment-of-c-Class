#include"myloign.h"

LoginWidget::LoginWidget()
{
	pUserNameEdit = new Edit(200, 100, 200, 30, RGB(204, 213, 240));				//输入用户名
	pPasswordEdit = new Edit(200, 150, 200, 30, RGB(204, 213, 240));				//输入密码
	pPasswordEdit->SetEditType(Edit::PsdEdit);									//设置当前编辑框为不可见
	pUserNameLabel = new Label("用户名:");										//用户名标签
	pPasswordLabel = new Label("密  码:");										//密码标签
	pEntranceButton = new Button(180, 230, 150, 35, RGB(106, 213, 245), "登录");					//登录		
}

void LoginWidget::Init(vector<Player>& UserArray)
{
	pUserNameEdit->RenewText();
	pPasswordEdit->RenewText();
	hwnd = initgraph(ENTERW, ENTERH);
	MoveWindow(hwnd, (screenWidth - ENTERW) / 2, (screenHeight - ENTERH) / 2, ENTERW, ENTERH, true);
	setbkcolor(RGB(158, 211, 206));
	cleardevice();																		//登录点击的按钮
	OnEvent(UserArray);
}

LoginWidget::~LoginWidget()
{
	delete pUserNameEdit;
	delete pPasswordEdit;
	delete pPasswordLabel;
	delete pUserNameLabel;
	delete pEntranceButton;
	closegraph();
}

void LoginWidget::Show()
{
	pUserNameLabel->Show(100, 100);
	pUserNameEdit->Show();
	pPasswordLabel->Show(100, 150);
	pPasswordEdit->Show();
	pEntranceButton->Show();
}

void LoginWidget::OnEvent(vector<Player>& UserArray)
{
	BeginBatchDraw();
	ExMessage msg;
	while (true)
	{
		while (peekmessage(&msg))
		{
			pUserNameEdit->OnEvent(msg);
			pPasswordEdit->OnEvent(msg);
			if (pEntranceButton->OnClickButton(msg))
			{
				if (CheckAccount(pUserNameEdit, pPasswordEdit))
				{
					MessageBox(hwnd, "登录成功", "提示", MB_OK);
					for (vector<Player>::iterator it = UserArray.begin(); it != UserArray.end(); it++)
					{
						if (it->Name == pUserNameEdit->GetText() && it->PIN == pPasswordEdit->GetText())
							it->chooseui();
					}
					return;
				}
				//管理员登录入口
				else if (pUserNameEdit->GetText() == "wurld" && pPasswordEdit->GetText() == "wenyang")
				{
					manager.chooseui(UserArray);
					return;
				}
				else
				{
					MessageBox(hwnd, "账号或密码错误,登录失败", "提示", MB_OK);
				}
			}
		}
		Show();
		FlushBatchDraw();
	}
	EndBatchDraw();
}

bool LoginWidget::CheckAccount(Edit* UserName, Edit* UserPIN)
{
	ifstream ifs(FILENAME, ios::in);
	if (!ifs)
	{
		cerr << "Error opening file for reading!" << endl;
		return false;
	}
	string name;
	string PIN;
	while (ifs >> name && ifs >> PIN)
	{
		if (name == UserName->GetText() && PIN == UserPIN->GetText())return true;
	}
	ifs.close();
	return false;
}