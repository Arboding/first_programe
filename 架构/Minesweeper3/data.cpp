#include "data.h"

int map[16][16];
int revealed[20][20];  // ���ڱ�Ǹ����Ƿ��ѱ����
int flagged[20][20];   // ���ڱ������Ҽ���ǵ���

bool isPaused = false;
bool isGameOver = false;
bool isWin = false;
int uncoveredCells = 0;
int timer = 0;
int difficulty = 1;
int width = 8, height = 8;
int mineCount = 10;
bool musicOn = true;
bool playSoundEffectOn = true;
int mx = 0, my = 0;  // ��ǰ���λ��
bool isTimerRunning = false;  // ��Ǽ�ʱ���Ƿ�����



