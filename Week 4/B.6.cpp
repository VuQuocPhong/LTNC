#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) std::cin >> arr[i];

    for (int i = 0; i < n - 2; ++i) {
        for (int j = i+1; j < n - 1; ++j) {
            for (int k = j+1; k < n; ++k) {
                if (arr[i]+arr[j]+arr[k] == 0) std::cout << arr[i] << " " << arr[j] << " " << arr[k] << '\n';
            }
        }
    }
}
