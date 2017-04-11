#include <iostream>

int main() {
    int N;
    std::cin >> N;
    int Time[N];
    for (int i = 0; i < N; ++i) std::cin >> Time[i];

    for (int i = 0; i < N-1; ++i) {
        if (Time[i] > Time[i+1]) {
            int tmp = Time[i];
            Time[i] = Time[i+1];
            Time[i+1] = tmp;
        }
    }

    int wait_time = 0;

    for (int i = 0; i < N-1; ++i) {
        wait_time += (N-i-1)*Time[i];
    }
    std::cout << wait_time;
}
