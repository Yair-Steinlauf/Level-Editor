#pragma once
#include "vector"
#include "string"
#include "SFML/Graphics.hpp"
#include "memory"
#include "Structs.h"

class DataLoader {
public:
    // Delete copy constructor and assignment
    DataLoader(const DataLoader&) = delete;
    DataLoader& operator=(const DataLoader&) = delete;

    // Singleton access
    static DataLoader& getInstance() {
        static DataLoader instance;
        return instance;
    }

    // Get texture by type
    static sf::Texture* getP2Texture(ObjectType type);

private:
    // Private constructor for singleton
    DataLoader();

    // Store textures using unique_ptr to manage memory
    static inline std::vector<std::unique_ptr<sf::Texture>> m_textures;
    static inline const std::vector<std::string> m_objectNames = {
        "ROBOT", "GUARD", "DOOR", "WALL", "ROCK", "EMPTY"
    };
};


//class DataLoader {
//public:
//	DataLoader();
//	static sf::Texture* getP2Texture(enum ObjectType type);
//private:
//	static inline std::vector <sf::Texture> m_textures;
//	static inline std::vector<std::string> m_objectNames = { "ROBOT" ,"GUARD", "DOOR",
//											   "WALL","ROCK", "EMPTY" };
//};