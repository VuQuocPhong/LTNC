#include <iostream>
#include <cstdlib>
#define SIZE 5

void getXQueen (int x[]) {
    for ( x[0] = 0; x[0] < SIZE; x[0]++) {
        for ( x[1] = 0; x[1] < SIZE; x[1]++) {
            if (x[1]!=x[0] && abs(x[1]-x[0])!=1) {
                for ( x[2] = 0; x[2] < SIZE; x[2]++) {
                    if (x[2]!=x[0] && x[2]!=x[1] && abs(x[2]-x[0])!=2 && abs(x[2]-x[1])!=1) {
                        for ( x[3] = 0; x[3] < SIZE; x[3]++) {
                            if (x[3]!=x[0] && x[3]!=x[1] && x[3]!=x[2] && abs(x[3]-x[2]!=1) && abs(x[3]-x[0])!=3 && abs(x[3]-x[1])!=2) {
                                x[4] = 1+2+3+4-x[0]-x[1]-x[2]-x[3];
                                if (abs(x[4]-x[0])!=4 && abs(x[4]-x[1])!=3 && abs(x[4]-x[2])!=2 && abs(x[4]-x[3])!=1) {
                                    return;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void printBoard (int x[]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (j == x[i]) std::cout << " ";
            else
                std::cout << '*';
        }
        std::cout << '\n';
    }
}

int main() {
    int x[SIZE];
    getXQueen(x);
    printBoard(x);
}
