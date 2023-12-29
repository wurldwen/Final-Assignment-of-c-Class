//飞机游戏中飞机的基类，派生出玩家飞机，小敌机，中敌机，boss（还未实现）
// 子弹结构体
#ifndef PLANEBASE_H
#define PLANEBASE_H

#include"planesource.h"

struct planebullet
{
	float x, y;                //子弹坐标
	float speed;               //子弹速度
	int width;                 //子弹宽度，为碰撞检测所用
	int height;                //子弹高度，为碰撞检测所用
	int attack;                //子弹击中飞机后飞机血量减少量
	bool exist = 0;            //子弹是否存在
};

class planebase
{
public:
	int HP;                    //飞机血量
	int colliattack;           //飞机撞击后会使被撞飞机减去的血量
	virtual void init(int a) = 0;
	void modifyX(int x,int dx);
	void modifyY(int dy);

	virtual void modifyExist();
	virtual void update() = 0;
	virtual void creatbulls(int a) = 0;
	virtual void shot() = 0;

	const virtual int getX() const { return x; }
	const virtual int getY() const { return y; }
	const virtual bool checkExist() const { return exist; }
	const virtual int getW() const { return width; }
	const virtual int getH() const { return height; }
	const virtual int getA() const { return colliattack; }
protected:
	int x, y;                  //飞机坐标
	int speed;                 //飞机速度
	int width;                 //飞机宽度，为碰撞检测所用
	int height;                //飞机高度，为碰撞检测所用
	bool exist;                //飞机是否存在
};

#endif // !PLANEBASE_H

