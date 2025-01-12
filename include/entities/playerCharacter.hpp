#pragma once

#include <SFML/Graphics.hpp>
#include "orbitBall.hpp"

struct PlayerCharacter : public sf::Drawable {
    sf::CircleShape shape;
    sf::Vector2f position;
    sf::Vector2f velocity;
    
    OrbitBall orbitBall;
    float orbitAngle;

    PlayerCharacter();
    void update();
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};