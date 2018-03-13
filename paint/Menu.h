#pragma once
#include <SFML/Graphics.hpp>

class Menu : public sf::Drawable
{
private:
	sf::Font font;
	sf::Text *text;
	sf::RectangleShape *rectangle;

	sf::RectangleShape *draw_color_rectangle;
	sf::RectangleShape *fill_color_rectangle;

	sf::Color draw_color;
	sf::Color fill_color;

	sf::Texture *colors_texture;
	sf::Sprite *colors_sprite;
	sf::Uint8 *colors_pixels;

	wchar_t flag;

	const unsigned int colors_size_x = 765;
	const unsigned int colors_size_y = 60;

	inline void draw_to_color_pixels(unsigned int x, unsigned int y, unsigned char r, unsigned char g, unsigned char b);

	void set_color(int mouse_clicked_x, int mouse_clicked_y, sf::Color &color);
public:
	Menu();

	void outtextxy(sf::RenderTarget& target, float x, float y, const wchar_t *str) const;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	wchar_t get_flag() const
	{
		return flag;
	}
	void set_flag(const wchar_t flag)
	{
		this->flag = flag;
	}

	void set_draw_color(int mouse_clicked_x, int mouse_clicked_y);
	void set_fill_color(int mouse_clicked_x, int mouse_clicked_y);
};