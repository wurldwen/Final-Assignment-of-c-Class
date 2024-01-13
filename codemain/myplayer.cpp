#include"myplayer.h"
Player::Player()
{
	birdscore = 0;
	planelevel = 1;
}

Player::~Player()
{
	/*mD<Button>d;
	d.mydelete(pPlanegameButton);
	d.mydelete(pBirdgameButton);
	d.mydelete(pReturnButton);*/
	//自己写的delete函数没有发挥应有的作用
	//适用于vector中多次存取
}

void Player::Show()
{
	pPlanegameButton->Show();
	pBirdgameButton->Show();
	pReturnButton->Show();
}

void Player::OnEvent()
{
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
				delete g;
			}
			if (pBirdgameButton->OnClickButton(msg))
			{
				g = new birdgame(birdscore);//更新飞翔的小鸟最高分
				g->playing();
				birdscore = g->maxscore;
				chooseui();
				delete g;
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

void Player::chooseui() 
{
	pPlanegameButton = new Button(125, 50, 250, 50, RGB(106, 213, 245), "飞机大战");
	pBirdgameButton = new Button(125, 150, 250, 50, RGB(106, 213, 245), "飞翔的小鸟");
	pReturnButton = new Button(150, 250, 200, 50, RGB(106, 213, 245), "返回");
	hwnd = initgraph(ENTERW, ENTERH);
	MoveWindow(hwnd, (screenWidth - ENTERW) / 2, (screenHeight - ENTERH) / 2, ENTERW, ENTERH, true);
	setbkcolor(RGB(204, 213, 240));
	cleardevice();
	OnEvent();
	delete pPlanegameButton;
	delete pBirdgameButton;
	delete pReturnButton;
}