#include <iostream>

// Using loop //
int euclideanLoop(int n1, int n2) {
	while (n1 != n2) {
		n1 = n1 > n2 ? n1 - n2 : n1;
		n2 = n2 > n1 ? n2 - n1 : n2;
	}
	return n1;
}

// Using resursion //
int euclideanRecursion (int n1, int n2) {
	if (n1 == n2)
		return n1;
	return euclideanRecursion(n1 > n2 ? n1 - n2 : n1, n2 > n1 ? n2 - n1 : n2);
}

int main () {
	int n1, n2;
	std::cin >> n1 >> n2;
	
	printf("NWD (%i, %i) = %i", n1, n2, euclideanRecursion(n1, n2));
	
	return 0;
}
