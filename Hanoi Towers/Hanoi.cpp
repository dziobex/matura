#include "Hanoi.h"

void Hanoi::solve(int n, char from, char help, char to) {
	if (n == 0) return;
	solve(n - 1, from, to, help); // move smallest disk to helper pog
	track.push_back(std::string(1, from) + std::string(1, to)); // move larger disk to the traget pog
	solve(n - 1, help, from, to); // move smallest disk to the larger one
}

Hanoi::Hanoi(int n) {
	this->n = n;
	doneTrials = 0;
	totalTrials = pow(2, n) - 1;
	solve(n, 'A', 'B', 'C'); // chars (or chars like 'A', 'B', 'C') are not necessary here, but determine which pog is in a visible way

	for (int i = 0; i < 10; ++i) {
		disks[i].currentPog = 0;
		disks[i].shape = sf::RectangleShape(sf::Vector2f(160 - 15 * i, 20));
		disks[i].shape.setFillColor(sf::Color::Black);
		disks[i].shape.setPosition(67.5 + 7.5 * i, 350 - 22 * (i+1));
	}

	// pogs initialization (all pogs are in the first pog) //
	for (int i = 0; i < 3; ++i) {
		pogs[i] = i == 0 ? n - 1: 0;
		for (int j = 0; j < n; ++j) {
			pogsAdresses[i][j] = i == 0 ? j : 0;
		}
	}
}

void Hanoi::Render(sf::RenderWindow& window, float deltaTime, int speed, bool move) {
	// disks //
	if (doneTrials < track.size() && disks[pogsAdresses[track[doneTrials][0] - 65][pogs[track[doneTrials][0] - 65]]].target == -1) { // change moving disk
		disks[pogsAdresses[track[doneTrials][0] - 65][pogs[track[doneTrials][0] - 65]]].target = track[doneTrials][1] - 65;
		disks[pogsAdresses[track[doneTrials][0] - 65][pogs[track[doneTrials][0] - 65]]].animationStage = 0;
		printf("\033[36;5m%c -> %c\033[0m\n", track[doneTrials][0], track[doneTrials][1]);
	}

	for (int i = 0; i < n; ++i) { // moving & rendering disks
		if (move && disks[i].Move(deltaTime, speed, pogs, pogsAdresses)) {
			++doneTrials;
			pogsAdresses[disks[i].currentPog][pogs[disks[i].currentPog]] = i;
		}
		disks[i].Render(window);
	}
}

// disk animation - up -> right/left -> down -> disabling movements //
bool Hanoi::Disk::Move(float deltaTime, int speed, int pogs[3], int pogsAdresses[3][11]) {
	if (target == -1) return false;
	switch (animationStage) {
	case 0:
		shape.setPosition(shape.getPosition() + sf::Vector2f(0, -speed * deltaTime));
		if (shape.getPosition().y <= 120)
			animationStage = currentPog < target ? 1 : 2;
		break;
	case 1:
		shape.setPosition(shape.getPosition() + sf::Vector2f(speed * deltaTime, 0));
		if (shape.getPosition().x + shape.getSize().x / 2 - 7 >= 140 + target * 150) {
			animationStage = 3;
			shape.setPosition(140 + target * 150 - (shape.getSize().x - 15) / 2, shape.getPosition().y);
		}
		break;
	case 2:
		shape.setPosition(shape.getPosition() + sf::Vector2f(-speed * deltaTime, 0));
		if (shape.getPosition().x + shape.getSize().x / 2 - 8 < 140 + target * 150) {
			animationStage = 3;
			shape.setPosition(140 + target * 150 - (shape.getSize().x - 15) / 2, shape.getPosition().y);
		}
		break;
	case 3:
		shape.setPosition(shape.getPosition() + sf::Vector2f(0, speed * deltaTime));
		if (shape.getPosition().y >= 350 - (1 + pogs[target]) * 22) {
			animationStage = -1;
			shape.setPosition(shape.getPosition().x, 350 - (1 + pogs[target] + (target == 0)) * 22);
			pogsAdresses[currentPog][pogs[currentPog]] = 0;
			pogs[currentPog]--;
			pogs[target]++;
			this->currentPog = target;
			target = -1;
			return true;
		}
		break;
	default:
		break;
	}
	return false;
}

void Hanoi::Disk::Render(sf::RenderWindow& window) {
	window.draw(shape);
}