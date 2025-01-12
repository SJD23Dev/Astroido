#pragma once

#include <cmath>
#include <SFML/Graphics.hpp>

struct OrbitBall : public sf::Drawable{
    sf::CircleShape shape;

    OrbitBall();
    void update(const sf::Vector2f& playerPosition, float orbitAngle);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};