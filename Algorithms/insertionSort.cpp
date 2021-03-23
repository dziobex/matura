#include <iostream>
#include <ctime>
#include <cstdlib>

// Performance: O(n^2) //

void insert (int array[20], int right, int value) {
	int i = right;
	for (; i >= 0 && value < array[i]; --i) {
		array[i + 1] = array[i];
	}
	array[i + 1] = value;
}

void insertionSort (int array[20]) {
	for (int i = 1; i < 20; ++i)
		insert (array, i - 1, array[i]);
}

int main () {
	srand(time(NULL));
	
	int array[20];
	std::cout << "Before sort:\n";
	for (int i = 0; i < 20; ++i) {
		array[i] = rand() % 110 - 10;
		std::cout << array[i] << (i == 19 ? "\n" : ", ");
	}
	
	insertionSort(array);
	std::cout << "\nAfter sort:\n";
	for (int i = 0; i < 20; ++i)
		std::cout << array[i] << (i == 19 ? "\n" : ", ");
	
	return 0;
}
