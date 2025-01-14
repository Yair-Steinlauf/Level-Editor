#pragma once
#include "SFML/Graphics.hpp"
#include "Structs.h"
#include "DataLoader.h"
class GameObject {
public:
	explicit GameObject(enum ObjectType type); 
	void draw(sf::RenderWindow& window, sf::Vector2f& location, sf::Vector2f& size)const;
	enum ObjectType getObjectType()const;

private:
	sf::Texture* m_texture;	
	enum ObjectType m_type;
};