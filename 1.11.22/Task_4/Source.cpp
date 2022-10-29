#include <iostream>

void f(int** M, int rows, int cols) {
	srand(time(NULL));
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
			M[i][j] = rand()%100 + 1;
}

int main() {
	int** M;
	int rows, cols;
	std::cin >> rows >> cols;
	M = new int* [rows];
	for (int i = 0; i < rows; ++i)
		M[i] = new int[cols];
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