#pragma once

#include <algorithm>
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "entities/playerCharacter.hpp"

struct Quadtree {
    static const int MAX_OBJECTS = 1000;
    static const int MAX_LEVELS = 5;

    int level;
    std::vector<sf::Drawable*> objects;
    sf::FloatRect bounds;
    std::vector<std::unique_ptr<Quadtree>> nodes;

    Quadtree(int pLevel, sf::FloatRect pBounds);
    void clear();
    void split();
    int getIndex(sf::FloatRect pRect);
    void insert(sf::Drawable* object, sf::FloatRect rect);
    void retrieve(std::vector<sf::Drawable*>& returnObjects, sf::FloatRect rect);
};

struct World {
    int DIAMETER = 1000;
    int RADIUS = DIAMETER / 2;

    Quadtree coordinateQuadtree;
    PlayerCharacter pc;

    World();
    void render(sf::RenderWindow& window);
    void addObject(sf::Drawable* object, sf::FloatRect rect);
    //void removeObject(sf::Drawable* object, sf::FloatRect rect);
};