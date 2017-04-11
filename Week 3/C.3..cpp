#include <iostream>
#define MAX_NUM_OF_DIGITS 100000;

int countNumOfDigits (int num) {
    int num_of_digits = 1;
    while (num / (num_of_digits*10) != 0) {
        num_of_digits++;
    }
    return num_of_digits;
}

bool isPalindrome (int num) {
    int num_of_digits = countNumOfDigits(num);
    int endn = 10;
    int startn = (num_of_digits - 1)*10;
    while (startn >= endn) {
        if (num / startn != num % endn) return false;
        startn = startn/10;
        endn = endn*10;
    }
    return true;
}

int countPalindrome (int a, int b) {
    int result = 0;
    for (int i = a; i <= b; ++i) {
        if (isPalindrome(i)) result++;
    }
    return result;
}

int main() {
    int T;
    std::cin >> T;
    int a, b;
    for (int i = 1; i <= T; ++i) {
        std::cin >> a >> b;
        int result = countPalindrome(a,b);
        std::cout << result << '\n';
    }
}
