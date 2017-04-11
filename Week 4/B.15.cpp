#include <iostream>


void getInput (char* board, int width, int height) {
    for (int i = 0; i < height; ++i)
        for (int j = 0; j < width; ++j) std::cin >> *(board+i*width+j);
}

void updatePossiblePos (char* board, int width,int height, int x, int y) {
    *(board+y*width+x) = 'Y';
    if (y < height-1) {
        if (*(board+(y+1)*width+x) == 'E') updatePossiblePos((char*) board, width,height, x, y+1);
        if (x > 0) {
            if ((*(board+(y+1)*width+x) != 'R' || *(board+y*width+x-1) != 'R') && *(board+(y+1)*width+x-1) != 'R') {
                updatePossiblePos((char*) board, width, height, x-1, y+1);
            }
        }
        if (x < width-1) {
            if ((*(board+(y+1)*width+x) != 'R' || *(board+y*width+x+1) != 'R') && *(board+(y+1)*width+x+1) != 'R') {
                updatePossiblePos((char*) board, width,height, x+1, y+1);
            }
        }
    }
}

int main() {
    int width, height;
    std::cin >> width >> height;
    char board[height][width];
    getInput((char*) board, width, height);
    int yplayer = 0;
    int xplayer;
    for (int i = 0; i < width; ++i) {
        if (board[0][i] == 'Y') xplayer = i;
    }
    updatePossiblePos((char*) board, width, height, xplayer, yplayer);
    bool is_pass = false;
    for (int i = 0; i < width; i++) {
        if (board[height-1][i] == 'Y') is_pass = true;
    }
    is_pass ? (std::cout << "YES") : (std::cout<< "NO");

//    std::cout << '\n';
//    for (int i = 0; i < height; ++i) {
//        for (int j = 0 ; j < width; ++j) {
//            std::cout << board[i][j];
//        }
//        std::cout << '\n';
//    }
}
