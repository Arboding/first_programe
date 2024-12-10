#include "settings.h"
#include "data.h"


/*
    ������: tyddddd
    ����: �������ֿ���MusicOn������Ч
        1. musicOnΪ1���ִ�
        2. musicOnΪ0���ֹر�
    ����: void
    ����ֵ: void
*/
void Music() {
    static bool isMusicOpen = false;  // ���ڱ�������Ƿ��Ѿ���

    if (musicOn) {
        if (!isMusicOpen) {
            // ���������δ�򿪣���򿪲����ű�������
            mciSendString(_T("open music/bgm.mp3 alias bgm"), NULL, 0, NULL);
            mciSendString(_T("play bgm repeat"), NULL, 0, NULL); //�ظ�����
            mciSendString(_T("setaudio bgm volume to 50"), NULL, 0, NULL);
            isMusicOpen = true;  // ��������Ѵ�
        }
    }
    else {
        if (isMusicOpen) {
            // ��������Ѿ��򿪣�ֹͣ���ر�����
            mciSendString(_T("stop bgm"), NULL, 0, NULL);
            mciSendString(_T("close bgm"), NULL, 0, NULL);
            isMusicOpen = false;  // ��������ѹر�
        }
    }
}


/*
    ������: tyddddd
    ����: ������Ч����audioOn������Ч
        1. audioOnΪ1���ִ�
        2. audioOnΪ0���ֹر�
    ����: void
    ����ֵ: void
*/
void playSoundEffect() {
    // �����Ч���ؿ���
    if (playSoundEffectOn) {
        // ֻ����Ч�ļ�һ�Σ�����Ҫÿ�ζ���
        static bool isSoundOpened = false;  // �����Ч�Ƿ��Ѵ�

        if (!isSoundOpened) {
            // ����Ч�ļ���Ϊÿ����Чָ����ͬ�ı���
            mciSendString(_T("open music/click.mp3 alias click"), NULL, 0, NULL);
            mciSendString(_T("open music/explosion.mp3 alias explosion"), NULL, 0, NULL);
            mciSendString(_T("open music/rightclick.mp3 alias rightclick"), NULL, 0, NULL);
            mciSendString(_T("open music/search.mp3 alias search"), NULL, 0, NULL);
            mciSendString(_T("open music/start.mp3 alias start"), NULL, 0, NULL);
            mciSendString(_T("open music/win.mp3 alias win"), NULL, 0, NULL);

            isSoundOpened = true;  // �����Ч�Ѵ�
        }
    }
    else {
        // �����Ч���عرգ��ر�������Ч�ļ�
        mciSendString(_T("close click"), NULL, 0, NULL);
        mciSendString(_T("close explosion"), NULL, 0, NULL);
        mciSendString(_T("close rightclick"), NULL, 0, NULL);
        mciSendString(_T("close search"), NULL, 0, NULL);
        mciSendString(_T("close start"), NULL, 0, NULL);
        mciSendString(_T("close win"), NULL, 0, NULL);
    }
}
