// Calosc mozna dowolnie edytowac wedle uznania. 

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Menu.h"

#include <iostream>


sf::VertexArray draw_line(float mouse_clicked_x, float mouse_clicked_y, float mouse_moved_x, float mouse_moved_y);


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 650), "GFK Lab 01",sf::Style::Titlebar | sf::Style::Close);
	sf::Event event;
	Menu menu;

	float mouse_clicked_x = 0, mouse_clicked_y = 0;
	float mouse_moved_x = 0, mouse_moved_y = 0;

	sf::Texture background;
	background.create(800, 650);

	sf::Sprite sprite;

	bool is_shape_drawed = false;
 
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

			if (event.type == sf::Event::MouseButtonPressed)
				if(event.mouseButton.button == sf::Mouse::Left)
				{
					mouse_clicked_x = (float)event.mouseButton.x;
					mouse_clicked_y = (float)event.mouseButton.y;

					if (mouse_clicked_y < 60)
						mouse_clicked_y = 61;
					if (mouse_clicked_y > 600)
						mouse_clicked_y = 599;

			}
			if (event.type == sf::Event::MouseMoved)
			{
				mouse_moved_x = (float)event.mouseMove.x;
				mouse_moved_y = (float)event.mouseMove.y;

				if (mouse_moved_y < 60)
					mouse_moved_y = 61;
				if (mouse_moved_y > 600)
					mouse_moved_y = 599;
			}
			if (event.type == sf::Event::MouseButtonReleased)
			{
				std::cout << "realeas";

				is_shape_drawed = true;
			}
		}


		//Draw BEGIN
		// Pomiêdzy "Draw BEGIN" a "Draw End" trzeba "cos" dopisac :-). Na pewno znajd¹ siê tam te dwie linijki:
		window.draw(menu);
		window.draw(sprite);

		
		if(mouse_moved_x != 0 && mouse_moved_y != 0 && mouse_clicked_x != 0 && mouse_clicked_y != 0)
		{
			sf::VertexArray line = draw_line(mouse_clicked_x, mouse_clicked_y, mouse_moved_x, mouse_moved_y);

			window.draw(line);

			if (is_shape_drawed)
			{
				background.update(window);
				sprite.setTexture(background);
				is_shape_drawed = false;

				mouse_clicked_x = 0;
				mouse_clicked_y = 0;
				mouse_moved_x = 0;
				mouse_moved_y = 0;
			}
		}

		window.display();

		//Draw END
	}
	return 0;
}


sf::VertexArray draw_line(float mouse_clicked_x, float mouse_clicked_y, float mouse_moved_x, float mouse_moved_y)
{
	sf::VertexArray line(sf::LinesStrip, 2);
	line[0].position = sf::Vector2f(mouse_clicked_x, mouse_clicked_y);
	line[1].position = sf::Vector2f(mouse_moved_x, mouse_moved_y);

	return line;
}