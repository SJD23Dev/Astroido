#include "entities/playerCharacter.hpp"

PlayerCharacter::PlayerCharacter() {
    shape.setRadius(10.f);
    shape.setFillColor(sf::Color::Green);
    position = sf::Vector2f(0.f, 0.f);
    shape.setPosition(position);
}

void PlayerCharacter::update() {
    shape.setPosition(position);
}

void PlayerCharacter::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(shape, states);
}