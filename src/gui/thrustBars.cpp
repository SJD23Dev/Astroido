#include "gui/thrustBars.hpp"
#include "entities/playerCharacter.hpp"

ThrustBars::ThrustBars() {
    font.loadFromFile("../assets/fonts/Cocogoose-Pro-Darkmode-trial.ttf");

    for (int i = 0; i < 5; i++) {
        thrustBars[i].setFont(font);
        thrustBars[i].setCharacterSize(8);
        thrustBars[i].setFillColor(sf::Color(255, 255, 255, 75));
        thrustBars[i].setString("|");
        thrustBars[i].setOrigin(thrustBars[i].getLocalBounds().width / 2, thrustBars[i].getLocalBounds().height / 2);
    }
}

void ThrustBars::update(PlayerCharacter player) {
    float barSpacing = 4.0f;
    for (int i = 0; i < 5; i++) {
        /*
        // Sets the onscreen position of the thrustbars with x and y coordinates.

        // 'x' is the position of the player character minus the width of the thrustbars,
        // plus the spacing between each bar, and the current bar number times the spacing
        // between each bar.

        // 'y' is the position of the player character plus the radius of the player character,
        // plus 6 pixels to space the thrustbars from the player character.
        */
        thrustBars[i].setPosition(player.position.x - (2 * barSpacing) + (i * barSpacing), 
                                  player.position.y + player.body.getRadius() + 6);
        
        // Sets the color of the thrustbars based on the current thrust level.
        if (i < player.thrust) {
            if (i == 0)
                thrustBars[i].setFillColor(sf::Color(60, 136, 159)); // Blue (Thrust 1)
            else if (i < 3)
                thrustBars[i].setFillColor(sf::Color(144, 233, 75, 180)); // Green (Thrust 2 and 3)
            else if (i == 3)
                thrustBars[i].setFillColor(sf::Color(219, 167, 45, 180)); // Orange (Thrust 4)
            else if (i == 4)
                thrustBars[i].setFillColor(sf::Color(222, 75, 75, 180)); // Red (Thrust 5)
        } else {
            thrustBars[i].setFillColor(sf::Color(255, 255, 255, 75)); // No Thrust
        }
    }
}

void ThrustBars::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (const auto& bar : thrustBars) {
        target.draw(bar, states);
    }
}