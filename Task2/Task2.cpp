#include <iostream>

int main() {
	int n;
	std::cin >> n;
	int k = n - 1;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if ((k * k + i * i) <= n * n) {
			ans += k;
		}
		else {
			while ((k * k + i * i) > n * n) {
				k -= 1;
			}
			ans += k;
		}
	}
	ans *= 4;
	ans += n * 4 + 1;
	std::cout << ans << std::endl;
}