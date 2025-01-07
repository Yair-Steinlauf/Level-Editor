#include "Menu.h"
#include <stdexcept>

namespace {
	constexpr float BUTTON_SPACING = 150.0f;
	constexpr float BUTTON_SCALE = 0.25f;
	constexpr float MENU_START_Y = 0.0f;
}

Menu::Menu()
{
	std::string buttomOrder = loadFromFile("Toolbar.txt");
	m_buttoms.push_back(GameObject(SAVE));
	m_buttoms.push_back(GameObject(DELETE));
	m_buttoms.push_back(GameObject(NEWPAGE));
	for (int index = 0; index < buttomOrder.length(); index++)
	{
		m_buttoms.push_back(GameObject(ObjectType(buttomOrder[index])));
	}
}

void Menu::draw(sf::RenderWindow& window)
{
	float startPoint = 0; 
	float scale = 0.25;
	float space = 150.0f;
	for (int col = 0; col < m_buttoms.size(); col++)
	{
			auto size = sf::Vector2f(scale, scale);
			auto location = sf::Vector2f(float(col * space), float(startPoint));
			m_buttoms[col].draw(window, location, size);
	}
}

int Menu::getHeight() const
{
	return 1;
}

int Menu::getWidth() const
{
	return m_buttoms.size();
}

std::string Menu::loadFromFile(std::string fileName)
{
	auto file = std::ifstream(fileName);
	std::string line;
	std::getline(file, line);
	return line;
}

GameObject Menu::operator()(const  sf::Vector2f coords) const {
	// Constants should ideally be class members or configuration parameters
	const float tileSize = (windowHeight - this->getHeight()) /
		std::max(this->getHeight(), this->getWidth());
	const float startPoint = 0.0f;

	int col = static_cast<int>((coords.x - startPoint) / BUTTON_SPACING);

	if (col >= 0 && col < static_cast<int>(m_buttoms.size())) {
		return m_buttoms[col];
	}

	// Return a default/invalid GameObject when out of bounds
	throw std::out_of_range("Menu coordinates out of bounds");
}
