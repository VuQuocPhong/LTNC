#include <iostream>

int nCr (int n, int r) {
    int nu = 1;
    for (int i = r + 1; i <= n; ++i) {
        nu *= i;
    }
    int de = 1;
    for (int i = 1; i <= n-r; ++i) {
        de *= i;
    }
    return nu/de;
}

int getNumWidth (int num) {
    int width = 1;
    while (num / 10 != 0) {
        width++;
        num = num / 10;
    }
    return width;
}

void printSpace (int width) {
    for (int i = 1; i <= width+1; ++i) {
        std::cout << " ";
    }
}

int main() {
    int level;
    std::cin >> level;

    int max_num = nCr(level,level/2);
    int max_width = getNumWidth(max_num);

    for (int i = 0; i < level; ++i) {
        for (int j = 0; j <= i; ++j) {
            int num = nCr(i,j);
            std::cout << num;
            int num_width = getNumWidth(num);
            int space_width = max_width - num_width;
            printSpace(space_width);
        }
        std::cout << '\n';
    }
}
