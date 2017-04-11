#include <iostream>

int main() {
    int row, col;
    std::cin >> row >> col;
    int board[row][col];

    char c;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            std::cin >> c;
            board[i][j] = (int) c;
        }
    }

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if(board[i][j] == '.') {
                board[i][j] = 0;
                if (i-1 >= 0 && board[i-1][j] == '*') board[i][j]++;
                if (i+1 < row && board[i+1][j] == '*') board[i][j]++;
                if (j-1 >= 0 && board[i][j-1] == '*') board[i][j]++;
                if (j+1 < col && board[i][j+1] == '*') board[i][j]++;
                if (i-1 >= 0 && j-1 >= 0 && board[i-1][j-1] == '*') board[i][j]++;
                if (i+1 < row && j+1 < col && board[i+1][j+1] == '*') board[i][j]++;
                if (i+1 < row && j-1 >= 0 && board[i+1][j-1] == '*') board[i][j]++;
                if (i-1 >= 0 && j+1 < col && board[i-1][j+1] == '*') board[i][j]++;
            }
        }
    }
    std::cout << '\n';
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
           if (board[i][j] == '*') std::cout << '*' << ' ';
           else
            std::cout << board[i][j] << ' ';
        }
        std::cout << '\n';
    }
}
