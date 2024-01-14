//飞机游戏
#ifndef PLANEGAME_H
#define PLANEGAME_H

#include"plane_mp.h"
#include"plane_lep.h"
#include"plane_mep.h"
#include"planesource.h"
#include"../codetools/mybutton.h"
//游戏状态
enum gamestatus { choose, play };
//敌机种类
enum enemy{little,middle1,middle2,none};
//游戏背景
struct Back1
{
	int x = 0, y = 0;
};
struct Back2
{
	int x = 0, y = HEIGHT;
};

class planegame :public game
{
public:
	planegame(int&level);
	virtual void playing();
	virtual int getRecord ()const;
	const int getLevel()const { return chooseLevel; }
	~planegame();
private:
	
	planesource* s;
	myPlane* myPlane = new class myPlane();
	std::vector<Back1>back1;
	std::vector<Back2>back2;
	std::vector<littleEnemy>littleEnemy1;
	std::vector<MiddleEnemy>middleEnemy1;
	std::vector<MiddleEnemy>middleEnemy2;
	
	Button* pReturnButton;
	Button* preturnbutton;
	int chooseLevel;				    //可供选择的最高关卡
	int gameLevel;					    //选择哪个关卡
	int status;                         //游戏进行的状态
	int existEnemy;                     //现存敌机种类
	bool creatlittle;                   //第一次产生小敌机

	void chooseui();                    //选择关卡界面
	void init();                        //初始化敌机坐标
	void draw();                        //渲染
	void update();	                    //更新游戏状态
	void createnemy(planebase* P);      //产生敌机
	void updateplane(planebase* P);     //刷新飞机
	void b_collided_p(std::vector<planebullet>& b, planebase* p, int bnum);
	void p_collided_p(planebase* e, planebase* p);
};
#endif // !PLANEGAME_H
