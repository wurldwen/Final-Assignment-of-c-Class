//ÕÊº“¿‡
#ifndef MYPLAYER_H
#define MYPLAYER_H

#include"myaccount.h"
#include"../codeplane/planegame.h"
#include"../codebird/birdgame.h"

class Player:public Account
{
public:
	Player();
	~Player();
	int birdscore;
	int planelevel;
	virtual void chooseui();
	void Show();
	void OnEvent();
private:
	
	game* g;
	
	Button* pPlanegameButton;	    
	Button* pBirdgameButton;
	Button* pReturnButton;
};

#define MYPLATER_H
#endif // !MYPLAYER_H

