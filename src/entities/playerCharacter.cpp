#include "entities/playerCharacter.hpp"

PlayerCharacter::PlayerCharacter()
    : headerAngle(0.0f)
    , velocity(0.0f, 0.0f)
    , thrust(0) {

    body.setRadius(10.f);
    body.setFillColor(sf::Color(25, 191, 225));
    body.setOrigin(body.getRadius(), body.getRadius());

    position = sf::Vector2f(500.0f, 500.0f);
    body.setPosition(position);

    thrustBars.update(*this);
}

void PlayerCharacter::update() {
    move();
    thrustBars.update(*this);
}

void PlayerCharacter::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(body, states);

    target.draw(thrustBars, states);
    target.draw(headerBall, states);

    if (isLocked) {
        target.draw(lockBall, states);
    }
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
            thrustMultiplier = 3.0f; 
            break;
        case 5:
            thrustMultiplier = 3.5f; 
            break;
        default:
            break;
        }

    if (!isLocked) {
        /*
        // Velosity is a vector of (x, y), where 'x' is the cos of the header angle,
        // and 'y' is the sin of the header angle. Velocity is then multiplied by the
        // current thrust mulitplier and a constant value of 0.1f.
        */

        velocity += sf::Vector2f(std::cos(headerAngle), std::sin(headerAngle)) * thrustMultiplier * 0.1f;
        velocity *= 0.99f; // Create a drag effect (lower = more drag)

        position += velocity;

        body.setPosition(position);
        headerBall.update(position, headerAngle);
        lockBall.update(position, headerAngle);

    } else {
        /* 
        // Velosity is a vector of (x, y), where 'x' is the cos of the lock angle,
        // and 'y' is the sin of the lock angle. Velocity is then multiplied by the
        // current thrust mulitplier and a constant value of 0.1f.
        */
        velocity += sf::Vector2f(std::cos(lockAngle), std::sin(lockAngle)) * thrustMultiplier * 0.1f;
        velocity *= 0.99f;

        position += velocity;

        body.setPosition(position);
        headerBall.update(position, headerAngle);
        lockBall.update(position, lockAngle);
    }
}