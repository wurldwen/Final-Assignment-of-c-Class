//�����С����Ϸ�е�С����
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
    bool hitfloor()const;                      //����С���Ƿ�ײ���ذ�
private:
	int x;
	int y;
	int speed;
};

#endif
