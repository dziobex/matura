#include <iostream>
#include <fstream>

struct Pixel { int currentStreak = 1; int maxStreak = 0; };

int grid[200][320];

int main()
{
	int max = 0, min = 256, contrasting = 0, minRows = 0, maxColumnStreak = 0;
	std::ifstream reader("dane.txt");

	for (int i = 0; i < 200; ++i)
		for (int j = 0; j < 320; ++j) {
			reader >> grid[i][j];
			max = grid[i][j] > max ? grid[i][j] : max;
			min = grid[i][j] < min ? grid[i][j] : min;
		}

	for (int i = 0; i < 200; ++i) {
		bool deleted = false;
		for (int j = 0; j < 320; ++j) {
			contrasting += (j < 319 && abs(grid[i][j] - grid[i][j + 1]) > 128) || (j > 0 && abs(grid[i][j] - grid[i][j - 1]) > 128) // left, right
				|| (i < 199 && abs(grid[i][j] - grid[i + 1][j]) > 128) || (i > 0 && abs(grid[i][j] - grid[i - 1][j]) > 128); // up, down
			deleted = !deleted ? grid[i][j] != grid[i][319 - j] : deleted;
		}
		minRows += deleted;
	}

	Pixel pixels[320];
	for (int i = 0; i < 320; ++i) {
		for (int j = 1; j < 200; ++j) {
			pixels[i].currentStreak = grid[j - 1][i] == grid[j][i] ? pixels[i].currentStreak + 1 : 1;
			pixels[i].maxStreak = pixels[i].currentStreak > pixels[i].maxStreak ? pixels[i].currentStreak : pixels[i].maxStreak;
		}
		maxColumnStreak = pixels[i].maxStreak > maxColumnStreak ? pixels[i].maxStreak : maxColumnStreak;
	}

	std::ofstream writer("wyniki6.txt");
	printf("1: max: %i, min: %i\n2: %i\n3: %i\n4: %i", max, min, minRows, contrasting, maxColumnStreak);
	writer << "1: max: " << max << ", min: " << min << "\n2: " << minRows << "\n3: " << contrasting << "\n4: " << maxColumnStreak;

	return 0;
}