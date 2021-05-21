#include <fstream>

int main()
{
	std::ifstream reader("instrukcje.txt");
	std::ofstream writer("wyniki4.txt", std::ios::app);
	std::string instruction = "", maxString = "", previous = "";
	char value = 0;
	int streak = 1, maxStreak = 0;

	while (reader >> instruction >> value) {
		if (instruction != previous) {
			if (maxStreak < streak) {
				maxStreak = streak;
				maxString = previous;
			}
			streak = 1;
		}
		else
			++streak;
		previous = instruction;
	}

	writer << "2.\n" << maxString << ' ' << maxStreak << "\n\n";

	return 0;
}