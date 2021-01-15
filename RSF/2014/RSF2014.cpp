#include <iostream>
#include <fstream>
#include <algorithm>

using std::string;

bool isPrimary(int num) {
	if (num < 2) return false;
	for (int i = 2; i <= sqrt(num); ++i) if (num % i == 0) return false;
	return true;
}

void specification(string inscription, bool& primary, bool& increasing) {
	int sum = inscription[0];
	for (int i = 1; i < inscription.size(); ++i) {
		sum += inscription[i];
		increasing = increasing && inscription[i - 1] >= inscription[i] ? !increasing : increasing;
	}
	primary = isPrimary(sum);
}

int main()
{
	std::ifstream reader("NAPIS.txt");
	string* inscriptions = new string[1000];
	string increasingInscriptions = "";

	int primaryInscriptions = 0;

	for (int i = 0; i < 1000; ++i) {
		reader >> inscriptions[i];
		bool primary = 1, increasing = 1;
		specification(inscriptions[i], primary, increasing);
		primaryInscriptions += primary;
		increasingInscriptions = increasing ? increasingInscriptions + inscriptions[i] + " ": increasingInscriptions;
	}

	std::ofstream writer("ZADANIE5.txt");
	printf("1:\n%i\n2:\n%s\n3:\n", primaryInscriptions, increasingInscriptions.c_str());
	writer << "1:\nliczba napisow pierwszych: " << primaryInscriptions << "\n2:\nnapisy rosnace: " << increasingInscriptions << "\n3:\nnapisy powtarzajace sie:\n";

	std::sort(inscriptions, inscriptions + 1000);
	for (int i = 1; i < 999; ++i)
		if (inscriptions[i - 1] == inscriptions[i] && inscriptions[i] != inscriptions[i + 1]) {
			printf("%s\n", inscriptions[i].c_str());
			writer << inscriptions[i] << '\n';
		}

	return 0;
}
