#ifndef SETTINGS_H
#define SETTINGS_H

#include <windows.h>     // 用于 Windows 系统的功能，比如延时和窗口操作
#include <mmsystem.h>
#include <tchar.h>       // 用于处理宽字符字符串的头文件（如果你需要处理宽字符）
#pragma comment (lib, "winmm.lib") //调用Windows的API播放音乐

void Music();
void playSoundEffect();

#endif

