#include <iostream>
#include <fstream>
#include <cstdlib>

unsigned long long convert(std::string number, int base, int index) {
	if (index == 0)
		return number[0] - (number[0] < 97 ? 48 : 87);
	return convert(number, base, index - 1) * base + (number[index] - (number[index] < 97 ? 48 : 87));
}

int main() {
	std::ifstream reader("zadanie01.txt");
	
	std::string n1, n2;
	int counter = 0;

	while (reader >> n1 >> n2) { 
		int base1 = std::atoi(n1.substr(11, n1.size() - 11).c_str()), base2 = std::atoi(n2.substr(11, n1.size() - 11).c_str());
		counter += convert(n1, base1, 9) > convert(n2, base2, 9);
	}

	std::cout << counter;

	reader.close();

	return 0;
}