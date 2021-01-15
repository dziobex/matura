#include <iostream>
#include <fstream>
#include <string>

using std::string;

string convertToDec(string oct) {
	int dec = 0;
	for (int i = oct.size() - 1; i >= 0; --i)
		dec += (oct[oct.size() - 1 - i] - 48) * pow(8, i);
	return std::to_string(dec);
}

void increasing(string num, int& min, int& max, int& increasingNumbers) {
	for (int i = 1; i < num.size(); ++i)
		if (num[i - 1] > num[i])
			return;
	min = std::atoi(num.c_str()) < min ? std::atoi(num.c_str()) : min;
	max = std::atoi(num.c_str()) > max ? std::atoi(num.c_str()) : max;
	++increasingNumbers;
}

int main()
{
	std::ifstream reader("dane.txt");
	string number;

	int firstEqualsLast = 0, firstEqualsLastDec = 0, max = 0, min = INT_MAX, increasingNumbers = 0;

	for (int i = 0; i < 5000; ++i) {
		reader >> number;
		string dec = convertToDec(number);
		firstEqualsLast += number[0] == number[number.size() - 1];
		firstEqualsLastDec += dec[0] == dec[dec.size() - 1];

		increasing(number, min, max, increasingNumbers);
	}

	std::ofstream writer("wyniki6.txt");
	printf("1:\n%i\n2:\n%i\n3:\n%i\nmin: %i(8)\nmax: %i(8)", firstEqualsLast, firstEqualsLastDec, increasingNumbers, min, max);
	writer << "1:\nliczby, ktorych pierwsza cyfra jest rowna ostatniej: " << firstEqualsLast << "\n2:\nliczby, ktore w systemie dec spelniaja warunek poprzedniego zadania: " << firstEqualsLastDec << "\n3:\nliczba liczb: " << increasingNumbers
		<< "\nmin: " << min << "(8)\nmax: " << max << "(8)";

	return 0;
}