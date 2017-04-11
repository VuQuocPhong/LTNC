#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int sum_a, sum_b;
    sum_a = sum_b = 0;
    int num;
    for (int i = 0; i < n; i++) {
            std::cin >> num;
        sum_a += num;
    }
    for (int i = 0; i < n+1; i++) {
        std::cin >> num;
        sum_b += num;
    }
    std::cout << sum_b - sum_a;
}
