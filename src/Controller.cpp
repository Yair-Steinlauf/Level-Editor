#include "Controller.h"


Controller::Controller()
	:m_board(loadFromFile("Board.txt")), 
	m_menu(),m_current(EMPTY)
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
					handelClick(location);
					break;
				}
			}
			}
		}
	}
}

void Controller::handelClick(sf::Vector2f location)
{
	if (location.y < menuHeight)
	{
		m_current = m_menu(location);
	}
	switch (m_current.getObjectType())
	{
	case SAVE: //TODO: save to file func-- use save to file of board
		break;
	case DELETE: m_board(location) = GameObject(EMPTY);
		break;
	case NEWPAGE: // TODO: m_board.setToDefualt()
		break;
	default: //TODO: add special beavior for ROBOT and DOOR 
		m_board(location) = m_current;
		break;
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


