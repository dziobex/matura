#include <iostream>
#include <fstream>

const double PI = atan(1) * 4;

int main()
{
	std::ifstream reader("punkty.txt");
	std::ofstream writer("wyniki_4.txt");
	int x, y;
	double edges = 0, getPi1000 = 0, getPi5000 = 0, getPiAll = 0, approx[2]{};

	writer << "1:\n";
	for (int i = 0; i < 10000; ++i) {
		reader >> x >> y;
		double form = pow(x - 200, 2) + pow(y - 200, 2);

		if (form == 40000)
			writer << '(' << x << ';' << y << ")\n";
		edges += form < pow(200, 2);
		getPi1000 += i < 1000 && (form <= pow(200, 2));
		getPi5000 += i < 5000 && (form <= pow(200, 2));
		getPiAll += form <= pow(200, 2);

		if (i == 999 || i == 1699)
			approx[i == 999 ? 0 : 1] = round(abs(PI - ((double(getPiAll) / (i + 1)) * 4)) * 10000) / 10000;
	}

	writer << "liczba pkt nalezacych do wnetrza kola: " << edges << "\n\n2:\npierwsze 1000 pkt: " << double(getPi1000 * 4) / 1000 << "\npierwsze 5000 pkt: " << double(getPi5000 * 4) / 5000
		<< "\nwszystkie pkt: " << double(getPiAll * 4) / 10000 << "\n\n3:\n1000: " << approx[0] << "\n1700: " << approx[1];

	printf("\033[1m:]\033[0m");

	return 0;
}
