//�����С����Ϸ�е�������
#ifndef PILLAR_H
#define PILLAR_H

#include"birdsource.h"

class Pillar
{
public:
	//�������ӵ�����
	float x;			
	int y;
	int h;			//�������ӵ���ʾ�߶�
	                //�������ӵĸ߶ȣ�320-h;
	void init();
	void update(float dx);
	Pillar();
};

#endif // !PILLAR_H

