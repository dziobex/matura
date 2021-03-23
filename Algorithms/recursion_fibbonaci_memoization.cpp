#include <iostream>

int memory[100] {};
int counter = 0; // how many times the fib. function will be called?
// I compared this program with that one without memoization technique //
// The results (for 17 as n) were quite different... this program made 16 calls and the 2nd one - 2583 //
// But still, using loop in solving fib. sequence would be a better solution (in terms of memory and time usage lol) //

int fibbonaci (int n) {
	if (n == 0 || n == 1)
		return n;
	if (memory[n - 1] == 0)
		memory[n - 1] = fibbonaci(n - 1);
	if (memory[n - 2] == 0)
		memory[n - 2] = fibbonaci(n - 2);
	printf("%i\n", ++counter);
	return memory[n - 1] + memory[n - 2];
}

int main () {
	int n;
	std::cin >> n;
	std::cout << "\n" << fibbonaci (n);
	
	return 0;
}
