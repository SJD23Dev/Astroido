#include "entities/orbitBall.hpp"

OrbitBall::OrbitBall() {
    shape.setRadius(5.0f);
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(shape.getRadius(), shape.getRadius());
    currentPosition = sf::Vector2f(0.0f, 0.0f);
    currentOrbitAngle = 0.0f;
}

void OrbitBall::update(const sf::Vector2f& playerPosition, float targetOrbitAngle) {
    const float radius = 30.0f;

    float smoothingFactor = 0.35f; // 0.0f = no smoothing
    currentOrbitAngle += (targetOrbitAngle - currentOrbitAngle) * smoothingFactor;

    currentPosition = sf::Vector2f(
        playerPosition.x + radius * std::cos(currentOrbitAngle),
        playerPosition.y + radius * std::sin(currentOrbitAngle)
    );

    shape.setPosition(currentPosition);
}

void OrbitBall::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(shape, states);
}