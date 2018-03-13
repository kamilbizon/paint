#include "Background.h"

Background::Background()
{
	window_texture.create(800, 650);
	sprite.setTexture(window_texture);
	sprite.setTextureRect(sf::IntRect(2, 61, 796, 538));
	sprite.setPosition(2, 61);
}

void Background::update_window_texture(sf::RenderWindow &window)
{
	window_texture.update(window);
}

void Background::save_image()
{
	image = window_texture.copyToImage();
	image.saveToFile("./obrazek");
}