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

	
	
private:
	sf::Texture window_texture;
	sf::Sprite sprite;
	sf::Image image;
};

