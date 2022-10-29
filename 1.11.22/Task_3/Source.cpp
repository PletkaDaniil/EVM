#include <iostream>

int main() {
	int n;
	std::cin >> n;
	int* M = new int[n];
	for (int i = 0; i < n; ++i) {
		std::cin >> M[i];
	}
	bool fl1 = true;
	for (int i = 1; i < n; ++i) {
		if (M[i - 1] <= M[i])
			continue;
		else
			fl1 = false;
	}
	if (fl1) {
		std::cout << "In ascending order" << std::endl;
		delete[] M;
		return 0;
	}
	else {
		bool fl2 = true;
		for (int i = 1; i < n; ++i) {
			if (M[i - 1] >= M[i])
				continue;
			else
				fl2 = false;
		}
		if (fl2) {
			std::cout << "In descending order" << std::endl;
			delete[] M;
			return 0;
		}
		else {
			std::cout << "Without any order" << std::endl;
			delete[] M;
			return 0;
		}
	}
}