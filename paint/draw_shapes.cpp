#include "draw_shapes.h"
#include <SFML/Graphics.hpp>
#include <math.h>



sf::VertexArray* draw_line(float mouse_clicked_x, float mouse_clicked_y, float mouse_moved_x, float mouse_moved_y)
{
	if (mouse_clicked_y < 61)
		mouse_clicked_y = 62;
	if (mouse_clicked_y > 599)
		mouse_clicked_y = 598;

	if (mouse_moved_y < 61)
		mouse_moved_y = 62;
	if (mouse_moved_y > 599)
		mouse_moved_y = 598;


	sf::VertexArray* line = new sf::VertexArray(sf::LinesStrip, 2);
	(*line)[0].position = sf::Vector2f(mouse_clicked_x, mouse_clicked_y);
	(*line)[1].position = sf::Vector2f(mouse_moved_x, mouse_moved_y);

	return line;
}

sf::RectangleShape * draw_rectangle_empty(float mouse_clicked_x, float mouse_clicked_y,
	float mouse_moved_x, float mouse_moved_y, sf::Color fill)
{
	if (mouse_clicked_y < 61)
		mouse_clicked_y = 62;
	if (mouse_clicked_y > 599)
		mouse_clicked_y = 598;

	if (mouse_moved_y < 61)
		mouse_moved_y = 62;
	if (mouse_moved_y > 599)
		mouse_moved_y = 598;


	float height = fabs(mouse_clicked_y - mouse_moved_y);
	float width = fabs(mouse_clicked_x - mouse_moved_x);

	float lower_x = (mouse_clicked_x < mouse_moved_x) ? mouse_clicked_x : mouse_moved_x;
	float lower_y = (mouse_clicked_y < mouse_moved_y) ? mouse_clicked_y : mouse_moved_y;



	sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2f(width, height));
	rectangle->setFillColor(fill);
	rectangle->setOutlineColor(sf::Color::White);
	rectangle->setOutlineThickness(1.0f);
	rectangle->setPosition(lower_x, lower_y);

	return rectangle;
}