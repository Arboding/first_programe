#include "settings.h"
#include "data.h"


/*
    负责人: tyddddd
    功能: 根据音乐开关MusicOn播放音效
        1. musicOn为1音乐打开
        2. musicOn为0音乐关闭
    参数: void
    返回值: void
*/
void Music() {
    static bool isMusicOpen = false;  // 用于标记音乐是否已经打开

    if (musicOn) {
        if (!isMusicOpen) {
            // 如果音乐尚未打开，则打开并播放背景音乐
            mciSendString(_T("open music/bgm.mp3 alias bgm"), NULL, 0, NULL);
            mciSendString(_T("play bgm repeat"), NULL, 0, NULL); //重复播放
            mciSendString(_T("setaudio bgm volume to 50"), NULL, 0, NULL);
            isMusicOpen = true;  // 标记音乐已打开
        }
    }
    else {
        if (isMusicOpen) {
            // 如果音乐已经打开，停止并关闭音乐
            mciSendString(_T("stop bgm"), NULL, 0, NULL);
            mciSendString(_T("close bgm"), NULL, 0, NULL);
            isMusicOpen = false;  // 标记音乐已关闭
        }
    }
}


/*
    负责人: tyddddd
    功能: 根据音效开关audioOn播放音效
        1. audioOn为1音乐打开
        2. audioOn为0音乐关闭
    参数: void
    返回值: void
*/
void playSoundEffect() {
    // 如果音效开关开启
    if (playSoundEffectOn) {
        // 只打开音效文件一次，不需要每次都打开
        static bool isSoundOpened = false;  // 标记音效是否已打开

        if (!isSoundOpened) {
            // 打开音效文件并为每个音效指定不同的别名
            mciSendString(_T("open music/click.mp3 alias click"), NULL, 0, NULL);
            mciSendString(_T("open music/explosion.mp3 alias explosion"), NULL, 0, NULL);
            mciSendString(_T("open music/rightclick.mp3 alias rightclick"), NULL, 0, NULL);
            mciSendString(_T("open music/search.mp3 alias search"), NULL, 0, NULL);
            mciSendString(_T("open music/start.mp3 alias start"), NULL, 0, NULL);
            mciSendString(_T("open music/win.mp3 alias win"), NULL, 0, NULL);

            isSoundOpened = true;  // 标记音效已打开
        }
    }
    else {
        // 如果音效开关关闭，关闭所有音效文件
        mciSendString(_T("close click"), NULL, 0, NULL);
        mciSendString(_T("close explosion"), NULL, 0, NULL);
        mciSendString(_T("close rightclick"), NULL, 0, NULL);
        mciSendString(_T("close search"), NULL, 0, NULL);
        mciSendString(_T("close start"), NULL, 0, NULL);
        mciSendString(_T("close win"), NULL, 0, NULL);
    }
}
