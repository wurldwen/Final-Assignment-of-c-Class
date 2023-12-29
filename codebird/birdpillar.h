//飞翔的小鸟游戏中的柱子类
#ifndef PILLAR_H
#define PILLAR_H

#include"birdsource.h"

class Pillar
{
public:
	//上面柱子的属性
	float x;			
	int y;
	int h;			//上面柱子的显示高度
	                //下面柱子的高度：320-h;
	void init();
	void update(float dx);
	Pillar();
};

#endif // !PILLAR_H

