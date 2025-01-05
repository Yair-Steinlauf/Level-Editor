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
	void run();
private:
	void handelClick(sf::Vector2f location);
	void draw(sf::RenderWindow& window);
	void saveToFile(std::string fileName);
	void moveOnce(GameObject gameObj, sf::Vector2f loc);
	Board loadFromFile(std::string fileName);
	Board m_board;
	Menu m_menu;
	GameObject m_current;
	sf::Vector2f m_doorLocation;
	sf::Vector2f m_robotLocation;

};