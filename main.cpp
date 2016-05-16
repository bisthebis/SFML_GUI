#include <iostream>
#include <SFML/Graphics.hpp>


#include "button.h"

int main()
{
	sf::ContextSettings settings;
	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.antialiasingLevel = 4;
	settings.majorVersion = 4;
	settings.minorVersion = 5;


	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!", sf::Style::Default, settings);
    sf::Clock clock;
    Button bouton;
    bouton.setCallback([](){std::cout << "Click" << std::endl;});

	while (window.isOpen())
	{
		sf::Event event;
        while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed)
			window.close();

            else if (event.type == sf::Event::MouseButtonPressed)
                bouton.check(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));

            else if (event.type == sf::Event::Resized)
                window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
		}
    bouton.move(sf::Vector2f(clock.restart().asSeconds()*5, 0));

	window.clear();
    window.draw(bouton);
	window.display();
	}

	return 0;
}
