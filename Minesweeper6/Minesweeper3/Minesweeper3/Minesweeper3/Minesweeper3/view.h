#ifndef VIEW_H
#define VIEW_H


#include <graphics.h> // EasyXÍ¼ÐÎ¿â
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

#endif

