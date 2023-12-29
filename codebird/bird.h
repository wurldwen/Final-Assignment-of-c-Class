//飞翔的小鸟游戏中的小鸟类
#ifndef BIRD_H
#define BIRD_H

#include"birdsource.h"

class Bird
{
public:
	Bird(int a, int b, int c) :x(a), y(b), speed(c) {}
	void update();
	const int getX()const { return x; }
	const int getY()const { return y; }
    bool hitfloor()const;                      //返回小鸟是否撞到地板
private:
	int x;
	int y;
	int speed;
};

#endif
