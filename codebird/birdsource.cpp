#include"birdsource.h"
birdsource* birdsource::getsource()
{
	if (m_s == NULL)
		m_s = new birdsource;
	return m_s;
}

void birdsource::load()
{
	loadimage(&background, _T("resbird/background.bmp"));
	loadimage(bigBird + 0, _T("resbird/birdy.bmp"), 50, 50);
	loadimage(bigBird + 1, _T("resbird/bird.bmp"), 50, 50);

	loadimage(down + 0, _T("resbird/downy.bmp"));
	loadimage(down + 1, _T("resbird/down.bmp"));

	loadimage(up + 0, _T("resbird/upy.bmp"));
	loadimage(up + 1, _T("resbird/up.bmp"));
}

birdsource* birdsource::m_s = NULL;