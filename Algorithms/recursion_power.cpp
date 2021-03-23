#include <iostream>

int power (int x, int n) {
	if (n == 0) return 1;
	if (n < 0) return -n;
	return x * power (x, n - 1);
}

int main () {
	int x, n;
	std::cin >> x >> n;
	std::cout << n << "-power of " << x << ": " << power (x, n);
	
	return 0;
}
