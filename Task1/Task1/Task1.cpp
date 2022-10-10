#include <iostream>
#include <string>

int main() {
	int n;
	std::cin >> n;
	std::string s("");
	while (n > 0) {
		s += std::to_string(n % 2);
		n /= 2;
	}
	std::string result;
	for (int i = s.size()-1; i >= 0; --i){
		result += s[i];
	}
	std::cout << result << std::endl;
}