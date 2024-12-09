#include "view.h"
#include "data.h"
#include "game_logic.h"




/*
    ������: Su bak
    ����: ���ƿ�ʼ����
        1. ��ʾ��Ϸ����
        2. ��ʾ�˵�ѡ���ʼ��Ϸ����Ϸ���á�������ܡ��Ŷ�չʾ���˳���Ϸ��
        3. �����û�ѡ����½���
    ����: void
    ����ֵ: void
*/
void drawStartMenu()
{
	
		//initgraph(1000, 750);
		setbkcolor(WHITE);
		cleardevice();//���� two
		settextstyle(70, 0, L"�Ļ���κ");
		settextcolor(RGB(30, 30, 30));
		outtextxy(410, 50, L"ɨ��");
		settextstyle(35, 0, L"����");
		settextcolor(RGB(30, 30, 30));
		outtextxy(360, 130, L"�������Ͻ�����");

		//�����κ�Բ�İ�����ʼ��
		setfillcolor(WHITE);//��䰴ť����ɫ
		settextstyle(40, 0, L"����");// ���  �߶� ����
		setlinecolor(BLACK);//�����ߵ���ɫ
		settextcolor(BLACK);//�������ֵ���ɫ
		setlinestyle(PS_SOLID, 2);//��������ʵ�߻������� 5��ָ�ߵĿ��
		setbkmode(TRANSPARENT);//�����ֵı���ȥ��

		//��ʼ��Ϸ

		fillrectangle(350, 270, 600, 320);//�����ζԽǵ�����
		outtextxy(350 + 50, 270 + 10, L"��ʼ��Ϸ");//�������ֵ�λ��

		//����
		fillrectangle(350, 370, 600, 420);//�����ζԽǵ�����
		outtextxy(350 + 50, 370 + 10, L"��Ϸ����");//�������ֵ�λ��

		//��ʷ��¼
		fillrectangle(350, 470, 600, 520);//�����ζԽǵ�����
		outtextxy(350 + 50, 470 + 10, L"��ʷ��¼");//�������ֵ�λ��

		//�˳���Ϸ
		fillrectangle(350, 570, 600, 620);//�����ζԽǵ�����
		outtextxy(350 + 50, 570 + 10, L"�˳���Ϸ");//�������ֵ�λ��

		//��
		settextstyle(35, 0, L"����");
		fillcircle(320, 200, 35);//X,Y��Բ��λ�ã�Բ�İ뾶  
		outtextxy(320 - 20, 200 - 30, L"��");//�������ֵ�λ��
		outtextxy(320 - 20, 200 + 5, L"��");//�������ֵ�λ��

		//��ͨ
		fillcircle(470, 200, 35);
		outtextxy(470 - 20, 200 - 30, L"��");//�������ֵ�λ��
		outtextxy(470 - 20, 200 + 5, L"ͨ");//�������ֵ�λ��

		//����
		fillcircle(620, 200, 35);
		outtextxy(620 - 20, 200 - 30, L"��");//�������ֵ�λ��
		outtextxy(620 - 20, 200 + 5, L"��");//�������ֵ�λ��

		//�������
		fillcircle(850, 700, 35);
		settextstyle(24, 0, L"����");
		outtextxy(850 - 20, 700 - 20, L"����");//�������ֵ�λ��
		outtextxy(850 - 20, 700 + 5, L"����");//�������ֵ�λ��

		//С����
		fillcircle(950, 700, 35);
		settextstyle(24, 0, L"����");
		outtextxy(950 - 20, 700 - 20, L"С��");//�������ֵ�λ��
		outtextxy(950 - 20, 700 + 5, L"���");//�������ֵ�λ��
		
		

}


/*
    ������: Su bak
    ����: ����˵�����
        1. �����û�����
        2. ���ݰ���ѡ��˵����ת����Ӧ����
    ����: void
    ����ֵ: void
*/
void handleMenuInput()
{
	drawStartMenu();
	while (1)
	{
		BeginBatchDraw();//�е���������һ��˫����
	    MOUSEMSG m = GetMouseMsg();

		//��ʼ��Ϸ
		if (m.x >= 350 && m.x <= 600 && m.y > 270 && m.y <= 320)
		{
			setfillcolor(YELLOW);//����ǰ��ť��Ϊ��ɫ
			settextstyle(41, 0, L"����");
			fillrectangle(350, 270, 600, 320);//�����ζԽǵ�����
			outtextxy(350 + 50, 270 + 10, L"��ʼ��Ϸ");//�������ֵ�λ��
			if (m.uMsg == WM_LBUTTONDOWN)//�����������
			{
				cleardevice();
				EndBatchDraw();
				drawGameBoard();//����Ϸ����
				drawStartMenu();
			}
		}
		else
		{
			setfillcolor(WHITE);
			settextstyle(40, 0, L"����");
			fillrectangle(350, 270, 600, 320);
			outtextxy(350 + 50, 270 + 10, L"��ʼ��Ϸ");
		}

		//����
		if (m.x >= 350 && m.x <= 600 && m.y > 370 && m.y <= 420)
		{
			setfillcolor(YELLOW);
			settextstyle(41, 0, L"����");
			fillrectangle(350, 370, 600, 420);
			outtextxy(350 + 50, 370 + 10, L"��Ϸ����");
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				cleardevice();
				EndBatchDraw();
				drawSettingsMenu();//�����ý���
				drawStartMenu();
			}
		}
		else
		{
			setfillcolor(WHITE);
			settextstyle(40, 0, L"����");
			fillrectangle(350, 370, 600, 420);
			outtextxy(350 + 50, 370 + 10, L"��Ϸ����");
		}

		//��ʷ��¼
		if (m.x >= 350 && m.x <= 600 && m.y > 470 && m.y <= 520)
		{
			setfillcolor(YELLOW);
			settextstyle(41, 0, L"����");
			fillrectangle(350, 470, 600, 520);
			outtextxy(350 + 50, 470 + 10, L"��ʷ��¼");
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				cleardevice();
				EndBatchDraw();
				displayHistory();  // ������ʷ��¼����
				drawStartMenu();
			}
		}
		else
		{
			setfillcolor(WHITE);
			settextstyle(40, 0, L"����");
			fillrectangle(350, 470, 600, 520);
			outtextxy(350 + 50, 470 + 10, L"��ʷ��¼");
		}

		//�˳���Ϸ
		if (m.x >= 350 && m.x <= 570 && m.y > 600 && m.y <= 620)
		{
			setfillcolor(YELLOW);
			settextstyle(41, 0, L"����");
			fillrectangle(350, 570, 600, 620);
			outtextxy(350 + 50, 570 + 10, L"�˳���Ϸ");
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				return;
			}
		}
		else
		{
			setfillcolor(WHITE);
			settextstyle(40, 0, L"����");
			fillrectangle(350, 570, 600, 620);
			outtextxy(350 + 50, 570 + 10, L"�˳���Ϸ");
		}

		//��
		if (sqrt((m.x - 320) * (m.x - 320) + (m.y - 200) * (m.y - 200)) <= 35)
		{
			settextstyle(30, 0, L"����");
			if (m.uMsg == WM_LBUTTONDOWN)//����������Ѷ�����Ϊ��
			{
				setfillcolor(YELLOW);
				fillcircle(320, 200, 35);//X,Y��Բ��λ�ã�Բ�İ뾶  
				outtextxy(320 - 20, 200 - 30, L"��");//�������ֵ�λ��
				outtextxy(320 - 20, 200 + 5, L"��");//�������ֵ�λ��

				//���Ѷ�����
				width = 8;
				height = 8;
				difficulty = 1;

			}

		}
		else
		{
			if (sqrt((m.x - 470) * (m.x - 470) + (m.y - 200) * (m.y - 200)) <= 35 || sqrt((m.x - 620) * (m.x - 620) + (m.y - 200) * (m.y - 200)) <= 35)
			{
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					setfillcolor(WHITE);
					settextstyle(35, 0, L"����");
					fillcircle(320, 200, 35);
					outtextxy(320 - 20, 200 - 30, L"��");
					outtextxy(320 - 20, 200 + 5, L"��");
				}
			}

		}

		//��ͨ
		if (sqrt((m.x - 470) * (m.x - 470) + (m.y - 200) * (m.y - 200)) <= 35)
		{
			settextstyle(30, 0, L"����");
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				setfillcolor(YELLOW);
				fillcircle(470, 200, 35);
				outtextxy(470 - 20, 200 - 30, L"��");
				outtextxy(470 - 20, 200 + 5, L"ͨ");

				//��ͨ�Ѷ�����
				width = 10;
				height = 10;
				difficulty = 2;

			}
		}
		else
		{
			if (sqrt((m.x - 320) * (m.x - 320) + (m.y - 200) * (m.y - 200)) <= 35 || sqrt((m.x - 620) * (m.x - 620) + (m.y - 200) * (m.y - 200)) <= 35)
			{
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					settextstyle(35, 0, L"����");
					setfillcolor(WHITE);
					fillcircle(470, 200, 35);
					outtextxy(470 - 20, 200 - 30, L"��");
					outtextxy(470 - 20, 200 + 5, L"ͨ");
				}
			}
		}

		//����
		if (sqrt((m.x - 620) * (m.x - 620) + (m.y - 200) * (m.y - 200)) <= 35)
		{
			settextstyle(30, 0, L"����");
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				setfillcolor(YELLOW);
				fillcircle(620, 200, 35);
				outtextxy(620 - 20, 200 - 30, L"��");
				outtextxy(620 - 20, 200 + 5, L"��");

				//�����Ѷ�����
				width = 16;
				height = 16;
				difficulty = 3;

			}
		}
		else
		{
			if (sqrt((m.x - 470) * (m.x - 470) + (m.y - 200) * (m.y - 200)) <= 35 || sqrt((m.x - 320) * (m.x - 320) + (m.y - 200) * (m.y - 200)) <= 35)
			{
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					settextstyle(35, 0, L"����");
					setfillcolor(WHITE);
					fillcircle(620, 200, 35);
					outtextxy(620 - 20, 200 - 30, L"��");
					outtextxy(620 - 20, 200 + 5, L"��");
				}
			}
		}

		//�������
		if (sqrt((m.x - 850) * (m.x - 850) + (m.y - 700) * (m.y - 700)) <= 35)
		{
			setfillcolor(YELLOW);
			settextstyle(25, 0, L"����");
			fillcircle(850, 700, 35);
			outtextxy(850 - 20, 700 - 20, L"����");//�������ֵ�λ��
			outtextxy(850 - 20, 700 + 5, L"����");//�������ֵ�λ��
			if (m.uMsg == WM_LBUTTONDOWN)//�����������
			{
				cleardevice();
				EndBatchDraw();
				ruleIntroduction();
				drawStartMenu();
			}
		}
		else
		{
			setfillcolor(WHITE);
			settextstyle(24, 0, L"����");
			fillcircle(850, 700, 35);
			outtextxy(850 - 20, 700 - 20, L"����");
			outtextxy(850 - 20, 700 + 5, L"����");
		}

		//С����
		if (sqrt((m.x - 950) * (m.x - 950) + (m.y - 700) * (m.y - 700)) <= 35)
		{
			setfillcolor(YELLOW);
			settextstyle(25, 0, L"����");
			fillcircle(950, 700, 35);
			outtextxy(950 - 20, 700 - 20, L"С��");
			outtextxy(950 - 20, 700 + 5, L"���");

			if (m.uMsg == WM_LBUTTONDOWN)//�����������
			{
				cleardevice();
				EndBatchDraw();
				groupPresentation();
				drawStartMenu();
			}
		}
		else
		{
			setfillcolor(WHITE);
			settextstyle(24, 0, L"����");
			fillcircle(950, 700, 35);
			settextstyle(24, 0, L"����");
			outtextxy(950 - 20, 700 - 20, L"С��");
			outtextxy(950 - 20, 700 + 5, L"���");

		}
	EndBatchDraw();
	}

	
}

/*
    ������: Ү���
    ����: ������Ϸ����
        1. ��ʾ��Ϸ��ͼ
        2. ������Ϸ״̬���Ƿ���ͣ���Ƿ���Ϸ��������ʾ�����Ϣ
        3. ��ʾ��ʱ��
        4. ʣ��ɱ�Ǹ�����
        5. ʣ��δ�򿪸��������������ѱ�Ǹ��ӣ�
    ����: void
    ����ֵ: void
*/
void drawGameBoard() 
{
    // ������Ϸ������
    // ���Ƹ��Ӻ��ѷ��������֡��ױ�ǵ�
}


/*
    ������: Ү���
    ����: ������Ϸ��������
        1. �����û��ĵ����������루����ͣ��Ϸ���������ӵȣ�
        2. �������������Ϸ״̬
    ����: void
    ����ֵ: void
*/
void handleGameInput() 
{
    // ������Ϸ���룬������Ҽ���ǡ���ͣ��
}


/*
    ������: ����
    ����: ����ʤ������
        1. ��ʾ��Ϸʤ����Ϣ
    ����: void
    ����ֵ: void
*/
void drawVictoryScreen() 
{
    // ������Ϸʤ������
}


/*
    ������: ����
    ����: ���ƽ������
        1. ��ʾ��Ϸ������Ϣ���ṩ���¿�ʼ���˳���ѡ��
    ����: void
    ����ֵ: void
*/
void drawGameOverScreen()
{
    // ������Ϸ��������
}


/*
    �����ˣ�chouchou
    ���ܣ��������
        1.��ʾ��Ϸ����
*/
void ruleIntroduction() 
{
	//closegraph();
	//initgraph(1000, 750);
	//cleardevice();
	setbkcolor(WHITE);
	//cleardevice();

	setlinecolor(BLACK);
	rectangle(20, 20, 980, 730);

	settextstyle(50, 0, L"����");  // ʹ�ÿ��ַ�
	setbkmode(TRANSPARENT);
	settextcolor(RGB(256, 256, 256));
	wchar_t Title[100] = L"�������";  // ʹ�ÿ��ַ�
	int widthTitle = 1000 / 2 - textwidth(Title) / 2;
	outtextxy(widthTitle, 30, Title);

	settextstyle(20, 0, L"����");
	wchar_t group[100] = L"�������Ͻ�����";  // ʹ�ÿ��ַ�
	outtextxy(835, 705, group);

	settextstyle(30, 0, L"����");
	wchar_t gamegoal[100] = L"һ����ϷĿ��";  // ʹ�ÿ��ַ�
	outtextxy(100, 100, gamegoal);

	settextstyle(25, 0, L"����");
	wchar_t gamegoalcontent[100] = L"�ҳ����е��ײ���ǣ�ͬʱ��ȫ�ش����зǵ��׷��顣";  // ʹ�ÿ��ַ�
	outtextxy(100, 140, gamegoalcontent);

	settextstyle(30, 0, L"����");
	wchar_t gameelement[100] = L"������ϷԪ��";  // ʹ�ÿ��ַ�
	outtextxy(100, 180, gameelement);

	settextstyle(25, 0, L"����");
	wchar_t gameelementcontentA[100] = L"���飺��Ϸ�п��Դ򿪵ĸ��ӣ��ڲ����ܰ������׻��������֡�";  // ʹ�ÿ��ַ�
	wchar_t gameelementcontentBa[100] = L"���֣���ʾ�÷�����Χ��3*3���򣬱߿�Ϊ5�����ӣ��ǿ�Ϊ3�����ӣ�";  // ʹ�ÿ��ַ�
	wchar_t gameelementcontentBb[100] = L"���׵�������";  // ʹ�ÿ��ַ�
	wchar_t gameelementcontentC[100] = L"��ǣ����ڱ�ʶ���׵����ӣ���ҿ���ͨ���Ҽ������������ǵ��ס�";  // ʹ�ÿ��ַ�
	wchar_t gameelementcontentD[100] = L"���ף���Ϸ�ĺ���Ԫ�أ������Ҫ���ⷭ����Щ���顣";  // ʹ�ÿ��ַ�
	outtextxy(100, 220, gameelementcontentA);
	outtextxy(100, 250, gameelementcontentBa);
	outtextxy(100, 280, gameelementcontentBb);
	outtextxy(100, 310, gameelementcontentC);
	outtextxy(100, 340, gameelementcontentD);

	settextstyle(30, 0, L"����");
	wchar_t gameoperation[100] = L"������������";  // ʹ�ÿ��ַ�
	outtextxy(100, 380, gameoperation);

	settextstyle(25, 0, L"����");
	wchar_t gameoperationcontentAa[100] = L"����������򿪷��飬����÷���Ϊ�գ�����ʾ���ֻ�����ݹ��";  // ʹ�ÿ��ַ�
	wchar_t gameoperationcontentAb[100] = L"���ڵĿշ��飻����������ף�����Ϸ������";  // ʹ�ÿ��ַ�
	outtextxy(100, 420, gameoperationcontentAa);
	outtextxy(100, 450, gameoperationcontentAb);

	wchar_t gameoperationcontentBa[100] = L"�Ҽ���������ǵ��ף�����С���졣�ٴ��Ҽ���������ȡ����ǣ���";  // ʹ�ÿ��ַ�
	wchar_t gameoperationcontentBb[100] = L"������Ϸ�˵��й�ѡ�ˡ����(?)��������Ҫ���β�����ȡ�����ף���";  // ʹ�ÿ��ַ�
	outtextxy(100, 480, gameoperationcontentBa);
	outtextxy(100, 510, gameoperationcontentBb);

	wchar_t gameoperationcontentCa[100] = L"˫������˫��λ����Χ�ѱ�ǵĵ����������ڸ�λ������ʱ��˫����";  // ʹ�ÿ��ַ�
	wchar_t gameoperationcontentCb[100] = L"�Դ򿪸�������Χ����δ��ǵķ��顣�����Ǵ�����˫�����";  // ʹ�ÿ��ַ�
	wchar_t gameoperationcontentCc[100] = L"�ķ����б��е��ף���Ϸ������";  // ʹ�ÿ��ַ�
	outtextxy(100, 540, gameoperationcontentCa);
	outtextxy(100, 570, gameoperationcontentCb);
	outtextxy(100, 600, gameoperationcontentCc);
	
	_getch();
	closegraph();
	return ;
}


/*
    �����ˣ�chouchou
    ���ܣ�С�����
        1.��ʾС�����
*/
void groupPresentation() 
{
	while (1)
	{
		

		setbkcolor(WHITE);
		cleardevice();

		setlinecolor(BLACK);
		rectangle(20, 20, 980, 730);

		// ���ñ�������
		settextstyle(50, 0, L"����");  // ʹ�ÿ��ַ�
		setbkmode(TRANSPARENT);
		settextcolor(RGB(256, 256, 256));

		// ��ʾ����
		wchar_t Title[] = L"С����";  // ���ַ��ַ���
		int widthTitle = 1000 / 2 - textwidth(Title) / 2;
		outtextxy(widthTitle, 30, Title);

		// ��ʾС������
		settextstyle(20, 0, L"����");
		wchar_t group[] = L"�������Ͻ�����";  // ���ַ��ַ���
		outtextxy(835, 705, group);

		// ��ʾ��Ա��Ϣ
		settextstyle(35, 0, L"����");

		wchar_t groupmemberA[] = L"��̽�����һָ����(�鳤��";
		int widthgroupmemberA = 1000 / 2 - textwidth(groupmemberA) / 2;

		wchar_t groupmemberB[] = L"Su bak(���鳤��";
		int widthgroupmemberB = 1000 / 2 - textwidth(groupmemberB) / 2;

		wchar_t groupmemberC[] = L"���ǣ������¼�٣�";
		int widthgroupmemberC = 1000 / 2 - textwidth(groupmemberC) / 2;

		wchar_t groupmemberD[] = L"�����ƣ���Ϣ�٣�";
		int widthgroupmemberD = 1000 / 2 - textwidth(groupmemberD) / 2;

		wchar_t groupmemberE[] = L"Savior���ල�٣�";
		int widthgroupmemberE = 1000 / 2 - textwidth(groupmemberE) / 2;

		wchar_t groupmemberF[] = L"������٣�";
		int widthgroupmemberF = 1000 / 2 - textwidth(groupmemberF) / 2;

		wchar_t groupmemberG[] = L"tydddd�������٣�";
		int widthgroupmemberG = 1000 / 2 - textwidth(groupmemberG) / 2;

		wchar_t groupmemberH[] = L"Ү�������Ʒ����";
		int widthgroupmemberH = 1000 / 2 - textwidth(groupmemberH) / 2;

		wchar_t groupmemberI[] = L"CHOUCHOU����Ʒ����";
		int widthgroupmemberI = 1000 / 2 - textwidth(groupmemberI) / 2;

		wchar_t groupmemberJ[] = L"����Сѧ��";
		int widthgroupmemberJ = 1000 / 2 - textwidth(groupmemberJ) / 2;

		// �����Ա��Ϣ
		outtextxy(widthgroupmemberA, 120, groupmemberA);
		outtextxy(widthgroupmemberB, 170, groupmemberB);
		outtextxy(widthgroupmemberC, 220, groupmemberC);
		outtextxy(widthgroupmemberD, 270, groupmemberD);
		outtextxy(widthgroupmemberE, 320, groupmemberE);
		outtextxy(widthgroupmemberF, 370, groupmemberF);
		outtextxy(widthgroupmemberG, 420, groupmemberG);
		outtextxy(widthgroupmemberH, 470, groupmemberH);
		outtextxy(widthgroupmemberI, 520, groupmemberI);
		outtextxy(widthgroupmemberJ, 570, groupmemberJ);

		getchar();
		
		return;
	}
}

/*
    ������: chouchou
    ����: ������Ϸ���ý���
        1. ��ʾ��ǰ�ѶȺ���������
        2. �ṩ�ѶȺ����ֿ���ѡ��
    ����: void
    ����ֵ: void
*/
void drawSettingsMenu() 
{
	

	setbkcolor(WHITE);
	cleardevice();

	setlinecolor(BLACK);
	rectangle(20, 20, 980, 730);

	settextstyle(50, 0, L"����");
	setbkmode(TRANSPARENT);
	settextcolor(RGB(256, 256, 256));

	std::wstring Title = L"����";  // ʹ�� Unicode �ַ���
	int widthTitle = 1000 / 2 - textwidth(Title.c_str()) / 2;
	outtextxy(widthTitle, 30, Title.c_str());

	settextstyle(20, 0, L"����");
	std::wstring group = L"�������Ͻ�����";
	outtextxy(835, 705, group.c_str());

	settextstyle(40, 0, L"����");

	std::wstring music = L"����";
	rectangle(400, 145, 600, 205);
	std::wstring musicopen = L"��";
	rectangle(400, 210, 600, 270);
	std::wstring musicclose = L"��";
	outtextxy(460, 90, music.c_str());
	outtextxy(480, 153, musicopen.c_str());
	outtextxy(480, 220, musicclose.c_str());

	settextstyle(40, 0, L"����");

	std::wstring soundeffect = L"��Ч";
	rectangle(400, 340, 600, 400);
	std::wstring soundeffectopen = L"��";
	rectangle(400, 405, 600, 465);
	std::wstring soundeffectclose = L"��";
	rectangle(400, 470, 600, 530);
	std::wstring bkmusic1 = L"��������1";
	rectangle(400, 535, 600, 595);
	std::wstring bkmusic2 = L"��������2";
	rectangle(400, 600, 600, 660);
	std::wstring bkmusic3 = L"��������3";

	outtextxy(460, 295, soundeffect.c_str());
	outtextxy(480, 350, soundeffectopen.c_str());
	outtextxy(480, 415, soundeffectclose.c_str());
	outtextxy(410, 480, bkmusic1.c_str());
	outtextxy(410, 545, bkmusic2.c_str());
	outtextxy(410, 610, bkmusic3.c_str());

	rectangle(36, 660, 160, 714);
	settextstyle(35, 0, L"����");
	std::wstring back = L"����";
	outtextxy(63, 670, back.c_str());

	getchar();
	
	return ;
}

/*
    ������: chouchou
    ����: �������ý�������
        1. �����û������ý����ѡ���Ѷȡ����ֿ��أ�
    ����: void
    ����ֵ: void
*/
void handleSettingsInput() 
{
    // �������ò˵�����
}


/*
	������: ������
	����: ��Ϸ����ʱ�Ĵ���
		1. ֹͣ��ʱ��
		2. ��ʾ�������
	����: void
	����ֵ: void
*/
void endGame()
{
	if (checkWin())
	{
		drawVictoryScreen();//����ʤ������
		saveHistory(getElapsedTime(), true); // ������Ϸʤ������ʷ��¼
	}
	else
	{
		drawGameOverScreen();//����ʧ�ܽ���
		saveHistory(getElapsedTime(), false); // ������Ϸʧ�ܵ���ʷ��¼
	}
}


void drawTable(int vernier_n, int n) {
	// �������
	setlinestyle(PS_SOLID, 2);
	setlinecolor(BLACK);
	fillroundrect(200, 125, 800, 625, 10, 10);
	line(200, 175, 800, 175);
	line(200, 225, 800, 225);
	line(200, 275, 800, 275);
	line(200, 325, 800, 325);
	line(200, 375, 800, 375);
	line(200, 425, 800, 425);
	line(200, 475, 800, 475);
	line(200, 525, 800, 525);
	line(200, 575, 800, 575);
	line(500, 125, 500, 625);
}






