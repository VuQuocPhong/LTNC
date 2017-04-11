#include <iostream>

static int numPalindrome (int num);
static int constructPalindrome (int palPrefix, int numLenght);


int main() {
    int a, b;
    int n;
    a = b = n = 0;
    std::cin >> n;
    while (n > 0) {
        std::cin >> a >> b;
        std::cout << numPalindrome(b) << " " << numPalindrome(a-1) << '\n';
        n--;
    }
    return 0;
}

static int numPalindrome (int num) {
    int numLength = 0;
    int palLength = 0;
    int palPrefix = 0;
    int temp = 0;

    for (numLength = 0, temp = num; temp != 0; temp /= 10) {
        numLength++;
    }
    palLength = (numLength+1) / 2;
    palPrefix = num;
    for (int i = 0; i < numLength-palLength; i++) {
        palPrefix /= 10;
    }

    if (constructPalindrome(palPrefix,palLength) > num)
        palPrefix--;

    palPrefix *= 2;
    if (numLength % 2 != 0) {
        int adjustment = 1;
        for (int i = 1; i < palLength; ++i) {
            adjustment *= 10;
        }
        palPrefix -= (palPrefix/2 - adjustment + 1);
    } else {
        int adjustment = 1;
        for (int i = 0; i < palLength; ++i) {
            adjustment *= 10;
        }
        palPrefix += (adjustment - 1 - palPrefix/2);
    }
    return palPrefix;
}

static int constructPalindrome (int palPrefix, int numLength) {
    int front_ = palPrefix;
    int back_ = 0;

    if (numLength % 2 != 0)
        palPrefix /= 10;

    while (palPrefix != 0) {
        back_ = back_ * 10 + palPrefix % 10;
        palPrefix /= 10;
        front_ *= 10;
    }
    return front_ + back_;
}
