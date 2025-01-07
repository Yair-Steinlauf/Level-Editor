#include "GameObject.h"
#include "iostream"
GameObject::GameObject(enum ObjectType type)
{
	m_type = type;
	m_texture = DataLoader::getP2Texture(type);
}

void GameObject::draw(sf::RenderWindow& window, sf::Vector2f& location, sf::Vector2f& size)const
{
	auto sprite = sf::Sprite();
	sprite.setPosition(location);
	sprite.setTexture(*m_texture);
	sprite.setScale(size);
	window.draw(sprite);
}

ObjectType GameObject::getObjectType()const
{
	return m_type;
}




