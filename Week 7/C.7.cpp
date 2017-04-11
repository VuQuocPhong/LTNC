#include <iostream>
#include <ctime>
#include <cstdlib>

const int MAX_SCORE = 6;
const int WIN_POINT = 100;

int getCurPoint() {
    return (rand() % 6 + 1);
}

void printCurTurnResult (int indx, int cur_point, int total) {
    indx = indx % 2 + 1;
    std::cout << "xuc xac nguoi choi " << indx << ": " << cur_point << '\t';
    std::cout << "tong nguoi choi " << indx << ": " << total << '\n';
}

void printFinalResult (int point_1, int point_2) {
    if (point_1 == WIN_POINT) std::cout << "Player 1 win.";
    else if (point_2 == WIN_POINT) std::cout << "Player 2 win.";
    else std::cout << "Both lost";
}

bool isContinue (int point_1, int point_2) {
    return ((point_1 < WIN_POINT||point_2 < WIN_POINT) && (point_1-WIN_POINT)*(point_2-WIN_POINT)!=0);
}

void modeA () {
    int player_indx = 0;
    int point_1 = 0;
    int point_2 = 0;
    while (isContinue(point_1,point_2)) {
        int cur_point = getCurPoint();
        if (player_indx % 2 == 0) {
            point_1 += cur_point;
            printCurTurnResult(player_indx,cur_point,point_1);
        } else {
            point_2 += cur_point;
            printCurTurnResult(player_indx,cur_point,point_2);
        }
        player_indx++;
    }
    printFinalResult(point_1,point_2);
}

void modeB () {
     int player_indx = 0;
    int point_1 = 0;
    int point_2 = 0;
    while (isContinue(point_1,point_2)) {
        int cur_point = getCurPoint();
        if (player_indx % 2 == 0) {
            point_1 += cur_point;
            printCurTurnResult(player_indx,cur_point,point_1);
        } else {
            point_2 += cur_point;
            printCurTurnResult(player_indx,cur_point,point_2);
        }
        if ((player_indx % 2 == 0 && point_1 > point_2) || (player_indx % 2 == 1 && point_2 > point_1)) player_indx++;
    }
    printFinalResult(point_1,point_2);
}

int main() {
    srand(time(0));
    int play_mode;
    std::cin >> play_mode;
    if (play_mode == 1) modeA();
    if (play_mode == 2) modeB();
}
