//飞翔的小鸟游戏中的资源类
#ifndef BIRDSOURCE_H
#define BIRDSOURCE_H

#include"../codemain/mygamebase.h"

#define W_W 288//窗口宽度
#define W_H 608//窗口高度
#define P_W 52//整根柱子宽度
#define P_H 320//整根柱子高度
#define F_Y 512//地板纵坐标
#define M_P 150//柱子水平间距

class birdsource
{
	birdsource() {};
public:
	static birdsource* m_s;
	static birdsource* getsource();
	void load();
	IMAGE background;			//背景图
	IMAGE bigBird[2];			//鸟
	IMAGE down[2];				//朝下的柱子
	IMAGE up[2];				//朝上的柱子
	IMAGE end[2];				//结束动画
	~birdsource();
};


#endif // !BIRDSOURCE_H

