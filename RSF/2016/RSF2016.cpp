#include <iostream>
#include <string>
#include <fstream>

bool** grid;
bool** helper;

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

int main()
{
	std::fstream reader("gra.txt", std::ios::in), writer("wyniki_5.txt", std::ios::out);

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

	int task1, task2;
	std::string task3;
	for (int i = 1; i <= 100; ++i) {
		int aliveCells = 0;
		for (int row = 0; row < 12; ++row)
			for (int col = 0; col < 20; ++col) {
				helper[row][col] = dead(row, col);
				aliveCells += (grid[row][col] ? 1 : 0);
			}

		if (i == 39) // + 2 due to + 2 steps forward by helper
			task1 = livingFriends(1, 18);
		if (i == 2)
			task2 = aliveCells;
		if (areEqual()) {
			task3 = std::to_string(i + 1) + ", komorki: " + std::to_string(aliveCells);
			break;
		}
	}

	delete[] grid;
	delete[] helper;

	printf("1: %i\n2: %i\n3: %s\n", task1, task2, task3.c_str());
	writer << "1: " << task1 << "\n2: " << task2 << "\n3: " << task3;

	reader.close();
	writer.close();

	return 0;
}