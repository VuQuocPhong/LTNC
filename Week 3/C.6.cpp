#include <iostream>
#include <stdlib.h>

int main() {
    int square_size;
    std::cin >> square_size;
    int matrix[square_size][square_size];
    for (int i = 0; i < square_size; ++i) {
        for (int j = 0; j < square_size; ++j) {
            matrix[i][j] = 0;
        }
    }
    int cur_y = 0;
    int cur_x = square_size/2;
    int count_val = 1;
    while (matrix[cur_y][cur_x] == 0) {
        matrix[cur_y][cur_x] = count_val;
        count_val++;
        int cur_x_temp = (cur_x+1) % square_size;
        int cur_y_temp = cur_y - 1;
        if (cur_y_temp < 0) cur_y_temp = square_size-1;
        if (matrix[cur_y_temp][cur_x_temp] == 0) {
            cur_x = cur_x_temp;
            cur_y = cur_y_temp;
        } else {
            cur_y = (cur_y+1) % square_size;
        }
    }

    for (int i = 0; i < square_size; ++i) {
        for (int j = 0; j < square_size; ++j) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
}
