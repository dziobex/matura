#include <iostream>

void sieveErastothenes (bool array[], int size) {
	printf("Liczby piersze z przedzialu 2-%i:\n", size);
	for (int i = 2; i < size; ++i)
		if (!array[i]) {
			for (int j = i * 2; j < size; j += i)
				array[j] = true;
			printf("%i%s", i, i == size - 1 ? "\n" : ", ");
		}
}

int main () {
	
	bool array[100]{};
	sieveErastothenes(array, 100);
	
	return 0;
}
