#include <iostream>

int main() {
	srand(time(NULL));
	int n;
	std::cin >> n;
	int *M = new int[n];
	int *K = new int[n+1];
	for (int i = 0; i <= n; ++i)
		K[i] = i;
	int j = 0;
	for (int i = 0; i < n; ++i) {
		j = rand() % ((n+1) - i);
		M[i] = K[j];
		K[j] = K[n - i];
	}
	for (int i = 0; i < n; ++i) {
		std::cout << M[i] << " " ;
	}

	int ans = n, maxN = 0;
	for (int i = 0; i < n; ++i) {
		ans += i;
		maxN += M[i];
	}
	std::cout << std::endl;
	std::cout << ans - maxN << std::endl;
	return 0;
}