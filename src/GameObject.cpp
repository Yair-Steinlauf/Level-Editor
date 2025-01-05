#include "GameObject.h"
#include "iostream"
GameObject::GameObject(enum ObjectType type)
{
	m_type = type;
	m_texture = DataLoader::getP2Texture(type);
}

void GameObject::draw(sf::RenderWindow& window, sf::Vector2f& location, sf::Vector2f& size)
{
	auto sprite = sf::Sprite();
	sprite.setPosition(location);
	sprite.setTexture(*m_texture);
	sprite.setScale(size);//TODO: understand how to change pic size
	window.draw(sprite);
}

ObjectType GameObject::getObjectType()
{
	return m_type;
}

bool GameObject::contain(sf::Vector2f coords,sf::Vector2f& location, sf::Vector2f& size)
{
	auto sprite = sf::Sprite();
	sprite.setPosition(location);
	sprite.setTexture(*m_texture);
	sprite.setScale(size);//TODO: understand how to change pic size
	auto boundingRec = sprite.getLocalBounds();
	return boundingRec.contains(coords);
}

