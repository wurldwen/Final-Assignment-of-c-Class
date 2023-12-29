//飞机游戏小敌机类
#ifndef PLANE_LITTLEENEMY_H
#define PLANE_LITTLEENEMY_H 

#include"planebase.h"

class littleEnemy :public planebase
{
public:
	std::vector<planebullet>littleEnemy_bullet1;
	littleEnemy()noexcept;
	virtual void init(int a);
	virtual void update();
	virtual void creatbulls(int a);
	virtual void shot();
};

#endif // !PLANE_LITTLEENEMY_H

