#pragma once
#include "Hanoi.h"

class Handler
{
	Hanoi hanoi;
	sf::Font font;

	bool render, paused; // events in the loop

	// bars //
	int values[2];
	sf::Text barsTextes[2], valuesTextes[2];
	sf::RectangleShape bars[2]; // in order: speed bar, disks count bar
	sf::CircleShape points[2]; // point the value shown on the bar
	bool moving[2];

	// buttons //
	sf::Text textes[3]; // in order: solve text, start/resume text, trails text (trails done / total trials)

	void initialize();
public:
	Handler();
	void Loop(sf::RenderWindow& window);
};

