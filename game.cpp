#include "game.h"
#include "settings.h"
enum {INTRO};
Game::Game() {
	window.create(
		sf::VideoMode(
			static_cast<size_t>(WINDOW_WIDTH),
			static_cast<size_t>(WINDOW_HEIGHT)
		),
		"OVER.SW Race",
		sf::Style::Titlebar | sf::Style::Close
	);
	road1.init(0.f, 0.f);
	road2.init(0.f, -WINDOW_HEIGHT);
}
void Game::play() {
	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed)
			
				window.close();
		}
		road1.update();
		road2.update();
		//window.clear();
		window.draw(road1.getSprite());
		window.draw(road2.getSprite());
		window.display();
	}
}