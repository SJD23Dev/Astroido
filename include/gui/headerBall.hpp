#pragma once

#include <cmath>
#include <SFML/Graphics.hpp>

struct HeaderBall : public sf::Drawable{
    sf::Text text;
    sf::Font font;
    sf::Vector2f currentPosition;
    float currentOrbitAngle;

    HeaderBall();
    void update(const sf::Vector2f& playerPosition, float orbitAngle);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};