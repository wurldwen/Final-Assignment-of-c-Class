#include"bird.h"
void Bird::update()
{
	y += 10;
	if (GetAsyncKeyState(VK_UP))y -= speed;
	if (GetAsyncKeyState(VK_DOWN))y += speed;
}

bool Bird::hitfloor()const
{
	if (y <= 0 || y >= F_Y - 50 + 19)
	{
		return 1;
	}
	return 0;
}