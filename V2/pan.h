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
		
		static sf::VertexArray shape(sf::LineStrip);
		

		shape.append(sf::Vector2f(x, y));

		window.draw(shape);
		
		window.display();
	}

protected:

private:
	int q;
	sf::Color color;
};