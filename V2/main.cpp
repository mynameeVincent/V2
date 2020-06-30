#include"head.h"

int main()
{
	RenderWindow window(VideoMode(200, 200), "SFMLworks", Style::Fullscreen);
	

	while (1)
	{
		eva(window);
	}
	/*
	pan io(Color(0, 255, 0));
	bool last=0;
	while (1) 
	{
		while (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i localPosition = sf::Mouse::getPosition(window);
			io.draw(localPosition.x, localPosition.y, last, window);
		}
		last = 1;
	}
	*/

	return 0;
}
