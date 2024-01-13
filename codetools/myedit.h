//文本框编辑组件
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
	int textw;			//文字宽度
	bool inputState;	//是否输入
	EditType  type;		//编辑框类型
};

#endif // !MYEDIT_H
