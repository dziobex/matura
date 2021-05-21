#include <iostream>
#include <fstream>

int main()
{
	std::ifstream reader("instrukcje.txt");
	std::ofstream writer("wyniki4.txt", std::ios::app);
	std::string instruction = "", result = "";
	char value = 'x';

	while (reader >> instruction >> value) {
		if (instruction == "DOPISZ")
			result += value;
		else if (instruction == "ZMIEN")
			result[result.size() - 1] = value;
		else if (instruction == "USUN")
			result = result.substr(0, result.size() - 1);
		else {
			for (int i = 0; i < result.size(); ++i) {
				if (result[i] == value) {
					result[i] = result[i] == 90 ? 'A' : result[i] + 1;
					break;
				}
			}
		}
	}

	writer << "4.\n" << result << "\n\n";

	return 0;
}