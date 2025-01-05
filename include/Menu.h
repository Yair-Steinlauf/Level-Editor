#pragma once
#include "vector"
#include "Structs.h"
#include "DataLoader.h"
#include "GameObject.h"
#include "string"
#include "fstream"
#include "SFML/Graphics.hpp"
class Menu {
public:
	Menu();
	void draw(sf::RenderWindow& window);
	int getHeight() const;
	int getWidth() const;
private:
	std::string loadFromFile(std::string fileName);
	std::vector<GameObject> m_buttoms;

};