#include <iostream>

void getInput (int man_height[],int girl_height[],int num_of_pair) {
    for (int i = 0; i < num_of_pair; ++i) std::cin >> man_height[i] >> girl_height[i];
}

void sortHeight (int height[], int length) {
    for (int i = length-1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (height[j] > height[j+1]) {
                int tmp = height[j];
                height[j] = height[j+1];
                height[j+1] = height[j];
            }
        }
    }
}

bool checkHeight (int man_height[], int girl_height[], int num_of_pair) {
    for (int i = 0; i < num_of_pair; i++) {
        if (man_height[i] < girl_height[i]) return false;
    }
    return true;
}

int main() {
    int num_of_pair;
    std::cin >> num_of_pair;
    int man_height[num_of_pair];
    int girl_height[num_of_pair];

    getInput(man_height, girl_height, num_of_pair);
    sortHeight(man_height, num_of_pair);
    sortHeight(girl_height, num_of_pair);

    bool is_nice_team = checkHeight(man_height, girl_height, num_of_pair);
    is_nice_team ? (std::cout << "YES") : (std::cout << "NO");
}
