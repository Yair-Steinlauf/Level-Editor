#include "DataLoader.h"



DataLoader::DataLoader() {
    // Reserve space to prevent reallocations
    m_textures.reserve(m_objectNames.size());

    for (const auto& objectName : m_objectNames) {
        auto texture = std::make_unique<sf::Texture>();
        if (!texture->loadFromFile(objectName + ".png")) {
            // Handle loading error
            throw std::runtime_error("Failed to load texture: " + objectName);
        }
        m_textures.push_back(std::move(texture));
    }
}
sf::Texture* DataLoader::getP2Texture(enum ObjectType type)
{
	auto& instance = getInstance();
	sf::Texture* temp;
	switch (type)
	{
	case ROBOT: return m_textures[TextureType::TROBOT].get();
		break;
	case GUARD: return m_textures[TextureType::TGUARD].get();
		break;
	case DOOR: return m_textures[TextureType::TDOOR].get();
		break;
	case WALL: return m_textures[TextureType::TWALL].get();
		break;
	case ROCK: return m_textures[TextureType::TROCK].get();
		break;
	case EMPTY:return m_textures[TextureType::TEMPTY].get();
		break;
	case DELETE:return m_textures[TextureType::TDELETE].get();
		break;
	case SAVE:return m_textures[TextureType::TSAVE].get();
		break;
	case NEWPAGE:return m_textures[TextureType::TNEWPAGE].get();
		break;
	}
}
