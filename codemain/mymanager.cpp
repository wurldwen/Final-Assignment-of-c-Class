#include"mymanager.h"
Manager::Manager()
{
	pShowButton = new Button(100, 100, 300, 50, LIGHTBLUE, "显示员工");
	pReturnButton = new Button(100, 200, 300, 50, LIGHTBLUE, "返回");
    pSearchButton=new Button(100, 5, 80, 25, LIGHTBLUE, "返回");
	pSearchEdit=new Edit(200, 5, 200, 25, RGB(204, 213, 240));
}

void Manager::Show()
{
	pShowButton->Show();
	pReturnButton->Show();
}

void Manager::DeleteUser(vector<Player>&UserArray)
{

}

void Manager::SearchUser(vector<Player>& UserArray)
{
	HWND se= initgraph(ENTERW, ENTERH);
	MoveWindow(hwnd, (screenWidth - ENTERW) / 2, (screenHeight - ENTERH) / 2, ENTERW, ENTERH, true);
	setbkcolor(RGB(204, 213, 240));
	cleardevice();
	BeginBatchDraw();
	ExMessage msg;
	while (true)
	{
		while (peekmessage(&msg))
		{
			pSearchEdit->OnEvent(msg);
			if (pSearchButton->OnClickButton(msg))
			{
				bool isfind = 0;
				for (vector<Player>::iterator it = UserArray.begin(); it != UserArray.end(); it++)
				{
					if (it->Name == pSearchEdit->GetText())
					{
						isfind = 1;
						ShowUsers(isfind);
					}
				}

				if(!isfind)
				{
					MessageBox(hwnd, "搜索结果不存在", "提示", MB_OK);
					ShowUsers(isfind);
				}
			}
		}
		pSearchButton->Show();
		pSearchEdit->Show();
		FlushBatchDraw();
	}
	EndBatchDraw();
}

void Manager::ShowUsers(bool isfind)
{

}

void Manager::chooseui()
{
	hwnd = initgraph(ENTERW, ENTERH);
	MoveWindow(hwnd, (screenWidth - ENTERW) / 2, (screenHeight - ENTERH) / 2, ENTERW, ENTERH, true);
	setbkcolor(RGB(204, 213, 240));
	cleardevice();
	BeginBatchDraw();
	ExMessage msg;
	while (true)
	{
		while (peekmessage(&msg))
		{
			if (pShowButton->OnClickButton(msg))
			{
				ShowUsers(0);
				chooseui();
			}
			if (pReturnButton->OnClickButton(msg))
			{
				return;
			}
		}
		Show();
		FlushBatchDraw();
	}
	EndBatchDraw();
}

Manager::~Manager()
{
	delete pReturnButton;
	delete pShowButton;
	delete pSearchButton;
	delete pSearchEdit;
	closegraph();
}