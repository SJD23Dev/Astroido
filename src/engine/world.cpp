#include "engine/world.hpp"

Quadtree::Quadtree(int pLevel, sf::FloatRect pBounds) : level(pLevel), bounds(pBounds) {
    nodes.reserve(4);
}

void Quadtree::clear() {
    objects.clear();
    for (auto& node: nodes) {
        if (node) {
            node->clear();
            node.reset();
        }
    }
    nodes.clear();
}

void Quadtree::split() {
    float subWidth = bounds.width / 2.0f;
    float subHeight = bounds.height / 2.0f;
    float x = bounds.left;
    float y = bounds.top;

    nodes.push_back(std::make_unique<Quadtree>( 
                    level + 1,
                    sf::FloatRect(x + subWidth, y, subWidth, subHeight)
    ));

    nodes.push_back(std::make_unique<Quadtree>(
                    level + 1, 
                    sf::FloatRect(x, y, subWidth, subHeight)
    ));

    nodes.push_back(std::make_unique<Quadtree>(
                    level + 1, 
                    sf::FloatRect(x, y + subHeight, subWidth, subHeight)
    ));

    nodes.push_back(std::make_unique<Quadtree>(
                    level + 1, 
                    sf::FloatRect(x + subWidth, y + subHeight, subWidth, subHeight)
    ));
}

int Quadtree::getIndex(sf::FloatRect rect) {
    int index = -1;

    float verticalMidpoint = bounds.left + (bounds.width / 2.0f);
    float horizontalMidpoint = bounds.top + (bounds.height / 2.0f);

    bool topQuadrant = (rect.top < horizontalMidpoint && rect.top + rect.height < horizontalMidpoint);
    bool bottomQuadrant = (rect.top > horizontalMidpoint);

    if (rect.left < verticalMidpoint && rect.left + rect.width < verticalMidpoint) {
        if (topQuadrant) {
            index = 1;
        } else if (bottomQuadrant) {
            index = 2;
        }
    } else if (rect.left > verticalMidpoint) {
        if (topQuadrant) {
            index = 0;
        } else if (bottomQuadrant) {
            index = 3;
        }
    }

    return index;
}

void Quadtree::insert(sf::Drawable* object, sf::FloatRect rect) {
    if (!nodes.empty()) {
        int index = getIndex(rect);

        if (index != -1) {
            nodes[index]->insert(object, rect);
            return;
        }
    }

    objects.push_back(object);

    if (objects.size() > MAX_OBJECTS && level < MAX_LEVELS) {
        if (nodes.empty()) {
            split();
        }

        auto it = objects.begin();
        while (it != objects.end()) {
            int index = getIndex(rect);
            if (index != -1) {
                nodes[index]->insert(*it, rect);
                it = objects.erase(it);
            } else {
                ++it;
            }
        }
    }
}

void Quadtree::retrieve(std::vector<sf::Drawable*>& returnObjects, sf::FloatRect rect) {
    int index = getIndex(rect);
    if (index != -1 && !nodes.empty()) {
        nodes[index]->retrieve(returnObjects, rect);
    }

    returnObjects.insert(returnObjects.end(), objects.begin(), objects.end());
}

World::World() : coordinateQuadtree(0, sf::FloatRect(0, 0, DIAMETER, DIAMETER)), pc() {
    coordinateQuadtree.insert(&pc, pc.shape.getGlobalBounds());
}

void World::render(sf::RenderWindow& window) {
    std::vector<sf::Drawable*> returnObjects;
    coordinateQuadtree.retrieve(returnObjects, sf::FloatRect(0, 0, DIAMETER, DIAMETER));

    for (auto& object: returnObjects) {
        window.draw(*object);
    }

    window.draw(pc);
}

void World::addObject(sf::Drawable* object, sf::FloatRect rect) {
    coordinateQuadtree.insert(object, rect);
}

PlayerCharacter& World::getPlayerCharacter() {
    return pc;
}