#pragma once
#include "vector"
#include "Structs.h"
#include "string"
#include "fstream"
#include "SFML/Graphics.hpp"
#include "GameObject.h"
#include "DataLoader.h"
//TODO: get tile from coords function

class Board {
public:
	explicit Board(int Height, int Width);
	explicit Board(std::ifstream& file);
	int getHeigth() const;
	int getWidth() const;
	void createGameObject(int row, int col, enum ObjectType type);
	void saveToFile(std::ofstream file);
	GameObject& operator()(int row, int col);
	GameObject& operator()(sf::Vector2f coords);
	void draw(sf::RenderWindow& window);
private:
	std::vector<std::string>& fileToString(std::ifstream& fileName);
	void loadGameObjectVector(std::vector<std::string>& str);
	ObjectType gameObject2ObjectType(GameObject& object);
	GameObject objectType2GameObject(enum ObjectType type);
	std::vector<std::vector<GameObject>> m_board;
	std::vector<std::vector<GameObject>> defualtBoard(int Height, int Width);



};