#include <iostream>
#include <string>
#include <fstream>
#include <chrono>

using std::string;

void quicksort(int* source, int left, int right) { // time ~ O(log n)
	if (right <= left)
		return;

	int l = left - 1, r = right + 1, pivot = source[(left + right) / 2];

	for (;;) {
		while (source[++l] < pivot) {}
		while (source[--r] > pivot) {}

		if (l <= r)
			std::swap(source[l], source[r]);
		else
			break;
	}

	if (l < right)
		quicksort(source, l, right);
	if (r > left)
		quicksort(source, left, r);
}

int popularNums(int* source, int size) {
	quicksort(source, 0, size - 1);

	int counter = 0, maxCounter = 0, max = source[0];
	for (int i = 1; i < size; ++i)
		if (source[i - 1] == source[i])
			++counter;
		else {
			if (counter > maxCounter) {
				maxCounter = counter;
				max = source[i - 1];
			}
			counter = 1;
		}
	return max;
}

int getMax(int* source, int size) {
	int maxElement = 0;
	int* sums = new int[size] {};

	for (int i = 0; i < size; ++i)
		for (int j = 0; j <= i; ++j) {
			sums[j] += source[i];
			maxElement = sums[j] > maxElement ? sums[j] : maxElement;
		}

	return maxElement;
}

int main()
{
	std::ofstream writer("Raport.txt");
	string ex2, ex3;
	int num = 0, max = getMax(new int[6]{ 1, -2, 6, -5, 7, -3 }, 6);
	int* data = new int[10000]{};

	printf("1: %i\n", max);
	writer << "1:\nnajlepsza suma: " << max << '\n';

	for (int i = 1; i <= 3; ++i) {
		{
			std::ifstream reader("dane5-" + std::to_string(i) + ".txt");

			int counter = -1;
			while (!reader.eof()) reader >> data[++counter];

			printf("%i: %i\n", i, getMax(data, counter));

			auto start = std::chrono::system_clock::now();
			int popular = popularNums(data, counter);
			auto stop = std::chrono::system_clock::now();

			printf("POPULAR %i: %i, time: %llu milisec\n", i, popular, std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count());

			ex2 += "dane5-" + std::to_string(i) + ".txt: " + std::to_string(getMax(data, counter)) + '\n';
			ex3 += "dane5-" + std::to_string(i) + ".txt: " + std::to_string(popular) + ", czas: " + std::to_string(std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count()) + " milisec\n";
		}
	}

	writer << "2:\n" << ex2 << "3:\n" << ex3;
	writer.close();

	return 0;
}