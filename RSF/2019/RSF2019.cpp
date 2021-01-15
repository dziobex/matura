#include <iostream>
#include <string>
#include <fstream>

using std::string;
string plots[50];

string reverse(string source) {
	string result;
	for (int i = source.size()-1; i >= 0; --i)
		result += source[i];
	return result;
}

int getSquare(int index) {
	for (int i = 0; i < 30; ++i)
		for (int j = 0; j <= i; ++j)
			if (plots[index][i * 30 + j] == 'X' || plots[index][j * 30 + i] == 'X'|| plots[index][j * 30 + j] == 'X')
				return i;
	return 30;
}

int main()
{
	std::fstream reader("dzialki.txt", std::ios::in), writer("wynik4.txt", std::ios::out);

	int above70PCT = 0, max = 0;
	string plot = "", plotsString = "";

	for (int i = 0; i < 50; ++i) {
		int grassCounter = 0;
		for (int j = 0; j < 30; ++j) {
			reader >> plot;
			for (char c : plot)
				grassCounter += c == '*';
			plots[i] += plot;
		}
		above70PCT += grassCounter * 100 / 900 >= 70;
	}

	printf("1:\n%i\n", above70PCT);
	writer << "1:\nliczba dzialek porosnietych w >=70% trawa: " << above70PCT << '\n';

	bool stop = false;
	for (int i = 0; i < 50 && !stop; ++i)
		for (int j = i + 1; j < 50 && !stop; ++j)
			if (plots[i] == reverse(plots[j])) {
				printf("2:\nDzialki: %i & %i\n", i + 1, j + 1);
				writer << "2:\nDzialki: " << i + 1 << " & " << j + 1 << '\n';
				stop = true;
			}

	for (int i = 0; i < 50; ++i) {
		int square = getSquare(i);
		if (square >= max) {
			plotsString = square > max ? std::to_string(i + 1) : plotsString + ", " + std::to_string(i + 1);
			max = square;
		}
	}

	printf("3:\nmax: %i\ndzialki: %s", max, plotsString.c_str());
	writer << "3:\nmax dlugosc kwadratu: " << max << "\ndzialki, na ktorych mozna wytyczyc taki kwadrat: " << plotsString;

	reader.close();
	writer.close();

	return 0;
}