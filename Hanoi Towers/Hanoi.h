#pragma once
#include <SFML/Graphics.hpp>

class Hanoi
{
	int n, totalTrials, doneTrials;
	std::vector <std::string> track;
	int pogs[3]; // how many disks are currently on the pog
	int pogsAdresses[3][11]; // adresses to the disk that are curently on the pog

	struct Disk {
		sf::RectangleShape shape;
		int currentPog, target = -1; // 0-2 <- pogs; -1 means that the disk does nothing
		int animationStage =-1; // -1: disk does nothing; 0: moving up; 1: moving right; 2: moving left; 3: moving down
		bool Move(float deltaTime, int speed, int pogs[3], int pogsAdresses[3][11]); // move disk to the target pog (if target exists - target != -1)
		void Render(sf::RenderWindow& window); // draw disk
	};

	Disk disks[10];
	void solve(int n, char from, char help, char to);
public:
	int speed;

	Hanoi() = default;
	Hanoi(int n);
	void Render(sf::RenderWindow& window, float deltaTime, int speed, bool move);

	std::string GetTrialsCount() { return std::to_string(doneTrials) + " / " + std::to_string(totalTrials); }
};

