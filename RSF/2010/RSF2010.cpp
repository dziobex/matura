#include <iostream>
#include <fstream>
#include <algorithm>

using std::string;

void writeAll(string filename, string words[]) {
	std::fstream writer(filename, std::ios::app);
	for (int i = 0; i < 5; ++i)
		writer << words[i] << (i == 4 ? '\n' : ' ');
	writer.close();
}

int main()
{
	std::ifstream reader("anagram.txt");

	string words[5];
	for (int i = 0; i < 200; ++i) {
		for (int j = 0; j < 5; ++j)
			reader >> words[j];
		if (std::all_of(words, words + 5, [words](string w) { return w.size() == words[0].size(); })) {
			writeAll("odp_a.txt", words);

			string helper[5];
			std::copy(words, words + 5, helper);
			for (int j = 0; j < 5; ++j)
				std::sort(helper[j].begin(), helper[j].end());

			if (std::all_of(helper, helper + 5, [helper](string w) { return w == helper[0]; }))
				writeAll("odp_b.txt", words);
		}
	}

	string str = "DONE.";
	for (int i = 31, j = 0; i <= 37; i += (i == 33 ? 2 : 1), ++j)
		printf("\033[%im%c\033[0m", i, str[j]);

	return 0;
}