#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using std::string;

struct Pair { string word1, word2; };

bool anagram(string w1, string w2) {
	std::sort(w1.begin(), w1.end());
	std::sort(w2.begin(), w2.end());
	return w1 == w2;
}

int main()
{
	std::fstream reader("slowa.txt", std::ios::in), writer("wyniki6.txt", std::ios::out);

	string word1, word2;
	std::vector<Pair> pairs;
	int lettersA = 0, containers = 0;

	for (int i = 0; i < 1000; ++i) {
		reader >> word1 >> word2;
		
		lettersA += (word1[word1.size() - 1] == 'A') + (word2[word2.size() - 1] == 'A');

		if (word2.find(word1) != string::npos)
			++containers;

		if (anagram(word1, word2))
			pairs.push_back(Pair() = { word1, word2 });
	}

	printf("1:\n%i\n2:\n%i\n3:\nliczba par: %i\n", lettersA, containers, pairs.size());
	writer << "1:\n" << lettersA << "\n2:\n" << containers << "\n3:\nliczba par: " << pairs.size() << "\npary:\n";

	for (auto pair : pairs) {
		printf("%s & %s\n", pair.word1.c_str(), pair.word2.c_str());
		writer << pair.word1 << " & " << pair.word2 << '\n';
	}

	reader.close();
	writer.close();

	return 0;
}