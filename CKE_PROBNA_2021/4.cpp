#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main()
{
	std::fstream reader("galerie.txt", std::ios::in);
	std::fstream writer_1("wynik4_1.txt", std::ios::out), writer_2("wynik4_2a.txt", std::ios::out), writer_3("wynik4_3.txt", std::ios::out);

	std::string country, city;
	int width, height;
	std::vector <std::string> countries;
	std::vector<int> placesAreas;
	std::pair<std::string, int> maxArea = std::make_pair("a", 0), minArea = std::make_pair("b", INT_MAX);
	std::pair<std::string, int> max = std::make_pair("a", 0), min = std::make_pair("b", 200);

	writer_2 << "a):\n";
	for (int linesCounter = 0; linesCounter < 50; ++linesCounter) {
		reader >> country >> city;
		countries.push_back(country);
		int totalArea = 0, places = 0, counter = 69;
		for (int i = 0; i < 70; ++i) {
			reader >> height >> width;
			totalArea += height * width;
			places += height != 0;
			// mozna tez posortowac zbior, a nastepnie sprawdzic czy zawiera duplikaty (tak jak zrobil*m w linii 51) //
			// sprawdz czy zbior zawiera 'nowa' powierzchnie, jesli nie - lokal sie powtarza, czyli zmniejsz liczbe unikatowych lokali //
			if (std::find(placesAreas.begin(), placesAreas.end(), height * width) == placesAreas.end())
				placesAreas.push_back(height * width);
			else
				counter--;
		}
		if (totalArea > maxArea.second)
			maxArea = std::make_pair(city, totalArea);
		if (totalArea < minArea.second)
			minArea = std::make_pair(city, totalArea);

		// ustaw nowa wartosc MAXA i MIN jesli counter jest wiekszy lub mniejszy od poprzedniego rekordu //
		if (counter > max.second)
			max = std::make_pair(city, counter);
		if (counter < min.second)
			min = std::make_pair(city, counter);

		// zadanie 2, a //
		writer_2 << city << ' ' << totalArea << ' ' << places << '\n';
		placesAreas.clear();
	}

	// zadanie 1, sprawdzenie ile jest powtorzen panstw //
	std::sort(countries.begin(), countries.end());
	int streak = 1;
	for (int i = 1; i < countries.size(); ++i) {
		if (countries[i - 1] == countries[i])
			streak++;
		else if (countries[i - 1] != countries[i]) {
			writer_1 << countries[i - 1] << ": " << streak << '\n';
			streak = 1;
		}
		if (i == countries.size() - 1)
			writer_1 << countries[i] << ": " << streak << '\n';
	}

	// zadanie 2, b //
	writer_2 << "b):\n" << maxArea.first << ' ' << maxArea.second << '\n' << minArea.first << ' ' << minArea.second << '\n';

	// zadanie 3 //
	writer_3 << max.first << ' ' << max.second << "\n" << min.first << ' ' << min.second << '\n';

	// zamkniecie strumieni //
	reader.close();
	writer_1.close();
	writer_2.close();
	writer_3.close();

	return 0;
}