//�ɻ���Ϸ
#ifndef PLANEGAME_H
#define PLANEGAME_H

#include"plane_mp.h"
#include"plane_lep.h"
#include"plane_mep.h"
#include"planesource.h"
#include"../codetools/mybutton.h"
//��Ϸ״̬
enum gamestatus { choose, play };
//�л�����
enum enemy{little,middle1,middle2,none};
//��Ϸ����
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
	int chooseLevel;				    //�ɹ�ѡ�����߹ؿ�
	int gameLevel;					    //ѡ���ĸ��ؿ�
	int status;                         //��Ϸ���е�״̬
	int existEnemy;                     //�ִ�л�����
	bool creatlittle;                   //��һ�β���С�л�

	void chooseui();                    //ѡ��ؿ�����
	void init();                        //��ʼ���л�����
	void draw();                        //��Ⱦ
	void update();	                    //������Ϸ״̬
	void createnemy(planebase* P);      //�����л�
	void updateplane(planebase* P);     //ˢ�·ɻ�
	void b_collided_p(std::vector<planebullet>& b, planebase* p, int bnum);
	void p_collided_p(planebase* e, planebase* p);
};
#endif // !PLANEGAME_H
