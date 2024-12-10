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
    
    isGameOver = 0;
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            map[i][k] = 0;
        }
    }

    srand((unsigned)time(NULL));
    //ʮ����
    for (int i = 0; i < mineCount; )
    {
        int r = rand() % height;
        int c = rand() % width;
        if (map[r][c] == 0)
        {
            map[r][c] = -1;
            i++;
        }
    }

    //���ָ�
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {	//����Χ�Ź����1
            if (map[i][k] == -1)
            {
                for (int r = i - 1; r <= i + 1; r++)
                {
                    for (int c = k - 1; c <= k + 1; c++)
                    {
                        if ((r >= 0 && r < height && c >= 0 && c < width) && map[r][c] != -1)
                        {
                            ++map[r][c];
                        }
                    }
                }
            }
        }
    }

    //δ��
    for (int i = 0; i < 20; i++)
    {
        for (int k = 0; k < 20; k++)
        {
            revealed[i][k] = 0;
        }
    }

    //flag
    for (int i = 0; i < 20; i++)
    {
        for (int k = 0; k < 20; k++)
        {
            flagged[i][k] = 0;
        }
    }
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
        settextstyle(40, 0, L"�Ļ���κ");
        settextcolor(RGB(30, 30, 30));
        outtextxy(40 * width, 40 * height - 80, L"��ͣ");
        settextstyle(40, 0, L"����");
        settextcolor(RGB(30, 30, 30));
        outtextxy(40 * width, 40 * height - 40, L"����");
        settextstyle(40, 0, L"����");
        settextcolor(RGB(30, 30, 30));
        outtextxy(40 * width, 40 * height, L"�˳�");


        putimage(width * 40 - 80, 0, &imgs[12]);
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
        // �����������ף���Ϸʧ�ܣ����ű�ը��Ч
        mciSendString(_T("play explosion"), NULL, 0, NULL);
        isGameOver = true;
        revealed[x][y] = true;
        uncoveredCells++;
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
                printf("111");
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
std::chrono::duration<int> pausedDuration;  // ��ͣ�ڼ侭����ʱ��

// ������ʱ��
void startTimer()
{
    if (!isTimerRunning) {
        startTime = std::chrono::steady_clock::now();  // ��ȡ��ǰʱ�䲢����
        pausedDuration = std::chrono::seconds(0);  // ������ͣʱ��
        isTimerRunning = true;  // ���ü�ʱ��Ϊ����״̬
        isPaused = false;  // ȷ����ʱ��û����ͣ
    }
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
    if (isTimerRunning) {
        auto currentTime = std::chrono::steady_clock::now();
        if (isPaused) {
            // �����ͣ���򷵻���ͣǰ��ʱ�������ͣ��ʱ��
            std::chrono::seconds elapsed = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime);
            return elapsed.count() + pausedDuration.count();
        }
        else {
            // ���û����ͣ��ֱ�Ӽ��㾭����ʱ��
            std::chrono::seconds elapsed = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime);
            return elapsed.count() + pausedDuration.count();
        }
    }
    return 0;  // �����ʱ��δ����������0
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
    string outcome = isWin ? "Victory" : "Failure";
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
    setbkcolor(WHITE);
    cleardevice();

    // ҳ����ʾ
    while (1) {

        // �������
        drawTable(vernier_n, n);

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
                    return;
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
void drawpauseGame()
{
    if (isTimerRunning && !isPaused) {
        auto currentTime = std::chrono::steady_clock::now();
        pausedDuration += std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime);  // ��¼��ͣ��ʱ��
        isPaused = true;  // ����Ϊ��ͣ״̬
    }
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
}
void pauseGame()
{
    drawpauseGame();
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
                cleardevice();
                EndBatchDraw();
                resumeGame();
                resetGame();
                drawpauseGame();
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
                cleardevice();
                EndBatchDraw();
                handleSettingsInput();
                drawpauseGame();
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
        EndBatchDraw();
    }
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
    if (isTimerRunning && isPaused) {
        startTime = std::chrono::steady_clock::now();  // ���¼�¼��ʼʱ��
        isPaused = false;  // ����Ϊ����״̬
    }
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
    timer = getElapsedTime();
    if (checkWin())
    {
        
        saveHistory(getElapsedTime(), true); // ������Ϸʤ������ʷ��¼
        isTimerRunning = false;
        drawVictoryScreen();//����ʤ������

    }
    if (isGameOver)
    {
        
        saveHistory(getElapsedTime(), false); // ������Ϸʧ�ܵ���ʷ��¼
        isTimerRunning = false;
        drawGameOverScreen();//����ʧ�ܽ���

    }
}





