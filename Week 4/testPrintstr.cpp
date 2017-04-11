#include <iostream>
#include <string>

int main() {
    std::string str1;
    std::cin >> str1;
    str1[3] = 'a';
    std::cout << str1;
    std::string str2;
    for(int i = 0; i < str1.length(); i++) {
        str2[i] = str1[i];
    }
    std::cout << str2;
}

