// Calosc mozna dowolnie edytowac wedle uznania. 

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Menu.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 650), "GFK Lab 01",sf::Style::Titlebar | sf::Style::Close);
	sf::Event event;
	Menu menu;
 
	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		window.clear(sf::Color::Black);

   
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
			
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case(sf::Keyboard::F):
					menu.set_flag(L'f');
					break;
				case(sf::Keyboard::B):
					menu.set_flag(L'b');
					break;
				case(sf::Keyboard::L):
					menu.set_flag(L'l');
					break;
				case(sf::Keyboard::R):
					menu.set_flag(L'r');
					break;
				case(sf::Keyboard::A):
					menu.set_flag(L'a');
					break;
				case(sf::Keyboard::C):
					menu.set_flag(L'c');
					break;
				case(sf::Keyboard::W):
					break;
				case(sf::Keyboard::O):
					break;
				case(sf::Keyboard::Escape):
					window.close();
				}

			}
		}
		//Draw BEGIN
		// Pomiêdzy "Draw BEGIN" a "Draw End" trzeba "cos" dopisac :-). Na pewno znajd¹ siê tam te dwie linijki:
		window.draw(menu);
		window.display();

		//Draw END
	}
	return 0;
}