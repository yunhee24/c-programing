#include "main.h"
#include "game.h"

using namespace std;


int main() {
    while (1) {
        title();
        int menuCode = menu();
        if (menuCode == 0) {            // 시작하기
            infor();
        }
        else if (menuCode == 1) {       // 종료하기
            return 0;
        }
        system("cls");

    }
    return 0;
}
