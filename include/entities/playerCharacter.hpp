#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "gui/headerBall.hpp"
#include "gui/thrustBars.hpp"
#include "gui/lockBall.hpp"

struct PlayerCharacter : public sf::Drawable {
    // Graphics
    sf::CircleShape body;

    // Variables
    sf::Vector2f position;
    sf::Vector2f velocity;
    int thrust;
    float headerAngle;
    float lockAngle;
    bool isLocked = false;
    
    // GUI
    HeaderBall headerBall;
    ThrustBars thrustBars;
    LockBall lockBall;
    
    PlayerCharacter();
    void update();
    void move();
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};