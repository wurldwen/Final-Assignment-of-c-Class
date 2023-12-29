#include"plane_mp.h"
myPlane::myPlane()
{
	myPlane_bullet.resize(100);
	myPlane_smallBullet.resize(200);
	this->x = 230;
	this->y = HEIGHT - 90;
	this->HP = 100;
	this->exist = 1;
	this->speed = 4;
	this->colliattack = 1000;

	for (int i = 0; i < 100; i++)
	{
		myPlane_bullet[i].speed = 8;
		myPlane_bullet[i].attack = 10;
		myPlane_bullet[i].width = 9;
		myPlane_bullet[i].height = 21;
	}

	for (int i = 0; i < 200; i++)
	{
		myPlane_smallBullet[i].speed = 8;
		myPlane_smallBullet[i].attack = 5;
		myPlane_smallBullet[i].width = 5;
		myPlane_smallBullet[i].height = 11;
	}
}

void myPlane::update()
{
	if (GetAsyncKeyState(VK_UP) && y > 5)y -= speed;
	if (GetAsyncKeyState(VK_DOWN) && y < HEIGHT - 50)y += speed;
	if (GetAsyncKeyState(VK_LEFT) && x > 5)x -= speed;
	if (GetAsyncKeyState(VK_RIGHT) && x < WIDTH - 55)x += speed;
}

void myPlane::creatbulls(int a)
{
	static clock_t t1;
	if (clock() - t1 > 200)
	{
		for (int i = 0; i < 100; i++)
		{
			if (myPlane_bullet[i].exist == false)
			{
				myPlane_bullet[i].exist = true;
				myPlane_bullet[i].x = this->x + 26;
				myPlane_bullet[i].y = this->y - 21;
				break;
			}
		}
		for (int i = 0; i < 200; i++)
		{
			if (myPlane_smallBullet[i].exist == false)
			{
				myPlane_smallBullet[i].exist = true;
				myPlane_smallBullet[i].x = x + 18;
				myPlane_smallBullet[i].y = y - 11;
				break;
			}
		}
		for (int i = 0; i < 200; i++)
		{
			if (myPlane_smallBullet[i].exist == false)
			{
				myPlane_smallBullet[i].exist = true;
				myPlane_smallBullet[i].x = x + 37;
				myPlane_smallBullet[i].y = y - 11;
				break;
			}
		}

		t1 = clock();
	}
}

void myPlane::shot()
{
	for (int i = 0; i < 100; i++)
	{
		if (myPlane_bullet[i].exist == true)
			myPlane_bullet[i].y -= myPlane_bullet[i].speed;

		if (myPlane_bullet[i].y <= 0)
			myPlane_bullet[i].exist = false;
	}

	for (int i = 0; i < 200; i++)
	{
		if (myPlane_smallBullet[i].exist == true)
			myPlane_smallBullet[i].y -= myPlane_bullet[i].speed;

		if (myPlane_smallBullet[i].y <= 0)
			myPlane_smallBullet[i].exist = false;
	}
}