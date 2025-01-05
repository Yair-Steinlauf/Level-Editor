#include "Board.h"  


Board::Board(int Height, int Width)
{
    m_board = defualtBoard(Height, Width);
}

Board::Board(std::ifstream& file)
{
    std::vector<std::string> str = fileToString(file);
    loadGameObjectVector(str);
}

int Board::getHeigth() const
{
    return m_board.size();
}

int Board::getWidth() const
{
    return m_board[0].size();
}


void Board::createGameObject(int row, int col, enum ObjectType type)
{
    m_board[row][col] = GameObject(type);
}

std::vector<std::string>& Board::fileToString(std::ifstream& file)
{
    std::string line;
    std::vector<std::string> board;
    while (std::getline(file, line)) {
        board.push_back(line);
    }
    file.close();
    return board;
}
void Board::loadGameObjectVector(std::vector<std::string>& str)
{
    for (int row = 0; row < str.size(); row++)
    {
        std::vector<GameObject> line;
        for (int col = 0; col < str[row].size(); col++)
        {
            line.emplace_back(GameObject((ObjectType)str[row][col]));
        }
        m_board.push_back(line);
    }
}
ObjectType Board::gameObject2ObjectType(GameObject& object)
{
    return object.getObjectType();
}
GameObject Board::objectType2GameObject(ObjectType type)
{
    return GameObject(type);
}
GameObject& Board::operator()(int row, int col)
{
	if (row < m_board.size() && col < m_board[row].size())
	{
		return m_board[row][col];
	}
}

void Board::draw(sf::RenderWindow& window)
{
    float tileSize = (windowHeight - menuHeight - this->getHeigth()) / std::max(this->getHeigth(), this->getWidth());
    float startPoint = (windowWidth - this->getWidth() * (tileSize + 1)) / 2;

    for (int row = 0; row < m_board.size(); row++)
    {
        for (int col = 0; col < m_board[row].size(); col++)
        {
            auto size = sf::Vector2f(tileSize, tileSize);
            auto location = sf::Vector2f(float(col * (tileSize + 1) + startPoint), float(row * (tileSize + 1) + matHeight));
            m_board[row][col].draw(window, location, size);
        }
    }
}

std::vector<std::vector<GameObject>> Board::defualtBoard(int Height, int Width)
{
    std::vector<GameObject> line;
    for (int i = 0; i < Width; i++)
    {
        line.emplace_back(GameObject(EMPTY));
    }
    std::vector<std::vector<GameObject>> board;
    for (int i = 0; i < Height; i++)
    {
        board.push_back(line);
    }
    return board;
}
