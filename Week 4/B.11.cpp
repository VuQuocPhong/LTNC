#include <iostream>

int main() {
    int n;
    std::cin >> n;
    std::string pass[n];

    for (int i = 0; i < n; ++i) {
        std::cin >> pass[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            bool found = true;
            int ilength = pass[i].length();
            int jlength = pass[j].length();
            if (ilength == jlength && ilength % 2 == 1) {
                int k;
                for (k = 0; k <= jlength/2; ++k) {
                    if (pass[i][k] != pass[j][jlength-1-k]) {
                        found = false;
                    }
                }

                if (found) std::cout << jlength << " " << pass[i][k-1];
            }
        }
    }
}
