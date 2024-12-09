#ifndef VIEW_H
#define VIEW_H


#include <graphics.h> // EasyXͼ�ο�
#include <conio.h>
#include <iostream>
#include <algorithm>



using namespace std;



void drawStartMenu();
void handleMenuInput();
void drawGameBoard();
void handleGameInput();
void drawVictoryScreen();
void drawGameOverScreen();
void ruleIntroduction();
void groupPresentation();
void drawSettingsMenu();
void handleSettingsInput();
void endGame();
void drawTable(int vernier_n, int n);



class Button
{
public:
    Button(int x, int y, int width, int height, COLORREF color, wstring ptext) // �޸�Ϊwstring
    {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
        this->color = color;
        this->ptext = ptext;
    }

    // ���ư�ť������
    void drawbutton()
    {
        setfillcolor(this->color);
        settextstyle(40, 0, L"΢���ź�");  // ��������ʹ�ÿ��ַ�
        setlinecolor(BLACK);
        settextcolor(RED);
        setbkmode(TRANSPARENT);
        fillrectangle(this->x, this->y, this->x + this->width, this->y + this->height);
        outtextxy(this->x + 11, this->y + 25, this->ptext.c_str());  // ʹ��wstring��c_str()
    }

    // �ж�����Ƿ��ڰ�ť��
    int mousebutton(MOUSEMSG m)
    {
        if (this->x <= m.x && m.x <= this->x + this->width && this->y <= m.y && m.y <= this->y + this->height)
        {
            this->color = YELLOW;
            return 1;
        }
        this->color = WHITE;
        return 0;
    }

    // ������������ѡ��
    int clickbutton(MOUSEMSG m)
    {
        if (mousebutton(m) && m.uMsg == WM_LBUTTONDOWN)
        {
            return 1;
        }
        return 0;
    }

    COLORREF& getcolor()
    {
        return color;
    }

protected:
    int x;
    int y;
    int width;
    int height;
    COLORREF color;  // ��ɫ
    wstring ptext;   // �޸�Ϊwstring֧��Unicode
};

#endif

