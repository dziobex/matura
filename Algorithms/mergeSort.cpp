#include <iostream>
#include <ctime>
#include <cstdlib>

// Performance: O (n * log2n) //

void merge (int array[20], int p, int q, int r) {
	int l = q - p + 1, h = r - q; // sizes of temporary arrays
	int lower[l], higher[h]; // temp arrays
	int k = p, i = 0, j = 0; // iterators
	
	for (int i = 0; i < l; ++i) // 1st half of an array
		lower[i] = array [p + i];
	
	for (int i = 0; i < h; ++i) // 2nd half of the array
		higher[i] = array [q + 1 + i];
		
	while (i < l && j < h) { // "sorting" the values by comparing 2 arrays
		if (lower[i] <= higher[j]) {
			array[k] = lower[i];
			i++;
		} else {
			array[k] = higher[j];
			j++;
		}
		k++;
	}
	
	// filing the array with the remaining unused values //
	while (i < l) {
		array[k] = lower[i];
		i++;
		k++;
	}
	while (j < h) {
		array[k] = higher[j];
		j++;
		k++;
	}
}

void mergeSort (int array[20], int p, int r) {
	if (p < r) { // sort 2 halves recursively and then merge them
		int q = (p + r) / 2;
		mergeSort(array, p, q);
		mergeSort(array, q + 1, r);
		merge(array, p, q, r);
	}
}

int main () {
	srand(time(NULL));
	
	int array[20];
	std::cout << "Before:\n";
	for (int i = 0; i < 20; ++i) {
		array[i] = rand() % 110 - 10;
		std::cout << array[i] << (i == 19 ? "\n" : ", ");
	}
	
	mergeSort(array, 0, 19);
	std::cout << "\nAfter:\n";
	for (int i = 0; i < 20; ++i) {
		std::cout << array[i] << (i == 19 ? "\n" : ", ");
	}
	
	return 0;
}
