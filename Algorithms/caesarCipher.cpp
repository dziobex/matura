#include <iostream>
#include <string>

void caesarCipher (std::string& str, int key) {
	for (int i = 0; i < str.size(); ++i)
		if (str[i] != ' ')
			str[i] = 97 + (str[i] - 97 + key) % 26;
}

int main () {
	int key;
	std::string str;
	
	std::cin >> key;
	std::getline(std::cin, str);
	
	caesarCipher(str, key);
	std::cout << str;
	
	return 0;
}
