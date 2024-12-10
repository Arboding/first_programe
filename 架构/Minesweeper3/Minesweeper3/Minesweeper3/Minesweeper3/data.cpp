#include "data.h"

int map[16][16];
int revealed[20][20];  // 用于标记格子是否已被点击
int flagged[20][20];   // 用于标记玩家右键标记的雷

bool isPaused = false;
bool isGameOver = false;
bool isWin = false;
int uncoveredCells = 0;
int timer = 0;
int difficulty = 0;
int width = 0, height = 0;
int mineCount = 0;
bool musicOn = true;
bool playSoundEffectOn = true;
int mx = 0, my = 0;  // 当前鼠标位置
