#pragma once

#include <SFML/Graphics.hpp>
#include "renderer.hpp"

struct EventHandler {
    sf::Event event;
    bool pollEvent(Renderer& renderer);
    void handleEvent(Renderer& renderer, EventHandler& event);
};