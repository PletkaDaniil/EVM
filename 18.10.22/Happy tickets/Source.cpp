#include <iostream>

int main() {
	int n;
	std::cin >> n;
	int count1 = 0, count2 = 0;
	for (int i = 0; i < 6; ++i) {
		if (i % 2 == 0) count1 += n % 10;
		else count2 += n % 10;
		n /= 10;
	}
	//std::cout << count1 << " " << count2 << std::endl;

	if (count1 == count2) std::cout << "The lucky ticket" << std::endl;
	else std::cout << "The unlucky ticket" << std::endl;

	return 0;
}