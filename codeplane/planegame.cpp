#include"planegame.h"

planegame::planegame(int&a)
{
	s = planesource::getsource();
	s->load();
	status = choose;
	chooseLevel = a;

	back1.resize(5);
	back2.resize(5);
	littleEnemy1.resize(lnum);
	middleEnemy1.resize(mnum);
	middleEnemy2.resize(mnum);

	pReturnButton = new Button(5, 5, 100, 50, WHITE, "����");
	preturnbutton = new Button(5, 5, 100, 50, WHITE, "����");
}

void planegame::init()
{
	creatlittle = 1;
	existEnemy = little;
	//ͨ���ı�л�Ѫ���ı�����ؿ��Ѷ�
	for (int j = 1; j <= chooseLevel; j++)
	{
		if (gameLevel == j)
		{
			for (int i = 0; i < lnum; i++)
			{
				littleEnemy1[i].HP = 100 + i * 50;
			}

			for (int i = 0; i < mnum; i++)
			{
				middleEnemy1[i].HP = 200 + i * 50;
				middleEnemy2[i].HP = 300 + i * 50;
			}
		}	
	}
	//��ʼ���л�����
	for (int i = 0; i < lnum; i++)
	{
		littleEnemy1[i].modifyX(18, i * 131);
	}
	for (int i = 0; i < mnum; i++)
	{
		middleEnemy1[i].modifyX(70, i * 257);
		middleEnemy2[i].modifyX(70, i * 261);
	}
}

void planegame::chooseui()
{
	BeginBatchDraw();
	for (int i = 1; i <=6; i++)
		if (chooseLevel == i)
			putimage(0, 0,s->chooselevelimg[i-1]);
	pReturnButton->Show();
	ExMessage m;       
	m = getmessage();
	if (m.message == WM_LBUTTONDOWN)
	{
		if (chooseLevel >= 1)
			if (m.x >= 67 && m.x <= 120 &&
				m.y >= 696 && m.y <= 747)
			{
				status = play;
				gameLevel = 1;
			}
		
		if (chooseLevel >= 2)
			if (m.x >= 278 && m.x <= 332 &&
				m.y >= 604 && m.y <= 655)
			{
				status = play;
				gameLevel = 2;
			}
		
		if (chooseLevel >= 3)
			if (m.x >= 112 && m.x <= 165 &&
				m.y >= 484 && m.y <= 537)
			{
				status = play;
				gameLevel = 3;
			}

		if (chooseLevel >= 4)
			if (m.x >= 349 && m.x <= 400 &&
				m.y >= 391 && m.y <= 444)
			{
				status = play;
				gameLevel = 4;
			}
		
		if (chooseLevel >= 5)
		{
			if (m.x >= 95 && m.x <= 149 &&
				m.y >= 302 && m.y <= 353)
			{
				status = play;
				gameLevel = 5;
			}
			if (m.x >= 330 && m.x <= 382 &&
				m.y >= 182 && m.y <= 233)
			{
				status = play;
				gameLevel = 6;
			}
		}
	}
	
	FlushBatchDraw();
}

void planegame::draw()
{
	//˫����
	BeginBatchDraw();
	//���Ʒ��ؼ�
	preturnbutton->Show();
	//���Ʊ���
	for (int i = 1; i <= 6; i++)
	{
		if (gameLevel == i)
		{
			if (gameLevel >= 5)
			{
				putimage(0, back1[4].y, s->background1[4]);
				putimage(back2[4].x, back2[4].y, s->background2[4]);
			}
			else 
			{
				putimage(0, back1[i - 1].y, s->background1[i - 1]);
				putimage(back2[i - 1].x, back2[i - 1].y, s->background2[i - 1]);
			}	
		}
	}
	//�����Լ��ķɻ�
	if (myPlane->checkExist())
	{
		putimage(myPlane->getX(), myPlane->getY(), s->myplaneimg[0], SRCPAINT);
		putimage(myPlane->getX(), myPlane->getY(), s->myplaneimg[1], SRCAND);
	}
	//�����Լ��ɻ����ӵ�
	for (int i = 0; i < 100; i++)
	{
		if (myPlane->myPlane_bullet[i].exist == true)
		{
			putimage(myPlane->myPlane_bullet[i].x, myPlane->myPlane_bullet[i].y, s->myplanebulls1[0], SRCPAINT);
			putimage(myPlane->myPlane_bullet[i].x, myPlane->myPlane_bullet[i].y, s->myplanebulls1[1], SRCAND);
		}
	}
	
	for (int i = 0; i < 200; i++)
	{
		if (myPlane->myPlane_smallBullet[i].exist == true)
		{
			putimage(myPlane->myPlane_smallBullet[i].x, myPlane->myPlane_smallBullet[i].y, s->myplanebulls2[0], SRCPAINT);
			putimage(myPlane->myPlane_smallBullet[i].x, myPlane->myPlane_smallBullet[i].y, s->myplanebulls2[1], SRCAND);
		}
	}
	//С�л�
	for (int i = 0; i < lnum; i++)
	{
		if (littleEnemy1[i].checkExist())
		{
			putimage(littleEnemy1[i].getX(), littleEnemy1[i].getY(), s->littleenemyimg[0], SRCPAINT);
			putimage(littleEnemy1[i].getX(), littleEnemy1[i].getY(), s->littleenemyimg[1], SRCAND);
			for (int j = 0; j < 20; j++)
			{
				if (littleEnemy1[i].littleEnemy_bullet1[j].exist == 1)
				{
					putimage(littleEnemy1[i].littleEnemy_bullet1[j].x, littleEnemy1[i].littleEnemy_bullet1[j].y, s->lebulls[0], SRCPAINT);
					putimage(littleEnemy1[i].littleEnemy_bullet1[j].x, littleEnemy1[i].littleEnemy_bullet1[j].y, s->lebulls[1], SRCAND);
				}
			}
			
		}
	}
	//�ел�1
	for (int i = 0; i < mnum; i++)
	{
		if (middleEnemy1[i].checkExist())
		{
			putimage(middleEnemy1[i].getX(), middleEnemy1[i].getY(), s->middleenemyimg1[0], SRCPAINT);
			putimage(middleEnemy1[i].getX(), middleEnemy1[i].getY(), s->middleenemyimg1[1], SRCAND);
			for (int j = 0; j < 20; j++)
			{
				if (middleEnemy1[i].middleEnemy_bullet1[j].exist == 1)
				{
					putimage(middleEnemy1[i].middleEnemy_bullet1[j].x, middleEnemy1[i].middleEnemy_bullet1[j].y, s->mebulls[0], SRCPAINT);
					putimage(middleEnemy1[i].middleEnemy_bullet1[j].x, middleEnemy1[i].middleEnemy_bullet1[j].y, s->mebulls[1], SRCAND);
				}
			}
		}
	}
	//�ел�2
	for (int i = 0; i < mnum; i++)
	{
		if (middleEnemy2[i].checkExist())
		{
			putimage(middleEnemy2[i].getX(), middleEnemy2[i].getY(), s->middleenemyimg2[0], SRCPAINT);
			putimage(middleEnemy2[i].getX(), middleEnemy2[i].getY(), s->middleenemyimg2[1], SRCAND);
			for (int j = 0; j < 20; j++)
			{
				if (middleEnemy1[i].middleEnemy_bullet1[j].exist == 1)
				{
					putimage(middleEnemy2[i].middleEnemy_bullet1[j].x, middleEnemy2[i].middleEnemy_bullet1[j].y, s->mebulls[0], SRCPAINT);
					putimage(middleEnemy2[i].middleEnemy_bullet1[j].x, middleEnemy2[i].middleEnemy_bullet1[j].y, s->mebulls[1], SRCAND);
				}
			}
		}
	}
	Sleep(1);
	FlushBatchDraw();
}

void planegame::update()
{
	//���ؼ�����
	ExMessage msg;
	msg= getmessage();
	if (preturnbutton->OnClickButton(msg))
	{
		status = choose;
		return;
	}
	//��ͼ�ƶ�
	for (int i = 1; i <= chooseLevel; i++)
	{
		if (gameLevel == i)
		{
			if (gameLevel >= 5)
			{
				if (back1[4].y >= HEIGHT)
					back1[4].y = -HEIGHT;

				if (back1[4].y < HEIGHT)
					back1[4].y += 2;

				if (back2[4].y >= HEIGHT)
					back2[4].y = -HEIGHT;

				if (back2[4].y < HEIGHT)
					back2[4].y += 2;
			}

			else
			{
				if (back1[i - 1].y >= HEIGHT)
					back1[i - 1].y = -HEIGHT;

				if (back1[i - 1].y < HEIGHT)
					back1[i - 1].y += 2;


				if (back2[i - 1].y >= HEIGHT)
					back2[i - 1].y = -HEIGHT;

				if (back2[i - 1].y < HEIGHT)
					back2[i - 1].y += 2;
			}
		}
	}
	
	//�����л��Լ��ж���Ϸ�Ƿ�ʤ��
	if (creatlittle)
	{
		for (int i = 0; i < lnum; i++)
			createnemy(&littleEnemy1[i]);
		creatlittle = 0;
	}
	static clock_t t;
	if (clock() - t >= 15000)
	{
		t = clock();
		if (existEnemy == little)
			for (int i = 0; i < lnum; i++)
				createnemy(&littleEnemy1[i]);

		if (existEnemy == middle1)
			for (int i = 0; i < mnum; i++)
				createnemy(&middleEnemy1[i]);

		if (existEnemy == middle2)
			for (int i = 0; i < mnum; i++)
				createnemy(&middleEnemy2[i]);
		//ָ��ʱ���ɻ���Ȼ�����Ϊ��Ϸͨ�أ�����ѡ�����
		if (existEnemy == none)
		{
			if (chooseLevel < 5)
				chooseLevel++;
			status = choose;
		}
		//���µл�����	
		if (existEnemy < none - 1)
			existEnemy++;
		static clock_t t2;
		if (clock() - t2 >= none*15000 && existEnemy == none - 1)
		{
			t2 = clock();
			existEnemy++;
		}
	}
	//�Լ��ķɻ�
	if (myPlane->checkExist())
		updateplane(myPlane);
	myPlane->creatbulls(1);
	//���µл�״̬
	for (int i = 0; i < lnum; i++)
		if (littleEnemy1[i].checkExist())
			updateplane(&littleEnemy1[i]);

	for (int i = 0; i < mnum; i++)
		if (middleEnemy1[i].checkExist())
			updateplane(&middleEnemy1[i]);

	for (int i = 0; i < mnum; i++)
		if (middleEnemy2[i].checkExist())
			updateplane(&middleEnemy2[i]);
	//�л������ӵ�		
	static clock_t t3;
	if (clock() -t3>= 450)
	{
		for (int i = 0; i < lnum; i++)
			if (littleEnemy1[i].checkExist())
				littleEnemy1[i].creatbulls(0);

		for (int i = 0; i < mnum; i++)
			if (middleEnemy1[i].checkExist())
				middleEnemy1[i].creatbulls(0);

		for (int i = 0; i < mnum; i++)
			if (middleEnemy2[i].checkExist())
				middleEnemy2[i].creatbulls(20);

		t3= clock();
	}	
	//��ײ��Ѫ
	//�Լ��ɻ�С�ӵ���л�
	for (int i = 0; i < lnum; i++)
	b_collided_p(myPlane->myPlane_smallBullet,&littleEnemy1[i], 200);
	for (int i = 0; i < mnum; i++)
	{
		b_collided_p(myPlane->myPlane_smallBullet, &middleEnemy1[i], 200);
		b_collided_p(myPlane->myPlane_smallBullet, &middleEnemy2[i], 200);
	}
	//�Լ��ɻ����ֵ���л�
	for (int i = 0; i < lnum; i++)
	b_collided_p(myPlane->myPlane_bullet, &littleEnemy1[i], 100);
	for (int i = 0; i < mnum; i++)
	{
		b_collided_p(myPlane->myPlane_bullet, &middleEnemy1[i], 100);
		b_collided_p(myPlane->myPlane_bullet, &middleEnemy2[i], 100);
	}
	//�л��ӵ����Լ��ɻ�
	for (int i = 0; i < lnum; i++)
		b_collided_p(littleEnemy1[i].littleEnemy_bullet1, myPlane, 20);
	for (int i = 0; i < mnum; i++)
	{
		b_collided_p(middleEnemy1[i].middleEnemy_bullet1, myPlane, 20);
		b_collided_p(middleEnemy2[i].middleEnemy_bullet1, myPlane, 20);
	}
	//�л����Լ��ɻ�
	for (int i = 0; i < lnum; i++)
		p_collided_p(&littleEnemy1[i], myPlane);
	for (int i = 0; i < mnum; i++)
	{
		p_collided_p(&middleEnemy1[i], myPlane);
		p_collided_p(&middleEnemy2[i], myPlane);
	}
	//�ж���Ϸʧ��,����ѡ�����
	if (myPlane->HP <= 0)
	{
		status = choose;
	}
}

void planegame::playing()
{
	hwnd=initgraph(WIDTH, HEIGHT);
	MoveWindow(hwnd, (screenWidth - WIDTH) / 2, (screenHeight -  HEIGHT) / 2, WIDTH, HEIGHT, true);
	while (1)
	{
		while (status == play)
		{
			init();
			while (status == play)
			{
				draw();
			    update();
			}
		}
		
		while (status == choose)
		{
			chooseui();
			ExMessage m;
			m = getmessage();
			if (pReturnButton->OnClickButton(m))
			{
				return;
			}
			
		}
	}
	
}

void planegame::createnemy(planebase*p)
{
	p->init(0);
	if (!p->checkExist())
		p->modifyExist();		
}

void planegame::updateplane(planebase*p)
{
	p->update();
	p->shot();
}

void planegame::b_collided_p(std::vector<planebullet>&b, planebase* p, int bnum)
{
	bool collision;
	int x1, y1, x2, y2;
	if (p->checkExist())
	{
		for (int i = 0; i < bnum; i++)
		{
			if (b[i].exist)
			{
				x1 = b[i].x;
				y1 = b[i].y;
				x2 = p->getX();
				y2 = p->getY();
				collision = collide(x1, x2, y1, y2, b[i].width, b[i].height,p->getW(),p->getH());
				if (collision)
				{
					b[i].exist = false;
					p->HP -= b[i].attack;
				}
			}
		}
	}
}

void planegame::p_collided_p(planebase* e, planebase* p)//�ɻ���ɻ�����ײ
{
	bool collision;
	int x1, y1, x2, y2;
	if (p->checkExist() && e->checkExist())
	{
		x1 = e->getX();
		y1 = e->getY();
		x2 = p->getX();
		y2 = p->getY();
		/* bool collide(int x1, int x2, int y1, int y2,int w1,int h1,int w2,int h2 )const{
		return x1 + w1 > x2 && x1<x2+w2 && y1 + h1>y2 && y1 < y2 + h2;}*/
		collision = collide(x1, x2, y1, y2, e->getW(),  e->getH(),p->getW(),p->getH());//getW()��getH()����ͼƬ��Ⱥ͸߶�
		if (collision)
		{
			e->HP-=p->getA();//getA()���طɻ�ײ�����ʹ��ײ�ɻ���ȥ��Ѫ��
			p->HP -=e->getA();
		}
	}
	//��update�����е���
	// for (int i = 0; i < lnum; i++)
	//p_collided_p(&littleEnemy1[i], myPlane);
}

planegame::~planegame()
{
	mD<class myPlane>d;
	d.mydelete(myPlane);
	delete pReturnButton;
	closegraph();
}
//draw(int n,Bullet*b,IMAGE**a){
	// for (int i = 0; i < n; i++){
	// if(b[i].exist){
	// putimage(b[i].x,b[i].y,a[0],SRCPAINT);
	// putimage(b[i].x,b[i].y,a[1],SRCAND);
	//}
	// draw(int n,planebase*p,IMAGE**a){
	// for (int i = 0; i < n; i++){
	// if(b[i].checkExist()){
	// putimage(p[i].getX(),p[i].getY(),a[0],SRCPAINT);
	// putimage(p.[i].getX(),p.getY(),a[1],SRCAND);
	//}
	//���ã�draw(100,myPlane->myPlane_bullet,s->myplanebulls1)



