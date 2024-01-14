#include"mysignup.h"

SignupWidget::SignupWidget(vector<Player>& UserArray):UserArray(UserArray)
{
	pUserNameEdit = new Edit(200, 100, 200, 30, RGB(204, 213, 240));					//�����û���
	pPasswordEdit = new Edit(200, 150, 200, 30, RGB(204, 213, 240));				//��������
	pPasswordEdit->SetEditType(Edit::PsdEdit);									//���õ�ǰ�༭��Ϊ���ɼ�
	pUserNameLabel = new Label("�û���:");										//�û�����ǩ
	pPasswordLabel = new Label("��  ��:");										//�����ǩ
	pEntranceButton = new Button(180, 230, 150, 35, RGB(106, 213, 245),  "ע��");					//ע��	
}

void SignupWidget::Init()
{
	pUserNameEdit->RenewText();
	pPasswordEdit->RenewText();
	hwnd = initgraph(ENTERW, ENTERH);
	MoveWindow(hwnd, (screenWidth - ENTERW) / 2, (screenHeight - ENTERH) / 2, ENTERW, ENTERH, true);	//�ƶ������Ĵ���
	setbkcolor(RGB(158, 211, 206));
	cleardevice();
	OnEvent();//��¼����İ�ť
}

void SignupWidget::AddAccount(Edit* UserName, Edit* UserPIN)
{
	/*ofstream ofs;
	ofs.open(FILENAME, ios::out);*/
	ofstream ofs(FILENAME,ios::out | ios::app);
	if (!ofs) {
		cerr << "Error opening file for reading!" << endl;
		return;
	}
	
	Player p;
	p.Name = UserName->GetText();
	p.PIN = UserPIN->GetText();
	ofs<< p.Name << " "<< p.PIN << " "<<0<<" "<<1<< endl;
	ofs.close();
	UserArray.push_back(p);
}

SignupWidget::~SignupWidget()
{
	delete pUserNameEdit;
	delete pPasswordEdit;
	delete pPasswordLabel;
	delete pUserNameLabel;
	delete pEntranceButton;
	closegraph();
}

void SignupWidget::Show()
{
	pUserNameLabel->Show(100, 100);
	pUserNameEdit->Show();
	pPasswordLabel->Show(100, 150);
	pPasswordEdit->Show();
	pEntranceButton->Show();
}

void SignupWidget::OnEvent()
{
	BeginBatchDraw();
	ExMessage msg;
	while (true)
	{
		while (peekmessage(&msg))
		{
			pUserNameEdit->OnEvent(msg);
			pPasswordEdit->OnEvent(msg);
			if (pEntranceButton->OnClickButton(msg))
			{
				if (pUserNameEdit->GetText() != " " && pPasswordEdit->GetText() != " ")
				{
					if (CheckAccount(pUserNameEdit))
					{
						MessageBox(hwnd, "�û��Ѵ���", "��ʾ", MB_OK);
					}
					else
					{
						AddAccount(pUserNameEdit, pPasswordEdit);
					    MessageBox(hwnd, "ע��ɹ�", "��ʾ", MB_OK);
					}
					return;
				}
			}
		}
		Show();
		FlushBatchDraw();
	}
	EndBatchDraw();
}

bool SignupWidget::CheckAccount(Edit* UserName)
{
	ifstream ifs(FILENAME, ios::in);
	if (!ifs)
	{
		cerr << "Error opening file for reading!" << endl;
		return false;
	}
	string name;
	while (ifs >> name)
	{
		if (name == UserName->GetText())return true;
	}
	ifs.close();
	return false;
}