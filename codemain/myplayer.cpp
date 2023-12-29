#include"myplayer.h"
Player::Player()
{
	pPlanegameButton = new Button(100, 50, 300, 50, LIGHTBLUE, "飞机大战");
	pBirdgameButton = new Button(100, 150, 300, 50, LIGHTBLUE, "飞翔的小鸟");
	pReturnButton = new Button(100, 250, 300, 50, LIGHTBLUE, "返回");
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
				//更新飞机游戏达到的最高关卡
				chooseui();
			}
			if (pBirdgameButton->OnClickButton(msg))
			{
				g = new birdgame(birdscore);//更新飞翔的小鸟最高分
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