#include "entities/playerCharacter.hpp"

PlayerCharacter::PlayerCharacter() : orbitAngle(0.0f), velocity(0.0f, 0.0f), thrust(0) {
    shape.setRadius(10.f);
    shape.setFillColor(sf::Color(25, 191, 225));
    shape.setOrigin(shape.getRadius(), shape.getRadius());
    position = sf::Vector2f(500.0f, 500.0f);
    shape.setPosition(position);

    font.loadFromFile("../assets/fonts/Cocogoose-Pro-Darkmode-trial.ttf");
    for (int i = 0; i < 5; i++) {
        thrustBars[i].setFont(font);
        thrustBars[i].setCharacterSize(8);
        thrustBars[i].setFillColor(sf::Color(255, 255, 255, 75));
        thrustBars[i].setString("|");
        thrustBars[i].setOrigin(thrustBars[i].getLocalBounds().width / 2, thrustBars[i].getLocalBounds().height / 2);
    }
    updateThrustBars();
}

void PlayerCharacter::update() {
    move();
    updateThrustBars();
}

void PlayerCharacter::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(shape, states);
    for (const auto& bar : thrustBars) {
        target.draw(bar, states);
    }
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

void PlayerCharacter::updateThrustBars() {
    float barSpacing = 4.0f; // Spacing between bars
    for (int i = 0; i < 5; ++i) {
        thrustBars[i].setPosition(position.x - (2 * barSpacing) + (i * barSpacing), position.y + shape.getRadius() + 6);
        if (i < thrust) {
            if (i < 3) {
                thrustBars[i].setFillColor(sf::Color(144, 233, 75, 180)); // Green for first three bars
            } else if (i == 3) {
                thrustBars[i].setFillColor(sf::Color(219, 167, 45, 180)); // Orange for the fourth bar
            } else if (i == 4) {
                thrustBars[i].setFillColor(sf::Color(222, 75, 75, 180)); // Red for the fifth bar
            }
        } else {
            thrustBars[i].setFillColor(sf::Color(255, 255, 255, 75)); // Semi-transparent for inactive thrust
        }
    }
}