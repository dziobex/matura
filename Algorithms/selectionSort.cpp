#include <iostream>
#include <ctime>
#include <cstdlib>

// Performance: O(n^2) //

int findMin (int array[20], int startIndex) {
	int min = startIndex;
	for (int i = startIndex + 1; i < 20; ++i)
		if (array[i] < array[min])
			min = i;
	return min;
}

void selectionSort(int array[20]) {
	for (int i = 0; i < 20; ++i) {
		int min = findMin(array, i);
		std::swap (array[i], array[min]);
	}
}

int main () {
	srand(time(NULL));
	int array[20];
	std::cout << "Before sort:\n";
	for (int i = 0; i < 20; ++i) {
		array[i] = rand() % 100;
		std::cout << array[i] << (i == 19 ? "\n" : ", ");
	}
	
	selectionSort(array);
	std::cout << "\nAfter sort:\n";
	for (int i = 0; i < 20; ++i)
		std::cout << array[i] << (i == 19 ? "\n" : ", ");
		
	return 0;
}
