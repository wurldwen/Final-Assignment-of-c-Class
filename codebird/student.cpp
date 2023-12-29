#define _CRT_SECURE_NO_WARNINGS //һЩ�Ϻ�������
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h> //Easyx��ͼ�ο�ͷ�ļ�
#include<string.h>
#include<ctype.h>//����ַ�

int nowstu_num = 0;//��ǰѧ������

typedef struct Student
{
	char s_Num[30];//ѧ��
	char s_Name[30];//����
	char s_computer[30]; //��
	char s_Math[30];//��
}Student;


//����ѧ���ṹ������
Student s[30];

void SaveInfor();
void ReadInfor();
void Showall();
void InputInfor();
void ModiInfor();
void PrintUI();
void Dele();
void Printfind();
void SaveInforModi();
void chose();

//���尴ť�Ĵ�С����
int R[] = { 150,50,650,150 };
int r1[] = { 200,200,600,250 };
int r2[] = { 200,270,600,320 };
int r3[] = { 200,340,600,390 };
int r4[] = { 200,410,600,460 };
int r5[] = { 200,480,600,530 };
int r6[] = { 200,550,600,600 };
RECT R1 = { R[0],R[1],R[2],R[3] };//����ָ��R1���������������д�֣����ü����ֵ�λ��
RECT R2 = { r1[0],r1[1],r1[2],r1[3] };
RECT R3 = { r2[0],r2[1],r2[2],r2[3] };
RECT R4 = { r3[0],r3[1],r3[2],r3[3] };
RECT R5 = { r4[0],r4[1],r4[2],r4[3] };
RECT R6 = { r5[0],r5[1],r5[2],r5[3] };
RECT R7 = { r6[0],r6[1],r6[2],r6[3] };
ExMessage m1;
void fontset()
{
	LOGFONT f;                          //������ʽָ��
	gettextstyle(&f);					//��ȡ������ʽ
	f.lfHeight = 40;
	_tcscpy(f.lfFaceName, _T("����"));	//����
	f.lfQuality = ANTIALIASED_QUALITY;  // ����� 
	settextstyle(&f);                   // ����������ʽ
	setbkmode(TRANSPARENT);             //���屳��͸��
	settextcolor(BLACK);
}
//���˵�
void menu()
{
	//����ͼ
	initgraph(800, 620);//�����С
	setbkcolor(RGB(102, 115, 97));
	cleardevice();
	setbkmode(TRANSPARENT);
	setfillcolor(WHITE);
	fillrectangle(r1[0], r1[1], r1[2], r1[3]);//�����Σ�����ť
	fillrectangle(r2[0], r2[1], r2[2], r2[3]);
	fillrectangle(r3[0], r3[1], r3[2], r3[3]);
	fillrectangle(r4[0], r4[1], r4[2], r4[3]);
	fillrectangle(r5[0], r5[1], r5[2], r5[3]);
	fillrectangle(r6[0], r6[1], r6[2], r6[3]);

	

	fontset();

	
	drawtext("ѧ���ɼ�����ϵͳ", &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//�ھ�������R1���������֣�ˮƽ���У���ֱ���У�������ʾ
	drawtext("�ɼ�¼��", &R2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("�ɼ���ѯ", &R3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("�ɼ��޸�", &R4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("�ɼ�ɾ��", &R5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("�ɼ���ӡ", &R6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext("�˳�ϵͳ", &R7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	//����������ѡ���������
	
}

//¼����Ϣ
void InputInfor()
{
	//ͨ��ѭ��������Ƿ����ظ���

	//����ѧ��
	while (1)
	{
		InputBox(s[nowstu_num].s_Num, 9, "�������ѧ����ѧ��");

		int FlagInput2 = 0;
		//����������ַ�������
		int nums = strlen(s[nowstu_num].s_Num);

		if (FlagInput2 == 0)
		{
			//�ж��Ƿ������ظ�
			int FlagInput1 = 0;
			for (int i = 0; i < nowstu_num; i++)
			{
				if (strcmp(s[nowstu_num].s_Num, s[i].s_Num) == 0)
				{
					FlagInput1 = 1;
				}
			}
			if (FlagInput1 == 1)
			{
				HWND hwndInput1 = GetHWnd();
				int isok = MessageBox(hwndInput1, "��ѧ���Ѿ����ڣ�����������", "��ʾ", MB_OK);
			}
			if (FlagInput1 == 0)
			{
				break;
			}
		}
	}

	InputBox(s[nowstu_num].s_Name, 10, "�������ѧ��������");
	InputBox(s[nowstu_num].s_Math, 4, "�������ѧ������ѧ�ɼ�");
	InputBox(s[nowstu_num].s_computer, 4, "�������ѧ���ļ�����ɼ�");

	SaveInfor();//��������
}

//�������ݵ��ļ���
void SaveInfor()
{
	//���ѧ�ź����������ǿյĲ�д���ļ�
	if (strlen(s[nowstu_num].s_Num) != 0 && strlen(s[nowstu_num].s_Name) != 0)
	{
		FILE* fp = fopen("StudentInfo.txt", "a");//׷��
		if (fp == NULL)
		{
			return;
		}
		fprintf(fp, "%s\t%s\t%s\t%s\n",
			s[nowstu_num].s_Num,
			s[nowstu_num].s_Name,
			s[nowstu_num].s_Math,
			s[nowstu_num].s_computer);
		fclose(fp);
		//�����������++
		nowstu_num++;
	}
}
//��ȡ�ļ��е���Ϣ
void ReadInfor()
{
	FILE* fp = fopen("StudentInfo.txt", "r");
	if (fp == NULL)
	{
		return;
	}
	//���ļ��е����ݶ�ȡ����ǰ�Ľṹ��������
	for (int i = 0; i < 15; i++)
	{

		fscanf(fp, "%s\t%s\t%s\t%s\t\n",
			s[i].s_Num,
			s[i].s_Name,
			s[i].s_computer,
			s[i].s_Math);
	}

	int FileStudentNums = 0;
	//��ȡ���ļ������ݵ���������
	for (int j = 0; j < 15; j++)
	{
		if (strlen(s[j].s_Name) != 0)
		{
			nowstu_num = ++FileStudentNums;
		}
	}
	fclose(fp);
}

int cha()//����
{
	char Input[30];
	InputBox(Input, 10, "������ѧ����������ѧ��");
	for (int k = 0; k < nowstu_num; k++)
	{
		if (strcmp(s[k].s_Name, Input) == 0 || strcmp(s[k].s_Num, Input) == 0)//�����ַ������
		{
			return k;
		}
	}

	return -1;
}

void PrintUI(int q)//����ɼ�����
{
	ExMessage m2;
	initgraph(640, 480);
	IMAGE img1;
	loadimage(&img1, "C:\\Users\\86182\\source\\repos\\ѧ���ɼ�����ϵͳ2.0\\Camera Roll\\file.jpg", 640, 480);
	putimage(0, 0, &img1);
	setfillcolor(WHITE);
	fillrectangle(300, 380, 380, 410);
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);

	settextstyle(20, 0, "����");
	outtextxy(40, 100, "ѧ��");
	outtextxy(200, 100, "����");
	outtextxy(300, 100, "�����");
	outtextxy(380, 100, "��ѧ");
	outtextxy(320, 380, "����");

	outtextxy(40, 140, s[q].s_Num);
	outtextxy(200, 140, s[q].s_Name);
	outtextxy(300, 140, s[q].s_computer);
	outtextxy(380, 140, s[q].s_Math);
	while (1) {
		m2 = getmessage();
		if (m2.x > 300 && m2.x < 380 && m2.y>380 && m2.y < 410) {
			setlinecolor(RED);
			rectangle(300, 380, 380, 410);
		}
		else {
			setlinecolor(WHITE);
			rectangle(300, 380, 380, 410);
		}
		if (m2.message == WM_LBUTTONDOWN) {
			menu();//���ص����˵�
			chose();
		}
	}
}

void Printfind()//����cha()
{
	int fan1 = cha();//����ֵ
	if (fan1 == -1)//û�ҵ�
	{
		//��ȡ���ھ��
		HWND hndtipsF = GetHWnd();
		int isok = MessageBox(hndtipsF, "���޴���!", "��ʾ", MB_OK);
	}
	else
	{
		PrintUI(fan1);
	}
}

void ModiInfor()
{
	int fan2 = cha();//����ֵ
	if (fan2 == -1)//û�ҵ�
	{
		HWND hndtipsM = GetHWnd();//��ȡ���ھ��
		int isok = MessageBox(hndtipsM, "���޴���!", "��ʾ", MB_OK);
	}
	else//�ҵ�
	{
		while (1)
		{
			char modi[30];
			InputBox(modi, 9, "��������Ҫ�޸ĵ�ѧ����ѧ��");

			if (strcmp(modi, s[fan2].s_Num) == 0)//�����ѧ����ԭ����ѧ����ͬ
			{
				break;
			}
			else//��ͬ
			{
				int flag = 0;
				int nums = strlen(modi);
				for (int i = 0; i < nowstu_num; i++)
				{
					if (strcmp(modi, s[i].s_Num) == 0)
					{
						flag = 1;
						break;
					}
				}
				if (flag == 1)
				{
					HWND hwndInput4 = GetHWnd();
					int isok = MessageBox(hwndInput4, "��ѧ���Ѿ����ڣ�����������", "��ʾ", MB_OK);
				}
				else if (flag == 0)
				{
					memcpy(s[fan2].s_Num, modi, nums);//���������ѧ�Ÿ��Ƶ�ѧ����Ϣ����
					break;
				}
			}

		}
		InputBox(s[fan2].s_Name, 8, "�������ѧ��������");
		InputBox(s[fan2].s_computer, 10, "�������ѧ���ļ�����ɼ�");
		InputBox(s[fan2].s_Math, 10, "�������ѧ������ѧ�ɼ�");
	}

	SaveInforModi();
}

void Dele()
{
	int dele = cha();
	if (dele == -1)//û�ҵ�
	{
		HWND hndtipsD = GetHWnd();
		int isok = MessageBox(hndtipsD, "���޴���!", "��ʾ", MB_OK);
	}
	else
	{
		HWND hndtipsDS = GetHWnd();
		int isok = MessageBox(hndtipsDS, "ȷ��ɾ����", "��ʾ", MB_OKCANCEL);
		if (isok == IDOK)
		{
			//ȷ��ɾ������
			//�����Ԫ�صĺ�һ������Ǩ��
			for (int n = dele; n < nowstu_num; n++)
			{
				s[n] = s[n + 1];
			}
			nowstu_num--;
			//���µ��ļ���
			SaveInforModi();//���ļ�����д
		}
		else if (isok == IDCANCEL)
		{

		}
	}
}

void SaveInforModi()
{
	//��ɾ��
	remove("StudentInfo.txt");
	FILE* fp = fopen("StudentInfo.txt", "a");
	if (fp == NULL)
	{
		return;
	}
	//����д
	for (int i = 0; i < nowstu_num; i++)
	{
		if (strlen(s[i].s_Num) != 0 && strlen(s[i].s_Name) != 0)
		{
			fprintf(fp, "%s\t%s\t%s\t%s\n",
				s[i].s_Num,
				s[i].s_Name,
				s[i].s_computer,
				s[i].s_Math);
		}
	}

	fclose(fp);
}

void Showall() //��ӡ���Գɼ�
{
	
	ExMessage m3;
	initgraph(640, 480);fontset();
	/*IMAGE img2;
	loadimage(&img2, "C:\\Users\\86182\\source\\repos\\ѧ���ɼ�����ϵͳ2.0\\Camera Roll\\file.jpg", 640, 480);
	putimage(0, 0, &img2);*/
	setbkcolor(RGB(225, 223, 238));
	cleardevice();
	setfillcolor(WHITE);
	fillrectangle(300, 430, 380, 460);
	/*setbkmode(TRANSPARENT);
	settextcolor(BLACK);*/
	

	//settextstyle(20, 0, "����");
	outtextxy(40, 20, "ѧ��");
	outtextxy(200, 20, "����");
	outtextxy(300, 20, "�����");
	outtextxy(380, 20, "��ѧ");
	outtextxy(320, 440, "����");//���ذ�ť

	for (int q = 0; q <= nowstu_num; q++) {
		outtextxy(40, 60 + q * 20, s[q].s_Num);
		outtextxy(200, 60 + q * 20, s[q].s_Name);
		outtextxy(300, 60 + q * 20, s[q].s_computer);
		outtextxy(380, 60 + q * 20, s[q].s_Math);
	}


	while (1) {
		m3 = getmessage();
		if (m3.x > 300 && m3.x < 430 && m3.y>380 && m3.y < 460) {
			setlinecolor(RED);
			rectangle(300, 430, 380, 460);if (m3.message == WM_LBUTTONDOWN) {
			menu();
			chose();//�������˵�
		}
		}
		else {
			setlinecolor(WHITE);
			rectangle(300, 430, 380, 460);
		}
		
	}

}
void chose()
{

	while (1)
	{
		static int n = 0; n++;
		m1 = getmessage();//��ȡ������
		if (m1.x > r1[0] && m1.x < r1[2] && m1.y>r1[1] && m1.y < r1[3]) {
			setlinecolor(RED);
			rectangle(r1[0], r1[1], r1[2], r1[3]);
			if (m1.message == WM_LBUTTONDOWN)
			{
				InputInfor();//¼��
			}
		}
		else if (m1.x >= r2[0] && m1.x <= r2[2] && m1.y >= r2[1] && m1.y <= r2[3]) {
			setlinecolor(RED);
			rectangle(r2[0], r2[1], r2[2], r2[3]);
			if (m1.message == WM_LBUTTONDOWN)
			{
				Printfind();//��ѯ
			}
		}
		else if (m1.x >= r3[0] && m1.x <= r3[2] && m1.y >= r3[1] && m1.y <= r3[3]) {
			setlinecolor(RED);
			rectangle(r3[0], r3[1], r3[2], r3[3]);
			if (m1.message == WM_LBUTTONDOWN)
			{
				ModiInfor();//�޸�
			}
		}

		else if (m1.x >= r4[0] && m1.x <= r4[2] && m1.y >= r4[1] && m1.y <= r4[3]) {
			setlinecolor(RED);
			rectangle(r4[0], r4[1], r4[2], r4[3]);
			if (m1.message == WM_LBUTTONDOWN) {
				Dele();//ɾ��

			}
		}
		else if (m1.x >= r5[0] && m1.x <= r5[2] && m1.y >= r5[1] && m1.y <= r5[3]) {
			setlinecolor(RED);
			rectangle(r5[0], r5[1], r5[2], r5[3]);
			if (m1.message == WM_LBUTTONDOWN) {
				Showall();//��ӡ
			}
		}
		else if (m1.x >= r6[0] && m1.x <= r6[2] && m1.y >= r6[1] && m1.y <= r6[3]) {
			setlinecolor(RED);
			rectangle(r6[0], r6[1], r6[2], r6[3]);
			if (m1.message == WM_LBUTTONDOWN) {
				closegraph();//�˳�
			}
		}
		else {
			setlinecolor(WHITE);
			rectangle(r1[0], r1[1], r1[2], r1[3]);
			rectangle(r2[0], r2[1], r2[2], r2[3]);
			rectangle(r3[0], r3[1], r3[2], r3[3]);
			rectangle(r4[0], r4[1], r4[2], r4[3]);
			rectangle(r5[0], r5[1], r5[2], r5[3]);
			rectangle(r6[0], r6[1], r6[2], r6[3]);
		}
	}
}
int main(void)//����������
{
	ReadInfor();
	menu();
	chose();
	system("pause");
	return 0;
}


