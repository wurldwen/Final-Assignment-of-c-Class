//�����С����Ϸ�е���Դ��
#ifndef BIRDSOURCE_H
#define BIRDSOURCE_H

#include"../codemain/mygamebase.h"

#define W_W 288//���ڿ��
#define W_H 608//���ڸ߶�
#define P_W 52//�������ӿ��
#define P_H 320//�������Ӹ߶�
#define F_Y 512//�ذ�������
#define M_P 150//����ˮƽ���

class birdsource
{
	birdsource() {};
public:
	static birdsource* m_s;
	static birdsource* getsource();
	void load();
	IMAGE background;			//����ͼ
	IMAGE bigBird[2];			//��
	IMAGE down[2];				//���µ�����
	IMAGE up[2];				//���ϵ�����
	IMAGE end[2];				//��������
	~birdsource();
};


#endif // !BIRDSOURCE_H

