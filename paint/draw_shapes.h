#pragma once
#include <SFML/Graphics.hpp>

sf::VertexArray* draw_line(float mouse_clicked_x, float mouse_clicked_y, float mouse_moved_x, float mouse_moved_y);
sf::RectangleShape* draw_rectangle_empty(float mouse_clicked_x, float mouse_clicked_y,
	float mouse_moved_x, float mouse_moved_y, sf::Color fill);
