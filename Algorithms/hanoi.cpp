#include <iostream>
#include <math.h>

// params: "sender" pog, helper pog, "aim" pog //
void hanoi (int n, char from, char aux, char to) {
	if (n == 0)
		return;
	hanoi (n - 1, from, to, aux);
	printf("%c -> %c\n", from, to);
	hanoi (n - 1, aux, from, to);
}

int main () {
	
	int n;
	std::cin >> n;
	
	printf("TRIALS: %i\n", (int)pow(2, n) - 1);
	hanoi (n, 'A', 'B', 'C');
	
	return 0;
}
