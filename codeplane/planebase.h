//�ɻ���Ϸ�зɻ��Ļ��࣬��������ҷɻ���С�л����ел���boss����δʵ�֣�
// �ӵ��ṹ��
#ifndef PLANEBASE_H
#define PLANEBASE_H

#include"planesource.h"

struct planebullet
{
	float x, y;                //�ӵ�����
	float speed;               //�ӵ��ٶ�
	int width;                 //�ӵ���ȣ�Ϊ��ײ�������
	int height;                //�ӵ��߶ȣ�Ϊ��ײ�������
	int attack;                //�ӵ����зɻ���ɻ�Ѫ��������
	bool exist = 0;            //�ӵ��Ƿ����
};

class planebase
{
public:
	int HP;                    //�ɻ�Ѫ��
	int colliattack;           //�ɻ�ײ�����ʹ��ײ�ɻ���ȥ��Ѫ��
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
	int x, y;                  //�ɻ�����
	int speed;                 //�ɻ��ٶ�
	int width;                 //�ɻ���ȣ�Ϊ��ײ�������
	int height;                //�ɻ��߶ȣ�Ϊ��ײ�������
	bool exist;                //�ɻ��Ƿ����
};

#endif // !PLANEBASE_H

