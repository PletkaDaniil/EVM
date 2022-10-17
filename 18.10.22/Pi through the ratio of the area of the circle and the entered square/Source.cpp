#include <iostream>
#include <iomanip>

int main(){
	int R = RAND_MAX - 1;
	int r = R / 2;
	double count_R = 0, count_r = 0;
	for (double i = 0; i <= R; ++i) {
		for (double j = 0; j <= R; ++j) {
			if (((i - r) * (i - r) + (j - r) * (j - r)) <= r * r) count_r += 1;
			else count_R += 1;
		}
	}
	std::cout << "Pi = " << ((count_r * 4) / (count_R + count_r)) << std::endl;

	return 0;
}