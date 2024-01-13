#include"mycontrol.h"
Control::Control()
{
	UserArray.clear();
	tsignup = new SignupWidget;
	tlogin = new LoginWidget;
	pSignupButton = new Button(100, 50, 300, 50, RGB(106, 213, 245), "×¢²á");
	pLoginButton = new Button(100, 150, 300, 50, RGB(106, 213, 245), "µÇÂ¼");
	pExitButton = new Button(100, 250, 300, 50, RGB(106, 213, 245), "ÍË³ö");

	ifstream ifs(FILENAME, ios::in);

	if (!ifs) {
		cerr << "Error opening file for reading!" << endl;
	}

	Player p;
	while (ifs>>p.Name&&ifs>>p.PIN>>p.birdscore>>p.planelevel)
	{
		UserArray.push_back(p);
	}

	ifs.close();


	while (1)
	{
		tenter = Enter();
		tenter->Init(UserArray);
	}
}

Entrance*Control::Enter()
{
	hwnd = initgraph(ENTERW, ENTERH);
	MoveWindow(hwnd, (screenWidth - ENTERW )/ 2, (screenHeight - ENTERH )/ 2, ENTERW, ENTERH, true);
	setbkcolor(RGB(204, 213, 240));
	cleardevice();

	BeginBatchDraw();
	ExMessage msg;
	while (true)
	{
		while (peekmessage(&msg))
		{
			if (pLoginButton->OnClickButton(msg))
			{
				return tlogin;
			}
			if (pSignupButton->OnClickButton(msg))
			{
				return tsignup;
			}
			if (pExitButton->OnClickButton(msg))
			{
				ofstream ofs(FILENAME, ios::out);
				if (!ofs) {
					cerr << "Error opening file for reading!" << endl;
				}
				for (vector<Player>::iterator it = UserArray.begin(); it != UserArray.end(); it++)
					ofs << it->Name << " " << it->PIN << " " << it->birdscore << " " << it->planelevel << endl;
				ofs.close();
				exit(0);
			}
		}
		pLoginButton->Show();
		pSignupButton->Show();
		pExitButton->Show();
		FlushBatchDraw();
	}
	EndBatchDraw();
}

Control::~Control()
{
	delete tenter;
	delete tlogin;
	delete tsignup;
	delete pLoginButton;	    //µÇÂ¼µã»÷µÄ°´Å¥
	delete pSignupButton;
	delete pExitButton;
	closegraph();
}