#pragma once
#include <SFML/Graphics.hpp>

sf::VertexArray* draw_line(float mouse_clicked_x, float mouse_clicked_y,
	float mouse_moved_x, float mouse_moved_y, sf::Color draw_color, sf::Color fill_color);

sf::RectangleShape* draw_rectangle_empty(float mouse_clicked_x, float mouse_clicked_y,
	float mouse_moved_x, float mouse_moved_y, sf::Color outline_color, sf::Color fill_color);

sf::CircleShape* draw_circle(float mouse_clicked_x, float mouse_clicked_y,
	float mouse_moved_x, float mouse_moved_y, sf::Color draw_color);