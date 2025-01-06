#include "Controller.h"


Controller::Controller()
	:m_board(loadFromFile("Board.txt")), 
	m_menu(),m_current(EMPTY)
{
	m_doorLocation = sf::Vector2f(0, 0);
	m_robotLocation = sf::Vector2f(0, 0);
}

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
		switch (m_current.getObjectType())
			{
			case SAVE: saveToFile("Board.txt");
				break;
			case NEWPAGE:
				m_board = newBoard();
				m_current = GameObject(EMPTY);
				break;
			case DELETE: m_current = GameObject(EMPTY);
				break;
		}
	}
	else
	{ 
		switch (m_current.getObjectType())
		{
			case  ROBOT:
				handleUniqueObject(location, ROBOT);
				break;
			case  DOOR:
				handleUniqueObject(location, DOOR);
				break;
			default:
				m_board(location) = m_current;
				break;
			}
		}
}

void Controller::handleUniqueObject(sf::Vector2f newLocation, ObjectType type)
{
	// Check if we're handling robot or door
	sf::Vector2f& currentLocation = (type == ROBOT) ? m_robotLocation : m_doorLocation;

	// If there's already an object of this type on the board
	if (currentLocation != sf::Vector2f(0, 0) &&
		m_board(currentLocation).getObjectType() == type)
	{
		// Remove the old object
		m_board(currentLocation) = GameObject(EMPTY);
	}

	// Place the new object and update its location
	m_board(newLocation) = GameObject(type);
	currentLocation = newLocation;
}



void Controller::saveToFile(std::string fileName)
{
	auto outPut = std::ofstream(fileName);
	if (outPut.is_open())
	{
		m_board.saveToFile(outPut);
	}
}



Board Controller::loadFromFile(std::string fileName)
{
	std::ifstream file(fileName);
	if (file.is_open())
	{
		return Board(file);
	}
	else
		return newBoard();
}

Board Controller::newBoard()
{
		std::cout << "enter heigth & width\n";
		int heigth, width;
		std::cin >> heigth >> width;
		return Board(heigth, width);
}


