#include "Controller.h"


Controller::Controller()
	:m_board(loadFromFile("Board.txt"))
{}

void Controller::run()
{

	auto window = sf::RenderWindow(sf::VideoMode(windowWidth, 740), "Level Editor");

	while (window.isOpen())
	{
		window.clear();
		m_board.draw(window);
		window.display();

		if (auto event = sf::Event{}; window.waitEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			//case sf::Event::MouseButtonReleased:
			//{
			//	auto location = window.mapPixelToCoords(
			//		{ event.mouseButton.x, event.mouseButton.y });

			//	switch (event.mouseButton.button)
			//	{
			//	case sf::Mouse::Button::Left:
			//		m_board(location.x,location.y) = GameObject(GUARD);
			//		break;
			//		//case sf::Mouse::Button::Right:
			//		//    handleClick(location);
			//		//    break;
			//	}

			//	break;
			//}
			}
		}
	}
}


Board Controller::loadFromFile(std::string fileName)
{
	auto file = std::ifstream (fileName);
	if (!file)
	{
		std::cout << "enter heigth & width\n";
		int heigth, width;
		std::cin >> heigth >> width;
		return Board(heigth, width);
	}
	else
		return Board(file);
}


