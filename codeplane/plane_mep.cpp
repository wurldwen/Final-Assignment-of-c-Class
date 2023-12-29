#include"plane_mep.h"
MiddleEnemy::MiddleEnemy()noexcept
{
	middleEnemy_bullet1.resize(20);
	this->exist = 0;
	this->speed = 1;
	this->colliattack = 50;  
	this->HP = 200;
	this->y = -167;
	this->x = 70;
	this->width = 119;
	this->height = 147;

	for (int i = 0; i < 20; i++) {
		middleEnemy_bullet1[i].speed = 3;
		middleEnemy_bullet1[i].x = x;
		middleEnemy_bullet1[i].y = y;
		middleEnemy_bullet1[i].attack = 40; 
	}
}

void MiddleEnemy::init(int a)
{
	y = -167 + a * 20;
}

void MiddleEnemy::update()
{
	this->y += speed;
	if (y >= HEIGHT||this->HP<0)
	{
		exist = 0;
	}
}

void MiddleEnemy::creatbulls(int a)
{
	for (int j = 0; j < 20; j++)
	{
		if (middleEnemy_bullet1[j].exist == false)
		{
			middleEnemy_bullet1[j].exist = true;
			middleEnemy_bullet1[j].x = x + 10 + a;
			middleEnemy_bullet1[j].y = y + 126 - a;
			break;
		}
	}

	for (int j = 0; j < 20; j++)
	{
		if (middleEnemy_bullet1[j].exist == false)
		{
			middleEnemy_bullet1[j].exist = true;
			middleEnemy_bullet1[j].x = x + 95 - a;
			middleEnemy_bullet1[j].y = y + 126 - a;
			break;
		}
	}
	
}

void MiddleEnemy::shot()
{
	for (int i = 0; i < 20; i++)
	{
		if (middleEnemy_bullet1[i].exist == true)
			middleEnemy_bullet1[i].y += middleEnemy_bullet1[i].speed;

		if (middleEnemy_bullet1[i].y >= HEIGHT)
			middleEnemy_bullet1[i].exist = false;
	}
}