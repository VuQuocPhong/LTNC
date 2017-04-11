#include <iostream>

int main(){
    int board_size;
    std::cin >> board_size;
    int board[board_size][board_size];
    for (int i = 0; i < board_size; ++i) {
        for (int j = 0; j < board_size; ++j) {
            board[i][j] = 0;
        }
    }
    int i, j;
    i = j = 0;
    int count_val = 1;
    while (count_val <= board_size*board_size) {
        while (board[i][j] == 0 && j < board_size) {
            board[i][j] = count_val;
            count_val++;
            j++;
        }
        j--;
        i++;
        while (board[i][j] == 0 && i < board_size) {
            board[i][j] = count_val;
            count_val++;
            i++;
        }
        i--;
        j--;

        while (board[i][j] == 0 && j >= 0) {
            board[i][j] = count_val;
            count_val++;
            j--;
        }
        j++;
        i--;

        while (board[i][j] == 0 && i >= 0) {
            board[i][j] = count_val;
            count_val++;
            i--;
        }
        i++;
        j++;

    }

    for (int i = 0; i < board_size; ++i) {
        for (int j = 0; j < board_size; ++j) {
            std::cout << board[i][j] << ' ';
        }
        std::cout << '\n';
    }
}
