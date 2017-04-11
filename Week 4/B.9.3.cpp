#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int y[n];
    for(int i = 0; i < n; ++i) y[i] = -1;
    int x_tmp, y_tmp;
    for(int i = 0; i < n; ++i) {
        std::cin >> x_tmp >> y_tmp;
        if (y[x_tmp] == -1) y[x_tmp] = y_tmp;
        else {
            std::cout << "yes";
            return 1;
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if (y[j] - y[i] == j-i || y[j] == y[i]) {
                std::cout << "yes";
                return 1;
            }
        }
    }
    std::cout << "No";
    return 0;
}
