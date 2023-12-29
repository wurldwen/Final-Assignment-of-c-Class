//·ÉÏèµÄÐ¡ÄñÓÎÏ·
#ifndef BIRDGAME_H
#define BIRDGAME_H

#include"bird.h"
#include"birdpillar.h"
#include"birdsource.h"
#include"../codetools/mylabel.h"

class birdgame :public game
{
public:
	birdgame(int&max);
	const int getScore()const { return score; }
	virtual void playing();
	~birdgame();
private:
	birdsource* s;
	Bird* bird;
	
	Label* lMaxScore;
	Label* lCurScore;
	std::vector<Pillar>pillar;
	void draw();
	void update();
	void drawPillar(Pillar pillar);
	static int score;
};

#endif // !BIRDGAME_H
