#include <iostream>
#include <fstream>

using std::string;

string reverse(string source) {
	string str;
	for (int i = source.size() - 1; i >= 0; --i)
		str += source[i];
	return str;
}

int* connect(string w1, string w2) {
	int left = w2.size() + 1, right = w2.size() + 1;

	while (w2.substr(0, --left) != w1.substr(w1.size() - left, left) && left > 0);
	while (w2.substr(w2.size() - (--right), right) != w1.substr(0, right) && right > 0);

	return new int[2] { left > right ? left : right, left > right ? 0 : 1 };
}

int main()
{
	std::ifstream reader("dane.txt");
	std::ofstream writer_words("slowa.txt"), writer_tasks("zad_5.txt");

	string w1, w2;
	int palindromes = 0, containers = 0, stickyWords = 0;
	for (int i = 0; i < 200; ++i) {
		reader >> w1 >> w2;
		palindromes += w1 == reverse(w1);
		palindromes += w2 == reverse(w2);

		if (w1.find(w2) != string::npos) {
			++containers;
			writer_words << w1 << '\n';
		}
		else {
			int* checkIf = connect(w1, w2);
			if (checkIf[0] == 0) {
				++stickyWords;
				writer_words << w1 << w2 << '\n';
				continue;
			}
			writer_words << (checkIf[1] == 0 ? w1.substr(0, w1.size() - checkIf[0]) + w2 : (w2.substr(0, checkIf[0]) + w1)) << '\n';
		}
	}

	printf("1. %i\n2. %i\n3. %i", palindromes, containers, stickyWords);
	writer_tasks << "1. " << palindromes << "\n2. " << containers << "\n3. " << stickyWords;

	return 0;
}