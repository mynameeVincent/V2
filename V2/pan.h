#pragma once
#include <SFML/Graphics.hpp>
#include<Windows.h>
class pan
{
public:

	pan(sf::Color col) :color(col), q(1)
	{
	}

	virtual void draw(int x, int y, bool last, sf::RenderWindow& window)
	{
		static int t = 0;
		static sf::VertexArray shape(sf::LineStrip);

		if (last)
		{
			window.draw(shape);
			window.display();
			shape.clear();
			t = 0;
		}
		shape.append(sf::Vector2f(x, y));
		shape[t].color = this->color;
		window.draw(shape);
		t++;
		window.display();
	}

protected:

private:
	int q;
	sf::Color color;
};