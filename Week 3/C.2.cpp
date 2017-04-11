#include <iostream>
#include <cstring>

int main() {
    std::string inStr;
    std::cin >> inStr;
    bool isSymmetric = true;
    int length = inStr.length();
    for (int i = 0; i < length; ++i) {
        if (inStr[i] != inStr[length-1-i]) isSymmetric = false;
    }
    isSymmetric ? (std::cout << "Yes") : (std::cout << "No");
    return 0;
}
