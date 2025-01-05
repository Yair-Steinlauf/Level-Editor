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
	void draw(sf::RenderWindow& window);
	Board loadFromFile(std::string fileName);
	Board m_board;
	Menu m_menu;


};