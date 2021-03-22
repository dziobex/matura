#include "Handler.h"

void Handler::initialize() {
	font.loadFromFile("resources/PrintBold-J5o.ttf");
	textes[0] = sf::Text("Solve", font, 40);
	textes[0].setPosition(200, 420);
	textes[1] = sf::Text("Pause", font, 40);
	textes[1].setPosition(330, 420);
	textes[2] = sf::Text("Trial: 21 / 37", font, 25);
	textes[2].setPosition(450, 10);

	for (int i = 0; i < 2; ++i) moving[i] = false;
	for (int i = 0; i < 3; ++i) textes[i].setFillColor(sf::Color::Black);

	// bars initialization //
	for (int i = 0; i < 2; ++i) {
		// bars //
		bars[i] = sf::RectangleShape(sf::Vector2f(100, 5));
		bars[i].setPosition(100, 20 + 40 * i);
		bars[i].setFillColor(sf::Color::Black);

		// "pointers" that point the values on the bar //
		points[i] = sf::CircleShape(5);
		points[i].setOrigin(0, 2.5);
		points[i].setPosition(100, 20 + 40 * i);
		points[i].setFillColor(sf::Color::Black);

		// textes that represent the bars names //
		barsTextes[i] = sf::Text(i == 0 ? "Disks:" : "Speed:", font, 30);
		barsTextes[i].setPosition(15, 0 + 40 * i);
		barsTextes[i].setFillColor(sf::Color::Black);

		// textes that represent values pointed on the bars //
		valuesTextes[i] = sf::Text("5", font, 30);
		valuesTextes[i].setPosition(215, 0 + 40 * i);
		valuesTextes[i].setFillColor(sf::Color::Black);
	}

	values[0] = 1;
}

Handler::Handler() {
	hanoi = Hanoi(1);
	initialize();
	render = paused = false;
}

// main "simulation" loop //
void Handler::Loop(sf::RenderWindow& window) {
	sf::Clock clock;
	float deltaTime;

	bool leftBtnPressed = false;
	while (window.isOpen()) {
		deltaTime = clock.restart().asSeconds(); // customsize speed to the user's device
		sf::Event e;
		bool leftMouseBtnReleased = false;
		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed) window.close();
			if (e.type == sf::Event::MouseButtonPressed) { if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) leftBtnPressed = true; }
			if (e.type == sf::Event::MouseButtonReleased) { if (leftBtnPressed) leftMouseBtnReleased = true; }
		}

		window.clear(sf::Color::White);

		// draw pogs //
		sf::RectangleShape footer(sf::Vector2f(500, 30));
		footer.setPosition(50, 350);
		footer.setFillColor(sf::Color::Black);
		window.draw(footer);

		// pogs //
		sf::RectangleShape pog(sf::Vector2f(15, 200));

		for (int i = 0; i < 3; ++i) {
			pog.setPosition(140 + 150 * i, 150);
			pog.setFillColor(sf::Color::Black);
			window.draw(pog);
		}

		hanoi.Render(window, deltaTime, values[1] * 10, render && !paused);

		// render numbers under pogs //
		sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
		textes[2].setString("Trial: " + hanoi.GetTrialsCount());
		for (int i = 0; i < 3; ++i) {
			if (i < 2 && textes[i].getGlobalBounds().contains(mousePos)) {
				textes[i].setStyle(sf::Text::Style::Underlined);
				if (leftMouseBtnReleased)
					if (i == 0) { hanoi = Hanoi(values[0]); render = true; }
					else if (i == 1) { paused = !paused; textes[i].setString(paused ? "Resume" : "Pause"); }
			}
			else if (i < 3)
				textes[i].setStyle(sf::Text::Style::Regular);
			window.draw(textes[i]);
		}

		// render numbers under pogs //
		for (int i = 0; i < 3; ++i) {
			sf::Text number(std::string(1, (char)65 + i), font, 35);
			number.setPosition(135 + 150 * i, 375);
			number.setFillColor(sf::Color::Black);
			window.draw(number);
		}

		// set bars values based on pointers locations & render bars //
		for (int i = 0; i < 2; ++i) {
			if (bars[i].getGlobalBounds().contains(mousePos) && sf::Mouse::isButtonPressed(sf::Mouse::Left) && !moving[i == 0 ? 1 : 0])
				moving[i] = true;
			else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
				moving[i] = false;
			if (moving[i] && mousePos.x >= bars[i].getPosition().x && mousePos.x <= bars[i].getPosition().x + bars[i].getSize().x)
				points[i].setPosition(mousePos.x, points[i].getPosition().y);
			int newValue = i == 1 ? (points[i].getPosition().x - bars[i].getPosition().x) : ceil((points[i].getPosition().x - bars[i].getPosition().x) / 10);
			if (newValue == 0) newValue = 1;
			if (i == 0 && values[i] != newValue) {
				render = paused = false;
				hanoi = Hanoi(ceil((points[i].getPosition().x - bars[i].getPosition().x) / 10));
			}
			values[i] = newValue;
			valuesTextes[i].setString(std::to_string(values[i]));
			window.draw(barsTextes[i]);
			window.draw(bars[i]);
			window.draw(points[i]);
			window.draw(valuesTextes[i]);
		}
		window.display();
	}
}