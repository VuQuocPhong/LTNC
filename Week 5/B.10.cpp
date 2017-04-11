#include <iostream>
#include <cstdlib>
#include <ctime>

void generateRandNum (int arr[], int length) {
	for (int i = 0; i < length; ++i) {
		arr[i] = rand() % 50;
	}
}

void generateSum (int arr[], int tmpArr[], int length, int tmpIndx, int Indx) {
	if (tmpIndx < 3) {
		for (int i = Indx; i < length; ++i) {
			tmpArr[tmpIndx] = arr[i]; 
			generateSum (arr,tmpArr,length,tmpIndx+1,i+1);
		}
	} else {
		int sum = 0;
		for (int j = 0; j < tmpIndx; ++j) sum += tmpArr[j];
		if (sum % 25 == 0) {
			for (int i = 0; i < 3; ++i) std::cout << tmpArr[i] << " ";
			std::cout << std::endl;
		}
	}
}

void printArr (int arr[], int length) {
	for (int i = 0; i < length; ++i) {
		std::cout << arr[i] << " ";
	}
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int N;
	std::cin >> N;
	int a[N];
	generateRandNum(a,N);
	printArr(a,N);
	int b[3];
	generateSum(a,b,N,0,0);
	return 0;
}