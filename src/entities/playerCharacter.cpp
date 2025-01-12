#include "entities/playerCharacter.hpp"

PlayerCharacter::PlayerCharacter() : orbitAngle(0.0f), velocity(0.0f, 0.0f) {
    shape.setRadius(10.f);
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin(shape.getRadius(), shape.getRadius());
    position = sf::Vector2f(500.0f, 500.0f);
    shape.setPosition(position);
}

void PlayerCharacter::update() {
    move();
}

void PlayerCharacter::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(shape, states);
    target.draw(orbitBall, states);
}

void PlayerCharacter::move() {
    float thrustMultiplier = 0.0f;
    switch (thrust) {
        case 1:
            thrustMultiplier = 0.5f;
            break;
        case 2:
            thrustMultiplier = 1.0f;
            break;
        case 3:
            thrustMultiplier = 1.5f;
            break;
        case 4:
            thrustMultiplier = 2.0f;
            break;
        case 5:
            thrustMultiplier = 2.5f;
            break;
        default:
            break;
    }

    velocity += sf::Vector2f(std::cos(orbitAngle), std::sin(orbitAngle)) * thrustMultiplier * 0.1f;
    velocity *= 0.99f;

    position += velocity;
    shape.setPosition(position);

    orbitBall.update(position, orbitAngle);
}