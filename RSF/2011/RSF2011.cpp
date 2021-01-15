#include <iostream>
#include <fstream>

using std::string;

int fromBin(string bin) { // I rejected by humanity with BITSET library
	int dec = 0;
	for (int i = bin.size() - 1; i >= 0; --i)
		dec += (bin[i] - 48) * pow(2, bin.size() - 1 - i);
	return dec;
}

string toBin(int dec) {
	string bin;
	while (dec > 0) {
		bin = (char)(dec % 2 + 48) + bin;
		dec /= 2;
	}
	return bin;
}

int main()
{
	std::ifstream reader("liczby.txt");

	string word, maxBin;
	int even = 0, digits9 = 0;
	for (int i = 0; i < 1000; ++i) {
		reader >> word;
		even += !(word[word.size() - 1] & 1);
		digits9 += word.size() == 9 ? fromBin(word) : 0;

		if (fromBin(word) > fromBin(maxBin))
			maxBin = word;
	}

	std::ofstream writer("zadanie6.txt");
	printf("1. %i\n2. %s(2) = %i(10)\n3. %s", even, maxBin.c_str(), fromBin(maxBin), toBin(digits9).c_str());
	writer << "1. parzyste: " << even << "\n2. max liczba: " << maxBin << "(2) = " << fromBin(maxBin) << "(10)\n3. suma liczb o dlugosci 9: " << toBin(digits9) << "(2)";

	return 0;
}