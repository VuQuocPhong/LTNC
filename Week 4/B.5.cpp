#include <iostream>

void getInput (int arr[], int length) {
    for (int i = 0; i < length; ++i) std::cin >> arr[i];
}

void printOutput (int arr[], int length) {
    for (int i = 0 ; i < length - 1; ++i) {
        for (int j = i + 1; j < length; ++j) {
            if (arr[i] + arr[j] == 0) std::cout << arr[i] << " " << arr[j] << '\n';
        }
    }
}

int main() {
    int arr_length;
    std::cin >> arr_length;
    if (arr_length == 0) {
        return -1;
    }
    int arr[arr_length];
    getInput(arr, arr_length);
    printOutput(arr, arr_length);
}
