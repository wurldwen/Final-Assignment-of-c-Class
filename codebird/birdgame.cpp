#include"birdgame.h"
//��̬��Ա�����ʼ����д��cpp��

int birdgame::score = 0;

birdgame::birdgame(int&max)
{
	maxscore = max;

	s = birdsource::getsource();
	s->load();
	pillar.resize(3);
	for(int i=0;i<3;i++)pillar[i].x = W_W + i * M_P;
	bird = new Bird(120,10,20);
	lMaxScore = new Label("��߷�");
	lCurScore = new Label("��ǰ����");
}

void birdgame::drawPillar(Pillar pillar)
{
	//��������
	putimage(pillar.x, pillar.h - P_H, s->down + 0, SRCAND);
	putimage(pillar.x, pillar.h - P_H, s->down + 1, SRCPAINT);
	//��������
	putimage(pillar.x, F_Y - (P_H - pillar.h), P_W, P_H - pillar.h, s->up + 0, 0, 0, SRCAND);
	putimage(pillar.x, F_Y - (P_H - pillar.h), P_W, P_H - pillar.h, s->up + 1, 0, 0, SRCPAINT);
	//��ʾ����
	std::string smax = "��߷֣�"+std::to_string(maxscore);
	std::string scur = "��ǰ����"+std::to_string(score);
	lMaxScore->SetTextStyle(18, "����", BLACK, smax);
	lCurScore->SetTextStyle(18, "����", BLACK,scur);
	lMaxScore->Show(5, 5);
	lCurScore->Show(5, 30);
}

void birdgame::update()
{
	//ʵ����ϷԽ��Խ�칦��
	static float dx = 0;
		if(dx<15)dx += 0.005;
	//ʵ��С��ɹ�����ʱ�ӷ�
		float a = 0;
	for (int i = 0; i < 3; i++)
	{
	     a= static_cast<float>(bird->getX());
		if (pillar[i].x + P_W >a-2-dx&& pillar[i].x + P_W<=a) 
		{
			score += 10;
			//printf("%d",score);
		}
		pillar[i].update(dx);
	}
	//������Ϸ��߷�
	maxscore = maxscore > score ? maxscore : score;
	//����С��λ��
	bird->update();
}

void birdgame::draw()
{
	putimage(0, 0, &s->background);
	for (int i = 0; i < 3; i++)
		drawPillar(pillar[i]);
	putimage(bird->getX(), bird->getY(), s->bigBird + 0, SRCAND);
	putimage(bird->getX(), bird->getY(), s->bigBird + 1, SRCPAINT);
}

void birdgame::playing()
{
	//��ʼ����������ֹʧ�ܺ󷵻ز˵������½���ʱ��������
	score = 0;
	hwnd=initgraph(W_W, W_H);
	MoveWindow(hwnd, (screenWidth - W_W) / 2, (screenHeight - W_H) / 2, W_W, W_H, true); 
    BeginBatchDraw();
	//�Ƿ���ײ
	bool flag1, flag2;
	while (1)
	{
		draw();
		update();
		for (int i = 0; i < pillar.size(); i++)
		{
			flag1 = collide(bird->getX(), pillar[i].x, bird->getY(), pillar[i].h - P_H - 20, 20, 19, P_W, P_H);
			flag2 = collide(bird->getX(), pillar[i].x, bird->getY(), F_Y - (P_H - pillar[i].h) - 10, 20, 19, P_W, P_H);
			//��Ϸʧ�ܷ���ѡ�����
			if (bird->hitfloor() || flag1 || flag2)
			{
				return;
			}
		}
		Sleep(20);
		FlushBatchDraw();	//��ʾÿһ֡
	}
	EndBatchDraw();	
}

birdgame::~birdgame()
{
	delete bird;
	delete lMaxScore;
	delete lCurScore;
	closegraph();
}
//// ����ͼ��
//void putimage(
//	int dstX,				// ����λ�õ� x ����
//	int dstY,				// ����λ�õ� y ����
//	IMAGE* pSrcImg,			// Ҫ���Ƶ� IMAGE ����ָ��
//	DWORD dwRop = SRCCOPY	// ��Ԫ��դ������
//);
// 
//// ����ͼ��(ָ����ߺ���ʼλ��)
//void putimage(
//	int dstX,				// ����λ�õ� x ����
//	int dstY,				// ����λ�õ� y ����
//	int dstWidth,			// ���ƵĿ��
//	int dstHeight,			// ���Ƶĸ߶�
//	IMAGE* pSrcImg,			// Ҫ���Ƶ� IMAGE ����ָ��
//	int srcX,				// ���������� IMAGE �����е����Ͻ� x ����
//	int srcY,				// ���������� IMAGE �����е����Ͻ� y ����
//	DWORD dwRop = SRCCOPY	// ��Ԫ��դ������
//);