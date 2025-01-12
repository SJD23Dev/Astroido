#pragma once

#include <SFML/Graphics.hpp>

struct PlayerCharacter : public sf::Drawable {
    sf::CircleShape shape;
    sf::Vector2f position;

    PlayerCharacter();
    void update();
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};