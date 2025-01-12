#pragma once

#include <SFML/Graphics.hpp>
struct Renderer;
struct World;

struct EventHandler {
    sf::Event event;
    bool pollEvent(Renderer& renderer, World& world);
    void handleEvent(Renderer& renderer, World& world);

    void handleOrbitAngle(World& world);
    void handleMovement(World& world);
};