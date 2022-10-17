#include <iostream>

int main() {
	int n;
	std::cin >> n;
	//1
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			std::cout << "*" << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	//2
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - i; ++j) {
			std::cout << "*" << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	//3
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			std::cout << " " << " ";
		}
		for (int j = 0; j <= i; ++j) {
			std::cout << "*" << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	//4
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			std::cout << " " << " ";
		}
		for (int j = 0; j < n - i; ++j) {
			std::cout << "*" << " ";
		}
		std::cout << std::endl;
	}
	//5
	for (int i = 0; i < n; ++i) {
		std::cout << std::endl;
		for (int j = 0; j < n - i - 1; ++j) {
			std::cout << " " << " ";
		}
		for (int j = 0; j <= i; ++j) {
			std::cout << "*" << " ";
		}
		for (int j = 0; j < i; ++j) {
			std::cout << "*" << " ";
		}
		for (int j = 0; j < n - i; ++j) {
			std::cout << " " << " ";
		}
	}
	for (int i = 0; i < n; ++i) {
		std::cout << std::endl;
		for (int j = 0; j <= i; ++j) {
			std::cout << " " << " ";
		}
		for (int j = 0; j < n - i - 1; ++j) {
			std::cout << "*" << " ";
		}
		for (int j = 0; j < n - i - 2; ++j) {
			std::cout << "*" << " ";
		}
		for (int j = 0; j < i + 2; ++j) {
			std::cout << " " << " ";
		}
	}
	std::cout << std::endl;
	//6
	int k;
	std::cin >> k;
	for (int i = 0; i < n; ++i) {
		std::cout << std::endl;
		for (int h = 0; h < k; ++h) {
			for (int j = 0; j < n - i - 1; ++j) {
				std::cout << " " << " ";
			}
			for (int j = 0; j <= i; ++j) {
				std::cout << "*" << " ";
			}
			for (int j = 0; j < i; ++j) {
				std::cout << "*" << " ";
			}
			for (int j = 0; j < n - i; ++j) {
				std::cout << " " << " ";
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		std::cout << std::endl;
		for (int h = 0; h < k; ++h) {
			for (int j = 0; j <= i; ++j) {
				std::cout << " " << " ";
			}
			for (int j = 0; j < n - i - 1; ++j) {
				std::cout << "*" << " ";
			}
			for (int j = 0; j < n - i - 2; ++j) {
				std::cout << "*" << " ";
			}
			for (int j = 0; j < i + 2; ++j) {
				std::cout << " " << " ";
			}
		}
	}

	return 0;
}