#include"birdgame.h"
//静态成员类外初始化需写在cpp中

int birdgame::score = 0;

birdgame::birdgame(int&max)
{
	maxscore = max;

	s = birdsource::getsource();
	s->load();
	pillar.resize(3);
	for(int i=0;i<3;i++)pillar[i].x = W_W + i * M_P;
	bird = new Bird(120,10,20);
	lMaxScore = new Label("最高分");
	lCurScore = new Label("当前分数");
}

void birdgame::drawPillar(Pillar pillar)
{
	//上面柱子
	putimage(pillar.x, pillar.h - P_H, s->down + 0, SRCAND);
	putimage(pillar.x, pillar.h - P_H, s->down + 1, SRCPAINT);
	//下面柱子
	putimage(pillar.x, F_Y - (P_H - pillar.h), P_W, P_H - pillar.h, s->up + 0, 0, 0, SRCAND);
	putimage(pillar.x, F_Y - (P_H - pillar.h), P_W, P_H - pillar.h, s->up + 1, 0, 0, SRCPAINT);
	//显示分数
	std::string smax = "最高分："+std::to_string(maxscore);
	std::string scur = "当前分数"+std::to_string(score);
	lMaxScore->SetTextStyle(18, "宋体", BLACK, smax);
	lCurScore->SetTextStyle(18, "宋体", BLACK,scur);
	lMaxScore->Show(5, 5);
	lCurScore->Show(5, 30);
}

void birdgame::update()
{
	//实现游戏越来越快功能
	static float dx = 0;
		if(dx<15)dx += 0.005;
	//实现小鸟飞过柱子时加分
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
	//更新游戏最高分
	maxscore = maxscore > score ? maxscore : score;
	//更新小鸟位置
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
	//初始化分数，防止失败后返回菜单又重新进入时分数保留
	score = 0;
	hwnd=initgraph(W_W, W_H);
	MoveWindow(hwnd, (screenWidth - W_W) / 2, (screenHeight - W_H) / 2, W_W, W_H, true); 
    BeginBatchDraw();
	//是否碰撞
	bool flag1, flag2;
	while (1)
	{
		draw();
		update();
		for (int i = 0; i < pillar.size(); i++)
		{
			flag1 = collide(bird->getX(), pillar[i].x, bird->getY(), pillar[i].h - P_H - 20, 20, 19, P_W, P_H);
			flag2 = collide(bird->getX(), pillar[i].x, bird->getY(), F_Y - (P_H - pillar[i].h) - 10, 20, 19, P_W, P_H);
			//游戏失败返回选择界面
			if (bird->hitfloor() || flag1 || flag2)
			{
				return;
			}
		}
		Sleep(20);
		FlushBatchDraw();	//显示每一帧
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
//// 绘制图像
//void putimage(
//	int dstX,				// 绘制位置的 x 坐标
//	int dstY,				// 绘制位置的 y 坐标
//	IMAGE* pSrcImg,			// 要绘制的 IMAGE 对象指针
//	DWORD dwRop = SRCCOPY	// 三元光栅操作码
//);
// 
//// 绘制图像(指定宽高和起始位置)
//void putimage(
//	int dstX,				// 绘制位置的 x 坐标
//	int dstY,				// 绘制位置的 y 坐标
//	int dstWidth,			// 绘制的宽度
//	int dstHeight,			// 绘制的高度
//	IMAGE* pSrcImg,			// 要绘制的 IMAGE 对象指针
//	int srcX,				// 绘制内容在 IMAGE 对象中的左上角 x 坐标
//	int srcY,				// 绘制内容在 IMAGE 对象中的左上角 y 坐标
//	DWORD dwRop = SRCCOPY	// 三元光栅操作码
//);