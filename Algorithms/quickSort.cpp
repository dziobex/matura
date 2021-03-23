#include <iostream>
#include <cstdlib>
#include <ctime>

// Performace: average case: O (n * log2n); worst case: O (n^2) //

// set new pivot //
int partition (int array[20], int p, int r) {
	int q = p;
	// move lower values to the left side, higher ones go to the right side //
	for (int i = p; i < r; ++i)
		if (array[i] <= array[r]) // move new pivot (q) if i-value is lower or equals the current pivot
			std::swap(array[i], array[q++]);
	std::swap (array[q], array[r]); // put pivot on the q-index (new-pivot index)
	return q;
}

void quickSort(int array[20], int p, int r) {
	if (r > p) {
		// set the pivot and sort 2 subbarrays - lower & higher //
		int q = partition(array, p, r);
		quickSort(array, p, q - 1);
		quickSort(array, q + 1, r);
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
	
	quickSort(array, 0, 19);
	std::cout << "\nAfter:\n";
	for (int i = 0; i < 20; ++i)
		std::cout << array[i] << (i == 19 ? "\n" : ", ");
	
	return 0;
}
