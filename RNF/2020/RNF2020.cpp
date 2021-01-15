#include <iostream>
#include <fstream>
#include <vector>

using std::string;

struct Pair { int number = 0; string word; };

bool prime(int num) {
	for (int i = 2; i <= sqrt(num); ++i)
		if (num < i || num % i == 0)
			return false;
	return true;
}

int lower(int num) {
	for (int i = 2;;++i)
		if (prime(i) && prime(num - i))
			return i;
}

string biggest(string source) {
	string max;
	for (int i = 1, start = 0; i < source.size(); ++i)
		if (source[i - 1] != source[i]) {
			if (source.substr(start, i - start).size() > max.size())
				max = source.substr(start, i - start);
			start = i;
		}
	return max;
}

int main()
{
	std::ifstream reader("pary.txt");
	std::ofstream writer("wyniki4.txt");
	string word, words[100];
	int num;
	std::vector<Pair> pairs;

	writer << "1:\n";
	for (int i = 0; i < 100; ++i) {
		reader >> num >> word;
		if (!(num & 1))
			writer << num << ' ' << lower(num) << ' ' << num - lower(num) << '\n';
		words[i] = biggest(word);
		if (num == word.size())
			pairs.push_back(Pair() = { num, word });
	}

	writer << "\n2:\n";
	for (int i = 0; i < 100; ++i)
		writer << words[i] << ' ' << words[i].size() << '\n';

	Pair min = pairs[0];
	for (int i = 1; i < pairs.size(); ++i)
		if (pairs[i].number < min.number || (pairs[i].number == min.number && pairs[i].word < min.word))
			min = pairs[i];

	writer << "\n3: " << min.number << ' ' << min.word;

	std::cout << "\033[1m:)\033[0m";

	return 0;
}