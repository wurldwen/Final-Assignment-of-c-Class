#include"birdpillar.h"
Pillar::Pillar()
{
	h = rand() % 30 * 5 + 100;	//rand() % 101 [0,100]  [100,200]
	x = W_W;
	y = 0;
}

void Pillar::init()
{
	h = rand() % 30 * 5 + 100;	//rand() % 101 [0,100]  [100,200]
	x = W_W;
	y = 0;
}

void Pillar::update(float dx)
{
	x -= 2.0 + dx;
	if (x < (-P_W - M_P))
		init();
}