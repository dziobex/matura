#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

// Performance: O(log2n) //

// version with recursion //
int binarySearchRecursion (int array[20], int value, int min, int max) {
	if (max - min < 0)
		return -1;
	if (array[(min + max) / 2] == value)
		return (min + max) / 2;
	return binarySearchRecursion (array, value, array[(min + max) / 2] < value ? (min + max) / 2 + 1 : min, // changing min value if the value is higher (getting rid of half of an array)
												array[(min + max) / 2] > value ? (min + max) / 2 - 1 : max); // changing max value if the value is lower (getting rid of half of the array)
}

// version with while loop //
int binarySearch (int array[20], int value) {
	int min = 0, max = 19, index = 0;
	while (max - min >= 0) {
		index = (max + min)/2;
		if (array[index] == value) return index;
		if (array[index] > value)
			max = index - 1;
		else
			min = index + 1;
	}
	return -1;
}

int main () {
	srand(time(NULL));
	
	int array[20];
	for (int i = 0; i < 20; ++i)
		array[i] = rand() % 100;
	
	std::sort(array, array + 20);
	for (int i = 0; i < 20; ++i)
		std::cout << array[i] << (i == 19 ? "\n" : ", ");
	
	int value;
	std::cin >> value;
	std::cout << value << " znajduje sie pod indexem " << binarySearchRecursion(array, value, 0, 19);
	
	return 0;
}
