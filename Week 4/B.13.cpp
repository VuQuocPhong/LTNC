#include <iostream>

int main() {
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int n;
        std::cin >> n;
        int sum_right, sum_left;
        sum_left = sum_right = 0;
        int a[n];
        bool isFound = false;
        if (n==1) isFound = true;
        for(int i = 0; i < n; i++) {
            std::cin >> a[i];
            sum_right += a[i];
        }

        sum_right -= a[0];

        for(int i = 0; i < n-1; i++) {
            if (sum_left == sum_right) {
                isFound = true;
                break;
            }
            sum_left += a[i];
            sum_right -= a[i+1];
        }

        isFound ? (std::cout << "YES\n") : (std::cout << "NO\n");
    }
    return 0;
}
