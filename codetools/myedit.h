//�ı���༭���
#ifndef MYEDIT_H
#define MYEDIT_H

#include"../codemain/mygamebase.h"
#include"mycrusor.h"
#include"myreact.h"

class Edit
{
public:
	enum EditType { TextEdit, PsdEdit };
	Edit(int x, int y, int w, int h, COLORREF color);
	void RenewText() { //text.erase(0,10);
		text.resize(0);
	}
	void Show();
	void SetEditType(EditType type);
	bool InEdit(ExMessage msg);
	void OnEvent(ExMessage msg);
	std::string GetText();
private:
	Rect rect;
	Cursor cursor;
	std::string text;		
	int textw;			//���ֿ��
	bool inputState;	//�Ƿ�����
	EditType  type;		//�༭������
};

#endif // !MYEDIT_H
