#include "gui/headerBall.hpp"

HeaderBall::HeaderBall() {
    currentPosition = sf::Vector2f(0.0f, 0.0f);
    currentOrbitAngle = 0.0f;
    font.loadFromFile("../assets/fonts/Cocogoose-Pro-Light-trial.ttf");
    text.setFont(font);
    text.setCharacterSize(12);
    text.setFillColor(sf::Color::White);
    text.setString(">");
    text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
}

void HeaderBall::update(const sf::Vector2f& playerPosition, float targetOrbitAngle) {
    const float radius = 30.0f;

    float smoothingFactor = 0.35f; // 0.0f = no smoothing
    currentOrbitAngle += (targetOrbitAngle - currentOrbitAngle) * smoothingFactor;

    currentPosition = sf::Vector2f(
        playerPosition.x + radius * std::cos(currentOrbitAngle),
        playerPosition.y + radius * std::sin(currentOrbitAngle)
    );

    text.setPosition(currentPosition);
    text.setRotation(currentOrbitAngle * 180 / M_PI);
}

void HeaderBall::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(text, states);
}