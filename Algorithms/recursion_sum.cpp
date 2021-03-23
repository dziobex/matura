#include <iostream>

int sum(int arr[3], int index) {
	if (index == 0)
		return arr[0];
	return arr[index] + sum(arr, index - 1);
}

int main () {
	int arr[3] = {1, 2, 7};
	std::cout << sum(arr, 2);
	return 0;
}
