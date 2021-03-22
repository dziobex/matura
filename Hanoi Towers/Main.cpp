#include "Handler.h"

int main() {
	// program entry //
	sf::RenderWindow window(sf::VideoMode(600, 500), "Hanoi Towers", sf::Style::Titlebar | sf::Style::Close);
	sf::Image icon;
	icon.loadFromFile("resources/icon.png");
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	Handler handler;
	handler.Loop(window);

	return 0;
}