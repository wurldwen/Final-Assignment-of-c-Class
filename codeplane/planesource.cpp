#include"planesource.h"

planesource* planesource::getsource()
{
	if (m_source == NULL)
		m_source = new planesource;
	return m_source;
}

planesource::~planesource()
{
	mD<IMAGE>d;
	for (int i = 0; i < 2; i++)
	{
		d.mydelete(myplaneimg[i]);
		d.mydelete(littleenemyimg[i]);
		d.mydelete(middleenemyimg1[i]);
		d.mydelete(middleenemyimg2[i]);
		d.mydelete(myplanebulls1[i]);
		d.mydelete(myplanebulls2[i]);
		d.mydelete(lebulls[i]);
		d.mydelete(mebulls[i]);
	}
	for (int i = 0; i < 5; i++)
	{
		d.mydelete(background1[i]);
		d.mydelete(background2[i]);
		d.mydelete(chooselevelimg[i]);
	}
}

void planesource::load()
{

	for (int i = 0; i < 2; i++)
	{
		myplaneimg[i] = new IMAGE;
		littleenemyimg[i] = new IMAGE;
		middleenemyimg1[i] = new IMAGE;
		middleenemyimg2[i] = new IMAGE;

		myplanebulls1[i] = new IMAGE;
		myplanebulls2[i] = new IMAGE;
		lebulls[i] = new IMAGE;
		mebulls[i] = new IMAGE;

		std::ostringstream oss1;
		oss1 << "resplane/newPlayer/uiPlane" << i << ".jpg";
		std::string path1 = oss1.str();
		std::ostringstream oss2;
		oss2 << "resplane/newEnemy/littleEnemy1(" << i << ").jpg";
		std::string path2 = oss2.str();
		std::ostringstream oss3;
		oss3 << "resplane/newEnemy/middleEnemy1(" << i << ").jpg";
		std::string path3 = oss3.str();
		std::ostringstream oss4;
		oss4 << "resplane/newEnemy/middleEnemy(" << i << ").jpg";
		std::string path4 = oss4.str();

		loadimage(myplaneimg[i], _T(path1.c_str()));

		loadimage(littleenemyimg[i], _T(path2.c_str()));
		loadimage(middleenemyimg1[i], _T(path3.c_str()));
		loadimage(middleenemyimg2[i], _T(path4.c_str()));


		std::ostringstream mpbulls1;
		mpbulls1 << "resplane/newPlayer/bullet" << i << ".jpg";
		std::string mpb1 = mpbulls1.str();
		std::ostringstream mpbulls2;
		mpbulls2 << "resplane/newPlayer/bullet" << (i + 2) << ".jpg";
		std::string mpb2 = mpbulls2.str();

		std::ostringstream lbulls;
		lbulls << "resplane/newEnemy/littleEnemy2bullet" << i << ".jpg";
		std::string lb = mpbulls2.str();
		std::ostringstream mbulls;
		mbulls << "resplane/newEnemy/littleEnemy1_bullet(" << i << ").jpg";
		std::string mb = mbulls.str();

		loadimage(myplanebulls1[i], _T(mpb1.c_str()));
		loadimage(myplanebulls2[i], _T(mpb2.c_str()));
		loadimage(lebulls[i], _T(lb.c_str()));
		loadimage(mebulls[i], _T(mb.c_str()));
	}

	for (int i = 0; i < 5; i++)
	{
		background1[i] = new IMAGE;
		background2[i] = new IMAGE;
		chooselevelimg[i] = new IMAGE;

		std::ostringstream oss1;
		oss1 << "resplane/scene/bg" << i << ".jpg";
		std::string name1 = oss1.str();

		std::ostringstream oss2;
		oss2 << "resplane/scene/game" << (i + 1) << ".jpg";
		std::string name2 = oss2.str();

		loadimage(background1[i], _T(name1.c_str()));
		loadimage(background2[i], _T(name1.c_str()));
		loadimage(chooselevelimg[i], _T(name2.c_str()));
	}
}
//资源单例的类外声明
planesource* planesource::m_source = NULL;
