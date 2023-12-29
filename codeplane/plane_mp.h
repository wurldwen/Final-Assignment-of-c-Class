//飞机游戏中玩家飞机类
#ifndef PLANE_MYPLANE_H
#define PLANE_MYPLANE_H

#include"planebase.h"

class myPlane :public planebase
{
public:
	virtual void init(int a) {}
	std::vector<planebullet> myPlane_smallBullet;
	std::vector<planebullet> myPlane_bullet;
	myPlane();
	virtual void update();
	virtual void creatbulls(int a);
	virtual void shot();
};

#endif // !PLANE_MYPLANE_H

