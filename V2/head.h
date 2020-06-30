#pragma once
#include <SFML/Graphics.hpp>
#include <windows.h>
#include"pan.h"
using namespace sf;

Event event;

/*
void eva1(RenderWindow& window)
{
	bool c = 1;
	while (c)
	{
		while (window.pollEvent(event))
		{
			window.clear(Color(0, 0, 0));
			window.display();
			switch (event.type)
			{
			case Event::KeyPressed:
			{
				if (event.key.code == Keyboard::Space)
				{

				}
				if (event.key.code == Keyboard::Delete)
				{
				}
				break;
			}
			}
		}
	}
}
*/

void eva(RenderWindow& window)
{
	while (window.pollEvent(event))
	{
		switch (event.type)
		{

			case Event::MouseButtonPressed:
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					pan io(Color(0, 0, 0));
					bool last = 1;
					while (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						last = 0;
						sf::Vector2i localPosition = sf::Mouse::getPosition(window);
						io.draw(localPosition.x, localPosition.y, last, window);
					}
					
				}
				break;
			}

			case Event::Closed:
			{
				window.close();
				break;
			}

			default:
			{
				break;
			}
			
			/*	case Event::KeyPressed:
			{
				if (event.key.code == Keyboard::Escape)
				{
					eva1(window);
//					window.close();
				}

				if (event.key.code == Keyboard::BackSpace)
				{
					window.clear(Color(100, 100, 100));
					window.display();
				}
				break;
			}
			*/
		}
	}
}