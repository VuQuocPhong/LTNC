#include <iostream>

int main() {
    int N;
    std::cin >> N;
    int x[N], y[N];
    for (int i = 0; i < N; ++i) {
        std::cin >> x[i] >> y[i];
    }

    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++i) {
            if (x[i]==x[j] || y[i]==y[j] || (x[j]-x[i] == y[j]-y[i])) {
                std::cout << "Yes";
                return 1;
            }
        }
    }
    std::cout << "No";
    return 0;
}
