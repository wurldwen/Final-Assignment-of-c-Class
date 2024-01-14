#include"mymanager.h"
Manager::Manager(vector<Player>& UserArray):UserArray(UserArray)
{
	this->pManageButton = new Button(100, 100, 300, 50,RGB(106, 213, 245), "管理员工");
	this->pReturnButton = new Button(100, 200, 300, 50, RGB(106, 213, 245), "返回");
}

void Manager::ManageUser()
{
	this->sReturnButton = new Button(5, 5, 50, 25, RGB(106, 213, 245), "返回");
	this->sSortButton = new Button(100, 5, 50, 25, RGB(106, 213, 245), "排序");
	this->sClearButton = new Button(200, 5, 100, 25, RGB(106, 213, 245), "清空账户");
	this->sDeleteButton = new Button(200, 600, 120, 25, RGB(106, 213, 245), "删除此账户");
    this->pSearchEdit = new Edit(200, 35, 200, 25, RGB(204, 213, 240));
	this->sSearchButton = new Button(400, 35, 50, 25, RGB(106, 213, 245), "搜索");

	HWND se = initgraph(800, 800);
	MoveWindow(hwnd, (screenWidth - 800) / 2, (screenHeight - 800) / 2, 800, 800, true);
	setbkcolor(RGB(204, 213, 240));
	cleardevice();
	OnEvent();

	delete sClearButton;
	delete sDeleteButton;
	delete sSearchButton;
	delete sReturnButton;  //查找时的返回按钮
	delete sSortButton;
	delete pSearchEdit;
}

void Manager::DeleteUser()
{
	for (int i=0;i<UserArray.size();i++)
	{
		if (UserArray[i].Name == pSearchEdit->GetText())
		{
			for (int j = i; j < UserArray.size() - 1; j++)
			{
				UserArray[j] = UserArray[j + 1];
			}
			UserArray.pop_back();
		}
	}

	ofstream ofs(FILENAME, ios::out);
	if(!ofs)
	{
		cerr << "Error opening file for reading!" << endl;
		return;
	}
	//for(vector<Player>::iterator it;it=UserArray.begin(),it!=UserArray.end();it++)
	for(auto&r:UserArray)
	{ 
		ofs << r.Name << ' ' << r.PIN << ' ' << r.birdscore << ' ' << r.planelevel << endl;
	}
	ofs.close();
}

void Manager::SearchUser()
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

	if (!isfind)
	{
		MessageBox(hwnd, "搜索结果不存在", "提示", MB_OK);
		ShowUsers(isfind);
	}
}

void Manager::ClearUser()
{
	UserArray.resize(0);
	ofstream ofs(FILENAME, ios::trunc);
	if (!ofs) {
		cerr << "Error opening file for reading!" << endl;
		return;
	}
	ofs.close();
	ShowUsers(false);

}

void Manager::SortUsers(int choice)
{
	switch(choice)
	{
	case 1:
	{

		ShowUsers(false);
	}
		break;
	}
}

void Manager::OnEvent()
{
	BeginBatchDraw();
	ExMessage msg;
	while (true)
	{
		while (peekmessage(&msg))
		{
			pSearchEdit->OnEvent(msg);
			if (sSearchButton->OnClickButton(msg))
			{
				SearchUser();
			}
			if (this->sDeleteButton->OnClickButton(msg))
			{
				this->DeleteUser();
			}
			if (this->sClearButton->OnClickButton(msg))
			{
				this->ClearUser();
			}
			if (this->sSortButton->InButton(msg))
			{
				this->SortUsers(1);
			}
			if (this->sReturnButton->OnClickButton(msg))
			{
				return;
			}
		}
		this->ShowUsers(false);
		sSearchButton->Show();
		pSearchEdit->Show();
		sClearButton->Show();
		sDeleteButton->Show();
		sReturnButton->Show(); 
		sSortButton->Show();
		FlushBatchDraw();
	}
	EndBatchDraw();

}

void Manager::ShowUsers(bool isfind)
{
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	settextstyle(20, 0, "黑体");
	outtextxy(40, 70, "Account");
	outtextxy(200, 70, "birdgame");
	outtextxy(300, 70, "planegame");
	
	if (isfind == true)
	{

	}
	if (isfind == false)
	{
		for (int q = 0; q <UserArray.size(); q++)
		{
			string s= to_string( UserArray[q].birdscore);
			string splane = to_string(UserArray[q].planelevel);
			outtextxy(40, 100 + q * 20, UserArray[q].Name.c_str());
			outtextxy(200, 100 + q * 20,s.c_str());
			outtextxy(300, 100 + q * 20, splane.c_str());
			
		}
	}
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
			if (pManageButton->OnClickButton(msg))
			{
				ManageUser();
				chooseui();
			}

			if (pReturnButton->OnClickButton(msg))
			{
				return;
			}
		}
		pManageButton->Show();
		pReturnButton->Show();
		FlushBatchDraw();
	}
	EndBatchDraw();
}

Manager::~Manager()
{
	delete pReturnButton;
	delete pManageButton;
	closegraph();
}