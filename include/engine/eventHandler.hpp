#pragma once

#include <SFML/Graphics.hpp>
struct Renderer;
struct World;

struct EventHandler {
    sf::Event event;
    bool pollEvent(Renderer& renderer, World& world);
    void handleEvent(Renderer& renderer, World& world);
    void handleKeyPress(World& world);
    void handleKeyRelease(World& world);
    void handleHeadingAngle(World& world);
};