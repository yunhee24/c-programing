#include "game.h"
#include <cstdlib>
#include <ctime>
#include <Windows.h>
using namespace std;


void title() {
    cout << " \n\n\n\n\n " << endl;
    cout << "                   _________   _______   _______   _________                        " << endl;
    cout << "                   | ______ \\  \\_   _/  /  ___  \\  |  ______\\                       " << endl;
    cout << "                   | |     \\ \\   | |   |  /   \\_|  | |                         " << endl;
    cout << "                   | |     | |   | |   | |         | |______                            " << endl;
    cout << "                   | |     | |   | |   | |         |  ______|                           " << endl;
    cout << "                   | |     | |   | |   | |     _   | |                           " << endl;
    cout << "                   | |_____/ /  _| |   |  \\___/ |  | |_______                   " << endl;
    cout << "                   |________/  /_____\\  \\_______/  |________/                             " << endl;
    cout << " \n\n " << endl;
    cout << "              ----------------------------------------------------" << endl;
}


int menu() {

    int x = 36;
    int y = 20;

    gotoxy(x - 2, y);
    cout << "▶ 시작하기";
    gotoxy(x, y + 1);
    cout << "종료하기";
    while (1) {
        int n = keyControl();
        switch (n) {
        case UP: {
            if (y > 20) {
                gotoxy(x - 2, y);
                cout << " ";
                gotoxy(x - 2, --y);
                cout << "▶";
            }
            break;
        }

        case DOWN: {
            if (y < 21) {
                gotoxy(x - 2, y);
                cout << " ";
                gotoxy(x - 2, ++y);
                cout << "▶";
            }
            break;
        }

        case SUBMIT: {
            return y - 20;
        }
        }
    }
}

int keyControl() {
    char temp = _getch();

    if (temp == 'w' || temp == 'W') {
        return UP;
    }
    else if (temp == 'a' || temp == 'A') {
        return LEFT;
    }
    else if (temp == 's' || temp == 'S') {
        return DOWN;
    }
    else if (temp == 'd' || temp == 'D') {
        return RIGHT;
    }
    else if (temp == ' ') {
        return SUBMIT;
    }
}


void infor() {
    system("cls");
    cout << "\n";
    cout << "                                                   __      _\n";
    cout << "                                                 o'')}____//\n";
    cout << "                       주사위 게임에 오신 것을    `_/      )\n";
    cout << "                          환영합니다! 멍멍!       (_(_/-(_/\n\n";
    cout << "            ----------------8<---------------------------------------\n\n\n";
    cout << "                     1. 게임은 플레이어와 컴퓨터가 진행합니다. \n\n";
    cout << "                     2. 주사위 말판을 따라 총 3회 회전하면\n";
    cout << "                        게임은 종료됩니다.\n\n";
    cout << "                     3. 말판에 스페셜 칸이 존재, 해당 칸에서\n";
    cout << "                        특별한 룰이 적용됩니다. \n\n";
    cout << "                     4. 1회에 2개의 주사위가 던져지며\n";
    cout << "                        나온 수의 합만큼 말판을 따라 이동합니다. \n\n\n";
    cout << "            컴퓨터보다 먼저 말판을 3회 회전하여 게임에서 승리하세요! \n\n\n";
    cout << "                                                   이제 진짜 게임을 시작합니다\n";
    cout << "                                                       스페이스바를 눌러주세요\n\n";

    while (1) {
        if (keyControl() == SUBMIT) {
            gamein();
        }
    }
}

class Player {
public:
    int x, y;  // 플레이어의 x, y 좌표
    string symbol;  // 플레이어의 표시 문자

    Player(int startX, int startY, string startSymbol) {
        x = startX;
        y = startY;
        symbol = startSymbol;
    }

    virtual void move(int dx, int dy) {
        // 기본 이동
        x += dx;
        y += dy;
    }

    virtual void draw() {
        // 플레이어 현재 위치 문자 출력
        gotoxy(x, y);
        cout << symbol;
    }
};

class Computer : public Player {
public:
    Computer(int startX, int startY) : Player(startX, startY, "뭐") {}

    void draw() override {
        gotoxy(x, y);
        cout << "뭐";
    }
};

int gamein() {

    // 1 이동가능, 0 이동불가능
    int board[7][7] = {
        {1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1},
    };

    int playerX = 0, playerY = 0;
    int computerX = 0, computerY = 0;

    int playerLaps = 0;
    int computerLaps = 0;

    Player player(19 + playerX * 6, 2 + playerY * 3, "얍");
    Computer computer(21 + computerX * 6, 2 + computerY * 3);


    system("cls");
    cout << "\n";
    cout << "                  ┌────┐┌────┐┌────┐┌────┐┌────┐┌────┐┌────┐" << endl;
    cout << "                  │    ││    ││    ││    ││    ││    ││    │       " << endl;
    cout << "                  └────┘└────┘└────┘└────┘└────┘└────┘└────┘" << endl;
    cout << "                  ┌────┐                              ┌────┐" << endl;
    cout << "                  │    │                              │    │       " << endl;
    cout << "                  └────┘                              └────┘" << endl;
    cout << "                  ┌────┐                              ┌────┐" << endl;
    cout << "                  │    │                              │    │       " << endl;
    cout << "                  └────┘                              └────┘" << endl;
    cout << "                  ┌────┐                              ┌────┐" << endl;
    cout << "                  │    │                              │    │       " << endl;
    cout << "                  └────┘                              └────┘" << endl;
    cout << "                  ┌────┐                              ┌────┐" << endl;
    cout << "                  │    │                              │    │       " << endl;
    cout << "                  └────┘                              └────┘" << endl;
    cout << "                  ┌────┐                              ┌────┐" << endl;
    cout << "                  │    │                              │    │       " << endl;
    cout << "                  └────┘                              └────┘" << endl;
    cout << "                  ┌────┐┌────┐┌────┐┌────┐┌────┐┌────┐┌────┐" << endl;
    cout << "                  │    ││    ││    ││    ││    ││    ││    │       " << endl;
    cout << "                  └────┘└────┘└────┘└────┘└────┘└────┘└────┘" << endl;

    player.draw();
    computer.draw();

    while (true) {
        // 플레이어 주사위 굴리기
        gotoxy(0, 23);
        int playerDice = Dice();
        for (int i = 0; i < playerDice; ++i) {
            gotoxy(player.x, player.y);
            cout << " ";

            if (playerX < 6 && board[playerY][playerX + 1] == 1 && playerY == 0) {
                playerX++;
                player.x += 6;
            }
            else if (playerY < 6 && board[playerY + 1][playerX] == 1 && playerX == 6) {
                playerY++;
                player.y += 3;
            }
            else if (playerX > 0 && board[playerY][playerX - 1] == 1) {
                playerX--;
                player.x -= 6;
            }
            else if (playerY > 0 && board[playerY - 1][playerX] == 1) {
                playerY--;
                player.y -= 3;
            }

            player.draw();
            Sleep(500);
        }

        if (playerX == 0 && playerY == 0) {
            playerLaps++;
            if (playerLaps == 3) {
                gotoxy(0, 25);
                cout << "\n당신이 승리했습니다!";
                break;
            }
        }

        // 컴퓨터 주사위 굴리기
        gotoxy(0, 23);
        int computerDice = Dice(true); // 컴퓨터는 엔터 없이 바로 실행
        for (int i = 0; i < computerDice; ++i) {
            gotoxy(computer.x, computer.y);
            cout << " ";

            if (computerX < 6 && board[computerY][computerX + 1] == 1 && computerY == 0) {
                computerX++;
                computer.x += 6;
            }
            else if (computerY < 6 && board[computerY + 1][computerX] == 1 && computerX == 6) {
                computerY++;
                computer.y += 3;
            }
            else if (computerX > 0 && board[computerY][computerX - 1] == 1) {
                computerX--;
                computer.x -= 6;
            }
            else if (computerY > 0 && board[computerY - 1][computerX] == 1) {
                computerY--;
                computer.y -= 3;
            }

            computer.draw();
            Sleep(500);
        }

        if (computerX == 0 && computerY == 0) {
            computerLaps++;
            if (computerLaps == 3) {
                gotoxy(0, 25);
                cout << "\n상대가 승리했습니다!";
                break;
            }
        }
    }

    return 0;
}

int Dice(bool isComputer) {
    srand(static_cast<unsigned int>(time(0)));

    int dice1 = rand() % 6 + 1;
    int dice2 = rand() % 6 + 1;
    int diceSum = dice1 + dice2;

    gotoxy(0, 23);
    cout << string(80, ' ');
    gotoxy(0, 24);
    cout << string(80, ' ');

    // 주사위를 굴리는 주체에 따라 메시지 출력
    gotoxy(0, 23);
    if (!isComputer) { // 플레이어일 경우
        cout << "                    주사위를 굴립니다. 엔터를 눌러주세요!" << endl;
        cin.get();
    }
    else { // 컴퓨터일 경우
        cout << "                         컴퓨터가 주사위를 굴립니다..." << endl;
    }

    gotoxy(0, 24);
    cout << "            | 첫번째 주사위:: " << dice1 << " | "
        << "두번째 주사위:: " << dice2 << " | ★ 합계:: " << diceSum << " |" << endl;

    return diceSum;
}
