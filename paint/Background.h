#pragma once

#include <SFML/Graphics.hpp>

class Background
{
public:
	Background();
	void update_window_texture(sf::RenderWindow &window);

	sf::Sprite get_sprite()
	{
		return sprite;
	}

	sf::Texture* get_window_texture()
	{
		return &window_texture;
	}

	void save_image();
	void read_from_file();
	
private:
	sf::Texture window_texture;
	sf::Sprite sprite;
	sf::Image image;
};

