#include <iostream>
#include <string>
#include <fstream>
#include <bitset>

int main()
{
	std::fstream reader("binarne.txt", std::ios::in), writer("zadanie4.txt", std::ios::out);

	std::string line, twoCycleMax = "01", incorrectString = "", maxBin = "0001";
	int twoCycleCount = 0, incorrectStringCount = 0;

	for (int i = 0; i < 500; ++i) {
		std::getline(reader, line);

		maxBin = std::bitset<32>(line).to_ulong() > std::bitset<32>(maxBin).to_ulong() && std::bitset<32>(line).to_ulong() <= 65535 ? line : maxBin;

		if (line.substr(0, line.size() / 2) == line.substr(line.size() / 2, line.size() / 2)) {
			++twoCycleCount;
			twoCycleMax = line.size() > twoCycleMax.size() ? line : twoCycleMax;
		}

		for (int j = 0; j < line.size(); j += 4)
			if (std::bitset<32>(line.substr(j, 4)).to_ulong() > 9) {
				++incorrectStringCount;
				incorrectString = line.size() < incorrectString.size() || incorrectString == "" ? line : incorrectString;
				break;
			}
	}

	printf("1:\nliczba liczb dwu-cyklicznych: %i\nmax liczba: %s o dlugosci: %i\n", twoCycleCount, twoCycleMax.c_str(), twoCycleMax.size());
	printf("2:\nliczba liczb niepoprawnych: %i\nmin dlugosc niepoprawnej liczby: %i\n", incorrectStringCount, incorrectString.size());
	printf("3:\nmax liczba w bin: %s\nw dec: %i\n", maxBin.c_str(), std::bitset<32>(maxBin).to_ulong());
	writer << "1:\nliczba liczb dwu-cyklicznych: " << twoCycleCount << "\nmax liczba: " << twoCycleMax << " o dlugosci: " << twoCycleMax.size() << "\n2:\nnliczba liczb niepoprawnych: " << incorrectStringCount
		<< "\nmin dlugosc niepoprawnej liczby: " << incorrectString.size() << "\n3:\nmax liczba w bin: " << maxBin << "\nw dec: " << std::bitset<32>(maxBin).to_ulong();

	reader.close();
	writer.close();

	return 0;
}