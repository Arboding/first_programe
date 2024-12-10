#ifndef DATA_H
#define DATA_H

extern int map[16][16];
extern int revealed[20][20];  // 用于标记格子是否已被点击
extern int flagged[20][20];   // 用于标记玩家右键标记的雷

extern bool isPaused;      // 游戏是否暂停
extern bool isGameOver;    // 游戏是否结束
extern bool isWin;         // 游戏是否胜利
extern bool timerStop;     //时间计时器是否关闭
extern int uncoveredCells; // 已翻开的格子数量
extern int timer;          // 游戏计时器
extern int difficulty;     // 游戏难度（地雷数量）
extern int width, height;  // 当前地图的宽度和高度
extern int mineCount;      // 雷的数量
extern bool musicOn;       // 音乐是否开启
extern bool playSoundEffectOn; // 音效是否开启
extern int mx, my;         // 鼠标点击的位置

#endif

