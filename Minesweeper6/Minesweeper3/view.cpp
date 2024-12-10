#include "view.h"
#include "data.h"
#include "game_logic.h"
#include "settings.h"




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
				handleSettingsInput();//�����ý���
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
				mineCount = 10;
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
				mineCount = 20;
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
				mineCount = 40;
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
	initGame();   //��ʼ��
	startTimer();  // ������ʱ��
	bool isPause = 0;
	IMAGE imgs[13];

	for (int i = 0; i <= 8; i++) {
		WCHAR fileName[20] = { 0 };
		wsprintf(fileName, _T("./source/��ʾ��-%d.png"), i);
		loadimage(imgs + i, fileName, 40, 40);
	}
	loadimage(imgs + 9, _T("./source/�׵�.png"), 40, 40);
	loadimage(imgs + 10, _T("./source/δ�򿪸���.png"), 40, 40);
	loadimage(imgs + 11, _T("./source/����.png"), 40, 40);
	loadimage(imgs + 12, _T("./source/����ʱ.png"), 80, 40);


	//��ѭ��
	BeginBatchDraw();
	while (true)
	{
		handleGameInput();
		cleardevice();
		if (isPause)
		{
			pauseGame();
		}

		setbkcolor(WHITE);



		//�����ΰ�����ʼ��
		setfillcolor(WHITE);//��䰴ť����ɫ
		settextstyle(40, 0, L"����");// ���  �߶� ����
		setlinecolor(BLACK);//�����ߵ���ɫ
		settextcolor(BLACK);//�������ֵ���ɫ
		setlinestyle(PS_SOLID, 2);//��������ʵ�߻�������
		setbkmode(TRANSPARENT);//�����ֵı���ȥ��

		//����
		/*fillrectangle(440, 440, 500,740);*/
		fillrectangle(40 * width, 40 * height - 80, 40 * width + 80, 40 * height - 40);//�����ζԽǵ�����
		fillrectangle(40 * width, 40 * height - 40, 40 * width + 80, 40 * height);//�����ζԽǵ�����
		fillrectangle(40 * width, 40 * height, 40 * width + 80, 40 * height + 40);//�����ζԽǵ�����

		setbkmode(TRANSPARENT);
		//cleardevice();//���� two
		settextstyle(40, 0, L"����");
		settextcolor(RGB(30, 30, 30));
		outtextxy(40 * width, 40 * height - 80, L"��ͣ");
		settextstyle(40, 0, L"����");
		settextcolor(RGB(30, 30, 30));
		outtextxy(40 * width, 40 * height - 40, L"����");
		settextstyle(40, 0, L"����");
		settextcolor(RGB(30, 30, 30));
		outtextxy(40 * width, 40 * height, L"�˳�");

		//��ʱ��

		if (getElapsedTime() / 1000 != 0)
		{

		}
		else if (getElapsedTime() / 100 != 0)
		{
			putimage(width * 40, 40, &imgs[getElapsedTime()/100]);
			putimage(width * 40+40, 40, &imgs[getElapsedTime() %100/10]);
			putimage(width * 40+80, 40, &imgs[getElapsedTime()%10]);

		}
		else if (getElapsedTime() / 10 != 0)
		{
			putimage(width * 40+40 , 40, &imgs[getElapsedTime()/10]);
			putimage(width * 40+80, 40, &imgs[getElapsedTime()%10]);

		}
		else
		{
			
			putimage(width*40+80, 40,&imgs[getElapsedTime()]);
		}



		//����map��ͼ

		for (int i = 0; i < height; i++)
		{
			for (int k = 0; k < width; k++)
			{
				if (revealed[i][k])
				{
					if (map[i][k] >= 0 && map[i][k] <= 8)
					{
						putimage(k * 40, i * 40 + 40, &imgs[map[i][k]]);

					}
					else if (map[i][k] == -1)
					{
						putimage(k * 40, i * 40 + 40, &imgs[9]);
					}

				}
				else if (!revealed[i][k] && !flagged[i][k])
				{
					putimage(k * 40, i * 40 + 40, &imgs[10]);
				}
				else if (!revealed[i][k] && flagged[i][k])
				{
					putimage(k * 40, i * 40 + 40, &imgs[11]);
				}
			}
		}
		FlushBatchDraw();
	}
	EndBatchDraw();
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
		// ������Ϸ���룬������Ҽ���ǡ���ͣ��
	static ExMessage maeMsg;
	
	ExMessage msg;
	if (!peekmessage(&msg, EM_MOUSE))
	{
		msg = maeMsg;
		msg.message = WM_MOUSEMOVE;
	}
	else
	{
		maeMsg = msg;
	}
	
		
		int r = msg.y / 40 - 1;
		int c = msg.x / 40;
		/*printf("%d %d",c,r);*/
		
		//��ͣ
		if ((c==width||c == width+1)&&r==height-3)
		{
			/*printf("YELLOW");*/
			setfillcolor(YELLOW);//����ǰ��ť��Ϊ��ɫ
			settextstyle(41, 0, L"����");
		}
		else
		{
			/*printf("WHITE");*/
			setfillcolor(WHITE);
			settextstyle(40, 0, L"����");
		}
		fillrectangle(40 * width, 40 * height - 80, 40 * width + 80, 40 * height - 40);//�����ζԽǵ�����
		outtextxy(40 * width, 40 * height - 80, L"��ͣ");//�������ֵ�λ��
		FlushBatchDraw();
		
		//����
		if ((c == width || c == width + 1) && r == height - 2)
		{
			/*printf("YELLOW");*/
			setfillcolor(YELLOW);//����ǰ��ť��Ϊ��ɫ
			settextstyle(41, 0, L"����");
		}
		else
		{
			/*printf("WHITE");*/
			setfillcolor(WHITE);
			settextstyle(40, 0, L"����");
		}
		fillrectangle(40 * width, 40 * height - 40, 40 * width + 80, 40 * height);//�����ζԽǵ�����
		outtextxy(40 * width, 40 * height - 40, L"����");//�������ֵ�λ��
		FlushBatchDraw();
		

		//�˳�
		if ((c == width || c == width + 1) && r == height - 1)
		{
			/*printf("YELLOW");*/
			setfillcolor(YELLOW);//����ǰ��ť��Ϊ��ɫ
			settextstyle(41, 0, L"����");
		}
		else
		{
			/*printf("WHITE");*/
			setfillcolor(WHITE);
			settextstyle(40, 0, L"����");
		}
		fillrectangle(40 * width, 40 * height, 40 * width + 80, 40 * height+40);//�����ζԽǵ�����
		outtextxy(40 * width, 40 * height, L"�˳�");//�������ֵ�λ��
		FlushBatchDraw();


		switch (msg.message)
		{
		case WM_LBUTTONDOWN:
			//���������map��
			if (r >= 0 && r < height && c >= 0 && c < width)
			{
				if (!flagged[r][c])
				{
					if (!revealed[r][c])
					{
						openCell(r, c);
						//�жϽ���
						endGame();
					}
				}
			}
			//��������
			else
			{
				if ((c == width + 1 || c == width) && r == height - 3)
				{
					//��ͣ
					pauseGame();
				}
				if ((c == width + 1 || c == width) && r == height - 2)
				{
					//����
					handleSettingsInput();
				}
				if ((c == width + 1 || c == width) && r == height - 1)
				{
					//�˳���Ϸ
					/*exit(0);*/
					/*cleardevice();*/
					handleMenuInput();
				}
			}


			break;
		case WM_RBUTTONDOWN:
			if (!flagged[r][c])
			{
				mciSendString(_T("open ./music/rightclick.mp3 alias click0"), NULL, 0, NULL);
				mciSendString(_T("play click0"), NULL, 0, NULL);
				flagged[r][c] = 1;
			}
			else if (flagged)
			{
				flagged[r][c] = 0;
			}
			break;
		}
	

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
	cleardevice();
	IMAGE img_victory;
	loadimage(&img_victory, L"ɨ��ʤ������ͼ��/ɨ��ʤ������.png", 1000, 750);  // ʹ��Lǰ׺֧��Unicode·��
	Button* resetgame = new Button(413, 365, 141, 95, WHITE, L"����һ��");  // ʹ��wstring֧��Unicode
	Button* startmenu = new Button(413, 520, 141, 95, WHITE, L"���ز˵�");  // ʹ��wstring֧��Unicode
	Button* close = new Button(849, 634, 102, 73, WHITE, L"�� ��");  // ʹ��wstring֧��Unicode
	while (1)
	{
		BeginBatchDraw();
		putimage(0, 0, &img_victory);
		resetgame->drawbutton();
		startmenu->drawbutton();
		close->drawbutton();
		MOUSEMSG m = GetMouseMsg();
		if (resetgame->clickbutton(m))
		{
			
			drawGameBoard();
		}
		if (startmenu->clickbutton(m))
		{
			
			handleMenuInput();
		}
		if (close->clickbutton(m))
		{
			
			exit(0);
		}
		//��ʾʱ��
		wchar_t str[32];
		wsprintf(str, _T(" %d seconds"), timer);
		settextstyle(30, 0, _T("΢���ź�"));
		outtextxy(90, 118, str);
		Sleep(1000);
		
		EndBatchDraw();
	}
	
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
	cleardevice();
	IMAGE img_victory;
	loadimage(&img_victory, L"ɨ��ʤ������ͼ��/ɨ��ʤ������.png", 1000, 750);  // ʹ��Lǰ׺֧��Unicode·��
	IMAGE img_Over;
	loadimage(&img_Over, L"ɨ��ʤ������ͼ��/ʧ��.png", 440, 210);  // ʹ��Lǰ׺֧��Unicode·��
	Button* resetgame = new Button(413, 365, 141, 95, WHITE, L"����һ��");  // ʹ��wstring֧��Unicode
	Button* startmenu = new Button(413, 520, 141, 95, WHITE, L"���ز˵�");  // ʹ��wstring֧��Unicode
	Button* close = new Button(849, 634, 102, 73, WHITE, L" �� ��");  // ʹ��wstring֧��Unicode
	while (1)
	{
		BeginBatchDraw();
		putimage(0, 0, &img_victory);
		putimage(250, 130, &img_Over);
		resetgame->drawbutton();
		startmenu->drawbutton();
		close->drawbutton();
		MOUSEMSG m = GetMouseMsg();
		if (resetgame->clickbutton(m))
		{
			
			drawGameBoard();
		}
		if (startmenu->clickbutton(m))
		{
			
			handleMenuInput();
		}
		if (close->clickbutton(m))
		{
			
			exit(0);
		}
	
		EndBatchDraw();
	}
}

/*
    �����ˣ�chouchou
    ���ܣ��������
        1.��ʾ��Ϸ����
*/
void ruleIntroduction() 
{
	
	cleardevice();
	setbkcolor(WHITE);
	cleardevice();

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
	
	outtextxy(20, 20, L"����");
	while (1)
		if (MouseHit())
		{
			MOUSEMSG msg = GetMouseMsg();
			if (msg.x > 0 && msg.x < 100 && msg.y>0 && msg.y < 65 && msg.uMsg == WM_LBUTTONDOWN)       //����Żذ�ť�����ҳ�����ݣ������˺���
			{
				cleardevice();
				return;
			}
		}
}


/*
    �����ˣ�chouchou
    ���ܣ�С�����
        1.��ʾС�����
*/
void groupPresentation() 
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

	outtextxy(20, 20, L"����");
	while (1)
	{
		if (MouseHit())
		{
			MOUSEMSG msg = GetMouseMsg();
			if (msg.x > 0 && msg.x < 100 && msg.y>0 && msg.y < 65 && msg.uMsg == WM_LBUTTONDOWN)       //����Żذ�ť�����ҳ�����ݣ������˺���
			{
				cleardevice();
				return;
			}
		}
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

	settextstyle(50, 0, L"����");  // ʹ�ÿ��ַ�ָ������
	setbkmode(TRANSPARENT);
	settextcolor(RGB(256, 256, 256));

	wchar_t Title[100] = L"����";  // ʹ�ÿ��ַ��ַ���
	int widthTitle = 1000 / 2 - textwidth(Title) / 2;
	outtextxy(widthTitle, 30, Title);

	settextstyle(20, 0, L"����");
	wchar_t group[100] = L"�������Ͻ�����";  // ʹ�ÿ��ַ��ַ���
	outtextxy(835, 705, group);

	setfillcolor(LIGHTGRAY);
	settextstyle(40, 0, L"����");
	wchar_t music[100] = L"����";  // ʹ�ÿ��ַ��ַ���
	rectangle(400, 145, 600, 205);
	fillrectangle(400, 145, 600, 205);
	wchar_t musicopen[100] = L"��";  // ʹ�ÿ��ַ��ַ���
	rectangle(400, 210, 600, 270);
	fillrectangle(400, 210, 600, 270);
	wchar_t musicclose[100] = L"��";  // ʹ�ÿ��ַ��ַ���
	outtextxy(460, 90, music);
	outtextxy(480, 153, musicopen);
	outtextxy(480, 220, musicclose);

	settextstyle(40, 0, L"����");
	wchar_t soundeffect[100] = L"��Ч";  // ʹ�ÿ��ַ��ַ���
	rectangle(400, 340, 600, 400);
	fillrectangle(400, 340, 600, 400);
	wchar_t soundeffectopen[100] = L"��";  // ʹ�ÿ��ַ��ַ���
	rectangle(400, 405, 600, 465);
	fillrectangle(400, 405, 600, 465);
	wchar_t soundeffectclose[100] = L"��";  // ʹ�ÿ��ַ��ַ���
	//rectangle(400, 470, 600, 530);
	//fillrectangle(400, 470, 600, 530);
	//wchar_t bkmusic1[100] = L"��������";  // ʹ�ÿ��ַ��ַ���
	//rectangle(400, 535, 600, 595);
	//fillrectangle(400, 535, 600, 595);
	//wchar_t bkmusic2[100] = L"��������2";  // ʹ�ÿ��ַ��ַ���
	//rectangle(400, 600, 600, 660);
	//fillrectangle(400, 600, 600, 660);
	//wchar_t bkmusic3[100] = L"��������3";  // ʹ�ÿ��ַ��ַ���
	outtextxy(460, 295, soundeffect);
	outtextxy(480, 350, soundeffectopen);
	outtextxy(480, 415, soundeffectclose);
	//outtextxy(410, 480, bkmusic1);
	//outtextxy(410, 545, bkmusic2);
	//outtextxy(410, 610, bkmusic3);

	rectangle(36, 660, 160, 714);
	fillrectangle(36, 660, 160, 714);
	settextstyle(35, 0, L"����");
	wchar_t back[100] = L"����";  // ʹ�ÿ��ַ��ַ���
	outtextxy(63, 670, back);
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
	drawSettingsMenu();
	while (1)
	{
		BeginBatchDraw();//�е���������һ��˫����
		MOUSEMSG m = GetMouseMsg();

		//��
		if (m.x >= 400 && m.x <= 600 && m.y > 145 && m.y <= 205)
		{
			setfillcolor(YELLOW);//����ǰ��ť��Ϊ��ɫ
			settextstyle(41, 0, L"����");
			fillrectangle(400, 145, 600, 205);//�����ζԽǵ�����
			outtextxy(480, 153, L"��");//�������ֵ�λ��
			if (m.uMsg == WM_LBUTTONDOWN)//�����������
			{
				musicOn = true;
				Music();
			}
		}
		else
		{
			setfillcolor(WHITE);
			settextstyle(40, 0, L"����");
			fillrectangle(400, 145, 600, 205);//�����ζԽǵ�����
			outtextxy(480, 153, L"��");
		}

		//��
		if (m.x >= 400 && m.x <= 600 && m.y > 210 && m.y <= 270)
		{
			setfillcolor(YELLOW);
			settextstyle(41, 0, L"����");
			fillrectangle(400, 210, 600, 270);
			outtextxy(480, 220, L"��");
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				musicOn = false;
				Music();
			}
		}
		else
		{
			setfillcolor(WHITE);
			settextstyle(40, 0, L"����");
			fillrectangle(400, 210, 600, 270);
			outtextxy(480, 220, L"��");
		}
		//��
		if (m.x >= 400 && m.x <= 600 && m.y > 340 && m.y <= 400)
		{
			setfillcolor(YELLOW);//����ǰ��ť��Ϊ��ɫ
			settextstyle(41, 0, L"����");
			fillrectangle(400, 340, 600, 400);
			outtextxy(480, 350, L"��");
			if (m.uMsg == WM_LBUTTONDOWN)//�����������
			{
				playSoundEffectOn = true;
				playSoundEffect();
			}
		}
		else
		{
			setfillcolor(WHITE);
			settextstyle(40, 0, L"����");
			fillrectangle(400, 340, 600, 400);
			outtextxy(480, 350, L"��");
		}

		//��
		if (m.x >= 400 && m.x <= 600 && m.y > 405 && m.y <= 465)
		{
			setfillcolor(YELLOW);
			settextstyle(41, 0, L"����");
			fillrectangle(400, 405, 600, 465);
			outtextxy(480, 415, L"��");
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				playSoundEffectOn = false;
				playSoundEffect();
			}
		}
		else
		{
			setfillcolor(WHITE);
			settextstyle(40, 0, L"����");
			fillrectangle(400, 405, 600, 465);
			outtextxy(480, 415, L"��");
		}


		//�˳���Ϸ
		if (m.x >= 36 && m.x <= 160 && m.y >= 660 && m.y <= 714)
		{
			setfillcolor(YELLOW);
			settextstyle(41, 0, L"����");
			fillrectangle(36, 660, 160, 714);
			outtextxy(63, 670, L"����");
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				return;
			}
		}
		else
		{
			setfillcolor(WHITE);
			settextstyle(40, 0, L"����");
			fillrectangle(36, 660, 160, 714);
			outtextxy(63, 670, L"����");
		}

		EndBatchDraw();
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

	// ��ʾ��ʷ��¼��ǩ
	settextstyle(30, 0, L"����");
	settextcolor(RED);
	wstring historyLabel = L"��ʷ��¼";  // ʹ�� Unicode �ַ���
	outtextxy(450, 75, historyLabel.c_str());

	// ��ʾ���б�ǩ
	settextcolor(BLACK);
	settextstyle(30, 0, L"����");
	wstring timeLabel = L"��Ϸ��ʱ/s";
	wstring resultLabel = L"ʤ��";
	outtextxy(285, 135, timeLabel.c_str());
	outtextxy(630, 135, resultLabel.c_str());

	// ��ʾ��һҳ����һҳ
	wstring prevPage = L"��һҳ";
	wstring nextPage = L"��һҳ";
	outtextxy(390, 640, prevPage.c_str());
	outtextxy(500, 640, nextPage.c_str());

	// ��ʾ����
	wstring backLabel = L"����";
	outtextxy(10, 10, backLabel.c_str());

	// ��ʾҳ��
	int pagination = (n / 9) + 1;
	int nowPagination = vernier_n / 9 + 1;
	wstring paginationStr1 = to_wstring(pagination);
	wstring paginationStr2 = to_wstring(nowPagination);
	outtextxy(925, 700, paginationStr2.c_str());
	outtextxy(945, 700, L"/");
	outtextxy(965, 700, paginationStr1.c_str());
}





