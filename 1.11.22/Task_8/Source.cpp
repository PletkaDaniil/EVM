#include <iostream>

void f(int** M, int rows, int cols) {
	int k = 1;
	for (int i = 0; i < rows; ++i) {
		if (i % 2 == 0)
			for (int j = 0; j < cols; ++j)
				M[i][j] = k + j;
		else
			for (int j = cols - 1; j >= 0; --j)
				M[i][j] = k + (cols - j - 1);
		k += cols;
	}
}

int main() {
	int** M;
	int rows, cols;
	std::cin >> rows >> cols;
	M = new int* [rows];
	for (int i = 0; i < rows; ++i)
		M[i] = new int[cols];
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
			M[i][j] = 0;
	f(M, rows, cols);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j)
			std::cout << M[i][j] << " ";
		std::cout << std::endl;
	}
	for (int i = 0; i < rows; ++i)
		delete[] M[i];
	delete[] M;
	return 0;
}