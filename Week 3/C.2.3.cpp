#include <iostream>

#define NUM_OF_ELEMENTS 9

int main() {
    int N;
    std::cin >> N;
    int count_arr[NUM_OF_ELEMENTS];
    int num;
    for (int i = 0; i < NUM_OF_ELEMENTS; ++i) {
        count_arr[i] = 0;
    }

    for (int i = 0; i < N; ++i) {
        std::cin >> num;
        count_arr[num]++;
    }

    for (int i = 0; i < NUM_OF_ELEMENTS; ++i) {
        std::cout << "Num of " << i << ": " << count_arr[i] << '\n';
    }
}
