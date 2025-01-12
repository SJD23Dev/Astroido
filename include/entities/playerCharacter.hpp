#pragma once

#include <SFML/Graphics.hpp>
#include "orbitBall.hpp"

struct PlayerCharacter : public sf::Drawable {
    sf::CircleShape shape;
    sf::Vector2f position;
    sf::Vector2f velocity;
    int thrust;
    
    OrbitBall orbitBall;
    float orbitAngle;

    sf::Font font;
    sf::Text thrustBars[5];

    PlayerCharacter();
    void update();
    void move();
    void updateThrustBars();
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};