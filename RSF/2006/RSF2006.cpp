#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using std::string;

string reverse(string source) {
	string result;
	for (int i = source.size() - 1; i >= 0; --i)
		result += source[i];
	return result;
}

int main()
{
	std::ifstream reader("dane.txt");

	string word;
	int even = 0, palindromes = 0;
	std::vector<string> words;
	while (!reader.eof()) {
		reader >> word;
		if (reader.eof())
			break;
		words.push_back(word);
		even += word[word.size() - 1] & 1; 
		palindromes += word == reverse(word);
	}

	std::sort(words.begin(), words.end());
	int duplicates = 0, appearCounter = 1, appearCounterMax = 0, indexMax = 0;

	for (int i = 1; i < words.size() - 1; ++i) {
		duplicates += words[i - 1] == words[i] && words[i] != words[i + 1];
		appearCounter = words[i - 1] == words[i] ? appearCounter + 1 : 1;
		indexMax = appearCounter > appearCounterMax && words[i] != words[i + 1] ? i : indexMax;
		appearCounterMax = appearCounter > appearCounterMax  && words[i] != words[i + 1] ? appearCounter : appearCounterMax;
	}

	std::ofstream writer("wynik.txt");
	printf("1: duplikaty: %i, max slowo: %s, o liczbie wystapien: %i\n2: %i\n3: %i", duplicates, words[indexMax].c_str(), appearCounterMax, even, palindromes);
	writer << "1: duplikaty: " << duplicates << ", slowo, ktore pojawilo sie najwieksza liczbe razy (" << appearCounterMax << "): " << words[indexMax] << "\n2: liczba liczb parzystych: " << even << "\n3: liczba palindromow: " << palindromes;

	return 0;
}