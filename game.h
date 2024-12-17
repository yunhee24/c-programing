#include "main.h"
#include "util.h"

#ifndef KEY_CODE
#define KEY_CODE

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

#define BOARD_SIZE 5

int keyControl();           // 키보드 조작
void title();               // 게임 타이틀
int menu();                 // 시작 메뉴
void infor();				// 게임 설명
int gamein();               // 게임 진행
int Dice(bool isComputer = false);					// 주사위

#endif

#ifndef GAME_H
#define GAME_H

class Event {
public:
    virtual void applyEvent(int& x, int& y) = 0; // 순수 가상 함수
};

class MoveOneStep : public Event {
public:
    void applyEvent(int& x, int& y) override;
};

// 다른 필요한 함수들
void initializeBoardEvents(Event* boardEvents[7][7], int targetX, int targetY);
void cleanupBoardEvents(Event* boardEvents[7][7]);

#endif