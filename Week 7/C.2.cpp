#include <iostream>
#include <cstdlib>
#include <ctime>

const int RACE_LENGTH = 70;

bool isRaceContinue (int rp, int tp) {
    return (rp < RACE_LENGTH && tp < RACE_LENGTH);
}

void printWinner (int rp, int tp) {
    if (rp > tp) std::cout << "Rabit won!";
    else if (tp > rp) std::cout << "Turtle won!";
    else std::cout << "Tie match!";
}

int main() {
    srand(time(0));
    int Rabit_point = 0;
    int Turtle_point = 0;
    while (isRaceContinue(Rabit_point, Turtle_point)) {
        int rand_chance = rand() % 60 + 1;
        if (rand_chance <= 15) Turtle_point += 3;
        if (rand_chance <= 24 && rand_chance >= 16) {
            Rabit_point++;
            Turtle_point++;
        }
        if (rand_chance >= 17 && rand_chance <= 22) Turtle_point -= 6;
        if (rand_chance >= 23 && rand_chance <= 28) Rabit_point += 9;
        if (rand_chance >= 29 && rand_chance <= 34) Rabit_point -= 2;
        if (rand_chance >= 35 && rand_chance <= 37) Rabit_point -= 12;
        if (Turtle_point < 0) Turtle_point = 0;
        if (Rabit_point < 0) Rabit_point = 0;
        std::cout << "Rabit at: " << Rabit_point << '\n';
        std::cout << "Turtle at: " << Turtle_point << '\n';
    }
    std::cout << '\n';
    printWinner(Rabit_point,Turtle_point);
}
