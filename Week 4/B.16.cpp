#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>

void getInput (char str[], int length) {
    for (int i = 0; i < length; ++i) std::cin >> str[i];
}

void getSubstr (char str[], char s_str[], int length, int i, int j) {
    int s = 0;
    for (int k = i; k <= j; ++k) {
        s_str[s] = str[k];
        std::cout << s_str[s];
        s++;
    }
}

int calculateTandemRepeats (char str[],int length, int i, int j) {
    char s_str[j-i+1];
    getSubstr(str,s_str,length,i,j);
    int max_repeat = 0;
    int tmp_max = 0;
    int s_length = j-i+1;
    int k = 0;
    int sk = 0;
    while (k < length) {
        if (str[k] == s_str[sk%s_length]) {
            sk++;
            if (sk % s_length == 0) tmp_max++;
            if (tmp_max > max_repeat) max_repeat = tmp_max;
        } else {
            tmp_max = 0;
            sk = 0;
            if (str[k] == s_str[sk%s_length]) {
                sk++;
                if (sk % s_length == 0) tmp_max++;
                if (tmp_max > max_repeat) max_repeat = tmp_max;
            }
        }
        k++;
    }
    return max_repeat;
}

int main() {
    int length;
    int test;
    int i, j;
    std::cin >> length >> test;
    char str[length];
    getInput(str,length);
    for (int t = 0; t < test; t++) {
        std::cin >> i >> j;
        int result = calculateTandemRepeats(str,length,i-1,j-1);
        std::cout << result << '\n';
    }
    system("pause");
}
