#include <iostream>

int main() {
	int n;
	std::cout << "n: ";
	std::cin >> n;
	n *= 2;
	std::cout << "2n: " << n << std::endl;
	std::cout << std::endl;
	int k = n / 4;
	for (int i = 0; i <= k; ++i) {
		std::cout << "option " << (i + 1) << ": "<< std::endl;
		std::cout << "Number of geese: " << (n - i*4) / 2 << "  Number of rabbits: " << i << std::endl;
		std::cout << std::endl;
	}
}