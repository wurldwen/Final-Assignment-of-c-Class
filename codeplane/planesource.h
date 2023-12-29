//飞机游戏资源类
#ifndef PLANESOURCE_H
#define PLANESOURCE_H

#define WIDTH 520
#define HEIGHT 800
#define lnum 4//小敌机数量
#define mnum 2//中敌机数量

#include"../codemain/mygamebase.h"

class planesource
{
public:
	void load();
	static planesource* m_source;
	static planesource* getsource();

	IMAGE* background1[5];
	IMAGE* background2[5];
	IMAGE* chooselevelimg[5];

	IMAGE* myplaneimg[2];
	IMAGE* littleenemyimg[2];
	IMAGE* middleenemyimg1[2];
	IMAGE* middleenemyimg2[2];
	IMAGE* myplanebulls1[2];
	IMAGE* myplanebulls2[2];
	IMAGE* lebulls[2];
	IMAGE* mebulls[2];

	~planesource();
private:
	planesource() {}
};

#endif // !PLANESOURCE_H

