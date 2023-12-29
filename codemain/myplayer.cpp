#include"myplayer.h"
Player::Player()
{
	pPlanegameButton = new Button(100, 50, 300, 50, LIGHTBLUE, "�ɻ���ս");
	pBirdgameButton = new Button(100, 150, 300, 50, LIGHTBLUE, "�����С��");
	pReturnButton = new Button(100, 250, 300, 50, LIGHTBLUE, "����");
	birdscore = 0;
	planelevel = 1;
}

void Player::Show()
{
	pPlanegameButton->Show();
	pBirdgameButton->Show();
	pReturnButton->Show();
}

void Player::chooseui() 
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
			if (pPlanegameButton->OnClickButton(msg))
			{
				g = new planegame(planelevel);
				g->playing();
				planelevel = g->chooseLevel;
				//���·ɻ���Ϸ�ﵽ����߹ؿ�
				chooseui();
			}
			if (pBirdgameButton->OnClickButton(msg))
			{
				g = new birdgame(birdscore);//���·����С����߷�
				g->playing();
				birdscore=g->maxscore;
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