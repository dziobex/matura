#include <iostream>
#include <fstream>

using std::string;

string reverse(string source) {
	string result = "";
	for (int i = source.size() - 1; i >= 0; --i)
		result += source[i];
	return result;
}

string newPassword(string source, string& max, string& min, string& if12, int& sum, bool autoMin) {
	int stopIndex = source.size() + 1;
	while (source.substr(0, --stopIndex) != reverse(source.substr(0, stopIndex)));

	string res = reverse(source.substr(stopIndex, source.size() - stopIndex)) + source.substr(0, stopIndex) + source.substr(stopIndex, source.size() - stopIndex);
	min = autoMin || res.size() < min.size() ? res : min;
	max = res.size() > max.size() ? res : max;
	sum += res.size();
	if12 = res.size() == 12 ? if12 + res + " " : if12;

	return res;
}

int main()
{
	std::ifstream reader("slowa.txt");
	std::ofstream password_writer_a("hasla_a.txt"), password_writer_b("hasla_b.txt"),
		words_writer_a("slowa_a.txt"), words_writer_b("slowa_b.txt");
	string password, minA, maxA, minB, maxB, if12 = "";
	int sum = 0;

	for (int i = 0; i < 1000; ++i) {
		reader >> password;
		minA = i == 0 || password.size() < minA.size() ? password : minA;
		maxA = password.size() > maxA.size() ? password : maxA;

		password_writer_a << reverse(password) << '\n';
		password_writer_b << newPassword(password, maxB, minB, if12, sum, i == 0) << '\n';
	}

	words_writer_a << "max: " << maxA << "\nmin: " << minA;
	words_writer_b << "1:\nhasla, ktorych dlugosc wynosi 12:\n" << if12 << "\n2:\nmax: " << maxB << "\nmin: " << minB << "\n3:\nsuma dlugosci wszystkich hasel: " << sum;

	string str = "DONE.";
	for (int i = 31, j = 0; i <= 37; i += (i == 33 ? 2 : 1), ++j)
		printf("\033[%im%c\033[0m", i, str[j]);

	return 0;
}