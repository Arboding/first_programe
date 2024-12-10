#include "view.h"
#include "data.h"
#include "game_logic.h"




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
				drawSettingsMenu();//打开设置界面
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
    // 绘制游戏胜利界面
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
    // 绘制游戏结束界面
}


/*
    负责人：chouchou
    功能：规则介绍
        1.显示游戏规则
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
	
	_getch();
	closegraph();
	return ;
}


/*
    负责人：chouchou
    功能：小组介绍
        1.显示小组介绍
*/
void groupPresentation() 
{
	while (1)
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

		getchar();
		
		return;
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

	settextstyle(50, 0, L"楷体");
	setbkmode(TRANSPARENT);
	settextcolor(RGB(256, 256, 256));

	std::wstring Title = L"设置";  // 使用 Unicode 字符串
	int widthTitle = 1000 / 2 - textwidth(Title.c_str()) / 2;
	outtextxy(widthTitle, 30, Title.c_str());

	settextstyle(20, 0, L"楷体");
	std::wstring group = L"量子码韵交响团";
	outtextxy(835, 705, group.c_str());

	settextstyle(40, 0, L"楷体");

	std::wstring music = L"音乐";
	rectangle(400, 145, 600, 205);
	std::wstring musicopen = L"开";
	rectangle(400, 210, 600, 270);
	std::wstring musicclose = L"关";
	outtextxy(460, 90, music.c_str());
	outtextxy(480, 153, musicopen.c_str());
	outtextxy(480, 220, musicclose.c_str());

	settextstyle(40, 0, L"楷体");

	std::wstring soundeffect = L"音效";
	rectangle(400, 340, 600, 400);
	std::wstring soundeffectopen = L"开";
	rectangle(400, 405, 600, 465);
	std::wstring soundeffectclose = L"关";
	rectangle(400, 470, 600, 530);
	std::wstring bkmusic1 = L"背景音乐1";
	rectangle(400, 535, 600, 595);
	std::wstring bkmusic2 = L"背景音乐2";
	rectangle(400, 600, 600, 660);
	std::wstring bkmusic3 = L"背景音乐3";

	outtextxy(460, 295, soundeffect.c_str());
	outtextxy(480, 350, soundeffectopen.c_str());
	outtextxy(480, 415, soundeffectclose.c_str());
	outtextxy(410, 480, bkmusic1.c_str());
	outtextxy(410, 545, bkmusic2.c_str());
	outtextxy(410, 610, bkmusic3.c_str());

	rectangle(36, 660, 160, 714);
	settextstyle(35, 0, L"楷体");
	std::wstring back = L"返回";
	outtextxy(63, 670, back.c_str());

	getchar();
	
	return ;
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
    // 处理设置菜单输入
}


/*
	负责人: 雨月云
	功能: 游戏结束时的处理
		1. 停止计时器
		2. 显示结算界面
	参数: void
	返回值: void
*/
void endGame()
{
	if (checkWin())
	{
		drawVictoryScreen();//调用胜利界面
		saveHistory(getElapsedTime(), true); // 保存游戏胜利的历史记录
	}
	else
	{
		drawGameOverScreen();//调用失败界面
		saveHistory(getElapsedTime(), false); // 保存游戏失败的历史记录
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
}






