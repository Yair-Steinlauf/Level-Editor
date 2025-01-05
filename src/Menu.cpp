#include "Menu.h"

Menu::Menu()
{
	std::string buttomOrder = loadFromFile("Toolbar.txt");
	m_buttoms.push_back(GameObject(SAVE));
	m_buttoms.push_back(GameObject(DELETE));
	m_buttoms.push_back(GameObject(NEWPAGE));
	for (int index = 0; index < buttomOrder.size(); index++)
	{
		m_buttoms.push_back(GameObject(ObjectType(buttomOrder[index])));
	}
}
void Menu::draw(sf::RenderWindow& window)
{
    // Fixed button size and spacing
    const float buttonSize = 50.0f;  // Fixed size for each button
    const float spacing = 10.0f;     // Space between buttons

    // Calculate start point to center the menu
    float totalWidth = (buttonSize + spacing) * m_buttoms.size() - spacing;
    float startPoint = (windowWidth - totalWidth) / 2;

    // Fixed scale for buttons
    float scale = 0.2f;  // Keep your existing scale

    // Fixed Y position for the menu
    float menuY = 10.0f;  // Distance from top of window

    // Draw each button
    for (int col = 0; col < m_buttoms.size(); col++)
    {
        auto size = sf::Vector2f(scale, scale);
        auto location = sf::Vector2f(
            startPoint + col * (buttonSize + spacing),  // X position
            menuY                                       // Y position
        );
        m_buttoms[col].draw(window, location, size);
    }
}
//void Menu::draw(sf::RenderWindow& window)
//{
//	float tileSize = 0;// (windowHeight - this->getHeight()) / std::max(this->getHeight(), this->getWidth());
//	float startPoint = (windowWidth - this->getWidth() * (tileSize + 1)) / 2;
//	float scale = 0.25;// 3.9f / std::max(this->getWidth(), this->getHeight());
//
//	for (int col = 0; col < m_buttoms.size(); col++)
//	{
//			auto size = sf::Vector2f(scale, scale);
//			auto location = sf::Vector2f(float(col * (tileSize + 1) + startPoint), float((tileSize + 1)));
//			m_buttoms[col].draw(window, location, size);
//	}
//}

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
