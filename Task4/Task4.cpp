#include <iostream>
#include <cmath>

double sinx(double x, int n, int k = 0){
    if (k == n) return 0;
    return sin(x) + sinx(sin(x), n, k + 1);
}

int main()
{
    double x;
    std::cout << "x: "; 
    std::cin >> x;
    int n; std::cout << "n: ";
    std::cin >> n;
    std::cout << sinx(x, n) << std::endl;
}