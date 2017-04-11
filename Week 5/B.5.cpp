#include <iostream>

int findGCDof (int a, int b) {
	if (b == 0) return a;
	else return (b,a%b);

}

int main(int argc, char const *argv[])
{
	int a, b;
	std::cin >> a >> b;
	if (a < b) {
		int tmp = b; 
		b = a;
		a = tmp;
	}
	int gcd = findGCDof(a,b);
	std::cout << gcd << '\n';
	(gcd == 1) ? (std::cout << "YES") : (std::cout << "NO");
	return 0;
}