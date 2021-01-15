#include <iostream>
#include <vector>
#include <fstream>

using std::string;

void checker(string number, int& zeros, int& blocks, int& max0Block) {
	int current0Block = number[0] == '0';

	for (int i = 1; i < number.size(); ++i) {
		current0Block = number[i] != '0' ? 0 : current0Block + 1;
		max0Block = current0Block > max0Block ? current0Block : max0Block;
		zeros += number[i] == '0';
		blocks += number[i - 1] != number[i];
	}
}

int main()
{
	std::fstream reader("slowa.txt", std::ios::in), writer("wynik4.txt", std::ios::out);

	string number;
	int moreZeros = 0, blocks2 = 0, maxBlock = 0;
	std::vector<string> maxNumbers;

	for (int i = 0; i < 1000; ++i) {
		reader >> number;

		int zeros = number[0] == '0', blocks = 1, max0Block = 0;
		checker(number, zeros, blocks, max0Block);

		moreZeros += zeros > number.size() - zeros;
		blocks2 += (blocks == 2 && number[0] == '0');

		if (max0Block >= maxBlock) {
			if (max0Block > maxBlock)
				maxNumbers.clear();
			maxBlock = max0Block;
			maxNumbers.push_back(number);
		}
	}

	printf("1:\n%i\n2:\n%i\n3:\n%i\n", moreZeros, blocks2, maxBlock);
	writer << "1:\nliczba liczb, w ktorych liczba 0 jest wieksza od liczby 1: " << moreZeros << "\n2:\nliczba liczb skaladajacych sie z dwoch blokow  (0 i 1): " << blocks2 << "\n3:\nmax blok: " << maxBlock << "\nliczby z max blokiem:\n";
	for (auto num : maxNumbers) {
		printf("%s\n", num.c_str());
		writer << num << '\n';
	}

	reader.close();
	writer.close();

	return 0;
}