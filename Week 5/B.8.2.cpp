#include <iostream>
#include <cmath>

int main(int argc, char const *argv[])
{
	double u;
	std::cin >> u;
	int u_round = (u - (int)u > 0.5) ? (ceil(u)) : (floor(u));
	std::cout << u_round;
	return 0;
}