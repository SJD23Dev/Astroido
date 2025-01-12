#include "engine/renderer.hpp"

Renderer::Renderer() : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Astroido") {
    window.setFramerateLimit(FPS);
}

sf::RenderWindow& Renderer::getWindow() {
    return window;
}