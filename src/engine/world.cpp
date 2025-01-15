#include "engine/world.hpp"

World::World() : spatialHash(), pc() {
    addObject(&pc, pc.body.getGlobalBounds());
}

void World::render(sf::RenderWindow& window) {
    for (auto& pair : spatialHash) {
        for (auto& object : pair.second) {
            window.draw(*object);
        }
    }
}

void World::update() {
    sf::Vector2f preActionPos = pc.body.getPosition();
    pc.update();
    sf::Vector2f postActionPos = wrapPosition(pc.body.getPosition());

    if (preActionPos != postActionPos) {
        pc.setLocation(postActionPos);
    }
    
}

sf::Vector2f World::wrapPosition(sf::Vector2f position) {
    float worldWidth = 1280;
    float worldHeight = 720;
    
    sf::Vector2f wrapped = position;
    
    // Wrap horizontally
    if (position.x < 0) wrapped.x = worldWidth + fmod(position.x, worldWidth);
    else wrapped.x = fmod(position.x, worldWidth);
    
    // Wrap vertically
    if (position.y < 0) wrapped.y = worldHeight + fmod(position.y, worldHeight);
    else wrapped.y = fmod(position.y, worldHeight);
    
    return wrapped;
}

World::Bucket World::getBucket(sf::Vector2f position) {
    int x = static_cast<int>(position.x) / BUCKET_SIZE;
    int y = static_cast<int>(position.y) / BUCKET_SIZE;
    return std::make_pair(x, y);
}

void World::addObject(sf::Drawable* object, sf::FloatRect rect) {
    Bucket bucket = getBucket(sf::Vector2f(rect.left, rect.top));
    spatialHash[bucket].push_back(object);
}

void World::removeObject(sf::Drawable* object, sf::FloatRect rect) {
    Bucket bucket = getBucket(sf::Vector2f(rect.left, rect.top));
    auto& objects = spatialHash[bucket];
    objects.erase(std::remove(objects.begin(), objects.end(), object), objects.end());
}

void World::checkCollisions() {
    for (auto& pair : spatialHash) {
        auto& objects = pair.second;
        for (size_t i = 0; i < objects.size(); ++i) {
            for (size_t j = i + 1; j < objects.size(); ++j) {
                // TODO: Implement collision detection
            }
        }
    }
}

PlayerCharacter& World::getPlayerCharacter() {
    return pc;
}