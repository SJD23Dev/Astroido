#pragma once

#include <SFML/Graphics.hpp>
struct Renderer;

struct EventHandler {
    sf::Event event;
    bool pollEvent(Renderer& renderer);
    void handleEvent(Renderer& renderer, EventHandler& event);
};