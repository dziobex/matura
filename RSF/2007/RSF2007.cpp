#include <iostream>
#include <string>
#include <fstream>
#include <bitset>

using std::string;

bool prime(unsigned long num) {
	if (num < 2) return false;
	for (int i = 2; i <= sqrt(num); ++i)
		if (num % i == 0)
			return false;
	return true;
}

int sumDigits(string num) {
	int sum = 0;
	for (char c : num)
		sum += (c - 48);
	return sum;
}

int main()
{
	int ranges[3]{}, sumA = 0, sumB = 0;
	for (int i = 2; i <= 1000; ++i)
		ranges[0] += prime(i) && prime(sumDigits(std::to_string(i))) && prime(sumDigits(std::bitset<16>(i).to_string()));

	for (int i = 100; i <= 10000; ++i) {
		sumA += prime(sumDigits(std::to_string(i)));
		if (prime(i) && prime(sumDigits(std::to_string(i))) && prime(sumDigits(std::bitset<16>(i).to_string()))) {
			++ranges[1];
			sumB += sumDigits(std::to_string(i));
		}
	}

	for (int i = 1000; i <= 100000; ++i)
		ranges[2] += prime(i) && prime(sumDigits(std::to_string(i))) && prime(sumDigits(std::bitset<32>(i).to_string()));

	printf("A:\n1: %i\n2: %i\n3: %i\n\nB:\n1: %i\n2: %s", ranges[0], ranges[1], ranges[2], sumA, prime(sumB) ? "TAK" : "NIE");
	for (int i = 1; i <= 3; ++i) {
		std::ofstream writer(std::to_string(i) + ".txt");
		writer << ranges[i - 1];
	}

	return 0;
}