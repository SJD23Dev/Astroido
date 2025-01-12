#pragma once

#include <SFML/Graphics.hpp>

struct Renderer {
    const int WINDOW_WIDTH = 1280;
    const int WINDOW_HEIGHT = 720;
    const int FPS = 60;

    sf::RenderWindow window;

    Renderer();
    sf::RenderWindow& getWindow();
};