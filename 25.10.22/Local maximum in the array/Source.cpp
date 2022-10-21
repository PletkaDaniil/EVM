#include <iostream>

int main() {
	srand(time(NULL));
	int n;
	std::cin >> n;
	int* M = new int[n];
	for (int i = 0; i < n; ++i) {
		M[i] = rand() % 100 + 1;
	}
	for (int i = 0; i < n; ++i) {
		std::cout << M[i] << " " ;
	}
	bool F = true;
	for (int i = 1; i < n - 1; ++i) {
		if (M[i - 1] < M[i] && M[i] > M[i + 1]) {
			std::cout << std::endl;
			std::cout << i+1 << std::endl;
			F = false;
			break;
		}
	}
	if (F) {
		std::cout << std::endl;
		std::cout << "No local max" << std::endl;
	}
	return 0;
}