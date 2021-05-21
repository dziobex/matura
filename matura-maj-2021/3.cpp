#include <iostream>
#include <fstream>

int main()
{
	std::ifstream reader("instrukcje.txt");
	std::ofstream writer("wyniki4.txt", std::ios::app);
	std::string instruction = "";
	char value = 0;
	int alphabet[26]{}, max = 0;

	while (reader >> instruction >> value) {
		instruction == "DOPISZ" ? ++alphabet[value - 65] : 666; // ignore my stupidity
		max = alphabet[value - 65] > alphabet[max] ? value - 65 : max;
	}

	writer << "3.\n" << (char)(max + 65) << ' ' << alphabet[max] << "\n\n";

	return 0;
}