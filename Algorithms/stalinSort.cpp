#include <iostream>
#include <cstdlib>
#include <ctime>

// stalin sort algorithm //
void stalinSort(int arr[], int n) {
	int c = 0;
	// let those, who're greater or equal than their first comrades, pass //
	for (int i = 1; i < n; ++i)
		if (arr[c] <= arr[i])
			arr[++c] = arr[i];

	for (int i = 0; i < c + 1; ++i) // print "sorted" array
		printf("%i%s", arr[i], i == c ? "" : ", ");
}

int main()
{
	srand(time(NULL));

	const int N = 10;
	int arr[N];

	printf("before:\n");
	for (int i = 0; i < N; ++i) {
		arr[i] = rand() % 100;
		printf("%i%s", arr[i], i == i - 1 ? "" : ", ");
	}

	printf("\nafter:\n");
	stalinSort(arr, N);
	return 0;
}