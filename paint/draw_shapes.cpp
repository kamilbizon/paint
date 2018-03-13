#include "draw_shapes.h"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

#define M_PI 3.14159265358979323846

sf::VertexArray* draw_line(float mouse_clicked_x, float mouse_clicked_y,
	float mouse_moved_x, float mouse_moved_y, sf::Color draw_color, sf::Color fill_color)
{
	if (mouse_clicked_y > 61 && mouse_clicked_y < 599)
	{
		// jezeli rysujacy wyjedzie poza krawedz obszaru rysowania przenies wspolrzedna do wnetrza obszaru
		if (mouse_moved_y < 61)
			mouse_moved_y = 62;
		if (mouse_moved_y > 599)
			mouse_moved_y = 598;


		sf::VertexArray* line = new sf::VertexArray(sf::LinesStrip, 2);
		(*line)[0].position = sf::Vector2f(mouse_clicked_x, mouse_clicked_y);
		(*line)[0].color = draw_color;
		(*line)[1].position = sf::Vector2f(mouse_moved_x, mouse_moved_y);
		(*line)[1].color = fill_color;

		return line;
	}
	else
		return NULL;
}

sf::RectangleShape * draw_rectangle_empty(float mouse_clicked_x, float mouse_clicked_y,
	float mouse_moved_x, float mouse_moved_y, sf::Color outline_color, sf::Color fill_color)
{
	if (mouse_clicked_y > 61 && mouse_clicked_y < 599)
	{
		if (mouse_moved_y < 61)
			mouse_moved_y = 62;
		if (mouse_moved_y > 599)
			mouse_moved_y = 598;


		float height = fabs(mouse_clicked_y - mouse_moved_y);
		float width = fabs(mouse_clicked_x - mouse_moved_x);

		float lower_x = (mouse_clicked_x < mouse_moved_x) ? mouse_clicked_x : mouse_moved_x;
		float lower_y = (mouse_clicked_y < mouse_moved_y) ? mouse_clicked_y : mouse_moved_y;



		sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2f(width, height));
		rectangle->setFillColor(fill_color);
		rectangle->setOutlineColor(outline_color);
		rectangle->setOutlineThickness(1.0f);
		rectangle->setPosition(lower_x, lower_y);

		return rectangle;
	}
	else
		return NULL;
}

sf::CircleShape* draw_circle(float mouse_clicked_x, float mouse_clicked_y,
	float mouse_moved_x, float mouse_moved_y, sf::Color draw_color)
{
	if (mouse_clicked_y > 61 && mouse_clicked_y < 599)
	{
		if (mouse_moved_y < 61)
			mouse_moved_y = 62;
		if (mouse_moved_y > 599)
			mouse_moved_y = 598;

		float x = mouse_moved_x - mouse_clicked_x;
		float y = mouse_moved_y - mouse_clicked_y;
		float radius = fabs(sqrt(x*x + y*y)/1.95);
		float angle = atan(y/x) * 180.0 / M_PI;

		std::cout << angle <<"\n";

		sf::CircleShape* circle = new sf::CircleShape(0.1f);

		circle->setFillColor(sf::Color::Transparent);
		circle->setOutlineColor(draw_color);
		circle->setOutlineThickness(1.0f);
		circle->setPosition(mouse_clicked_x, mouse_clicked_y - radius * 0.5);
		circle->setOrigin(0, radius * 0.5);
		circle->setRadius(radius);
		circle->setRotation(angle);

		return circle;
	}
	else
		return NULL;
}