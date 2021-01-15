#include <iostream>
#include <fstream>
#include <vector>

void sort(std::string& source, int left, int right) {
	if (right <= left)
		return;
	int l = left - 1, r = right + 1, pivot = source[(l + r)/2];
	for (;;) {
		while (source[++l] < pivot);
		while (r > 0 && source[--r] > pivot);
		
		if (l <= r)
			std::swap(source[l], source[r]);
		else
			break;
	}
	if (r > left)
		sort(source, left, r);
	if (l < right)
		sort(source, l, right);
}

int lettersCounter(std::string source) {
	sort(source, 0, source.size() - 1);
	int letts = 1;
	for (int i = 1; i < source.size(); ++i)
		letts += source[i - 1] != source[i];
	return letts;
}

bool correctWord(std::string source) {
	sort(source, 0, source.size() - 1);
	return abs(source[0] - source[source.size() - 1]) <= 10;
}

int main()
{
	std::ifstream reader("sygnaly.txt");
	std::string signal, message, maxSignal;
	std::vector<std::string> correctSignals;
	int max = 0;

	for (int i = 0; i < 1000; ++i) {
		reader >> signal;
		if ((i + 1) % 40 == 0)
			message += signal[9];
		int counter = lettersCounter(signal);
		maxSignal = counter > max ? signal : maxSignal;
		max = counter > max ? counter : max;
		if (correctWord(signal))
			correctSignals.push_back(signal);
	}

	std::ofstream writer("wyniki4.txt");
	writer << "1:\n" << message << "\n\n2:\n" << max << '\n' << maxSignal << "\n\n3:\n";
	for (std::string sig : correctSignals)
		writer << sig << '\n';

	std::cout << "\033[1m:)\033[0m";

	return 0;
}