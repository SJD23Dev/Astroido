#pragma once

#include <SFML/Graphics.hpp>
#include "world.hpp"

struct Renderer {
    const int WINDOW_WIDTH = 1280;
    const int WINDOW_HEIGHT = 720;
    const int FPS = 30;

    sf::RenderWindow window;
    sf::ContextSettings settings;

    Renderer();
    sf::RenderWindow& getWindow();
    bool isOpen();
    void update(World& world);
};