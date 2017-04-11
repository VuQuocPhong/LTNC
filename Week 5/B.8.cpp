#include <iostream>

int round (double num) {
	double dec = num - (int)num;
	return (dec < 0.5) ? ((int) num) : ((int)num + 1);
}

int main(int argc, char const *argv[])
{
	double num;
	std::cin >> num;
	int round_num = round(num);
	std::cout << round_num;
	return 0;
}