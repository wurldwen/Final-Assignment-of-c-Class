//飞机游戏中敌机类
#ifndef PLANE_MIDDLEENEMY_H
#define PLANE_MIDDLEENEMY_H

#include"planebase.h"

class MiddleEnemy :public planebase
{
public:
	std::vector<planebullet>middleEnemy_bullet1;
	MiddleEnemy()noexcept;
	virtual void init(int a);
	virtual void update();
	virtual void creatbulls(int a);
	virtual void shot();
};

#endif // !PLANE_MIDDLEENEMY_H

