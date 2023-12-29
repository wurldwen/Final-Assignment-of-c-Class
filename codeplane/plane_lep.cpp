#include"plane_lep.h"
littleEnemy::littleEnemy()noexcept
{
	littleEnemy_bullet1.resize(20);

	this->exist = 0;
	this->speed = 1;
	this->colliattack = 30;
	this->HP = 100;
	this->y = -70;
	this->x = 18;
	this->width = 91;
	this->height = 70;

	for (int i = 0; i < 20; i++)
	{
		littleEnemy_bullet1[i].speed = 4;
		littleEnemy_bullet1[i].x = x;
		littleEnemy_bullet1[i].y = y;
		littleEnemy_bullet1[i].attack = 20;
	}
}

void littleEnemy::init(int a)
{
	this->y = -70 - a * HEIGHT / 2;
}

void littleEnemy::update()
{
	this->y += speed;
	if (y >= HEIGHT||this->HP<0)
	{
		exist = 0;
	}
}

void littleEnemy::creatbulls(int a)
{
	for (int j = 0; j < 20; j++)
	{
		if (littleEnemy_bullet1[j].exist == false)
		{
			littleEnemy_bullet1[j].exist = true;
			littleEnemy_bullet1[j].x = this->x + 40;
			littleEnemy_bullet1[j].y = this->y + 70;
			break;
		}
	}
}

void littleEnemy::shot()
{
	for (int i = 0; i < 20; i++)
	{
		if (littleEnemy_bullet1[i].exist == true)
			littleEnemy_bullet1[i].y += littleEnemy_bullet1[i].speed;
		if (littleEnemy_bullet1[i].y >= HEIGHT)
			littleEnemy_bullet1[i].exist = false;
	}
}
