#pragma once

#include <cmath>
#include <SFML/Graphics.hpp>

struct LockBall : public sf::Drawable {
    sf::Text text;
    sf::Font font;
    sf::Vector2f currentPosition;
    float currentLockAngle;

    LockBall();
    void update(const sf::Vector2f& playerPosition, float angle);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};