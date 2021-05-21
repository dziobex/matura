#include <iostream>
#include <fstream>

int main()
{
	std::ifstream reader("instrukcje.txt");
	std::ofstream writer("wyniki4.txt", std::ios::out);
	std::string instruction = "";
	char value = 'x';
	int result = 0;

	while (reader >> instruction >> value)
		instruction == "DOPISZ" ? ++result : instruction == "USUN" ? --result : 666;

	writer << "1.\n" << result << "\n\n";

	return 0;
}