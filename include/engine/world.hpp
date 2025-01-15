#pragma once

#include <unordered_map>
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "entities/playerCharacter.hpp"

// Hash function for std::pair<int, int>
struct PairHash {
    template <typename T1, typename T2> 
    std::size_t operator()(const std::pair<T1, T2>& pair) const {
        auto hash1 = std::hash<T1>{}(pair.first);
        auto hash2 = std::hash<T2>{}(pair.second);
        return hash1 ^ hash2;
    }
};

struct World {
    // Constants
    int HEIGHT = 1280;
    int WIDTH = 720;
    int BUCKET_SIZE = 50; // Size of each bucket in the spatial hash

    // Spatial Hashing
    using Bucket = std::pair<int, int>;
    std::unordered_map<Bucket, std::vector<sf::Drawable*>, PairHash> spatialHash;

    // Entities
    PlayerCharacter pc;

    World();
    void render(sf::RenderWindow& window);
    void update();

    sf::Vector2f wrapPosition(sf::Vector2f position);

    // Spatial Hashing functions
    Bucket getBucket(sf::Vector2f position);
    void addObject(sf::Drawable* object, sf::FloatRect rect);
    void removeObject(sf::Drawable* object, sf::FloatRect rect);
    void checkCollisions();
    
    PlayerCharacter& getPlayerCharacter();
};