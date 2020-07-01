#pragma once
#include <SFML/Graphics.hpp>
#include <windows.h>
#include"brash.h"
#include"pan.h"
using namespace sf;

Event event;


void eva1(RenderWindow& window)
{
	bool c = 1;
	while (c)
	{
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case Event::MouseButtonPressed:
				{
					brash io(Color(0, 0, 0));
					bool last = 1;
					while (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						sf::Vector2i localPosition = sf::Mouse::getPosition(window);
						io.draw(localPosition.x, localPosition.y, last, window);
						last = 0;
					}
					break;
				}

				default:
				{
					break;
				}
			}
		}
	}
}


void eva(RenderWindow& window)
{
	while (window.pollEvent(event))
	{
		switch (event.type)
		{

			case Event::MouseButtonPressed:
			{
				pan io(Color(255, 0, 0));
				bool last = 1;
				while (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					
					sf::Vector2i localPosition = sf::Mouse::getPosition(window);
					io.draw(localPosition.x, localPosition.y, last, window);
					last = 0;
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
			
			case Event::KeyPressed:
			{
				if (event.key.code == Keyboard::LAlt)
				{
					eva1(window);
				}

				if (event.key.code == Keyboard::BackSpace)
				{
					window.clear(Color(100, 100, 100));
					window.display();
				}
				break;
			}
			
		}
	}
}