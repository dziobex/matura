#include <iostream>

int counter = 0; // how many times the fib. function will be called?

unsigned long long fibonacci(int n) {
	if (n <= 1)
		return n;
	printf("%i\n", ++counter);
	return fibonacci(n-2) + fibonacci(n-1);
}

int main () {
	int n;
	std::cin >> n;
	std::cout << "Your " << n << "-element in fib. sequence: " << fibonacci(n);
	
	return 0;
}
