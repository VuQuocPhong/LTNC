#include <iostream>

int main() {
    int n;
    std::cin >> n;
    char arr[n];
    for (int i = 0; i < n; ++i) std::cin >> arr[i];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << arr[i] << arr[j] << " ";
            for (int k = 0; k < n; ++k) {
                std::cout << arr[i] << arr[j] << arr[k] << " ";
            }
        }
    }
}
