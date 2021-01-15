#include <iostream>
#include <fstream>

using std::string;

bool counter(string num) {
	int zeros = 0;
	for (char c : num)
		zeros += c == '0';
	return zeros > num.size() - zeros;
}

bool compare(string n1, string n2) {
	if (n1.size() == n2.size())
		return n1 > n2;
	return n1.size() > n2.size();
}

int main()
{
	std::ifstream reader("liczby.txt");

	string number, minStr, maxStr;
	int zeros = 0, div2 = 0, div8 = 0, indexMin = 0, indexMax = 0;

	for (int i = 0; i < 1000; ++i) {
		reader >> number;
		zeros += counter(number);
		div2 += number[number.size() - 1] == '0';
		div8 += number.substr(number.size() - 3, 3) == "000";

		indexMin = i == 0 || compare(minStr, number) ? i : indexMin;
		indexMax = compare(number, maxStr) ? i : indexMax;
		minStr = i == 0 || compare(minStr, number) ? number : minStr;
		maxStr = compare(number, maxStr) ? number : maxStr;
	}

	std::ofstream writer("wynik4.txt");
	printf("1: %i\n2: podzielne przez 2: %i, podzielne przez 8: %i\n3:\nmin: %s, linia: %i\nmax: %s, linia: %i", zeros, div2, div8, minStr.c_str(), indexMin + 1, maxStr.c_str(), indexMax + 1);
	writer << "1: " << zeros << "\n2: podzielne przez 2: " << div2 << ", podzielne przez 8: " << div8 << "\n3: liczba min znajduje sie w linii: " << indexMin + 1 << ", a max: " << indexMax + 1;

	return 0;
}