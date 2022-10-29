#include <iostream>

int main() {
	srand(time(NULL));
	int n, A;
	std::cin >> n >> A;
	int* M = new int[n];
	for (int i = 0; i < n; ++i) {
		M[i] = rand() % 100 + 1;
	}
	for (int i = 0; i < n; ++i)
		std::cout << M[i] << " ";
	int* B = new int[n];
	for (int i = 0; i < n; ++i) {
		B[i] = 0;
	}
	int m = n, i = 0, j = 0;
	while (m > 0) {
		if (M[i] < A) {
			B[j] = M[i];
			j += 1;
		}
		m -= 1;
		i += 1;
	}
	m = n, i = 0;
	while (m > 0) {
		if (M[i] >= A) {
			B[j] = M[i];
			j += 1;
		}
		m -= 1;
		i += 1;
	}
	std::cout << std::endl;
	for (int i = 0; i < n; ++i)
		std::cout << B[i] << " ";
	delete[] M;
	delete[] B;
	return 0;
}