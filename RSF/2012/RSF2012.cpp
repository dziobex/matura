#include <iostream>
#include <fstream>

using std::string;

void transform(string filename, string word, string key, bool encrypt) {
	string result;
	for (int i = 0, j = 0; i < word.size(); ++i, j = (j == key.size() - 1 ? 0 : j + 1)) {
		if (encrypt)
			result += word[i] + (key[j] - 64) > 90 ? word[i] + (key[j] - 64) - 26 : word[i] + (key[j] - 64);
		else
			result += word[i] - (key[j] - 64) < 65 ? word[i] - (key[j] - 64) + 26 : word[i] - (key[j] - 64);
	}

	std::ofstream writer(filename, std::ios::app);
	writer << result << '\n';
}

int main()
{
	std::ifstream encryptCodes("tj.txt"), encryptKeys("klucze1.txt");
	std::ifstream dencryptCodes("sz.txt"), dencryptKeys("klucze2.txt");

	string toEncrypt, toDecrypt, encCode, decCode;
	for (int i = 0; i < 120; ++i) {
		encryptCodes >> toEncrypt;
		dencryptCodes >> toDecrypt;
		encryptKeys >> encCode;
		dencryptKeys >> decCode;

		transform("wynik4a.txt", toEncrypt, encCode, 1);
		transform("wynik4b.txt", toDecrypt, decCode, 0);
	}

	string str = "DONE.";
	for (int i = 31, j = 0; i <= 37; i += (i == 33 ? 2 : 1), ++j)
		printf("\033[%im%c\033[0m", i, str[j]);

	return 0;
}
