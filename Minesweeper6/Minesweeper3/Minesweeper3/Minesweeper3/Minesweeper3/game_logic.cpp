#include "game_logic.h"
#include "data.h"
#include "view.h"



/*
    ������: savior
    ����: ��ʼ����Ϸ����
        1. ���õ�ͼ�ĳ�ʼ״̬
        2. �����Ѷ�������
        3. ��ʼ����Ϸ״̬��������ʱ����ʤ��״̬�ȣ�
    ����: void
    ����ֵ: void
*/
void initGame() 
{
    // ��ʼ����Ϸ״̬�͵�ͼ
    
    // �����Ѷ����õ�ͼ��С�͵�����
 // ��ʼ�����������
    // �����Ѷ�������
    // ������ʼ������
}

/*
    ������: savior
    ����: ������Ϸ״̬�����¿�ʼ��Ϸ
        1. �����ͼ��״̬
        2. �����Ѷ������µ�ͼ�͵���
    ����: void
    ����ֵ: void
*/
void resetGame() 
{
    // ��յ�ͼ���������ɵ���
    initGame();
}

/*
    ������: ��
    ����: �����������������ָ���ĸ���
        1. ������ҵ���ĸ��ӵ�����
        2. �жϸ������ס��հ׻�������
        3. ������Ϸ״̬
    ����: int x, int y����ҵ���ĵ�ͼ�е����꣩
    ����ֵ: bool�������ɹ�����true��ʧ�ܷ���false��
*/
bool openCell(int x, int y) 
{
    if (x < 0 || x >= width || y < 0 || y >= height || revealed[x][y]) {
        // ��������������Ч���߸ø����Ѿ����������򷵻� false
        return false;
    }

    if (map[x][y] == -1) {
        // �����������ף���Ϸʧ��
        // �����������ף���Ϸʧ�ܣ����ű�ը��Ч
        mciSendString(_T("play explosion"), NULL, 0, NULL);
        isGameOver = true;
        return false;
    }

    // ������ǰ����
    revealed[x][y] = true;
    uncoveredCells++;

    // ���ŵ����Ч
    mciSendString(_T("play click"), NULL, 0, NULL); 


    // ���������ǿհ׸�0����չ����Χ����
    if (map[x][y] == 0) {
        mciSendString(_T("play search"), NULL, 0, NULL);  // ���ſհ׸񷭿���Ч
        expandArea(x, y);
    }

    // �����Ϸ�Ƿ�ʤ��
    if (checkWin()) {
        mciSendString(_T("play win"), NULL, 0, NULL);  // ����ʤ����Ч
    }

    return true;
}


/*
    ������: ��
    ����: ������ҵ���ĸ���λ��չ����Χ�ĸ��ӣ�����ǿհ׸�
        1. ��չ����Χ8������
    ����: int x, int y����ҵ�������꣩
    ����ֵ: void
*/
void expandArea(int x, int y) 
{
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int nx = x + i, ny = y + j;

            if (nx >= 0 && nx < width && ny >= 0 && ny < height && !revealed[nx][ny]) {
                // �����Χ�ĸ�����δ�����ģ���������Ч�ĸ��ӣ��򷭿���
                revealed[nx][ny] = true;
                uncoveredCells++;

                // ����ø�����Ȼ�ǿհ׸�0�����ݹ�չ������Χ�ĸ���
                if (map[nx][ny] == 0) {
                    expandArea(nx, ny);
                }
            }
        }
    }
}



/*
    ������: ��
    ����: �ж�����Ƿ�ʤ��
        1. ������ͼ�ж����з��׸����Ƿ��ѷ���
        2. �ж��Ƿ�ﵽʤ������
    ����: void
    ����ֵ: bool��ʤ������true��ʧ�ܷ���false��
*/
bool checkWin() 
{
    if (uncoveredCells == (width * height - mineCount)) {
        // ���з��׸��Ӷ��ѷ�������һ�ʤ
        isWin = true;
        return true;
    }
    return false;
}



/*
    ������: ��
    ����: �ж���Ϸ�Ƿ�ʧ��
        1. �ж���ҵ���Ƿ�ȵ���
        2. �������������򷵻�ʧ��
    ����: void
    ����ֵ: bool��ʧ�ܷ���true��������Ϸ����false��
*/
bool checkGameOver() 
{
    // �����ͼ�ϵ�ĳ���������ײ�����ҵ������������Ϸ����
    if (isGameOver) {
        return true;
    }
    return false;
}



/*
    ������: ��̽�����һָ����
    ����: ������ʱ��*
        1. ÿ�����һ����Ϸ��ʱ��
    ����: void
    ����ֵ: void
*/
// ���ڼ�¼��Ϸ��ʼʱ��
std::chrono::time_point<std::chrono::steady_clock> startTime;

// ������ʱ��
void startTimer()
{
    startTime = std::chrono::steady_clock::now();  // ��ȡ��ǰʱ�䲢����
}

/*
    ������: ��̽�����һָ����
    ����: ��ȡ��ǰ��Ϸʱ��
        1. ���ؼ�ʱ����ǰ��ʱ�䣨������
    ����: void
    ����ֵ: int����ǰ��Ϸ������ʱ�䣬��λ�룩
*/
// ��ȡ��ǰ��Ϸʱ�䣨�룩
int getElapsedTime()
{
    // ��ȡ��ǰʱ���
    auto currentTime = std::chrono::steady_clock::now();

    // ������Ϸ�ѽ��е�ʱ�䣨�룩
    std::chrono::duration<int> elapsed = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime);

    return elapsed.count();
}

/*
    ������: ��̽�����һָ����
    ����: ������Ϸ��ʷ��¼
        1. ����Ϸ��ʱ���ʤ��������浽�ļ���
        2. ��ʷ��¼��������Ϸʱ����ʤ��״̬
    ����:
        int timeTaken  ��Ϸ��ʱ���룩
        bool isWin     ��Ϸ�Ƿ�ʤ��
    ����ֵ: void
*/
void saveHistory(int timeTaken, bool isWin)
{
    ofstream outFile;
    outFile.open("game_history.txt", ios::app);        // ��׷��ģʽ���ļ����������Ḳ����ǰ������
    string outcome = isWin ? "ʤ��" : "ʧ��";
    outFile << timeTaken << " " << outcome << endl;
    outFile.close();
}


/*
    ������: ��̽�����һָ����
    ����: ��ʾ��ʷ��¼
        1. ���ļ��ж�ȡ��չʾ������ʷ��¼
        2. ��ʽ��ʱ�� + ʤ��״̬��ʤ��/ʧ�ܣ�
    ����: void
    ����ֵ: void
*/
void displayHistory() 
{
    // ��ȡ�ļ��е���ʷ��¼
    wifstream inFile(L"game_history.txt");
    vector<wstring> timeTaken(999);
    vector<wstring> isWin(999);
    int n = 0; // ��¼��¼����
    while (inFile >> timeTaken[n] >> isWin[n])
        n++;

    int vernier_n = 0; // �����α귽���¼��ǰҳ��

    // �ļ�����ʷ��¼Ϊ�����򣬽�˳���ת
    vector<wstring> timeTakens(999);
    vector<wstring> isWins(999);
    for (int i = 0; i < n; i++) {
        timeTakens[i] = timeTaken[n - i - 1];
        isWins[i] = isWin[n - i - 1];
    }

    // ҳ����ʾ
    while (1) {
        
        
        setbkcolor(WHITE);
        cleardevice();

        // ��ʾ��ʷ��¼��ǩ
        settextstyle(30, 0, L"����");
        settextcolor(RED);
        wstring historyLabel = L"��ʷ��¼";  // ʹ�� Unicode �ַ���
        outtextxy(450, 75, historyLabel.c_str());

        // �������
        drawTable(vernier_n, n);

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

        // ����ʾ��һҳ����
        int line_x = 330, line_y = 180;
        for (int i = vernier_n; i < vernier_n + 9; i++) { // ѭ���ŴΣ���ʾ���м�¼
            outtextxy(line_x, line_y, timeTakens[i].c_str());
            outtextxy(line_x + 300, line_y, isWins[i].c_str());
            line_y += 50;
        }
        // ��ҳ
        while (1) {
            if (MouseHit()) {
                MOUSEMSG msg = GetMouseMsg();
                if (msg.x > 400 && msg.x < 500 && msg.y > 625 && msg.y < 690 && msg.uMsg == WM_LBUTTONDOWN) { // �������һҳ�����
                    if (vernier_n == 0) { // ҳ��Ϊ1������һҳ
                    }
                    else { // ҳ�����1������ǰ��ҳ
                        cleardevice(); // ���ҳ������

                        // ����ҳ������
                        vernier_n -= 9; // ���α�-9��ʹҳ��-1
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
                    if (n - vernier_n < 9) { // ҳ�뵽����Ŷ���޷����·�ҳ
                    }
                    else {
                        cleardevice(); // ���ҳ������

                        // ����ҳ������
                        vernier_n += 9; // ���α�+9��ʹҳ���һ
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
                else if (msg.x > 0 && msg.x < 100 && msg.y > 0 && msg.y < 65 && msg.uMsg == WM_LBUTTONDOWN) { // ������ذ�ť�����ҳ�����ݣ������˺���
                    cleardevice();
                    return ;
                }
            }
        }
        
    }
}


/*
    ������: ������
    ����: ��ͣ��Ϸ
        1. ������ϷΪ��ͣ״̬
    ����: void
    ����ֵ: void
*/
std::chrono::time_point<std::chrono::steady_clock> pauseTime;
void pauseGame()
{
    isPaused = true;
    pauseTime = std::chrono::steady_clock::now();  // ��¼��ͣʱ��
    closegraph();
    initgraph(1000, 750);
    setbkcolor(WHITE);
    cleardevice();//���� two
    settextstyle(70, 0, L"�Ļ���κ");
    settextcolor(RGB(30, 30, 30));
    outtextxy(350, 50, L"��ͣ��Ϸ");
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

    //��ͣ���е�Բ��
    circle(475, 350, 125);
    //��ͣԲ���е�������
    int x1 = 523, y1 = 350;
    int x2 = 450, y2 = 300;
    int x3 = 450, y3 = 400;

    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);


    //������Ϸ
    fillrectangle(50, 570, 300, 620);//�����ζԽǵ�����
    outtextxy(50 + 50, 570 + 10, L"������Ϸ");//�������ֵ�λ��


    //��Ϸ����
    fillrectangle(350, 570, 600, 620);//�����ζԽǵ�����
    outtextxy(350 + 50, 570 + 10, L"��Ϸ����");//�������ֵ�λ��


    //�˳���Ϸ
    fillrectangle(650, 570, 900, 620);//�����ζԽǵ�����
    outtextxy(650 + 50, 570 + 10, L"�˳���Ϸ");//�������ֵ�λ��



    while (1)
    {
        BeginBatchDraw();

        MOUSEMSG m = GetMouseMsg();

        //������Ϸ
        if (m.x >= 50 && m.x <= 300 && m.y > 570 && m.y <= 620)
        {
            setfillcolor(YELLOW);//����ǰ��ť��Ϊ��ɫ
            settextstyle(41, 0, L"����");
            fillrectangle(50, 570, 300, 620);//�����ζԽǵ�����
            outtextxy(50 + 50, 570 + 10, L"������Ϸ");//�������ֵ�λ��
            if (m.uMsg == WM_LBUTTONDOWN)//�����������
            {
                resumeGame(); //�ָ���Ϸ״̬
                drawGameBoard();//����Ϸ����
            }
        }
        else
        {
            setfillcolor(WHITE);
            settextstyle(40, 0, L"����");
            fillrectangle(50, 570, 300, 620);
            outtextxy(50 + 50, 570 + 10, L"������Ϸ");
        }

        //��Ϸ����
        if (m.x >= 350 && m.x <= 600 && m.y > 570 && m.y <= 620)
        {
            setfillcolor(YELLOW);
            settextstyle(41, 0, L"����");
            fillrectangle(350, 570, 600, 620);
            outtextxy(350 + 50, 570 + 10, L"��Ϸ����");
            if (m.uMsg == WM_LBUTTONDOWN)
            {
                drawSettingsMenu();//�����ý���
            }
        }
        else
        {
            setfillcolor(WHITE);
            settextstyle(40, 0, L"����");
            fillrectangle(350, 570, 600, 420);
            outtextxy(350 + 50, 570 + 10, L"��Ϸ����");
        }

        //�˳���Ϸ
        if (m.x >= 650 && m.x <= 900 && m.y > 570 && m.y <= 620)
        {
            setfillcolor(YELLOW);
            settextstyle(41, 0, L"����");
            fillrectangle(650, 570, 900, 620);
            outtextxy(650 + 50, 570 + 10, L"�˳���Ϸ");
            if (m.uMsg == WM_LBUTTONDOWN)
            {
                exit(0);
            }
        }
        else
        {
            setfillcolor(WHITE);
            settextstyle(40, 0, L"����");
            fillrectangle(650, 570, 900, 620);
            outtextxy(650 + 50, 570 + 10, L"�˳���Ϸ");
        }
    }
    //getchar();
    closegraph();
}




/*
    ������: ������
    ����: �ָ���Ϸ
        1. ������ϷΪ�ָ�״̬
    ����: void
    ����ֵ: void
*/
void resumeGame()
{
    if (isPaused)
    {
        auto pauseDuration = std::chrono::steady_clock::now() - pauseTime;
        startTime += pauseDuration; // ������ͣʱ��
        isPaused = false;
    }
}






