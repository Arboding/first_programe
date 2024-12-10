#ifndef DATA_H
#define DATA_H

extern int map[16][16];
extern int revealed[20][20];  // ���ڱ�Ǹ����Ƿ��ѱ����
extern int flagged[20][20];   // ���ڱ������Ҽ���ǵ���

extern bool isPaused;      // ��Ϸ�Ƿ���ͣ
extern bool isGameOver;    // ��Ϸ�Ƿ����
extern bool isWin;         // ��Ϸ�Ƿ�ʤ��
extern bool timerStop;     //ʱ���ʱ���Ƿ�ر�
extern int uncoveredCells; // �ѷ����ĸ�������
extern int timer;          // ��Ϸ��ʱ��
extern int difficulty;     // ��Ϸ�Ѷȣ�����������
extern int width, height;  // ��ǰ��ͼ�Ŀ�Ⱥ͸߶�
extern int mineCount;      // �׵�����
extern bool musicOn;       // �����Ƿ���
extern bool playSoundEffectOn; // ��Ч�Ƿ���
extern int mx, my;         // �������λ��

#endif

