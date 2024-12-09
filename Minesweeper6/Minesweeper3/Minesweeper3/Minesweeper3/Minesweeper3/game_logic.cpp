#include "game_logic.h"
#include "data.h"
#include "view.h"



/*
    负责人: savior
    功能: 初始化游戏数据
        1. 设置地图的初始状态
        2. 根据难度生成雷
        3. 初始化游戏状态变量（计时器、胜负状态等）
    参数: void
    返回值: void
*/
void initGame() 
{
    // 初始化游戏状态和地图
    
    // 根据难度设置地图大小和地雷数
 // 初始化随机数种子
    // 根据难度生成雷
    // 其他初始化代码
}

/*
    负责人: savior
    功能: 重置游戏状态，重新开始游戏
        1. 清除地图和状态
        2. 根据难度生成新地图和地雷
    参数: void
    返回值: void
*/
void resetGame() 
{
    // 清空地图，重新生成地雷
    initGame();
}

/*
    负责人: 念
    功能: 根据玩家输入来翻开指定的格子
        1. 计算玩家点击的格子的坐标
        2. 判断格子是雷、空白还是数字
        3. 更新游戏状态
    参数: int x, int y（玩家点击的地图中的坐标）
    返回值: bool（翻开成功返回true，失败返回false）
*/
bool openCell(int x, int y) 
{
    if (x < 0 || x >= width || y < 0 || y >= height || revealed[x][y]) {
        // 如果点击的坐标无效或者该格子已经被翻开，则返回 false
        return false;
    }

    if (map[x][y] == -1) {
        // 如果点击的是雷，游戏失败
        // 如果点击的是雷，游戏失败，播放爆炸音效
        mciSendString(_T("play explosion"), NULL, 0, NULL);
        isGameOver = true;
        return false;
    }

    // 翻开当前格子
    revealed[x][y] = true;
    uncoveredCells++;

    // 播放点击音效
    mciSendString(_T("play click"), NULL, 0, NULL); 


    // 如果点击的是空白格（0），展开周围区域
    if (map[x][y] == 0) {
        mciSendString(_T("play search"), NULL, 0, NULL);  // 播放空白格翻开音效
        expandArea(x, y);
    }

    // 检查游戏是否胜利
    if (checkWin()) {
        mciSendString(_T("play win"), NULL, 0, NULL);  // 播放胜利音效
    }

    return true;
}


/*
    负责人: 念
    功能: 根据玩家点击的格子位置展开周围的格子（如果是空白格）
        1. 扩展打开周围8个格子
    参数: int x, int y（玩家点击的坐标）
    返回值: void
*/
void expandArea(int x, int y) 
{
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int nx = x + i, ny = y + j;

            if (nx >= 0 && nx < width && ny >= 0 && ny < height && !revealed[nx][ny]) {
                // 如果周围的格子是未翻开的，并且是有效的格子，则翻开它
                revealed[nx][ny] = true;
                uncoveredCells++;

                // 如果该格子仍然是空白格（0），递归展开其周围的格子
                if (map[nx][ny] == 0) {
                    expandArea(nx, ny);
                }
            }
        }
    }
}



/*
    负责人: 念
    功能: 判断玩家是否胜利
        1. 遍历地图判断所有非雷格子是否都已翻开
        2. 判断是否达到胜利条件
    参数: void
    返回值: bool（胜利返回true，失败返回false）
*/
bool checkWin() 
{
    if (uncoveredCells == (width * height - mineCount)) {
        // 所有非雷格子都已翻开，玩家获胜
        isWin = true;
        return true;
    }
    return false;
}



/*
    负责人: 念
    功能: 判断游戏是否失败
        1. 判断玩家点击是否踩到雷
        2. 如果点击的是雷则返回失败
    参数: void
    返回值: bool（失败返回true，继续游戏返回false）
*/
bool checkGameOver() 
{
    // 如果地图上的某个格子是雷并且玩家点击了它，则游戏结束
    if (isGameOver) {
        return true;
    }
    return false;
}



/*
    负责人: 编程界首屈一指的蛆
    功能: 启动计时器*
        1. 每秒更新一次游戏计时器
    参数: void
    返回值: void
*/
// 用于记录游戏开始时间
std::chrono::time_point<std::chrono::steady_clock> startTime;

// 启动计时器
void startTimer()
{
    startTime = std::chrono::steady_clock::now();  // 获取当前时间并保存
}

/*
    负责人: 编程界首屈一指的蛆
    功能: 获取当前游戏时间
        1. 返回计时器当前的时间（秒数）
    参数: void
    返回值: int（当前游戏经过的时间，单位秒）
*/
// 获取当前游戏时间（秒）
int getElapsedTime()
{
    // 获取当前时间点
    auto currentTime = std::chrono::steady_clock::now();

    // 计算游戏已进行的时间（秒）
    std::chrono::duration<int> elapsed = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime);

    return elapsed.count();
}

/*
    负责人: 编程界首屈一指的蛆
    功能: 保存游戏历史记录
        1. 将游戏的时间和胜负结果保存到文件中
        2. 历史记录包括：游戏时长、胜负状态
    参数:
        int timeTaken  游戏用时（秒）
        bool isWin     游戏是否胜利
    返回值: void
*/
void saveHistory(int timeTaken, bool isWin)
{
    ofstream outFile;
    outFile.open("game_history.txt", ios::app);        // 以追加模式打开文件，这样不会覆盖以前的内容
    string outcome = isWin ? "胜利" : "失败";
    outFile << timeTaken << " " << outcome << endl;
    outFile.close();
}


/*
    负责人: 编程界首屈一指的蛆
    功能: 显示历史记录
        1. 从文件中读取并展示所有历史记录
        2. 格式：时间 + 胜负状态（胜利/失败）
    参数: void
    返回值: void
*/
void displayHistory() 
{
    // 读取文件中的历史记录
    wifstream inFile(L"game_history.txt");
    vector<wstring> timeTaken(999);
    vector<wstring> isWin(999);
    int n = 0; // 记录记录总数
    while (inFile >> timeTaken[n] >> isWin[n])
        n++;

    int vernier_n = 0; // 设置游标方便记录当前页面

    // 文件中历史记录为反方向，将顺序掉转
    vector<wstring> timeTakens(999);
    vector<wstring> isWins(999);
    for (int i = 0; i < n; i++) {
        timeTakens[i] = timeTaken[n - i - 1];
        isWins[i] = isWin[n - i - 1];
    }

    // 页面显示
    while (1) {
        
        
        setbkcolor(WHITE);
        cleardevice();

        // 显示历史记录标签
        settextstyle(30, 0, L"宋体");
        settextcolor(RED);
        wstring historyLabel = L"历史记录";  // 使用 Unicode 字符串
        outtextxy(450, 75, historyLabel.c_str());

        // 画出表格
        drawTable(vernier_n, n);

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

        // 先显示第一页内容
        int line_x = 330, line_y = 180;
        for (int i = vernier_n; i < vernier_n + 9; i++) { // 循环九次，显示九行记录
            outtextxy(line_x, line_y, timeTakens[i].c_str());
            outtextxy(line_x + 300, line_y, isWins[i].c_str());
            line_y += 50;
        }
        // 翻页
        while (1) {
            if (MouseHit()) {
                MOUSEMSG msg = GetMouseMsg();
                if (msg.x > 400 && msg.x < 500 && msg.y > 625 && msg.y < 690 && msg.uMsg == WM_LBUTTONDOWN) { // 点击在上一页的情况
                    if (vernier_n == 0) { // 页码为1，无上一页
                    }
                    else { // 页码大于1，可向前翻页
                        cleardevice(); // 清除页面内容

                        // 更新页面内容
                        vernier_n -= 9; // 将游标-9，使页码-1
                        drawTable(vernier_n, n);
                        int line_x = 330, line_y = 180;
                        for (int i = vernier_n; i < vernier_n + 9; i++) {
                            outtextxy(line_x, line_y, timeTakens[i].c_str());
                            outtextxy(line_x + 300, line_y, isWins[i].c_str());
                            line_y += 50;
                        }
                    }
                }
                else if (msg.x > 500 && msg.x < 600 && msg.y > 625 && msg.y < 690 && msg.uMsg == WM_LBUTTONDOWN && n > 0) {
                    if (n - vernier_n < 9) { // 页码到达最哦大，无法向下翻页
                    }
                    else {
                        cleardevice(); // 清除页面内容

                        // 更新页面内容
                        vernier_n += 9; // 将游标+9，使页码加一
                        drawTable(vernier_n, n);
                        int line_x = 330, line_y = 180;
                        for (int i = vernier_n; i < vernier_n + 9; i++) {
                            if (i > n)
                                break;
                            outtextxy(line_x, line_y, timeTakens[i].c_str());
                            outtextxy(line_x + 300, line_y, isWins[i].c_str());
                            line_y += 50;
                        }
                    }
                }
                else if (msg.x > 0 && msg.x < 100 && msg.y > 0 && msg.y < 65 && msg.uMsg == WM_LBUTTONDOWN) { // 点击返回按钮，清除页面内容，结束此函数
                    cleardevice();
                    return ;
                }
            }
        }
        
    }
}


/*
    负责人: 雨月云
    功能: 暂停游戏
        1. 设置游戏为暂停状态
    参数: void
    返回值: void
*/
std::chrono::time_point<std::chrono::steady_clock> pauseTime;
void pauseGame()
{
    isPaused = true;
    pauseTime = std::chrono::steady_clock::now();  // 记录暂停时刻
    closegraph();
    initgraph(1000, 750);
    setbkcolor(WHITE);
    cleardevice();//清屏 two
    settextstyle(70, 0, L"文华新魏");
    settextcolor(RGB(30, 30, 30));
    outtextxy(350, 50, L"暂停游戏");
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

    //暂停居中的圆形
    circle(475, 350, 125);
    //暂停圆形中的三角形
    int x1 = 523, y1 = 350;
    int x2 = 450, y2 = 300;
    int x3 = 450, y3 = 400;

    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);


    //继续游戏
    fillrectangle(50, 570, 300, 620);//传矩形对角的坐标
    outtextxy(50 + 50, 570 + 10, L"继续游戏");//设置文字的位置


    //游戏设置
    fillrectangle(350, 570, 600, 620);//传矩形对角的坐标
    outtextxy(350 + 50, 570 + 10, L"游戏设置");//设置文字的位置


    //退出游戏
    fillrectangle(650, 570, 900, 620);//传矩形对角的坐标
    outtextxy(650 + 50, 570 + 10, L"退出游戏");//设置文字的位置



    while (1)
    {
        BeginBatchDraw();

        MOUSEMSG m = GetMouseMsg();

        //继续游戏
        if (m.x >= 50 && m.x <= 300 && m.y > 570 && m.y <= 620)
        {
            setfillcolor(YELLOW);//将当前按钮改为黄色
            settextstyle(41, 0, L"楷体");
            fillrectangle(50, 570, 300, 620);//传矩形对角的坐标
            outtextxy(50 + 50, 570 + 10, L"继续游戏");//设置文字的位置
            if (m.uMsg == WM_LBUTTONDOWN)//当左键被按下
            {
                resumeGame(); //恢复游戏状态
                drawGameBoard();//打开游戏界面
            }
        }
        else
        {
            setfillcolor(WHITE);
            settextstyle(40, 0, L"楷体");
            fillrectangle(50, 570, 300, 620);
            outtextxy(50 + 50, 570 + 10, L"继续游戏");
        }

        //游戏设置
        if (m.x >= 350 && m.x <= 600 && m.y > 570 && m.y <= 620)
        {
            setfillcolor(YELLOW);
            settextstyle(41, 0, L"楷体");
            fillrectangle(350, 570, 600, 620);
            outtextxy(350 + 50, 570 + 10, L"游戏设置");
            if (m.uMsg == WM_LBUTTONDOWN)
            {
                drawSettingsMenu();//打开设置界面
            }
        }
        else
        {
            setfillcolor(WHITE);
            settextstyle(40, 0, L"楷体");
            fillrectangle(350, 570, 600, 420);
            outtextxy(350 + 50, 570 + 10, L"游戏设置");
        }

        //退出游戏
        if (m.x >= 650 && m.x <= 900 && m.y > 570 && m.y <= 620)
        {
            setfillcolor(YELLOW);
            settextstyle(41, 0, L"楷体");
            fillrectangle(650, 570, 900, 620);
            outtextxy(650 + 50, 570 + 10, L"退出游戏");
            if (m.uMsg == WM_LBUTTONDOWN)
            {
                exit(0);
            }
        }
        else
        {
            setfillcolor(WHITE);
            settextstyle(40, 0, L"楷体");
            fillrectangle(650, 570, 900, 620);
            outtextxy(650 + 50, 570 + 10, L"退出游戏");
        }
    }
    //getchar();
    closegraph();
}




/*
    负责人: 雨月云
    功能: 恢复游戏
        1. 设置游戏为恢复状态
    参数: void
    返回值: void
*/
void resumeGame()
{
    if (isPaused)
    {
        auto pauseDuration = std::chrono::steady_clock::now() - pauseTime;
        startTime += pauseDuration; // 跳过暂停时间
        isPaused = false;
    }
}






