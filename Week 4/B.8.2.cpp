#include <iostream>

void getInput (int man_height[],int girl_height[],int num_of_pair) {
    for (int i = 0; i < num_of_pair; ++i) std::cin >> man_height[i] >> girl_height[i];
}


bool checkHeight (int man_height[], int girl_height[], int num_of_pair) {
    bool is_true;
    for (int i = 0; i < num_of_pair; i++) {
        is_true = false;
        for (int j = 0; j < num_of_pair; j++) {
            if (man_height[i] > girl_height[j])  is_true = true;
        }
        if (!is_true) return false;
    }
    return true;
}


int main() {
    int num_of_pair;
    std::cin >> num_of_pair;
    int man_height[num_of_pair];
    int girl_height[num_of_pair];

    getInput(man_height, girl_height, num_of_pair);

    bool is_nice_team = checkHeight(man_height, girl_height, num_of_pair);
    is_nice_team ? (std::cout << "YES") : (std::cout << "NO");
}

