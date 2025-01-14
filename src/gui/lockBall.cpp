#include "gui/lockBall.hpp"

LockBall::LockBall() {
    currentPosition = sf::Vector2f(0.0f, 0.0f);
    currentLockAngle = 0.0f;
    font.loadFromFile("../assets/fonts/Cocogoose-Pro-Bold-trial.ttf");
    text.setFont(font);
    text.setCharacterSize(12);
    text.setFillColor(sf::Color(30, 245, 5));
    text.setString("|");

    sf::FloatRect textBounds = text.getLocalBounds();
    text.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
}

void LockBall::update(const sf::Vector2f& playerPosition, float angle) {
    const float radius = 20.0f;

    currentLockAngle += (angle - currentLockAngle);

    currentPosition = sf::Vector2f(
        playerPosition.x + radius * std::cos(currentLockAngle),
        playerPosition.y + radius * std::sin(currentLockAngle)
    );

    text.setPosition(currentPosition);
    text.setRotation(currentLockAngle * 180 / M_PI);
}

void LockBall::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(text, states);
}