#include <iostream>
#include <string>

std::string reverse(std::string word, int index) {
	if (index == 0) // przypadek podstawowy
		return std::string(1, word[0]);
	return word[index] + reverse(word, index - 1); // przypadek rekurencyjny
}
int main () {
	std::string word;
	std::cin >> word;
	std::cout << reverse(word, word.size() - 1);
	return 0;
}
