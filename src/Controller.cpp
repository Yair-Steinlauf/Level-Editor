#include "Controller.h"


Controller::Controller()
	:m_board(loadFromFile("Board.txt")), 
	m_menu()
{}

void Controller::run()
{

	auto window = sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "Level Editor");
	sf::RectangleShape background(sf::Vector2f(windowWidth, windowHeight));
	background.setFillColor(sf::Color(128, 0, 128)); 

	while (window.isOpen())
	{
		window.clear();
		window.draw(background);
		m_board.draw(window);
		m_menu.draw(window);
		window.display();

		if (auto event = sf::Event{}; window.waitEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonReleased:
			{
				auto location = window.mapPixelToCoords(
					{ event.mouseButton.x, event.mouseButton.y });

				switch (event.mouseButton.button)
				{
				case sf::Mouse::Button::Left:
					m_board(location) = GameObject(GUARD);
					break;
			//		//case sf::Mouse::Button::Right:
			//		//    handleClick(location);
			//		//    break;
				}

			//	break;
			}
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


