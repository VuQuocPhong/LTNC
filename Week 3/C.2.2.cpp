#include <iostream>

int main() {
    int N;
    std::cin >> N;
    int num;
    int smax, smin;
    int sum_of_even = 0;
    int odd_count = 0;

    for (int i = 0; i < N; ++i) {
        std::cin >> num;
        if (i == 0) {
            smax = smin = num;
        }
        if (num > smax) smax = num;
        if (num < smin) smin = num;
        (num % 2 == 0) ? (sum_of_even += num) : (odd_count++);
    }
    std::cout << "Max: " << smax << "  " << "Min: " << smin << '\n'
                << "Sum of even elements: " << sum_of_even << '\n'
                << "Number of odd elements: " << odd_count << '\n';
}
