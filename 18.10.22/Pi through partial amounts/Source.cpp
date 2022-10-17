#include <iostream>
#include <iomanip>

int main() {
	long n = 400000000;
	double ans = 0;
	for (int i = 1; i <= n; ++i) {
		int k = -1;
		if (i % 2 != 0) {
			k *= (-1);
		}
		ans = ans + k * (1.0 / (2 * i - 1));
	}
	std::cout << std::setprecision(16) << ans << std::endl;
	ans = 0;
	for (int i = 1; i <= n + 2; ++i) {
		int k = -1;
		if (i % 2 != 0) {
			k *= (-1);
		}
		ans = ans + k * (1.0 / (2 * i - 1));
	}
	std::cout << std::setprecision(16) << ans << std::endl;

	std::cout << "Pi = " << ans * 4 << std::endl;

	return 0;
}