#include"planebase.h"
void planebase::modifyX(int x,int dx)
{
	this->x=x+dx;
}

void planebase::modifyY(int dy)
{
	this->y += dy;
}

void planebase::modifyExist()
{
	if (exist)exist = 0;
	else exist = 1;
}