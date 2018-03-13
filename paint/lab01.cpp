// Calosc mozna dowolnie edytowac wedle uznania. 

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Background.h"
#include "draw_shapes.h"

#include <iostream>



int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 650), "GFK Lab 01",sf::Style::Titlebar | sf::Style::Close);
	sf::Event event;
	Menu menu;

	float mouse_clicked_x = 0, mouse_clicked_y = 0;
	float mouse_moved_x = 0, mouse_moved_y = 0;

	Background background;

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
					menu.set_flag(L' ');
					background.save_image();
					break;
				case(sf::Keyboard::O):
					menu.set_flag(L' ');
					background.read_from_file();
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
			}
			if (event.type == sf::Event::MouseMoved)
			{
				mouse_moved_x = (float)event.mouseMove.x;
				mouse_moved_y = (float)event.mouseMove.y;
			}
			if (event.type == sf::Event::MouseButtonReleased)
			{
				is_shape_drawed = true;
			}
		}


		//Draw BEGIN
		// Pomiêdzy "Draw BEGIN" a "Draw End" trzeba "cos" dopisac :-). Na pewno znajd¹ siê tam te dwie linijki:
		window.draw(menu);
		window.draw(background.get_sprite());

		// Wykonywanie dzialania zgodnego z flaga, pobieranie koloru i rysowanie ksztaltow
		if(mouse_moved_x != 0 && mouse_moved_y != 0 && mouse_clicked_x != 0 && mouse_clicked_y != 0)
		{
			sf::Drawable *shape = NULL;
			switch (menu.get_flag())
			{
			case(L'f'):
				menu.set_draw_color((int)mouse_clicked_x, (int)mouse_clicked_y);
				break;
			case(L'b'):
				menu.set_fill_color((int)mouse_clicked_x, (int)mouse_clicked_y);
				break;
			case(L'l'):
				shape = draw_line(mouse_clicked_x, mouse_clicked_y, mouse_moved_x, mouse_moved_y,
								  menu.get_draw_color(), menu.get_fill_color());
				break;
			case(L'r'):
				shape = draw_rectangle_empty(mouse_clicked_x, mouse_clicked_y, mouse_moved_x, mouse_moved_y, 
											 menu.get_draw_color(), sf::Color::Transparent);
				break;
			case(L'a'):
				shape = draw_rectangle_empty(mouse_clicked_x, mouse_clicked_y, mouse_moved_x, mouse_moved_y,
											 menu.get_draw_color(), menu.get_fill_color());
				break;
			case(L'c'):
				shape = draw_circle(mouse_clicked_x, mouse_clicked_y, mouse_moved_x, mouse_moved_y,
									menu.get_draw_color());
				break;
			}

			if (shape != NULL)
			{
				window.draw(*shape);
				delete shape;
			}

			if (is_shape_drawed)
			{
				background.update_window_texture(window);

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