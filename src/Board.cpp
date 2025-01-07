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

void Board::saveToFile(std::ofstream& out)const
{
    for (int rowIndex = 0; rowIndex < getHeigth(); rowIndex++)
    {
        for (int colIndex = 0; colIndex < getWidth(); colIndex++)
        {
            out <<(char) m_board[rowIndex][colIndex].getObjectType();
        }
        out << std::endl;
    }
}

std::vector<std::string> Board::fileToString(std::ifstream& file)const
{
    std::string line;
    std::vector<std::string> board;
    while (std::getline(file, line)) {
        board.push_back(line);
    }
    file.close();
    return board;
}
void Board::loadGameObjectVector(const std::vector<std::string>& str)
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

GameObject& Board::operator()(int row, int col)
{
	if (row >= 0 && row < getHeigth() && col >= 0 && col < getWidth())
	{
		return m_board[row][col];
	}

    return defaultObj;

}



const GameObject& Board::operator()(int row, int col) const
{
    if (row >= 0 && row < getHeigth() && col >= 0 && col < getWidth())
    {
        return m_board[row][col];
    }
    return defaultObj;

}

GameObject& Board::operator()(const sf::Vector2f& coords)
{

        float tileSize = (windowHeight - menuHeight - this->getHeigth()) / std::max(this->getHeigth(), this->getWidth());
        float startPoint = (windowWidth - this->getWidth() * (tileSize + 1)) / 2;

        // Calculate row and column from coordinates
        int row = static_cast<int>((coords.y - matHeight) / (tileSize + 1));
        int col = static_cast<int>((coords.x - startPoint) / (tileSize + 1));

        return operator()(row,col);

}

sf::Vector2f Board::getCoords(int row, int col)const
{
    float tileSize = (windowHeight - menuHeight - this->getHeigth()) / std::max(this->getHeigth(), this->getWidth());
    float startPoint = (windowWidth - this->getWidth() * (tileSize + 1)) / 2;
    auto location = sf::Vector2f(float(col * (tileSize + 1) + startPoint), float(row * (tileSize + 1) + matHeight));
    return location;

}
void Board::draw(sf::RenderWindow& window)const
{
    float scale = 2.5f / std::max(this->getWidth(), this->getHeigth());

    for (int row = 0; row < m_board.size(); row++)
    {
        for (int col = 0; col < m_board[row].size(); col++)
        {
            auto size = sf::Vector2f(scale, scale);
            sf::Vector2f location = getCoords(row, col);
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
