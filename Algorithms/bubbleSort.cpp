#include <iostream>
#include <ctime>
#include <cstdlib>

// Performance: O (n^2) //

void bubbleSort(int arr[], int size) {
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size - 1 - i; ++j)
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
}

int main () {
	srand(time(NULL));
	int arr[100];
	
	printf("Before sort:\n");
	for (int i = 0; i < 100; ++i) {
		arr[i] = rand() % 160 - 10;
		printf("%i%s", arr[i], i == 99 ? "\n" : ", ");
	}
	
	bubbleSort(arr, 100);
	printf("\nAfter sort:\n");
	for (int i = 0; i < 100; ++i)
		printf("%i%s", arr[i], i == 99 ? "\n" : " ");
	
	return 0;
}
