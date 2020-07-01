#pragma once
#include <SFML/Graphics.hpp>
#include<Windows.h>
#include<vector>
class brash
{
public:

	brash(sf::Color col) :color(col), q(1)
	{
	}

	virtual void draw(int x, int y, bool last, sf::RenderWindow& window)
	{
		static unsigned int t = 0;
		static unsigned int xl, yl;
		static std::vector<sf::ConvexShape> shape;
		if (!last)
		{
			xl = x;
			yl = y;
			t = 0;
			shape.clear();
		}
		sf::ConvexShape set(4);
		shape.push_back(set);



		shape[t].setPoint(3, sf::Vector2f(xl - 10, yl - 10));
		shape[t].setPoint(2, sf::Vector2f(xl + 10, yl - 10));
		shape[t].setPoint(1, sf::Vector2f(x + 10, y + 10));
		shape[t].setPoint(0, sf::Vector2f(x - 10, y + 10));
		window.draw(shape[t]);
		window.display();
		t += 1;
		xl = x;
		yl = y;

		
	
	}

protected:

private:
	int q;
	sf::Color color;
};