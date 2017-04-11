#include <iostream>

void getInput (int arr[], int length) {
    for (int i = 0; i < length; ++i) {
        std::cin >> arr[i];
    }
}

float CalculateAvg (int arr[], int length) {
    int sum = 0;
    for (int i = 0; i < length; ++i) {
        sum += arr[i];
    }
    return (float)sum/length;
}

float CalculateVariance (int arr[], int length, float Avg) {
    float square_sum = 0;
    for (int i = 0; i < length; ++i) {
        square_sum += (Avg-arr[i])*(Avg-arr[i]);
    }
    return square_sum/(length-1);
}

int main() {
    int N;
    std::cin >> N;
    int num_arr[N];
    getInput(num_arr,N);
    float Avg = CalculateAvg(num_arr,N);
    float Var = CalculateVariance(num_arr,N,Avg);
    std::cout << Avg << " " << Var;
}
