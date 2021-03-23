#include <iostream>

bool isPalindrome (std::string str, int start, int end) {
	if (end - start <= 1)
		return true;
	if (str[start] != str[end])
		return false;
	return isPalindrome(str, start + 1, end - 1);
}

int main () {
	std::string str;
	std::cin >> str;
	std::cout << "Is " << str << " a palindrome? " << isPalindrome(str, 0, str.size() - 1);
	
	return 0;
}
