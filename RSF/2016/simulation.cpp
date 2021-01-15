#include <iostream>
#include <string>
#include <fstream>
#include <thread>
#include <chrono>

bool** grid;
bool** helper;

int livingFriends(int row, int col);
bool dead(int row, int col);
bool areEqual();

int main()
{
	std::ifstream reader("gra.txt");

	grid = new bool* [12];
	helper = new bool* [12];
	std::string line;
	for (int i = 0; i < 12; ++i) {
		std::getline(reader, line);
		grid[i] = new bool[20];
		helper[i] = new bool[20];
		for (int j = 0; j < 20; ++j)
			grid[i][j] = line[j] == 'X';
	}

	int color = 0;
	for (int i = 1; i <= 100; ++i) {
		printf("\033[%im\033[4mPOKOLENIE: %i%s\033[0m\n\033[0m", color, i, color != 0 ? " KONIEC EWOLUCJI" : "");
		for (int row = 0; row < 12; ++row)
			for (int col = 0; col < 20; ++col) {
				helper[row][col] = dead(row, col);
				printf("\033[%im%c%s\033[0m", grid[row][col] ? color : 0, grid[row][col] ? 'X' : '.', col == 19 ? "\n" : "");
			}

		if (color != 0)
			break;
		color = areEqual() ? 31 : 0;
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		system("CLS");
	}

	delete[] grid;
	delete[] helper;

	printf("\n");
	system("pause");

	return 0;
}

int livingFriends(int row, int col) {
	int aliveCells = 0;

	for (int i = -1; i <= 1; i += 2) {
		aliveCells += (grid[row + i < 0 ? 11 : (row + i >= 12 ? 0 : row + i)][col] ? 1 : 0);
		aliveCells += (grid[row][col + i < 0 ? 11 : (col + i >= 12 ? 0 : col + i)] ? 1 : 0);
		aliveCells += (grid[row + i < 0 ? 11 : (row + i >= 12 ? 0 : row + i)][col + i < 0 ? 11 : (col + i >= 12 ? 0 : col + i)] ? 1 : 0);
		aliveCells += (grid[row - i < 0 ? 11 : (row - i >= 12 ? 0 : row - i)][col + i < 0 ? 11 : (col + i >= 12 ? 0 : col + i)] ? 1 : 0);
	}

	return aliveCells;
}

bool dead(int row, int col) {
	int aliveCells = livingFriends(row, col);
	return (grid[row][col] && aliveCells == 2) || (grid[row][col] && aliveCells == 3) || (!grid[row][col] && aliveCells == 3);
}

bool areEqual() {
	bool result = true;
	for (int i = 0; i < 12; ++i)
		for (int j = 0; j < 20; ++j)
			if (grid[i][j] != helper[i][j]) {
				result = false;
				grid[i][j] = helper[i][j];
			}
	return result;
}