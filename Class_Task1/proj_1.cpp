#include <iostream>
#include <string>

std::string str = "";

void bin(int x){
	if (x){
		bin(x >> 1);
		str += std::to_string((x & 1));
	}
}

int main(){
	int n, m;
	std::cin >> n >> m;
	bin(n);
	std::string str1 = str;
	std::cout << str;
	std::cout << std::endl;
	str = "";
	bin(m);
	std::cout << str;
	std::cout << std::endl;
	std::string str2 = str;

	return 0;
}
	/*
	int count1 = 0, count2 = 0;
	for (int i = 0; i < 6; ++i) {
		if (i % 2 == 0) count1 += n % 10;
		else count2 += n % 10;
		n /= 10;
	}
	std::cout << count1 << " " << count2 << std::endl;
	*/



	//std::cout << rand();
	/*
	2 способ
	int R = RAND_MAX - 1;
	int r = R / 2;
	double count_R = 0, count_r = 0;
	for (double i = 0; i <= R; ++i) {
		for (double j = 0; j <= R; ++j) {
			if (((i - r) * (i - r) + (j - r) * (j - r)) <= r * r) count_r += 1;
			else count_R += 1;
		}
	}
	std::cout << count_r << " " << count_R << std::endl;
	std::cout << ((count_r * 4) / (count_R+count_r)) << std::endl;
	std::cout << std::setprecision(16) << ((count_r * 4) / (count_R + count_r)) << std::endl;
	*/
	/*
	1 вариант
	double ans = 0;
	for (int i = 1; i <= n; ++i) {
		int k = -1;
		if (i % 2 != 0) {
			k *= (-1);
		}
		ans = ans + k * (1.0 / (2*i - 1));
	}
	//std::cout << ans << std::endl;
	std::cout << std::setprecision(32) << ans << std::endl;
	ans = 0;
	for (int i = 1; i <= n+2; ++i) {
		int k = -1;
		if (i % 2 != 0) {
			k *= (-1);
		}
		ans = ans + k * (1.0 / (2 * i - 1));
	}
	*/
	