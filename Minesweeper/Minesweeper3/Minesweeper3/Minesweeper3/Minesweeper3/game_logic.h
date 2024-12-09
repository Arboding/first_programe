#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include <chrono>
#include <thread>
#include <iostream>
#include <fstream>
#include <graphics.h>
#include <locale.h>
#include <vector>
#include <string>


void initGame();
void resetGame();
bool openCell(int x, int y);  //传进来时均为，地图的行和列
void expandArea(int x, int y);//传进来时均为，地图的行和列
bool checkWin();
bool checkGameOver();
void startTimer();
int getElapsedTime();
void saveHistory(int timeTaken, bool isWin);
void displayHistory();
void pauseGame();
void resumeGame();

#endif

