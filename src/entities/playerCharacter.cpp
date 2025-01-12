#include "entities/playerCharacter.hpp"

PlayerCharacter::PlayerCharacter() : orbitAngle(0.0f), velocity(0.0f, 0.0f) {
    shape.setRadius(10.f);
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin(shape.getRadius(), shape.getRadius());
    position = sf::Vector2f(500.0f, 500.0f);
    shape.setPosition(position);
}

void PlayerCharacter::update() {
    orbitBall.update(position, orbitAngle);

    position += velocity;
    shape.setPosition(position);
}

void PlayerCharacter::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(shape, states);
    target.draw(orbitBall, states);
}