#include "entities/playerCharacter.hpp"

PlayerCharacter::PlayerCharacter() : headerAngle(0.0f), velocity(0.0f, 0.0f), thrust(0) {
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
    target.draw(headerBall, states);
}

void PlayerCharacter::move() {
    float thrustMultiplier = 0.0f;
    switch (thrust) {
        case 1:
            thrustMultiplier = 0.15f; // Stealth
            break;
        case 2:
            thrustMultiplier = 0.8f; // "Walk" Speed
            break;
        case 3:
            thrustMultiplier = 1.5f; // "Run" Speed
            break;
        case 4:
            thrustMultiplier = 3.0f; // TODO: Decide what to do with this
            break;
        case 5:
            thrustMultiplier = 3.5f; // TODO: Decide what to do with this
            break;
        default:
            break;
    }

    velocity += sf::Vector2f(std::cos(headerAngle), std::sin(headerAngle)) * thrustMultiplier * 0.1f;
    velocity *= 0.99f;

    position += velocity;
    shape.setPosition(position);

    headerBall.update(position, headerAngle);
}

void PlayerCharacter::updateThrustBars() {
    float barSpacing = 4.0f; // Spacing between bars
    for (int i = 0; i < 5; ++i) {
        thrustBars[i].setPosition(position.x - (2 * barSpacing) + (i * barSpacing), position.y + shape.getRadius() + 6);
        if (i < thrust) {
            if (i == 0) {
                thrustBars[i].setFillColor(sf::Color(60, 136, 159));
            } else if (i < 3) {
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