#pragma once

#include <SFML/Graphics.hpp>
#include "gui/headerBall.hpp"

struct PlayerCharacter : public sf::Drawable {
    // PC Object 
    // TODO: Make something cooler than a circle
    sf::CircleShape shape;

    // Movement
    sf::Vector2f position;
    sf::Vector2f velocity;
    int thrust;
    
    // Header UI
    HeaderBall headerBall;
    float headerAngle;

    // Thrust UI
    sf::Font font;
    sf::Text thrustBars[5];
    
    // Functions... needs to be organized better
    PlayerCharacter();
    void update();

    void move();
    void updateThrustBars();
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};