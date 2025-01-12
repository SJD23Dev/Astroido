#include "entities/orbitBall.hpp"

OrbitBall::OrbitBall() {
    shape.setRadius(5.0f);
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(shape.getRadius(), shape.getRadius());
}

void OrbitBall::update(const sf::Vector2f& playerPosition, float orbitAngle) {
    const float radius = 30.0f;
    shape.setPosition(
        playerPosition.x + radius * std::cos(orbitAngle),
        playerPosition.y + radius * std::sin(orbitAngle)
    );
}

void OrbitBall::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(shape, states);
}