#include "view.h"
#include "data.h"
#include "game_logic.h"
#include "settings.h"




/*
	负责人: Su bak
	功能: 绘制开始界面
		1. 显示游戏标题
		2. 显示菜单选项（开始游戏、游戏设置、规则介绍、团队展示、退出游戏）
		3. 根据用户选择更新界面
	参数: void
	返回值: void
*/
void drawStartMenu()
{

	//initgraph(1000, 750);
	setbkcolor(WHITE);
	cleardevice();//清屏 two
	settextstyle(70, 0, L"文华新魏");
	settextcolor(RGB(30, 30, 30));
	outtextxy(410, 50, L"扫雷");
	settextstyle(35, 0, L"楷体");
	settextcolor(RGB(30, 30, 30));
	outtextxy(360, 130, L"量子码韵交响团");

	//长方形和圆的按键初始化
	setfillcolor(WHITE);//填充按钮的颜色
	settextstyle(40, 0, L"楷体");// 宽度  高度 字体
	setlinecolor(BLACK);//设置线的颜色
	settextcolor(BLACK);//设置文字的颜色
	setlinestyle(PS_SOLID, 2);//设置线是实线还是虚线 5是指线的宽度
	setbkmode(TRANSPARENT);//将文字的背景去掉

	//开始游戏

	fillrectangle(350, 270, 600, 320);//传矩形对角的坐标
	outtextxy(350 + 50, 270 + 10, L"开始游戏");//设置文字的位置

	//设置
	fillrectangle(350, 370, 600, 420);//传矩形对角的坐标
	outtextxy(350 + 50, 370 + 10, L"游戏设置");//设置文字的位置

	//历史记录
	fillrectangle(350, 470, 600, 520);//传矩形对角的坐标
	outtextxy(350 + 50, 470 + 10, L"历史记录");//设置文字的位置

	//退出游戏
	fillrectangle(350, 570, 600, 620);//传矩形对角的坐标
	outtextxy(350 + 50, 570 + 10, L"退出游戏");//设置文字的位置

	//简单
	settextstyle(35, 0, L"楷体");
	fillcircle(320, 200, 35);//X,Y（圆心位置）圆的半径  
	outtextxy(320 - 20, 200 - 30, L"简");//设置文字的位置
	outtextxy(320 - 20, 200 + 5, L"单");//设置文字的位置

	//普通
	fillcircle(470, 200, 35);
	outtextxy(470 - 20, 200 - 30, L"普");//设置文字的位置
	outtextxy(470 - 20, 200 + 5, L"通");//设置文字的位置

	//困难
	fillcircle(620, 200, 35);
	outtextxy(620 - 20, 200 - 30, L"困");//设置文字的位置
	outtextxy(620 - 20, 200 + 5, L"难");//设置文字的位置

	//规则介绍
	fillcircle(850, 700, 35);
	settextstyle(24, 0, L"楷体");
	outtextxy(850 - 20, 700 - 20, L"规则");//设置文字的位置
	outtextxy(850 - 20, 700 + 5, L"介绍");//设置文字的位置

	//小组简介
	fillcircle(950, 700, 35);
	settextstyle(24, 0, L"楷体");
	outtextxy(950 - 20, 700 - 20, L"小组");//设置文字的位置
	outtextxy(950 - 20, 700 + 5, L"简介");//设置文字的位置



}


/*
	负责人: Su bak
	功能: 处理菜单输入
		1. 监听用户按键
		2. 根据按键选择菜单项，跳转到相应功能
	参数: void
	返回值: void
*/
void handleMenuInput()
{
	drawStartMenu();
	while (1)
	{
		BeginBatchDraw();//有点闪屏，加一个双缓冲
		MOUSEMSG m = GetMouseMsg();

		//开始游戏
		if (m.x >= 350 && m.x <= 600 && m.y > 270 && m.y <= 320)
		{
			setfillcolor(YELLOW);//将当前按钮改为黄色
			settextstyle(41, 0, L"楷体");
			fillrectangle(350, 270, 600, 320);//传矩形对角的坐标
			outtextxy(350 + 50, 270 + 10, L"开始游戏");//设置文字的位置
			if (m.uMsg == WM_LBUTTONDOWN)//当左键被按下
			{
				cleardevice();
				EndBatchDraw();
				drawGameBoard();//打开游戏界面
				drawStartMenu();
			}
		}
		else
		{
			setfillcolor(WHITE);
			settextstyle(40, 0, L"楷体");
			fillrectangle(350, 270, 600, 320);
			outtextxy(350 + 50, 270 + 10, L"开始游戏");
		}

		//设置
		if (m.x >= 350 && m.x <= 600 && m.y > 370 && m.y <= 420)
		{
			setfillcolor(YELLOW);
			settextstyle(41, 0, L"楷体");
			fillrectangle(350, 370, 600, 420);
			outtextxy(350 + 50, 370 + 10, L"游戏设置");
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				cleardevice();
				EndBatchDraw();
				handleSettingsInput();//打开设置界面
				drawStartMenu();
			}
		}
		else
		{
			setfillcolor(WHITE);
			settextstyle(40, 0, L"楷体");
			fillrectangle(350, 370, 600, 420);
			outtextxy(350 + 50, 370 + 10, L"游戏设置");
		}

		//历史记录
		if (m.x >= 350 && m.x <= 600 && m.y > 470 && m.y <= 520)
		{
			setfillcolor(YELLOW);
			settextstyle(41, 0, L"楷体");
			fillrectangle(350, 470, 600, 520);
			outtextxy(350 + 50, 470 + 10, L"历史记录");
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				cleardevice();
				EndBatchDraw();
				displayHistory();  // 绘制历史记录界面
				drawStartMenu();
			}
		}
		else
		{
			setfillcolor(WHITE);
			settextstyle(40, 0, L"楷体");
			fillrectangle(350, 470, 600, 520);
			outtextxy(350 + 50, 470 + 10, L"历史记录");
		}

		//退出游戏
		if (m.x >= 350 && m.x <= 570 && m.y > 600 && m.y <= 620)
		{
			setfillcolor(YELLOW);
			settextstyle(41, 0, L"楷体");
			fillrectangle(350, 570, 600, 620);
			outtextxy(350 + 50, 570 + 10, L"退出游戏");
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				return;
			}
		}
		else
		{
			setfillcolor(WHITE);
			settextstyle(40, 0, L"楷体");
			fillrectangle(350, 570, 600, 620);
			outtextxy(350 + 50, 570 + 10, L"退出游戏");
		}

		//简单
		if (sqrt((m.x - 320) * (m.x - 320) + (m.y - 200) * (m.y - 200)) <= 35)
		{
			settextstyle(30, 0, L"楷体");
			if (m.uMsg == WM_LBUTTONDOWN)//按下左键将难度设置为简单
			{
				setfillcolor(YELLOW);
				fillcircle(320, 200, 35);//X,Y（圆心位置）圆的半径  
				outtextxy(320 - 20, 200 - 30, L"简");//设置文字的位置
				outtextxy(320 - 20, 200 + 5, L"单");//设置文字的位置

				//简单难度设置
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
					settextstyle(35, 0, L"楷体");
					fillcircle(320, 200, 35);
					outtextxy(320 - 20, 200 - 30, L"简");
					outtextxy(320 - 20, 200 + 5, L"单");
				}
			}

		}

		//普通
		if (sqrt((m.x - 470) * (m.x - 470) + (m.y - 200) * (m.y - 200)) <= 35)
		{
			settextstyle(30, 0, L"楷体");
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				setfillcolor(YELLOW);
				fillcircle(470, 200, 35);
				outtextxy(470 - 20, 200 - 30, L"普");
				outtextxy(470 - 20, 200 + 5, L"通");

				//普通难度设置
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
					settextstyle(35, 0, L"楷体");
					setfillcolor(WHITE);
					fillcircle(470, 200, 35);
					outtextxy(470 - 20, 200 - 30, L"普");
					outtextxy(470 - 20, 200 + 5, L"通");
				}
			}
		}

		//困难
		if (sqrt((m.x - 620) * (m.x - 620) + (m.y - 200) * (m.y - 200)) <= 35)
		{
			settextstyle(30, 0, L"楷体");
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				setfillcolor(YELLOW);
				fillcircle(620, 200, 35);
				outtextxy(620 - 20, 200 - 30, L"困");
				outtextxy(620 - 20, 200 + 5, L"难");

				//困难难度设置
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
					settextstyle(35, 0, L"楷体");
					setfillcolor(WHITE);
					fillcircle(620, 200, 35);
					outtextxy(620 - 20, 200 - 30, L"困");
					outtextxy(620 - 20, 200 + 5, L"难");
				}
			}
		}

		//规则介绍
		if (sqrt((m.x - 850) * (m.x - 850) + (m.y - 700) * (m.y - 700)) <= 35)
		{
			setfillcolor(YELLOW);
			settextstyle(25, 0, L"楷体");
			fillcircle(850, 700, 35);
			outtextxy(850 - 20, 700 - 20, L"规则");//设置文字的位置
			outtextxy(850 - 20, 700 + 5, L"介绍");//设置文字的位置
			if (m.uMsg == WM_LBUTTONDOWN)//当左键被按下
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
			settextstyle(24, 0, L"楷体");
			fillcircle(850, 700, 35);
			outtextxy(850 - 20, 700 - 20, L"规则");
			outtextxy(850 - 20, 700 + 5, L"介绍");
		}

		//小组简介
		if (sqrt((m.x - 950) * (m.x - 950) + (m.y - 700) * (m.y - 700)) <= 35)
		{
			setfillcolor(YELLOW);
			settextstyle(25, 0, L"楷体");
			fillcircle(950, 700, 35);
			outtextxy(950 - 20, 700 - 20, L"小组");
			outtextxy(950 - 20, 700 + 5, L"简介");

			if (m.uMsg == WM_LBUTTONDOWN)//当左键被按下
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
			settextstyle(24, 0, L"楷体");
			fillcircle(950, 700, 35);
			settextstyle(24, 0, L"楷体");
			outtextxy(950 - 20, 700 - 20, L"小组");
			outtextxy(950 - 20, 700 + 5, L"简介");

		}
		EndBatchDraw();
	}


}

/*
    负责人: 耶格尔
    功能: 绘制游戏界面
        1. 显示游戏地图
        2. 根据游戏状态（是否暂停、是否游戏结束）显示相关信息
        3. 显示计时器
        4. 剩余可标记格子数
        5. 剩余未打开格子数（不包括已标记格子）
    参数: void
    返回值: void
*/
void drawGameBoard()
{
	// 绘制游戏主界面
	// 绘制格子和已翻开的数字、雷标记等
	initGame();   //初始化
	startTimer();  // 启动计时器
	bool isPause = 0;
	IMAGE imgs[13];

	for (int i = 0; i <= 8; i++) {
		WCHAR fileName[20] = { 0 };
		wsprintf(fileName, _T("./source/提示数-%d.png"), i);
		loadimage(imgs + i, fileName, 40, 40);
	}
	loadimage(imgs + 9, _T("./source/雷点.png"), 40, 40);
	loadimage(imgs + 10, _T("./source/未打开格子.png"), 40, 40);
	loadimage(imgs + 11, _T("./source/旗帜.png"), 40, 40);
	loadimage(imgs + 12, _T("./source/倒计时.png"), 80, 40);


	//主循环
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



		//长方形按键初始化
		setfillcolor(WHITE);//填充按钮的颜色
		settextstyle(40, 0, L"楷体");// 宽度  高度 字体
		setlinecolor(BLACK);//设置线的颜色
		settextcolor(BLACK);//设置文字的颜色
		setlinestyle(PS_SOLID, 2);//设置线是实线还是虚线
		setbkmode(TRANSPARENT);//将文字的背景去掉

		//矩形
		/*fillrectangle(440, 440, 500,740);*/
		fillrectangle(40 * width, 40 * height - 80, 40 * width + 80, 40 * height - 40);//传矩形对角的坐标
		fillrectangle(40 * width, 40 * height - 40, 40 * width + 80, 40 * height);//传矩形对角的坐标
		fillrectangle(40 * width, 40 * height, 40 * width + 80, 40 * height + 40);//传矩形对角的坐标

		setbkmode(TRANSPARENT);
		//cleardevice();//清屏 two
		settextstyle(40, 0, L"楷体");
		settextcolor(RGB(30, 30, 30));
		outtextxy(40 * width, 40 * height - 80, L"暂停");
		settextstyle(40, 0, L"楷体");
		settextcolor(RGB(30, 30, 30));
		outtextxy(40 * width, 40 * height - 40, L"设置");
		settextstyle(40, 0, L"楷体");
		settextcolor(RGB(30, 30, 30));
		outtextxy(40 * width, 40 * height, L"退出");

		//计时器

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



		//根据map贴图

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
    负责人: 耶格尔
    功能: 处理游戏界面输入
        1. 监听用户的点击或键盘输入（如暂停游戏、翻开格子等）
        2. 根据输入更新游戏状态
    参数: void
    返回值: void
*/
void handleGameInput()
{
	// 处理游戏输入，点击、右键标记、暂停等
		// 处理游戏输入，点击、右键标记、暂停等
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
		
		//暂停
		if ((c==width||c == width+1)&&r==height-3)
		{
			/*printf("YELLOW");*/
			setfillcolor(YELLOW);//将当前按钮改为黄色
			settextstyle(41, 0, L"楷体");
		}
		else
		{
			/*printf("WHITE");*/
			setfillcolor(WHITE);
			settextstyle(40, 0, L"楷体");
		}
		fillrectangle(40 * width, 40 * height - 80, 40 * width + 80, 40 * height - 40);//传矩形对角的坐标
		outtextxy(40 * width, 40 * height - 80, L"暂停");//设置文字的位置
		FlushBatchDraw();
		
		//设置
		if ((c == width || c == width + 1) && r == height - 2)
		{
			/*printf("YELLOW");*/
			setfillcolor(YELLOW);//将当前按钮改为黄色
			settextstyle(41, 0, L"楷体");
		}
		else
		{
			/*printf("WHITE");*/
			setfillcolor(WHITE);
			settextstyle(40, 0, L"楷体");
		}
		fillrectangle(40 * width, 40 * height - 40, 40 * width + 80, 40 * height);//传矩形对角的坐标
		outtextxy(40 * width, 40 * height - 40, L"设置");//设置文字的位置
		FlushBatchDraw();
		

		//退出
		if ((c == width || c == width + 1) && r == height - 1)
		{
			/*printf("YELLOW");*/
			setfillcolor(YELLOW);//将当前按钮改为黄色
			settextstyle(41, 0, L"楷体");
		}
		else
		{
			/*printf("WHITE");*/
			setfillcolor(WHITE);
			settextstyle(40, 0, L"楷体");
		}
		fillrectangle(40 * width, 40 * height, 40 * width + 80, 40 * height+40);//传矩形对角的坐标
		outtextxy(40 * width, 40 * height, L"退出");//设置文字的位置
		FlushBatchDraw();


		switch (msg.message)
		{
		case WM_LBUTTONDOWN:
			//按键如果在map中
			if (r >= 0 && r < height && c >= 0 && c < width)
			{
				if (!flagged[r][c])
				{
					if (!revealed[r][c])
					{
						openCell(r, c);
						//判断结束
						endGame();
					}
				}
			}
			//其他操作
			else
			{
				if ((c == width + 1 || c == width) && r == height - 3)
				{
					//暂停
					pauseGame();
				}
				if ((c == width + 1 || c == width) && r == height - 2)
				{
					//设置
					handleSettingsInput();
				}
				if ((c == width + 1 || c == width) && r == height - 1)
				{
					//退出游戏
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
    负责人: 安辞
    功能: 绘制胜利界面
        1. 显示游戏胜利信息
    参数: void
    返回值: void
*/
void drawVictoryScreen()
{
	cleardevice();
	IMAGE img_victory;
	loadimage(&img_victory, L"扫雷胜利界面图标/扫雷胜利界面.png", 1000, 750);  // 使用L前缀支持Unicode路径
	Button* resetgame = new Button(413, 365, 141, 95, WHITE, L"再来一次");  // 使用wstring支持Unicode
	Button* startmenu = new Button(413, 520, 141, 95, WHITE, L"返回菜单");  // 使用wstring支持Unicode
	Button* close = new Button(849, 634, 102, 73, WHITE, L"退 出");  // 使用wstring支持Unicode
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
		//显示时长
		wchar_t str[32];
		wsprintf(str, _T(" %d seconds"), timer);
		settextstyle(30, 0, _T("微软雅黑"));
		outtextxy(90, 118, str);
		Sleep(1000);
		
		EndBatchDraw();
	}
	
}


/*
    负责人: 安辞
    功能: 绘制结算界面
        1. 显示游戏结束信息，提供重新开始或退出的选项
    参数: void
    返回值: void
*/
void drawGameOverScreen()
{
	cleardevice();
	IMAGE img_victory;
	loadimage(&img_victory, L"扫雷胜利界面图标/扫雷胜利界面.png", 1000, 750);  // 使用L前缀支持Unicode路径
	IMAGE img_Over;
	loadimage(&img_Over, L"扫雷胜利界面图标/失败.png", 440, 210);  // 使用L前缀支持Unicode路径
	Button* resetgame = new Button(413, 365, 141, 95, WHITE, L"再来一次");  // 使用wstring支持Unicode
	Button* startmenu = new Button(413, 520, 141, 95, WHITE, L"返回菜单");  // 使用wstring支持Unicode
	Button* close = new Button(849, 634, 102, 73, WHITE, L" 退 出");  // 使用wstring支持Unicode
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
    负责人：chouchou
    功能：规则介绍
        1.显示游戏规则
*/
void ruleIntroduction() 
{
	
	cleardevice();
	setbkcolor(WHITE);
	cleardevice();

	setlinecolor(BLACK);
	rectangle(20, 20, 980, 730);

	settextstyle(50, 0, L"楷体");  // 使用宽字符
	setbkmode(TRANSPARENT);
	settextcolor(RGB(256, 256, 256));
	wchar_t Title[100] = L"规则介绍";  // 使用宽字符
	int widthTitle = 1000 / 2 - textwidth(Title) / 2;
	outtextxy(widthTitle, 30, Title);

	settextstyle(20, 0, L"楷体");
	wchar_t group[100] = L"量子码韵交响团";  // 使用宽字符
	outtextxy(835, 705, group);

	settextstyle(30, 0, L"楷体");
	wchar_t gamegoal[100] = L"一，游戏目标";  // 使用宽字符
	outtextxy(100, 100, gamegoal);

	settextstyle(25, 0, L"楷体");
	wchar_t gamegoalcontent[100] = L"找出所有地雷并标记，同时安全地打开所有非地雷方块。";  // 使用宽字符
	outtextxy(100, 140, gamegoalcontent);

	settextstyle(30, 0, L"楷体");
	wchar_t gameelement[100] = L"二，游戏元素";  // 使用宽字符
	outtextxy(100, 180, gameelement);

	settextstyle(25, 0, L"楷体");
	wchar_t gameelementcontentA[100] = L"方块：游戏中可以打开的格子，内部可能包含地雷或其他数字。";  // 使用宽字符
	wchar_t gameelementcontentBa[100] = L"数字：表示该方块周围（3*3区域，边块为5个格子，角块为3个格子）";  // 使用宽字符
	wchar_t gameelementcontentBb[100] = L"地雷的数量。";  // 使用宽字符
	wchar_t gameelementcontentC[100] = L"标记：用于标识地雷的旗子，玩家可以通过右键点击方块来标记地雷。";  // 使用宽字符
	wchar_t gameelementcontentD[100] = L"地雷：游戏的核心元素，玩家需要避免翻开这些方块。";  // 使用宽字符
	outtextxy(100, 220, gameelementcontentA);
	outtextxy(100, 250, gameelementcontentBa);
	outtextxy(100, 280, gameelementcontentBb);
	outtextxy(100, 310, gameelementcontentC);
	outtextxy(100, 340, gameelementcontentD);

	settextstyle(30, 0, L"楷体");
	wchar_t gameoperation[100] = L"三，基本操作";  // 使用宽字符
	outtextxy(100, 380, gameoperation);

	settextstyle(25, 0, L"楷体");
	wchar_t gameoperationcontentAa[100] = L"左键单击：打开方块，如果该方块为空，则显示数字或继续递归打开";  // 使用宽字符
	wchar_t gameoperationcontentAb[100] = L"相邻的空方块；如果翻开地雷，则游戏结束。";  // 使用宽字符
	outtextxy(100, 420, gameoperationcontentAa);
	outtextxy(100, 450, gameoperationcontentAb);

	wchar_t gameoperationcontentBa[100] = L"右键单击：标记地雷，插上小红旗。再次右键单击可以取消标记（如";  // 使用宽字符
	wchar_t gameoperationcontentBb[100] = L"果在游戏菜单中勾选了“标记(?)”，则需要两次操作来取消标雷）。";  // 使用宽字符
	outtextxy(100, 480, gameoperationcontentBa);
	outtextxy(100, 510, gameoperationcontentBb);

	wchar_t gameoperationcontentCa[100] = L"双击：当双击位置周围已标记的地雷数量等于该位置数字时，双击可";  // 使用宽字符
	wchar_t gameoperationcontentCb[100] = L"以打开该数字周围所有未标记的方块。如果标记错误，则双击后打开";  // 使用宽字符
	wchar_t gameoperationcontentCc[100] = L"的方块中必有地雷，游戏结束。";  // 使用宽字符
	outtextxy(100, 540, gameoperationcontentCa);
	outtextxy(100, 570, gameoperationcontentCb);
	outtextxy(100, 600, gameoperationcontentCc);
	
	outtextxy(20, 20, L"返回");
	while (1)
		if (MouseHit())
		{
			MOUSEMSG msg = GetMouseMsg();
			if (msg.x > 0 && msg.x < 100 && msg.y>0 && msg.y < 65 && msg.uMsg == WM_LBUTTONDOWN)       //点击放回按钮，清除页面内容，结束此函数
			{
				cleardevice();
				return;
			}
		}
}


/*
    负责人：chouchou
    功能：小组介绍
        1.显示小组介绍
*/
void groupPresentation() 
{
	setbkcolor(WHITE);
	cleardevice();

	setlinecolor(BLACK);
	rectangle(20, 20, 980, 730);

	// 设置标题字体
	settextstyle(50, 0, L"楷体");  // 使用宽字符
	setbkmode(TRANSPARENT);
	settextcolor(RGB(256, 256, 256));

	// 显示标题
	wchar_t Title[] = L"小组简介";  // 宽字符字符串
	int widthTitle = 1000 / 2 - textwidth(Title) / 2;
	outtextxy(widthTitle, 30, Title);

	// 显示小组名称
	settextstyle(20, 0, L"楷体");
	wchar_t group[] = L"量子码韵交响团";  // 宽字符字符串
	outtextxy(835, 705, group);

	// 显示组员信息
	settextstyle(35, 0, L"楷体");

	wchar_t groupmemberA[] = L"编程界首屈一指的蛆(组长）";
	int widthgroupmemberA = 1000 / 2 - textwidth(groupmemberA) / 2;

	wchar_t groupmemberB[] = L"Su bak(副组长）";
	int widthgroupmemberB = 1000 / 2 - textwidth(groupmemberB) / 2;

	wchar_t groupmemberC[] = L"安辞（会议记录官）";
	int widthgroupmemberC = 1000 / 2 - textwidth(groupmemberC) / 2;

	wchar_t groupmemberD[] = L"雨月云（信息官）";
	int widthgroupmemberD = 1000 / 2 - textwidth(groupmemberD) / 2;

	wchar_t groupmemberE[] = L"Savior（监督官）";
	int widthgroupmemberE = 1000 / 2 - textwidth(groupmemberE) / 2;

	wchar_t groupmemberF[] = L"念（技术官）";
	int widthgroupmemberF = 1000 / 2 - textwidth(groupmemberF) / 2;

	wchar_t groupmemberG[] = L"tydddd（技术官）";
	int widthgroupmemberG = 1000 / 2 - textwidth(groupmemberG) / 2;

	wchar_t groupmemberH[] = L"耶格尔（产品经理）";
	int widthgroupmemberH = 1000 / 2 - textwidth(groupmemberH) / 2;

	wchar_t groupmemberI[] = L"CHOUCHOU（产品经理）";
	int widthgroupmemberI = 1000 / 2 - textwidth(groupmemberI) / 2;

	wchar_t groupmemberJ[] = L"恒心小学长";
	int widthgroupmemberJ = 1000 / 2 - textwidth(groupmemberJ) / 2;

	// 输出组员信息
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

	outtextxy(20, 20, L"返回");
	while (1)
	{
		if (MouseHit())
		{
			MOUSEMSG msg = GetMouseMsg();
			if (msg.x > 0 && msg.x < 100 && msg.y>0 && msg.y < 65 && msg.uMsg == WM_LBUTTONDOWN)       //点击放回按钮，清除页面内容，结束此函数
			{
				cleardevice();
				return;
			}
		}
	}
}

/*
    负责人: chouchou
    功能: 绘制游戏设置界面
        1. 显示当前难度和音乐设置
        2. 提供难度和音乐开关选项
    参数: void
    返回值: void
*/
void drawSettingsMenu() 
{
	setbkcolor(WHITE);
	cleardevice();

	setlinecolor(BLACK);
	rectangle(20, 20, 980, 730);

	settextstyle(50, 0, L"楷体");  // 使用宽字符指定字体
	setbkmode(TRANSPARENT);
	settextcolor(RGB(256, 256, 256));

	wchar_t Title[100] = L"设置";  // 使用宽字符字符串
	int widthTitle = 1000 / 2 - textwidth(Title) / 2;
	outtextxy(widthTitle, 30, Title);

	settextstyle(20, 0, L"楷体");
	wchar_t group[100] = L"量子码韵交响团";  // 使用宽字符字符串
	outtextxy(835, 705, group);

	setfillcolor(LIGHTGRAY);
	settextstyle(40, 0, L"楷体");
	wchar_t music[100] = L"音乐";  // 使用宽字符字符串
	rectangle(400, 145, 600, 205);
	fillrectangle(400, 145, 600, 205);
	wchar_t musicopen[100] = L"开";  // 使用宽字符字符串
	rectangle(400, 210, 600, 270);
	fillrectangle(400, 210, 600, 270);
	wchar_t musicclose[100] = L"关";  // 使用宽字符字符串
	outtextxy(460, 90, music);
	outtextxy(480, 153, musicopen);
	outtextxy(480, 220, musicclose);

	settextstyle(40, 0, L"楷体");
	wchar_t soundeffect[100] = L"音效";  // 使用宽字符字符串
	rectangle(400, 340, 600, 400);
	fillrectangle(400, 340, 600, 400);
	wchar_t soundeffectopen[100] = L"开";  // 使用宽字符字符串
	rectangle(400, 405, 600, 465);
	fillrectangle(400, 405, 600, 465);
	wchar_t soundeffectclose[100] = L"关";  // 使用宽字符字符串
	//rectangle(400, 470, 600, 530);
	//fillrectangle(400, 470, 600, 530);
	//wchar_t bkmusic1[100] = L"背景音乐";  // 使用宽字符字符串
	//rectangle(400, 535, 600, 595);
	//fillrectangle(400, 535, 600, 595);
	//wchar_t bkmusic2[100] = L"背景音乐2";  // 使用宽字符字符串
	//rectangle(400, 600, 600, 660);
	//fillrectangle(400, 600, 600, 660);
	//wchar_t bkmusic3[100] = L"背景音乐3";  // 使用宽字符字符串
	outtextxy(460, 295, soundeffect);
	outtextxy(480, 350, soundeffectopen);
	outtextxy(480, 415, soundeffectclose);
	//outtextxy(410, 480, bkmusic1);
	//outtextxy(410, 545, bkmusic2);
	//outtextxy(410, 610, bkmusic3);

	rectangle(36, 660, 160, 714);
	fillrectangle(36, 660, 160, 714);
	settextstyle(35, 0, L"楷体");
	wchar_t back[100] = L"返回";  // 使用宽字符字符串
	outtextxy(63, 670, back);
}

/*
    负责人: chouchou
    功能: 处理设置界面输入
        1. 监听用户在设置界面的选择（难度、音乐开关）
    参数: void
    返回值: void
*/
void handleSettingsInput() 
{
	drawSettingsMenu();
	while (1)
	{
		BeginBatchDraw();//有点闪屏，加一个双缓冲
		MOUSEMSG m = GetMouseMsg();

		//开
		if (m.x >= 400 && m.x <= 600 && m.y > 145 && m.y <= 205)
		{
			setfillcolor(YELLOW);//将当前按钮改为黄色
			settextstyle(41, 0, L"楷体");
			fillrectangle(400, 145, 600, 205);//传矩形对角的坐标
			outtextxy(480, 153, L"开");//设置文字的位置
			if (m.uMsg == WM_LBUTTONDOWN)//当左键被按下
			{
				musicOn = true;
				Music();
			}
		}
		else
		{
			setfillcolor(WHITE);
			settextstyle(40, 0, L"楷体");
			fillrectangle(400, 145, 600, 205);//传矩形对角的坐标
			outtextxy(480, 153, L"开");
		}

		//关
		if (m.x >= 400 && m.x <= 600 && m.y > 210 && m.y <= 270)
		{
			setfillcolor(YELLOW);
			settextstyle(41, 0, L"楷体");
			fillrectangle(400, 210, 600, 270);
			outtextxy(480, 220, L"关");
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				musicOn = false;
				Music();
			}
		}
		else
		{
			setfillcolor(WHITE);
			settextstyle(40, 0, L"楷体");
			fillrectangle(400, 210, 600, 270);
			outtextxy(480, 220, L"关");
		}
		//开
		if (m.x >= 400 && m.x <= 600 && m.y > 340 && m.y <= 400)
		{
			setfillcolor(YELLOW);//将当前按钮改为黄色
			settextstyle(41, 0, L"楷体");
			fillrectangle(400, 340, 600, 400);
			outtextxy(480, 350, L"开");
			if (m.uMsg == WM_LBUTTONDOWN)//当左键被按下
			{
				playSoundEffectOn = true;
				playSoundEffect();
			}
		}
		else
		{
			setfillcolor(WHITE);
			settextstyle(40, 0, L"楷体");
			fillrectangle(400, 340, 600, 400);
			outtextxy(480, 350, L"开");
		}

		//关
		if (m.x >= 400 && m.x <= 600 && m.y > 405 && m.y <= 465)
		{
			setfillcolor(YELLOW);
			settextstyle(41, 0, L"楷体");
			fillrectangle(400, 405, 600, 465);
			outtextxy(480, 415, L"关");
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				playSoundEffectOn = false;
				playSoundEffect();
			}
		}
		else
		{
			setfillcolor(WHITE);
			settextstyle(40, 0, L"楷体");
			fillrectangle(400, 405, 600, 465);
			outtextxy(480, 415, L"关");
		}


		//退出游戏
		if (m.x >= 36 && m.x <= 160 && m.y >= 660 && m.y <= 714)
		{
			setfillcolor(YELLOW);
			settextstyle(41, 0, L"楷体");
			fillrectangle(36, 660, 160, 714);
			outtextxy(63, 670, L"返回");
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				return;
			}
		}
		else
		{
			setfillcolor(WHITE);
			settextstyle(40, 0, L"楷体");
			fillrectangle(36, 660, 160, 714);
			outtextxy(63, 670, L"返回");
		}

		EndBatchDraw();
	}
}




void drawTable(int vernier_n, int n) {
	// 画出表格
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

	// 显示历史记录标签
	settextstyle(30, 0, L"宋体");
	settextcolor(RED);
	wstring historyLabel = L"历史记录";  // 使用 Unicode 字符串
	outtextxy(450, 75, historyLabel.c_str());

	// 显示两列标签
	settextcolor(BLACK);
	settextstyle(30, 0, L"宋体");
	wstring timeLabel = L"游戏用时/s";
	wstring resultLabel = L"胜负";
	outtextxy(285, 135, timeLabel.c_str());
	outtextxy(630, 135, resultLabel.c_str());

	// 显示下一页和上一页
	wstring prevPage = L"上一页";
	wstring nextPage = L"下一页";
	outtextxy(390, 640, prevPage.c_str());
	outtextxy(500, 640, nextPage.c_str());

	// 显示返回
	wstring backLabel = L"返回";
	outtextxy(10, 10, backLabel.c_str());

	// 显示页码
	int pagination = (n / 9) + 1;
	int nowPagination = vernier_n / 9 + 1;
	wstring paginationStr1 = to_wstring(pagination);
	wstring paginationStr2 = to_wstring(nowPagination);
	outtextxy(925, 700, paginationStr2.c_str());
	outtextxy(945, 700, L"/");
	outtextxy(965, 700, paginationStr1.c_str());
}





