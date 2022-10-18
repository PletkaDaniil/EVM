#include <iostream>
#include <cmath>

int main() {
	int n;
	std::cin >> n;
	int count = log2(n);
	for (int i = 0; i <= count; ++i) {
		int ch = 1 << (count-i);
		if ((ch & n) == 0) std::cout << "0";
		else std::cout << "1";
	}

	return 0;
}