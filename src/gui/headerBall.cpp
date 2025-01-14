#include "gui/headerBall.hpp"

HeaderBall::HeaderBall() {
    currentPosition = sf::Vector2f(0.0f, 0.0f);
    currentHeaderAngle = 0.0f;
    font.loadFromFile("../assets/fonts/Cocogoose-Pro-Bold-trial.ttf");
    text.setFont(font);
    text.setCharacterSize(12);
    text.setFillColor(sf::Color(245, 30, 5));
    text.setString(">");

    sf::FloatRect textBounds = text.getLocalBounds();
    text.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
}

void HeaderBall::update(const sf::Vector2f& playerPosition, float angle) {
    const float radius = 30.0f;

    float smoothingFactor = 0.35f; // 0.0f = no smoothing
    currentHeaderAngle += (angle - currentHeaderAngle) * smoothingFactor;

    currentPosition = sf::Vector2f(
        playerPosition.x + radius * std::cos(currentHeaderAngle),
        playerPosition.y + radius * std::sin(currentHeaderAngle)
    );

    text.setPosition(currentPosition);
    text.setRotation(currentHeaderAngle * 180 / M_PI);
}

void HeaderBall::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(text, states);
}