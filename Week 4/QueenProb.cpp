#include <iostream>

void run (int i, bool main_diag[], bool diag[], bool col[], int n) {
    for (int j = 1; i <= n; ++i) {
        main_diag[i+j] = false;
    }
}

int main() {
    int n;
    std::cin >> n;
    bool main_diag[n+1] = {true}, diag[n+1] = {true}, col[n+1] = {true};
    run(1,main_diag,diag,col,n);
}
