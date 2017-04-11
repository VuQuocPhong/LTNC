#include <iostream>

#define MAX 2870

void getInput (int k[], int n[], int &length) {
	int i = 0;
	do {
		std::cin >> k[i] >> n[i];
		i++;
		length++;
	} while (k[i-1] != -1 || n[i-1] != -1);
}

int f(int num) {
	if(num == 0) return 1;
	return num*f(num-1);
}

void calculate (int k[], int n[], int length) {
	for (int i = 0; i < length; ++i) {
		if (k[i] <= n[i] && k[i] >= 0 && n[i] > 0) {
			std::cout << n[i] << "C" << k[i] << " = ";
			int result = f(n[i])/(f(n[i]-k[i])*f(k[i]));
			std::cout << result << '\n';
		} 
	}
}

int main(int argc, char const *argv[])
{
	int k[MAX];
	int n[MAX];
	int length = 0;
	getInput(k,n,length);
	calculate(k,n,length);
	return 0;
}