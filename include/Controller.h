#pragma once
#include "Board.h"
#include "string"
#include "SFML/Graphics.hpp"
#include "fstream"
#include "iostream"
#include "Menu.h"
class Controller {
public:
	Controller();
	sf::Vector2f findObject(ObjectType type);
	void run();
private:
	void handelClick(sf::Vector2f location);
	void handleUniqueObject(sf::Vector2f newLocation, ObjectType type);
	void saveToFile(std::string fileName);
	Board loadFromFile(std::string fileName);
	Board newBoard();
	Board m_board;
	Menu m_menu;
	GameObject m_current;
	sf::Vector2f m_doorLocation = sf::Vector2f(0, 0);
	sf::Vector2f m_robotLocation = sf::Vector2f(0, 0);


};