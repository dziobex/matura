#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int factorial(int num);
bool equals(int num);
int GCD(int n1, int n2);

int main()
{
	std::ifstream reader("liczby.txt");
	int nums[500], pows = 0, gcd = 1, div = 1, streak = 0, start = 0, streakMax = 0, startMax = 0;
	std::vector<int> factorialNumbers;

	for (int i = 0; i < 500; ++i) {
		reader >> nums[i];
		if (equals(nums[i]))
			factorialNumbers.push_back(nums[i]);
		pows += std::to_string(log(nums[i]) / log(3)) == std::to_string(round(log(nums[i]) / log(3)));

		if (i > 0 && GCD(nums[i - 1], nums[i]) > 1)
			++streak;
		else if (i > 0) {
			if (streak > streakMax) {
				streakMax = streak;
				div = gcd;
				startMax = start;
			}
			start = i + 1;
			streak = 0;
		}
		if (i > 0)
			gcd = GCD(nums[i - 1], nums[i]);
	}

	std::ofstream writer("wyniki4.txt");
	writer << "1: " << pows << "\n\n2:\n";
	for (int fn : factorialNumbers)
		writer << fn << '\n';
	writer << "\n3:\npierwsza liczba ciagu: " << nums[startMax] << "\ndlugosc: " << streakMax << "\nnwd: " << div;

	printf("\033[1m:]\033[0m");

	return 0;
}

int factorial(int num) {
	int fct = 1;
	for (int i = 1; i <= num; ++i)
		fct *= i;
	return fct;
}

bool equals(int num) {
	int sum = 0, n = num;
	while (n > 0) {
		sum += factorial(n % 10);
		n /= 10;
	}
	return sum == num;
}

int GCD(int n1, int n2) {
	while (n1 != n2) {
		n1 = n1 > n2 ? n1 - n2 : n1;
		n2 = n2 > n1 ? n2 - n1 : n2;
	}
	return n1;
}