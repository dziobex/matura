#include <iostream>
#include <fstream>
#include <cstdlib>

bool invalid(std::string number, int base) {
	for (int i = 0; i < 10; ++i)
		if (number[i] - (number[i] < 97 ? 48 : 87) >= base)
			return true;
	return false;
}

int main() {
	std::ifstream reader("zadanie02.txt");

	std::string n1, n2;
	int counter = 0;

	while (reader >> n1 >> n2) {
		int base1 = std::atoi(n1.substr(11, n1.size() - 11).c_str()), base2 = std::atoi(n2.substr(11, n1.size() - 11).c_str());
		counter += invalid(n1, base1) || invalid(n2, base2);
	}

	std::cout << counter;
	reader.close();

	return 0;
}