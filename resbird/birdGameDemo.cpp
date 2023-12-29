/*************************************************
		ͷ�ļ�		:������
		#include	:����
		stdio.h		:C���Ա�׼ͷ�ļ�
		graphics.h	:ͼ�ο�ͷ�ļ�
		conio.h		:��������
		time.h		:�������
		mmsystem.h  :��ý���
**************************************************/
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <time.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
/*************************************************
					�������
**************************************************/
IMAGE background;
IMAGE bigBird[2];		//bigBird[0]  bigBird[1];
IMAGE endImg[2];
IMAGE down[2];
IMAGE up[2];
HWND hwnd;
//C���Խṹ��
struct bird
{
	int x;				//���x��y����
	int y;
	int speed;			//����ٶ�
};
struct bird myBird = { 120, 10, 100 };
//������Դ����ͼƬ�ͱ�����һ��
void loadResource()
{
	loadimage(&background, "background.bmp");
	loadimage(&bigBird[0], "birdy.bmp",48,48);
	loadimage(&bigBird[1], "bird.bmp",48,48); 
	loadimage(&endImg[0], "endy.bmp");
	loadimage(&endImg[1], "end.bmp");

	loadimage(&down[0], "downy.bmp");
	loadimage(&down[1], "down.bmp");

	loadimage(&up[0], "upy.bmp");
	loadimage(&up[1], "up.bmp");
}
/**************************************************
					���ģ��
		1.������Ĺ���
		2.��������������Ĺ���
		3.���ֲ���---���߳�
***************************************************/
//������Ĺ���
void drawBigBird(int x, int y)
{
	putimage(x, y, &bigBird[0], SRCAND);
	putimage(x, y, &bigBird[1], SRCPAINT);
}
//�̴߳�����--->C�����к���ָ��
DWORD WINAPI playMusic(LPVOID pVoid)
{
	mciSendString("open jump.mp3", 0, 0, 0);
	mciSendString("play jump.mp3 wait", 0, 0, 0);
	mciSendString("close jump.mp3", 0, 0, 0);
	return 0;
}
/****************************************************
		ͨ���Լ���:
				1.�������
				2.������
				3.���ݿ���
*****************************************************/
//��������
void  keyDown()
{
	char userKey = '\0';
	userKey = _getch();
	//��ͣ����
	if (userKey == ' ')
	{
		while (_getch() != ' ');
	}
	switch (userKey)
	{
	case 72:	//С����
		myBird.y -= myBird.speed;
		CreateThread(NULL, NULL, playMusic, NULL, NULL, NULL);
		break;
	default:	//��������
		break;
	}
}
//���ذ���ϱ߽紦��
int hitFloor()
{
	if (myBird.y <= 0 || myBird.y >= (512 - 48))
		return 1;
	return 0;
}
//��������
void gameOverAction()
{
	int x = 60;
	int y = 608;
	while (y >= 240)
	{
		putimage(0, 0, &background); 
		putimage(x, y, &endImg[0], SRCAND);
		putimage(x, y, &endImg[1], SRCPAINT);
		y -= 50;
		Sleep(50);
	}
	MessageBox(hwnd, "GameOver!You die!!","over", MB_OK);
}
/******************************************************
					���Ӳ���
			1.������
			2.��ʼ������
			3.�ƶ�����
******************************************************/
struct pillar
{
	//�������ӵ�����
	int x;
	int y;
	int h;	
	//�ܹ��Ƴ��������ӵ�����:
	//Height-h;
};
struct pillar ����[3];
//��ʼ������
void initPillar(struct pillar ����[], int i)
{
	����[i].h = rand() % 100 + 160;
	����[i].y = 0;
	����[i].x = 288;
}
void drawPillar(struct pillar ����)
{
	//���������
	putimage(����.x, 0, 52, ����.h, &down[0], 0, 320 - ����.h, SRCAND);
	putimage(����.x, 0, 52, ����.h, &down[1], 0, 320 - ����.h, SRCPAINT);

	//���������
	putimage(����.x, 512-(320-����.h), 52, 320-����.h, &up[0], 0, 0, SRCAND);
	putimage(����.x, 512 - (320 - ����.h), 52, 320 - ����.h, &up[1], 0, 0, SRCPAINT);
}

//ͨ����+������
/*************************************************
					��ں���
**************************************************/
int main()
{
	srand((unsigned int)time(NULL));
	loadResource();
	//1.��������
	hwnd=initgraph(288, 608);
	//������������
	for (int i = 0; i < 3; i++)
	{
		initPillar(����, i);
		����[i].x = 288 + i * 150;
	}
	BeginBatchDraw();
	while (1)
	{
		putimage(0, 0, &background);
		drawBigBird(myBird.x, myBird.y);
		for (int i = 0; i < 3; i++)
		{
			����[i].x -= 10;
			if (����[i].x < (-52 - 150))
			{
				initPillar(����, i);
			}
		}
		for (int i = 0; i < 3; i++)
		{
			drawPillar(����[i]);
		}
		if (hitFloor())
		{
			gameOverAction();
			break;
		}
		myBird.y += 10;
		//ֻ���а����Ŵ���û�а������ܴ���
		//kbhit():���ڰ������ط���ֵ
		if (_kbhit())
		{
			keyDown();
		}
		Sleep(50);		//��ʱ����
		FlushBatchDraw();
	}
	EndBatchDraw();
	_getch();			//�ȴ��û�����
	//2.�رմ���
	closegraph();
	return 0;
}

/*
	1.ϲ���Ͽη�ʽ--->������ʦ
	2.���ѧϰ,ֱ���γ� ����Ѷ���� 6���£�û�� 6��������ѧ����
	3.������ѯ����, ����¼��+���ñʼ�+����  �κ��ṩһ��һ���
	4.�����ҵ��
	֮����ѧ����:��ϵͳ  �����  ����ϰ
			��ѧ����


*/