#pragma once

#include <SFML/Graphics.hpp>
struct PlayerCharacter;

struct ThrustBars : public sf::Drawable {
    sf::Font font;
    sf::Text thrustBars[5];

    ThrustBars();
    void update(PlayerCharacter player);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};