#include <iostream>
#include <cstdlib>
#include <ctime>

int kadane (int array[100]) {
	int sum = 0, maxSum = 0;
	for (int i = 0; i < 100; ++i)
		if (array[i] >= 0) {
			sum += array[i];
			if (sum > maxSum)
				maxSum = sum;
		}
		else
			sum = 0;
	return maxSum;
}

int main () {
	srand(time(NULL));
	int array[100];
	
	printf("Tablica 100-elementowa:\n");
	for (int i = 0; i < 100; ++i) {
		array[i] = rand() % 160 - 20;
		printf("%i%s", array[i], i == 99 ? "\n" : ", ");
	}
	
	printf("\nNajwieksza suma sasiednich liczb: %i", kadane(array));
	
	return 0;
}
