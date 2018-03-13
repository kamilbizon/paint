#include "Background.h"

Background::Background()
{
	window_texture.create(800, 650);
	sprite.setTexture(window_texture);
}

void Background::update_window_texture(sf::RenderWindow &window)
{
	window_texture.update(window);
}
